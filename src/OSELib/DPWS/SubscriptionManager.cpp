/*
 * SubscriptionManager.cpp
 *
 *  Created on: 07.12.2015, matthias
 *  Modified on: 29.08.2019, baumeister
 *
 */

#include "OSELib/DPWS/SubscriptionManager.h"
#include "OSELib/Helper/DurationWrapper.h"
#include "OSELib/SOAP/NormalizedMessageAdapter.h"
#include "OSELib/SOAP/NormalizedMessageSerializer.h"
#include "OSELib/SOAP/SoapActionCommand.h"
#include "OSELib/DPWS/OperationTraits.h"


#include "SDCLib/SDCInstance.h"

#include "DataModel/eventing.hxx"

#include <Poco/URI.h>
#include <Poco/Net/HTTPClientSession.h>


using namespace OSELib;
using namespace OSELib::DPWS;

const auto DEFAULT_DURATION_S = std::chrono::seconds{60};

SubscriptionManager::SubscriptionManager(const std::vector<xml_schema::Uri>& pl_allowedEventActions,
                                         SDCLib::Config::SSLConfig_shared_ptr p_SSLConfig)
    : OSELib::Helper::WithLogger(Log::EVENTSOURCE)
    , m_allowedEventActions(pl_allowedEventActions)
    , m_sessionManager(new HTTP::HTTPSessionManager(this, std::move(p_SSLConfig)))
    , m_runnableAdapter(*this, &SubscriptionManager::run)
{
    m_thread.start(m_runnableAdapter);
}
SubscriptionManager::~SubscriptionManager()
{
    /* NOTE: TODO: Notify consumer
    for(auto& endSubscription : m_subscriptions.getAllSubscriptions())
    {
        OSELib::DPWS::SubscriptionEndTraits::ReportType::SubscriptionManagerType subscriptionManager(
            WS::ADDRESSING::AttributedURIType(endSubscription.second.m_notifyTo.getAddress())); // <- Double check that parameter here!
        OSELib::DPWS::SubscriptionEndTraits::ReportType::StatusType statusType{
            "http://schemas.xmlsoap.org/ws/2004/08/eventing/SourceShuttingDown"};

        OSELib::DPWS::SubscriptionEndTraits::ReportType endReport{subscriptionManager, statusType};
        fireEvent<OSELib::DPWS::SubscriptionEndTraits>(endReport);
    }*/

    m_thread.wakeUp();
    m_thread.join();
}
void SubscriptionManager::houseKeeping()
{
    for(const auto& expiredID : m_subscriptions.collectExpiredSubscriptions())
    {
        m_subscriptions.removeSubscription(expiredID);
        log_information([&] { return "Expired Subscription: " + expiredID; });
    }
}

void SubscriptionManager::run()
{
    while(Poco::Thread::trySleep(6000))
    {
        log_debug([] { return "Checking for expired subscriptions..."; });
        houseKeeping();
    }
}


std::unique_ptr<SubscribeTraits::Response> SubscriptionManager::dispatch(const SubscribeTraits::Request& p_request)
{
    using ResponseType = SubscribeTraits::Response;

    const std::string t_expiresString(p_request.getExpires().present() ? p_request.getExpires().get() :
                                                                         "PT60S"); // TODO: MAGIC NUMBER PT'60'S

    Helper::DurationWrapper t_expiresDuration(t_expiresString);

    if(t_expiresDuration.toDuration_s().second == std::chrono::seconds(0) || t_expiresDuration.negative())
    {
        if(p_request.getExpires().present())
        {
            // NOTE: THIS MUST FAIL! See WS-Eventing wse:InvalidExpirationTime ?
        }
        // Falling back to default
        t_expiresDuration = Helper::DurationWrapper(DEFAULT_DURATION_S);
    }

    if(p_request.getDelivery().getMode().present() && p_request.getDelivery().getMode().get() != OSELib::WS_EVENTING_DELIVERYMODE_PUSH)
    {
        throw SOAP::SoapActionCommand::DispatchingFailed("Delivery mode not supported: " + p_request.getDelivery().getMode().get());
    }

    if(!p_request.getFilter().present())
    {
        throw SOAP::SoapActionCommand::DispatchingFailed("No filter specified");
    }

    if(p_request.getFilter().get().getDialect() != OSELib::WS_EVENTING_FILTER_ACTION)
    {
        throw SOAP::SoapActionCommand::DispatchingFailed("Filter mode not supported: " + p_request.getFilter().get().getDialect());
    }
    for(const auto& t_filterAction : p_request.getFilter().get())
    {
        if(std::find(m_allowedEventActions.begin(), m_allowedEventActions.end(), t_filterAction) == m_allowedEventActions.end())
        {
            log_debug([&] { return "Unknown event action: " + t_filterAction; });
            throw SOAP::SoapActionCommand::DispatchingFailed("Unknown event action: " + t_filterAction);
        }
    }

    auto t_result_TimePoint = t_expiresDuration.toExpirationTimePoint();
    if(!t_result_TimePoint.first)
    {
        log_error([&] { return "Subscribe: TimePoint conversion failed!"; });
        throw SOAP::SoapActionCommand::DispatchingFailed("Subscribe: Timepoint / Duration parse Error!");
    }


    ActiveSubscriptions::SubscriptionInformation t_info(p_request.getDelivery().getNotifyTo(),
                                                        t_result_TimePoint.second,
                                                        p_request.getFilter().get());
    const auto t_mySubscriptionID(m_subscriptions.addSubscription(t_info));

    log_debug([&] { return "Subscribing " + t_mySubscriptionID; });

    // Build the response
    ResponseType::SubscriptionManagerType t_subscriptionManager(WS::ADDRESSING::AttributedURIType("To be defined by ServiceHandler"));
    ResponseType::SubscriptionManagerType::ReferenceParametersType::IdentifierType t_myID(t_mySubscriptionID);
    ResponseType::SubscriptionManagerType::ReferenceParametersType t_referenceParameters;
    t_referenceParameters.getIdentifier().set(t_myID);
    t_subscriptionManager.getReferenceParameters().set(t_referenceParameters);
    std::unique_ptr<ResponseType> t_response(new ResponseType(t_subscriptionManager, t_expiresDuration.toString()));

    m_subscriptions.printSubscriptions();

    return t_response;
}

std::unique_ptr<RenewTraits::Response> SubscriptionManager::dispatch(const RenewTraits::Request& p_request,
                                                                     const RenewTraits::RequestIdentifier& p_identifier)
{
    // Check if the subscription already exists
    auto t_subscription = m_subscriptions.getSubscriptionStatus(p_identifier);
    if(!t_subscription.first)
    {
        // FIXME: Create a new Subscription! https://www.w3.org/Submission/WS-Eventing/#Renew
    }

    using ResponseType = RenewTraits::Response;

    const std::string t_expiresString(p_request.getExpires().present() ? p_request.getExpires().get() :
                                                                         "PT60S"); // TODO: MAGIC NUMBER PT'60'S

    Helper::DurationWrapper t_expiresDuration(t_expiresString);

    auto t_duration = t_expiresDuration.toDuration_s();
    if((t_duration.second == std::chrono::seconds(0)) || t_expiresDuration.negative())
    {
        t_expiresDuration = Helper::DurationWrapper(DEFAULT_DURATION_S);
    }

    std::unique_ptr<ResponseType> t_response(new ResponseType());
    t_response->getExpires().set(t_expiresDuration.toString());

    auto t_result_TimePoint = t_expiresDuration.toExpirationTimePoint();
    if(t_result_TimePoint.first)
    {
        log_debug([&] { return "Renewing " + p_identifier; });
        m_subscriptions.renewSubscription(p_identifier, t_result_TimePoint.second);
    }
    else
    {
        // TODO Fallback? Error response?
        log_error([] { return "Renew: TimePoint conversion failed! No renewing!"; });
    }

    m_subscriptions.printSubscriptions();
    return t_response;
}

std::unique_ptr<GetStatusTraits::Response> SubscriptionManager::dispatch(const GetStatusTraits::Request&,
                                                                         const GetStatusTraits::RequestIdentifier& p_identifier)
{
    if(p_identifier.empty())
    {
        log_debug([] { return "GetStatus: Empty Identifier!"; });
        throw SOAP::SoapActionCommand::DispatchingFailed("### GETSTATUS: Empty Identifier!");
    }

    auto t_subscription = m_subscriptions.getSubscriptionStatus(p_identifier);
    if(!t_subscription.first)
    {
        log_debug([] { return "GetStatus: Unknown Identifier!"; });
        throw SOAP::SoapActionCommand::DispatchingFailed("### GETSTATUS: Unknown Identifier: " + p_identifier + "!");
    }

    auto t_expiresDuration = Helper::DurationWrapper(
        std::chrono::duration_cast<std::chrono::seconds>(t_subscription.second.m_expirationTime - std::chrono::system_clock::now()));

    auto t_duration = t_expiresDuration.toDuration_s();
    if((t_duration.second == std::chrono::seconds(0)) || t_expiresDuration.negative())
    {
        // NOTE: EXPIRED! WHAT TO DO HERE? -> Copied from renew...
        t_expiresDuration = Helper::DurationWrapper(DEFAULT_DURATION_S);
    }

    // Create the Response
    using ResponseType = GetStatusTraits::Response;
    std::unique_ptr<ResponseType> t_response(new ResponseType());
    t_response->getExpires().set(t_expiresDuration.toString());

    m_subscriptions.printSubscriptions();
    return t_response;
}

std::unique_ptr<UnsubscribeTraits::Response> SubscriptionManager::dispatch(const UnsubscribeTraits::Request&,
                                                                           const UnsubscribeTraits::RequestIdentifier& p_identifier)
{
    using ResponseType = UnsubscribeTraits::Response;
    std::unique_ptr<ResponseType> t_response(new ResponseType());

    log_debug([&] { return "Unsubscribing " + p_identifier; });
    m_subscriptions.removeSubscription(p_identifier);

    m_subscriptions.printSubscriptions();

    return t_response;
}

void SubscriptionManager::endSubscription(const SubscriptionEndTraits::RequestIdentifier&)
{
    // TODO: Write member function to get active subscription by identifier and end

    /*
     * BUILD REPORT
     * fireEvent<OSELib::DPWS::SubscriptionEndTraits>(p_report);

    auto endIdentifier = p_report.getSubscriptionManager().getReferenceParameters().get().getIdentifier().get();
    log_debug([&] { return "SubscriptionEnd for: " + endIdentifier; });
    m_subscriptions.removeSubscription(endIdentifier);
    */
}


template<class TraitsType> void SubscriptionManager::fireEvent(const typename TraitsType::ReportType& p_report)
{
    std::unique_ptr<MESSAGEMODEL::Envelope::HeaderType> t_header(new MESSAGEMODEL::Envelope::HeaderType());
    using MessageIDType = MESSAGEMODEL::Envelope::HeaderType::MessageIDType;
    t_header->getMessageID().set(MessageIDType(SDCLib::SDCInstance::calcMSGID()));

    using ActionType = MESSAGEMODEL::Envelope::HeaderType::ActionType;
    t_header->getAction().set(ActionType(TraitsType::Action()));

    std::unique_ptr<MESSAGEMODEL::Envelope::BodyType> t_body(new MESSAGEMODEL::Envelope::BodyType());

    std::unique_ptr<MESSAGEMODEL::Envelope> t_eventMessage(new MESSAGEMODEL::Envelope(std::move(t_header), std::move(t_body)));

    SOAP::NormalizedMessageAdapter<typename TraitsType::ReportType> adapter;
    adapter.set(*t_eventMessage, std::unique_ptr<typename TraitsType::ReportType>(new typename TraitsType::ReportType(p_report)));

    SOAP::NormalizedMessageSerializer t_serializer;
    for(const auto& t_epr : m_subscriptions.getSubscriptionsForAction(TraitsType::Action()))
    {
        t_eventMessage->getHeader().setTo(t_epr.second.getAddress());
        t_eventMessage->getHeader().getIdentifier().reset();

        if(t_epr.second.getReferenceParameters().present() && t_epr.second.getReferenceParameters().get().getIdentifier().present())
        {
            t_eventMessage->getHeader().setIdentifier(t_epr.second.getReferenceParameters().get().getIdentifier().get());
        }

        const Poco::URI t_uri(t_epr.second.getAddress());

        log_trace([&] { return "Enqueuing event for " + t_epr.first; });

        m_sessionManager->enqueMessage(t_uri, t_serializer.serialize(*t_eventMessage), t_epr.first);
    }
}


// DescriptionEvent
template void SubscriptionManager::fireEvent<OSELib::SDC::DescriptionModificationReportTraits>(
    const OSELib::SDC::DescriptionModificationReportTraits::ReportType& p_report);
// StateEvent
template void SubscriptionManager::fireEvent<OSELib::SDC::EpisodicAlertReportTraits>(
    const OSELib::SDC::EpisodicAlertReportTraits::ReportType& p_report);
template void SubscriptionManager::fireEvent<OSELib::SDC::EpisodicComponentReportTraits>(
    const OSELib::SDC::EpisodicComponentReportTraits::ReportType& p_report);
template void SubscriptionManager::fireEvent<OSELib::SDC::EpisodicContextReportTraits>(
    const OSELib::SDC::EpisodicContextReportTraits::ReportType& p_report);
template void SubscriptionManager::fireEvent<OSELib::SDC::EpisodicMetricReportTraits>(
    const OSELib::SDC::EpisodicMetricReportTraits::ReportType& p_report);
template void SubscriptionManager::fireEvent<OSELib::SDC::EpisodicOperationalStateReportTraits>(
    const OSELib::SDC::EpisodicOperationalStateReportTraits::ReportType& p_report);
template void SubscriptionManager::fireEvent<OSELib::SDC::PeriodicAlertReportTraits>(
    const OSELib::SDC::PeriodicAlertReportTraits::ReportType& p_report);
template void SubscriptionManager::fireEvent<OSELib::SDC::PeriodicContextReportTraits>(
    const OSELib::SDC::PeriodicContextReportTraits::ReportType& p_report);
template void SubscriptionManager::fireEvent<OSELib::SDC::PeriodicMetricReportTraits>(
    const OSELib::SDC::PeriodicMetricReportTraits::ReportType& p_report);
template void SubscriptionManager::fireEvent<OSELib::SDC::OperationInvokedReportTraits>(
    const OSELib::SDC::OperationInvokedReportTraits::ReportType& p_report);

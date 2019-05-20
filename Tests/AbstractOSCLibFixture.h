/*
 * AbstractOSCLibFixture.h
 *
 *  Created on: 23.05.2014
 *      Author: roehser
 */

#ifndef ABSTRACTOSCLIBFIXTURE_H_
#define ABSTRACTOSCLIBFIXTURE_H_

#include <string>

#include "OSCLib/SDCLibrary.h"

#include "OSELib/Helper/WithLogger.h"

namespace SDCLib {
namespace Tests {

struct AbstractOSCLibFixture : public OSELib::WithLogger {
public:
	AbstractOSCLibFixture(const std::string & testname, OSELib::LogLevel debuglevel) :
		WithLogger(OSELib::Log::BASE),
		testname(testname)
	{
		log_notice([&]{ return testname + ":  Startup."; });
		SDCLibrary::getInstance().startup(debuglevel);

	}

	virtual ~AbstractOSCLibFixture() {
		SDCLibrary::getInstance().shutdown();
		log_notice([&]{ return testname + ":  Shutdown."; });
	}

public:

    SDCLib::SDCPort getNewPort() { return m_port++; }

    SDCLib::SDCInstance_shared_ptr createSDCInstance()
    {
        // Init SDCInstance
        // Create a new SDCInstance (dont init yet) - give it a new port (just increment)
        log_notice([]{ return "Creating new SDCInstance..."; });
        auto t_SDCInstance = std::make_shared<SDCInstance>(getNewPort(), false);
        // Init
        log_notice([]{ return "Init SDCInstance..."; });
        if(!t_SDCInstance->init()) {
            log_notice([]{ return "CRITICAL: Failed to init SDCInstance"; });
            return nullptr;
        }
        // Some restriction
        t_SDCInstance->setIP6enabled(false);
        t_SDCInstance->setIP4enabled(true);
        // Bind it to interface that matches the internal criteria (usually the first enumerated)
        if(!t_SDCInstance->bindToDefaultNetworkInterface()) {
            log_notice([]{ return "Failed to bind SDCInstance to default network interface! Exit..."; });
            return nullptr;
        }
        return t_SDCInstance;
    }

private:
	const std::string testname;

    std::atomic<SDCPort> m_port = ATOMIC_VAR_INIT(Config::SDC_ALLOWED_PORT_START);
};

}
}

#endif /* ABSTRACTOSCLIBFIXTURE_H_ */

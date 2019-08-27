// Copyright (c) 2005-2014 Code Synthesis Tools CC
//
// This program was generated by CodeSynthesis XSD, an XML Schema to
// C++ data binding compiler.
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License version 2 as
// published by the Free Software Foundation.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
//
// In addition, as a special exception, Code Synthesis Tools CC gives
// permission to link this program with the Xerces-C++ library (or with
// modified versions of Xerces-C++ that use the same license as Xerces-C++),
// and distribute linked combinations including the two. You must obey
// the GNU General Public License version 2 in all respects for all of
// the code used other than Xerces-C++. If you modify this copy of the
// program, you may extend this exception to your version of the program,
// but you are not obligated to do so. If you do not wish to do so, delete
// this exception statement from your version.
//
// Furthermore, Code Synthesis Tools CC makes a special exception for
// the Free/Libre and Open Source Software (FLOSS) which is described
// in the accompanying FLOSSE file.
//

#ifndef WS_STREAMING_HXX
#define WS_STREAMING_HXX

#include "DataModel/ws-streaming-fwd.hxx"

// Begin prologue.
//
//
// End prologue.

#include <xsd/cxx/config.hxx>

#if (XSD_INT_VERSION != 4000000L)
#error XSD runtime version mismatch
#endif

#include <xsd/cxx/pre.hxx>

#include <memory>    // ::std::unique_ptr
#include <limits>    // std::numeric_limits
#include <algorithm> // std::binary_search
#include <utility>   // std::move

#include <xsd/cxx/xml/char-utf8.hxx>

#include <xsd/cxx/tree/exceptions.hxx>
#include <xsd/cxx/tree/elements.hxx>
#include <xsd/cxx/tree/containers.hxx>
#include <xsd/cxx/tree/list.hxx>

#include <xsd/cxx/xml/dom/parsing-header.hxx>

namespace WS
{
  namespace STREAMING
  {
    class TStreamType: public ::xml_schema::Type
    {
      public:
      // actionURI
      //
      typedef ::xml_schema::Uri ActionURIType;
      typedef ::xsd::cxx::tree::optional< ActionURIType > ActionURIOptional;
      typedef ::xsd::cxx::tree::traits< ActionURIType, char > ActionURITraits;

      const ActionURIOptional&
      actionURI () const;

      ActionURIOptional&
      actionURI ();

      void
      actionURI (const ActionURIType& x);

      void
      actionURI (const ActionURIOptional& x);

      void
      actionURI (::std::unique_ptr< ActionURIType > p);

      // element
      //
      typedef ::xml_schema::Qname ElementType;
      typedef ::xsd::cxx::tree::optional< ElementType > ElementOptional;
      typedef ::xsd::cxx::tree::traits< ElementType, char > ElementTraits;

      const ElementOptional&
      element () const;

      ElementOptional&
      element ();

      void
      element (const ElementType& x);

      void
      element (const ElementOptional& x);

      void
      element (::std::unique_ptr< ElementType > p);

      // id
      //
      typedef ::xml_schema::String IdType;
      typedef ::xsd::cxx::tree::optional< IdType > IdOptional;
      typedef ::xsd::cxx::tree::traits< IdType, char > IdTraits;

      const IdOptional&
      id () const;

      IdOptional&
      id ();

      void
      id (const IdType& x);

      void
      id (const IdOptional& x);

      void
      id (::std::unique_ptr< IdType > p);

      // streamType
      //
      typedef ::xml_schema::Uri StreamTypeType;
      typedef ::xsd::cxx::tree::optional< StreamTypeType > StreamTypeOptional;
      typedef ::xsd::cxx::tree::traits< StreamTypeType, char > StreamTypeTraits;

      const StreamTypeOptional&
      streamType () const;

      StreamTypeOptional&
      streamType ();

      void
      streamType (const StreamTypeType& x);

      void
      streamType (const StreamTypeOptional& x);

      void
      streamType (::std::unique_ptr< StreamTypeType > p);

      // Constructors.
      //
      TStreamType ();

      TStreamType (const ::xercesc::DOMElement& e,
                   ::xml_schema::Flags f = 0,
                   ::xml_schema::Container* c = 0);

      TStreamType (const TStreamType& x,
                   ::xml_schema::Flags f = 0,
                   ::xml_schema::Container* c = 0);

      virtual TStreamType*
      _clone (::xml_schema::Flags f = 0,
              ::xml_schema::Container* c = 0) const;

      TStreamType&
      operator= (const TStreamType& x);

      virtual 
      ~TStreamType ();

      // Implementation.
      //
      protected:
      void
      parse (::xsd::cxx::xml::dom::parser< char >&,
             ::xml_schema::Flags);

      protected:
      ActionURIOptional actionURI_;
      ElementOptional element_;
      IdOptional id_;
      StreamTypeOptional streamType_;
    };

    class TStreamDescriptions: public ::xml_schema::Type
    {
      public:
      // streamType
      //
      typedef ::WS::STREAMING::TStreamType StreamTypeType;
      typedef ::xsd::cxx::tree::traits< StreamTypeType, char > StreamTypeTraits;

      const StreamTypeType&
      streamType () const;

      StreamTypeType&
      streamType ();

      void
      streamType (const StreamTypeType& x);

      void
      streamType (::std::unique_ptr< StreamTypeType > p);

      // targetNamespace
      //
      typedef ::xml_schema::String TargetNamespaceType;
      typedef ::xsd::cxx::tree::optional< TargetNamespaceType > TargetNamespaceOptional;
      typedef ::xsd::cxx::tree::traits< TargetNamespaceType, char > TargetNamespaceTraits;

      const TargetNamespaceOptional&
      targetNamespace () const;

      TargetNamespaceOptional&
      targetNamespace ();

      void
      targetNamespace (const TargetNamespaceType& x);

      void
      targetNamespace (const TargetNamespaceOptional& x);

      void
      targetNamespace (::std::unique_ptr< TargetNamespaceType > p);

      // Constructors.
      //
      TStreamDescriptions (const StreamTypeType&);

      TStreamDescriptions (::std::unique_ptr< StreamTypeType >);

      TStreamDescriptions (const ::xercesc::DOMElement& e,
                           ::xml_schema::Flags f = 0,
                           ::xml_schema::Container* c = 0);

      TStreamDescriptions (const TStreamDescriptions& x,
                           ::xml_schema::Flags f = 0,
                           ::xml_schema::Container* c = 0);

      virtual TStreamDescriptions*
      _clone (::xml_schema::Flags f = 0,
              ::xml_schema::Container* c = 0) const;

      TStreamDescriptions&
      operator= (const TStreamDescriptions& x);

      virtual 
      ~TStreamDescriptions ();

      // Implementation.
      //
      protected:
      void
      parse (::xsd::cxx::xml::dom::parser< char >&,
             ::xml_schema::Flags);

      protected:
      ::xsd::cxx::tree::one< StreamTypeType > streamType_;
      TargetNamespaceOptional targetNamespace_;
    };

    class StreamSource: public ::xml_schema::Type
    {
      public:
      // StreamDescriptions
      //
      typedef ::WS::STREAMING::TStreamDescriptions StreamDescriptionsType;
      typedef ::xsd::cxx::tree::traits< StreamDescriptionsType, char > StreamDescriptionsTraits;

      const StreamDescriptionsType&
      StreamDescriptions () const;

      StreamDescriptionsType&
      StreamDescriptions ();

      void
      StreamDescriptions (const StreamDescriptionsType& x);

      void
      StreamDescriptions (::std::unique_ptr< StreamDescriptionsType > p);

      // Constructors.
      //
      StreamSource (const StreamDescriptionsType&);

      StreamSource (::std::unique_ptr< StreamDescriptionsType >);

      StreamSource (const ::xercesc::DOMElement& e,
                    ::xml_schema::Flags f = 0,
                    ::xml_schema::Container* c = 0);

      StreamSource (const StreamSource& x,
                    ::xml_schema::Flags f = 0,
                    ::xml_schema::Container* c = 0);

      virtual StreamSource*
      _clone (::xml_schema::Flags f = 0,
              ::xml_schema::Container* c = 0) const;

      StreamSource&
      operator= (const StreamSource& x);

      virtual 
      ~StreamSource ();

      // Implementation.
      //
      protected:
      void
      parse (::xsd::cxx::xml::dom::parser< char >&,
             ::xml_schema::Flags);

      protected:
      ::xsd::cxx::tree::one< StreamDescriptionsType > StreamDescriptions_;
    };
  }
}

#include <iosfwd>

#include <xercesc/sax/InputSource.hpp>
#include <xercesc/dom/DOMDocument.hpp>
#include <xercesc/dom/DOMErrorHandler.hpp>

namespace WS
{
  namespace STREAMING
  {
    // Parse a URI or a local file.
    //

    ::std::unique_ptr< ::WS::STREAMING::StreamSource >
    StreamSource_ (const ::std::string& uri,
                   ::xml_schema::Flags f = 0,
                   const ::xml_schema::Properties& p = ::xml_schema::Properties ());

    ::std::unique_ptr< ::WS::STREAMING::StreamSource >
    StreamSource_ (const ::std::string& uri,
                   ::xml_schema::ErrorHandler& eh,
                   ::xml_schema::Flags f = 0,
                   const ::xml_schema::Properties& p = ::xml_schema::Properties ());

    ::std::unique_ptr< ::WS::STREAMING::StreamSource >
    StreamSource_ (const ::std::string& uri,
                   ::xercesc::DOMErrorHandler& eh,
                   ::xml_schema::Flags f = 0,
                   const ::xml_schema::Properties& p = ::xml_schema::Properties ());

    // Parse std::istream.
    //

    ::std::unique_ptr< ::WS::STREAMING::StreamSource >
    StreamSource_ (::std::istream& is,
                   ::xml_schema::Flags f = 0,
                   const ::xml_schema::Properties& p = ::xml_schema::Properties ());

    ::std::unique_ptr< ::WS::STREAMING::StreamSource >
    StreamSource_ (::std::istream& is,
                   ::xml_schema::ErrorHandler& eh,
                   ::xml_schema::Flags f = 0,
                   const ::xml_schema::Properties& p = ::xml_schema::Properties ());

    ::std::unique_ptr< ::WS::STREAMING::StreamSource >
    StreamSource_ (::std::istream& is,
                   ::xercesc::DOMErrorHandler& eh,
                   ::xml_schema::Flags f = 0,
                   const ::xml_schema::Properties& p = ::xml_schema::Properties ());

    ::std::unique_ptr< ::WS::STREAMING::StreamSource >
    StreamSource_ (::std::istream& is,
                   const ::std::string& id,
                   ::xml_schema::Flags f = 0,
                   const ::xml_schema::Properties& p = ::xml_schema::Properties ());

    ::std::unique_ptr< ::WS::STREAMING::StreamSource >
    StreamSource_ (::std::istream& is,
                   const ::std::string& id,
                   ::xml_schema::ErrorHandler& eh,
                   ::xml_schema::Flags f = 0,
                   const ::xml_schema::Properties& p = ::xml_schema::Properties ());

    ::std::unique_ptr< ::WS::STREAMING::StreamSource >
    StreamSource_ (::std::istream& is,
                   const ::std::string& id,
                   ::xercesc::DOMErrorHandler& eh,
                   ::xml_schema::Flags f = 0,
                   const ::xml_schema::Properties& p = ::xml_schema::Properties ());

    // Parse xercesc::InputSource.
    //

    ::std::unique_ptr< ::WS::STREAMING::StreamSource >
    StreamSource_ (::xercesc::InputSource& is,
                   ::xml_schema::Flags f = 0,
                   const ::xml_schema::Properties& p = ::xml_schema::Properties ());

    ::std::unique_ptr< ::WS::STREAMING::StreamSource >
    StreamSource_ (::xercesc::InputSource& is,
                   ::xml_schema::ErrorHandler& eh,
                   ::xml_schema::Flags f = 0,
                   const ::xml_schema::Properties& p = ::xml_schema::Properties ());

    ::std::unique_ptr< ::WS::STREAMING::StreamSource >
    StreamSource_ (::xercesc::InputSource& is,
                   ::xercesc::DOMErrorHandler& eh,
                   ::xml_schema::Flags f = 0,
                   const ::xml_schema::Properties& p = ::xml_schema::Properties ());

    // Parse xercesc::DOMDocument.
    //

    ::std::unique_ptr< ::WS::STREAMING::StreamSource >
    StreamSource_ (const ::xercesc::DOMDocument& d,
                   ::xml_schema::Flags f = 0,
                   const ::xml_schema::Properties& p = ::xml_schema::Properties ());

    ::std::unique_ptr< ::WS::STREAMING::StreamSource >
    StreamSource_ (::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d,
                   ::xml_schema::Flags f = 0,
                   const ::xml_schema::Properties& p = ::xml_schema::Properties ());
  }
}

#include <iosfwd>

#include <xercesc/dom/DOMDocument.hpp>
#include <xercesc/dom/DOMErrorHandler.hpp>
#include <xercesc/framework/XMLFormatter.hpp>

#include <xsd/cxx/xml/dom/auto-ptr.hxx>

namespace WS
{
  namespace STREAMING
  {
    void
    operator<< (::xercesc::DOMElement&, const TStreamType&);

    void
    operator<< (::xercesc::DOMElement&, const TStreamDescriptions&);

    // Serialize to std::ostream.
    //

    void
    StreamSource_ (::std::ostream& os,
                   const ::WS::STREAMING::StreamSource& x, 
                   const ::xml_schema::NamespaceInfomap& m = ::xml_schema::NamespaceInfomap (),
                   const ::std::string& e = "UTF-8",
                   ::xml_schema::Flags f = 0);

    void
    StreamSource_ (::std::ostream& os,
                   const ::WS::STREAMING::StreamSource& x, 
                   ::xml_schema::ErrorHandler& eh,
                   const ::xml_schema::NamespaceInfomap& m = ::xml_schema::NamespaceInfomap (),
                   const ::std::string& e = "UTF-8",
                   ::xml_schema::Flags f = 0);

    void
    StreamSource_ (::std::ostream& os,
                   const ::WS::STREAMING::StreamSource& x, 
                   ::xercesc::DOMErrorHandler& eh,
                   const ::xml_schema::NamespaceInfomap& m = ::xml_schema::NamespaceInfomap (),
                   const ::std::string& e = "UTF-8",
                   ::xml_schema::Flags f = 0);

    // Serialize to xercesc::XMLFormatTarget.
    //

    void
    StreamSource_ (::xercesc::XMLFormatTarget& ft,
                   const ::WS::STREAMING::StreamSource& x, 
                   const ::xml_schema::NamespaceInfomap& m = ::xml_schema::NamespaceInfomap (),
                   const ::std::string& e = "UTF-8",
                   ::xml_schema::Flags f = 0);

    void
    StreamSource_ (::xercesc::XMLFormatTarget& ft,
                   const ::WS::STREAMING::StreamSource& x, 
                   ::xml_schema::ErrorHandler& eh,
                   const ::xml_schema::NamespaceInfomap& m = ::xml_schema::NamespaceInfomap (),
                   const ::std::string& e = "UTF-8",
                   ::xml_schema::Flags f = 0);

    void
    StreamSource_ (::xercesc::XMLFormatTarget& ft,
                   const ::WS::STREAMING::StreamSource& x, 
                   ::xercesc::DOMErrorHandler& eh,
                   const ::xml_schema::NamespaceInfomap& m = ::xml_schema::NamespaceInfomap (),
                   const ::std::string& e = "UTF-8",
                   ::xml_schema::Flags f = 0);

    // Serialize to an existing xercesc::DOMDocument.
    //

    void
    StreamSource_ (::xercesc::DOMDocument& d,
                   const ::WS::STREAMING::StreamSource& x,
                   ::xml_schema::Flags f = 0);

    // Serialize to a new xercesc::DOMDocument.
    //

    ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument >
    StreamSource_ (const ::WS::STREAMING::StreamSource& x, 
                   const ::xml_schema::NamespaceInfomap& m = ::xml_schema::NamespaceInfomap (),
                   ::xml_schema::Flags f = 0);

    void
    operator<< (::xercesc::DOMElement&, const StreamSource&);
  }
}

#include <xsd/cxx/post.hxx>

// Begin epilogue.
//
//
// End epilogue.

#endif // WS_STREAMING_HXX

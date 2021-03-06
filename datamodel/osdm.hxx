
#ifndef OSDM_HXX
#define OSDM_HXX

#ifndef XSD_CXX11
#define XSD_CXX11
#endif

#ifndef XSD_USE_CHAR
#define XSD_USE_CHAR
#endif

#ifndef XSD_CXX_TREE_USE_CHAR
#define XSD_CXX_TREE_USE_CHAR
#endif

#include "DataModel/BICEPS_ParticipantModel.hxx"
#include "DataModel/BICEPS_MessageModel.hxx"
#include "DataModel/DICOMDeviceDescription.hxx"
#include "DataModel/ExtensionPoint.hxx"

namespace CDM {
	typedef xml_schema::Base64Binary Base64Binary;
	typedef xml_schema::DateTime DateTime;
	typedef xml_schema::Duration Duration;
	typedef xml_schema::Language Language;
}

#endif // OSDM_HXX

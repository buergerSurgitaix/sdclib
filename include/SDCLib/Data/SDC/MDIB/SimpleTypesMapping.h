/*
 * SimpleTypesMapping.h
 *
 *  Created on: 22.06.2017
 *      Author: buerger
 *
 *  This file is autogenerated.
 *
 *  Do not edit this file. For customization please edit the SimpleTypesMapping_beginning.hxx or SimpleTypesMapping_ending.hxx
 */

/*! \file */

#ifndef SIMPLETYPESMAPPING_H_
#define SIMPLETYPESMAPPING_H_

#include "DataModel/osdm-fwd.hxx"

namespace SDCLib {
namespace Data {
namespace SDC {

// needed from message model for API
enum class InvocationState
{
	Wait,
	Start,
	Cnclld,
	CnclldMan,
	Fin,
	FinMod,
	Fail
};

// autogenerated starting here

typedef unsigned long long Timestamp;
typedef unsigned long long VersionCounter;
typedef unsigned long long ReferencedVersion;
typedef std::string CodeIdentifier;
typedef std::string SymbolicCodeName;
typedef std::string LocalizedTextRef;
typedef std::string LocalizedTextContent;
typedef std::string Handle;
typedef std::string HandleRef;
typedef std::vector<std::string> AlertConditionReference;
typedef double QualityIndicator;
typedef std::vector<double> RealTimeValueType;
typedef std::vector<std::string> EntryRef;
typedef std::vector<std::string> OperationRef;
typedef std::string TimeZone;
typedef xml_schema::Uri Root;
typedef std::string Extension;
typedef std::string DateOfBirth;


enum class MeasurementValidity
{
	Vld,
	Vldated,
	Ong,
	Qst,
	Calib,
	Inv,
	Oflw,
	Uflw,
	NA
};

enum class LocalizedTextWidth
{
	xs,
	s,
	m,
	l,
	xl,
	xxl
};

enum class SafetyClassification
{
	Inf,
	MedA,
	MedB,
	MedC
};

enum class ComponentActivation
{
	On,
	NotRdy,
	StndBy,
	Off,
	Shtdn,
	Fail
};

enum class CalibrationState
{
	No,
	Req,
	Run,
	Cal,
	Oth
};

enum class CalibrationType
{
	Offset,
	Gain,
	TP,
	Unspec
};

enum class MdsOperatingMode
{
	Nml,
	Dmo,
	Srv,
	Mtn
};

enum class AlertActivation
{
	On,
	Off,
	Psd
};

enum class AlertConditionKind
{
	Phy,
	Tec,
	Oth
};

enum class AlertConditionPriority
{
	Lo,
	Me,
	Hi,
	None
};

enum class AlertConditionMonitoredLimits
{
	All,
	LoOff,
	HiOff,
	None
};

enum class AlertSignalManifestation
{
	Aud,
	Vis,
	Tan,
	Oth
};

enum class AlertSignalPresence
{
	On,
	Off,
	Latch,
	Ack
};

enum class AlertSignalPrimaryLocation
{
	Loc,
	Rem
};

enum class GenerationMode
{
	Real,
	Test,
	Demo
};

enum class MetricCategory
{
	Unspec,
	Msrmt,
	Clc,
	Set,
	Preset,
	Rcmm
};

enum class DerivationMethod
{
	Auto,
	Man
};

enum class MetricAvailability
{
	Intr,
	Cont
};

enum class OperatingMode
{
	Dis,
	En,
	NA
};

enum class ContextAssociation
{
	No,
	Pre,
	Assoc,
	Dis
};

enum class Sex
{
	Unspec,
	M,
	F,
	Unkn
};

enum class PatientType
{
	Unspec,
	Ad,
	Ado,
	Ped,
	Inf,
	Neo,
	Oth
};

enum class DicomTransferRole
{
	Scu,
	Scp
};

enum class CanEscalate
{
	Lo,
	Me,
	Hi
};

enum class CanDeescalate
{
	Me,
	Lo,
	None
};

enum class Kind
{
	Rcm,
	PS,
	SST,
	ECE,
	DCE,
	Oth
};

enum class AccessLevel
{
	Usr,
	CSUsr,
	RO,
	SP,
	Oth
};

enum class ChargeStatus
{
	Ful,
	ChB,
	DisChB,
	DEB
};

enum class Criticality
{
	Lo,
	Hi
};

class EnumToString {
public:
	EnumToString();
	virtual ~EnumToString();
	static std::string convert(MeasurementValidity source);
	static std::string convert(LocalizedTextWidth source);
	static std::string convert(SafetyClassification source);
	static std::string convert(ComponentActivation source);
	static std::string convert(CalibrationState source);
	static std::string convert(CalibrationType source);
	static std::string convert(MdsOperatingMode source);
	static std::string convert(AlertActivation source);
	static std::string convert(AlertConditionKind source);
	static std::string convert(AlertConditionPriority source);
	static std::string convert(AlertConditionMonitoredLimits source);
	static std::string convert(AlertSignalManifestation source);
	static std::string convert(AlertSignalPresence source);
	static std::string convert(AlertSignalPrimaryLocation source);
	static std::string convert(GenerationMode source);
	static std::string convert(MetricCategory source);
	static std::string convert(DerivationMethod source);
	static std::string convert(MetricAvailability source);
	static std::string convert(OperatingMode source);
	static std::string convert(ContextAssociation source);
	static std::string convert(Sex source);
	static std::string convert(PatientType source);
	static std::string convert(DicomTransferRole source);
	static std::string convert(CanEscalate source);
	static std::string convert(CanDeescalate source);
	static std::string convert(Kind source);
	static std::string convert(AccessLevel source);
	static std::string convert(ChargeStatus source);
	static std::string convert(Criticality source);

	// non-auto generated ending
	static std::string convert(InvocationState source);

};

} /* namespace SDC */
} /* namespace Data */
} /* namespace SDCLib */

#endif /* SIMPLETYPESMAPPING_H_ */

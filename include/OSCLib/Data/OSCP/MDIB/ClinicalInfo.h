/**
  * This program is free software: you can redistribute it and/or modify
  * it under the terms of the GNU General Public License as published by
  * the Free Software Foundation, either version 3 of the License, or
  * (at your option) any later version.
  *
  * This program is distributed in the hope that it will be useful,
  * but WITHOUT ANY WARRANTY; without even the implied warranty of
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  * GNU General Public License for more details.
  *
  * You should have received a copy of the GNU General Public License
  * along with this program.  If not, see <http://www.gnu.org/licenses/>.
  *
  */

/*
 *  ClinicalInfo.h
 *
 *  @Copyright (C) 2015, SurgiTAIX AG
 *  Author: besting, roehser
 */
 
/**
 * THIS FILE IS GENERATED AUTOMATICALLY! DO NOT MODIFY!
 *
 * YOUR CHANGES WILL BE OVERWRITTEN!
 * 
 * USE THE DEFINITION FILES IN THE FOLDER "codegenerator" INSTEAD!
 */

#ifndef CLINICALINFO_H_
#define CLINICALINFO_H_

#include "OSCLib/Data/OSCP/MDIB/SimpleTypesMapping.h"
#include "OSCLib/Data/OSCP/OSCP-fwd.h"
#include "osdm-fwd.hxx"

namespace OSCLib {
namespace Data {
namespace OSCP {

class ClinicalInfo {
private:
	ClinicalInfo(const CDM::ClinicalInfo & object);
	operator CDM::ClinicalInfo() const;
	friend class ConvertFromCDM;
	friend class ConvertToCDM;
public:
	ClinicalInfo();
	ClinicalInfo(const ClinicalInfo & object);
	virtual ~ClinicalInfo();
    
    void copyFrom(const ClinicalInfo & object);
    ClinicalInfo & operator=(const ClinicalInfo & object);
    
    typedef CDM::ClinicalInfo WrappedType;

	ClinicalInfo & setType(const CodedValue & value);
	CodedValue getType() const;
	bool getType(CodedValue & out) const;
	bool hasType() const;

	ClinicalInfo & setRelatedMeasurement(const RelatedMeasurementType & value);
	RelatedMeasurementType getRelatedMeasurement() const;

	ClinicalInfo & setValue(const Measurement & value);
	Measurement getValue() const;

	ClinicalInfo & setRange(const Range & value);
	Range getRange() const;

	ClinicalInfo & setMeaning(const CodedValue & value);
	CodedValue getMeaning() const;
	bool getMeaning(CodedValue & out) const;
	bool hasMeaning() const;

	ClinicalInfo & addDescription(const LocalizedText & value);
	std::vector<LocalizedText> getDescriptionLists() const;
	void clearDescriptionLists();
	
private:
	std::shared_ptr<CDM::ClinicalInfo> data;
};

} /* namespace OSCP */
} /* namespace Data */
} /* namespace OSCLib */
#endif /* CLINICALINFO_H_ */

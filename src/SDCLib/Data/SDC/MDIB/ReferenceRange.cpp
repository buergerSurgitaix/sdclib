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
 *  ReferenceRange.cpp
 *
 *  @Copyright (C) 2015, SurgiTAIX AG
 *  Author: besting, buerger, roehser
 */

/**
 * THIS FILE IS GENERATED AUTOMATICALLY! DO NOT MODIFY!
 *
 * YOUR CHANGES WILL BE OVERWRITTEN!
 *
 * USE THE DEFINITION FILES IN THE FOLDER "codegenerator" INSTEAD!
 */

#include "SDCLib/Data/SDC/MDIB/ReferenceRange.h"
#include "SDCLib/Data/SDC/MDIB/ConvertToCDM.h"
#include "SDCLib/Data/SDC/MDIB/ConvertFromCDM.h"
#include "SDCLib/Data/SDC/MDIB/Defaults.h"

#include "DataModel/osdm.hxx"

#include "SDCLib/Data/SDC/MDIB/Range.h"
#include "SDCLib/Data/SDC/MDIB/CodedValue.h"

namespace SDCLib {
namespace Data {
namespace SDC {


ReferenceRange::ReferenceRange(
		Range range
) : data(Defaults::ReferenceRangeInit(
		range
))
{}

ReferenceRange::operator CDM::ReferenceRange() const {
	return *data;
}

ReferenceRange::ReferenceRange(const CDM::ReferenceRange & object)
: data(new CDM::ReferenceRange(object))
{ }

ReferenceRange::ReferenceRange(const ReferenceRange & object)
: data(std::make_shared<CDM::ReferenceRange>(*object.data))
{ }

void ReferenceRange::copyFrom(const ReferenceRange & object) {
	data = std::make_shared<CDM::ReferenceRange>(*object.data);
}

ReferenceRange & ReferenceRange:: operator=(const ReferenceRange& object) {
	copyFrom(object);
	return *this;
}


ReferenceRange & ReferenceRange::setRange(const Range & value) {
	data->setRange(ConvertToCDM::convert(value));
	return *this;
}


Range ReferenceRange::getRange() const {
	return ConvertFromCDM::convert(data->getRange());
}

ReferenceRange & ReferenceRange::setMeaning(const CodedValue & value) {
	data->setMeaning(ConvertToCDM::convert(value));
	return *this;
}

bool ReferenceRange::getMeaning(CodedValue & out) const {
	if (data->getMeaning().present()) {
		out = ConvertFromCDM::convert(data->getMeaning().get());
		return true;
	}
	return false;
}

CodedValue ReferenceRange::getMeaning() const {
	return ConvertFromCDM::convert(data->getMeaning().get());
}

bool ReferenceRange::hasMeaning() const {
	return data->getMeaning().present();
}


} /* namespace SDC */
} /* namespace Data */
} /* namespace SDCLib */


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
 *  LocationContextState.cpp
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

#include "OSCLib/Data/OSCP/MDIB/LocationContextState.h"
#include "OSCLib/Data/OSCP/MDIB/ConvertToCDM.h"
#include "OSCLib/Data/OSCP/MDIB/ConvertFromCDM.h"
#include "OSCLib/Data/OSCP/MDIB/custom/Defaults.h"

#include "osdm.hxx"

#include "OSCLib/Data/OSCP/MDIB/LocationDetail.h"
#include "OSCLib/Data/OSCP/MDIB/InstanceIdentifier.h"
#include "OSCLib/Data/OSCP/MDIB/CodedValue.h"

namespace OSCLib {
namespace Data {
namespace OSCP {

LocationContextState::LocationContextState() : data(Defaults::LocationContextState()) {
}

LocationContextState::operator CDM::LocationContextState() const {
	return *data;
}

LocationContextState::LocationContextState(const CDM::LocationContextState & object) : data(new CDM::LocationContextState(object)) {

}

LocationContextState::LocationContextState(const LocationContextState & object) : data(new CDM::LocationContextState(*object.data)) {

}

LocationContextState::~LocationContextState() {

}

void LocationContextState::copyFrom(const LocationContextState & object) {
	*data = *object.data;
}

LocationContextState & LocationContextState:: operator=(const LocationContextState & object) {
	copyFrom(object);
	return *this;
}


LocationContextState & LocationContextState::setStateVersion(const VersionCounter & value) {
	data->StateVersion(ConvertToCDM::convert(value));
	return *this;
}


VersionCounter LocationContextState::getStateVersion() const {
	return ConvertFromCDM::convert(data->StateVersion());
}
	
LocationContextState & LocationContextState::setDescriptorHandle(const HandleRef & value) {
	data->DescriptorHandle(ConvertToCDM::convert(value));
	return *this;
}


HandleRef LocationContextState::getDescriptorHandle() const {
	return ConvertFromCDM::convert(data->DescriptorHandle());
}
	
LocationContextState & LocationContextState::setDescriptorVersion(const ReferencedVersion & value) {
	data->DescriptorVersion(ConvertToCDM::convert(value));
	return *this;
}


ReferencedVersion LocationContextState::getDescriptorVersion() const {
	return ConvertFromCDM::convert(data->DescriptorVersion());
}
	
LocationContextState & LocationContextState::setCategory(const CodedValue & value) {
	data->Category(ConvertToCDM::convert(value));
	return *this;
}

bool LocationContextState::getCategory(CodedValue & out) const {
	if (data->Category().present()) {
		out = ConvertFromCDM::convert(data->Category().get());
		return true;
	}
	return false;
}

CodedValue LocationContextState::getCategory() const {
	return ConvertFromCDM::convert(data->Category().get());
}
	
bool LocationContextState::hasCategory() const {
	return data->Category().present();
}
	
LocationContextState & LocationContextState::setHandle(const Handle & value) {
	data->Handle(ConvertToCDM::convert(value));
	return *this;
}


Handle LocationContextState::getHandle() const {
	return ConvertFromCDM::convert(data->Handle());
}
	
LocationContextState & LocationContextState::setContextAssociation(const ContextAssociation & value) {
	data->ContextAssociation(ConvertToCDM::convert(value));
	return *this;
}


ContextAssociation LocationContextState::getContextAssociation() const {
	return ConvertFromCDM::convert(data->ContextAssociation());
}
	
LocationContextState & LocationContextState::setBindingMdibVersion(const ReferencedVersion & value) {
	data->BindingMdibVersion(ConvertToCDM::convert(value));
	return *this;
}

bool LocationContextState::getBindingMdibVersion(ReferencedVersion & out) const {
	if (data->BindingMdibVersion().present()) {
		out = ConvertFromCDM::convert(data->BindingMdibVersion().get());
		return true;
	}
	return false;
}

ReferencedVersion LocationContextState::getBindingMdibVersion() const {
	return ConvertFromCDM::convert(data->BindingMdibVersion().get());
}
	
bool LocationContextState::hasBindingMdibVersion() const {
	return data->BindingMdibVersion().present();
}
	
LocationContextState & LocationContextState::setUnbindingMdibVersion(const ReferencedVersion & value) {
	data->UnbindingMdibVersion(ConvertToCDM::convert(value));
	return *this;
}


ReferencedVersion LocationContextState::getUnbindingMdibVersion() const {
	return ConvertFromCDM::convert(data->UnbindingMdibVersion());
}
	
LocationContextState & LocationContextState::setBindingStartTime(const Timestamp & value) {
	data->BindingStartTime(ConvertToCDM::convert(value));
	return *this;
}


Timestamp LocationContextState::getBindingStartTime() const {
	return ConvertFromCDM::convert(data->BindingStartTime());
}
	
LocationContextState & LocationContextState::setBindingEndTime(const Timestamp & value) {
	data->BindingEndTime(ConvertToCDM::convert(value));
	return *this;
}


Timestamp LocationContextState::getBindingEndTime() const {
	return ConvertFromCDM::convert(data->BindingEndTime());
}
	
LocationContextState & LocationContextState::addValidator(const InstanceIdentifier & value) {
	data->Validator().push_back(ConvertToCDM::convert(value));
	return *this;
}

std::vector<InstanceIdentifier> LocationContextState::getValidatorLists() const {
	std::vector<InstanceIdentifier> result;
	result.reserve(data->Validator().size());
	for (const auto & value: data->Validator()) {
		result.push_back(ConvertFromCDM::convert(value));
	}
	return result;
}

void LocationContextState::clearValidatorLists() {
	data->Validator().clear();
}

LocationContextState & LocationContextState::addIdentification(const InstanceIdentifier & value) {
	data->Identification().push_back(ConvertToCDM::convert(value));
	return *this;
}

std::vector<InstanceIdentifier> LocationContextState::getIdentificationLists() const {
	std::vector<InstanceIdentifier> result;
	result.reserve(data->Identification().size());
	for (const auto & value: data->Identification()) {
		result.push_back(ConvertFromCDM::convert(value));
	}
	return result;
}

void LocationContextState::clearIdentificationLists() {
	data->Identification().clear();
}

LocationContextState & LocationContextState::setLocationDetail(const LocationDetail & value) {
	data->LocationDetail(ConvertToCDM::convert(value));
	return *this;
}

bool LocationContextState::getLocationDetail(LocationDetail & out) const {
	if (data->LocationDetail().present()) {
		out = ConvertFromCDM::convert(data->LocationDetail().get());
		return true;
	}
	return false;
}

LocationDetail LocationContextState::getLocationDetail() const {
	return ConvertFromCDM::convert(data->LocationDetail().get());
}
	
bool LocationContextState::hasLocationDetail() const {
	return data->LocationDetail().present();
}
	

} /* namespace OSCP */
} /* namespace Data */
} /* namespace OSCLib */


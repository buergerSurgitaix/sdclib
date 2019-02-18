/*
 * test_ServiceProvider_MdsDescriptor_11073_10207_R0034.cpp
 *
 *  Created on: Dec 3, 2018
 *      Author: rosenau
 */

#include <iostream>
#include "OSCLib/Data/SDC/MDIB/MdsDescriptor.h"
#include "OSCLib/Data/SDC/MDIB/CodedValue.h"

using namespace SDCLib;
using namespace SDCLib::Data;
using namespace SDCLib::Data::SDC;

int main()
{
	std::cout << "Test against requirement 11073-10207-R0034: A Service PROVIDER SHALL "
			  << "increment pm:AbstractDescriptor/@DescriptorVersion by 1 if the content "
			  << "or an ATTRIBUTE of the descriptor have changed and if the child "
			  << "ELEMENT itself is not derived from pm:AbstractDescriptor"
			  << std::endl;

	MdsDescriptor mdsDescriptor("testMdsDescriptor");
	mdsDescriptor.setDescriptorVersion(0);
	mdsDescriptor.setHandle("changedTestMdsDescriptor");
	if(mdsDescriptor.getDescriptorVersion() != 1)
	{
		std::cout << "Version did not increase on changing handle, Version count: "
					  << mdsDescriptor.getDescriptorVersion()  << std::endl;
		std::cout << "Test failed" << std::endl;
		return 0;
	}
	mdsDescriptor.setSafetyClassification(SafetyClassification::Inf);
	if(mdsDescriptor.getDescriptorVersion() != 2)
	{
		std::cout << "Version did not increase on changing SafetyClassification, Version count: "
					  << mdsDescriptor.getDescriptorVersion()  << std::endl;
		std::cout << "Test failed" << std::endl;
		return 0;
	}
	mdsDescriptor.setType(CodedValue("testValue"));
	if (mdsDescriptor.getDescriptorVersion() != 3)
	{
		std::cout << "Version did not increase on changing Type, Version count: "
					  << mdsDescriptor.getDescriptorVersion()  << std::endl;
		std::cout << "Test failed" << std::endl;
		return 0;
	}
}




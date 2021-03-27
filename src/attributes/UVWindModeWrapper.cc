
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file UVWindModeAttributes.h
    \\brief Definition of UVWindMode Attributes class.

    This file is automatically generated.
    Do Not Edit!

*/

#include "MagRequest.h"
#include "UVWindModeWrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"
#include "MagicsGlobal.h"

using namespace magics;



UVWindModeWrapper::UVWindModeWrapper(): uvwindmode_(new UVWindMode())


{


	
	WindModeWrapper::object(uvwindmode_);
	

}
UVWindModeWrapper::UVWindModeWrapper(UVWindMode* uvwindmode): uvwindmode_(uvwindmode)
{

	
	WindModeWrapper::object(uvwindmode_);
	
}

UVWindModeWrapper::~UVWindModeWrapper()
{

}

void UVWindModeWrapper::set(const MagRequest& request)
{

	

	WindModeWrapper::set(request);
	

	
	
}

void UVWindModeWrapper::print(ostream& out)  const
{
	out << "UVWindModeWrapper[]";
}



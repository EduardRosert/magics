
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file PolyShadingMethodAttributes.h
    \\brief Definition of PolyShadingMethod Attributes class.

    This file is automatically generated.
    Do Not Edit!

*/

#include "MagRequest.h"
#include "PolyShadingMethodWrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"
#include "MagicsSettings.h"

using namespace magics;


PolyShadingMethodWrapper::PolyShadingMethodWrapper(): polyshadingmethod_(new PolyShadingMethod())

{


	

}
PolyShadingMethodWrapper::PolyShadingMethodWrapper(PolyShadingMethod* polyshadingmethod): polyshadingmethod_(polyshadingmethod)
{

	
}

PolyShadingMethodWrapper::~PolyShadingMethodWrapper()
{

}

void PolyShadingMethodWrapper::set(const MagRequest& request)
{

	

	
	
}

void PolyShadingMethodWrapper::print(ostream& out)  const
{
	out << "PolyShadingMethodWrapper[]";
}



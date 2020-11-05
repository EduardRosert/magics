
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file HyperAxisMethodAttributes.h
    \\brief Definition of HyperAxisMethod Attributes class.

    This file is automatically generated.
    Do Not Edit!
*/

#include "MagRequest.h" 
#include "HyperAxisMethodWrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"

using namespace magics;


HyperAxisMethodWrapper::HyperAxisMethodWrapper(): hyperaxismethod_(new HyperAxisMethod())

{

	
	
	AxisMethodWrapper::object(hyperaxismethod_);
	
	
} 
HyperAxisMethodWrapper::HyperAxisMethodWrapper(HyperAxisMethod* hyperaxismethod): hyperaxismethod_(hyperaxismethod)
{
	
	
	AxisMethodWrapper::object(hyperaxismethod_);
	
} 

HyperAxisMethodWrapper::~HyperAxisMethodWrapper()
{
	
}

void HyperAxisMethodWrapper::set(const MagRequest& request)
{
	
	
	
	AxisMethodWrapper::set(request);
	

	
	
}

void HyperAxisMethodWrapper::print(ostream& out)  const
{
	out << "HyperAxisMethodWrapper[]";
}


    




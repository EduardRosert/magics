
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file AutomaticContourMethodAttributes.h
    \\brief Definition of AutomaticContourMethod Attributes class.

    This file is automatically generated.
    Do Not Edit!
*/

#include "MagRequest.h" 
#include "AutomaticContourMethodWrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"

using namespace magics;



AutomaticContourMethodWrapper::AutomaticContourMethodWrapper(): automaticcontourmethod_(new AutomaticContourMethod())


{

	
	
	ContourMethodWrapper::object(automaticcontourmethod_);
	
	
} 
AutomaticContourMethodWrapper::AutomaticContourMethodWrapper(AutomaticContourMethod* automaticcontourmethod): automaticcontourmethod_(automaticcontourmethod)
{
	
	
	ContourMethodWrapper::object(automaticcontourmethod_);
	
} 

AutomaticContourMethodWrapper::~AutomaticContourMethodWrapper()
{
	
}

void AutomaticContourMethodWrapper::set(const MagRequest& request)
{
	
	
	
	ContourMethodWrapper::set(request);
	

	
	
}

void AutomaticContourMethodWrapper::print(ostream& out)  const
{
	out << "AutomaticContourMethodWrapper[]";
}


    




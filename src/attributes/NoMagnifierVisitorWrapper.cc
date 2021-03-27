
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file NoMagnifierVisitorAttributes.h
    \\brief Definition of NoMagnifierVisitor Attributes class.

    This file is automatically generated.
    Do Not Edit!
*/

#include "MagRequest.h" 
#include "NoMagnifierVisitorWrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"

using namespace magics;



NoMagnifierVisitorWrapper::NoMagnifierVisitorWrapper(): nomagnifiervisitor_(new NoMagnifierVisitor())


{

	
	
	
} 
NoMagnifierVisitorWrapper::NoMagnifierVisitorWrapper(NoMagnifierVisitor* nomagnifiervisitor): nomagnifiervisitor_(nomagnifiervisitor)
{
	
	
} 

NoMagnifierVisitorWrapper::~NoMagnifierVisitorWrapper()
{
	
}

void NoMagnifierVisitorWrapper::set(const MagRequest& request)
{
	
	

	
	
}

void NoMagnifierVisitorWrapper::print(ostream& out)  const
{
	out << "NoMagnifierVisitorWrapper[]";
}


    




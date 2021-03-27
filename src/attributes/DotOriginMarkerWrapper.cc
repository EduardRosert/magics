
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file DotOriginMarkerAttributes.h
    \\brief Definition of DotOriginMarker Attributes class.

    This file is automatically generated.
    Do Not Edit!
*/

#include "MagRequest.h" 
#include "DotOriginMarkerWrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"

using namespace magics;



DotOriginMarkerWrapper::DotOriginMarkerWrapper(): dotoriginmarker_(new DotOriginMarker())


{

	
	
	OriginMarkerWrapper::object(dotoriginmarker_);
	
	
} 
DotOriginMarkerWrapper::DotOriginMarkerWrapper(DotOriginMarker* dotoriginmarker): dotoriginmarker_(dotoriginmarker)
{
	
	
	OriginMarkerWrapper::object(dotoriginmarker_);
	
} 

DotOriginMarkerWrapper::~DotOriginMarkerWrapper()
{
	
}

void DotOriginMarkerWrapper::set(const MagRequest& request)
{
	
	
	
	OriginMarkerWrapper::set(request);
	

	
	
}

void DotOriginMarkerWrapper::print(ostream& out)  const
{
	out << "DotOriginMarkerWrapper[]";
}


    




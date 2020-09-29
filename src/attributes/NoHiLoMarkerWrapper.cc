
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file NoHiLoMarkerAttributes.h
    \\brief Definition of NoHiLoMarker Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 2020-09-24
*/

#include "MagRequest.h" 
#include "NoHiLoMarkerWrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"

using namespace magics;


NoHiLoMarkerWrapper::NoHiLoMarkerWrapper(): nohilomarker_(new NoHiLoMarker())

{

	
	
	HiLoMarkerBaseWrapper::object(nohilomarker_);
	
	
} 
NoHiLoMarkerWrapper::NoHiLoMarkerWrapper(NoHiLoMarker* nohilomarker): nohilomarker_(nohilomarker)
{
	
	
	HiLoMarkerBaseWrapper::object(nohilomarker_);
	
} 

NoHiLoMarkerWrapper::~NoHiLoMarkerWrapper()
{
	
}

void NoHiLoMarkerWrapper::set(const MagRequest& request)
{
	
	
	
	HiLoMarkerBaseWrapper::set(request);
	

	
	
}

void NoHiLoMarkerWrapper::print(ostream& out)  const
{
	out << "NoHiLoMarkerWrapper[]";
}


    





/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file OriginMarkerAttributes.h
    \\brief Definition of OriginMarker Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 2020-09-24
*/

#include "MagRequest.h" 
#include "OriginMarkerWrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"

using namespace magics;


OriginMarkerWrapper::OriginMarkerWrapper(): originmarker_(new OriginMarker())

{

	
	
	
} 
OriginMarkerWrapper::OriginMarkerWrapper(OriginMarker* originmarker): originmarker_(originmarker)
{
	
	
} 

OriginMarkerWrapper::~OriginMarkerWrapper()
{
	
}

void OriginMarkerWrapper::set(const MagRequest& request)
{
	
	

	
	
}

void OriginMarkerWrapper::print(ostream& out)  const
{
	out << "OriginMarkerWrapper[]";
}


    




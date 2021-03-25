
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file CairoDriverAttributes.h
    \\brief Definition of CairoDriver Attributes class.

    This file is automatically generated.
    Do Not Edit!
*/

#include "MagRequest.h" 
#include "CairoDriverWrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"

using namespace magics;


CairoDriverWrapper::CairoDriverWrapper(): cairodriver_(new CairoDriver())

{

	
	
	BaseDriverWrapper::object(cairodriver_);
	
	
} 
CairoDriverWrapper::CairoDriverWrapper(CairoDriver* cairodriver): cairodriver_(cairodriver)
{
	
	
	BaseDriverWrapper::object(cairodriver_);
	
} 

CairoDriverWrapper::~CairoDriverWrapper()
{
	
}

void CairoDriverWrapper::set(const MagRequest& request)
{
	
	
	
	BaseDriverWrapper::set(request);
	

	if  (request.countValues("OUTPUT_CAIRO_TRANSPARENT_BACKGROUND") ) {
		string transparent_value = request("OUTPUT_CAIRO_TRANSPARENT_BACKGROUND");
		cairodriver_->transparent_ = transparent_value;
		}
	if  (request.countValues("OUTPUT_CAIRO_ANTIALIAS") ) {
		string antialias_value = request("OUTPUT_CAIRO_ANTIALIAS");
		cairodriver_->antialias_ = antialias_value;
		}
	if  (request.countValues("OUTPUT_CAIRO_PALETTE") ) {
		string palette_value = request("OUTPUT_CAIRO_PALETTE");
		cairodriver_->palette_ = palette_value;
		}
	if  (request.countValues("OUTPUT_GEOTIFF_QUALITY") ) {
		int quality_value = request("OUTPUT_GEOTIFF_QUALITY");
		cairodriver_->quality_ = quality_value;
		}
	
	
}

void CairoDriverWrapper::print(ostream& out)  const
{
	out << "CairoDriverWrapper[]";
}


    




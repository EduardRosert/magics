
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file SVGDriverAttributes.h
    \\brief Definition of SVGDriver Attributes class.

    This file is automatically generated.
    Do Not Edit!

*/

#include "MagRequest.h"
#include "SVGDriverWrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"
#include "MagicsGlobal.h"

using namespace magics;


SVGDriverWrapper::SVGDriverWrapper(): svgdriver_(new SVGDriver())

{


	
	BaseDriverWrapper::object(svgdriver_);
	

}
SVGDriverWrapper::SVGDriverWrapper(SVGDriver* svgdriver): svgdriver_(svgdriver)
{

	
	BaseDriverWrapper::object(svgdriver_);
	
}

SVGDriverWrapper::~SVGDriverWrapper()
{

}

void SVGDriverWrapper::set(const MagRequest& request)
{

	

	BaseDriverWrapper::set(request);
	

	if  (request.countValues("OUTPUT_SVG_LOGO_LOCATION") ) {
		string logoLocation_value = request("OUTPUT_SVG_LOGO_LOCATION");
		svgdriver_->logoLocation_ = logoLocation_value;
		}
	if  (request.countValues("OUTPUT_SVG_DESC") ) {
		string desc_value = request("OUTPUT_SVG_DESC");
		svgdriver_->desc_ = desc_value;
		}
	if  (request.countValues("OUTPUT_SVG_META") ) {
		string meta_value = request("OUTPUT_SVG_META");
		svgdriver_->meta_ = meta_value;
		}
	if  (request.countValues("OUTPUT_SVG_USE_EXTERNAL_FILES") ) {
		string external_value = request("OUTPUT_SVG_USE_EXTERNAL_FILES");
		svgdriver_->external_ = MagTranslator<string, bool>()(external_value);
		}
	if  (request.countValues("OUTPUT_SVG_FIX_SIZE") ) {
		string fixSize_value = request("OUTPUT_SVG_FIX_SIZE");
		svgdriver_->fixSize_ = MagTranslator<string, bool>()(fixSize_value);
		}
	
	
}

void SVGDriverWrapper::print(ostream& out)  const
{
	out << "SVGDriverWrapper[]";
}



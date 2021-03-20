
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file GeoRectangularProjectionAttributes.h
    \\brief Definition of GeoRectangularProjection Attributes class.

    This file is automatically generated.
    Do Not Edit!

*/

#include "MagRequest.h"
#include "GeoRectangularProjectionWrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"
#include "MagicsGlobal.h"

using namespace magics;


GeoRectangularProjectionWrapper::GeoRectangularProjectionWrapper(): georectangularprojection_(new GeoRectangularProjection())

{


	
	TransformationWrapper::object(georectangularprojection_);
	

}
GeoRectangularProjectionWrapper::GeoRectangularProjectionWrapper(GeoRectangularProjection* georectangularprojection): georectangularprojection_(georectangularprojection)
{

	
	TransformationWrapper::object(georectangularprojection_);
	
}

GeoRectangularProjectionWrapper::~GeoRectangularProjectionWrapper()
{

}

void GeoRectangularProjectionWrapper::set(const MagRequest& request)
{

	

	TransformationWrapper::set(request);
	

	if  (request.countValues("SUBPAGE_LOWER_LEFT_LATITUDE") ) {
		double min_latitude_value = request("SUBPAGE_LOWER_LEFT_LATITUDE");
		georectangularprojection_->min_latitude_ = min_latitude_value;
		}
	if  (request.countValues("SUBPAGE_LOWER_LEFT_LONGITUDE") ) {
		double min_longitude_value = request("SUBPAGE_LOWER_LEFT_LONGITUDE");
		georectangularprojection_->min_longitude_ = min_longitude_value;
		}
	if  (request.countValues("SUBPAGE_UPPER_RIGHT_LATITUDE") ) {
		double max_latitude_value = request("SUBPAGE_UPPER_RIGHT_LATITUDE");
		georectangularprojection_->max_latitude_ = max_latitude_value;
		}
	if  (request.countValues("SUBPAGE_UPPER_RIGHT_LONGITUDE") ) {
		double max_longitude_value = request("SUBPAGE_UPPER_RIGHT_LONGITUDE");
		georectangularprojection_->max_longitude_ = max_longitude_value;
		}
	if  (request.countValues("SUBPAGE_MINIMAL_AREA") ) {
		double min_area_value = request("SUBPAGE_MINIMAL_AREA");
		georectangularprojection_->min_area_ = min_area_value;
		}
	
	
}

void GeoRectangularProjectionWrapper::print(ostream& out)  const
{
	out << "GeoRectangularProjectionWrapper[]";
}



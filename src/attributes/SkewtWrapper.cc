
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file SkewtAttributes.h
    \\brief Definition of Skewt Attributes class.

    This file is automatically generated.
    Do Not Edit!

*/

#include "MagRequest.h"
#include "SkewtWrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"
#include "MagicsGlobal.h"

using namespace magics;



SkewtWrapper::SkewtWrapper(): skewt_(new Skewt())


{


	
	TransformationWrapper::object(skewt_);
	

}
SkewtWrapper::SkewtWrapper(Skewt* skewt): skewt_(skewt)
{

	
	TransformationWrapper::object(skewt_);
	
}

SkewtWrapper::~SkewtWrapper()
{

}

void SkewtWrapper::set(const MagRequest& request)
{

	

	TransformationWrapper::set(request);
	

	if  (request.countValues("X_MIN") ) {
		double x_min_value = request("X_MIN");
		skewt_->x_min_ = x_min_value;
		}
	if  (request.countValues("SUBPAGE_X_AUTOMATIC") ) {
		string x_automatic_value = request("SUBPAGE_X_AUTOMATIC");
		
		skewt_->x_automatic_ = MagTranslator<string, bool>()(x_automatic_value);
		
		}
	if  (request.countValues("SUBPAGE_Y_AUTOMATIC") ) {
		string y_automatic_value = request("SUBPAGE_Y_AUTOMATIC");
		
		skewt_->y_automatic_ = MagTranslator<string, bool>()(y_automatic_value);
		
		}
	if  (request.countValues("X_MAX") ) {
		double x_max_value = request("X_MAX");
		skewt_->x_max_ = x_max_value;
		}
	if  (request.countValues("Y_MIN") ) {
		double y_min_value = request("Y_MIN");
		skewt_->y_min_ = y_min_value;
		}
	if  (request.countValues("Y_MAX") ) {
		double y_max_value = request("Y_MAX");
		skewt_->y_max_ = y_max_value;
		}
	if  (request.countValues("THERMO_ANNOTATION_WIDTH") ) {
		double annotation_width_value = request("THERMO_ANNOTATION_WIDTH");
		skewt_->annotation_width_ = annotation_width_value;
		}
	
	
}

void SkewtWrapper::print(ostream& out)  const
{
	out << "SkewtWrapper[]";
}



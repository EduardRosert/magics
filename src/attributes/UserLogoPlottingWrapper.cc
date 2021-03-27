
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file UserLogoPlottingAttributes.h
    \\brief Definition of UserLogoPlotting Attributes class.

    This file is automatically generated.
    Do Not Edit!
*/

#include "MagRequest.h" 
#include "UserLogoPlottingWrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"

using namespace magics;



UserLogoPlottingWrapper::UserLogoPlottingWrapper(): userlogoplotting_(new UserLogoPlotting())


{

	
	
	NoLogoPlottingWrapper::object(userlogoplotting_);
	
	
} 
UserLogoPlottingWrapper::UserLogoPlottingWrapper(UserLogoPlotting* userlogoplotting): userlogoplotting_(userlogoplotting)
{
	
	
	NoLogoPlottingWrapper::object(userlogoplotting_);
	
} 

UserLogoPlottingWrapper::~UserLogoPlottingWrapper()
{
	
}

void UserLogoPlottingWrapper::set(const MagRequest& request)
{
	
	
	
	NoLogoPlottingWrapper::set(request);
	

	if  (request.countValues("USER_LOGO_FILENAME") ) {
		string path_value = request("USER_LOGO_FILENAME");
		userlogoplotting_->path_ = path_value;
		}
	if  (request.countValues("USER_LOGO_FORMAT") ) {
		string format_value = request("USER_LOGO_FORMAT");
		userlogoplotting_->format_ = format_value;
		}
	if  (request.countValues("USER_LOGO_POSITION_UNITS") ) {
		string units_value = request("USER_LOGO_POSITION_UNITS");
		userlogoplotting_->units_ = units_value;
		}
	if  (request.countValues("USER_LOGO_Y_POSITION") ) {
		double y_value = request("USER_LOGO_Y_POSITION");
		userlogoplotting_->y_ = y_value;
		}
	if  (request.countValues("USER_LOGO_X_POSITION") ) {
		double x_value = request("USER_LOGO_X_POSITION");
		userlogoplotting_->x_ = x_value;
		}
	if  (request.countValues("USER_LOGO_BOTTOM") ) {
		string bottom_value = request("USER_LOGO_BOTTOM");
		userlogoplotting_->bottom_ = bottom_value;
		}
	if  (request.countValues("USER_LOGO_LEFT") ) {
		string left_value = request("USER_LOGO_LEFT");
		userlogoplotting_->left_ = left_value;
		}
	if  (request.countValues("USER_LOGO_WIDTH") ) {
		double width_value = request("USER_LOGO_WIDTH");
		userlogoplotting_->width_ = width_value;
		}
	if  (request.countValues("USER_LOGO_HEIGHT") ) {
		double height_value = request("USER_LOGO_HEIGHT");
		userlogoplotting_->height_ = height_value;
		}
	
	
}

void UserLogoPlottingWrapper::print(ostream& out)  const
{
	out << "UserLogoPlottingWrapper[]";
}


    





/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file XDateCoordinateAttributes.h
    \\brief Definition of XDateCoordinate Attributes class.

    This file is automatically generated.
    Do Not Edit!

*/

#include "MagRequest.h"
#include "XDateCoordinateWrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"
#include "MagicsGlobal.h"

using namespace magics;


XDateCoordinateWrapper::XDateCoordinateWrapper(): xdatecoordinate_(new XDateCoordinate())

{


	
	XCoordinateWrapper::object(xdatecoordinate_);
	

}
XDateCoordinateWrapper::XDateCoordinateWrapper(XDateCoordinate* xdatecoordinate): xdatecoordinate_(xdatecoordinate)
{

	
	XCoordinateWrapper::object(xdatecoordinate_);
	
}

XDateCoordinateWrapper::~XDateCoordinateWrapper()
{

}

void XDateCoordinateWrapper::set(const MagRequest& request)
{

	

	XCoordinateWrapper::set(request);
	

	if  (request.countValues("X_DATE_MIN") ) {
		string date_min_value = request("X_DATE_MIN");
		xdatecoordinate_->date_min_ = date_min_value;
		}
	if  (request.countValues("X_DATE_MAX") ) {
		string date_max_value = request("X_DATE_MAX");
		xdatecoordinate_->date_max_ = date_max_value;
		}
	if  (request.countValues("X_AUTOMATIC_REVERSE") ) {
		string reverse_value = request("X_AUTOMATIC_REVERSE");
		xdatecoordinate_->reverse_ = MagTranslator<string, bool>()(reverse_value);
		}
	
	
	if  (request.countValues("X_AUTOMATIC") ) {
		string automatic_value = request("X_AUTOMATIC");
		xdatecoordinate_->automatic_ = MagTranslator<string, AxisAutomaticSetting>()(automatic_value);
	}
		
	
}

void XDateCoordinateWrapper::print(ostream& out)  const
{
	out << "XDateCoordinateWrapper[]";
}




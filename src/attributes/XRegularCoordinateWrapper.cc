
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file XRegularCoordinateAttributes.h
    \\brief Definition of XRegularCoordinate Attributes class.

    This file is automatically generated.
    Do Not Edit!

*/

#include "MagRequest.h"
#include "XRegularCoordinateWrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"
#include "MagicsGlobal.h"

using namespace magics;


XRegularCoordinateWrapper::XRegularCoordinateWrapper(): xregularcoordinate_(new XRegularCoordinate())

{


	
	XCoordinateWrapper::object(xregularcoordinate_);
	

}
XRegularCoordinateWrapper::XRegularCoordinateWrapper(XRegularCoordinate* xregularcoordinate): xregularcoordinate_(xregularcoordinate)
{

	
	XCoordinateWrapper::object(xregularcoordinate_);
	
}

XRegularCoordinateWrapper::~XRegularCoordinateWrapper()
{

}

void XRegularCoordinateWrapper::set(const MagRequest& request)
{

	

	XCoordinateWrapper::set(request);
	

	if  (request.countValues("X_MIN") ) {
		double min_value = request("X_MIN");
		xregularcoordinate_->min_ = min_value;
		}
	if  (request.countValues("X_MAX") ) {
		double max_value = request("X_MAX");
		xregularcoordinate_->max_ = max_value;
		}
	if  (request.countValues("X_AUTOMATIC_REVERSE") ) {
		string reverse_value = request("X_AUTOMATIC_REVERSE");
		xregularcoordinate_->reverse_ = MagTranslator<string, bool>()(reverse_value);
		}
	
	
	if  (request.countValues("X_AUTOMATIC") ) {
		string automatic_value = request("X_AUTOMATIC");
		xregularcoordinate_->automatic_ = MagTranslator<string, AxisAutomaticSetting>()(automatic_value);
	}
		
	
}

void XRegularCoordinateWrapper::print(ostream& out)  const
{
	out << "XRegularCoordinateWrapper[]";
}




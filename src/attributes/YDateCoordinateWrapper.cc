
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file YDateCoordinateAttributes.h
    \\brief Definition of YDateCoordinate Attributes class.

    This file is automatically generated.
    Do Not Edit!

*/

#include "MagRequest.h"
#include "YDateCoordinateWrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"
#include "MagicsGlobal.h"

using namespace magics;



YDateCoordinateWrapper::YDateCoordinateWrapper(): ydatecoordinate_(new YDateCoordinate())


{


	
	YCoordinateWrapper::object(ydatecoordinate_);
	

}
YDateCoordinateWrapper::YDateCoordinateWrapper(YDateCoordinate* ydatecoordinate): ydatecoordinate_(ydatecoordinate)
{

	
	YCoordinateWrapper::object(ydatecoordinate_);
	
}

YDateCoordinateWrapper::~YDateCoordinateWrapper()
{

}

void YDateCoordinateWrapper::set(const MagRequest& request)
{

	

	YCoordinateWrapper::set(request);
	

	if  (request.countValues("Y_DATE_MIN") ) {
		string date_min_value = request("Y_DATE_MIN");
		ydatecoordinate_->date_min_ = date_min_value;
		}
	if  (request.countValues("Y_DATE_MAX") ) {
		string date_max_value = request("Y_DATE_MAX");
		ydatecoordinate_->date_max_ = date_max_value;
		}
	if  (request.countValues("Y_AUTOMATIC_REVERSE") ) {
		string reverse_value = request("Y_AUTOMATIC_REVERSE");
		
		ydatecoordinate_->reverse_ = MagTranslator<string, bool>()(reverse_value);
		
		}
	
	
	if  (request.countValues("Y_AUTOMATIC") ) {
		string automatic_value = request("Y_AUTOMATIC");
		ydatecoordinate_->automatic_ = MagTranslator<string, AxisAutomaticSetting>()(automatic_value);
	}
		
	
}

void YDateCoordinateWrapper::print(ostream& out)  const
{
	out << "YDateCoordinateWrapper[]";
}





/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file LevelSelectionAttributes.h
    \\brief Definition of LevelSelection Attributes class.

    This file is automatically generated.
    Do Not Edit!

*/

#include "MagRequest.h"
#include "LevelSelectionWrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"
#include "MagicsGlobal.h"

using namespace magics;



LevelSelectionWrapper::LevelSelectionWrapper(): levelselection_(new LevelSelection())


{


	

}
LevelSelectionWrapper::LevelSelectionWrapper(LevelSelection* levelselection): levelselection_(levelselection)
{

	
}

LevelSelectionWrapper::~LevelSelectionWrapper()
{

}

void LevelSelectionWrapper::set(const MagRequest& request)
{

	

	if  (request.countValues("CONTOUR_MAX_LEVEL") ) {
		double max_value = request("CONTOUR_MAX_LEVEL");
		levelselection_->max_ = max_value;
		}
	if  (request.countValues("CONTOUR_MIN_LEVEL") ) {
		double min_value = request("CONTOUR_MIN_LEVEL");
		levelselection_->min_ = min_value;
		}
	if  (request.countValues("CONTOUR_SHADE_MAX_LEVEL") ) {
		double max_shade_value = request("CONTOUR_SHADE_MAX_LEVEL");
		levelselection_->max_shade_ = max_shade_value;
		}
	if  (request.countValues("CONTOUR_SHADE_MIN_LEVEL") ) {
		double min_shade_value = request("CONTOUR_SHADE_MIN_LEVEL");
		levelselection_->min_shade_ = min_shade_value;
		}
	
	
}

void LevelSelectionWrapper::print(ostream& out)  const
{
	out << "LevelSelectionWrapper[]";
}



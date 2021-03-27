
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file TaylorProjectionAttributes.h
    \\brief Definition of TaylorProjection Attributes class.

    This file is automatically generated.
    Do Not Edit!
*/

#include "MagRequest.h" 
#include "TaylorProjectionWrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"

using namespace magics;



TaylorProjectionWrapper::TaylorProjectionWrapper(): taylorprojection_(new TaylorProjection())


{

	
	
	TransformationWrapper::object(taylorprojection_);
	
	
} 
TaylorProjectionWrapper::TaylorProjectionWrapper(TaylorProjection* taylorprojection): taylorprojection_(taylorprojection)
{
	
	
	TransformationWrapper::object(taylorprojection_);
	
} 

TaylorProjectionWrapper::~TaylorProjectionWrapper()
{
	
}

void TaylorProjectionWrapper::set(const MagRequest& request)
{
	
	
	
	TransformationWrapper::set(request);
	

	if  (request.countValues("TAYLOR_STANDARD_DEVIATION_MIN") ) {
		double min_value = request("TAYLOR_STANDARD_DEVIATION_MIN");
		taylorprojection_->min_ = min_value;
		}
	if  (request.countValues("TAYLOR_STANDARD_DEVIATION_MAX") ) {
		double max_value = request("TAYLOR_STANDARD_DEVIATION_MAX");
		taylorprojection_->max_ = max_value;
		}
	
	
}

void TaylorProjectionWrapper::print(ostream& out)  const
{
	out << "TaylorProjectionWrapper[]";
}


    




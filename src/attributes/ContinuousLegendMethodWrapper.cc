
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file ContinuousLegendMethodAttributes.h
    \\brief Definition of ContinuousLegendMethod Attributes class.

    This file is automatically generated.
    Do Not Edit!
*/

#include "MagRequest.h" 
#include "ContinuousLegendMethodWrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"

using namespace magics;


ContinuousLegendMethodWrapper::ContinuousLegendMethodWrapper(): continuouslegendmethod_(new ContinuousLegendMethod())

{

	
	
	LegendMethodWrapper::object(continuouslegendmethod_);
	
	
} 
ContinuousLegendMethodWrapper::ContinuousLegendMethodWrapper(ContinuousLegendMethod* continuouslegendmethod): continuouslegendmethod_(continuouslegendmethod)
{
	
	
	LegendMethodWrapper::object(continuouslegendmethod_);
	
} 

ContinuousLegendMethodWrapper::~ContinuousLegendMethodWrapper()
{
	
}

void ContinuousLegendMethodWrapper::set(const MagRequest& request)
{
	
	
	
	LegendMethodWrapper::set(request);
	

	if  (request.countValues("LEGEND_LABEL_FREQUENCY") ) {
		int label_frequency_value = request("LEGEND_LABEL_FREQUENCY");
		continuouslegendmethod_->label_frequency_ = label_frequency_value;
		}
	
	
}

void ContinuousLegendMethodWrapper::print(ostream& out)  const
{
	out << "ContinuousLegendMethodWrapper[]";
}


    




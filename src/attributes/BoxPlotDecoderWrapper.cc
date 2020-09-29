
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file BoxPlotDecoderAttributes.h
    \\brief Definition of BoxPlotDecoder Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 2020-09-24
*/

#include "MagRequest.h" 
#include "BoxPlotDecoderWrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"

using namespace magics;


BoxPlotDecoderWrapper::BoxPlotDecoderWrapper(): boxplotdecoder_(new BoxPlotDecoder())

{

	
	
	
} 
BoxPlotDecoderWrapper::BoxPlotDecoderWrapper(BoxPlotDecoder* boxplotdecoder): boxplotdecoder_(boxplotdecoder)
{
	
	
} 

BoxPlotDecoderWrapper::~BoxPlotDecoderWrapper()
{
	
}

void BoxPlotDecoderWrapper::set(const MagRequest& request)
{
	
	

	doublearray  x_value;
	for (int i = 0; i < request.countValues("BOXPLOT_POSITIONS"); i++)
		x_value.push_back((double)request("BOXPLOT_POSITIONS", i));
	if ( !x_value.empty() ) 
		boxplotdecoder_->x_ = x_value;
	stringarray  date_x_value;
	for (int i = 0; i < request.countValues("BOXPLOT_DATE_POSITIONS"); i++)
		date_x_value.push_back((string)request("BOXPLOT_DATE_POSITIONS", i));
	if ( !date_x_value.empty() ) 
		boxplotdecoder_->date_x_ = date_x_value;
	doublearray  min_value;
	for (int i = 0; i < request.countValues("BOXPLOT_MINIMUM_VALUES"); i++)
		min_value.push_back((double)request("BOXPLOT_MINIMUM_VALUES", i));
	if ( !min_value.empty() ) 
		boxplotdecoder_->min_ = min_value;
	doublearray  max_value;
	for (int i = 0; i < request.countValues("BOXPLOT_MAXIMUM_VALUES"); i++)
		max_value.push_back((double)request("BOXPLOT_MAXIMUM_VALUES", i));
	if ( !max_value.empty() ) 
		boxplotdecoder_->max_ = max_value;
	doublearray  upper_value;
	for (int i = 0; i < request.countValues("BOXPLOT_BOX_UPPER_VALUES"); i++)
		upper_value.push_back((double)request("BOXPLOT_BOX_UPPER_VALUES", i));
	if ( !upper_value.empty() ) 
		boxplotdecoder_->upper_ = upper_value;
	doublearray  lower_value;
	for (int i = 0; i < request.countValues("BOXPLOT_BOX_LOWER_VALUES"); i++)
		lower_value.push_back((double)request("BOXPLOT_BOX_LOWER_VALUES", i));
	if ( !lower_value.empty() ) 
		boxplotdecoder_->lower_ = lower_value;
	doublearray  median_value;
	for (int i = 0; i < request.countValues("BOXPLOT_MEDIAN_VALUES"); i++)
		median_value.push_back((double)request("BOXPLOT_MEDIAN_VALUES", i));
	if ( !median_value.empty() ) 
		boxplotdecoder_->median_ = median_value;
	
	
}

void BoxPlotDecoderWrapper::print(ostream& out)  const
{
	out << "BoxPlotDecoderWrapper[]";
}


    




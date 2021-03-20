
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file BoxPlotMedianAttributes.h
    \\brief Definition of BoxPlotMedian Attributes class.

    This file is automatically generated.
    Do Not Edit!

*/

#include "MagRequest.h"
#include "BoxPlotMedianWrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"
#include "MagicsGlobal.h"

using namespace magics;


BoxPlotMedianWrapper::BoxPlotMedianWrapper(): boxplotmedian_(new BoxPlotMedian())

{


	
	NoBoxPlotMedianWrapper::object(boxplotmedian_);
	

}
BoxPlotMedianWrapper::BoxPlotMedianWrapper(BoxPlotMedian* boxplotmedian): boxplotmedian_(boxplotmedian)
{

	
	NoBoxPlotMedianWrapper::object(boxplotmedian_);
	
}

BoxPlotMedianWrapper::~BoxPlotMedianWrapper()
{

}

void BoxPlotMedianWrapper::set(const MagRequest& request)
{

	

	NoBoxPlotMedianWrapper::set(request);
	

	if  (request.countValues("BOXPLOT_MEDIAN_THICKNESS") ) {
		int thickness_value = request("BOXPLOT_MEDIAN_THICKNESS");
		boxplotmedian_->thickness_ = thickness_value;
		}
	
	if  (request.countValues("BOXPLOT_MEDIAN_COLOUR") ) {
		string colour_value = request("BOXPLOT_MEDIAN_COLOUR");
		boxplotmedian_->colour_ = unique_ptr<Colour>(MagTranslator<string, Colour>()(colour_value));
	}
		
	
	if  (request.countValues("BOXPLOT_MEDIAN_LINE_STYLE") ) {
		string style_value = request("BOXPLOT_MEDIAN_LINE_STYLE");
		boxplotmedian_->style_ = MagTranslator<string, LineStyle>()(style_value);
	}
		
	
}

void BoxPlotMedianWrapper::print(ostream& out)  const
{
	out << "BoxPlotMedianWrapper[]";
}





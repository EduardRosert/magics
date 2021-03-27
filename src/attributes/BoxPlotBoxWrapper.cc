
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file BoxPlotBoxAttributes.h
    \\brief Definition of BoxPlotBox Attributes class.

    This file is automatically generated.
    Do Not Edit!

*/

#include "MagRequest.h"
#include "BoxPlotBoxWrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"
#include "MagicsGlobal.h"

using namespace magics;



BoxPlotBoxWrapper::BoxPlotBoxWrapper(): boxplotbox_(new BoxPlotBox())


{


	

}
BoxPlotBoxWrapper::BoxPlotBoxWrapper(BoxPlotBox* boxplotbox): boxplotbox_(boxplotbox)
{

	
}

BoxPlotBoxWrapper::~BoxPlotBoxWrapper()
{

}

void BoxPlotBoxWrapper::set(const MagRequest& request)
{

	

	if  (request.countValues("BOXPLOT_BOX_WIDTH") ) {
		double width_value = request("BOXPLOT_BOX_WIDTH");
		boxplotbox_->width_ = width_value;
		}
	
	if  (request.countValues("BOXPLOT_BOX_COLOUR") ) {
		string colour_value = request("BOXPLOT_BOX_COLOUR");
		boxplotbox_->colour_ = unique_ptr<Colour>(MagTranslator<string, Colour>()(colour_value));
	}
		
	
		string border_value = request.countValues("BOXPLOT_BOX_BORDER") ?  (string) request("BOXPLOT_BOX_BORDER") : "on";
	MagLog::debug() << " BOXPLOT_BOX_BORDER set to " << border_value << endl;
	NoBoxPlotBoxBorderWrapper* border_wrapper = 0;
	try
	{
		border_wrapper = SimpleFactory<NoBoxPlotBoxBorderWrapper>::create(border_value);
	}
	 catch (NoFactoryException&) {
		if (MagicsGlobal::strict()) {
            throw;
        }
		MagLog::warning() << "[" << border_value << "] is not a valid value for border: reset to default -> [on]" << endl;
		border_wrapper = SimpleFactory<NoBoxPlotBoxBorderWrapper>::create("on");
	}
	border_wrapper->set(request);
	boxplotbox_->border_ =  unique_ptr<NoBoxPlotBoxBorder>(border_wrapper->object());
	delete border_wrapper;
	
		string median_value = request.countValues("BOXPLOT_MEDIAN") ?  (string) request("BOXPLOT_MEDIAN") : "on";
	MagLog::debug() << " BOXPLOT_MEDIAN set to " << median_value << endl;
	NoBoxPlotMedianWrapper* median_wrapper = 0;
	try
	{
		median_wrapper = SimpleFactory<NoBoxPlotMedianWrapper>::create(median_value);
	}
	 catch (NoFactoryException&) {
		if (MagicsGlobal::strict()) {
            throw;
        }
		MagLog::warning() << "[" << median_value << "] is not a valid value for median: reset to default -> [on]" << endl;
		median_wrapper = SimpleFactory<NoBoxPlotMedianWrapper>::create("on");
	}
	median_wrapper->set(request);
	boxplotbox_->median_ =  unique_ptr<NoBoxPlotMedian>(median_wrapper->object());
	delete median_wrapper;
	
}

void BoxPlotBoxWrapper::print(ostream& out)  const
{
	out << "BoxPlotBoxWrapper[]";
}



#include "BoxPlotBoxBorderWrapper.h"
static SimpleObjectMaker<BoxPlotBoxBorder, NoBoxPlotBoxBorder> BoxPlotBox_boxplot_box_border_border ("border");
static SimpleObjectMaker<BoxPlotBoxBorderWrapper, NoBoxPlotBoxBorderWrapper> BoxPlotBox_boxplot_box_border_border_wrapper ("border");


#include "BoxPlotBoxBorderWrapper.h"
static SimpleObjectMaker<BoxPlotBoxBorder, NoBoxPlotBoxBorder> BoxPlotBox_boxplot_box_border_on ("on");
static SimpleObjectMaker<BoxPlotBoxBorderWrapper, NoBoxPlotBoxBorderWrapper> BoxPlotBox_boxplot_box_border_on_wrapper ("on");


#include "NoBoxPlotBoxBorderWrapper.h"

static SimpleObjectMaker<NoBoxPlotBoxBorderWrapper> BoxPlotBox_boxplot_box_border_noborder_Wrapper("noborder");


#include "NoBoxPlotBoxBorderWrapper.h"

static SimpleObjectMaker<NoBoxPlotBoxBorderWrapper> BoxPlotBox_boxplot_box_border_off_Wrapper("off");



#include "BoxPlotMedianWrapper.h"
static SimpleObjectMaker<BoxPlotMedian, NoBoxPlotMedian> BoxPlotBox_boxplot_median_median ("median");
static SimpleObjectMaker<BoxPlotMedianWrapper, NoBoxPlotMedianWrapper> BoxPlotBox_boxplot_median_median_wrapper ("median");


#include "BoxPlotMedianWrapper.h"
static SimpleObjectMaker<BoxPlotMedian, NoBoxPlotMedian> BoxPlotBox_boxplot_median_on ("on");
static SimpleObjectMaker<BoxPlotMedianWrapper, NoBoxPlotMedianWrapper> BoxPlotBox_boxplot_median_on_wrapper ("on");


#include "NoBoxPlotMedianWrapper.h"

static SimpleObjectMaker<NoBoxPlotMedianWrapper> BoxPlotBox_boxplot_median_nomedian_Wrapper("nomedian");


#include "NoBoxPlotMedianWrapper.h"

static SimpleObjectMaker<NoBoxPlotMedianWrapper> BoxPlotBox_boxplot_median_off_Wrapper("off");




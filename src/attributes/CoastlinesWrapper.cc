
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file CoastlinesAttributes.h
    \\brief Definition of Coastlines Attributes class.

    This file is automatically generated.
    Do Not Edit!

*/

#include "MagRequest.h"
#include "CoastlinesWrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"
#include "MagicsGlobal.h"

using namespace magics;



CoastlinesWrapper::CoastlinesWrapper(): coastlines_(new Coastlines())


{


	

}
CoastlinesWrapper::CoastlinesWrapper(Coastlines* coastlines): coastlines_(coastlines)
{

	
}

CoastlinesWrapper::~CoastlinesWrapper()
{

}

void CoastlinesWrapper::set(const MagRequest& request)
{

	

	if  (request.countValues("MAP_COASTLINE_GENERAL_STYLE") ) {
		string style_value = request("MAP_COASTLINE_GENERAL_STYLE");
		coastlines_->style_ = style_value;
		}
	
	
		string coastlines_value = request.countValues("MAP_COASTLINE") ?  (string) request("MAP_COASTLINE") : "on";
	MagLog::debug() << " MAP_COASTLINE set to " << coastlines_value << endl;
	NoCoastPlottingWrapper* coastlines_wrapper = 0;
	try
	{
		coastlines_wrapper = SimpleFactory<NoCoastPlottingWrapper>::create(coastlines_value);
	}
	 catch (NoFactoryException&) {
		if (MagicsGlobal::strict()) {
            throw;
        }
		MagLog::warning() << "[" << coastlines_value << "] is not a valid value for coastlines: reset to default -> [on]" << endl;
		coastlines_wrapper = SimpleFactory<NoCoastPlottingWrapper>::create("on");
	}
	coastlines_wrapper->set(request);
	coastlines_->coastlines_ =  unique_ptr<NoCoastPlotting>(coastlines_wrapper->object());
	delete coastlines_wrapper;
	
		string grid_value = request.countValues("MAP_GRID") ?  (string) request("MAP_GRID") : "on";
	MagLog::debug() << " MAP_GRID set to " << grid_value << endl;
	NoGridPlottingWrapper* grid_wrapper = 0;
	try
	{
		grid_wrapper = SimpleFactory<NoGridPlottingWrapper>::create(grid_value);
	}
	 catch (NoFactoryException&) {
		if (MagicsGlobal::strict()) {
            throw;
        }
		MagLog::warning() << "[" << grid_value << "] is not a valid value for grid: reset to default -> [on]" << endl;
		grid_wrapper = SimpleFactory<NoGridPlottingWrapper>::create("on");
	}
	grid_wrapper->set(request);
	coastlines_->grid_ =  unique_ptr<NoGridPlotting>(grid_wrapper->object());
	delete grid_wrapper;
	
		string label_value = request.countValues("MAP_LABEL") ?  (string) request("MAP_LABEL") : "on";
	MagLog::debug() << " MAP_LABEL set to " << label_value << endl;
	NoLabelPlottingWrapper* label_wrapper = 0;
	try
	{
		label_wrapper = SimpleFactory<NoLabelPlottingWrapper>::create(label_value);
	}
	 catch (NoFactoryException&) {
		if (MagicsGlobal::strict()) {
            throw;
        }
		MagLog::warning() << "[" << label_value << "] is not a valid value for label: reset to default -> [on]" << endl;
		label_wrapper = SimpleFactory<NoLabelPlottingWrapper>::create("on");
	}
	label_wrapper->set(request);
	coastlines_->label_ =  unique_ptr<NoLabelPlotting>(label_wrapper->object());
	delete label_wrapper;
	
}

void CoastlinesWrapper::print(ostream& out)  const
{
	out << "CoastlinesWrapper[]";
}


#include "CoastPlottingWrapper.h"
static SimpleObjectMaker<CoastPlotting, NoCoastPlotting> Coastlines_map_coastline_coast ("coast");
static SimpleObjectMaker<CoastPlottingWrapper, NoCoastPlottingWrapper> Coastlines_map_coastline_coast_wrapper ("coast");


#include "CoastPlottingWrapper.h"
static SimpleObjectMaker<CoastPlotting, NoCoastPlotting> Coastlines_map_coastline_on ("on");
static SimpleObjectMaker<CoastPlottingWrapper, NoCoastPlottingWrapper> Coastlines_map_coastline_on_wrapper ("on");


#include "NoCoastPlottingWrapper.h"

static SimpleObjectMaker<NoCoastPlottingWrapper> Coastlines_map_coastline_nocoast_Wrapper("nocoast");


#include "NoCoastPlottingWrapper.h"

static SimpleObjectMaker<NoCoastPlottingWrapper> Coastlines_map_coastline_off_Wrapper("off");



#include "GridPlottingWrapper.h"
static SimpleObjectMaker<GridPlotting, NoGridPlotting> Coastlines_map_grid_grid ("grid");
static SimpleObjectMaker<GridPlottingWrapper, NoGridPlottingWrapper> Coastlines_map_grid_grid_wrapper ("grid");


#include "GridPlottingWrapper.h"
static SimpleObjectMaker<GridPlotting, NoGridPlotting> Coastlines_map_grid_on ("on");
static SimpleObjectMaker<GridPlottingWrapper, NoGridPlottingWrapper> Coastlines_map_grid_on_wrapper ("on");


#include "NoGridPlottingWrapper.h"

static SimpleObjectMaker<NoGridPlottingWrapper> Coastlines_map_grid_nogrid_Wrapper("nogrid");


#include "NoGridPlottingWrapper.h"

static SimpleObjectMaker<NoGridPlottingWrapper> Coastlines_map_grid_off_Wrapper("off");



#include "LabelPlottingWrapper.h"
static SimpleObjectMaker<LabelPlotting, NoLabelPlotting> Coastlines_map_label_label ("label");
static SimpleObjectMaker<LabelPlottingWrapper, NoLabelPlottingWrapper> Coastlines_map_label_label_wrapper ("label");


#include "LabelPlottingWrapper.h"
static SimpleObjectMaker<LabelPlotting, NoLabelPlotting> Coastlines_map_label_on ("on");
static SimpleObjectMaker<LabelPlottingWrapper, NoLabelPlottingWrapper> Coastlines_map_label_on_wrapper ("on");


#include "NoLabelPlottingWrapper.h"

static SimpleObjectMaker<NoLabelPlottingWrapper> Coastlines_map_label_nolabel_Wrapper("nolabel");


#include "NoLabelPlottingWrapper.h"

static SimpleObjectMaker<NoLabelPlottingWrapper> Coastlines_map_label_off_Wrapper("off");




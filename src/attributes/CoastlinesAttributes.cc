
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

#include "CoastlinesAttributes.h"
#include "MagicsParameter.h"
#include "ParameterSettings.h"

using namespace magics;

CoastlinesAttributes::CoastlinesAttributes():
	style_(ParameterManager::getString("map_coastline_general_style"))
	,
	coastlines_(MagTranslator<string, NoCoastPlotting>().magics("map_coastline")),
	grid_(MagTranslator<string, NoGridPlotting>().magics("map_grid")),
	label_(MagTranslator<string, NoLabelPlotting>().magics("map_label"))
	 
{
} 


CoastlinesAttributes::~CoastlinesAttributes()
{
	
}

    
void CoastlinesAttributes::set(const std::map<string, string>& params)
{
	vector<string> prefix(1);
	int i = 0;
	prefix[i++] = "map";
	
	setAttribute(prefix, "map_coastline_general_style", style_, params);
	
	setMember(prefix, "map_coastline", coastlines_, params);
	setMember(prefix, "map_grid", grid_, params);
	setMember(prefix, "map_label", label_, params);
	
}

void CoastlinesAttributes::copy(const CoastlinesAttributes& other)
{
	style_ = other.style_;
	coastlines_ = unique_ptr<NoCoastPlotting>(other.coastlines_->clone());
	grid_ = unique_ptr<NoGridPlotting>(other.grid_->clone());
	label_ = unique_ptr<NoLabelPlotting>(other.label_->clone());
	
} 


bool CoastlinesAttributes::accept(const string& node)
{	
	
	if ( magCompare(node, "coastlines")  )
		return true;
	if ( magCompare(node, "zcoastlines")  )
		return true;
	if ( acceptNode(node, coastlines_) )
		return true;
	if ( acceptNode(node, grid_) )
		return true;
	if ( acceptNode(node, label_) )
		return true;
	
	return false;
}

void CoastlinesAttributes::set(const XmlNode& node)
{
	bool apply = false;

	if ( this->accept(node.name()) == false ) 
		return;

	if ( magCompare(node.name(), "coastlines")  )
		apply = true;
	if ( magCompare(node.name(), "zcoastlines")  )
		apply = true;
	

	if ( apply )
		set(node.attributes());
	else {
		setMember(node.name(), coastlines_, node);
		setMember(node.name(), grid_, node);
		setMember(node.name(), label_, node);
		
	}
	for (auto &elt : node.elements())
	{
		setMember(elt->name(), coastlines_, *elt); 
		setMember(elt->name(), grid_, *elt); 
		setMember(elt->name(), label_, *elt); 
		
	}
}

void CoastlinesAttributes::print(ostream& out)  const
{
	out << "Attributes[";
	out << " style = " <<  style_;
	out << " coastlines = " <<  *coastlines_;
	out << " grid = " <<  *grid_;
	out << " label = " <<  *label_;
	
	out << "]" << "\n";
}

void CoastlinesAttributes::toxml(ostream& out)  const
{
	out <<  "\"coastlines\""; 
	out << ", \"map_coastline_general_style\":";
	niceprint(out,style_);
	out << ", \"map_coastline\":";
	coastlines_->toxml(out);
	out << ", \"map_grid\":";
	grid_->toxml(out);
	out << ", \"map_label\":";
	label_->toxml(out);
	
}

static MagicsParameter<string> map_coastline_general_style("map_coastline_general_style", "", "");
static MagicsParameter<string> map_coastline("map_coastline", "on", ""); 
static MagicsParameter<string> map_grid("map_grid", "on", ""); 
static MagicsParameter<string> map_label("map_label", "on", ""); 
#include "CoastPlotting.h"
#include "LabelPlotting.h"
#include "GridPlotting.h"
static SimpleObjectMaker<CoastPlotting , NoCoastPlotting> coast_CoastPlotting("coast");
static SimpleObjectMaker<CoastPlotting , NoCoastPlotting> on_CoastPlotting("on");
static SimpleObjectMaker<NoCoastPlotting , NoCoastPlotting> nocoast_NoCoastPlotting("nocoast");
static SimpleObjectMaker<NoCoastPlotting , NoCoastPlotting> off_NoCoastPlotting("off");
static SimpleObjectMaker<GridPlotting , NoGridPlotting> grid_GridPlotting("grid");
static SimpleObjectMaker<GridPlotting , NoGridPlotting> on_GridPlotting("on");
static SimpleObjectMaker<NoGridPlotting , NoGridPlotting> nogrid_NoGridPlotting("nogrid");
static SimpleObjectMaker<NoGridPlotting , NoGridPlotting> off_NoGridPlotting("off");
static SimpleObjectMaker<LabelPlotting , NoLabelPlotting> label_LabelPlotting("label");
static SimpleObjectMaker<LabelPlotting , NoLabelPlotting> on_LabelPlotting("on");
static SimpleObjectMaker<NoLabelPlotting , NoLabelPlotting> nolabel_NoLabelPlotting("nolabel");
static SimpleObjectMaker<NoLabelPlotting , NoLabelPlotting> off_NoLabelPlotting("off");

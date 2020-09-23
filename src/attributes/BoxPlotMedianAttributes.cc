
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

    Generated: 2020-09-22
*/

#include "BoxPlotMedianAttributes.h"
#include "MagicsParameter.h"
#include "ParameterSettings.h"

using namespace magics;

BoxPlotMedianAttributes::BoxPlotMedianAttributes():
	thickness_(ParameterManager::getInt("boxplot_median_thickness"))
	,
	colour_(MagTranslator<string, Colour>().magics("boxplot_median_colour")),
	style_(MagTranslator<string, LineStyle>().magics("boxplot_median_line_style"))
	 
{
} 


BoxPlotMedianAttributes::~BoxPlotMedianAttributes()
{
	
}

    
void BoxPlotMedianAttributes::set(const std::map<string, string>& params)
{
	vector<string> prefix(2);
	int i = 0;
	prefix[i++] = "boxplot";
	prefix[i++] = "boxplot_median";
	
	setAttribute(prefix, "boxplot_median_thickness", thickness_, params);
	
	setMember(prefix, "boxplot_median_colour", colour_, params);
	setAttribute(prefix, "boxplot_median_line_style", style_, params);
	
}

void BoxPlotMedianAttributes::copy(const BoxPlotMedianAttributes& other)
{
	thickness_ = other.thickness_;
	colour_ = unique_ptr<Colour>(other.colour_->clone());
	style_ = other.style_;
	
} 


bool BoxPlotMedianAttributes::accept(const string& node)
{	
	
	if ( magCompare(node, "median")  )
		return true;
	
	return false;
}

void BoxPlotMedianAttributes::set(const XmlNode& node)
{
	bool apply = false;

	if ( this->accept(node.name()) == false ) 
		return;

	if ( magCompare(node.name(), "median")  )
		apply = true;
	

	if ( apply )
		set(node.attributes());
	else {
		
	}
	for (auto &elt : node.elements())
	{
		
	}
}

void BoxPlotMedianAttributes::print(ostream& out)  const
{
	out << "Attributes[";
	out << " thickness = " <<  thickness_;
	out << " colour = " <<  *colour_;
	out << " style = " <<  style_;
	
	out << "]" << "\n";
}

void BoxPlotMedianAttributes::toxml(ostream& out)  const
{
	out <<  "\"median\""; 
	out << ", \"boxplot_median_thickness\":";
	niceprint(out,thickness_);
	out << ", \"boxplot_median_colour\":";
	niceprint(out, *colour_);
	out << ", \"boxplot_median_line_style\":";
	niceprint(out, style_);
	
}

static MagicsParameter<int> boxplot_median_thickness("boxplot_median_thickness", 3, "");
static MagicsParameter<string> boxplot_median_colour("boxplot_median_colour", "navy", ""); 
static MagicsParameter<string> boxplot_median_line_style("boxplot_median_line_style", "solid", ""); 

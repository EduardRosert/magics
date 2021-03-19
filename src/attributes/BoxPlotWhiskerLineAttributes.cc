
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file BoxPlotWhiskerLineAttributes.h
    \\brief Definition of BoxPlotWhiskerLine Attributes class.

    This file is automatically generated.
    Do Not Edit!
*/

#include "BoxPlotWhiskerLineAttributes.h"
#include "MagicsParameter.h"
#include "ParameterSettings.h"

using namespace magics;

BoxPlotWhiskerLineAttributes::BoxPlotWhiskerLineAttributes():
	thickness_(ParameterManager::getInt("boxplot_whisker_line_thickness"))
	,
	colour_(MagTranslator<string, Colour>().magics("boxplot_whisker_line_colour")),
	style_(MagTranslator<string, LineStyle>().magics("boxplot_whisker_line_style"))
	
{
}


BoxPlotWhiskerLineAttributes::~BoxPlotWhiskerLineAttributes()
{

}


void BoxPlotWhiskerLineAttributes::set(const std::map<string, string>& params)
{
	vector<string> prefix(3);
	int i = 0;
	prefix[i++] = "boxplot";
	prefix[i++] = "boxplot_whisker";
	prefix[i++] = "boxplot_whisker_line";
	
	setAttribute(prefix, "boxplot_whisker_line_thickness", thickness_, params);
	
	setMember(prefix, "boxplot_whisker_line_colour", colour_, params);
	setAttribute(prefix, "boxplot_whisker_line_style", style_, params);
	
}

void BoxPlotWhiskerLineAttributes::copy(const BoxPlotWhiskerLineAttributes& other)
{
	thickness_ = other.thickness_;
	colour_ = unique_ptr<Colour>(other.colour_->clone());
	style_ = other.style_;
	
}


bool BoxPlotWhiskerLineAttributes::accept(const string& node)
{

	if ( magCompare(node, "whisker_line")  )
		return true;
	
	return false;
}

void BoxPlotWhiskerLineAttributes::set(const XmlNode& node)
{
	bool apply = false;

	if ( this->accept(node.name()) == false )
		return;

	if ( magCompare(node.name(), "whisker_line")  )
		apply = true;
	

	if ( apply )
		set(node.attributes());
	else {
		
	}
	for (auto &elt : node.elements())
	{
		
	}
}

void BoxPlotWhiskerLineAttributes::print(ostream& out)  const
{
	out << "Attributes[";
	out << " thickness = " <<  thickness_;
	out << " colour = " <<  *colour_;
	out << " style = " <<  style_;
	
	out << "]" << "\n";
}

void BoxPlotWhiskerLineAttributes::toxml(ostream& out)  const
{
	out <<  "\"whisker_line\"";
	out << ", \"boxplot_whisker_line_thickness\":";
	niceprint(out,thickness_);
	out << ", \"boxplot_whisker_line_colour\":";
	niceprint(out, *colour_);
	out << ", \"boxplot_whisker_line_style\":";
	niceprint(out, style_);
	
}

static MagicsParameter<int> boxplot_whisker_line_thickness("boxplot_whisker_line_thickness", 3);
static MagicsParameter<string> boxplot_whisker_line_colour("boxplot_whisker_line_colour", "navy");
static MagicsParameter<string> boxplot_whisker_line_style("boxplot_whisker_line_style", "solid");

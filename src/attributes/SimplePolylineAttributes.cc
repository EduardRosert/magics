
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file SimplePolylineAttributes.h
    \\brief Definition of SimplePolyline Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 2020-09-22
*/

#include "SimplePolylineAttributes.h"
#include "MagicsParameter.h"
#include "ParameterSettings.h"

using namespace magics;

SimplePolylineAttributes::SimplePolylineAttributes():
	legend_(ParameterManager::getBool("legend")),
	thickness_(ParameterManager::getInt("polyline_line_thickness")),
	method_(ParameterManager::getString("polyline_effect_method")),
	pivot_(ParameterManager::getInt("polyline_trajectory_pivot_index")),
	factor_(ParameterManager::getInt("polyline_trajectory_factor")),
	count_(ParameterManager::getInt("polyline_level_count")),
	tolerance_(ParameterManager::getInt("polyline_level_tolerance")),
	reference_(ParameterManager::getDouble("polyline_reference_level")),
	interval_(ParameterManager::getDouble("polyline_interval")),
	list_(ParameterManager::getDoubleArray("polyline_level_list")),
	shade_(ParameterManager::getBool("polyline_shade")),
	max_(ParameterManager::getDouble("polyline_shade_max_level")),
	min_(ParameterManager::getDouble("polyline_shade_min_level")),
	direction_(ParameterManager::getString("polyline_shade_colour_direction")),
	colours_(ParameterManager::getStringArray("polyline_shade_colour_list")),
	priority_key_(ParameterManager::getString("polyline_priority_variable_name")),
	colour_key_(ParameterManager::getString("polyline_colour_variable_name")),
	colour_list_(ParameterManager::getStringArray("polyline_colour_list")),
	colour_level_list_(ParameterManager::getDoubleArray("polyline_colour_level_list")),
	style_key_(ParameterManager::getString("polyline_line_style_variable_name")),
	style_list_(ParameterManager::getStringArray("polyline_line_style_list")),
	style_level_list_(ParameterManager::getDoubleArray("polyline_line_style_level_list")),
	thickness_key_(ParameterManager::getString("polyline_thickness_variable_name")),
	thickness_list_(ParameterManager::getDoubleArray("polyline_thickness_list")),
	thickness_level_list_(ParameterManager::getDoubleArray("polyline_thickness_level_list")),
	transparency_key_(ParameterManager::getString("polyline_transparency_variable_name")),
	pivot_key_(ParameterManager::getString("polyline_transparency_pivot_variable_name")),
	pivot_marker_(ParameterManager::getString("polyline_pivot_marker")),
	pivot_marker_name_(ParameterManager::getString("polyline_pivot_marker_name")),
	pivot_marker_height_(ParameterManager::getDouble("polyline_pivot_marker_height")),
	transparency_level_list_(ParameterManager::getDoubleArray("polyline_transparency_level_list")),
	legend_only_(ParameterManager::getBool("polyline_legend_only"))
	,
	colour_(MagTranslator<string, Colour>().magics("polyline_line_colour")),
	style_(MagTranslator<string, LineStyle>().magics("polyline_line_style")),
	levelSelection_(MagTranslator<string, LevelSelection>().magics("polyline_shade_level_selection_type")),
	colourMethod_(MagTranslator<string, ColourTechnique>().magics("polyline_shade_colour_method")),
	maxColour_(MagTranslator<string, Colour>().magics("polyline_shade_max_level_colour")),
	minColour_(MagTranslator<string, Colour>().magics("polyline_shade_min_level_colour")),
	colour_policy_(MagTranslator<string, ListPolicy>().magics("polyline_colour_list_policy")),
	style_policy_(MagTranslator<string, ListPolicy>().magics("polyline_line_style_list_policy")),
	thickness_policy_(MagTranslator<string, ListPolicy>().magics("polyline_thickness_list_policy")),
	pivot_marker_colour_(MagTranslator<string, Colour>().magics("polyline_pivot_marker_colour"))
	 
{
} 


SimplePolylineAttributes::~SimplePolylineAttributes()
{
	
}

    
void SimplePolylineAttributes::set(const std::map<string, string>& params)
{
	vector<string> prefix(2);
	int i = 0;
	prefix[i++] = "polyline";
	prefix[i++] = "polyline_line";
	
	setAttribute(prefix, "legend", legend_, params);
	setAttribute(prefix, "polyline_line_thickness", thickness_, params);
	setAttribute(prefix, "polyline_effect_method", method_, params);
	setAttribute(prefix, "polyline_trajectory_pivot_index", pivot_, params);
	setAttribute(prefix, "polyline_trajectory_factor", factor_, params);
	setAttribute(prefix, "polyline_level_count", count_, params);
	setAttribute(prefix, "polyline_level_tolerance", tolerance_, params);
	setAttribute(prefix, "polyline_reference_level", reference_, params);
	setAttribute(prefix, "polyline_interval", interval_, params);
	setAttribute(prefix, "polyline_level_list", list_, params);
	setAttribute(prefix, "polyline_shade", shade_, params);
	setAttribute(prefix, "polyline_shade_max_level", max_, params);
	setAttribute(prefix, "polyline_shade_min_level", min_, params);
	setAttribute(prefix, "polyline_shade_colour_direction", direction_, params);
	setAttribute(prefix, "polyline_shade_colour_list", colours_, params);
	setAttribute(prefix, "polyline_priority_variable_name", priority_key_, params);
	setAttribute(prefix, "polyline_colour_variable_name", colour_key_, params);
	setAttribute(prefix, "polyline_colour_list", colour_list_, params);
	setAttribute(prefix, "polyline_colour_level_list", colour_level_list_, params);
	setAttribute(prefix, "polyline_line_style_variable_name", style_key_, params);
	setAttribute(prefix, "polyline_line_style_list", style_list_, params);
	setAttribute(prefix, "polyline_line_style_level_list", style_level_list_, params);
	setAttribute(prefix, "polyline_thickness_variable_name", thickness_key_, params);
	setAttribute(prefix, "polyline_thickness_list", thickness_list_, params);
	setAttribute(prefix, "polyline_thickness_level_list", thickness_level_list_, params);
	setAttribute(prefix, "polyline_transparency_variable_name", transparency_key_, params);
	setAttribute(prefix, "polyline_transparency_pivot_variable_name", pivot_key_, params);
	setAttribute(prefix, "polyline_pivot_marker", pivot_marker_, params);
	setAttribute(prefix, "polyline_pivot_marker_name", pivot_marker_name_, params);
	setAttribute(prefix, "polyline_pivot_marker_height", pivot_marker_height_, params);
	setAttribute(prefix, "polyline_transparency_level_list", transparency_level_list_, params);
	setAttribute(prefix, "polyline_legend_only", legend_only_, params);
	
	setMember(prefix, "polyline_line_colour", colour_, params);
	setAttribute(prefix, "polyline_line_style", style_, params);
	setMember(prefix, "polyline_shade_level_selection_type", levelSelection_, params);
	setMember(prefix, "polyline_shade_colour_method", colourMethod_, params);
	setMember(prefix, "polyline_shade_max_level_colour", maxColour_, params);
	setMember(prefix, "polyline_shade_min_level_colour", minColour_, params);
	setAttribute(prefix, "polyline_colour_list_policy", colour_policy_, params);
	setAttribute(prefix, "polyline_line_style_list_policy", style_policy_, params);
	setAttribute(prefix, "polyline_thickness_list_policy", thickness_policy_, params);
	setMember(prefix, "polyline_pivot_marker_colour", pivot_marker_colour_, params);
	
}

void SimplePolylineAttributes::copy(const SimplePolylineAttributes& other)
{
	legend_ = other.legend_;
	thickness_ = other.thickness_;
	method_ = other.method_;
	pivot_ = other.pivot_;
	factor_ = other.factor_;
	count_ = other.count_;
	tolerance_ = other.tolerance_;
	reference_ = other.reference_;
	interval_ = other.interval_;
	list_ = other.list_;
	shade_ = other.shade_;
	max_ = other.max_;
	min_ = other.min_;
	direction_ = other.direction_;
	colours_ = other.colours_;
	priority_key_ = other.priority_key_;
	colour_key_ = other.colour_key_;
	colour_list_ = other.colour_list_;
	colour_level_list_ = other.colour_level_list_;
	style_key_ = other.style_key_;
	style_list_ = other.style_list_;
	style_level_list_ = other.style_level_list_;
	thickness_key_ = other.thickness_key_;
	thickness_list_ = other.thickness_list_;
	thickness_level_list_ = other.thickness_level_list_;
	transparency_key_ = other.transparency_key_;
	pivot_key_ = other.pivot_key_;
	pivot_marker_ = other.pivot_marker_;
	pivot_marker_name_ = other.pivot_marker_name_;
	pivot_marker_height_ = other.pivot_marker_height_;
	transparency_level_list_ = other.transparency_level_list_;
	legend_only_ = other.legend_only_;
	colour_ = unique_ptr<Colour>(other.colour_->clone());
	style_ = other.style_;
	levelSelection_ = unique_ptr<LevelSelection>(other.levelSelection_->clone());
	colourMethod_ = unique_ptr<ColourTechnique>(other.colourMethod_->clone());
	maxColour_ = unique_ptr<Colour>(other.maxColour_->clone());
	minColour_ = unique_ptr<Colour>(other.minColour_->clone());
	colour_policy_ = other.colour_policy_;
	style_policy_ = other.style_policy_;
	thickness_policy_ = other.thickness_policy_;
	pivot_marker_colour_ = unique_ptr<Colour>(other.pivot_marker_colour_->clone());
	
} 


bool SimplePolylineAttributes::accept(const string& node)
{	
	
	if ( magCompare(node, "polyline")  )
		return true;
	if ( acceptNode(node, levelSelection_) )
		return true;
	if ( acceptNode(node, colourMethod_) )
		return true;
	
	return false;
}

void SimplePolylineAttributes::set(const XmlNode& node)
{
	bool apply = false;

	if ( this->accept(node.name()) == false ) 
		return;

	if ( magCompare(node.name(), "polyline")  )
		apply = true;
	

	if ( apply )
		set(node.attributes());
	else {
		setMember(node.name(), levelSelection_, node);
		setMember(node.name(), colourMethod_, node);
		
	}
	for (auto &elt : node.elements())
	{
		setMember(elt->name(), levelSelection_, *elt); 
		setMember(elt->name(), colourMethod_, *elt); 
		
	}
}

void SimplePolylineAttributes::print(ostream& out)  const
{
	out << "Attributes[";
	out << " legend = " <<  legend_;
	out << " thickness = " <<  thickness_;
	out << " method = " <<  method_;
	out << " pivot = " <<  pivot_;
	out << " factor = " <<  factor_;
	out << " count = " <<  count_;
	out << " tolerance = " <<  tolerance_;
	out << " reference = " <<  reference_;
	out << " interval = " <<  interval_;
	out << " list = " <<  list_;
	out << " shade = " <<  shade_;
	out << " max = " <<  max_;
	out << " min = " <<  min_;
	out << " direction = " <<  direction_;
	out << " colours = " <<  colours_;
	out << " priority_key = " <<  priority_key_;
	out << " colour_key = " <<  colour_key_;
	out << " colour_list = " <<  colour_list_;
	out << " colour_level_list = " <<  colour_level_list_;
	out << " style_key = " <<  style_key_;
	out << " style_list = " <<  style_list_;
	out << " style_level_list = " <<  style_level_list_;
	out << " thickness_key = " <<  thickness_key_;
	out << " thickness_list = " <<  thickness_list_;
	out << " thickness_level_list = " <<  thickness_level_list_;
	out << " transparency_key = " <<  transparency_key_;
	out << " pivot_key = " <<  pivot_key_;
	out << " pivot_marker = " <<  pivot_marker_;
	out << " pivot_marker_name = " <<  pivot_marker_name_;
	out << " pivot_marker_height = " <<  pivot_marker_height_;
	out << " transparency_level_list = " <<  transparency_level_list_;
	out << " legend_only = " <<  legend_only_;
	out << " colour = " <<  *colour_;
	out << " style = " <<  style_;
	out << " levelSelection = " <<  *levelSelection_;
	out << " colourMethod = " <<  *colourMethod_;
	out << " maxColour = " <<  *maxColour_;
	out << " minColour = " <<  *minColour_;
	out << " colour_policy = " <<  colour_policy_;
	out << " style_policy = " <<  style_policy_;
	out << " thickness_policy = " <<  thickness_policy_;
	out << " pivot_marker_colour = " <<  *pivot_marker_colour_;
	
	out << "]" << "\n";
}

void SimplePolylineAttributes::toxml(ostream& out)  const
{
	out <<  "\"polyline\""; 
	out << ", \"legend\":";
	niceprint(out,legend_);
	out << ", \"polyline_line_thickness\":";
	niceprint(out,thickness_);
	out << ", \"polyline_effect_method\":";
	niceprint(out,method_);
	out << ", \"polyline_trajectory_pivot_index\":";
	niceprint(out,pivot_);
	out << ", \"polyline_trajectory_factor\":";
	niceprint(out,factor_);
	out << ", \"polyline_level_count\":";
	niceprint(out,count_);
	out << ", \"polyline_level_tolerance\":";
	niceprint(out,tolerance_);
	out << ", \"polyline_reference_level\":";
	niceprint(out,reference_);
	out << ", \"polyline_interval\":";
	niceprint(out,interval_);
	out << ", \"polyline_level_list\":";
	niceprint(out,list_);
	out << ", \"polyline_shade\":";
	niceprint(out,shade_);
	out << ", \"polyline_shade_max_level\":";
	niceprint(out,max_);
	out << ", \"polyline_shade_min_level\":";
	niceprint(out,min_);
	out << ", \"polyline_shade_colour_direction\":";
	niceprint(out,direction_);
	out << ", \"polyline_shade_colour_list\":";
	niceprint(out,colours_);
	out << ", \"polyline_priority_variable_name\":";
	niceprint(out,priority_key_);
	out << ", \"polyline_colour_variable_name\":";
	niceprint(out,colour_key_);
	out << ", \"polyline_colour_list\":";
	niceprint(out,colour_list_);
	out << ", \"polyline_colour_level_list\":";
	niceprint(out,colour_level_list_);
	out << ", \"polyline_line_style_variable_name\":";
	niceprint(out,style_key_);
	out << ", \"polyline_line_style_list\":";
	niceprint(out,style_list_);
	out << ", \"polyline_line_style_level_list\":";
	niceprint(out,style_level_list_);
	out << ", \"polyline_thickness_variable_name\":";
	niceprint(out,thickness_key_);
	out << ", \"polyline_thickness_list\":";
	niceprint(out,thickness_list_);
	out << ", \"polyline_thickness_level_list\":";
	niceprint(out,thickness_level_list_);
	out << ", \"polyline_transparency_variable_name\":";
	niceprint(out,transparency_key_);
	out << ", \"polyline_transparency_pivot_variable_name\":";
	niceprint(out,pivot_key_);
	out << ", \"polyline_pivot_marker\":";
	niceprint(out,pivot_marker_);
	out << ", \"polyline_pivot_marker_name\":";
	niceprint(out,pivot_marker_name_);
	out << ", \"polyline_pivot_marker_height\":";
	niceprint(out,pivot_marker_height_);
	out << ", \"polyline_transparency_level_list\":";
	niceprint(out,transparency_level_list_);
	out << ", \"polyline_legend_only\":";
	niceprint(out,legend_only_);
	out << ", \"polyline_line_colour\":";
	niceprint(out, *colour_);
	out << ", \"polyline_line_style\":";
	niceprint(out, style_);
	out << ", \"polyline_shade_level_selection_type\":";
	levelSelection_->toxml(out);
	out << ", \"polyline_shade_colour_method\":";
	colourMethod_->toxml(out);
	out << ", \"polyline_shade_max_level_colour\":";
	niceprint(out, *maxColour_);
	out << ", \"polyline_shade_min_level_colour\":";
	niceprint(out, *minColour_);
	out << ", \"polyline_colour_list_policy\":";
	niceprint(out, colour_policy_);
	out << ", \"polyline_line_style_list_policy\":";
	niceprint(out, style_policy_);
	out << ", \"polyline_thickness_list_policy\":";
	niceprint(out, thickness_policy_);
	out << ", \"polyline_pivot_marker_colour\":";
	niceprint(out, *pivot_marker_colour_);
	
}

static MagicsParameter<string> legend("legend", "off", "");
static MagicsParameter<int> polyline_line_thickness("polyline_line_thickness", 1, "");
static MagicsParameter<string> polyline_effect_method("polyline_effect_method", "classic", "");
static MagicsParameter<int> polyline_trajectory_pivot_index("polyline_trajectory_pivot_index", -1, "");
static MagicsParameter<int> polyline_trajectory_factor("polyline_trajectory_factor", -1, "");
static MagicsParameter<int> polyline_level_count("polyline_level_count", 10, "");
static MagicsParameter<int> polyline_level_tolerance("polyline_level_tolerance", 2, "");
static MagicsParameter<double> polyline_reference_level("polyline_reference_level", 0.0, "");
static MagicsParameter<double> polyline_interval("polyline_interval", 8.0, "");
static MagicsParameter<doublearray> polyline_level_list("polyline_level_list", floatarray(), "");
static MagicsParameter<string> polyline_shade("polyline_shade", "none", "");
static MagicsParameter<double> polyline_shade_max_level("polyline_shade_max_level", 1.0e+21, "");
static MagicsParameter<double> polyline_shade_min_level("polyline_shade_min_level", -1.0e+21, "");
static MagicsParameter<string> polyline_shade_colour_direction("polyline_shade_colour_direction", "anti_clockwise", "");
static MagicsParameter<stringarray> polyline_shade_colour_list("polyline_shade_colour_list", stringarray(), "");
static MagicsParameter<string> polyline_priority_variable_name("polyline_priority_variable_name", "", "");
static MagicsParameter<string> polyline_colour_variable_name("polyline_colour_variable_name", "", "");
static MagicsParameter<stringarray> polyline_colour_list("polyline_colour_list", stringarray(), "");
static MagicsParameter<doublearray> polyline_colour_level_list("polyline_colour_level_list", floatarray(), "");
static MagicsParameter<string> polyline_line_style_variable_name("polyline_line_style_variable_name", "", "");
static MagicsParameter<stringarray> polyline_line_style_list("polyline_line_style_list", stringarray(), "");
static MagicsParameter<doublearray> polyline_line_style_level_list("polyline_line_style_level_list", floatarray(), "");
static MagicsParameter<string> polyline_thickness_variable_name("polyline_thickness_variable_name", "", "");
static MagicsParameter<doublearray> polyline_thickness_list("polyline_thickness_list", floatarray(), "");
static MagicsParameter<doublearray> polyline_thickness_level_list("polyline_thickness_level_list", floatarray(), "");
static MagicsParameter<string> polyline_transparency_variable_name("polyline_transparency_variable_name", "", "");
static MagicsParameter<string> polyline_transparency_pivot_variable_name("polyline_transparency_pivot_variable_name", "", "");
static MagicsParameter<string> polyline_pivot_marker("polyline_pivot_marker", "none", "");
static MagicsParameter<string> polyline_pivot_marker_name("polyline_pivot_marker_name", "cyclone", "");
static MagicsParameter<double> polyline_pivot_marker_height("polyline_pivot_marker_height", 0.4, "");
static MagicsParameter<doublearray> polyline_transparency_level_list("polyline_transparency_level_list", floatarray(), "");
static MagicsParameter<string> polyline_legend_only("polyline_legend_only", "off", "");
static MagicsParameter<string> polyline_line_colour("polyline_line_colour", "blue", ""); 
static MagicsParameter<string> polyline_line_style("polyline_line_style", "solid", ""); 
static MagicsParameter<string> polyline_shade_level_selection_type("polyline_shade_level_selection_type", "count", ""); 
static MagicsParameter<string> polyline_shade_colour_method("polyline_shade_colour_method", "calculate", ""); 
static MagicsParameter<string> polyline_shade_max_level_colour("polyline_shade_max_level_colour", "blue", ""); 
static MagicsParameter<string> polyline_shade_min_level_colour("polyline_shade_min_level_colour", "red", ""); 
static MagicsParameter<string> polyline_colour_list_policy("polyline_colour_list_policy", "lastone", ""); 
static MagicsParameter<string> polyline_line_style_list_policy("polyline_line_style_list_policy", "lastone", ""); 
static MagicsParameter<string> polyline_thickness_list_policy("polyline_thickness_list_policy", "lastone", ""); 
static MagicsParameter<string> polyline_pivot_marker_colour("polyline_pivot_marker_colour", "black", ""); 
#include "ListColourTechnique.h"
#include "IntervalSelectionType.h"
#include "CountSelectionType.h"
#include "CalculateColourTechnique.h"
#include "LevelListSelectionType.h"
static SimpleObjectMaker<CountSelectionType , LevelSelection> count_CountSelectionType("count");
static SimpleObjectMaker<IntervalSelectionType , LevelSelection> interval_IntervalSelectionType("interval");
static SimpleObjectMaker<LevelListSelectionType , LevelSelection> list_LevelListSelectionType("list");
static SimpleObjectMaker<CalculateColourTechnique , ColourTechnique> calculate_CalculateColourTechnique("calculate");
static SimpleObjectMaker<ListColourTechnique , ColourTechnique> list_ListColourTechnique("list");

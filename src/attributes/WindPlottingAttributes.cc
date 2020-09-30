
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file WindPlottingAttributes.h
    \\brief Definition of WindPlotting Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 2020-09-24
*/

#include "WindPlottingAttributes.h"
#include "MagicsParameter.h"
#include "ParameterSettings.h"

using namespace magics;

WindPlottingAttributes::WindPlottingAttributes():
	legend_(ParameterManager::getBool("legend")),
	legend_only_(ParameterManager::getBool("wind_legend_only")),
	legend_text_(ParameterManager::getString("wind_legend_text")),
	advanced_method_(ParameterManager::getString("wind_advanced_method")),
	colour_method_(ParameterManager::getString("wind_advanced_colour_parameter")),
	max_(ParameterManager::getDouble("wind_advanced_colour_max_value")),
	min_(ParameterManager::getDouble("wind_advanced_colour_min_value")),
	count_(ParameterManager::getInt("wind_advanced_colour_level_count")),
	tolerance_(ParameterManager::getInt("wind_advanced_colour_level_tolerance")),
	reference_(ParameterManager::getDouble("wind_advanced_colour_reference_level")),
	interval_(ParameterManager::getDouble("wind_advanced_colour_level_interval")),
	list_(ParameterManager::getDoubleArray("wind_advanced_colour_level_list")),
	direction_(ParameterManager::getString("wind_advanced_colour_direction")),
	colours_(ParameterManager::getStringArray("wind_advanced_colour_list"))
	,
	levels_(MagTranslator<string, LevelSelection>().magics("wind_advanced_colour_selection_type")),
	colourMethod_(MagTranslator<string, ColourTechnique>().magics("wind_advanced_colour_table_colour_method")),
	maxColour_(MagTranslator<string, Colour>().magics("wind_advanced_colour_max_level_colour")),
	minColour_(MagTranslator<string, Colour>().magics("wind_advanced_colour_min_level_colour")),
	colour_policy_(MagTranslator<string, ListPolicy>().magics("wind_advanced_colour_list_policy"))
	 
{
} 


WindPlottingAttributes::~WindPlottingAttributes()
{
	
}

    
void WindPlottingAttributes::set(const std::map<string, string>& params)
{
	vector<string> prefix(2);
	int i = 0;
	prefix[i++] = "wind";
	prefix[i++] = "wind_flag";
	
	setAttribute(prefix, "legend", legend_, params);
	setAttribute(prefix, "wind_legend_only", legend_only_, params);
	setAttribute(prefix, "wind_legend_text", legend_text_, params);
	setAttribute(prefix, "wind_advanced_method", advanced_method_, params);
	setAttribute(prefix, "wind_advanced_colour_parameter", colour_method_, params);
	setAttribute(prefix, "wind_advanced_colour_max_value", max_, params);
	setAttribute(prefix, "wind_advanced_colour_min_value", min_, params);
	setAttribute(prefix, "wind_advanced_colour_level_count", count_, params);
	setAttribute(prefix, "wind_advanced_colour_level_tolerance", tolerance_, params);
	setAttribute(prefix, "wind_advanced_colour_reference_level", reference_, params);
	setAttribute(prefix, "wind_advanced_colour_level_interval", interval_, params);
	setAttribute(prefix, "wind_advanced_colour_level_list", list_, params);
	setAttribute(prefix, "wind_advanced_colour_direction", direction_, params);
	setAttribute(prefix, "wind_advanced_colour_list", colours_, params);
	
	setMember(prefix, "wind_advanced_colour_selection_type", levels_, params);
	setMember(prefix, "wind_advanced_colour_table_colour_method", colourMethod_, params);
	setMember(prefix, "wind_advanced_colour_max_level_colour", maxColour_, params);
	setMember(prefix, "wind_advanced_colour_min_level_colour", minColour_, params);
	setAttribute(prefix, "wind_advanced_colour_list_policy", colour_policy_, params);
	
}

void WindPlottingAttributes::copy(const WindPlottingAttributes& other)
{
	legend_ = other.legend_;
	legend_only_ = other.legend_only_;
	legend_text_ = other.legend_text_;
	advanced_method_ = other.advanced_method_;
	colour_method_ = other.colour_method_;
	max_ = other.max_;
	min_ = other.min_;
	count_ = other.count_;
	tolerance_ = other.tolerance_;
	reference_ = other.reference_;
	interval_ = other.interval_;
	list_ = other.list_;
	direction_ = other.direction_;
	colours_ = other.colours_;
	levels_ = unique_ptr<LevelSelection>(other.levels_->clone());
	colourMethod_ = unique_ptr<ColourTechnique>(other.colourMethod_->clone());
	maxColour_ = unique_ptr<Colour>(other.maxColour_->clone());
	minColour_ = unique_ptr<Colour>(other.minColour_->clone());
	colour_policy_ = other.colour_policy_;
	
} 


bool WindPlottingAttributes::accept(const string& node)
{	
	
	if ( magCompare(node, "flags")  )
		return true;
	if ( acceptNode(node, levels_) )
		return true;
	if ( acceptNode(node, colourMethod_) )
		return true;
	
	return false;
}

void WindPlottingAttributes::set(const XmlNode& node)
{
	bool apply = false;

	if ( this->accept(node.name()) == false ) 
		return;

	if ( magCompare(node.name(), "flags")  )
		apply = true;
	

	if ( apply )
		set(node.attributes());
	else {
		setMember(node.name(), levels_, node);
		setMember(node.name(), colourMethod_, node);
		
	}
	for (auto &elt : node.elements())
	{
		setMember(elt->name(), levels_, *elt); 
		setMember(elt->name(), colourMethod_, *elt); 
		
	}
}

void WindPlottingAttributes::print(ostream& out)  const
{
	out << "Attributes[";
	out << " legend = " <<  legend_;
	out << " legend_only = " <<  legend_only_;
	out << " legend_text = " <<  legend_text_;
	out << " advanced_method = " <<  advanced_method_;
	out << " colour_method = " <<  colour_method_;
	out << " max = " <<  max_;
	out << " min = " <<  min_;
	out << " count = " <<  count_;
	out << " tolerance = " <<  tolerance_;
	out << " reference = " <<  reference_;
	out << " interval = " <<  interval_;
	out << " list = " <<  list_;
	out << " direction = " <<  direction_;
	out << " colours = " <<  colours_;
	out << " levels = " <<  *levels_;
	out << " colourMethod = " <<  *colourMethod_;
	out << " maxColour = " <<  *maxColour_;
	out << " minColour = " <<  *minColour_;
	out << " colour_policy = " <<  colour_policy_;
	
	out << "]" << "\n";
}

void WindPlottingAttributes::toxml(ostream& out)  const
{
	out <<  "\"flags\""; 
	out << ", \"legend\":";
	niceprint(out,legend_);
	out << ", \"wind_legend_only\":";
	niceprint(out,legend_only_);
	out << ", \"wind_legend_text\":";
	niceprint(out,legend_text_);
	out << ", \"wind_advanced_method\":";
	niceprint(out,advanced_method_);
	out << ", \"wind_advanced_colour_parameter\":";
	niceprint(out,colour_method_);
	out << ", \"wind_advanced_colour_max_value\":";
	niceprint(out,max_);
	out << ", \"wind_advanced_colour_min_value\":";
	niceprint(out,min_);
	out << ", \"wind_advanced_colour_level_count\":";
	niceprint(out,count_);
	out << ", \"wind_advanced_colour_level_tolerance\":";
	niceprint(out,tolerance_);
	out << ", \"wind_advanced_colour_reference_level\":";
	niceprint(out,reference_);
	out << ", \"wind_advanced_colour_level_interval\":";
	niceprint(out,interval_);
	out << ", \"wind_advanced_colour_level_list\":";
	niceprint(out,list_);
	out << ", \"wind_advanced_colour_direction\":";
	niceprint(out,direction_);
	out << ", \"wind_advanced_colour_list\":";
	niceprint(out,colours_);
	out << ", \"wind_advanced_colour_selection_type\":";
	levels_->toxml(out);
	out << ", \"wind_advanced_colour_table_colour_method\":";
	colourMethod_->toxml(out);
	out << ", \"wind_advanced_colour_max_level_colour\":";
	niceprint(out, *maxColour_);
	out << ", \"wind_advanced_colour_min_level_colour\":";
	niceprint(out, *minColour_);
	out << ", \"wind_advanced_colour_list_policy\":";
	niceprint(out, colour_policy_);
	
}

static MagicsParameter<string> legend("legend", "off", "");
static MagicsParameter<string> wind_legend_only("wind_legend_only", "off", "");
static MagicsParameter<string> wind_legend_text("wind_legend_text", "vector", "");
static MagicsParameter<string> wind_advanced_method("wind_advanced_method", "off", "");
static MagicsParameter<string> wind_advanced_colour_parameter("wind_advanced_colour_parameter", "speed", "");
static MagicsParameter<double> wind_advanced_colour_max_value("wind_advanced_colour_max_value", 1.e21, "");
static MagicsParameter<double> wind_advanced_colour_min_value("wind_advanced_colour_min_value", -1.e21, "");
static MagicsParameter<int> wind_advanced_colour_level_count("wind_advanced_colour_level_count", 10, "");
static MagicsParameter<int> wind_advanced_colour_level_tolerance("wind_advanced_colour_level_tolerance", 2, "");
static MagicsParameter<double> wind_advanced_colour_reference_level("wind_advanced_colour_reference_level", 0.0, "");
static MagicsParameter<double> wind_advanced_colour_level_interval("wind_advanced_colour_level_interval", 8.0, "");
static MagicsParameter<doublearray> wind_advanced_colour_level_list("wind_advanced_colour_level_list", floatarray(), "");
static MagicsParameter<string> wind_advanced_colour_direction("wind_advanced_colour_direction", "anti_clockwise", "");
static MagicsParameter<stringarray> wind_advanced_colour_list("wind_advanced_colour_list", stringarray(), "");
static MagicsParameter<string> wind_advanced_colour_selection_type("wind_advanced_colour_selection_type", "count", ""); 
static MagicsParameter<string> wind_advanced_colour_table_colour_method("wind_advanced_colour_table_colour_method", "calculate", ""); 
static MagicsParameter<string> wind_advanced_colour_max_level_colour("wind_advanced_colour_max_level_colour", "blue", ""); 
static MagicsParameter<string> wind_advanced_colour_min_level_colour("wind_advanced_colour_min_level_colour", "red", ""); 
static MagicsParameter<string> wind_advanced_colour_list_policy("wind_advanced_colour_list_policy", "lastone", ""); 
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

/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file AxisAttributes.h
    \\brief Definition of Axis Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 2020-09-24
*/

#include "AxisAttributes.h"
#include "MagicsParameter.h"
#include "ParameterSettings.h"

using namespace magics;

AxisAttributes::AxisAttributes():
	orientation_(ParameterManager::getString("axis_orientation")),
	position_(ParameterManager::getString("axis_position")),
	line_(ParameterManager::getBool("axis_line")),
	line_thickness_(ParameterManager::getInt("axis_line_thickness")),
	grid_(ParameterManager::getBool("axis_grid")),
	grid_thickness_(ParameterManager::getInt("axis_grid_thickness")),
	minor_grid_(ParameterManager::getBool("axis_minor_grid")),
	minor_grid_thickness_(ParameterManager::getInt("axis_minor_grid_thickness")),
	grid_reference_level_(ParameterManager::getDouble("axis_grid_reference_level")),
	grid_reference_thickness_(ParameterManager::getInt("axis_grid_reference_thickness")),
	title_(ParameterManager::getBool("axis_title")),
	title_text_(ParameterManager::getString("axis_title_text")),
	title_orientation_(ParameterManager::getString("axis_title_orientation")),
	title_height_(ParameterManager::getDouble("axis_title_height")),
	title_font_(ParameterManager::getString("axis_title_font")),
	title_font_style_(ParameterManager::getString("axis_title_font_style")),
	title_relative_position_(ParameterManager::getDouble("axis_title_position")),
	tick_(ParameterManager::getBool("axis_tick")),
	interval_(ParameterManager::getDouble("axis_tick_interval")),
	positions_(ParameterManager::getDoubleArray("axis_tick_position_list")),
	tick_position_(ParameterManager::getString("axis_tick_position")),
	tick_length_(ParameterManager::getDouble("axis_tick_size")),
	tick_thickness_(ParameterManager::getInt("axis_tick_thickness")),
	label_(ParameterManager::getBool("axis_tick_label")),
	label_type_(ParameterManager::getString("axis_tick_label_type")),
	label_frequency_(ParameterManager::getInt("axis_tick_label_frequency")),
	label_first_(ParameterManager::getBool("axis_tick_label_first")),
	label_last_(ParameterManager::getBool("axis_tick_label_last")),
	label_position_(ParameterManager::getString("axis_tick_label_position")),
	label_orientation_(ParameterManager::getString("axis_tick_label_orientation")),
	label_font_(ParameterManager::getString("axis_tick_label_font")),
	label_font_style_(ParameterManager::getString("axis_tick_label_font_style")),
	label_height_(ParameterManager::getDouble("axis_tick_label_height")),
	label_labels_(ParameterManager::getStringArray("axis_tick_label_list")),
	label_format_(ParameterManager::getString("axis_tick_label_format")),
	minor_tick_(ParameterManager::getBool("axis_minor_tick")),
	minor_tick_count_(ParameterManager::getInt("axis_minor_tick_count")),
	minor_tick_thickness_(ParameterManager::getInt("axis_minor_tick_thickness")),
	tip_(ParameterManager::getBool("axis_tip_title")),
	tip_text_(ParameterManager::getString("axis_tip_title_text")),
	tip_height_(ParameterManager::getDouble("axis_tip_title_height")),
	tip_quality_(ParameterManager::getString("axis_tip_title_quality"))
	,
	method_(MagTranslator<string, AxisMethod>().magics("axis_type")),
	line_colour_(MagTranslator<string, Colour>().magics("axis_line_colour")),
	line_style_(MagTranslator<string, LineStyle>().magics("axis_line_style")),
	grid_colour_(MagTranslator<string, Colour>().magics("axis_grid_colour")),
	grid_style_(MagTranslator<string, LineStyle>().magics("axis_grid_line_style")),
	minor_grid_colour_(MagTranslator<string, Colour>().magics("axis_minor_grid_colour")),
	minor_grid_style_(MagTranslator<string, LineStyle>().magics("axis_minor_grid_line_style")),
	grid_reference_colour_(MagTranslator<string, Colour>().magics("axis_grid_reference_colour")),
	grid_reference_style_(MagTranslator<string, LineStyle>().magics("axis_grid_reference_line_style")),
	title_colour_(MagTranslator<string, Colour>().magics("axis_title_colour")),
	tick_colour_(MagTranslator<string, Colour>().magics("axis_tick_colour")),
	label_colour_(MagTranslator<string, Colour>().magics("axis_tick_label_colour")),
	minor_tick_colour_(MagTranslator<string, Colour>().magics("axis_minor_tick_colour")),
	tip_colour_(MagTranslator<string, Colour>().magics("axis_tip_title_colour"))
	 
{
} 


AxisAttributes::~AxisAttributes()
{
	
}

    
void AxisAttributes::set(const std::map<string, string>& params)
{
	vector<string> prefix(1);
	int i = 0;
	prefix[i++] = "";
	
	setAttribute(prefix, "axis_orientation", orientation_, params);
	setAttribute(prefix, "axis_position", position_, params);
	setAttribute(prefix, "axis_line", line_, params);
	setAttribute(prefix, "axis_line_thickness", line_thickness_, params);
	setAttribute(prefix, "axis_grid", grid_, params);
	setAttribute(prefix, "axis_grid_thickness", grid_thickness_, params);
	setAttribute(prefix, "axis_minor_grid", minor_grid_, params);
	setAttribute(prefix, "axis_minor_grid_thickness", minor_grid_thickness_, params);
	setAttribute(prefix, "axis_grid_reference_level", grid_reference_level_, params);
	setAttribute(prefix, "axis_grid_reference_thickness", grid_reference_thickness_, params);
	setAttribute(prefix, "axis_title", title_, params);
	setAttribute(prefix, "axis_title_text", title_text_, params);
	setAttribute(prefix, "axis_title_orientation", title_orientation_, params);
	setAttribute(prefix, "axis_title_height", title_height_, params);
	setAttribute(prefix, "axis_title_font", title_font_, params);
	setAttribute(prefix, "axis_title_font_style", title_font_style_, params);
	setAttribute(prefix, "axis_title_position", title_relative_position_, params);
	setAttribute(prefix, "axis_tick", tick_, params);
	setAttribute(prefix, "axis_tick_interval", interval_, params);
	setAttribute(prefix, "axis_tick_position_list", positions_, params);
	setAttribute(prefix, "axis_tick_position", tick_position_, params);
	setAttribute(prefix, "axis_tick_size", tick_length_, params);
	setAttribute(prefix, "axis_tick_thickness", tick_thickness_, params);
	setAttribute(prefix, "axis_tick_label", label_, params);
	setAttribute(prefix, "axis_tick_label_type", label_type_, params);
	setAttribute(prefix, "axis_tick_label_frequency", label_frequency_, params);
	setAttribute(prefix, "axis_tick_label_first", label_first_, params);
	setAttribute(prefix, "axis_tick_label_last", label_last_, params);
	setAttribute(prefix, "axis_tick_label_position", label_position_, params);
	setAttribute(prefix, "axis_tick_label_orientation", label_orientation_, params);
	setAttribute(prefix, "axis_tick_label_font", label_font_, params);
	setAttribute(prefix, "axis_tick_label_font_style", label_font_style_, params);
	setAttribute(prefix, "axis_tick_label_height", label_height_, params);
	setAttribute(prefix, "axis_tick_label_list", label_labels_, params);
	setAttribute(prefix, "axis_tick_label_format", label_format_, params);
	setAttribute(prefix, "axis_minor_tick", minor_tick_, params);
	setAttribute(prefix, "axis_minor_tick_count", minor_tick_count_, params);
	setAttribute(prefix, "axis_minor_tick_thickness", minor_tick_thickness_, params);
	setAttribute(prefix, "axis_tip_title", tip_, params);
	setAttribute(prefix, "axis_tip_title_text", tip_text_, params);
	setAttribute(prefix, "axis_tip_title_height", tip_height_, params);
	setAttribute(prefix, "axis_tip_title_quality", tip_quality_, params);
	
	setMember(prefix, "axis_type", method_, params);
	setMember(prefix, "axis_line_colour", line_colour_, params);
	setAttribute(prefix, "axis_line_style", line_style_, params);
	setMember(prefix, "axis_grid_colour", grid_colour_, params);
	setAttribute(prefix, "axis_grid_line_style", grid_style_, params);
	setMember(prefix, "axis_minor_grid_colour", minor_grid_colour_, params);
	setAttribute(prefix, "axis_minor_grid_line_style", minor_grid_style_, params);
	setMember(prefix, "axis_grid_reference_colour", grid_reference_colour_, params);
	setAttribute(prefix, "axis_grid_reference_line_style", grid_reference_style_, params);
	setMember(prefix, "axis_title_colour", title_colour_, params);
	setMember(prefix, "axis_tick_colour", tick_colour_, params);
	setMember(prefix, "axis_tick_label_colour", label_colour_, params);
	setMember(prefix, "axis_minor_tick_colour", minor_tick_colour_, params);
	setMember(prefix, "axis_tip_title_colour", tip_colour_, params);
	
}

void AxisAttributes::copy(const AxisAttributes& other)
{
	orientation_ = other.orientation_;
	position_ = other.position_;
	line_ = other.line_;
	line_thickness_ = other.line_thickness_;
	grid_ = other.grid_;
	grid_thickness_ = other.grid_thickness_;
	minor_grid_ = other.minor_grid_;
	minor_grid_thickness_ = other.minor_grid_thickness_;
	grid_reference_level_ = other.grid_reference_level_;
	grid_reference_thickness_ = other.grid_reference_thickness_;
	title_ = other.title_;
	title_text_ = other.title_text_;
	title_orientation_ = other.title_orientation_;
	title_height_ = other.title_height_;
	title_font_ = other.title_font_;
	title_font_style_ = other.title_font_style_;
	title_relative_position_ = other.title_relative_position_;
	tick_ = other.tick_;
	interval_ = other.interval_;
	positions_ = other.positions_;
	tick_position_ = other.tick_position_;
	tick_length_ = other.tick_length_;
	tick_thickness_ = other.tick_thickness_;
	label_ = other.label_;
	label_type_ = other.label_type_;
	label_frequency_ = other.label_frequency_;
	label_first_ = other.label_first_;
	label_last_ = other.label_last_;
	label_position_ = other.label_position_;
	label_orientation_ = other.label_orientation_;
	label_font_ = other.label_font_;
	label_font_style_ = other.label_font_style_;
	label_height_ = other.label_height_;
	label_labels_ = other.label_labels_;
	label_format_ = other.label_format_;
	minor_tick_ = other.minor_tick_;
	minor_tick_count_ = other.minor_tick_count_;
	minor_tick_thickness_ = other.minor_tick_thickness_;
	tip_ = other.tip_;
	tip_text_ = other.tip_text_;
	tip_height_ = other.tip_height_;
	tip_quality_ = other.tip_quality_;
	method_ = unique_ptr<AxisMethod>(other.method_->clone());
	line_colour_ = unique_ptr<Colour>(other.line_colour_->clone());
	line_style_ = other.line_style_;
	grid_colour_ = unique_ptr<Colour>(other.grid_colour_->clone());
	grid_style_ = other.grid_style_;
	minor_grid_colour_ = unique_ptr<Colour>(other.minor_grid_colour_->clone());
	minor_grid_style_ = other.minor_grid_style_;
	grid_reference_colour_ = unique_ptr<Colour>(other.grid_reference_colour_->clone());
	grid_reference_style_ = other.grid_reference_style_;
	title_colour_ = unique_ptr<Colour>(other.title_colour_->clone());
	tick_colour_ = unique_ptr<Colour>(other.tick_colour_->clone());
	label_colour_ = unique_ptr<Colour>(other.label_colour_->clone());
	minor_tick_colour_ = unique_ptr<Colour>(other.minor_tick_colour_->clone());
	tip_colour_ = unique_ptr<Colour>(other.tip_colour_->clone());
	
} 


bool AxisAttributes::accept(const string& node)
{	
	
	if ( magCompare(node, "axis")  )
		return true;
	if ( acceptNode(node, method_) )
		return true;
	
	return false;
}

void AxisAttributes::set(const XmlNode& node)
{
	bool apply = false;

	if ( this->accept(node.name()) == false ) 
		return;

	if ( magCompare(node.name(), "axis")  )
		apply = true;
	

	if ( apply )
		set(node.attributes());
	else {
		setMember(node.name(), method_, node);
		
	}
	for (auto &elt : node.elements())
	{
		setMember(elt->name(), method_, *elt); 
		
	}
}

void AxisAttributes::print(ostream& out)  const
{
	out << "Attributes[";
	out << " orientation = " <<  orientation_;
	out << " position = " <<  position_;
	out << " line = " <<  line_;
	out << " line_thickness = " <<  line_thickness_;
	out << " grid = " <<  grid_;
	out << " grid_thickness = " <<  grid_thickness_;
	out << " minor_grid = " <<  minor_grid_;
	out << " minor_grid_thickness = " <<  minor_grid_thickness_;
	out << " grid_reference_level = " <<  grid_reference_level_;
	out << " grid_reference_thickness = " <<  grid_reference_thickness_;
	out << " title = " <<  title_;
	out << " title_text = " <<  title_text_;
	out << " title_orientation = " <<  title_orientation_;
	out << " title_height = " <<  title_height_;
	out << " title_font = " <<  title_font_;
	out << " title_font_style = " <<  title_font_style_;
	out << " title_relative_position = " <<  title_relative_position_;
	out << " tick = " <<  tick_;
	out << " interval = " <<  interval_;
	out << " positions = " <<  positions_;
	out << " tick_position = " <<  tick_position_;
	out << " tick_length = " <<  tick_length_;
	out << " tick_thickness = " <<  tick_thickness_;
	out << " label = " <<  label_;
	out << " label_type = " <<  label_type_;
	out << " label_frequency = " <<  label_frequency_;
	out << " label_first = " <<  label_first_;
	out << " label_last = " <<  label_last_;
	out << " label_position = " <<  label_position_;
	out << " label_orientation = " <<  label_orientation_;
	out << " label_font = " <<  label_font_;
	out << " label_font_style = " <<  label_font_style_;
	out << " label_height = " <<  label_height_;
	out << " label_labels = " <<  label_labels_;
	out << " label_format = " <<  label_format_;
	out << " minor_tick = " <<  minor_tick_;
	out << " minor_tick_count = " <<  minor_tick_count_;
	out << " minor_tick_thickness = " <<  minor_tick_thickness_;
	out << " tip = " <<  tip_;
	out << " tip_text = " <<  tip_text_;
	out << " tip_height = " <<  tip_height_;
	out << " tip_quality = " <<  tip_quality_;
	out << " method = " <<  *method_;
	out << " line_colour = " <<  *line_colour_;
	out << " line_style = " <<  line_style_;
	out << " grid_colour = " <<  *grid_colour_;
	out << " grid_style = " <<  grid_style_;
	out << " minor_grid_colour = " <<  *minor_grid_colour_;
	out << " minor_grid_style = " <<  minor_grid_style_;
	out << " grid_reference_colour = " <<  *grid_reference_colour_;
	out << " grid_reference_style = " <<  grid_reference_style_;
	out << " title_colour = " <<  *title_colour_;
	out << " tick_colour = " <<  *tick_colour_;
	out << " label_colour = " <<  *label_colour_;
	out << " minor_tick_colour = " <<  *minor_tick_colour_;
	out << " tip_colour = " <<  *tip_colour_;
	
	out << "]" << "\n";
}

void AxisAttributes::toxml(ostream& out)  const
{
	out <<  "\"axis\""; 
	out << ", \"axis_orientation\":";
	niceprint(out,orientation_);
	out << ", \"axis_position\":";
	niceprint(out,position_);
	out << ", \"axis_line\":";
	niceprint(out,line_);
	out << ", \"axis_line_thickness\":";
	niceprint(out,line_thickness_);
	out << ", \"axis_grid\":";
	niceprint(out,grid_);
	out << ", \"axis_grid_thickness\":";
	niceprint(out,grid_thickness_);
	out << ", \"axis_minor_grid\":";
	niceprint(out,minor_grid_);
	out << ", \"axis_minor_grid_thickness\":";
	niceprint(out,minor_grid_thickness_);
	out << ", \"axis_grid_reference_level\":";
	niceprint(out,grid_reference_level_);
	out << ", \"axis_grid_reference_thickness\":";
	niceprint(out,grid_reference_thickness_);
	out << ", \"axis_title\":";
	niceprint(out,title_);
	out << ", \"axis_title_text\":";
	niceprint(out,title_text_);
	out << ", \"axis_title_orientation\":";
	niceprint(out,title_orientation_);
	out << ", \"axis_title_height\":";
	niceprint(out,title_height_);
	out << ", \"axis_title_font\":";
	niceprint(out,title_font_);
	out << ", \"axis_title_font_style\":";
	niceprint(out,title_font_style_);
	out << ", \"axis_title_position\":";
	niceprint(out,title_relative_position_);
	out << ", \"axis_tick\":";
	niceprint(out,tick_);
	out << ", \"axis_tick_interval\":";
	niceprint(out,interval_);
	out << ", \"axis_tick_position_list\":";
	niceprint(out,positions_);
	out << ", \"axis_tick_position\":";
	niceprint(out,tick_position_);
	out << ", \"axis_tick_size\":";
	niceprint(out,tick_length_);
	out << ", \"axis_tick_thickness\":";
	niceprint(out,tick_thickness_);
	out << ", \"axis_tick_label\":";
	niceprint(out,label_);
	out << ", \"axis_tick_label_type\":";
	niceprint(out,label_type_);
	out << ", \"axis_tick_label_frequency\":";
	niceprint(out,label_frequency_);
	out << ", \"axis_tick_label_first\":";
	niceprint(out,label_first_);
	out << ", \"axis_tick_label_last\":";
	niceprint(out,label_last_);
	out << ", \"axis_tick_label_position\":";
	niceprint(out,label_position_);
	out << ", \"axis_tick_label_orientation\":";
	niceprint(out,label_orientation_);
	out << ", \"axis_tick_label_font\":";
	niceprint(out,label_font_);
	out << ", \"axis_tick_label_font_style\":";
	niceprint(out,label_font_style_);
	out << ", \"axis_tick_label_height\":";
	niceprint(out,label_height_);
	out << ", \"axis_tick_label_list\":";
	niceprint(out,label_labels_);
	out << ", \"axis_tick_label_format\":";
	niceprint(out,label_format_);
	out << ", \"axis_minor_tick\":";
	niceprint(out,minor_tick_);
	out << ", \"axis_minor_tick_count\":";
	niceprint(out,minor_tick_count_);
	out << ", \"axis_minor_tick_thickness\":";
	niceprint(out,minor_tick_thickness_);
	out << ", \"axis_tip_title\":";
	niceprint(out,tip_);
	out << ", \"axis_tip_title_text\":";
	niceprint(out,tip_text_);
	out << ", \"axis_tip_title_height\":";
	niceprint(out,tip_height_);
	out << ", \"axis_tip_title_quality\":";
	niceprint(out,tip_quality_);
	out << ", \"axis_type\":";
	method_->toxml(out);
	out << ", \"axis_line_colour\":";
	niceprint(out, *line_colour_);
	out << ", \"axis_line_style\":";
	niceprint(out, line_style_);
	out << ", \"axis_grid_colour\":";
	niceprint(out, *grid_colour_);
	out << ", \"axis_grid_line_style\":";
	niceprint(out, grid_style_);
	out << ", \"axis_minor_grid_colour\":";
	niceprint(out, *minor_grid_colour_);
	out << ", \"axis_minor_grid_line_style\":";
	niceprint(out, minor_grid_style_);
	out << ", \"axis_grid_reference_colour\":";
	niceprint(out, *grid_reference_colour_);
	out << ", \"axis_grid_reference_line_style\":";
	niceprint(out, grid_reference_style_);
	out << ", \"axis_title_colour\":";
	niceprint(out, *title_colour_);
	out << ", \"axis_tick_colour\":";
	niceprint(out, *tick_colour_);
	out << ", \"axis_tick_label_colour\":";
	niceprint(out, *label_colour_);
	out << ", \"axis_minor_tick_colour\":";
	niceprint(out, *minor_tick_colour_);
	out << ", \"axis_tip_title_colour\":";
	niceprint(out, *tip_colour_);
	
}

static MagicsParameter<string> axis_orientation("axis_orientation", "horizontal", "");
static MagicsParameter<string> axis_position("axis_position", "automatic", "");
static MagicsParameter<string> axis_line("axis_line", "on", "");
static MagicsParameter<int> axis_line_thickness("axis_line_thickness", 2, "");
static MagicsParameter<string> axis_grid("axis_grid", "off", "");
static MagicsParameter<int> axis_grid_thickness("axis_grid_thickness", 1, "");
static MagicsParameter<string> axis_minor_grid("axis_minor_grid", "off", "");
static MagicsParameter<int> axis_minor_grid_thickness("axis_minor_grid_thickness", 1, "");
static MagicsParameter<double> axis_grid_reference_level("axis_grid_reference_level", INT_MAX, "");
static MagicsParameter<int> axis_grid_reference_thickness("axis_grid_reference_thickness", 2, "");
static MagicsParameter<string> axis_title("axis_title", "on", "");
static MagicsParameter<string> axis_title_text("axis_title_text", "", "");
static MagicsParameter<string> axis_title_orientation("axis_title_orientation", "parallel", "");
static MagicsParameter<double> axis_title_height("axis_title_height", 0.4, "");
static MagicsParameter<string> axis_title_font("axis_title_font", "sansserif", "");
static MagicsParameter<string> axis_title_font_style("axis_title_font_style", "normal", "");
static MagicsParameter<double> axis_title_position("axis_title_position", -1, "");
static MagicsParameter<string> axis_tick("axis_tick", "on", "");
static MagicsParameter<double> axis_tick_interval("axis_tick_interval", INT_MAX, "");
static MagicsParameter<doublearray> axis_tick_position_list("axis_tick_position_list", floatarray(), "");
static MagicsParameter<string> axis_tick_position("axis_tick_position", "out", "");
static MagicsParameter<double> axis_tick_size("axis_tick_size", 0.175, "");
static MagicsParameter<int> axis_tick_thickness("axis_tick_thickness", 2, "");
static MagicsParameter<string> axis_tick_label("axis_tick_label", "on", "");
static MagicsParameter<string> axis_tick_label_type("axis_tick_label_type", "number", "");
static MagicsParameter<int> axis_tick_label_frequency("axis_tick_label_frequency", 1, "");
static MagicsParameter<string> axis_tick_label_first("axis_tick_label_first", "on", "");
static MagicsParameter<string> axis_tick_label_last("axis_tick_label_last", "on", "");
static MagicsParameter<string> axis_tick_label_position("axis_tick_label_position", "on_tick", "");
static MagicsParameter<string> axis_tick_label_orientation("axis_tick_label_orientation", "horizontal", "");
static MagicsParameter<string> axis_tick_label_font("axis_tick_label_font", "sansserif", "");
static MagicsParameter<string> axis_tick_label_font_style("axis_tick_label_font_style", "normal", "");
static MagicsParameter<double> axis_tick_label_height("axis_tick_label_height", 0.3, "");
static MagicsParameter<stringarray> axis_tick_label_list("axis_tick_label_list", stringarray(), "");
static MagicsParameter<string> axis_tick_label_format("axis_tick_label_format", "(automatic)", "");
static MagicsParameter<string> axis_minor_tick("axis_minor_tick", "off", "");
static MagicsParameter<int> axis_minor_tick_count("axis_minor_tick_count", 2, "");
static MagicsParameter<int> axis_minor_tick_thickness("axis_minor_tick_thickness", 1, "");
static MagicsParameter<string> axis_tip_title("axis_tip_title", "off", "");
static MagicsParameter<string> axis_tip_title_text("axis_tip_title_text", "", "");
static MagicsParameter<double> axis_tip_title_height("axis_tip_title_height", 0.4, "");
static MagicsParameter<string> axis_tip_title_quality("axis_tip_title_quality", "medium", "");
static MagicsParameter<string> axis_type("axis_type", "regular", ""); 
static MagicsParameter<string> axis_line_colour("axis_line_colour", "automatic", ""); 
static MagicsParameter<string> axis_line_style("axis_line_style", "solid", ""); 
static MagicsParameter<string> axis_grid_colour("axis_grid_colour", "black", ""); 
static MagicsParameter<string> axis_grid_line_style("axis_grid_line_style", "solid", ""); 
static MagicsParameter<string> axis_minor_grid_colour("axis_minor_grid_colour", "black", ""); 
static MagicsParameter<string> axis_minor_grid_line_style("axis_minor_grid_line_style", "solid", ""); 
static MagicsParameter<string> axis_grid_reference_colour("axis_grid_reference_colour", "automatic", ""); 
static MagicsParameter<string> axis_grid_reference_line_style("axis_grid_reference_line_style", "solid", ""); 
static MagicsParameter<string> axis_title_colour("axis_title_colour", "automatic", ""); 
static MagicsParameter<string> axis_tick_colour("axis_tick_colour", "automatic", ""); 
static MagicsParameter<string> axis_tick_label_colour("axis_tick_label_colour", "automatic", ""); 
static MagicsParameter<string> axis_minor_tick_colour("axis_minor_tick_colour", "automatic", ""); 
static MagicsParameter<string> axis_tip_title_colour("axis_tip_title_colour", "automatic", ""); 
#include "AxisMethod.h"
#include "DateAxis.h"
static SimpleObjectMaker<AxisMethod , AxisMethod> regular_AxisMethod("regular");
static SimpleObjectMaker<PositionListAxisMethod , AxisMethod> position_list_PositionListAxisMethod("position_list");
static SimpleObjectMaker<LogarithmicAxisMethod , AxisMethod> logarithmic_LogarithmicAxisMethod("logarithmic");
static SimpleObjectMaker<DateAxisMethod , AxisMethod> date_DateAxisMethod("date");
static SimpleObjectMaker<HyperAxisMethod , AxisMethod> geoline_HyperAxisMethod("geoline");
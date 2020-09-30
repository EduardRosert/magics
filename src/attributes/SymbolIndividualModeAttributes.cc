
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file SymbolIndividualModeAttributes.h
    \\brief Definition of SymbolIndividualMode Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 2020-09-24
*/

#include "SymbolIndividualModeAttributes.h"
#include "MagicsParameter.h"
#include "ParameterSettings.h"

using namespace magics;

SymbolIndividualModeAttributes::SymbolIndividualModeAttributes():
	legend_text_(ParameterManager::getString("legend_user_text")),
	height_(ParameterManager::getDouble("symbol_height")),
	marker_mode_(ParameterManager::getString("symbol_marker_mode")),
	marker_(ParameterManager::getInt("symbol_marker_index")),
	symbol_(ParameterManager::getString("symbol_marker_name")),
	image_path_(ParameterManager::getString("symbol_image_path")),
	image_format_(ParameterManager::getString("symbol_image_format")),
	image_width_(ParameterManager::getDouble("symbol_image_width")),
	image_height_(ParameterManager::getDouble("symbol_image_height")),
	text_(ParameterManager::getStringArray("symbol_text_list")),
	text_position_(ParameterManager::getString("symbol_text_position")),
	text_font_name_(ParameterManager::getString("symbol_text_font")),
	text_font_size_(ParameterManager::getDouble("symbol_text_font_size")),
	text_font_style_(ParameterManager::getString("symbol_text_font_style")),
	legend_height_(ParameterManager::getDouble("symbol_legend_height"))
	,
	colour_(MagTranslator<string, Colour>().magics("symbol_colour")),
	text_font_colour_(MagTranslator<string, Colour>().magics("symbol_text_font_colour"))
	 
{
} 


SymbolIndividualModeAttributes::~SymbolIndividualModeAttributes()
{
	
}

    
void SymbolIndividualModeAttributes::set(const std::map<string, string>& params)
{
	vector<string> prefix(1);
	int i = 0;
	prefix[i++] = "symbol";
	
	setAttribute(prefix, "legend_user_text", legend_text_, params);
	setAttribute(prefix, "symbol_height", height_, params);
	setAttribute(prefix, "symbol_marker_mode", marker_mode_, params);
	setAttribute(prefix, "symbol_marker_index", marker_, params);
	setAttribute(prefix, "symbol_marker_name", symbol_, params);
	setAttribute(prefix, "symbol_image_path", image_path_, params);
	setAttribute(prefix, "symbol_image_format", image_format_, params);
	setAttribute(prefix, "symbol_image_width", image_width_, params);
	setAttribute(prefix, "symbol_image_height", image_height_, params);
	setAttribute(prefix, "symbol_text_list", text_, params);
	setAttribute(prefix, "symbol_text_position", text_position_, params);
	setAttribute(prefix, "symbol_text_font", text_font_name_, params);
	setAttribute(prefix, "symbol_text_font_size", text_font_size_, params);
	setAttribute(prefix, "symbol_text_font_style", text_font_style_, params);
	setAttribute(prefix, "symbol_legend_height", legend_height_, params);
	
	setMember(prefix, "symbol_colour", colour_, params);
	setMember(prefix, "symbol_text_font_colour", text_font_colour_, params);
	
}

void SymbolIndividualModeAttributes::copy(const SymbolIndividualModeAttributes& other)
{
	legend_text_ = other.legend_text_;
	height_ = other.height_;
	marker_mode_ = other.marker_mode_;
	marker_ = other.marker_;
	symbol_ = other.symbol_;
	image_path_ = other.image_path_;
	image_format_ = other.image_format_;
	image_width_ = other.image_width_;
	image_height_ = other.image_height_;
	text_ = other.text_;
	text_position_ = other.text_position_;
	text_font_name_ = other.text_font_name_;
	text_font_size_ = other.text_font_size_;
	text_font_style_ = other.text_font_style_;
	legend_height_ = other.legend_height_;
	colour_ = unique_ptr<Colour>(other.colour_->clone());
	text_font_colour_ = unique_ptr<Colour>(other.text_font_colour_->clone());
	
} 


bool SymbolIndividualModeAttributes::accept(const string& node)
{	
	
	if ( magCompare(node, "individual")  )
		return true;
	
	return false;
}

void SymbolIndividualModeAttributes::set(const XmlNode& node)
{
	bool apply = false;

	if ( this->accept(node.name()) == false ) 
		return;

	if ( magCompare(node.name(), "individual")  )
		apply = true;
	

	if ( apply )
		set(node.attributes());
	else {
		
	}
	for (auto &elt : node.elements())
	{
		
	}
}

void SymbolIndividualModeAttributes::print(ostream& out)  const
{
	out << "Attributes[";
	out << " legend_text = " <<  legend_text_;
	out << " height = " <<  height_;
	out << " marker_mode = " <<  marker_mode_;
	out << " marker = " <<  marker_;
	out << " symbol = " <<  symbol_;
	out << " image_path = " <<  image_path_;
	out << " image_format = " <<  image_format_;
	out << " image_width = " <<  image_width_;
	out << " image_height = " <<  image_height_;
	out << " text = " <<  text_;
	out << " text_position = " <<  text_position_;
	out << " text_font_name = " <<  text_font_name_;
	out << " text_font_size = " <<  text_font_size_;
	out << " text_font_style = " <<  text_font_style_;
	out << " legend_height = " <<  legend_height_;
	out << " colour = " <<  *colour_;
	out << " text_font_colour = " <<  *text_font_colour_;
	
	out << "]" << "\n";
}

void SymbolIndividualModeAttributes::toxml(ostream& out)  const
{
	out <<  "\"individual\""; 
	out << ", \"legend_user_text\":";
	niceprint(out,legend_text_);
	out << ", \"symbol_height\":";
	niceprint(out,height_);
	out << ", \"symbol_marker_mode\":";
	niceprint(out,marker_mode_);
	out << ", \"symbol_marker_index\":";
	niceprint(out,marker_);
	out << ", \"symbol_marker_name\":";
	niceprint(out,symbol_);
	out << ", \"symbol_image_path\":";
	niceprint(out,image_path_);
	out << ", \"symbol_image_format\":";
	niceprint(out,image_format_);
	out << ", \"symbol_image_width\":";
	niceprint(out,image_width_);
	out << ", \"symbol_image_height\":";
	niceprint(out,image_height_);
	out << ", \"symbol_text_list\":";
	niceprint(out,text_);
	out << ", \"symbol_text_position\":";
	niceprint(out,text_position_);
	out << ", \"symbol_text_font\":";
	niceprint(out,text_font_name_);
	out << ", \"symbol_text_font_size\":";
	niceprint(out,text_font_size_);
	out << ", \"symbol_text_font_style\":";
	niceprint(out,text_font_style_);
	out << ", \"symbol_legend_height\":";
	niceprint(out,legend_height_);
	out << ", \"symbol_colour\":";
	niceprint(out, *colour_);
	out << ", \"symbol_text_font_colour\":";
	niceprint(out, *text_font_colour_);
	
}

static MagicsParameter<string> legend_user_text("legend_user_text", "", "");
static MagicsParameter<double> symbol_height("symbol_height", 0.2, "");
static MagicsParameter<string> symbol_marker_mode("symbol_marker_mode", "index", "");
static MagicsParameter<int> symbol_marker_index("symbol_marker_index", 1, "");
static MagicsParameter<string> symbol_marker_name("symbol_marker_name", "dot", "");
static MagicsParameter<string> symbol_image_path("symbol_image_path", "", "");
static MagicsParameter<string> symbol_image_format("symbol_image_format", "automatic", "");
static MagicsParameter<double> symbol_image_width("symbol_image_width", -1, "");
static MagicsParameter<double> symbol_image_height("symbol_image_height", -1, "");
static MagicsParameter<stringarray> symbol_text_list("symbol_text_list", stringarray(), "");
static MagicsParameter<string> symbol_text_position("symbol_text_position", "right", "");
static MagicsParameter<string> symbol_text_font("symbol_text_font", "sansserif", "");
static MagicsParameter<double> symbol_text_font_size("symbol_text_font_size", 0.25, "");
static MagicsParameter<string> symbol_text_font_style("symbol_text_font_style", "normal", "");
static MagicsParameter<double> symbol_legend_height("symbol_legend_height", -1, "");
static MagicsParameter<string> symbol_colour("symbol_colour", "blue", ""); 
static MagicsParameter<string> symbol_text_font_colour("symbol_text_font_colour", "automatic", ""); 
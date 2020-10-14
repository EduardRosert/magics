
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file XmlBasicNodeAttributes.h
    \\brief Definition of XmlBasicNode Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 2020-10-14
*/

#include "XmlBasicNodeAttributes.h"
#include "MagicsParameter.h"
#include "ParameterSettings.h"

using namespace magics;

XmlBasicNodeAttributes::XmlBasicNodeAttributes():
	standalone_(ParameterManager::getBool("view_standalone")),
	standalone_path_(ParameterManager::getString("view_standalone_file_name")),
	standalone_format_(ParameterManager::getString("view_standalone_format")),
	standalone_width_(ParameterManager::getDouble("view_standalone_width")),
	standalone_height_(ParameterManager::getDouble("view_standalone_height")),
	bottom_(ParameterManager::getString("view_bottom")),
	left_(ParameterManager::getString("view_left")),
	width_(ParameterManager::getString("view_width")),
	height_(ParameterManager::getString("view_height")),
	margin_bottom_(ParameterManager::getString("view_margin_bottom")),
	margin_left_(ParameterManager::getString("view_margin_left")),
	margin_right_(ParameterManager::getString("view_margin_right")),
	margin_top_(ParameterManager::getString("view_margin_top")),
	border_bottom_(ParameterManager::getString("view_border_bottom")),
	border_left_(ParameterManager::getString("view_border_left")),
	border_right_(ParameterManager::getString("view_border_right")),
	border_top_(ParameterManager::getString("view_border_top")),
	border_(ParameterManager::getBool("view_border")),
	blanking_(ParameterManager::getBool("view_blanking")),
	border_thickness_(ParameterManager::getInt("view_border_thickness")),
	padding_bottom_(ParameterManager::getString("view_padding_bottom")),
	padding_left_(ParameterManager::getString("view_padding_left")),
	padding_right_(ParameterManager::getString("view_padding_right")),
	padding_top_(ParameterManager::getString("view_padding_top"))
	,
	display_(MagTranslator<string, DisplayType>().magics("view_display")),
	background_(MagTranslator<string, Colour>().magics("view_background_colour")),
	border_colour_(MagTranslator<string, Colour>().magics("view_border_colour")),
	border_style_(MagTranslator<string, LineStyle>().magics("view_border_style")),
	padding_colour_(MagTranslator<string, Colour>().magics("view_padding_colour"))
	 
{
} 


XmlBasicNodeAttributes::~XmlBasicNodeAttributes()
{
	
}

    
void XmlBasicNodeAttributes::set(const std::map<string, string>& params)
{
	vector<string> prefix(1);
	int i = 0;
	prefix[i++] = "view";
	
	setAttribute(prefix, "view_standalone", standalone_, params);
	setAttribute(prefix, "view_standalone_file_name", standalone_path_, params);
	setAttribute(prefix, "view_standalone_format", standalone_format_, params);
	setAttribute(prefix, "view_standalone_width", standalone_width_, params);
	setAttribute(prefix, "view_standalone_height", standalone_height_, params);
	setAttribute(prefix, "view_bottom", bottom_, params);
	setAttribute(prefix, "view_left", left_, params);
	setAttribute(prefix, "view_width", width_, params);
	setAttribute(prefix, "view_height", height_, params);
	setAttribute(prefix, "view_margin_bottom", margin_bottom_, params);
	setAttribute(prefix, "view_margin_left", margin_left_, params);
	setAttribute(prefix, "view_margin_right", margin_right_, params);
	setAttribute(prefix, "view_margin_top", margin_top_, params);
	setAttribute(prefix, "view_border_bottom", border_bottom_, params);
	setAttribute(prefix, "view_border_left", border_left_, params);
	setAttribute(prefix, "view_border_right", border_right_, params);
	setAttribute(prefix, "view_border_top", border_top_, params);
	setAttribute(prefix, "view_border", border_, params);
	setAttribute(prefix, "view_blanking", blanking_, params);
	setAttribute(prefix, "view_border_thickness", border_thickness_, params);
	setAttribute(prefix, "view_padding_bottom", padding_bottom_, params);
	setAttribute(prefix, "view_padding_left", padding_left_, params);
	setAttribute(prefix, "view_padding_right", padding_right_, params);
	setAttribute(prefix, "view_padding_top", padding_top_, params);
	
	setAttribute(prefix, "view_display", display_, params);
	setMember(prefix, "view_background_colour", background_, params);
	setMember(prefix, "view_border_colour", border_colour_, params);
	setAttribute(prefix, "view_border_style", border_style_, params);
	setMember(prefix, "view_padding_colour", padding_colour_, params);
	
}

void XmlBasicNodeAttributes::copy(const XmlBasicNodeAttributes& other)
{
	standalone_ = other.standalone_;
	standalone_path_ = other.standalone_path_;
	standalone_format_ = other.standalone_format_;
	standalone_width_ = other.standalone_width_;
	standalone_height_ = other.standalone_height_;
	bottom_ = other.bottom_;
	left_ = other.left_;
	width_ = other.width_;
	height_ = other.height_;
	margin_bottom_ = other.margin_bottom_;
	margin_left_ = other.margin_left_;
	margin_right_ = other.margin_right_;
	margin_top_ = other.margin_top_;
	border_bottom_ = other.border_bottom_;
	border_left_ = other.border_left_;
	border_right_ = other.border_right_;
	border_top_ = other.border_top_;
	border_ = other.border_;
	blanking_ = other.blanking_;
	border_thickness_ = other.border_thickness_;
	padding_bottom_ = other.padding_bottom_;
	padding_left_ = other.padding_left_;
	padding_right_ = other.padding_right_;
	padding_top_ = other.padding_top_;
	display_ = other.display_;
	background_ = unique_ptr<Colour>(other.background_->clone());
	border_colour_ = unique_ptr<Colour>(other.border_colour_->clone());
	border_style_ = other.border_style_;
	padding_colour_ = unique_ptr<Colour>(other.padding_colour_->clone());
	
} 


bool XmlBasicNodeAttributes::accept(const string& node)
{	
	
	if ( magCompare(node, "view")  )
		return true;
	
	return false;
}

void XmlBasicNodeAttributes::set(const XmlNode& node)
{
	bool apply = false;

	if ( this->accept(node.name()) == false ) 
		return;

	if ( magCompare(node.name(), "view")  )
		apply = true;
	

	if ( apply )
		set(node.attributes());
	else {
		
	}
	for (auto &elt : node.elements())
	{
		
	}
}

void XmlBasicNodeAttributes::print(ostream& out)  const
{
	out << "Attributes[";
	out << " standalone = " <<  standalone_;
	out << " standalone_path = " <<  standalone_path_;
	out << " standalone_format = " <<  standalone_format_;
	out << " standalone_width = " <<  standalone_width_;
	out << " standalone_height = " <<  standalone_height_;
	out << " bottom = " <<  bottom_;
	out << " left = " <<  left_;
	out << " width = " <<  width_;
	out << " height = " <<  height_;
	out << " margin_bottom = " <<  margin_bottom_;
	out << " margin_left = " <<  margin_left_;
	out << " margin_right = " <<  margin_right_;
	out << " margin_top = " <<  margin_top_;
	out << " border_bottom = " <<  border_bottom_;
	out << " border_left = " <<  border_left_;
	out << " border_right = " <<  border_right_;
	out << " border_top = " <<  border_top_;
	out << " border = " <<  border_;
	out << " blanking = " <<  blanking_;
	out << " border_thickness = " <<  border_thickness_;
	out << " padding_bottom = " <<  padding_bottom_;
	out << " padding_left = " <<  padding_left_;
	out << " padding_right = " <<  padding_right_;
	out << " padding_top = " <<  padding_top_;
	out << " display = " <<  display_;
	out << " background = " <<  *background_;
	out << " border_colour = " <<  *border_colour_;
	out << " border_style = " <<  border_style_;
	out << " padding_colour = " <<  *padding_colour_;
	
	out << "]" << "\n";
}

void XmlBasicNodeAttributes::toxml(ostream& out)  const
{
	out <<  "\"view\""; 
	out << ", \"view_standalone\":";
	niceprint(out,standalone_);
	out << ", \"view_standalone_file_name\":";
	niceprint(out,standalone_path_);
	out << ", \"view_standalone_format\":";
	niceprint(out,standalone_format_);
	out << ", \"view_standalone_width\":";
	niceprint(out,standalone_width_);
	out << ", \"view_standalone_height\":";
	niceprint(out,standalone_height_);
	out << ", \"view_bottom\":";
	niceprint(out,bottom_);
	out << ", \"view_left\":";
	niceprint(out,left_);
	out << ", \"view_width\":";
	niceprint(out,width_);
	out << ", \"view_height\":";
	niceprint(out,height_);
	out << ", \"view_margin_bottom\":";
	niceprint(out,margin_bottom_);
	out << ", \"view_margin_left\":";
	niceprint(out,margin_left_);
	out << ", \"view_margin_right\":";
	niceprint(out,margin_right_);
	out << ", \"view_margin_top\":";
	niceprint(out,margin_top_);
	out << ", \"view_border_bottom\":";
	niceprint(out,border_bottom_);
	out << ", \"view_border_left\":";
	niceprint(out,border_left_);
	out << ", \"view_border_right\":";
	niceprint(out,border_right_);
	out << ", \"view_border_top\":";
	niceprint(out,border_top_);
	out << ", \"view_border\":";
	niceprint(out,border_);
	out << ", \"view_blanking\":";
	niceprint(out,blanking_);
	out << ", \"view_border_thickness\":";
	niceprint(out,border_thickness_);
	out << ", \"view_padding_bottom\":";
	niceprint(out,padding_bottom_);
	out << ", \"view_padding_left\":";
	niceprint(out,padding_left_);
	out << ", \"view_padding_right\":";
	niceprint(out,padding_right_);
	out << ", \"view_padding_top\":";
	niceprint(out,padding_top_);
	out << ", \"view_display\":";
	niceprint(out, display_);
	out << ", \"view_background_colour\":";
	niceprint(out, *background_);
	out << ", \"view_border_colour\":";
	niceprint(out, *border_colour_);
	out << ", \"view_border_style\":";
	niceprint(out, border_style_);
	out << ", \"view_padding_colour\":";
	niceprint(out, *padding_colour_);
	
}

static MagicsParameter<string> view_standalone("view_standalone", "off", "");
static MagicsParameter<string> view_standalone_file_name("view_standalone_file_name", "", "");
static MagicsParameter<string> view_standalone_format("view_standalone_format", "png", "");
static MagicsParameter<double> view_standalone_width("view_standalone_width", 128, "");
static MagicsParameter<double> view_standalone_height("view_standalone_height", 64, "");
static MagicsParameter<string> view_bottom("view_bottom", "0%", "");
static MagicsParameter<string> view_left("view_left", "0%", "");
static MagicsParameter<string> view_width("view_width", "100%", "");
static MagicsParameter<string> view_height("view_height", "100%", "");
static MagicsParameter<string> view_margin_bottom("view_margin_bottom", "undef", "");
static MagicsParameter<string> view_margin_left("view_margin_left", "undef", "");
static MagicsParameter<string> view_margin_right("view_margin_right", "undef", "");
static MagicsParameter<string> view_margin_top("view_margin_top", "undef", "");
static MagicsParameter<string> view_border_bottom("view_border_bottom", "1px", "");
static MagicsParameter<string> view_border_left("view_border_left", "1px", "");
static MagicsParameter<string> view_border_right("view_border_right", "1px", "");
static MagicsParameter<string> view_border_top("view_border_top", "1px", "");
static MagicsParameter<string> view_border("view_border", "on", "");
static MagicsParameter<string> view_blanking("view_blanking", "on", "");
static MagicsParameter<int> view_border_thickness("view_border_thickness", 1, "");
static MagicsParameter<string> view_padding_bottom("view_padding_bottom", "0%", "");
static MagicsParameter<string> view_padding_left("view_padding_left", "0%", "");
static MagicsParameter<string> view_padding_right("view_padding_right", "0%", "");
static MagicsParameter<string> view_padding_top("view_padding_top", "0%", "");
static MagicsParameter<string> view_display("view_display", "inline", ""); 
static MagicsParameter<string> view_background_colour("view_background_colour", "none", ""); 
static MagicsParameter<string> view_border_colour("view_border_colour", "tan", ""); 
static MagicsParameter<string> view_border_style("view_border_style", "solid", ""); 
static MagicsParameter<string> view_padding_colour("view_padding_colour", "none", ""); 

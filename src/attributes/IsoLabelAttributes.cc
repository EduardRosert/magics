
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file IsoLabelAttributes.h
    \\brief Definition of IsoLabel Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 2020-09-22
*/

#include "IsoLabelAttributes.h"
#include "MagicsParameter.h"
#include "ParameterSettings.h"

using namespace magics;

IsoLabelAttributes::IsoLabelAttributes():
	type_(ParameterManager::getString("contour_label_type")),
	text_(ParameterManager::getString("contour_label_text")),
	height_(ParameterManager::getDouble("contour_label_height")),
	format_(ParameterManager::getString("contour_label_format")),
	blanking_(ParameterManager::getBool("contour_label_blanking")),
	font_(ParameterManager::getString("contour_label_font")),
	style_(ParameterManager::getString("contour_label_font_style")),
	colour_(ParameterManager::getString("contour_label_colour")),
	frequency_(ParameterManager::getInt("contour_label_frequency"))
	
	 
{
} 


IsoLabelAttributes::~IsoLabelAttributes()
{
	
}

    
void IsoLabelAttributes::set(const std::map<string, string>& params)
{
	vector<string> prefix(3);
	int i = 0;
	prefix[i++] = "contour";
	prefix[i++] = "contour";
	prefix[i++] = "contour_label";
	
	setAttribute(prefix, "contour_label_type", type_, params);
	setAttribute(prefix, "contour_label_text", text_, params);
	setAttribute(prefix, "contour_label_height", height_, params);
	setAttribute(prefix, "contour_label_format", format_, params);
	setAttribute(prefix, "contour_label_blanking", blanking_, params);
	setAttribute(prefix, "contour_label_font", font_, params);
	setAttribute(prefix, "contour_label_font_style", style_, params);
	setAttribute(prefix, "contour_label_colour", colour_, params);
	setAttribute(prefix, "contour_label_frequency", frequency_, params);
	
	
}

void IsoLabelAttributes::copy(const IsoLabelAttributes& other)
{
	type_ = other.type_;
	text_ = other.text_;
	height_ = other.height_;
	format_ = other.format_;
	blanking_ = other.blanking_;
	font_ = other.font_;
	style_ = other.style_;
	colour_ = other.colour_;
	frequency_ = other.frequency_;
	
} 


bool IsoLabelAttributes::accept(const string& node)
{	
	
	if ( magCompare(node, "label")  )
		return true;
	
	return false;
}

void IsoLabelAttributes::set(const XmlNode& node)
{
	bool apply = false;

	if ( this->accept(node.name()) == false ) 
		return;

	if ( magCompare(node.name(), "label")  )
		apply = true;
	

	if ( apply )
		set(node.attributes());
	else {
		
	}
	for (auto &elt : node.elements())
	{
		
	}
}

void IsoLabelAttributes::print(ostream& out)  const
{
	out << "Attributes[";
	out << " type = " <<  type_;
	out << " text = " <<  text_;
	out << " height = " <<  height_;
	out << " format = " <<  format_;
	out << " blanking = " <<  blanking_;
	out << " font = " <<  font_;
	out << " style = " <<  style_;
	out << " colour = " <<  colour_;
	out << " frequency = " <<  frequency_;
	
	out << "]" << "\n";
}

void IsoLabelAttributes::toxml(ostream& out)  const
{
	out <<  "\"label\""; 
	out << ", \"contour_label_type\":";
	niceprint(out,type_);
	out << ", \"contour_label_text\":";
	niceprint(out,text_);
	out << ", \"contour_label_height\":";
	niceprint(out,height_);
	out << ", \"contour_label_format\":";
	niceprint(out,format_);
	out << ", \"contour_label_blanking\":";
	niceprint(out,blanking_);
	out << ", \"contour_label_font\":";
	niceprint(out,font_);
	out << ", \"contour_label_font_style\":";
	niceprint(out,style_);
	out << ", \"contour_label_colour\":";
	niceprint(out,colour_);
	out << ", \"contour_label_frequency\":";
	niceprint(out,frequency_);
	
}

static MagicsParameter<string> contour_label_type("contour_label_type", "number", "");
static MagicsParameter<string> contour_label_text("contour_label_text", "", "");
static MagicsParameter<double> contour_label_height("contour_label_height", 0.3, "");
static MagicsParameter<string> contour_label_format("contour_label_format", "(automatic)", "");
static MagicsParameter<string> contour_label_blanking("contour_label_blanking", "on", "");
static MagicsParameter<string> contour_label_font("contour_label_font", "sansserif", "");
static MagicsParameter<string> contour_label_font_style("contour_label_font_style", "normal", "");
static MagicsParameter<string> contour_label_colour("contour_label_colour", "contour_line_colour", "");
static MagicsParameter<int> contour_label_frequency("contour_label_frequency", 2, "");


/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file EfiGraphAttributes.h
    \\brief Definition of EfiGraph Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 2020-10-14
*/

#include "EfiGraphAttributes.h"
#include "MagicsParameter.h"
#include "ParameterSettings.h"

using namespace magics;

EfiGraphAttributes::EfiGraphAttributes():
	box_colour_(ParameterManager::getStringArray("efi_box_colour_array")),
	border_thickness_(ParameterManager::getInt("efi_box_border_thickness")),
	normal_thickness_(ParameterManager::getInt("efi_normal_thickness")),
	font_(ParameterManager::getString("efi_font")),
	font_size_(ParameterManager::getDouble("efi_font_size")),
	font_style_(ParameterManager::getString("efi_font_style"))
	,
	border_colour_(MagTranslator<string, Colour>().magics("efi_box_border_colour")),
	border_style_(MagTranslator<string, LineStyle>().magics("efi_box_border_line_style")),
	normal_colour_(MagTranslator<string, Colour>().magics("efi_normal_colour")),
	normal_style_(MagTranslator<string, LineStyle>().magics("efi_normal_line_style")),
	font_colour_(MagTranslator<string, Colour>().magics("efi_font_colour"))
	 
{
} 


EfiGraphAttributes::~EfiGraphAttributes()
{
	
}

    
void EfiGraphAttributes::set(const std::map<string, string>& params)
{
	vector<string> prefix(1);
	int i = 0;
	prefix[i++] = "efi";
	
	setAttribute(prefix, "efi_box_colour_array", box_colour_, params);
	setAttribute(prefix, "efi_box_border_thickness", border_thickness_, params);
	setAttribute(prefix, "efi_normal_thickness", normal_thickness_, params);
	setAttribute(prefix, "efi_font", font_, params);
	setAttribute(prefix, "efi_font_size", font_size_, params);
	setAttribute(prefix, "efi_font_style", font_style_, params);
	
	setMember(prefix, "efi_box_border_colour", border_colour_, params);
	setAttribute(prefix, "efi_box_border_line_style", border_style_, params);
	setMember(prefix, "efi_normal_colour", normal_colour_, params);
	setAttribute(prefix, "efi_normal_line_style", normal_style_, params);
	setMember(prefix, "efi_font_colour", font_colour_, params);
	
}

void EfiGraphAttributes::copy(const EfiGraphAttributes& other)
{
	box_colour_ = other.box_colour_;
	border_thickness_ = other.border_thickness_;
	normal_thickness_ = other.normal_thickness_;
	font_ = other.font_;
	font_size_ = other.font_size_;
	font_style_ = other.font_style_;
	border_colour_ = unique_ptr<Colour>(other.border_colour_->clone());
	border_style_ = other.border_style_;
	normal_colour_ = unique_ptr<Colour>(other.normal_colour_->clone());
	normal_style_ = other.normal_style_;
	font_colour_ = unique_ptr<Colour>(other.font_colour_->clone());
	
} 


bool EfiGraphAttributes::accept(const string& node)
{	
	
	if ( magCompare(node, "efigraph")  )
		return true;
	
	return false;
}

void EfiGraphAttributes::set(const XmlNode& node)
{
	bool apply = false;

	if ( this->accept(node.name()) == false ) 
		return;

	if ( magCompare(node.name(), "efigraph")  )
		apply = true;
	

	if ( apply )
		set(node.attributes());
	else {
		
	}
	for (auto &elt : node.elements())
	{
		
	}
}

void EfiGraphAttributes::print(ostream& out)  const
{
	out << "Attributes[";
	out << " box_colour = " <<  box_colour_;
	out << " border_thickness = " <<  border_thickness_;
	out << " normal_thickness = " <<  normal_thickness_;
	out << " font = " <<  font_;
	out << " font_size = " <<  font_size_;
	out << " font_style = " <<  font_style_;
	out << " border_colour = " <<  *border_colour_;
	out << " border_style = " <<  border_style_;
	out << " normal_colour = " <<  *normal_colour_;
	out << " normal_style = " <<  normal_style_;
	out << " font_colour = " <<  *font_colour_;
	
	out << "]" << "\n";
}

void EfiGraphAttributes::toxml(ostream& out)  const
{
	out <<  "\"efigraph\""; 
	out << ", \"efi_box_colour_array\":";
	niceprint(out,box_colour_);
	out << ", \"efi_box_border_thickness\":";
	niceprint(out,border_thickness_);
	out << ", \"efi_normal_thickness\":";
	niceprint(out,normal_thickness_);
	out << ", \"efi_font\":";
	niceprint(out,font_);
	out << ", \"efi_font_size\":";
	niceprint(out,font_size_);
	out << ", \"efi_font_style\":";
	niceprint(out,font_style_);
	out << ", \"efi_box_border_colour\":";
	niceprint(out, *border_colour_);
	out << ", \"efi_box_border_line_style\":";
	niceprint(out, border_style_);
	out << ", \"efi_normal_colour\":";
	niceprint(out, *normal_colour_);
	out << ", \"efi_normal_line_style\":";
	niceprint(out, normal_style_);
	out << ", \"efi_font_colour\":";
	niceprint(out, *font_colour_);
	
}

static MagicsParameter<stringarray> efi_box_colour_array("efi_box_colour_array", stringarray(), "");
static MagicsParameter<int> efi_box_border_thickness("efi_box_border_thickness", 1, "");
static MagicsParameter<int> efi_normal_thickness("efi_normal_thickness", 4, "");
static MagicsParameter<string> efi_font("efi_font", "sansserif", "");
static MagicsParameter<double> efi_font_size("efi_font_size", 0.25, "");
static MagicsParameter<string> efi_font_style("efi_font_style", "", "");
static MagicsParameter<string> efi_box_border_colour("efi_box_border_colour", "black", ""); 
static MagicsParameter<string> efi_box_border_line_style("efi_box_border_line_style", "solid", ""); 
static MagicsParameter<string> efi_normal_colour("efi_normal_colour", "black", ""); 
static MagicsParameter<string> efi_normal_line_style("efi_normal_line_style", "solid", ""); 
static MagicsParameter<string> efi_font_colour("efi_font_colour", "black", ""); 

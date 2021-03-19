
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file MagnifierVisitorAttributes.h
    \\brief Definition of MagnifierVisitor Attributes class.

    This file is automatically generated.
    Do Not Edit!
*/

#include "MagnifierVisitorAttributes.h"
#include "MagicsParameter.h"
#include "ParameterSettings.h"

using namespace magics;

MagnifierVisitorAttributes::MagnifierVisitorAttributes():
	symbol_name_(ParameterManager::getString("magnifier_symbol_name")),
	hidden_symbol_name_(ParameterManager::getString("magnifier_hidden_symbol_name")),
	symbol_height_(ParameterManager::getDouble("magnifier_symbol_height")),
	hidden_symbol_height_(ParameterManager::getDouble("magnifier_hidden_symbol_height")),
	text_font_name_(ParameterManager::getString("magnifier_text_font")),
	text_font_size_(ParameterManager::getDouble("magnifier_text_font_size")),
	text_format_(ParameterManager::getString("magnifier_text_format"))
	,
	symbol_colour_(MagTranslator<string, Colour>().magics("magnifier_symbol_colour")),
	hidden_symbol_colour_(MagTranslator<string, Colour>().magics("magnifier_hidden_symbol_colour")),
	text_font_colour_(MagTranslator<string, Colour>().magics("magnifier_text_font_colour"))
	
{
}


MagnifierVisitorAttributes::~MagnifierVisitorAttributes()
{

}


void MagnifierVisitorAttributes::set(const std::map<string, string>& params)
{
	vector<string> prefix(1);
	int i = 0;
	prefix[i++] = "";
	
	setAttribute(prefix, "magnifier_symbol_name", symbol_name_, params);
	setAttribute(prefix, "magnifier_hidden_symbol_name", hidden_symbol_name_, params);
	setAttribute(prefix, "magnifier_symbol_height", symbol_height_, params);
	setAttribute(prefix, "magnifier_hidden_symbol_height", hidden_symbol_height_, params);
	setAttribute(prefix, "magnifier_text_font", text_font_name_, params);
	setAttribute(prefix, "magnifier_text_font_size", text_font_size_, params);
	setAttribute(prefix, "magnifier_text_format", text_format_, params);
	
	setMember(prefix, "magnifier_symbol_colour", symbol_colour_, params);
	setMember(prefix, "magnifier_hidden_symbol_colour", hidden_symbol_colour_, params);
	setMember(prefix, "magnifier_text_font_colour", text_font_colour_, params);
	
}

void MagnifierVisitorAttributes::copy(const MagnifierVisitorAttributes& other)
{
	symbol_name_ = other.symbol_name_;
	hidden_symbol_name_ = other.hidden_symbol_name_;
	symbol_height_ = other.symbol_height_;
	hidden_symbol_height_ = other.hidden_symbol_height_;
	text_font_name_ = other.text_font_name_;
	text_font_size_ = other.text_font_size_;
	text_format_ = other.text_format_;
	symbol_colour_ = unique_ptr<Colour>(other.symbol_colour_->clone());
	hidden_symbol_colour_ = unique_ptr<Colour>(other.hidden_symbol_colour_->clone());
	text_font_colour_ = unique_ptr<Colour>(other.text_font_colour_->clone());
	
}


bool MagnifierVisitorAttributes::accept(const string& node)
{

	if ( magCompare(node, "")  )
		return true;
	
	return false;
}

void MagnifierVisitorAttributes::set(const XmlNode& node)
{
	bool apply = false;

	if ( this->accept(node.name()) == false )
		return;

	if ( magCompare(node.name(), "")  )
		apply = true;
	

	if ( apply )
		set(node.attributes());
	else {
		
	}
	for (auto &elt : node.elements())
	{
		
	}
}

void MagnifierVisitorAttributes::print(ostream& out)  const
{
	out << "Attributes[";
	out << " symbol_name = " <<  symbol_name_;
	out << " hidden_symbol_name = " <<  hidden_symbol_name_;
	out << " symbol_height = " <<  symbol_height_;
	out << " hidden_symbol_height = " <<  hidden_symbol_height_;
	out << " text_font_name = " <<  text_font_name_;
	out << " text_font_size = " <<  text_font_size_;
	out << " text_format = " <<  text_format_;
	out << " symbol_colour = " <<  *symbol_colour_;
	out << " hidden_symbol_colour = " <<  *hidden_symbol_colour_;
	out << " text_font_colour = " <<  *text_font_colour_;
	
	out << "]" << "\n";
}

void MagnifierVisitorAttributes::toxml(ostream& out)  const
{
	out <<  "\"\"";
	out << ", \"magnifier_symbol_name\":";
	niceprint(out,symbol_name_);
	out << ", \"magnifier_hidden_symbol_name\":";
	niceprint(out,hidden_symbol_name_);
	out << ", \"magnifier_symbol_height\":";
	niceprint(out,symbol_height_);
	out << ", \"magnifier_hidden_symbol_height\":";
	niceprint(out,hidden_symbol_height_);
	out << ", \"magnifier_text_font\":";
	niceprint(out,text_font_name_);
	out << ", \"magnifier_text_font_size\":";
	niceprint(out,text_font_size_);
	out << ", \"magnifier_text_format\":";
	niceprint(out,text_format_);
	out << ", \"magnifier_symbol_colour\":";
	niceprint(out, *symbol_colour_);
	out << ", \"magnifier_hidden_symbol_colour\":";
	niceprint(out, *hidden_symbol_colour_);
	out << ", \"magnifier_text_font_colour\":";
	niceprint(out, *text_font_colour_);
	
}

static MagicsParameter<string> magnifier_symbol_name("magnifier_symbol_name", "magics_3");
static MagicsParameter<string> magnifier_hidden_symbol_name("magnifier_hidden_symbol_name", "magics_3");
static MagicsParameter<double> magnifier_symbol_height("magnifier_symbol_height", 0.2);
static MagicsParameter<double> magnifier_hidden_symbol_height("magnifier_hidden_symbol_height", 0.1);
static MagicsParameter<string> magnifier_text_font("magnifier_text_font", "sanserif");
static MagicsParameter<double> magnifier_text_font_size("magnifier_text_font_size", 0.2);
static MagicsParameter<string> magnifier_text_format("magnifier_text_format", "(automatic)");
static MagicsParameter<string> magnifier_symbol_colour("magnifier_symbol_colour", "red");
static MagicsParameter<string> magnifier_hidden_symbol_colour("magnifier_hidden_symbol_colour", "navy");
static MagicsParameter<string> magnifier_text_font_colour("magnifier_text_font_colour", "navy");

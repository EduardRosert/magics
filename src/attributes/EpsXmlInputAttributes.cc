
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file EpsXmlInputAttributes.h
    \\brief Definition of EpsXmlInput Attributes class.

    This file is automatically generated.
    Do Not Edit!
*/

#include "EpsXmlInputAttributes.h"
#include "MagicsParameter.h"
#include "ParameterSettings.h"

using namespace magics;

EpsXmlInputAttributes::EpsXmlInputAttributes():
	path_(ParameterManager::getString("epsxml_input_filename")),
	param_(ParameterManager::getString("epsxml_parameter")),
	long_title_(ParameterManager::getBool("epsxml_long_title")),
	short_title_(ParameterManager::getBool("epsxml_title"))
	
	 
{
} 


EpsXmlInputAttributes::~EpsXmlInputAttributes()
{
	
}

    
void EpsXmlInputAttributes::set(const std::map<string, string>& params)
{
	vector<string> prefix(1);
	int i = 0;
	prefix[i++] = "epsxml";
	
	setAttribute(prefix, "epsxml_input_filename", path_, params);
	setAttribute(prefix, "epsxml_parameter", param_, params);
	setAttribute(prefix, "epsxml_long_title", long_title_, params);
	setAttribute(prefix, "epsxml_title", short_title_, params);
	
	
}

void EpsXmlInputAttributes::copy(const EpsXmlInputAttributes& other)
{
	path_ = other.path_;
	param_ = other.param_;
	long_title_ = other.long_title_;
	short_title_ = other.short_title_;
	
} 


bool EpsXmlInputAttributes::accept(const string& node)
{	
	
	if ( magCompare(node, "epsxml")  )
		return true;
	
	return false;
}

void EpsXmlInputAttributes::set(const XmlNode& node)
{
	bool apply = false;

	if ( this->accept(node.name()) == false ) 
		return;

	if ( magCompare(node.name(), "epsxml")  )
		apply = true;
	

	if ( apply )
		set(node.attributes());
	else {
		
	}
	for (auto &elt : node.elements())
	{
		
	}
}

void EpsXmlInputAttributes::print(ostream& out)  const
{
	out << "Attributes[";
	out << " path = " <<  path_;
	out << " param = " <<  param_;
	out << " long_title = " <<  long_title_;
	out << " short_title = " <<  short_title_;
	
	out << "]" << "\n";
}

void EpsXmlInputAttributes::toxml(ostream& out)  const
{
	out <<  "\"epsxml\""; 
	out << ", \"epsxml_input_filename\":";
	niceprint(out,path_);
	out << ", \"epsxml_parameter\":";
	niceprint(out,param_);
	out << ", \"epsxml_long_title\":";
	niceprint(out,long_title_);
	out << ", \"epsxml_title\":";
	niceprint(out,short_title_);
	
}

static MagicsParameter<string> epsxml_input_filename("epsxml_input_filename", "", "");
static MagicsParameter<string> epsxml_parameter("epsxml_parameter", "", "");
static MagicsParameter<string> epsxml_long_title("epsxml_long_title", "off", "");
static MagicsParameter<string> epsxml_title("epsxml_title", "on", "");

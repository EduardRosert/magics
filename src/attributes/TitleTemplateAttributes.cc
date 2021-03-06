
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file TitleTemplateAttributes.h
    \\brief Definition of TitleTemplate Attributes class.

    This file is automatically generated.
    Do Not Edit!
*/

#include "TitleTemplateAttributes.h"
#include "MagicsParameter.h"
#include "ParameterSettings.h"

using namespace magics;

TitleTemplateAttributes::TitleTemplateAttributes():
	file_(ParameterManager::getString("title_template_filename"))
	
	
{
}


TitleTemplateAttributes::~TitleTemplateAttributes()
{

}


void TitleTemplateAttributes::set(const std::map<string, string>& params)
{
	vector<string> prefix(1);
	int i = 0;
	prefix[i++] = "";
	
	setAttribute(prefix, "title_template_filename", file_, params);
	
	
}

void TitleTemplateAttributes::copy(const TitleTemplateAttributes& other)
{
	file_ = other.file_;
	
}


bool TitleTemplateAttributes::accept(const string& node)
{

	if ( magCompare(node, "")  )
		return true;
	
	return false;
}

void TitleTemplateAttributes::set(const XmlNode& node)
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

void TitleTemplateAttributes::print(ostream& out)  const
{
	out << "Attributes[";
	out << " file = " <<  file_;
	
	out << "]" << "\n";
}

void TitleTemplateAttributes::toxml(ostream& out)  const
{
	out <<  "\"\"";
	out << ", \"title_template_filename\":";
	niceprint(out,file_);
	
}

static MagicsParameter<string> title_template_filename("title_template_filename", "title_template.xml");

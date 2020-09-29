
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file GraphFlagAttributes.h
    \\brief Definition of GraphFlag Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 2020-09-24
*/

#include "GraphFlagAttributes.h"
#include "MagicsParameter.h"
#include "ParameterSettings.h"

using namespace magics;

GraphFlagAttributes::GraphFlagAttributes():
	length_(ParameterManager::getDouble("graph_flag_length"))
	,
	colour_(MagTranslator<string, Colour>().magics("graph_flag_colour"))
	 
{
} 


GraphFlagAttributes::~GraphFlagAttributes()
{
	
}

    
void GraphFlagAttributes::set(const std::map<string, string>& params)
{
	vector<string> prefix(1);
	int i = 0;
	prefix[i++] = "";
	
	setAttribute(prefix, "graph_flag_length", length_, params);
	
	setMember(prefix, "graph_flag_colour", colour_, params);
	
}

void GraphFlagAttributes::copy(const GraphFlagAttributes& other)
{
	length_ = other.length_;
	colour_ = unique_ptr<Colour>(other.colour_->clone());
	
} 


bool GraphFlagAttributes::accept(const string& node)
{	
	
	if ( magCompare(node, "flag")  )
		return true;
	
	return false;
}

void GraphFlagAttributes::set(const XmlNode& node)
{
	bool apply = false;

	if ( this->accept(node.name()) == false ) 
		return;

	if ( magCompare(node.name(), "flag")  )
		apply = true;
	

	if ( apply )
		set(node.attributes());
	else {
		
	}
	for (auto &elt : node.elements())
	{
		
	}
}

void GraphFlagAttributes::print(ostream& out)  const
{
	out << "Attributes[";
	out << " length = " <<  length_;
	out << " colour = " <<  *colour_;
	
	out << "]" << "\n";
}

void GraphFlagAttributes::toxml(ostream& out)  const
{
	out <<  "\"flag\""; 
	out << ", \"graph_flag_length\":";
	niceprint(out,length_);
	out << ", \"graph_flag_colour\":";
	niceprint(out, *colour_);
	
}

static MagicsParameter<double> graph_flag_length("graph_flag_length", 0.75, "");
static MagicsParameter<string> graph_flag_colour("graph_flag_colour", "black", ""); 

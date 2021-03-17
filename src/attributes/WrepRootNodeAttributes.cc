
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file WrepRootNodeAttributes.h
    \\brief Definition of WrepRootNode Attributes class.

    This file is automatically generated.
    Do Not Edit!
*/

#include "WrepRootNodeAttributes.h"
#include "MagicsParameter.h"
#include "ParameterSettings.h"

using namespace magics;

WrepRootNodeAttributes::WrepRootNodeAttributes():
	pixel_width_(ParameterManager::getDouble("wrep_node_width")),
	pixel_height_(ParameterManager::getDouble("wrep_node_height")),
	anchor_(ParameterManager::getString("wrep_node_mapping_anchor"))
	
	
{
}


WrepRootNodeAttributes::~WrepRootNodeAttributes()
{

}


void WrepRootNodeAttributes::set(const std::map<string, string>& params)
{
	vector<string> prefix(1);
	int i = 0;
	prefix[i++] = "wrep_node";
	
	setAttribute(prefix, "wrep_node_width", pixel_width_, params);
	setAttribute(prefix, "wrep_node_height", pixel_height_, params);
	setAttribute(prefix, "wrep_node_mapping_anchor", anchor_, params);
	
	
}

void WrepRootNodeAttributes::copy(const WrepRootNodeAttributes& other)
{
	pixel_width_ = other.pixel_width_;
	pixel_height_ = other.pixel_height_;
	anchor_ = other.anchor_;
	
}


bool WrepRootNodeAttributes::accept(const string& node)
{

	if ( magCompare(node, "magics")  )
		return true;
	
	return false;
}

void WrepRootNodeAttributes::set(const XmlNode& node)
{
	bool apply = false;

	if ( this->accept(node.name()) == false )
		return;

	if ( magCompare(node.name(), "magics")  )
		apply = true;
	

	if ( apply )
		set(node.attributes());
	else {
		
	}
	for (auto &elt : node.elements())
	{
		
	}
}

void WrepRootNodeAttributes::print(ostream& out)  const
{
	out << "Attributes[";
	out << " pixel_width = " <<  pixel_width_;
	out << " pixel_height = " <<  pixel_height_;
	out << " anchor = " <<  anchor_;
	
	out << "]" << "\n";
}

void WrepRootNodeAttributes::toxml(ostream& out)  const
{
	out <<  "\"magics\"";
	out << ", \"wrep_node_width\":";
	niceprint(out,pixel_width_);
	out << ", \"wrep_node_height\":";
	niceprint(out,pixel_height_);
	out << ", \"wrep_node_mapping_anchor\":";
	niceprint(out,anchor_);
	
}

static MagicsParameter<double> wrep_node_width("wrep_node_width", 800);
static MagicsParameter<double> wrep_node_height("wrep_node_height", 400);
static MagicsParameter<string> wrep_node_mapping_anchor("wrep_node_mapping_anchor", "centre");

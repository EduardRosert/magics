
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file XmlRootNodeAttributes.h
    \\brief Definition of XmlRootNode Attributes class.

    This file is automatically generated.
    Do Not Edit!
*/

#include "XmlRootNodeAttributes.h"
#include "MagicsParameter.h"
#include "ParameterSettings.h"

using namespace magics;

XmlRootNodeAttributes::XmlRootNodeAttributes():
	format_(ParameterManager::getString("root_node_format")),
	orientation_(ParameterManager::getString("root_node_orientation")),
	width_(ParameterManager::getDouble("root_node_width")),
	height_(ParameterManager::getDouble("root_node_height")),
	border_(ParameterManager::getBool("root_node_frame")),
	border_thickness_(ParameterManager::getInt("root_node_frame_thickness")),
	application_(ParameterManager::getString("root_node_application"))
	,
	border_colour_(MagTranslator<string, Colour>().magics("root_node_frame_colour")),
	border_style_(MagTranslator<string, LineStyle>().magics("root_node_frame_line_style"))
	
{
}


XmlRootNodeAttributes::~XmlRootNodeAttributes()
{

}


void XmlRootNodeAttributes::set(const std::map<string, string>& params)
{
	vector<string> prefix(1);
	int i = 0;
	prefix[i++] = "root_node";
	
	setAttribute(prefix, "root_node_format", format_, params);
	setAttribute(prefix, "root_node_orientation", orientation_, params);
	setAttribute(prefix, "root_node_width", width_, params);
	setAttribute(prefix, "root_node_height", height_, params);
	setAttribute(prefix, "root_node_frame", border_, params);
	setAttribute(prefix, "root_node_frame_thickness", border_thickness_, params);
	setAttribute(prefix, "root_node_application", application_, params);
	
	setMember(prefix, "root_node_frame_colour", border_colour_, params);
	setAttribute(prefix, "root_node_frame_line_style", border_style_, params);
	
}

void XmlRootNodeAttributes::copy(const XmlRootNodeAttributes& other)
{
	format_ = other.format_;
	orientation_ = other.orientation_;
	width_ = other.width_;
	height_ = other.height_;
	border_ = other.border_;
	border_thickness_ = other.border_thickness_;
	application_ = other.application_;
	border_colour_ = unique_ptr<Colour>(other.border_colour_->clone());
	border_style_ = other.border_style_;
	
}


bool XmlRootNodeAttributes::accept(const string& node)
{

	if ( magCompare(node, "magics")  )
		return true;
	
	return false;
}

void XmlRootNodeAttributes::set(const XmlNode& node)
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

void XmlRootNodeAttributes::print(ostream& out)  const
{
	out << "Attributes[";
	out << " format = " <<  format_;
	out << " orientation = " <<  orientation_;
	out << " width = " <<  width_;
	out << " height = " <<  height_;
	out << " border = " <<  border_;
	out << " border_thickness = " <<  border_thickness_;
	out << " application = " <<  application_;
	out << " border_colour = " <<  *border_colour_;
	out << " border_style = " <<  border_style_;
	
	out << "]" << "\n";
}

void XmlRootNodeAttributes::toxml(ostream& out)  const
{
	out <<  "\"magics\"";
	out << ", \"root_node_format\":";
	niceprint(out,format_);
	out << ", \"root_node_orientation\":";
	niceprint(out,orientation_);
	out << ", \"root_node_width\":";
	niceprint(out,width_);
	out << ", \"root_node_height\":";
	niceprint(out,height_);
	out << ", \"root_node_frame\":";
	niceprint(out,border_);
	out << ", \"root_node_frame_thickness\":";
	niceprint(out,border_thickness_);
	out << ", \"root_node_application\":";
	niceprint(out,application_);
	out << ", \"root_node_frame_colour\":";
	niceprint(out, *border_colour_);
	out << ", \"root_node_frame_line_style\":";
	niceprint(out, border_style_);
	
}

static MagicsParameter<string> root_node_format("root_node_format", "a4");
static MagicsParameter<string> root_node_orientation("root_node_orientation", "landscape");
static MagicsParameter<double> root_node_width("root_node_width", -1);
static MagicsParameter<double> root_node_height("root_node_height", -1);
static MagicsParameter<string> root_node_frame("root_node_frame", "off");
static MagicsParameter<int> root_node_frame_thickness("root_node_frame_thickness", 1);
static MagicsParameter<string> root_node_application("root_node_application", "magml");
static MagicsParameter<string> root_node_frame_colour("root_node_frame_colour", "blue");
static MagicsParameter<string> root_node_frame_line_style("root_node_frame_line_style", "solid");

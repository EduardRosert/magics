
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file StreamlinesAttributes.h
    \\brief Definition of Streamlines Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 2020-09-22
*/

#include "StreamlinesAttributes.h"
#include "MagicsParameter.h"
#include "ParameterSettings.h"

using namespace magics;

StreamlinesAttributes::StreamlinesAttributes():
	min_density_(ParameterManager::getDouble("wind_streamline_min_density")),
	min_speed_(ParameterManager::getDouble("wind_streamline_min_speed")),
	thickness_(ParameterManager::getInt("wind_streamline_thickness")),
	head_(ParameterManager::getInt("wind_streamline_head_shape")),
	ratio_(ParameterManager::getDouble("wind_streamline_head_ratio"))
	,
	colour_(MagTranslator<string, Colour>().magics("wind_streamline_colour")),
	style_(MagTranslator<string, LineStyle>().magics("wind_streamline_style"))
	 
{
} 


StreamlinesAttributes::~StreamlinesAttributes()
{
	
}

    
void StreamlinesAttributes::set(const std::map<string, string>& params)
{
	vector<string> prefix(2);
	int i = 0;
	prefix[i++] = "wind";
	prefix[i++] = "wind_streamlines";
	
	setAttribute(prefix, "wind_streamline_min_density", min_density_, params);
	setAttribute(prefix, "wind_streamline_min_speed", min_speed_, params);
	setAttribute(prefix, "wind_streamline_thickness", thickness_, params);
	setAttribute(prefix, "wind_streamline_head_shape", head_, params);
	setAttribute(prefix, "wind_streamline_head_ratio", ratio_, params);
	
	setMember(prefix, "wind_streamline_colour", colour_, params);
	setAttribute(prefix, "wind_streamline_style", style_, params);
	
}

void StreamlinesAttributes::copy(const StreamlinesAttributes& other)
{
	min_density_ = other.min_density_;
	min_speed_ = other.min_speed_;
	thickness_ = other.thickness_;
	head_ = other.head_;
	ratio_ = other.ratio_;
	colour_ = unique_ptr<Colour>(other.colour_->clone());
	style_ = other.style_;
	
} 


bool StreamlinesAttributes::accept(const string& node)
{	
	
	if ( magCompare(node, "")  )
		return true;
	
	return false;
}

void StreamlinesAttributes::set(const XmlNode& node)
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

void StreamlinesAttributes::print(ostream& out)  const
{
	out << "Attributes[";
	out << " min_density = " <<  min_density_;
	out << " min_speed = " <<  min_speed_;
	out << " thickness = " <<  thickness_;
	out << " head = " <<  head_;
	out << " ratio = " <<  ratio_;
	out << " colour = " <<  *colour_;
	out << " style = " <<  style_;
	
	out << "]" << "\n";
}

void StreamlinesAttributes::toxml(ostream& out)  const
{
	out <<  "\"\""; 
	out << ", \"wind_streamline_min_density\":";
	niceprint(out,min_density_);
	out << ", \"wind_streamline_min_speed\":";
	niceprint(out,min_speed_);
	out << ", \"wind_streamline_thickness\":";
	niceprint(out,thickness_);
	out << ", \"wind_streamline_head_shape\":";
	niceprint(out,head_);
	out << ", \"wind_streamline_head_ratio\":";
	niceprint(out,ratio_);
	out << ", \"wind_streamline_colour\":";
	niceprint(out, *colour_);
	out << ", \"wind_streamline_style\":";
	niceprint(out, style_);
	
}

static MagicsParameter<double> wind_streamline_min_density("wind_streamline_min_density", 1, "");
static MagicsParameter<double> wind_streamline_min_speed("wind_streamline_min_speed", 1, "");
static MagicsParameter<int> wind_streamline_thickness("wind_streamline_thickness", 2, "");
static MagicsParameter<int> wind_streamline_head_shape("wind_streamline_head_shape", 1, "");
static MagicsParameter<double> wind_streamline_head_ratio("wind_streamline_head_ratio", 0.2, "");
static MagicsParameter<string> wind_streamline_colour("wind_streamline_colour", "blue", ""); 
static MagicsParameter<string> wind_streamline_style("wind_streamline_style", "solid", ""); 

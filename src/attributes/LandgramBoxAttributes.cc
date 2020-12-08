
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file LandgramBoxAttributes.h
    \\brief Definition of LandgramBox Attributes class.

    This file is automatically generated.
    Do Not Edit!
*/

#include "LandgramBoxAttributes.h"
#include "MagicsParameter.h"
#include "ParameterSettings.h"

using namespace magics;

LandgramBoxAttributes::LandgramBoxAttributes():
	width_(ParameterManager::getDouble("landgram_width")),
	top1_shading_(ParameterManager::getString("landgram_top_box1_shading")),
	top2_shading_(ParameterManager::getString("landgram_top_box2_shading")),
	bottom1_shading_(ParameterManager::getString("landgram_bottom_box1_shading")),
	bottom2_shading_(ParameterManager::getString("landgram_bottom_box2_shading"))
	,
	top1_colour_(MagTranslator<string, Colour>().magics("landgram_top_box1_colour")),
	top2_colour_(MagTranslator<string, Colour>().magics("landgram_top_box2_colour")),
	bottom1_colour_(MagTranslator<string, Colour>().magics("landgram_bottom_box1_colour")),
	bottom2_colour_(MagTranslator<string, Colour>().magics("landgram_bottom_box2_colour"))
	 
{
} 


LandgramBoxAttributes::~LandgramBoxAttributes()
{
	
}

    
void LandgramBoxAttributes::set(const std::map<string, string>& params)
{
	vector<string> prefix(1);
	int i = 0;
	prefix[i++] = "landbox";
	
	setAttribute(prefix, "landgram_width", width_, params);
	setAttribute(prefix, "landgram_top_box1_shading", top1_shading_, params);
	setAttribute(prefix, "landgram_top_box2_shading", top2_shading_, params);
	setAttribute(prefix, "landgram_bottom_box1_shading", bottom1_shading_, params);
	setAttribute(prefix, "landgram_bottom_box2_shading", bottom2_shading_, params);
	
	setMember(prefix, "landgram_top_box1_colour", top1_colour_, params);
	setMember(prefix, "landgram_top_box2_colour", top2_colour_, params);
	setMember(prefix, "landgram_bottom_box1_colour", bottom1_colour_, params);
	setMember(prefix, "landgram_bottom_box2_colour", bottom2_colour_, params);
	
}

void LandgramBoxAttributes::copy(const LandgramBoxAttributes& other)
{
	width_ = other.width_;
	top1_shading_ = other.top1_shading_;
	top2_shading_ = other.top2_shading_;
	bottom1_shading_ = other.bottom1_shading_;
	bottom2_shading_ = other.bottom2_shading_;
	top1_colour_ = unique_ptr<Colour>(other.top1_colour_->clone());
	top2_colour_ = unique_ptr<Colour>(other.top2_colour_->clone());
	bottom1_colour_ = unique_ptr<Colour>(other.bottom1_colour_->clone());
	bottom2_colour_ = unique_ptr<Colour>(other.bottom2_colour_->clone());
	
} 


bool LandgramBoxAttributes::accept(const string& node)
{	
	
	if ( magCompare(node, "landgrambox")  )
		return true;
	
	return false;
}

void LandgramBoxAttributes::set(const XmlNode& node)
{
	bool apply = false;

	if ( this->accept(node.name()) == false ) 
		return;

	if ( magCompare(node.name(), "landgrambox")  )
		apply = true;
	

	if ( apply )
		set(node.attributes());
	else {
		
	}
	for (auto &elt : node.elements())
	{
		
	}
}

void LandgramBoxAttributes::print(ostream& out)  const
{
	out << "Attributes[";
	out << " width = " <<  width_;
	out << " top1_shading = " <<  top1_shading_;
	out << " top2_shading = " <<  top2_shading_;
	out << " bottom1_shading = " <<  bottom1_shading_;
	out << " bottom2_shading = " <<  bottom2_shading_;
	out << " top1_colour = " <<  *top1_colour_;
	out << " top2_colour = " <<  *top2_colour_;
	out << " bottom1_colour = " <<  *bottom1_colour_;
	out << " bottom2_colour = " <<  *bottom2_colour_;
	
	out << "]" << "\n";
}

void LandgramBoxAttributes::toxml(ostream& out)  const
{
	out <<  "\"landgrambox\""; 
	out << ", \"landgram_width\":";
	niceprint(out,width_);
	out << ", \"landgram_top_box1_shading\":";
	niceprint(out,top1_shading_);
	out << ", \"landgram_top_box2_shading\":";
	niceprint(out,top2_shading_);
	out << ", \"landgram_bottom_box1_shading\":";
	niceprint(out,bottom1_shading_);
	out << ", \"landgram_bottom_box2_shading\":";
	niceprint(out,bottom2_shading_);
	out << ", \"landgram_top_box1_colour\":";
	niceprint(out, *top1_colour_);
	out << ", \"landgram_top_box2_colour\":";
	niceprint(out, *top2_colour_);
	out << ", \"landgram_bottom_box1_colour\":";
	niceprint(out, *bottom1_colour_);
	out << ", \"landgram_bottom_box2_colour\":";
	niceprint(out, *bottom2_colour_);
	
}

static MagicsParameter<double> landgram_width("landgram_width", 6, "");
static MagicsParameter<string> landgram_top_box1_shading("landgram_top_box1_shading", "solid", "");
static MagicsParameter<string> landgram_top_box2_shading("landgram_top_box2_shading", "dot", "");
static MagicsParameter<string> landgram_bottom_box1_shading("landgram_bottom_box1_shading", "solid", "");
static MagicsParameter<string> landgram_bottom_box2_shading("landgram_bottom_box2_shading", "dot", "");
static MagicsParameter<string> landgram_top_box1_colour("landgram_top_box1_colour", "evergreen", ""); 
static MagicsParameter<string> landgram_top_box2_colour("landgram_top_box2_colour", "evergreen", ""); 
static MagicsParameter<string> landgram_bottom_box1_colour("landgram_bottom_box1_colour", "evergreen", ""); 
static MagicsParameter<string> landgram_bottom_box2_colour("landgram_bottom_box2_colour", "evergreen", ""); 

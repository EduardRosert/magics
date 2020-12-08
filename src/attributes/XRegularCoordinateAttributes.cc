
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file XRegularCoordinateAttributes.h
    \\brief Definition of XRegularCoordinate Attributes class.

    This file is automatically generated.
    Do Not Edit!
*/

#include "XRegularCoordinateAttributes.h"
#include "MagicsParameter.h"
#include "ParameterSettings.h"

using namespace magics;

XRegularCoordinateAttributes::XRegularCoordinateAttributes():
	min_(ParameterManager::getDouble("subpage_x_min")),
	max_(ParameterManager::getDouble("subpage_x_max")),
	reverse_(ParameterManager::getBool("subpage_x_automatic_reverse"))
	,
	automatic_(MagTranslator<string, AxisAutomaticSetting>().magics("subpage_x_automatic"))
	 
{
} 


XRegularCoordinateAttributes::~XRegularCoordinateAttributes()
{
	
}

    
void XRegularCoordinateAttributes::set(const std::map<string, string>& params)
{
	vector<string> prefix(2);
	int i = 0;
	prefix[i++] = "subpage";
	prefix[i++] = "subpage_x";
	
	setAttribute(prefix, "subpage_x_min", min_, params);
	setAttribute(prefix, "subpage_x_max", max_, params);
	setAttribute(prefix, "subpage_x_automatic_reverse", reverse_, params);
	
	setAttribute(prefix, "subpage_x_automatic", automatic_, params);
	
}

void XRegularCoordinateAttributes::copy(const XRegularCoordinateAttributes& other)
{
	min_ = other.min_;
	max_ = other.max_;
	reverse_ = other.reverse_;
	automatic_ = other.automatic_;
	
} 


bool XRegularCoordinateAttributes::accept(const string& node)
{	
	
	if ( magCompare(node, "x_regular")  )
		return true;
	
	return false;
}

void XRegularCoordinateAttributes::set(const XmlNode& node)
{
	bool apply = false;

	if ( this->accept(node.name()) == false ) 
		return;

	if ( magCompare(node.name(), "x_regular")  )
		apply = true;
	

	if ( apply )
		set(node.attributes());
	else {
		
	}
	for (auto &elt : node.elements())
	{
		
	}
}

void XRegularCoordinateAttributes::print(ostream& out)  const
{
	out << "Attributes[";
	out << " min = " <<  min_;
	out << " max = " <<  max_;
	out << " reverse = " <<  reverse_;
	out << " automatic = " <<  automatic_;
	
	out << "]" << "\n";
}

void XRegularCoordinateAttributes::toxml(ostream& out)  const
{
	out <<  "\"x_regular\""; 
	out << ", \"subpage_x_min\":";
	niceprint(out,min_);
	out << ", \"subpage_x_max\":";
	niceprint(out,max_);
	out << ", \"subpage_x_automatic_reverse\":";
	niceprint(out,reverse_);
	out << ", \"subpage_x_automatic\":";
	niceprint(out, automatic_);
	
}

static MagicsParameter<double> subpage_x_min("subpage_x_min", 0, "");
static MagicsParameter<double> subpage_x_max("subpage_x_max", 100, "");
static MagicsParameter<string> subpage_x_automatic_reverse("subpage_x_automatic_reverse", "off", "");
static MagicsParameter<string> subpage_x_automatic("subpage_x_automatic", "off", ""); 

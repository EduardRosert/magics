
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file YLogarithmicCoordinateAttributes.h
    \\brief Definition of YLogarithmicCoordinate Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 2020-10-14
*/

#include "YLogarithmicCoordinateAttributes.h"
#include "MagicsParameter.h"
#include "ParameterSettings.h"

using namespace magics;

YLogarithmicCoordinateAttributes::YLogarithmicCoordinateAttributes():
	min_(ParameterManager::getDouble("subpage_y_min")),
	max_(ParameterManager::getDouble("subpage_y_max")),
	reverse_(ParameterManager::getBool("subpage_y_automatic_reverse"))
	,
	automatic_(MagTranslator<string, AxisAutomaticSetting>().magics("subpage_y_automatic"))
	 
{
} 


YLogarithmicCoordinateAttributes::~YLogarithmicCoordinateAttributes()
{
	
}

    
void YLogarithmicCoordinateAttributes::set(const std::map<string, string>& params)
{
	vector<string> prefix(2);
	int i = 0;
	prefix[i++] = "subpage";
	prefix[i++] = "subpage_y";
	
	setAttribute(prefix, "subpage_y_min", min_, params);
	setAttribute(prefix, "subpage_y_max", max_, params);
	setAttribute(prefix, "subpage_y_automatic_reverse", reverse_, params);
	
	setAttribute(prefix, "subpage_y_automatic", automatic_, params);
	
}

void YLogarithmicCoordinateAttributes::copy(const YLogarithmicCoordinateAttributes& other)
{
	min_ = other.min_;
	max_ = other.max_;
	reverse_ = other.reverse_;
	automatic_ = other.automatic_;
	
} 


bool YLogarithmicCoordinateAttributes::accept(const string& node)
{	
	
	if ( magCompare(node, "y_regular")  )
		return true;
	
	return false;
}

void YLogarithmicCoordinateAttributes::set(const XmlNode& node)
{
	bool apply = false;

	if ( this->accept(node.name()) == false ) 
		return;

	if ( magCompare(node.name(), "y_regular")  )
		apply = true;
	

	if ( apply )
		set(node.attributes());
	else {
		
	}
	for (auto &elt : node.elements())
	{
		
	}
}

void YLogarithmicCoordinateAttributes::print(ostream& out)  const
{
	out << "Attributes[";
	out << " min = " <<  min_;
	out << " max = " <<  max_;
	out << " reverse = " <<  reverse_;
	out << " automatic = " <<  automatic_;
	
	out << "]" << "\n";
}

void YLogarithmicCoordinateAttributes::toxml(ostream& out)  const
{
	out <<  "\"y_regular\""; 
	out << ", \"subpage_y_min\":";
	niceprint(out,min_);
	out << ", \"subpage_y_max\":";
	niceprint(out,max_);
	out << ", \"subpage_y_automatic_reverse\":";
	niceprint(out,reverse_);
	out << ", \"subpage_y_automatic\":";
	niceprint(out, automatic_);
	
}

static MagicsParameter<double> subpage_y_min("subpage_y_min", 0, "");
static MagicsParameter<double> subpage_y_max("subpage_y_max", 100, "");
static MagicsParameter<string> subpage_y_automatic_reverse("subpage_y_automatic_reverse", "off", "");
static MagicsParameter<string> subpage_y_automatic("subpage_y_automatic", "off", ""); 


/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file XHyperCoordinateAttributes.h
    \\brief Definition of XHyperCoordinate Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 2020-09-22
*/

#include "XHyperCoordinateAttributes.h"
#include "MagicsParameter.h"
#include "ParameterSettings.h"

using namespace magics;

XHyperCoordinateAttributes::XHyperCoordinateAttributes():
	min_lat_(ParameterManager::getDouble("subpage_x_min_latitude")),
	max_lat_(ParameterManager::getDouble("subpage_x_max_latitude")),
	min_lon_(ParameterManager::getDouble("subpage_x_min_longitude")),
	max_lon_(ParameterManager::getDouble("subpage_x_max_longitude")),
	reverse_(ParameterManager::getBool("subpage_x_automatic_reverse"))
	,
	automatic_(MagTranslator<string, AxisAutomaticSetting>().magics("subpage_x_automatic"))
	 
{
} 


XHyperCoordinateAttributes::~XHyperCoordinateAttributes()
{
	
}

    
void XHyperCoordinateAttributes::set(const std::map<string, string>& params)
{
	vector<string> prefix(3);
	int i = 0;
	prefix[i++] = "subpage";
	prefix[i++] = "subpage_x";
	prefix[i++] = "subpage_x_hyper";
	
	setAttribute(prefix, "subpage_x_min_latitude", min_lat_, params);
	setAttribute(prefix, "subpage_x_max_latitude", max_lat_, params);
	setAttribute(prefix, "subpage_x_min_longitude", min_lon_, params);
	setAttribute(prefix, "subpage_x_max_longitude", max_lon_, params);
	setAttribute(prefix, "subpage_x_automatic_reverse", reverse_, params);
	
	setAttribute(prefix, "subpage_x_automatic", automatic_, params);
	
}

void XHyperCoordinateAttributes::copy(const XHyperCoordinateAttributes& other)
{
	min_lat_ = other.min_lat_;
	max_lat_ = other.max_lat_;
	min_lon_ = other.min_lon_;
	max_lon_ = other.max_lon_;
	reverse_ = other.reverse_;
	automatic_ = other.automatic_;
	
} 


bool XHyperCoordinateAttributes::accept(const string& node)
{	
	
	if ( magCompare(node, "x_hyper")  )
		return true;
	
	return false;
}

void XHyperCoordinateAttributes::set(const XmlNode& node)
{
	bool apply = false;

	if ( this->accept(node.name()) == false ) 
		return;

	if ( magCompare(node.name(), "x_hyper")  )
		apply = true;
	

	if ( apply )
		set(node.attributes());
	else {
		
	}
	for (auto &elt : node.elements())
	{
		
	}
}

void XHyperCoordinateAttributes::print(ostream& out)  const
{
	out << "Attributes[";
	out << " min_lat = " <<  min_lat_;
	out << " max_lat = " <<  max_lat_;
	out << " min_lon = " <<  min_lon_;
	out << " max_lon = " <<  max_lon_;
	out << " reverse = " <<  reverse_;
	out << " automatic = " <<  automatic_;
	
	out << "]" << "\n";
}

void XHyperCoordinateAttributes::toxml(ostream& out)  const
{
	out <<  "\"x_hyper\""; 
	out << ", \"subpage_x_min_latitude\":";
	niceprint(out,min_lat_);
	out << ", \"subpage_x_max_latitude\":";
	niceprint(out,max_lat_);
	out << ", \"subpage_x_min_longitude\":";
	niceprint(out,min_lon_);
	out << ", \"subpage_x_max_longitude\":";
	niceprint(out,max_lon_);
	out << ", \"subpage_x_automatic_reverse\":";
	niceprint(out,reverse_);
	out << ", \"subpage_x_automatic\":";
	niceprint(out, automatic_);
	
}

static MagicsParameter<double> subpage_x_min_latitude("subpage_x_min_latitude", -90, "");
static MagicsParameter<double> subpage_x_max_latitude("subpage_x_max_latitude", 90, "");
static MagicsParameter<double> subpage_x_min_longitude("subpage_x_min_longitude", -180, "");
static MagicsParameter<double> subpage_x_max_longitude("subpage_x_max_longitude", 180, "");
static MagicsParameter<string> subpage_x_automatic_reverse("subpage_x_automatic_reverse", "off", "");
static MagicsParameter<string> subpage_x_automatic("subpage_x_automatic", "off", ""); 

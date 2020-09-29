
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file SimplePolylineInputAttributes.h
    \\brief Definition of SimplePolylineInput Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 2020-09-24
*/

#include "SimplePolylineInputAttributes.h"
#include "MagicsParameter.h"
#include "ParameterSettings.h"

using namespace magics;

SimplePolylineInputAttributes::SimplePolylineInputAttributes():
	latitudes_(ParameterManager::getDoubleArray("polyline_input_latitudes")),
	longitudes_(ParameterManager::getDoubleArray("polyline_input_longitudes")),
	values_(ParameterManager::getDoubleArray("polyline_input_values")),
	breakvalue_(ParameterManager::getDouble("polyline_input_break_indicator")),
	position_filename_(ParameterManager::getString("polyline_input_positions_filename")),
	values_filename_(ParameterManager::getString("polyline_input_values_filename"))
	
	 
{
} 


SimplePolylineInputAttributes::~SimplePolylineInputAttributes()
{
	
}

    
void SimplePolylineInputAttributes::set(const std::map<string, string>& params)
{
	vector<string> prefix(2);
	int i = 0;
	prefix[i++] = "polyline";
	prefix[i++] = "polyline_input";
	
	setAttribute(prefix, "polyline_input_latitudes", latitudes_, params);
	setAttribute(prefix, "polyline_input_longitudes", longitudes_, params);
	setAttribute(prefix, "polyline_input_values", values_, params);
	setAttribute(prefix, "polyline_input_break_indicator", breakvalue_, params);
	setAttribute(prefix, "polyline_input_positions_filename", position_filename_, params);
	setAttribute(prefix, "polyline_input_values_filename", values_filename_, params);
	
	
}

void SimplePolylineInputAttributes::copy(const SimplePolylineInputAttributes& other)
{
	latitudes_ = other.latitudes_;
	longitudes_ = other.longitudes_;
	values_ = other.values_;
	breakvalue_ = other.breakvalue_;
	position_filename_ = other.position_filename_;
	values_filename_ = other.values_filename_;
	
} 


bool SimplePolylineInputAttributes::accept(const string& node)
{	
	
	if ( magCompare(node, "polyline_input")  )
		return true;
	
	return false;
}

void SimplePolylineInputAttributes::set(const XmlNode& node)
{
	bool apply = false;

	if ( this->accept(node.name()) == false ) 
		return;

	if ( magCompare(node.name(), "polyline_input")  )
		apply = true;
	

	if ( apply )
		set(node.attributes());
	else {
		
	}
	for (auto &elt : node.elements())
	{
		
	}
}

void SimplePolylineInputAttributes::print(ostream& out)  const
{
	out << "Attributes[";
	out << " latitudes = " <<  latitudes_;
	out << " longitudes = " <<  longitudes_;
	out << " values = " <<  values_;
	out << " breakvalue = " <<  breakvalue_;
	out << " position_filename = " <<  position_filename_;
	out << " values_filename = " <<  values_filename_;
	
	out << "]" << "\n";
}

void SimplePolylineInputAttributes::toxml(ostream& out)  const
{
	out <<  "\"polyline_input\""; 
	out << ", \"polyline_input_latitudes\":";
	niceprint(out,latitudes_);
	out << ", \"polyline_input_longitudes\":";
	niceprint(out,longitudes_);
	out << ", \"polyline_input_values\":";
	niceprint(out,values_);
	out << ", \"polyline_input_break_indicator\":";
	niceprint(out,breakvalue_);
	out << ", \"polyline_input_positions_filename\":";
	niceprint(out,position_filename_);
	out << ", \"polyline_input_values_filename\":";
	niceprint(out,values_filename_);
	
}

static MagicsParameter<doublearray> polyline_input_latitudes("polyline_input_latitudes", floatarray(), "");
static MagicsParameter<doublearray> polyline_input_longitudes("polyline_input_longitudes", floatarray(), "");
static MagicsParameter<doublearray> polyline_input_values("polyline_input_values", floatarray(), "");
static MagicsParameter<double> polyline_input_break_indicator("polyline_input_break_indicator", -999, "");
static MagicsParameter<string> polyline_input_positions_filename("polyline_input_positions_filename", "", "");
static MagicsParameter<string> polyline_input_values_filename("polyline_input_values_filename", "", "");

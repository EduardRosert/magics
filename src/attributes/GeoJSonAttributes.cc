
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file GeoJSonAttributes.h
    \\brief Definition of GeoJSon Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 2020-10-14
*/

#include "GeoJSonAttributes.h"
#include "MagicsParameter.h"
#include "ParameterSettings.h"

using namespace magics;

GeoJSonAttributes::GeoJSonAttributes():
	type_(ParameterManager::getString("geojson_input_type")),
	path_(ParameterManager::getString("geojson_input_filename")),
	input_(ParameterManager::getString("geojson_input")),
	binning_resolution_(ParameterManager::getDouble("geojson_binning_grid_resolution"))
	
	 
{
} 


GeoJSonAttributes::~GeoJSonAttributes()
{
	
}

    
void GeoJSonAttributes::set(const std::map<string, string>& params)
{
	vector<string> prefix(1);
	int i = 0;
	prefix[i++] = "geojson";
	
	setAttribute(prefix, "geojson_input_type", type_, params);
	setAttribute(prefix, "geojson_input_filename", path_, params);
	setAttribute(prefix, "geojson_input", input_, params);
	setAttribute(prefix, "geojson_binning_grid_resolution", binning_resolution_, params);
	
	
}

void GeoJSonAttributes::copy(const GeoJSonAttributes& other)
{
	type_ = other.type_;
	path_ = other.path_;
	input_ = other.input_;
	binning_resolution_ = other.binning_resolution_;
	
} 


bool GeoJSonAttributes::accept(const string& node)
{	
	
	if ( magCompare(node, "geojson")  )
		return true;
	
	return false;
}

void GeoJSonAttributes::set(const XmlNode& node)
{
	bool apply = false;

	if ( this->accept(node.name()) == false ) 
		return;

	if ( magCompare(node.name(), "geojson")  )
		apply = true;
	

	if ( apply )
		set(node.attributes());
	else {
		
	}
	for (auto &elt : node.elements())
	{
		
	}
}

void GeoJSonAttributes::print(ostream& out)  const
{
	out << "Attributes[";
	out << " type = " <<  type_;
	out << " path = " <<  path_;
	out << " input = " <<  input_;
	out << " binning_resolution = " <<  binning_resolution_;
	
	out << "]" << "\n";
}

void GeoJSonAttributes::toxml(ostream& out)  const
{
	out <<  "\"geojson\""; 
	out << ", \"geojson_input_type\":";
	niceprint(out,type_);
	out << ", \"geojson_input_filename\":";
	niceprint(out,path_);
	out << ", \"geojson_input\":";
	niceprint(out,input_);
	out << ", \"geojson_binning_grid_resolution\":";
	niceprint(out,binning_resolution_);
	
}

static MagicsParameter<string> geojson_input_type("geojson_input_type", "file", "");
static MagicsParameter<string> geojson_input_filename("geojson_input_filename", "", "");
static MagicsParameter<string> geojson_input("geojson_input", "{}", "");
static MagicsParameter<double> geojson_binning_grid_resolution("geojson_binning_grid_resolution", 1., "");

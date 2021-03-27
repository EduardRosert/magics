
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file TileDecoderAttributes.h
    \\brief Definition of TileDecoder Attributes class.

    This file is automatically generated.
    Do Not Edit!
*/

#include "TileDecoderAttributes.h"
#include "MagicsParameter.h"
#include "ParameterSettings.h"

using namespace magics;

TileDecoderAttributes::TileDecoderAttributes():
	file_name_(ParameterManager::getString("grib_input_file_name")),
	projection_(ParameterManager::getString("grib_tile_projection")),
	loop_(ParameterManager::getBool("grib_loop")),
	z_(ParameterManager::getInt("grib_tile_z")),
	x_(ParameterManager::getInt("grib_tile_x")),
	y_(ParameterManager::getInt("grib_tile_y")),
	scaling_(ParameterManager::getBool("grib_automatic_scaling")),
	scaling_factor_(ParameterManager::getDouble("grib_scaling_factor")),
	scaling_offset_(ParameterManager::getDouble("grib_scaling_offset"))
	
	 
{
} 


TileDecoderAttributes::~TileDecoderAttributes()
{
	
}

    
void TileDecoderAttributes::set(const std::map<string, string>& params)
{
	vector<string> prefix(1);
	int i = 0;
	prefix[i++] = "grib";
	
	setAttribute(prefix, "grib_input_file_name", file_name_, params);
	setAttribute(prefix, "grib_tile_projection", projection_, params);
	setAttribute(prefix, "grib_loop", loop_, params);
	setAttribute(prefix, "grib_tile_z", z_, params);
	setAttribute(prefix, "grib_tile_x", x_, params);
	setAttribute(prefix, "grib_tile_y", y_, params);
	setAttribute(prefix, "grib_automatic_scaling", scaling_, params);
	setAttribute(prefix, "grib_scaling_factor", scaling_factor_, params);
	setAttribute(prefix, "grib_scaling_offset", scaling_offset_, params);
	
	
}

void TileDecoderAttributes::copy(const TileDecoderAttributes& other)
{
	file_name_ = other.file_name_;
	projection_ = other.projection_;
	loop_ = other.loop_;
	z_ = other.z_;
	x_ = other.x_;
	y_ = other.y_;
	scaling_ = other.scaling_;
	scaling_factor_ = other.scaling_factor_;
	scaling_offset_ = other.scaling_offset_;
	
} 


bool TileDecoderAttributes::accept(const string& node)
{	
	
	if ( magCompare(node, "grib")  )
		return true;
	
	return false;
}

void TileDecoderAttributes::set(const XmlNode& node)
{
	bool apply = false;

	if ( this->accept(node.name()) == false ) 
		return;

	if ( magCompare(node.name(), "grib")  )
		apply = true;
	

	if ( apply )
		set(node.attributes());
	else {
		
	}
	for (auto &elt : node.elements())
	{
		
	}
}

void TileDecoderAttributes::print(ostream& out)  const
{
	out << "Attributes[";
	out << " file_name = " <<  file_name_;
	out << " projection = " <<  projection_;
	out << " loop = " <<  loop_;
	out << " z = " <<  z_;
	out << " x = " <<  x_;
	out << " y = " <<  y_;
	out << " scaling = " <<  scaling_;
	out << " scaling_factor = " <<  scaling_factor_;
	out << " scaling_offset = " <<  scaling_offset_;
	
	out << "]" << "\n";
}

void TileDecoderAttributes::toxml(ostream& out)  const
{
	out <<  "\"grib\""; 
	out << ", \"grib_input_file_name\":";
	niceprint(out,file_name_);
	out << ", \"grib_tile_projection\":";
	niceprint(out,projection_);
	out << ", \"grib_loop\":";
	niceprint(out,loop_);
	out << ", \"grib_tile_z\":";
	niceprint(out,z_);
	out << ", \"grib_tile_x\":";
	niceprint(out,x_);
	out << ", \"grib_tile_y\":";
	niceprint(out,y_);
	out << ", \"grib_automatic_scaling\":";
	niceprint(out,scaling_);
	out << ", \"grib_scaling_factor\":";
	niceprint(out,scaling_factor_);
	out << ", \"grib_scaling_offset\":";
	niceprint(out,scaling_offset_);
	
}

static MagicsParameter<string> grib_input_file_name("grib_input_file_name", "", "");
static MagicsParameter<string> grib_tile_projection("grib_tile_projection", "cylindrical", "");
static MagicsParameter<string> grib_loop("grib_loop", "off", "");
static MagicsParameter<int> grib_tile_z("grib_tile_z", 1, "");
static MagicsParameter<int> grib_tile_x("grib_tile_x", 0, "");
static MagicsParameter<int> grib_tile_y("grib_tile_y", 0, "");
static MagicsParameter<string> grib_automatic_scaling("grib_automatic_scaling", "on", "");
static MagicsParameter<double> grib_scaling_factor("grib_scaling_factor", 1, "");
static MagicsParameter<double> grib_scaling_offset("grib_scaling_offset", 0, "");

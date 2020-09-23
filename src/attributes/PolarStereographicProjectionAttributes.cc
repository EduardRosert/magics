
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file PolarStereographicProjectionAttributes.h
    \\brief Definition of PolarStereographicProjection Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 2020-09-22
*/

#include "PolarStereographicProjectionAttributes.h"
#include "MagicsParameter.h"
#include "ParameterSettings.h"

using namespace magics;

PolarStereographicProjectionAttributes::PolarStereographicProjectionAttributes():
	system_(ParameterManager::getString("subpage_map_area_coordinate_system")),
	area_(ParameterManager::getString("subpage_map_area_definition_polar")),
	min_latitude_(ParameterManager::getDouble("subpage_lower_left_latitude")),
	min_longitude_(ParameterManager::getDouble("subpage_lower_left_longitude")),
	max_latitude_(ParameterManager::getDouble("subpage_upper_right_latitude")),
	max_longitude_(ParameterManager::getDouble("subpage_upper_right_longitude")),
	vertical_longitude_(ParameterManager::getDouble("subpage_map_vertical_longitude")),
	centre_latitude_(ParameterManager::getDouble("subpage_map_centre_latitude")),
	centre_longitude_(ParameterManager::getDouble("subpage_map_centre_longitude")),
	map_scale_(ParameterManager::getDouble("subpage_map_scale"))
	,
	hemisphere_(MagTranslator<string, Hemisphere>().magics("subpage_map_hemisphere"))
	 
{
} 


PolarStereographicProjectionAttributes::~PolarStereographicProjectionAttributes()
{
	
}

    
void PolarStereographicProjectionAttributes::set(const std::map<string, string>& params)
{
	vector<string> prefix(4);
	int i = 0;
	prefix[i++] = "subpage";
	prefix[i++] = "subpage";
	prefix[i++] = "subpage_map";
	prefix[i++] = "subpage_map_area";
	
	setAttribute(prefix, "subpage_map_area_coordinate_system", system_, params);
	setAttribute(prefix, "subpage_map_area_definition_polar", area_, params);
	setAttribute(prefix, "subpage_lower_left_latitude", min_latitude_, params);
	setAttribute(prefix, "subpage_lower_left_longitude", min_longitude_, params);
	setAttribute(prefix, "subpage_upper_right_latitude", max_latitude_, params);
	setAttribute(prefix, "subpage_upper_right_longitude", max_longitude_, params);
	setAttribute(prefix, "subpage_map_vertical_longitude", vertical_longitude_, params);
	setAttribute(prefix, "subpage_map_centre_latitude", centre_latitude_, params);
	setAttribute(prefix, "subpage_map_centre_longitude", centre_longitude_, params);
	setAttribute(prefix, "subpage_map_scale", map_scale_, params);
	
	setAttribute(prefix, "subpage_map_hemisphere", hemisphere_, params);
	
}

void PolarStereographicProjectionAttributes::copy(const PolarStereographicProjectionAttributes& other)
{
	system_ = other.system_;
	area_ = other.area_;
	min_latitude_ = other.min_latitude_;
	min_longitude_ = other.min_longitude_;
	max_latitude_ = other.max_latitude_;
	max_longitude_ = other.max_longitude_;
	vertical_longitude_ = other.vertical_longitude_;
	centre_latitude_ = other.centre_latitude_;
	centre_longitude_ = other.centre_longitude_;
	map_scale_ = other.map_scale_;
	hemisphere_ = other.hemisphere_;
	
} 


bool PolarStereographicProjectionAttributes::accept(const string& node)
{	
	
	if ( magCompare(node, "polar_stereographic")  )
		return true;
	
	return false;
}

void PolarStereographicProjectionAttributes::set(const XmlNode& node)
{
	bool apply = false;

	if ( this->accept(node.name()) == false ) 
		return;

	if ( magCompare(node.name(), "polar_stereographic")  )
		apply = true;
	

	if ( apply )
		set(node.attributes());
	else {
		
	}
	for (auto &elt : node.elements())
	{
		
	}
}

void PolarStereographicProjectionAttributes::print(ostream& out)  const
{
	out << "Attributes[";
	out << " system = " <<  system_;
	out << " area = " <<  area_;
	out << " min_latitude = " <<  min_latitude_;
	out << " min_longitude = " <<  min_longitude_;
	out << " max_latitude = " <<  max_latitude_;
	out << " max_longitude = " <<  max_longitude_;
	out << " vertical_longitude = " <<  vertical_longitude_;
	out << " centre_latitude = " <<  centre_latitude_;
	out << " centre_longitude = " <<  centre_longitude_;
	out << " map_scale = " <<  map_scale_;
	out << " hemisphere = " <<  hemisphere_;
	
	out << "]" << "\n";
}

void PolarStereographicProjectionAttributes::toxml(ostream& out)  const
{
	out <<  "\"polar_stereographic\""; 
	out << ", \"subpage_map_area_coordinate_system\":";
	niceprint(out,system_);
	out << ", \"subpage_map_area_definition_polar\":";
	niceprint(out,area_);
	out << ", \"subpage_lower_left_latitude\":";
	niceprint(out,min_latitude_);
	out << ", \"subpage_lower_left_longitude\":";
	niceprint(out,min_longitude_);
	out << ", \"subpage_upper_right_latitude\":";
	niceprint(out,max_latitude_);
	out << ", \"subpage_upper_right_longitude\":";
	niceprint(out,max_longitude_);
	out << ", \"subpage_map_vertical_longitude\":";
	niceprint(out,vertical_longitude_);
	out << ", \"subpage_map_centre_latitude\":";
	niceprint(out,centre_latitude_);
	out << ", \"subpage_map_centre_longitude\":";
	niceprint(out,centre_longitude_);
	out << ", \"subpage_map_scale\":";
	niceprint(out,map_scale_);
	out << ", \"subpage_map_hemisphere\":";
	niceprint(out, hemisphere_);
	
}

static MagicsParameter<string> subpage_map_area_coordinate_system("subpage_map_area_coordinate_system", "users", "");
static MagicsParameter<string> subpage_map_area_definition_polar("subpage_map_area_definition_polar", "corners", "");
static MagicsParameter<double> subpage_lower_left_latitude("subpage_lower_left_latitude", -90.0, "");
static MagicsParameter<double> subpage_lower_left_longitude("subpage_lower_left_longitude", -180.0, "");
static MagicsParameter<double> subpage_upper_right_latitude("subpage_upper_right_latitude", 90.0, "");
static MagicsParameter<double> subpage_upper_right_longitude("subpage_upper_right_longitude", 180.0, "");
static MagicsParameter<double> subpage_map_vertical_longitude("subpage_map_vertical_longitude", 0.0, "");
static MagicsParameter<double> subpage_map_centre_latitude("subpage_map_centre_latitude", 90.0, "");
static MagicsParameter<double> subpage_map_centre_longitude("subpage_map_centre_longitude", 0.0, "");
static MagicsParameter<double> subpage_map_scale("subpage_map_scale", 50.e6, "");
static MagicsParameter<string> subpage_map_hemisphere("subpage_map_hemisphere", "north", ""); 

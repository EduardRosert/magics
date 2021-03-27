
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file NetcdfInterpretorAttributes.h
    \\brief Definition of NetcdfInterpretor Attributes class.

    This file is automatically generated.
    Do Not Edit!
*/

#include "NetcdfInterpretorAttributes.h"
#include "MagicsParameter.h"
#include "ParameterSettings.h"

using namespace magics;

NetcdfInterpretorAttributes::NetcdfInterpretorAttributes():
	path_(ParameterManager::getString("netcdf_filename")),
	dimension_(ParameterManager::getStringArray("netcdf_dimension_setting")),
	time_variable_(ParameterManager::getString("netcdf_time_variable")),
	level_variable_(ParameterManager::getString("netcdf_level_variable")),
	number_variable_(ParameterManager::getString("netcdf_number_variable")),
	time_dimension_(ParameterManager::getString("netcdf_time_dimension_setting")),
	level_dimension_(ParameterManager::getString("netcdf_level_dimension_setting")),
	number_dimension_(ParameterManager::getString("netcdf_number_dimension_setting")),
	dimension_method_(ParameterManager::getString("netcdf_dimension_setting_method")),
	latitude_(ParameterManager::getString("netcdf_latitude_variable")),
	longitude_(ParameterManager::getString("netcdf_longitude_variable")),
	speed_(ParameterManager::getString("netcdf_speed_component_variable")),
	direction_(ParameterManager::getString("netcdf_direction_component_variable")),
	field_(ParameterManager::getString("netcdf_value_variable")),
	x_component_(ParameterManager::getString("netcdf_x_component_variable")),
	y_component_(ParameterManager::getString("netcdf_y_component_variable")),
	colour_component_(ParameterManager::getString("netcdf_colour_component_variable")),
	automatic_scaling_(ParameterManager::getBool("netcdf_field_automatic_scaling")),
	scaling_(ParameterManager::getDouble("netcdf_field_scaling_factor")),
	offset_(ParameterManager::getDouble("netcdf_field_add_offset")),
	missing_attribute_(ParameterManager::getString("netcdf_missing_attribute")),
	reference_(ParameterManager::getString("netcdf_reference_date")),
	suppress_below_(ParameterManager::getDouble("netcdf_field_suppress_below")),
	suppress_above_(ParameterManager::getDouble("netcdf_field_suppress_above")),
	x_(ParameterManager::getString("netcdf_x_variable")),
	x2_(ParameterManager::getString("netcdf_x2_variable")),
	y_(ParameterManager::getString("netcdf_y_variable")),
	y2_(ParameterManager::getString("netcdf_y2_variable")),
	aux_x_(ParameterManager::getString("netcdf_x_auxiliary_variable")),
	geo_x_convention_(ParameterManager::getString("netcdf_x_geoline_convention")),
	geo_y_convention_(ParameterManager::getString("netcdf_y_geoline_convention")),
	aux_y_(ParameterManager::getString("netcdf_y_auxiliary_variable")),
	primary_index_(ParameterManager::getString("netcdf_matrix_primary_index"))
	
	
{
}


NetcdfInterpretorAttributes::~NetcdfInterpretorAttributes()
{

}


void NetcdfInterpretorAttributes::set(const std::map<string, string>& params)
{
	vector<string> prefix(1);
	int i = 0;
	prefix[i++] = "netcdf";
	
	setAttribute(prefix, "netcdf_filename", path_, params);
	setAttribute(prefix, "netcdf_dimension_setting", dimension_, params);
	setAttribute(prefix, "netcdf_time_variable", time_variable_, params);
	setAttribute(prefix, "netcdf_level_variable", level_variable_, params);
	setAttribute(prefix, "netcdf_number_variable", number_variable_, params);
	setAttribute(prefix, "netcdf_time_dimension_setting", time_dimension_, params);
	setAttribute(prefix, "netcdf_level_dimension_setting", level_dimension_, params);
	setAttribute(prefix, "netcdf_number_dimension_setting", number_dimension_, params);
	setAttribute(prefix, "netcdf_dimension_setting_method", dimension_method_, params);
	setAttribute(prefix, "netcdf_latitude_variable", latitude_, params);
	setAttribute(prefix, "netcdf_longitude_variable", longitude_, params);
	setAttribute(prefix, "netcdf_speed_component_variable", speed_, params);
	setAttribute(prefix, "netcdf_direction_component_variable", direction_, params);
	setAttribute(prefix, "netcdf_value_variable", field_, params);
	setAttribute(prefix, "netcdf_x_component_variable", x_component_, params);
	setAttribute(prefix, "netcdf_y_component_variable", y_component_, params);
	setAttribute(prefix, "netcdf_colour_component_variable", colour_component_, params);
	setAttribute(prefix, "netcdf_field_automatic_scaling", automatic_scaling_, params);
	setAttribute(prefix, "netcdf_field_scaling_factor", scaling_, params);
	setAttribute(prefix, "netcdf_field_add_offset", offset_, params);
	setAttribute(prefix, "netcdf_missing_attribute", missing_attribute_, params);
	setAttribute(prefix, "netcdf_reference_date", reference_, params);
	setAttribute(prefix, "netcdf_field_suppress_below", suppress_below_, params);
	setAttribute(prefix, "netcdf_field_suppress_above", suppress_above_, params);
	setAttribute(prefix, "netcdf_x_variable", x_, params);
	setAttribute(prefix, "netcdf_x2_variable", x2_, params);
	setAttribute(prefix, "netcdf_y_variable", y_, params);
	setAttribute(prefix, "netcdf_y2_variable", y2_, params);
	setAttribute(prefix, "netcdf_x_auxiliary_variable", aux_x_, params);
	setAttribute(prefix, "netcdf_x_geoline_convention", geo_x_convention_, params);
	setAttribute(prefix, "netcdf_y_geoline_convention", geo_y_convention_, params);
	setAttribute(prefix, "netcdf_y_auxiliary_variable", aux_y_, params);
	setAttribute(prefix, "netcdf_matrix_primary_index", primary_index_, params);
	
	
}

void NetcdfInterpretorAttributes::copy(const NetcdfInterpretorAttributes& other)
{
	path_ = other.path_;
	dimension_ = other.dimension_;
	time_variable_ = other.time_variable_;
	level_variable_ = other.level_variable_;
	number_variable_ = other.number_variable_;
	time_dimension_ = other.time_dimension_;
	level_dimension_ = other.level_dimension_;
	number_dimension_ = other.number_dimension_;
	dimension_method_ = other.dimension_method_;
	latitude_ = other.latitude_;
	longitude_ = other.longitude_;
	speed_ = other.speed_;
	direction_ = other.direction_;
	field_ = other.field_;
	x_component_ = other.x_component_;
	y_component_ = other.y_component_;
	colour_component_ = other.colour_component_;
	automatic_scaling_ = other.automatic_scaling_;
	scaling_ = other.scaling_;
	offset_ = other.offset_;
	missing_attribute_ = other.missing_attribute_;
	reference_ = other.reference_;
	suppress_below_ = other.suppress_below_;
	suppress_above_ = other.suppress_above_;
	x_ = other.x_;
	x2_ = other.x2_;
	y_ = other.y_;
	y2_ = other.y2_;
	aux_x_ = other.aux_x_;
	geo_x_convention_ = other.geo_x_convention_;
	geo_y_convention_ = other.geo_y_convention_;
	aux_y_ = other.aux_y_;
	primary_index_ = other.primary_index_;
	
}


bool NetcdfInterpretorAttributes::accept(const string& node)
{

	if ( magCompare(node, "netcdf")  )
		return true;
	
	return false;
}

void NetcdfInterpretorAttributes::set(const XmlNode& node)
{
	bool apply = false;

	if ( this->accept(node.name()) == false )
		return;

	if ( magCompare(node.name(), "netcdf")  )
		apply = true;
	

	if ( apply )
		set(node.attributes());
	else {
		
	}
	for (auto &elt : node.elements())
	{
		
	}
}

void NetcdfInterpretorAttributes::print(ostream& out)  const
{
	out << "Attributes[";
	out << " path = " <<  path_;
	out << " dimension = " <<  dimension_;
	out << " time_variable = " <<  time_variable_;
	out << " level_variable = " <<  level_variable_;
	out << " number_variable = " <<  number_variable_;
	out << " time_dimension = " <<  time_dimension_;
	out << " level_dimension = " <<  level_dimension_;
	out << " number_dimension = " <<  number_dimension_;
	out << " dimension_method = " <<  dimension_method_;
	out << " latitude = " <<  latitude_;
	out << " longitude = " <<  longitude_;
	out << " speed = " <<  speed_;
	out << " direction = " <<  direction_;
	out << " field = " <<  field_;
	out << " x_component = " <<  x_component_;
	out << " y_component = " <<  y_component_;
	out << " colour_component = " <<  colour_component_;
	out << " automatic_scaling = " <<  automatic_scaling_;
	out << " scaling = " <<  scaling_;
	out << " offset = " <<  offset_;
	out << " missing_attribute = " <<  missing_attribute_;
	out << " reference = " <<  reference_;
	out << " suppress_below = " <<  suppress_below_;
	out << " suppress_above = " <<  suppress_above_;
	out << " x = " <<  x_;
	out << " x2 = " <<  x2_;
	out << " y = " <<  y_;
	out << " y2 = " <<  y2_;
	out << " aux_x = " <<  aux_x_;
	out << " geo_x_convention = " <<  geo_x_convention_;
	out << " geo_y_convention = " <<  geo_y_convention_;
	out << " aux_y = " <<  aux_y_;
	out << " primary_index = " <<  primary_index_;
	
	out << "]" << "\n";
}

void NetcdfInterpretorAttributes::toxml(ostream& out)  const
{
	out <<  "\"netcdf\"";
	out << ", \"netcdf_filename\":";
	niceprint(out,path_);
	out << ", \"netcdf_dimension_setting\":";
	niceprint(out,dimension_);
	out << ", \"netcdf_time_variable\":";
	niceprint(out,time_variable_);
	out << ", \"netcdf_level_variable\":";
	niceprint(out,level_variable_);
	out << ", \"netcdf_number_variable\":";
	niceprint(out,number_variable_);
	out << ", \"netcdf_time_dimension_setting\":";
	niceprint(out,time_dimension_);
	out << ", \"netcdf_level_dimension_setting\":";
	niceprint(out,level_dimension_);
	out << ", \"netcdf_number_dimension_setting\":";
	niceprint(out,number_dimension_);
	out << ", \"netcdf_dimension_setting_method\":";
	niceprint(out,dimension_method_);
	out << ", \"netcdf_latitude_variable\":";
	niceprint(out,latitude_);
	out << ", \"netcdf_longitude_variable\":";
	niceprint(out,longitude_);
	out << ", \"netcdf_speed_component_variable\":";
	niceprint(out,speed_);
	out << ", \"netcdf_direction_component_variable\":";
	niceprint(out,direction_);
	out << ", \"netcdf_value_variable\":";
	niceprint(out,field_);
	out << ", \"netcdf_x_component_variable\":";
	niceprint(out,x_component_);
	out << ", \"netcdf_y_component_variable\":";
	niceprint(out,y_component_);
	out << ", \"netcdf_colour_component_variable\":";
	niceprint(out,colour_component_);
	out << ", \"netcdf_field_automatic_scaling\":";
	niceprint(out,automatic_scaling_);
	out << ", \"netcdf_field_scaling_factor\":";
	niceprint(out,scaling_);
	out << ", \"netcdf_field_add_offset\":";
	niceprint(out,offset_);
	out << ", \"netcdf_missing_attribute\":";
	niceprint(out,missing_attribute_);
	out << ", \"netcdf_reference_date\":";
	niceprint(out,reference_);
	out << ", \"netcdf_field_suppress_below\":";
	niceprint(out,suppress_below_);
	out << ", \"netcdf_field_suppress_above\":";
	niceprint(out,suppress_above_);
	out << ", \"netcdf_x_variable\":";
	niceprint(out,x_);
	out << ", \"netcdf_x2_variable\":";
	niceprint(out,x2_);
	out << ", \"netcdf_y_variable\":";
	niceprint(out,y_);
	out << ", \"netcdf_y2_variable\":";
	niceprint(out,y2_);
	out << ", \"netcdf_x_auxiliary_variable\":";
	niceprint(out,aux_x_);
	out << ", \"netcdf_x_geoline_convention\":";
	niceprint(out,geo_x_convention_);
	out << ", \"netcdf_y_geoline_convention\":";
	niceprint(out,geo_y_convention_);
	out << ", \"netcdf_y_auxiliary_variable\":";
	niceprint(out,aux_y_);
	out << ", \"netcdf_matrix_primary_index\":";
	niceprint(out,primary_index_);
	
}

static MagicsParameter<string> netcdf_filename("netcdf_filename", "");
static MagicsParameter<stringarray> netcdf_dimension_setting("netcdf_dimension_setting", stringarray());
static MagicsParameter<string> netcdf_time_variable("netcdf_time_variable", "time");
static MagicsParameter<string> netcdf_level_variable("netcdf_level_variable", "level");
static MagicsParameter<string> netcdf_number_variable("netcdf_number_variable", "number");
static MagicsParameter<string> netcdf_time_dimension_setting("netcdf_time_dimension_setting", "");
static MagicsParameter<string> netcdf_level_dimension_setting("netcdf_level_dimension_setting", "");
static MagicsParameter<string> netcdf_number_dimension_setting("netcdf_number_dimension_setting", "");
static MagicsParameter<string> netcdf_dimension_setting_method("netcdf_dimension_setting_method", "value");
static MagicsParameter<string> netcdf_latitude_variable("netcdf_latitude_variable", "latitude");
static MagicsParameter<string> netcdf_longitude_variable("netcdf_longitude_variable", "longitude");
static MagicsParameter<string> netcdf_speed_component_variable("netcdf_speed_component_variable", "");
static MagicsParameter<string> netcdf_direction_component_variable("netcdf_direction_component_variable", "");
static MagicsParameter<string> netcdf_value_variable("netcdf_value_variable", "");
static MagicsParameter<string> netcdf_x_component_variable("netcdf_x_component_variable", "");
static MagicsParameter<string> netcdf_y_component_variable("netcdf_y_component_variable", "");
static MagicsParameter<string> netcdf_colour_component_variable("netcdf_colour_component_variable", "");
static MagicsParameter<string> netcdf_field_automatic_scaling("netcdf_field_automatic_scaling", "on");
static MagicsParameter<double> netcdf_field_scaling_factor("netcdf_field_scaling_factor", 1);
static MagicsParameter<double> netcdf_field_add_offset("netcdf_field_add_offset", 0);
static MagicsParameter<string> netcdf_missing_attribute("netcdf_missing_attribute", "_FillValue");
static MagicsParameter<string> netcdf_reference_date("netcdf_reference_date", "0");
static MagicsParameter<double> netcdf_field_suppress_below("netcdf_field_suppress_below", -1.0e+21);
static MagicsParameter<double> netcdf_field_suppress_above("netcdf_field_suppress_above", 1.0e+21);
static MagicsParameter<string> netcdf_x_variable("netcdf_x_variable", "x");
static MagicsParameter<string> netcdf_x2_variable("netcdf_x2_variable", "x2");
static MagicsParameter<string> netcdf_y_variable("netcdf_y_variable", "y");
static MagicsParameter<string> netcdf_y2_variable("netcdf_y2_variable", "y2");
static MagicsParameter<string> netcdf_x_auxiliary_variable("netcdf_x_auxiliary_variable", "");
static MagicsParameter<string> netcdf_x_geoline_convention("netcdf_x_geoline_convention", "lonlat");
static MagicsParameter<string> netcdf_y_geoline_convention("netcdf_y_geoline_convention", "lonlat");
static MagicsParameter<string> netcdf_y_auxiliary_variable("netcdf_y_auxiliary_variable", "");
static MagicsParameter<string> netcdf_matrix_primary_index("netcdf_matrix_primary_index", "longitude");

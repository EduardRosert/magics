
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file GribLoopAttributes.h
    \\brief Definition of GribLoop Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 2020-10-14
*/

#include "GribLoopAttributes.h"
#include "MagicsParameter.h"
#include "ParameterSettings.h"

using namespace magics;

GribLoopAttributes::GribLoopAttributes():
	dimension_(ParameterManager::getIntArray("grib_dimension")),
	dim_1_(ParameterManager::getLongIntArray("grib_position_1")),
	dim_2_(ParameterManager::getLongIntArray("grib_position_2")),
	dim_colour_(ParameterManager::getLongIntArray("grib_position_colour")),
	dim_(ParameterManager::getLongIntArray("grib_position")),
	path_(ParameterManager::getString("grib_loop_path")),
	scaling_(ParameterManager::getBool("grib_automatic_scaling")),
	derived_scaling_(ParameterManager::getBool("grib_automatic_derived_scaling")),
	scaling_factor_(ParameterManager::getDouble("grib_scaling_factor")),
	scaling_offset_(ParameterManager::getDouble("grib_scaling_offset")),
	regular_resolution_(ParameterManager::getDouble("grib_interpolation_regular_resolution")),
	interpolation_method_(ParameterManager::getString("grib_interpolation_method")),
	missing_fill_count_(ParameterManager::getInt("grib_interpolation_method_missing_fill_count"))
	,
	address_mode_(MagTranslator<string, GribAddressMode>().magics("grib_file_address_mode")),
	step_(MagTranslator<string, GribLoopStep>().magics("grib_loop_step")),
	wind_mode_(MagTranslator<string, WindMode>().magics("grib_wind_mode"))
	 
{
} 


GribLoopAttributes::~GribLoopAttributes()
{
	
}

    
void GribLoopAttributes::set(const std::map<string, string>& params)
{
	vector<string> prefix(1);
	int i = 0;
	prefix[i++] = "grib";
	
	setAttribute(prefix, "grib_dimension", dimension_, params);
	setAttribute(prefix, "grib_position_1", dim_1_, params);
	setAttribute(prefix, "grib_position_2", dim_2_, params);
	setAttribute(prefix, "grib_position_colour", dim_colour_, params);
	setAttribute(prefix, "grib_position", dim_, params);
	setAttribute(prefix, "grib_loop_path", path_, params);
	setAttribute(prefix, "grib_automatic_scaling", scaling_, params);
	setAttribute(prefix, "grib_automatic_derived_scaling", derived_scaling_, params);
	setAttribute(prefix, "grib_scaling_factor", scaling_factor_, params);
	setAttribute(prefix, "grib_scaling_offset", scaling_offset_, params);
	setAttribute(prefix, "grib_interpolation_regular_resolution", regular_resolution_, params);
	setAttribute(prefix, "grib_interpolation_method", interpolation_method_, params);
	setAttribute(prefix, "grib_interpolation_method_missing_fill_count", missing_fill_count_, params);
	
	setMember(prefix, "grib_file_address_mode", address_mode_, params);
	setMember(prefix, "grib_loop_step", step_, params);
	setMember(prefix, "grib_wind_mode", wind_mode_, params);
	
}

void GribLoopAttributes::copy(const GribLoopAttributes& other)
{
	dimension_ = other.dimension_;
	dim_1_ = other.dim_1_;
	dim_2_ = other.dim_2_;
	dim_colour_ = other.dim_colour_;
	dim_ = other.dim_;
	path_ = other.path_;
	scaling_ = other.scaling_;
	derived_scaling_ = other.derived_scaling_;
	scaling_factor_ = other.scaling_factor_;
	scaling_offset_ = other.scaling_offset_;
	regular_resolution_ = other.regular_resolution_;
	interpolation_method_ = other.interpolation_method_;
	missing_fill_count_ = other.missing_fill_count_;
	address_mode_ = unique_ptr<GribAddressMode>(other.address_mode_->clone());
	step_ = unique_ptr<GribLoopStep>(other.step_->clone());
	wind_mode_ = unique_ptr<WindMode>(other.wind_mode_->clone());
	
} 


bool GribLoopAttributes::accept(const string& node)
{	
	
	if ( magCompare(node, "gribloop")  )
		return true;
	if ( acceptNode(node, address_mode_) )
		return true;
	if ( acceptNode(node, step_) )
		return true;
	if ( acceptNode(node, wind_mode_) )
		return true;
	
	return false;
}

void GribLoopAttributes::set(const XmlNode& node)
{
	bool apply = false;

	if ( this->accept(node.name()) == false ) 
		return;

	if ( magCompare(node.name(), "gribloop")  )
		apply = true;
	

	if ( apply )
		set(node.attributes());
	else {
		setMember(node.name(), address_mode_, node);
		setMember(node.name(), step_, node);
		setMember(node.name(), wind_mode_, node);
		
	}
	for (auto &elt : node.elements())
	{
		setMember(elt->name(), address_mode_, *elt); 
		setMember(elt->name(), step_, *elt); 
		setMember(elt->name(), wind_mode_, *elt); 
		
	}
}

void GribLoopAttributes::print(ostream& out)  const
{
	out << "Attributes[";
	out << " dimension = " <<  dimension_;
	out << " dim_1 = " <<  dim_1_;
	out << " dim_2 = " <<  dim_2_;
	out << " dim_colour = " <<  dim_colour_;
	out << " dim = " <<  dim_;
	out << " path = " <<  path_;
	out << " scaling = " <<  scaling_;
	out << " derived_scaling = " <<  derived_scaling_;
	out << " scaling_factor = " <<  scaling_factor_;
	out << " scaling_offset = " <<  scaling_offset_;
	out << " regular_resolution = " <<  regular_resolution_;
	out << " interpolation_method = " <<  interpolation_method_;
	out << " missing_fill_count = " <<  missing_fill_count_;
	out << " address_mode = " <<  *address_mode_;
	out << " step = " <<  *step_;
	out << " wind_mode = " <<  *wind_mode_;
	
	out << "]" << "\n";
}

void GribLoopAttributes::toxml(ostream& out)  const
{
	out <<  "\"gribloop\""; 
	out << ", \"grib_dimension\":";
	niceprint(out,dimension_);
	out << ", \"grib_position_1\":";
	niceprint(out,dim_1_);
	out << ", \"grib_position_2\":";
	niceprint(out,dim_2_);
	out << ", \"grib_position_colour\":";
	niceprint(out,dim_colour_);
	out << ", \"grib_position\":";
	niceprint(out,dim_);
	out << ", \"grib_loop_path\":";
	niceprint(out,path_);
	out << ", \"grib_automatic_scaling\":";
	niceprint(out,scaling_);
	out << ", \"grib_automatic_derived_scaling\":";
	niceprint(out,derived_scaling_);
	out << ", \"grib_scaling_factor\":";
	niceprint(out,scaling_factor_);
	out << ", \"grib_scaling_offset\":";
	niceprint(out,scaling_offset_);
	out << ", \"grib_interpolation_regular_resolution\":";
	niceprint(out,regular_resolution_);
	out << ", \"grib_interpolation_method\":";
	niceprint(out,interpolation_method_);
	out << ", \"grib_interpolation_method_missing_fill_count\":";
	niceprint(out,missing_fill_count_);
	out << ", \"grib_file_address_mode\":";
	address_mode_->toxml(out);
	out << ", \"grib_loop_step\":";
	step_->toxml(out);
	out << ", \"grib_wind_mode\":";
	wind_mode_->toxml(out);
	
}

static MagicsParameter<intarray> grib_dimension("grib_dimension", intarray(), "");
static MagicsParameter<longintarray> grib_position_1("grib_position_1", longintarray(), "");
static MagicsParameter<longintarray> grib_position_2("grib_position_2", longintarray(), "");
static MagicsParameter<longintarray> grib_position_colour("grib_position_colour", longintarray(), "");
static MagicsParameter<longintarray> grib_position("grib_position", longintarray(), "");
static MagicsParameter<string> grib_loop_path("grib_loop_path", "", "");
static MagicsParameter<string> grib_automatic_scaling("grib_automatic_scaling", "on", "");
static MagicsParameter<string> grib_automatic_derived_scaling("grib_automatic_derived_scaling", "off", "");
static MagicsParameter<double> grib_scaling_factor("grib_scaling_factor", 1, "");
static MagicsParameter<double> grib_scaling_offset("grib_scaling_offset", 0, "");
static MagicsParameter<double> grib_interpolation_regular_resolution("grib_interpolation_regular_resolution", 0.1, "");
static MagicsParameter<string> grib_interpolation_method("grib_interpolation_method", "interpolate", "");
static MagicsParameter<int> grib_interpolation_method_missing_fill_count("grib_interpolation_method_missing_fill_count", 1, "");
static MagicsParameter<string> grib_file_address_mode("grib_file_address_mode", "record", ""); 
static MagicsParameter<string> grib_loop_step("grib_loop_step", "loopondate", ""); 
static MagicsParameter<string> grib_wind_mode("grib_wind_mode", "uv", ""); 
#include "GribLoopStep.h"
#include "WindMode.h"
#include "GribAddressMode.h"
static SimpleObjectMaker<GribAddressRecordMode , GribAddressMode> record_GribAddressRecordMode("record");
static SimpleObjectMaker<GribAddressByteMode , GribAddressMode> byte_offset_GribAddressByteMode("byte_offset");
static SimpleObjectMaker<DateGribLoopStep , GribLoopStep> loopondate_DateGribLoopStep("loopondate");
static SimpleObjectMaker<ParamGribLoopStep , GribLoopStep> looponparam_ParamGribLoopStep("looponparam");
static SimpleObjectMaker<UVWindMode , WindMode> uvmode_UVWindMode("uvmode");
static SimpleObjectMaker<UVWindMode , WindMode> uv_UVWindMode("uv");
static SimpleObjectMaker<SDWindMode , WindMode> sdmode_SDWindMode("sdmode");
static SimpleObjectMaker<SDWindMode , WindMode> sd_SDWindMode("sd");

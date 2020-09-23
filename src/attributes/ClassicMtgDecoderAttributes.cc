
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file ClassicMtgDecoderAttributes.h
    \\brief Definition of ClassicMtgDecoder Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 2020-09-22
*/

#include "ClassicMtgDecoderAttributes.h"
#include "MagicsParameter.h"
#include "ParameterSettings.h"

using namespace magics;

ClassicMtgDecoderAttributes::ClassicMtgDecoderAttributes():
	database_(ParameterManager::getString("metgram_database")),
	param_(ParameterManager::getString("metgram_parameter")),
	latitude_(ParameterManager::getDouble("metgram_latitude")),
	param_scaling_(ParameterManager::getDouble("metgram_parameter_scaling_factor")),
	param_offset_(ParameterManager::getDouble("metgram_parameter_offset")),
	param_title_(ParameterManager::getString("metgram_parameter_title")),
	longitude_(ParameterManager::getDouble("metgram_longitude")),
	date_(ParameterManager::getString("metgram_date")),
	time_(ParameterManager::getString("metgram_time")),
	long_title_(ParameterManager::getBool("metgram_long_title")),
	station_(ParameterManager::getString("metgram_station_name")),
	height_(ParameterManager::getDouble("metgram_station_height")),
	correction_(ParameterManager::getBool("metgram_temperature_correction"))
	
	 
{
} 


ClassicMtgDecoderAttributes::~ClassicMtgDecoderAttributes()
{
	
}

    
void ClassicMtgDecoderAttributes::set(const std::map<string, string>& params)
{
	vector<string> prefix(1);
	int i = 0;
	prefix[i++] = "metgram";
	
	setAttribute(prefix, "metgram_database", database_, params);
	setAttribute(prefix, "metgram_parameter", param_, params);
	setAttribute(prefix, "metgram_latitude", latitude_, params);
	setAttribute(prefix, "metgram_parameter_scaling_factor", param_scaling_, params);
	setAttribute(prefix, "metgram_parameter_offset", param_offset_, params);
	setAttribute(prefix, "metgram_parameter_title", param_title_, params);
	setAttribute(prefix, "metgram_longitude", longitude_, params);
	setAttribute(prefix, "metgram_date", date_, params);
	setAttribute(prefix, "metgram_time", time_, params);
	setAttribute(prefix, "metgram_long_title", long_title_, params);
	setAttribute(prefix, "metgram_station_name", station_, params);
	setAttribute(prefix, "metgram_station_height", height_, params);
	setAttribute(prefix, "metgram_temperature_correction", correction_, params);
	
	
}

void ClassicMtgDecoderAttributes::copy(const ClassicMtgDecoderAttributes& other)
{
	database_ = other.database_;
	param_ = other.param_;
	latitude_ = other.latitude_;
	param_scaling_ = other.param_scaling_;
	param_offset_ = other.param_offset_;
	param_title_ = other.param_title_;
	longitude_ = other.longitude_;
	date_ = other.date_;
	time_ = other.time_;
	long_title_ = other.long_title_;
	station_ = other.station_;
	height_ = other.height_;
	correction_ = other.correction_;
	
} 


bool ClassicMtgDecoderAttributes::accept(const string& node)
{	
	
	if ( magCompare(node, "metgram")  )
		return true;
	
	return false;
}

void ClassicMtgDecoderAttributes::set(const XmlNode& node)
{
	bool apply = false;

	if ( this->accept(node.name()) == false ) 
		return;

	if ( magCompare(node.name(), "metgram")  )
		apply = true;
	

	if ( apply )
		set(node.attributes());
	else {
		
	}
	for (auto &elt : node.elements())
	{
		
	}
}

void ClassicMtgDecoderAttributes::print(ostream& out)  const
{
	out << "Attributes[";
	out << " database = " <<  database_;
	out << " param = " <<  param_;
	out << " latitude = " <<  latitude_;
	out << " param_scaling = " <<  param_scaling_;
	out << " param_offset = " <<  param_offset_;
	out << " param_title = " <<  param_title_;
	out << " longitude = " <<  longitude_;
	out << " date = " <<  date_;
	out << " time = " <<  time_;
	out << " long_title = " <<  long_title_;
	out << " station = " <<  station_;
	out << " height = " <<  height_;
	out << " correction = " <<  correction_;
	
	out << "]" << "\n";
}

void ClassicMtgDecoderAttributes::toxml(ostream& out)  const
{
	out <<  "\"metgram\""; 
	out << ", \"metgram_database\":";
	niceprint(out,database_);
	out << ", \"metgram_parameter\":";
	niceprint(out,param_);
	out << ", \"metgram_latitude\":";
	niceprint(out,latitude_);
	out << ", \"metgram_parameter_scaling_factor\":";
	niceprint(out,param_scaling_);
	out << ", \"metgram_parameter_offset\":";
	niceprint(out,param_offset_);
	out << ", \"metgram_parameter_title\":";
	niceprint(out,param_title_);
	out << ", \"metgram_longitude\":";
	niceprint(out,longitude_);
	out << ", \"metgram_date\":";
	niceprint(out,date_);
	out << ", \"metgram_time\":";
	niceprint(out,time_);
	out << ", \"metgram_long_title\":";
	niceprint(out,long_title_);
	out << ", \"metgram_station_name\":";
	niceprint(out,station_);
	out << ", \"metgram_station_height\":";
	niceprint(out,height_);
	out << ", \"metgram_temperature_correction\":";
	niceprint(out,correction_);
	
}

static MagicsParameter<string> metgram_database("metgram_database", "/vol/epsgram/data/spotbase/epsdb", "");
static MagicsParameter<string> metgram_parameter("metgram_parameter", "", "");
static MagicsParameter<double> metgram_latitude("metgram_latitude", 0, "");
static MagicsParameter<double> metgram_parameter_scaling_factor("metgram_parameter_scaling_factor", 1, "");
static MagicsParameter<double> metgram_parameter_offset("metgram_parameter_offset", 0, "");
static MagicsParameter<string> metgram_parameter_title("metgram_parameter_title", "", "");
static MagicsParameter<double> metgram_longitude("metgram_longitude", 0, "");
static MagicsParameter<string> metgram_date("metgram_date", "-1", "");
static MagicsParameter<string> metgram_time("metgram_time", "0000", "");
static MagicsParameter<string> metgram_long_title("metgram_long_title", "off", "");
static MagicsParameter<string> metgram_station_name("metgram_station_name", "", "");
static MagicsParameter<double> metgram_station_height("metgram_station_height", -1., "");
static MagicsParameter<string> metgram_temperature_correction("metgram_temperature_correction", "yes", "");

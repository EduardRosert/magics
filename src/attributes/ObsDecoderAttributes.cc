
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file ObsDecoderAttributes.h
    \\brief Definition of ObsDecoder Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 2020-10-14
*/

#include "ObsDecoderAttributes.h"
#include "MagicsParameter.h"
#include "ParameterSettings.h"

using namespace magics;

ObsDecoderAttributes::ObsDecoderAttributes():
	file_name_(ParameterManager::getString("obs_input_file_name")),
	level_(ParameterManager::getInt("obs_level")),
	level2_(ParameterManager::getInt("obs_level_2")),
	tolerance_(ParameterManager::getInt("obs_level_tolerance")),
	types_(ParameterManager::getStringArray("obs_type_list"))
	
	 
{
} 


ObsDecoderAttributes::~ObsDecoderAttributes()
{
	
}

    
void ObsDecoderAttributes::set(const std::map<string, string>& params)
{
	vector<string> prefix(1);
	int i = 0;
	prefix[i++] = "obs";
	
	setAttribute(prefix, "obs_input_file_name", file_name_, params);
	setAttribute(prefix, "obs_level", level_, params);
	setAttribute(prefix, "obs_level_2", level2_, params);
	setAttribute(prefix, "obs_level_tolerance", tolerance_, params);
	setAttribute(prefix, "obs_type_list", types_, params);
	
	
}

void ObsDecoderAttributes::copy(const ObsDecoderAttributes& other)
{
	file_name_ = other.file_name_;
	level_ = other.level_;
	level2_ = other.level2_;
	tolerance_ = other.tolerance_;
	types_ = other.types_;
	
} 


bool ObsDecoderAttributes::accept(const string& node)
{	
	
	if ( magCompare(node, "bufr")  )
		return true;
	
	return false;
}

void ObsDecoderAttributes::set(const XmlNode& node)
{
	bool apply = false;

	if ( this->accept(node.name()) == false ) 
		return;

	if ( magCompare(node.name(), "bufr")  )
		apply = true;
	

	if ( apply )
		set(node.attributes());
	else {
		
	}
	for (auto &elt : node.elements())
	{
		
	}
}

void ObsDecoderAttributes::print(ostream& out)  const
{
	out << "Attributes[";
	out << " file_name = " <<  file_name_;
	out << " level = " <<  level_;
	out << " level2 = " <<  level2_;
	out << " tolerance = " <<  tolerance_;
	out << " types = " <<  types_;
	
	out << "]" << "\n";
}

void ObsDecoderAttributes::toxml(ostream& out)  const
{
	out <<  "\"bufr\""; 
	out << ", \"obs_input_file_name\":";
	niceprint(out,file_name_);
	out << ", \"obs_level\":";
	niceprint(out,level_);
	out << ", \"obs_level_2\":";
	niceprint(out,level2_);
	out << ", \"obs_level_tolerance\":";
	niceprint(out,tolerance_);
	out << ", \"obs_type_list\":";
	niceprint(out,types_);
	
}

static MagicsParameter<string> obs_input_file_name("obs_input_file_name", "", "");
static MagicsParameter<int> obs_level("obs_level", 500, "");
static MagicsParameter<int> obs_level_2("obs_level_2", 1000, "");
static MagicsParameter<int> obs_level_tolerance("obs_level_tolerance", 0, "");
static MagicsParameter<stringarray> obs_type_list("obs_type_list", stringarray(), "");

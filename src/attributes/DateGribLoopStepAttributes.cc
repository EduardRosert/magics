
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file DateGribLoopStepAttributes.h
    \\brief Definition of DateGribLoopStep Attributes class.

    This file is automatically generated.
    Do Not Edit!
*/

#include "DateGribLoopStepAttributes.h"
#include "MagicsParameter.h"
#include "ParameterSettings.h"

using namespace magics;

DateGribLoopStepAttributes::DateGribLoopStepAttributes():
	span_(ParameterManager::getDouble("grib_loop_step_span"))
	,
	address_mode_(MagTranslator<string, GribAddressMode>().magics("grib_file_address_mode"))
	 
{
} 


DateGribLoopStepAttributes::~DateGribLoopStepAttributes()
{
	
}

    
void DateGribLoopStepAttributes::set(const std::map<string, string>& params)
{
	vector<string> prefix(2);
	int i = 0;
	prefix[i++] = "grib";
	prefix[i++] = "grib_loop_step";
	
	setAttribute(prefix, "grib_loop_step_span", span_, params);
	
	setMember(prefix, "grib_file_address_mode", address_mode_, params);
	
}

void DateGribLoopStepAttributes::copy(const DateGribLoopStepAttributes& other)
{
	span_ = other.span_;
	address_mode_ = unique_ptr<GribAddressMode>(other.address_mode_->clone());
	
} 


bool DateGribLoopStepAttributes::accept(const string& node)
{	
	
	if ( magCompare(node, "loopondate")  )
		return true;
	if ( acceptNode(node, address_mode_) )
		return true;
	
	return false;
}

void DateGribLoopStepAttributes::set(const XmlNode& node)
{
	bool apply = false;

	if ( this->accept(node.name()) == false ) 
		return;

	if ( magCompare(node.name(), "loopondate")  )
		apply = true;
	

	if ( apply )
		set(node.attributes());
	else {
		setMember(node.name(), address_mode_, node);
		
	}
	for (auto &elt : node.elements())
	{
		setMember(elt->name(), address_mode_, *elt); 
		
	}
}

void DateGribLoopStepAttributes::print(ostream& out)  const
{
	out << "Attributes[";
	out << " span = " <<  span_;
	out << " address_mode = " <<  *address_mode_;
	
	out << "]" << "\n";
}

void DateGribLoopStepAttributes::toxml(ostream& out)  const
{
	out <<  "\"loopondate\""; 
	out << ", \"grib_loop_step_span\":";
	niceprint(out,span_);
	out << ", \"grib_file_address_mode\":";
	address_mode_->toxml(out);
	
}

static MagicsParameter<double> grib_loop_step_span("grib_loop_step_span", 3, "");
static MagicsParameter<string> grib_file_address_mode("grib_file_address_mode", "record", ""); 
#include "GribAddressMode.h"
static SimpleObjectMaker<GribAddressRecordMode , GribAddressMode> record_GribAddressRecordMode("record");
static SimpleObjectMaker<GribAddressByteMode , GribAddressMode> byte_offset_GribAddressByteMode("byte_offset");

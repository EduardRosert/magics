
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file GeoRectangularProjectionAttributes.h
    \\brief Definition of GeoRectangularProjection Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 2020-09-22
*/

#include "GeoRectangularProjectionAttributes.h"
#include "MagicsParameter.h"
#include "ParameterSettings.h"

using namespace magics;

GeoRectangularProjectionAttributes::GeoRectangularProjectionAttributes():
	min_latitude_(ParameterManager::getDouble("subpage_lower_left_latitude")),
	min_longitude_(ParameterManager::getDouble("subpage_lower_left_longitude")),
	max_latitude_(ParameterManager::getDouble("subpage_upper_right_latitude")),
	max_longitude_(ParameterManager::getDouble("subpage_upper_right_longitude")),
	min_area_(ParameterManager::getDouble("subpage_minimal_area"))
	
	 
{
} 


GeoRectangularProjectionAttributes::~GeoRectangularProjectionAttributes()
{
	
}

    
void GeoRectangularProjectionAttributes::set(const std::map<string, string>& params)
{
	vector<string> prefix(1);
	int i = 0;
	prefix[i++] = "subpage";
	
	setAttribute(prefix, "subpage_lower_left_latitude", min_latitude_, params);
	setAttribute(prefix, "subpage_lower_left_longitude", min_longitude_, params);
	setAttribute(prefix, "subpage_upper_right_latitude", max_latitude_, params);
	setAttribute(prefix, "subpage_upper_right_longitude", max_longitude_, params);
	setAttribute(prefix, "subpage_minimal_area", min_area_, params);
	
	
}

void GeoRectangularProjectionAttributes::copy(const GeoRectangularProjectionAttributes& other)
{
	min_latitude_ = other.min_latitude_;
	min_longitude_ = other.min_longitude_;
	max_latitude_ = other.max_latitude_;
	max_longitude_ = other.max_longitude_;
	min_area_ = other.min_area_;
	
} 


bool GeoRectangularProjectionAttributes::accept(const string& node)
{	
	
	if ( magCompare(node, "cylindrical")  )
		return true;
	
	return false;
}

void GeoRectangularProjectionAttributes::set(const XmlNode& node)
{
	bool apply = false;

	if ( this->accept(node.name()) == false ) 
		return;

	if ( magCompare(node.name(), "cylindrical")  )
		apply = true;
	

	if ( apply )
		set(node.attributes());
	else {
		
	}
	for (auto &elt : node.elements())
	{
		
	}
}

void GeoRectangularProjectionAttributes::print(ostream& out)  const
{
	out << "Attributes[";
	out << " min_latitude = " <<  min_latitude_;
	out << " min_longitude = " <<  min_longitude_;
	out << " max_latitude = " <<  max_latitude_;
	out << " max_longitude = " <<  max_longitude_;
	out << " min_area = " <<  min_area_;
	
	out << "]" << "\n";
}

void GeoRectangularProjectionAttributes::toxml(ostream& out)  const
{
	out <<  "\"cylindrical\""; 
	out << ", \"subpage_lower_left_latitude\":";
	niceprint(out,min_latitude_);
	out << ", \"subpage_lower_left_longitude\":";
	niceprint(out,min_longitude_);
	out << ", \"subpage_upper_right_latitude\":";
	niceprint(out,max_latitude_);
	out << ", \"subpage_upper_right_longitude\":";
	niceprint(out,max_longitude_);
	out << ", \"subpage_minimal_area\":";
	niceprint(out,min_area_);
	
}

static MagicsParameter<double> subpage_lower_left_latitude("subpage_lower_left_latitude", -90.0, "");
static MagicsParameter<double> subpage_lower_left_longitude("subpage_lower_left_longitude", -180.0, "");
static MagicsParameter<double> subpage_upper_right_latitude("subpage_upper_right_latitude", 90.0, "");
static MagicsParameter<double> subpage_upper_right_longitude("subpage_upper_right_longitude", 180.0, "");
static MagicsParameter<double> subpage_minimal_area("subpage_minimal_area", 0.1, "");

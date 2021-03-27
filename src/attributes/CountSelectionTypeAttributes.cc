
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file CountSelectionTypeAttributes.h
    \\brief Definition of CountSelectionType Attributes class.

    This file is automatically generated.
    Do Not Edit!
*/

#include "CountSelectionTypeAttributes.h"
#include "MagicsParameter.h"
#include "ParameterSettings.h"

using namespace magics;

CountSelectionTypeAttributes::CountSelectionTypeAttributes():
	levelCount_(ParameterManager::getInt("contour_level_count")),
	tolerance_(ParameterManager::getInt("contour_level_tolerance")),
	reference_(ParameterManager::getDouble("contour_reference_level"))
	
	 
{
} 


CountSelectionTypeAttributes::~CountSelectionTypeAttributes()
{
	
}

    
void CountSelectionTypeAttributes::set(const std::map<string, string>& params)
{
	vector<string> prefix(3);
	int i = 0;
	prefix[i++] = "contour";
	prefix[i++] = "contour";
	prefix[i++] = "contour_level";
	
	setAttribute(prefix, "contour_level_count", levelCount_, params);
	setAttribute(prefix, "contour_level_tolerance", tolerance_, params);
	setAttribute(prefix, "contour_reference_level", reference_, params);
	
	
}

void CountSelectionTypeAttributes::copy(const CountSelectionTypeAttributes& other)
{
	levelCount_ = other.levelCount_;
	tolerance_ = other.tolerance_;
	reference_ = other.reference_;
	
} 


bool CountSelectionTypeAttributes::accept(const string& node)
{	
	
	if ( magCompare(node, "count")  )
		return true;
	
	return false;
}

void CountSelectionTypeAttributes::set(const XmlNode& node)
{
	bool apply = false;

	if ( this->accept(node.name()) == false ) 
		return;

	if ( magCompare(node.name(), "count")  )
		apply = true;
	

	if ( apply )
		set(node.attributes());
	else {
		
	}
	for (auto &elt : node.elements())
	{
		
	}
}

void CountSelectionTypeAttributes::print(ostream& out)  const
{
	out << "Attributes[";
	out << " levelCount = " <<  levelCount_;
	out << " tolerance = " <<  tolerance_;
	out << " reference = " <<  reference_;
	
	out << "]" << "\n";
}

void CountSelectionTypeAttributes::toxml(ostream& out)  const
{
	out <<  "\"count\""; 
	out << ", \"contour_level_count\":";
	niceprint(out,levelCount_);
	out << ", \"contour_level_tolerance\":";
	niceprint(out,tolerance_);
	out << ", \"contour_reference_level\":";
	niceprint(out,reference_);
	
}

static MagicsParameter<int> contour_level_count("contour_level_count", 10, "");
static MagicsParameter<int> contour_level_tolerance("contour_level_tolerance", 2, "");
static MagicsParameter<double> contour_reference_level("contour_reference_level", 0.0, "");

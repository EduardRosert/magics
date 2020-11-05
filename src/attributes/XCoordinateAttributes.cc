
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file XCoordinateAttributes.h
    \\brief Definition of XCoordinate Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 2020-10-14
*/

#include "XCoordinateAttributes.h"
#include "MagicsParameter.h"
#include "ParameterSettings.h"

using namespace magics;

XCoordinateAttributes::XCoordinateAttributes()
	
	 
{
} 


XCoordinateAttributes::~XCoordinateAttributes()
{
	
}

    
void XCoordinateAttributes::set(const std::map<string, string>& params)
{
	vector<string> prefix(1);
	int i = 0;
	prefix[i++] = "";
	
	
	
}

void XCoordinateAttributes::copy(const XCoordinateAttributes& other)
{
	
} 


bool XCoordinateAttributes::accept(const string& node)
{	
	
	if ( magCompare(node, "x_regular")  )
		return true;
	
	return false;
}

void XCoordinateAttributes::set(const XmlNode& node)
{
	bool apply = false;

	if ( this->accept(node.name()) == false ) 
		return;

	if ( magCompare(node.name(), "x_regular")  )
		apply = true;
	

	if ( apply )
		set(node.attributes());
	else {
		
	}
	for (auto &elt : node.elements())
	{
		
	}
}

void XCoordinateAttributes::print(ostream& out)  const
{
	out << "Attributes[";
	
	out << "]" << "\n";
}

void XCoordinateAttributes::toxml(ostream& out)  const
{
	out <<  "\"x_regular\""; 
	
}


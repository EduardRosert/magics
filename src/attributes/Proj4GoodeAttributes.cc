
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file Proj4GoodeAttributes.h
    \\brief Definition of Proj4Goode Attributes class.

    This file is automatically generated.
    Do Not Edit!
*/

#include "Proj4GoodeAttributes.h"
#include "MagicsParameter.h"
#include "ParameterSettings.h"

using namespace magics;

Proj4GoodeAttributes::Proj4GoodeAttributes()
	
	
{
}


Proj4GoodeAttributes::~Proj4GoodeAttributes()
{

}


void Proj4GoodeAttributes::set(const std::map<string, string>& params)
{
	vector<string> prefix(1);
	int i = 0;
	prefix[i++] = "subpage";
	
	
	
}

void Proj4GoodeAttributes::copy(const Proj4GoodeAttributes& other)
{
	
}


bool Proj4GoodeAttributes::accept(const string& node)
{

	if ( magCompare(node, "")  )
		return true;
	
	return false;
}

void Proj4GoodeAttributes::set(const XmlNode& node)
{
	bool apply = false;

	if ( this->accept(node.name()) == false )
		return;

	if ( magCompare(node.name(), "")  )
		apply = true;
	

	if ( apply )
		set(node.attributes());
	else {
		
	}
	for (auto &elt : node.elements())
	{
		
	}
}

void Proj4GoodeAttributes::print(ostream& out)  const
{
	out << "Attributes[";
	
	out << "]" << "\n";
}

void Proj4GoodeAttributes::toxml(ostream& out)  const
{
	out <<  "\"\"";
	
}


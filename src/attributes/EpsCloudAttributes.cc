
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file EpsCloudAttributes.h
    \\brief Definition of EpsCloud Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 2020-09-22
*/

#include "EpsCloudAttributes.h"
#include "MagicsParameter.h"
#include "ParameterSettings.h"

using namespace magics;

EpsCloudAttributes::EpsCloudAttributes():
	
	colour_(MagTranslator<string, Colour>().magics("eps_rose_cloud_colour")),
	border_colour_(MagTranslator<string, Colour>().magics("eps_rose_cloud_border_colour"))
	 
{
} 


EpsCloudAttributes::~EpsCloudAttributes()
{
	
}

    
void EpsCloudAttributes::set(const std::map<string, string>& params)
{
	vector<string> prefix(2);
	int i = 0;
	prefix[i++] = "eps";
	prefix[i++] = "eps_rose_cloud";
	
	
	setMember(prefix, "eps_rose_cloud_colour", colour_, params);
	setMember(prefix, "eps_rose_cloud_border_colour", border_colour_, params);
	
}

void EpsCloudAttributes::copy(const EpsCloudAttributes& other)
{
	colour_ = unique_ptr<Colour>(other.colour_->clone());
	border_colour_ = unique_ptr<Colour>(other.border_colour_->clone());
	
} 


bool EpsCloudAttributes::accept(const string& node)
{	
	
	if ( magCompare(node, "epscloud")  )
		return true;
	
	return false;
}

void EpsCloudAttributes::set(const XmlNode& node)
{
	bool apply = false;

	if ( this->accept(node.name()) == false ) 
		return;

	if ( magCompare(node.name(), "epscloud")  )
		apply = true;
	

	if ( apply )
		set(node.attributes());
	else {
		
	}
	for (auto &elt : node.elements())
	{
		
	}
}

void EpsCloudAttributes::print(ostream& out)  const
{
	out << "Attributes[";
	out << " colour = " <<  *colour_;
	out << " border_colour = " <<  *border_colour_;
	
	out << "]" << "\n";
}

void EpsCloudAttributes::toxml(ostream& out)  const
{
	out <<  "\"epscloud\""; 
	out << ", \"eps_rose_cloud_colour\":";
	niceprint(out, *colour_);
	out << ", \"eps_rose_cloud_border_colour\":";
	niceprint(out, *border_colour_);
	
}

static MagicsParameter<string> eps_rose_cloud_colour("eps_rose_cloud_colour", "black", ""); 
static MagicsParameter<string> eps_rose_cloud_border_colour("eps_rose_cloud_border_colour", "none", ""); 

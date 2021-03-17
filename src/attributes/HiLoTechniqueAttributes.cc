
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file HiLoTechniqueAttributes.h
    \\brief Definition of HiLoTechnique Attributes class.

    This file is automatically generated.
    Do Not Edit!
*/

#include "HiLoTechniqueAttributes.h"
#include "MagicsParameter.h"
#include "ParameterSettings.h"

using namespace magics;

HiLoTechniqueAttributes::HiLoTechniqueAttributes():
	contour_hilo_height_(ParameterManager::getDouble("contour_hilo_height")),
	format_(ParameterManager::getString("contour_hilo_format"))
	,
	hi_colour_(MagTranslator<string, Colour>().magics("contour_hi_colour")),
	lo_colour_(MagTranslator<string, Colour>().magics("contour_lo_colour"))
	
{
}


HiLoTechniqueAttributes::~HiLoTechniqueAttributes()
{

}


void HiLoTechniqueAttributes::set(const std::map<string, string>& params)
{
	vector<string> prefix(2);
	int i = 0;
	prefix[i++] = "contour";
	prefix[i++] = "contour_hilo";
	
	setAttribute(prefix, "contour_hilo_height", contour_hilo_height_, params);
	setAttribute(prefix, "contour_hilo_format", format_, params);
	
	setMember(prefix, "contour_hi_colour", hi_colour_, params);
	setMember(prefix, "contour_lo_colour", lo_colour_, params);
	
}

void HiLoTechniqueAttributes::copy(const HiLoTechniqueAttributes& other)
{
	contour_hilo_height_ = other.contour_hilo_height_;
	format_ = other.format_;
	hi_colour_ = unique_ptr<Colour>(other.hi_colour_->clone());
	lo_colour_ = unique_ptr<Colour>(other.lo_colour_->clone());
	
}


bool HiLoTechniqueAttributes::accept(const string& node)
{

	if ( magCompare(node, "hilo")  )
		return true;
	
	return false;
}

void HiLoTechniqueAttributes::set(const XmlNode& node)
{
	bool apply = false;

	if ( this->accept(node.name()) == false )
		return;

	if ( magCompare(node.name(), "hilo")  )
		apply = true;
	

	if ( apply )
		set(node.attributes());
	else {
		
	}
	for (auto &elt : node.elements())
	{
		
	}
}

void HiLoTechniqueAttributes::print(ostream& out)  const
{
	out << "Attributes[";
	out << " contour_hilo_height = " <<  contour_hilo_height_;
	out << " format = " <<  format_;
	out << " hi_colour = " <<  *hi_colour_;
	out << " lo_colour = " <<  *lo_colour_;
	
	out << "]" << "\n";
}

void HiLoTechniqueAttributes::toxml(ostream& out)  const
{
	out <<  "\"hilo\"";
	out << ", \"contour_hilo_height\":";
	niceprint(out,contour_hilo_height_);
	out << ", \"contour_hilo_format\":";
	niceprint(out,format_);
	out << ", \"contour_hi_colour\":";
	niceprint(out, *hi_colour_);
	out << ", \"contour_lo_colour\":";
	niceprint(out, *lo_colour_);
	
}

static MagicsParameter<double> contour_hilo_height("contour_hilo_height", 0.4);
static MagicsParameter<string> contour_hilo_format("contour_hilo_format", "(automatic)");
static MagicsParameter<string> contour_hi_colour("contour_hi_colour", "blue");
static MagicsParameter<string> contour_lo_colour("contour_lo_colour", "blue");

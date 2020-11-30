
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file ImageListColourTechniqueAttributes.h
    \\brief Definition of ImageListColourTechnique Attributes class.

    This file is automatically generated.
    Do Not Edit!
*/

#include "ImageListColourTechniqueAttributes.h"
#include "MagicsParameter.h"
#include "ParameterSettings.h"

using namespace magics;

ImageListColourTechniqueAttributes::ImageListColourTechniqueAttributes():
	values_(ParameterManager::getStringArray("image_colour_table"))
	
	 
{
} 


ImageListColourTechniqueAttributes::~ImageListColourTechniqueAttributes()
{
	
}

    
void ImageListColourTechniqueAttributes::set(const std::map<string, string>& params)
{
	vector<string> prefix(1);
	int i = 0;
	prefix[i++] = "image";
	
	setAttribute(prefix, "image_colour_table", values_, params);
	
	
}

void ImageListColourTechniqueAttributes::copy(const ImageListColourTechniqueAttributes& other)
{
	values_ = other.values_;
	
} 


bool ImageListColourTechniqueAttributes::accept(const string& node)
{	
	
	if ( magCompare(node, "list")  )
		return true;
	
	return false;
}

void ImageListColourTechniqueAttributes::set(const XmlNode& node)
{
	bool apply = false;

	if ( this->accept(node.name()) == false ) 
		return;

	if ( magCompare(node.name(), "list")  )
		apply = true;
	

	if ( apply )
		set(node.attributes());
	else {
		
	}
	for (auto &elt : node.elements())
	{
		
	}
}

void ImageListColourTechniqueAttributes::print(ostream& out)  const
{
	out << "Attributes[";
	out << " values = " <<  values_;
	
	out << "]" << "\n";
}

void ImageListColourTechniqueAttributes::toxml(ostream& out)  const
{
	out <<  "\"list\""; 
	out << ", \"image_colour_table\":";
	niceprint(out,values_);
	
}

static MagicsParameter<stringarray> image_colour_table("image_colour_table", stringarray(), "");

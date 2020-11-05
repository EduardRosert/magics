
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file CalculateColourTechniqueAttributes.h
    \\brief Definition of CalculateColourTechnique Attributes class.

    This file is automatically generated.
    Do Not Edit!
*/

#include "MagRequest.h" 
#include "CalculateColourTechniqueWrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"

using namespace magics;


CalculateColourTechniqueWrapper::CalculateColourTechniqueWrapper(): calculatecolourtechnique_(new CalculateColourTechnique())

{

	
	
	ColourTechniqueWrapper::object(calculatecolourtechnique_);
	
	
} 
CalculateColourTechniqueWrapper::CalculateColourTechniqueWrapper(CalculateColourTechnique* calculatecolourtechnique): calculatecolourtechnique_(calculatecolourtechnique)
{
	
	
	ColourTechniqueWrapper::object(calculatecolourtechnique_);
	
} 

CalculateColourTechniqueWrapper::~CalculateColourTechniqueWrapper()
{
	
}

void CalculateColourTechniqueWrapper::set(const MagRequest& request)
{
	
	
	
	ColourTechniqueWrapper::set(request);
	

	if  (request.countValues("CONTOUR_SHADE_COLOUR_DIRECTION") ) {
		string direction_value = request("CONTOUR_SHADE_COLOUR_DIRECTION");
		calculatecolourtechnique_->direction_ = direction_value;
		}
	
	if  (request.countValues("CONTOUR_SHADE_MAX_LEVEL_COLOUR") ) {
		string max_value = request("CONTOUR_SHADE_MAX_LEVEL_COLOUR");
		calculatecolourtechnique_->max_ = unique_ptr<Colour>(MagTranslator<string, Colour>()(max_value));
	}
		
	if  (request.countValues("CONTOUR_SHADE_MIN_LEVEL_COLOUR") ) {
		string min_value = request("CONTOUR_SHADE_MIN_LEVEL_COLOUR");
		calculatecolourtechnique_->min_ = unique_ptr<Colour>(MagTranslator<string, Colour>()(min_value));
	}
		
	
}

void CalculateColourTechniqueWrapper::print(ostream& out)  const
{
	out << "CalculateColourTechniqueWrapper[]";
}


    






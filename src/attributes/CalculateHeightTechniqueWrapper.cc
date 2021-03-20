
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file CalculateHeightTechniqueAttributes.h
    \\brief Definition of CalculateHeightTechnique Attributes class.

    This file is automatically generated.
    Do Not Edit!

*/

#include "MagRequest.h"
#include "CalculateHeightTechniqueWrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"
#include "MagicsGlobal.h"

using namespace magics;


CalculateHeightTechniqueWrapper::CalculateHeightTechniqueWrapper(): calculateheighttechnique_(new CalculateHeightTechnique())

{


	
	HeightTechniqueWrapper::object(calculateheighttechnique_);
	

}
CalculateHeightTechniqueWrapper::CalculateHeightTechniqueWrapper(CalculateHeightTechnique* calculateheighttechnique): calculateheighttechnique_(calculateheighttechnique)
{

	
	HeightTechniqueWrapper::object(calculateheighttechnique_);
	
}

CalculateHeightTechniqueWrapper::~CalculateHeightTechniqueWrapper()
{

}

void CalculateHeightTechniqueWrapper::set(const MagRequest& request)
{

	

	HeightTechniqueWrapper::set(request);
	

	
	
}

void CalculateHeightTechniqueWrapper::print(ostream& out)  const
{
	out << "CalculateHeightTechniqueWrapper[]";
}



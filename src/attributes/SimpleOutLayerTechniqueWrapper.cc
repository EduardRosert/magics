
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file SimpleOutLayerTechniqueAttributes.h
    \\brief Definition of SimpleOutLayerTechnique Attributes class.

    This file is automatically generated.
    Do Not Edit!

*/

#include "MagRequest.h"
#include "SimpleOutLayerTechniqueWrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"
#include "MagicsGlobal.h"

using namespace magics;



SimpleOutLayerTechniqueWrapper::SimpleOutLayerTechniqueWrapper(): simpleoutlayertechnique_(new SimpleOutLayerTechnique())


{


	
	NoOutLayerTechniqueWrapper::object(simpleoutlayertechnique_);
	

}
SimpleOutLayerTechniqueWrapper::SimpleOutLayerTechniqueWrapper(SimpleOutLayerTechnique* simpleoutlayertechnique): simpleoutlayertechnique_(simpleoutlayertechnique)
{

	
	NoOutLayerTechniqueWrapper::object(simpleoutlayertechnique_);
	
}

SimpleOutLayerTechniqueWrapper::~SimpleOutLayerTechniqueWrapper()
{

}

void SimpleOutLayerTechniqueWrapper::set(const MagRequest& request)
{

	

	NoOutLayerTechniqueWrapper::set(request);
	

	
	
}

void SimpleOutLayerTechniqueWrapper::print(ostream& out)  const
{
	out << "SimpleOutLayerTechniqueWrapper[]";
}



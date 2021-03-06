
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file PolyShadingTechniqueAttributes.h
    \\brief Definition of PolyShadingTechnique Attributes class.

    This file is automatically generated.
    Do Not Edit!

*/

#include "MagRequest.h"
#include "PolyShadingTechniqueWrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"
#include "MagicsGlobal.h"

using namespace magics;



PolyShadingTechniqueWrapper::PolyShadingTechniqueWrapper(): polyshadingtechnique_(new PolyShadingTechnique())


{


	
	ShadingTechniqueWrapper::object(polyshadingtechnique_);
	

}
PolyShadingTechniqueWrapper::PolyShadingTechniqueWrapper(PolyShadingTechnique* polyshadingtechnique): polyshadingtechnique_(polyshadingtechnique)
{

	
	ShadingTechniqueWrapper::object(polyshadingtechnique_);
	
}

PolyShadingTechniqueWrapper::~PolyShadingTechniqueWrapper()
{

}

void PolyShadingTechniqueWrapper::set(const MagRequest& request)
{

	

	ShadingTechniqueWrapper::set(request);
	

	
	
		string method_value = request.countValues("CONTOUR_SHADE_METHOD") ?  (string) request("CONTOUR_SHADE_METHOD") : "dot";
	MagLog::debug() << " CONTOUR_SHADE_METHOD set to " << method_value << endl;
	PolyShadingMethodWrapper* method_wrapper = 0;
	try
	{
		method_wrapper = SimpleFactory<PolyShadingMethodWrapper>::create(method_value);
	}
	 catch (NoFactoryException&) {
		if (MagicsGlobal::strict()) {
            throw;
        }
		MagLog::warning() << "[" << method_value << "] is not a valid value for method: reset to default -> [dot]" << endl;
		method_wrapper = SimpleFactory<PolyShadingMethodWrapper>::create("dot");
	}
	method_wrapper->set(request);
	polyshadingtechnique_->method_ =  unique_ptr<PolyShadingMethod>(method_wrapper->object());
	delete method_wrapper;
	
}

void PolyShadingTechniqueWrapper::print(ostream& out)  const
{
	out << "PolyShadingTechniqueWrapper[]";
}


#include "PolyShadingMethodWrapper.h"

static SimpleObjectMaker<PolyShadingMethodWrapper> PolyShadingTechnique_contour_shade_method_area_Wrapper("area");


#include "PolyShadingMethodWrapper.h"

static SimpleObjectMaker<PolyShadingMethodWrapper> PolyShadingTechnique_contour_shade_method_area_fill_Wrapper("area_fill");


#include "PolyShadingMethodWrapper.h"

static SimpleObjectMaker<PolyShadingMethodWrapper> PolyShadingTechnique_contour_shade_method_solid_Wrapper("solid");


#include "DotPolyShadingMethodWrapper.h"
static SimpleObjectMaker<DotPolyShadingMethod, PolyShadingMethod> PolyShadingTechnique_contour_shade_method_dot ("dot");
static SimpleObjectMaker<DotPolyShadingMethodWrapper, PolyShadingMethodWrapper> PolyShadingTechnique_contour_shade_method_dot_wrapper ("dot");


#include "HatchPolyShadingMethodWrapper.h"
static SimpleObjectMaker<HatchPolyShadingMethod, PolyShadingMethod> PolyShadingTechnique_contour_shade_method_hatch ("hatch");
static SimpleObjectMaker<HatchPolyShadingMethodWrapper, PolyShadingMethodWrapper> PolyShadingTechnique_contour_shade_method_hatch_wrapper ("hatch");




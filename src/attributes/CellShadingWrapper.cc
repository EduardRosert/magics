
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file CellShadingAttributes.h
    \\brief Definition of CellShading Attributes class.

    This file is automatically generated.
    Do Not Edit!

*/

#include "MagRequest.h"
#include "CellShadingWrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"
#include "MagicsGlobal.h"

using namespace magics;



CellShadingWrapper::CellShadingWrapper(): cellshading_(new CellShading())


{


	
	ShadingTechniqueWrapper::object(cellshading_);
	

}
CellShadingWrapper::CellShadingWrapper(CellShading* cellshading): cellshading_(cellshading)
{

	
	ShadingTechniqueWrapper::object(cellshading_);
	
}

CellShadingWrapper::~CellShadingWrapper()
{

}

void CellShadingWrapper::set(const MagRequest& request)
{

	

	ShadingTechniqueWrapper::set(request);
	

	if  (request.countValues("CONTOUR_SHADE_CELL_RESOLUTION") ) {
		double resolution_value = request("CONTOUR_SHADE_CELL_RESOLUTION");
		cellshading_->resolution_ = resolution_value;
		}
	if  (request.countValues("CONTOUR_SHADE_CELL_METHOD") ) {
		string method_value = request("CONTOUR_SHADE_CELL_METHOD");
		cellshading_->method_ = method_value;
		}
	if  (request.countValues("CONTOUR_SHADE_CELL_RESOLUTION_METHOD") ) {
		string resolution_method_value = request("CONTOUR_SHADE_CELL_RESOLUTION_METHOD");
		cellshading_->resolution_method_ = resolution_method_value;
		}
	
	
}

void CellShadingWrapper::print(ostream& out)  const
{
	out << "CellShadingWrapper[]";
}



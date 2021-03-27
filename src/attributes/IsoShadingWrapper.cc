
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file IsoShadingAttributes.h
    \\brief Definition of IsoShading Attributes class.

    This file is automatically generated.
    Do Not Edit!
*/

#include "MagRequest.h" 
#include "IsoShadingWrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"

using namespace magics;



IsoShadingWrapper::IsoShadingWrapper(): isoshading_(new IsoShading())


{

	
	
	NoIsoShadingWrapper::object(isoshading_);
	
	
} 
IsoShadingWrapper::IsoShadingWrapper(IsoShading* isoshading): isoshading_(isoshading)
{
	
	
	NoIsoShadingWrapper::object(isoshading_);
	
} 

IsoShadingWrapper::~IsoShadingWrapper()
{
	
}

void IsoShadingWrapper::set(const MagRequest& request)
{
	
	
	
	NoIsoShadingWrapper::set(request);
	

	if  (request.countValues("CONTOUR_SHADE_MAX_LEVEL") ) {
		double max_value = request("CONTOUR_SHADE_MAX_LEVEL");
		isoshading_->max_ = max_value;
		}
	if  (request.countValues("CONTOUR_SHADE_MIN_LEVEL") ) {
		double min_value = request("CONTOUR_SHADE_MIN_LEVEL");
		isoshading_->min_ = min_value;
		}
	
	
		string technique_value = request.countValues("CONTOUR_SHADE_TECHNIQUE") ?  (string) request("CONTOUR_SHADE_TECHNIQUE") : "polygon_shading";
	MagLog::debug() << " CONTOUR_SHADE_TECHNIQUE set to " << technique_value << endl;
	ShadingTechniqueWrapper* technique_wrapper = 0;
	try
	{
		technique_wrapper = SimpleFactory<ShadingTechniqueWrapper>::create(technique_value);
	}
	 catch (NoFactoryException) {
		MagLog::warning() << "[" << technique_value << "] is not a valid value for technique: reset to default -> [polygon_shading]" << endl;
		technique_wrapper = SimpleFactory<ShadingTechniqueWrapper>::create("polygon_shading");
	}
	technique_wrapper->set(request);
	isoshading_->technique_ =  unique_ptr<ShadingTechnique>(technique_wrapper->object());
	delete technique_wrapper;
	
		string colourMethod_value = request.countValues("CONTOUR_SHADE_COLOUR_METHOD") ?  (string) request("CONTOUR_SHADE_COLOUR_METHOD") : "calculate";
	MagLog::debug() << " CONTOUR_SHADE_COLOUR_METHOD set to " << colourMethod_value << endl;
	ColourTechniqueWrapper* colourMethod_wrapper = 0;
	try
	{
		colourMethod_wrapper = SimpleFactory<ColourTechniqueWrapper>::create(colourMethod_value);
	}
	 catch (NoFactoryException) {
		MagLog::warning() << "[" << colourMethod_value << "] is not a valid value for colourMethod: reset to default -> [calculate]" << endl;
		colourMethod_wrapper = SimpleFactory<ColourTechniqueWrapper>::create("calculate");
	}
	colourMethod_wrapper->set(request);
	isoshading_->colourMethod_ =  unique_ptr<ColourTechnique>(colourMethod_wrapper->object());
	delete colourMethod_wrapper;
	
}

void IsoShadingWrapper::print(ostream& out)  const
{
	out << "IsoShadingWrapper[]";
}


    



#include "PolyShadingTechniqueWrapper.h"
static SimpleObjectMaker<PolyShadingTechnique, ShadingTechnique> IsoShading_contour_shade_technique_polygon ("polygon");
static SimpleObjectMaker<PolyShadingTechniqueWrapper, ShadingTechniqueWrapper> IsoShading_contour_shade_technique_polygon_wrapper ("polygon");


#include "PolyShadingTechniqueWrapper.h"
static SimpleObjectMaker<PolyShadingTechnique, ShadingTechnique> IsoShading_contour_shade_technique_polygon_shading ("polygon_shading");
static SimpleObjectMaker<PolyShadingTechniqueWrapper, ShadingTechniqueWrapper> IsoShading_contour_shade_technique_polygon_shading_wrapper ("polygon_shading");


#include "GridShadingWrapper.h"
static SimpleObjectMaker<GridShading, ShadingTechnique> IsoShading_contour_shade_technique_grid_shading ("grid_shading");
static SimpleObjectMaker<GridShadingWrapper, ShadingTechniqueWrapper> IsoShading_contour_shade_technique_grid_shading_wrapper ("grid_shading");


#include "CellShadingWrapper.h"
static SimpleObjectMaker<CellShading, ShadingTechnique> IsoShading_contour_shade_technique_cell_shading ("cell_shading");
static SimpleObjectMaker<CellShadingWrapper, ShadingTechniqueWrapper> IsoShading_contour_shade_technique_cell_shading_wrapper ("cell_shading");


#include "DumpShadingWrapper.h"
static SimpleObjectMaker<DumpShading, ShadingTechnique> IsoShading_contour_shade_technique_dump_shading ("dump_shading");
static SimpleObjectMaker<DumpShadingWrapper, ShadingTechniqueWrapper> IsoShading_contour_shade_technique_dump_shading_wrapper ("dump_shading");


#include "MarkerShadingTechniqueWrapper.h"
static SimpleObjectMaker<MarkerShadingTechnique, ShadingTechnique> IsoShading_contour_shade_technique_marker ("marker");
static SimpleObjectMaker<MarkerShadingTechniqueWrapper, ShadingTechniqueWrapper> IsoShading_contour_shade_technique_marker_wrapper ("marker");



#include "CalculateColourTechniqueWrapper.h"
static SimpleObjectMaker<CalculateColourTechnique, ColourTechnique> IsoShading_contour_shade_colour_method_calculate ("calculate");
static SimpleObjectMaker<CalculateColourTechniqueWrapper, ColourTechniqueWrapper> IsoShading_contour_shade_colour_method_calculate_wrapper ("calculate");


#include "ListColourTechniqueWrapper.h"
static SimpleObjectMaker<ListColourTechnique, ColourTechnique> IsoShading_contour_shade_colour_method_list ("list");
static SimpleObjectMaker<ListColourTechniqueWrapper, ColourTechniqueWrapper> IsoShading_contour_shade_colour_method_list_wrapper ("list");


#include "GradientsColourTechniqueWrapper.h"
static SimpleObjectMaker<GradientsColourTechnique, ColourTechnique> IsoShading_contour_shade_colour_method_gradients ("gradients");
static SimpleObjectMaker<GradientsColourTechniqueWrapper, ColourTechniqueWrapper> IsoShading_contour_shade_colour_method_gradients_wrapper ("gradients");


#include "PaletteColourTechniqueWrapper.h"
static SimpleObjectMaker<PaletteColourTechnique, ColourTechnique> IsoShading_contour_shade_colour_method_palette ("palette");
static SimpleObjectMaker<PaletteColourTechniqueWrapper, ColourTechniqueWrapper> IsoShading_contour_shade_colour_method_palette_wrapper ("palette");




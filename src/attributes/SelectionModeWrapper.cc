
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file SelectionModeAttributes.h
    \\brief Definition of SelectionMode Attributes class.

    This file is automatically generated.
    Do Not Edit!

*/

#include "MagRequest.h"
#include "SelectionModeWrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"
#include "MagicsSettings.h"

using namespace magics;


SelectionModeWrapper::SelectionModeWrapper(): selectionmode_(new SelectionMode())

{


	

}
SelectionModeWrapper::SelectionModeWrapper(SelectionMode* selectionmode): selectionmode_(selectionmode)
{

	
}

SelectionModeWrapper::~SelectionModeWrapper()
{

}

void SelectionModeWrapper::set(const MagRequest& request)
{

	

	if  (request.countValues("SELECTION_MODE_BACKGROUND_OPACITY") ) {
		int background_opacity_value = request("SELECTION_MODE_BACKGROUND_OPACITY");
		selectionmode_->background_opacity_ = background_opacity_value;
		}
	if  (request.countValues("SELECTION_MODE_LINE_THICKNESS") ) {
		int line_thickness_value = request("SELECTION_MODE_LINE_THICKNESS");
		selectionmode_->line_thickness_ = line_thickness_value;
		}
	if  (request.countValues("SELECTION_MODE_OBJECT_INSTANCIES") ) {
		int object_instancies_value = request("SELECTION_MODE_OBJECT_INSTANCIES");
		selectionmode_->object_instancies_ = object_instancies_value;
		}
	
	if  (request.countValues("SELECTION_MODE_BACKGROUND_COLOUR") ) {
		string background_colour_value = request("SELECTION_MODE_BACKGROUND_COLOUR");
		selectionmode_->background_colour_ = unique_ptr<Colour>(MagTranslator<string, Colour>()(background_colour_value));
	}
		
	if  (request.countValues("SELECTION_MODE_LINE_COLOUR") ) {
		string line_colour_value = request("SELECTION_MODE_LINE_COLOUR");
		selectionmode_->line_colour_ = unique_ptr<Colour>(MagTranslator<string, Colour>()(line_colour_value));
	}
		
	
	if  (request.countValues("SELECTION_MODE_LINE_STYLE") ) {
		string line_style_value = request("SELECTION_MODE_LINE_STYLE");
		selectionmode_->line_style_ = MagTranslator<string, LineStyle>()(line_style_value);
	}
		
	
}

void SelectionModeWrapper::print(ostream& out)  const
{
	out << "SelectionModeWrapper[]";
}






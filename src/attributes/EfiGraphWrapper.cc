
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file EfiGraphAttributes.h
    \\brief Definition of EfiGraph Attributes class.

    This file is automatically generated.
    Do Not Edit!

*/

#include "MagRequest.h"
#include "EfiGraphWrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"
#include "MagicsGlobal.h"

using namespace magics;


EfiGraphWrapper::EfiGraphWrapper(): efigraph_(new EfiGraph())

{


	

}
EfiGraphWrapper::EfiGraphWrapper(EfiGraph* efigraph): efigraph_(efigraph)
{

	
}

EfiGraphWrapper::~EfiGraphWrapper()
{

}

void EfiGraphWrapper::set(const MagRequest& request)
{

	

	stringarray  box_colour_value;
	for (int i = 0; i < request.countValues("EFI_BOX_COLOUR_ARRAY"); i++)
		box_colour_value.push_back((string)request("EFI_BOX_COLOUR_ARRAY", i));
	if ( !box_colour_value.empty() )
		efigraph_->box_colour_ = box_colour_value;
	if  (request.countValues("EFI_BOX_BORDER_THICKNESS") ) {
		int border_thickness_value = request("EFI_BOX_BORDER_THICKNESS");
		efigraph_->border_thickness_ = border_thickness_value;
		}
	if  (request.countValues("EFI_NORMAL_THICKNESS") ) {
		int normal_thickness_value = request("EFI_NORMAL_THICKNESS");
		efigraph_->normal_thickness_ = normal_thickness_value;
		}
	if  (request.countValues("EFI_FONT") ) {
		string font_value = request("EFI_FONT");
		efigraph_->font_ = font_value;
		}
	if  (request.countValues("EFI_FONT_SIZE") ) {
		double font_size_value = request("EFI_FONT_SIZE");
		efigraph_->font_size_ = font_size_value;
		}
	if  (request.countValues("EFI_FONT_STYLE") ) {
		string font_style_value = request("EFI_FONT_STYLE");
		efigraph_->font_style_ = font_style_value;
		}
	
	if  (request.countValues("EFI_BOX_BORDER_COLOUR") ) {
		string border_colour_value = request("EFI_BOX_BORDER_COLOUR");
		efigraph_->border_colour_ = unique_ptr<Colour>(MagTranslator<string, Colour>()(border_colour_value));
	}
		
	
	if  (request.countValues("EFI_BOX_BORDER_LINE_STYLE") ) {
		string border_style_value = request("EFI_BOX_BORDER_LINE_STYLE");
		efigraph_->border_style_ = MagTranslator<string, LineStyle>()(border_style_value);
	}
		
	if  (request.countValues("EFI_NORMAL_COLOUR") ) {
		string normal_colour_value = request("EFI_NORMAL_COLOUR");
		efigraph_->normal_colour_ = unique_ptr<Colour>(MagTranslator<string, Colour>()(normal_colour_value));
	}
		
	
	if  (request.countValues("EFI_NORMAL_LINE_STYLE") ) {
		string normal_style_value = request("EFI_NORMAL_LINE_STYLE");
		efigraph_->normal_style_ = MagTranslator<string, LineStyle>()(normal_style_value);
	}
		
	if  (request.countValues("EFI_FONT_COLOUR") ) {
		string font_colour_value = request("EFI_FONT_COLOUR");
		efigraph_->font_colour_ = unique_ptr<Colour>(MagTranslator<string, Colour>()(font_colour_value));
	}
		
	
}

void EfiGraphWrapper::print(ostream& out)  const
{
	out << "EfiGraphWrapper[]";
}








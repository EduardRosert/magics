
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file SymbolIndividualModeAttributes.h
    \\brief Definition of SymbolIndividualMode Attributes class.

    This file is automatically generated.
    Do Not Edit!

*/

#include "MagRequest.h"
#include "SymbolIndividualModeWrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"
#include "MagicsGlobal.h"

using namespace magics;


SymbolIndividualModeWrapper::SymbolIndividualModeWrapper(): symbolindividualmode_(new SymbolIndividualMode())

{


	
	SymbolModeWrapper::object(symbolindividualmode_);
	

}
SymbolIndividualModeWrapper::SymbolIndividualModeWrapper(SymbolIndividualMode* symbolindividualmode): symbolindividualmode_(symbolindividualmode)
{

	
	SymbolModeWrapper::object(symbolindividualmode_);
	
}

SymbolIndividualModeWrapper::~SymbolIndividualModeWrapper()
{

}

void SymbolIndividualModeWrapper::set(const MagRequest& request)
{

	

	SymbolModeWrapper::set(request);
	

	if  (request.countValues("LEGEND_USER_TEXT") ) {
		string legend_text_value = request("LEGEND_USER_TEXT");
		symbolindividualmode_->legend_text_ = legend_text_value;
		}
	if  (request.countValues("SYMBOL_HEIGHT") ) {
		double height_value = request("SYMBOL_HEIGHT");
		symbolindividualmode_->height_ = height_value;
		}
	if  (request.countValues("SYMBOL_MARKER_MODE") ) {
		string marker_mode_value = request("SYMBOL_MARKER_MODE");
		symbolindividualmode_->marker_mode_ = marker_mode_value;
		}
	if  (request.countValues("SYMBOL_MARKER_INDEX") ) {
		int marker_value = request("SYMBOL_MARKER_INDEX");
		symbolindividualmode_->marker_ = marker_value;
		}
	if  (request.countValues("SYMBOL_MARKER_NAME") ) {
		string symbol_value = request("SYMBOL_MARKER_NAME");
		symbolindividualmode_->symbol_ = symbol_value;
		}
	if  (request.countValues("SYMBOL_IMAGE_PATH") ) {
		string image_path_value = request("SYMBOL_IMAGE_PATH");
		symbolindividualmode_->image_path_ = image_path_value;
		}
	if  (request.countValues("SYMBOL_IMAGE_FORMAT") ) {
		string image_format_value = request("SYMBOL_IMAGE_FORMAT");
		symbolindividualmode_->image_format_ = image_format_value;
		}
	if  (request.countValues("SYMBOL_IMAGE_WIDTH") ) {
		double image_width_value = request("SYMBOL_IMAGE_WIDTH");
		symbolindividualmode_->image_width_ = image_width_value;
		}
	if  (request.countValues("SYMBOL_IMAGE_HEIGHT") ) {
		double image_height_value = request("SYMBOL_IMAGE_HEIGHT");
		symbolindividualmode_->image_height_ = image_height_value;
		}
	if  (request.countValues("SYMBOL_IMAGE_BY_REFERENCE") ) {
		string image_by_reference_value = request("SYMBOL_IMAGE_BY_REFERENCE");
		symbolindividualmode_->image_by_reference_ = MagTranslator<string, bool>()(image_by_reference_value);
		}
	stringarray  text_value;
	for (int i = 0; i < request.countValues("SYMBOL_TEXT_LIST"); i++)
		text_value.push_back((string)request("SYMBOL_TEXT_LIST", i));
	if ( !text_value.empty() )
		symbolindividualmode_->text_ = text_value;
	if  (request.countValues("SYMBOL_TEXT_POSITION") ) {
		string text_position_value = request("SYMBOL_TEXT_POSITION");
		symbolindividualmode_->text_position_ = text_position_value;
		}
	if  (request.countValues("SYMBOL_TEXT_FONT") ) {
		string text_font_name_value = request("SYMBOL_TEXT_FONT");
		symbolindividualmode_->text_font_name_ = text_font_name_value;
		}
	if  (request.countValues("SYMBOL_TEXT_FONT_SIZE") ) {
		double text_font_size_value = request("SYMBOL_TEXT_FONT_SIZE");
		symbolindividualmode_->text_font_size_ = text_font_size_value;
		}
	if  (request.countValues("SYMBOL_TEXT_FONT_STYLE") ) {
		string text_font_style_value = request("SYMBOL_TEXT_FONT_STYLE");
		symbolindividualmode_->text_font_style_ = text_font_style_value;
		}
	if  (request.countValues("SYMBOL_LEGEND_HEIGHT") ) {
		double legend_height_value = request("SYMBOL_LEGEND_HEIGHT");
		symbolindividualmode_->legend_height_ = legend_height_value;
		}
	
	if  (request.countValues("SYMBOL_COLOUR") ) {
		string colour_value = request("SYMBOL_COLOUR");
		symbolindividualmode_->colour_ = unique_ptr<Colour>(MagTranslator<string, Colour>()(colour_value));
	}
		
	if  (request.countValues("SYMBOL_TEXT_FONT_COLOUR") ) {
		string text_font_colour_value = request("SYMBOL_TEXT_FONT_COLOUR");
		symbolindividualmode_->text_font_colour_ = unique_ptr<Colour>(MagTranslator<string, Colour>()(text_font_colour_value));
	}
		
	
}

void SymbolIndividualModeWrapper::print(ostream& out)  const
{
	out << "SymbolIndividualModeWrapper[]";
}






/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file TextVisitorAttributes.h
    \\brief Definition of TextVisitor Attributes class.

    This file is automatically generated.
    Do Not Edit!
*/

#include "MagRequest.h" 
#include "TextVisitorWrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"

using namespace magics;


TextVisitorWrapper::TextVisitorWrapper(): textvisitor_(new TextVisitor())

{

	
	
	
} 
TextVisitorWrapper::TextVisitorWrapper(TextVisitor* textvisitor): textvisitor_(textvisitor)
{
	
	
} 

TextVisitorWrapper::~TextVisitorWrapper()
{
	
}

void TextVisitorWrapper::set(const MagRequest& request)
{
	
	

	if  (request.countValues("TEXT_LINE_COUNT") ) {
		int count_value = request("TEXT_LINE_COUNT");
		textvisitor_->count_ = count_value;
		}
	if  (request.countValues("TEXT_LINE_1") ) {
		string line1_value = request("TEXT_LINE_1");
		textvisitor_->line1_ = line1_value;
		}
	if  (request.countValues("TEXT_LINE_2") ) {
		string line2_value = request("TEXT_LINE_2");
		textvisitor_->line2_ = line2_value;
		}
	if  (request.countValues("TEXT_LINE_3") ) {
		string line3_value = request("TEXT_LINE_3");
		textvisitor_->line3_ = line3_value;
		}
	if  (request.countValues("TEXT_LINE_4") ) {
		string line4_value = request("TEXT_LINE_4");
		textvisitor_->line4_ = line4_value;
		}
	if  (request.countValues("TEXT_LINE_5") ) {
		string line5_value = request("TEXT_LINE_5");
		textvisitor_->line5_ = line5_value;
		}
	if  (request.countValues("TEXT_LINE_6") ) {
		string line6_value = request("TEXT_LINE_6");
		textvisitor_->line6_ = line6_value;
		}
	if  (request.countValues("TEXT_LINE_7") ) {
		string line7_value = request("TEXT_LINE_7");
		textvisitor_->line7_ = line7_value;
		}
	if  (request.countValues("TEXT_LINE_8") ) {
		string line8_value = request("TEXT_LINE_8");
		textvisitor_->line8_ = line8_value;
		}
	if  (request.countValues("TEXT_LINE_9") ) {
		string line9_value = request("TEXT_LINE_9");
		textvisitor_->line9_ = line9_value;
		}
	if  (request.countValues("TEXT_LINE_10") ) {
		string line10_value = request("TEXT_LINE_10");
		textvisitor_->line10_ = line10_value;
		}
	if  (request.countValues("TEXT_FONT") ) {
		string font_value = request("TEXT_FONT");
		textvisitor_->font_ = font_value;
		}
	if  (request.countValues("TEXT_FONT_STYLE") ) {
		string font_style_value = request("TEXT_FONT_STYLE");
		textvisitor_->font_style_ = font_style_value;
		}
	if  (request.countValues("TEXT_FONT_SIZE") ) {
		string font_dimension_value = request("TEXT_FONT_SIZE");
		textvisitor_->font_dimension_ = font_dimension_value;
		}
	if  (request.countValues("TEXT_ORIENTATION") ) {
		string orientation_value = request("TEXT_ORIENTATION");
		textvisitor_->orientation_ = orientation_value;
		}
	if  (request.countValues("TEXT_AUTOMATIC") ) {
		string automatic_value = request("TEXT_AUTOMATIC");
		textvisitor_->automatic_ = MagTranslator<string, bool>()(automatic_value);
		}
	stringarray  lines_value;
	for (int i = 0; i < request.countValues("TEXT_LINES"); i++)
		lines_value.push_back((string)request("TEXT_LINES", i));
	if ( !lines_value.empty() ) 
		textvisitor_->lines_ = lines_value;
	if  (request.countValues("TEXT_MODE") ) {
		string mode_value = request("TEXT_MODE");
		textvisitor_->mode_ = mode_value;
		}
	if  (request.countValues("TEXT_BOX_X_POSITION") ) {
		double x_value = request("TEXT_BOX_X_POSITION");
		textvisitor_->x_ = x_value;
		}
	if  (request.countValues("TEXT_BOX_Y_POSITION") ) {
		double y_value = request("TEXT_BOX_Y_POSITION");
		textvisitor_->y_ = y_value;
		}
	if  (request.countValues("TEXT_BOX_X_LENGTH") ) {
		double width_value = request("TEXT_BOX_X_LENGTH");
		textvisitor_->width_ = width_value;
		}
	if  (request.countValues("TEXT_BOX_Y_LENGTH") ) {
		double height_value = request("TEXT_BOX_Y_LENGTH");
		textvisitor_->height_ = height_value;
		}
	if  (request.countValues("TEXT_BOX_BLANKING") ) {
		string blanking_value = request("TEXT_BOX_BLANKING");
		textvisitor_->blanking_ = MagTranslator<string, bool>()(blanking_value);
		}
	if  (request.countValues("TEXT_BORDER") ) {
		string border_value = request("TEXT_BORDER");
		textvisitor_->border_ = MagTranslator<string, bool>()(border_value);
		}
	if  (request.countValues("TEXT_BORDER_THICKNESS") ) {
		int border_thickness_value = request("TEXT_BORDER_THICKNESS");
		textvisitor_->border_thickness_ = border_thickness_value;
		}
	
	if  (request.countValues("TEXT_COLOUR") ) {
		string font_colour_value = request("TEXT_COLOUR");
		textvisitor_->font_colour_ = unique_ptr<Colour>(MagTranslator<string, Colour>()(font_colour_value));
	}
		
	
	if  (request.countValues("TEXT_JUSTIFICATION") ) {
		string justification_value = request("TEXT_JUSTIFICATION");
		textvisitor_->justification_ = MagTranslator<string, Justification>()(justification_value);
	}
		
	
	if  (request.countValues("TEXT_BORDER_LINE_STYLE") ) {
		string border_line_style_value = request("TEXT_BORDER_LINE_STYLE");
		textvisitor_->border_line_style_ = MagTranslator<string, LineStyle>()(border_line_style_value);
	}
		
	if  (request.countValues("TEXT_BORDER_COLOUR") ) {
		string border_colour_value = request("TEXT_BORDER_COLOUR");
		textvisitor_->border_colour_ = unique_ptr<Colour>(MagTranslator<string, Colour>()(border_colour_value));
	}
		
	
}

void TextVisitorWrapper::print(ostream& out)  const
{
	out << "TextVisitorWrapper[]";
}


    








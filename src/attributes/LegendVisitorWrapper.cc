
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file LegendVisitorAttributes.h
    \\brief Definition of LegendVisitor Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 2020-09-24
*/

#include "MagRequest.h" 
#include "LegendVisitorWrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"

using namespace magics;


LegendVisitorWrapper::LegendVisitorWrapper(): legendvisitor_(new LegendVisitor())

{

	
	
	
} 
LegendVisitorWrapper::LegendVisitorWrapper(LegendVisitor* legendvisitor): legendvisitor_(legendvisitor)
{
	
	
} 

LegendVisitorWrapper::~LegendVisitorWrapper()
{
	
}

void LegendVisitorWrapper::set(const MagRequest& request)
{
	
	

	if  (request.countValues("LEGEND_TITLE") ) {
		string title_value = request("LEGEND_TITLE");
		legendvisitor_->title_ = MagTranslator<string, bool>()(title_value);
		}
	if  (request.countValues("LEGEND_TITLE_TEXT") ) {
		string title_text_value = request("LEGEND_TITLE_TEXT");
		legendvisitor_->title_text_ = title_text_value;
		}
	if  (request.countValues("LEGEND_TITLE_ORIENTATION") ) {
		string title_orientation_value = request("LEGEND_TITLE_ORIENTATION");
		legendvisitor_->title_orientation_ = title_orientation_value;
		}
	if  (request.countValues("LEGEND_TITLE_FONT_SIZE") ) {
		double title_font_size_value = request("LEGEND_TITLE_FONT_SIZE");
		legendvisitor_->title_font_size_ = title_font_size_value;
		}
	if  (request.countValues("LEGEND_TITLE_POSITION_RATIO") ) {
		double title_ratio_value = request("LEGEND_TITLE_POSITION_RATIO");
		legendvisitor_->title_ratio_ = title_ratio_value;
		}
	if  (request.countValues("LEGEND_UNITS_TEXT") ) {
		string units_text_value = request("LEGEND_UNITS_TEXT");
		legendvisitor_->units_text_ = units_text_value;
		}
	if  (request.countValues("LEGEND_USER_MINIMUM") ) {
		string use_min_value = request("LEGEND_USER_MINIMUM");
		legendvisitor_->use_min_ = MagTranslator<string, bool>()(use_min_value);
		}
	if  (request.countValues("LEGEND_USER_MINIMUM_TEXT") ) {
		string use_min_text_value = request("LEGEND_USER_MINIMUM_TEXT");
		legendvisitor_->use_min_text_ = use_min_text_value;
		}
	if  (request.countValues("LEGEND_USER_MAXIMUM") ) {
		string use_max_value = request("LEGEND_USER_MAXIMUM");
		legendvisitor_->use_max_ = MagTranslator<string, bool>()(use_max_value);
		}
	if  (request.countValues("LEGEND_USER_MAXIMUM_TEXT") ) {
		string use_max_text_value = request("LEGEND_USER_MAXIMUM_TEXT");
		legendvisitor_->use_max_text_ = use_max_text_value;
		}
	if  (request.countValues("LEGEND_TEXT_FORMAT") ) {
		string format_value = request("LEGEND_TEXT_FORMAT");
		legendvisitor_->format_ = format_value;
		}
	if  (request.countValues("LEGEND_BOX_MODE") ) {
		string box_value = request("LEGEND_BOX_MODE");
		legendvisitor_->box_ = box_value;
		}
	if  (request.countValues("LEGEND_AUTOMATIC_POSITION") ) {
		string box_position_value = request("LEGEND_AUTOMATIC_POSITION");
		legendvisitor_->box_position_ = box_position_value;
		}
	if  (request.countValues("LEGEND_AUTOMATIC_BOX_MARGIN") ) {
		double box_margin_value = request("LEGEND_AUTOMATIC_BOX_MARGIN");
		legendvisitor_->box_margin_ = box_margin_value;
		}
	if  (request.countValues("LEGEND_TEXT_FONT") ) {
		string font_value = request("LEGEND_TEXT_FONT");
		legendvisitor_->font_ = font_value;
		}
	if  (request.countValues("LEGEND_TEXT_FONT_STYLE") ) {
		string font_style_value = request("LEGEND_TEXT_FONT_STYLE");
		legendvisitor_->font_style_ = font_style_value;
		}
	if  (request.countValues("LEGEND_TEXT_FONT_SIZE") ) {
		string font_dimension_value = request("LEGEND_TEXT_FONT_SIZE");
		legendvisitor_->font_dimension_ = font_dimension_value;
		}
	if  (request.countValues("LEGEND_TEXT_QUALITY") ) {
		string text_quality_value = request("LEGEND_TEXT_QUALITY");
		legendvisitor_->text_quality_ = text_quality_value;
		}
	if  (request.countValues("LEGEND_TEXT_ORIENTATION") ) {
		double orientation_value = request("LEGEND_TEXT_ORIENTATION");
		legendvisitor_->orientation_ = orientation_value;
		}
	stringarray  lines_value;
	for (int i = 0; i < request.countValues("LEGEND_USER_LINES"); i++)
		lines_value.push_back((string)request("LEGEND_USER_LINES", i));
	if ( !lines_value.empty() ) 
		legendvisitor_->lines_ = lines_value;
	if  (request.countValues("LEGEND_COLUMN_COUNT") ) {
		int columns_value = request("LEGEND_COLUMN_COUNT");
		legendvisitor_->columns_ = columns_value;
		}
	if  (request.countValues("LEGEND_ENTRY_PLOT_DIRECTION") ) {
		string direction_value = request("LEGEND_ENTRY_PLOT_DIRECTION");
		legendvisitor_->direction_ = direction_value;
		}
	if  (request.countValues("LEGEND_ENTRY_PLOT_ORIENTATION") ) {
		string entry_orientation_value = request("LEGEND_ENTRY_PLOT_ORIENTATION");
		legendvisitor_->entry_orientation_ = entry_orientation_value;
		}
	if  (request.countValues("LEGEND_TEXT_COMPOSITION") ) {
		string composition_value = request("LEGEND_TEXT_COMPOSITION");
		legendvisitor_->composition_ = composition_value;
		}
	doublearray  values_list_value;
	for (int i = 0; i < request.countValues("LEGEND_VALUES_LIST"); i++)
		values_list_value.push_back((double)request("LEGEND_VALUES_LIST", i));
	if ( !values_list_value.empty() ) 
		legendvisitor_->values_list_ = values_list_value;
	if  (request.countValues("LEGEND_USER_TEXT") ) {
		string text_value = request("LEGEND_USER_TEXT");
		legendvisitor_->text_ = text_value;
		}
	if  (request.countValues("LEGEND_USER_TEXT_1") ) {
		string text1_value = request("LEGEND_USER_TEXT_1");
		legendvisitor_->text1_ = text1_value;
		}
	if  (request.countValues("LEGEND_USER_TEXT_2") ) {
		string text2_value = request("LEGEND_USER_TEXT_2");
		legendvisitor_->text2_ = text2_value;
		}
	if  (request.countValues("LEGEND_USER_TEXT_3") ) {
		string text3_value = request("LEGEND_USER_TEXT_3");
		legendvisitor_->text3_ = text3_value;
		}
	if  (request.countValues("LEGEND_USER_TEXT_4") ) {
		string text4_value = request("LEGEND_USER_TEXT_4");
		legendvisitor_->text4_ = text4_value;
		}
	if  (request.countValues("LEGEND_USER_TEXT_5") ) {
		string text5_value = request("LEGEND_USER_TEXT_5");
		legendvisitor_->text5_ = text5_value;
		}
	if  (request.countValues("LEGEND_USER_TEXT_6") ) {
		string text6_value = request("LEGEND_USER_TEXT_6");
		legendvisitor_->text6_ = text6_value;
		}
	if  (request.countValues("LEGEND_USER_TEXT_7") ) {
		string text7_value = request("LEGEND_USER_TEXT_7");
		legendvisitor_->text7_ = text7_value;
		}
	if  (request.countValues("LEGEND_USER_TEXT_8") ) {
		string text8_value = request("LEGEND_USER_TEXT_8");
		legendvisitor_->text8_ = text8_value;
		}
	if  (request.countValues("LEGEND_USER_TEXT_9") ) {
		string text9_value = request("LEGEND_USER_TEXT_9");
		legendvisitor_->text9_ = text9_value;
		}
	if  (request.countValues("LEGEND_USER_TEXT_10") ) {
		string text10_value = request("LEGEND_USER_TEXT_10");
		legendvisitor_->text10_ = text10_value;
		}
	if  (request.countValues("LEGEND_SYMBOL_HEIGHT_FACTOR") ) {
		double symbol_factor_value = request("LEGEND_SYMBOL_HEIGHT_FACTOR");
		legendvisitor_->symbol_factor_ = symbol_factor_value;
		}
	if  (request.countValues("LEGEND_BOX_X_POSITION") ) {
		double box_x_value = request("LEGEND_BOX_X_POSITION");
		legendvisitor_->box_x_ = box_x_value;
		}
	if  (request.countValues("LEGEND_BOX_Y_POSITION") ) {
		double box_y_value = request("LEGEND_BOX_Y_POSITION");
		legendvisitor_->box_y_ = box_y_value;
		}
	if  (request.countValues("LEGEND_BOX_X_LENGTH") ) {
		double box_width_value = request("LEGEND_BOX_X_LENGTH");
		legendvisitor_->box_width_ = box_width_value;
		}
	if  (request.countValues("LEGEND_BOX_Y_LENGTH") ) {
		double box_height_value = request("LEGEND_BOX_Y_LENGTH");
		legendvisitor_->box_height_ = box_height_value;
		}
	if  (request.countValues("LEGEND_BOX_BLANKING") ) {
		string blanking_value = request("LEGEND_BOX_BLANKING");
		legendvisitor_->blanking_ = MagTranslator<string, bool>()(blanking_value);
		}
	if  (request.countValues("LEGEND_BORDER") ) {
		string border_value = request("LEGEND_BORDER");
		legendvisitor_->border_ = MagTranslator<string, bool>()(border_value);
		}
	if  (request.countValues("LEGEND_BORDER_THICKNESS") ) {
		int border_thickness_value = request("LEGEND_BORDER_THICKNESS");
		legendvisitor_->border_thickness_ = border_thickness_value;
		}
	if  (request.countValues("LEGEND_WREP") ) {
		string wrep_value = request("LEGEND_WREP");
		legendvisitor_->wrep_ = MagTranslator<string, bool>()(wrep_value);
		}
	if  (request.countValues("LEGEND_ONLY") ) {
		string only_value = request("LEGEND_ONLY");
		legendvisitor_->only_ = MagTranslator<string, bool>()(only_value);
		}
	if  (request.countValues("LEGEND_ENTRY_TEXT_WIDTH") ) {
		double text_width_value = request("LEGEND_ENTRY_TEXT_WIDTH");
		legendvisitor_->text_width_ = text_width_value;
		}
	if  (request.countValues("LEGEND_ENTRY_BORDER") ) {
		string entry_border_value = request("LEGEND_ENTRY_BORDER");
		legendvisitor_->entry_border_ = MagTranslator<string, bool>()(entry_border_value);
		}
	
	if  (request.countValues("LEGEND_TEXT_COLOUR") ) {
		string colour_value = request("LEGEND_TEXT_COLOUR");
		legendvisitor_->colour_ = unique_ptr<Colour>(MagTranslator<string, Colour>()(colour_value));
	}
		
	if  (request.countValues("LEGEND_TITLE_FONT_COLOUR") ) {
		string title_font_colour_value = request("LEGEND_TITLE_FONT_COLOUR");
		legendvisitor_->title_font_colour_ = unique_ptr<Colour>(MagTranslator<string, Colour>()(title_font_colour_value));
	}
		
	
	if  (request.countValues("LEGEND_TITLE_POSITION") ) {
		string title_position_value = request("LEGEND_TITLE_POSITION");
		legendvisitor_->title_position_ = MagTranslator<string, Position>()(title_position_value);
	}
		
	
		string method_value = request.countValues("LEGEND_DISPLAY_TYPE") ?  (string) request("LEGEND_DISPLAY_TYPE") : "disjoint";
	MagLog::debug() << " LEGEND_DISPLAY_TYPE set to " << method_value << endl;
	LegendMethodWrapper* method_wrapper = 0;
#ifdef MAGICS_EXCEPTION
	try
#endif
	{
		method_wrapper = SimpleFactory<LegendMethodWrapper>::create(method_value);
	}
#ifdef MAGICS_EXCEPTION
	 catch (NoFactoryException) {
#else
	 if (!method_wrapper) {
#endif
		MagLog::warning() << "[" << method_value << "] is not a valid value for method: reset to default -> [disjoint]" << endl;
		method_wrapper = SimpleFactory<LegendMethodWrapper>::create("disjoint");
	}
	method_wrapper->set(request);
	legendvisitor_->method_ =  unique_ptr<LegendMethod>(method_wrapper->object());
	delete method_wrapper;
	
	if  (request.countValues("LEGEND_BORDER_LINE_STYLE") ) {
		string border_line_style_value = request("LEGEND_BORDER_LINE_STYLE");
		legendvisitor_->border_line_style_ = MagTranslator<string, LineStyle>()(border_line_style_value);
	}
		
	if  (request.countValues("LEGEND_BORDER_COLOUR") ) {
		string border_colour_value = request("LEGEND_BORDER_COLOUR");
		legendvisitor_->border_colour_ = unique_ptr<Colour>(MagTranslator<string, Colour>()(border_colour_value));
	}
		
	if  (request.countValues("LEGEND_ENTRY_BORDER_COLOUR") ) {
		string entry_border_colour_value = request("LEGEND_ENTRY_BORDER_COLOUR");
		legendvisitor_->entry_border_colour_ = unique_ptr<Colour>(MagTranslator<string, Colour>()(entry_border_colour_value));
	}
		
	
}

void LegendVisitorWrapper::print(ostream& out)  const
{
	out << "LegendVisitorWrapper[]";
}


    






#include "LegendMethodWrapper.h"

static SimpleObjectMaker<LegendMethodWrapper> LegendVisitor_legend_display_type_disjoint_Wrapper("disjoint");


#include "ContinuousLegendMethodWrapper.h"
static SimpleObjectMaker<ContinuousLegendMethod, LegendMethod> LegendVisitor_legend_display_type_continuous ("continuous");
static SimpleObjectMaker<ContinuousLegendMethodWrapper, LegendMethodWrapper> LegendVisitor_legend_display_type_continuous_wrapper ("continuous");


#include "HistogramLegendMethodWrapper.h"
static SimpleObjectMaker<HistogramLegendMethod, LegendMethod> LegendVisitor_legend_display_type_histogram ("histogram");
static SimpleObjectMaker<HistogramLegendMethodWrapper, LegendMethodWrapper> LegendVisitor_legend_display_type_histogram_wrapper ("histogram");






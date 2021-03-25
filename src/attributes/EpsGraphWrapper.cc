
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file EpsGraphAttributes.h
    \\brief Definition of EpsGraph Attributes class.

    This file is automatically generated.
    Do Not Edit!
*/

#include "MagRequest.h" 
#include "EpsGraphWrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"

using namespace magics;


EpsGraphWrapper::EpsGraphWrapper(): epsgraph_(new EpsGraph())

{

	
	
	
} 
EpsGraphWrapper::EpsGraphWrapper(EpsGraph* epsgraph): epsgraph_(epsgraph)
{
	
	
} 

EpsGraphWrapper::~EpsGraphWrapper()
{
	
}

void EpsGraphWrapper::set(const MagRequest& request)
{
	
	

	if  (request.countValues("EPS_FONT") ) {
		string font_value = request("EPS_FONT");
		epsgraph_->font_ = font_value;
		}
	if  (request.countValues("EPS_FONT_SIZE") ) {
		double font_size_value = request("EPS_FONT_SIZE");
		epsgraph_->font_size_ = font_size_value;
		}
	if  (request.countValues("EPS_FONT_STYLE") ) {
		string font_style_value = request("EPS_FONT_STYLE");
		epsgraph_->font_style_ = font_style_value;
		}
	if  (request.countValues("EPS_BOX_SHIFT") ) {
		int box_shift_value = request("EPS_BOX_SHIFT");
		epsgraph_->box_shift_ = box_shift_value;
		}
	stringarray  quantiles_colour_value;
	for (int i = 0; i < request.countValues("EPS_BOX_QUANTILES_COLOUR"); i++)
		quantiles_colour_value.push_back((string)request("EPS_BOX_QUANTILES_COLOUR", i));
	if ( !quantiles_colour_value.empty() ) 
		epsgraph_->quantiles_colour_ = quantiles_colour_value;
	if  (request.countValues("EPS_BOX_BORDER_THICKNESS") ) {
		int border_thickness_value = request("EPS_BOX_BORDER_THICKNESS");
		epsgraph_->border_thickness_ = border_thickness_value;
		}
	if  (request.countValues("EPS_BOX_MEDIAN_THICKNESS") ) {
		int median_thickness_value = request("EPS_BOX_MEDIAN_THICKNESS");
		epsgraph_->median_thickness_ = median_thickness_value;
		}
	if  (request.countValues("EPS_MAXIMUM") ) {
		double max_value = request("EPS_MAXIMUM");
		epsgraph_->max_ = max_value;
		}
	if  (request.countValues("EPS_MAXIMUM_FONT") ) {
		string max_font_name_value = request("EPS_MAXIMUM_FONT");
		epsgraph_->max_font_name_ = max_font_name_value;
		}
	if  (request.countValues("EPS_MAXIMUM_FONT_STYLE") ) {
		string max_font_style_value = request("EPS_MAXIMUM_FONT_STYLE");
		epsgraph_->max_font_style_ = max_font_style_value;
		}
	if  (request.countValues("EPS_MAXIMUM_FONT_SIZE") ) {
		double max_font_size_value = request("EPS_MAXIMUM_FONT_SIZE");
		epsgraph_->max_font_size_ = max_font_size_value;
		}
	if  (request.countValues("EPS_BOX_WIDTH") ) {
		double box_width_value = request("EPS_BOX_WIDTH");
		epsgraph_->box_width_ = box_width_value;
		}
	if  (request.countValues("EPS_WHISKER") ) {
		string whisker_value = request("EPS_WHISKER");
		epsgraph_->whisker_ = MagTranslator<string, bool>()(whisker_value);
		}
	if  (request.countValues("EPS_LEGEND_RESOLUTION") ) {
		string legend_resolution_value = request("EPS_LEGEND_RESOLUTION");
		epsgraph_->legend_resolution_ = legend_resolution_value;
		}
	if  (request.countValues("EPS_LEGEND_CONTROL_TEXT") ) {
		string legend_control_text_value = request("EPS_LEGEND_CONTROL_TEXT");
		epsgraph_->legend_control_text_ = legend_control_text_value;
		}
	if  (request.countValues("EPS_LEGEND_FONT_SIZE") ) {
		double legend_size_value = request("EPS_LEGEND_FONT_SIZE");
		epsgraph_->legend_size_ = legend_size_value;
		}
	if  (request.countValues("EPS_LEGEND_FORECAST_TEXT") ) {
		string legend_forecast_text_value = request("EPS_LEGEND_FORECAST_TEXT");
		epsgraph_->legend_forecast_text_ = legend_forecast_text_value;
		}
	if  (request.countValues("EPS_DETERMINISTIC") ) {
		string deterministic_value = request("EPS_DETERMINISTIC");
		epsgraph_->deterministic_ = MagTranslator<string, bool>()(deterministic_value);
		}
	if  (request.countValues("EPS_DETERMINISTIC_LINE_THICKNESS") ) {
		int deterministic_thickness_value = request("EPS_DETERMINISTIC_LINE_THICKNESS");
		epsgraph_->deterministic_thickness_ = deterministic_thickness_value;
		}
	if  (request.countValues("EPS_DETERMINISTIC_LEGEND_TEXT") ) {
		string deterministic_legend_value = request("EPS_DETERMINISTIC_LEGEND_TEXT");
		epsgraph_->deterministic_legend_ = deterministic_legend_value;
		}
	if  (request.countValues("EPS_CONTROL") ) {
		string control_value = request("EPS_CONTROL");
		epsgraph_->control_ = MagTranslator<string, bool>()(control_value);
		}
	if  (request.countValues("EPS_CONTROL_LINE_THICKNESS") ) {
		int control_thickness_value = request("EPS_CONTROL_LINE_THICKNESS");
		epsgraph_->control_thickness_ = control_thickness_value;
		}
	if  (request.countValues("EPS_CONTROL_LEGEND_TEXT") ) {
		string control_legend_value = request("EPS_CONTROL_LEGEND_TEXT");
		epsgraph_->control_legend_ = control_legend_value;
		}
	if  (request.countValues("LEGEND") ) {
		string legend_value = request("LEGEND");
		epsgraph_->legend_ = MagTranslator<string, bool>()(legend_value);
		}
	if  (request.countValues("EPS_GREY_LEGEND") ) {
		string grey_legend_value = request("EPS_GREY_LEGEND");
		epsgraph_->grey_legend_ = MagTranslator<string, bool>()(grey_legend_value);
		}
	
	if  (request.countValues("EPS_FONT_COLOUR") ) {
		string font_colour_value = request("EPS_FONT_COLOUR");
		epsgraph_->font_colour_ = unique_ptr<Colour>(MagTranslator<string, Colour>()(font_colour_value));
	}
		
	if  (request.countValues("EPS_BOX_COLOUR") ) {
		string colour_value = request("EPS_BOX_COLOUR");
		epsgraph_->colour_ = unique_ptr<Colour>(MagTranslator<string, Colour>()(colour_value));
	}
		
	if  (request.countValues("EPS_RIGHT_BOX_COLOUR") ) {
		string right_colour_value = request("EPS_RIGHT_BOX_COLOUR");
		epsgraph_->right_colour_ = unique_ptr<Colour>(MagTranslator<string, Colour>()(right_colour_value));
	}
		
	if  (request.countValues("EPS_LEFT_BOX_COLOUR") ) {
		string left_colour_value = request("EPS_LEFT_BOX_COLOUR");
		epsgraph_->left_colour_ = unique_ptr<Colour>(MagTranslator<string, Colour>()(left_colour_value));
	}
		
	if  (request.countValues("EPS_BOX_BORDER_COLOUR") ) {
		string border_colour_value = request("EPS_BOX_BORDER_COLOUR");
		epsgraph_->border_colour_ = unique_ptr<Colour>(MagTranslator<string, Colour>()(border_colour_value));
	}
		
	if  (request.countValues("EPS_BOX_MEDIAN_COLOUR") ) {
		string median_colour_value = request("EPS_BOX_MEDIAN_COLOUR");
		epsgraph_->median_colour_ = unique_ptr<Colour>(MagTranslator<string, Colour>()(median_colour_value));
	}
		
	if  (request.countValues("EPS_MAXIMUM_FONT_COLOUR") ) {
		string max_font_colour_value = request("EPS_MAXIMUM_FONT_COLOUR");
		epsgraph_->max_font_colour_ = unique_ptr<Colour>(MagTranslator<string, Colour>()(max_font_colour_value));
	}
		
	if  (request.countValues("EPS_DETERMINISTIC_LINE_COLOUR") ) {
		string deterministic_colour_value = request("EPS_DETERMINISTIC_LINE_COLOUR");
		epsgraph_->deterministic_colour_ = unique_ptr<Colour>(MagTranslator<string, Colour>()(deterministic_colour_value));
	}
		
	
	if  (request.countValues("EPS_DETERMINISTIC_LINE_STYLE") ) {
		string deterministic_style_value = request("EPS_DETERMINISTIC_LINE_STYLE");
		epsgraph_->deterministic_style_ = MagTranslator<string, LineStyle>()(deterministic_style_value);
	}
		
	if  (request.countValues("EPS_CONTROL_LINE_COLOUR") ) {
		string control_colour_value = request("EPS_CONTROL_LINE_COLOUR");
		epsgraph_->control_colour_ = unique_ptr<Colour>(MagTranslator<string, Colour>()(control_colour_value));
	}
		
	
	if  (request.countValues("EPS_CONTROL_LINE_STYLE") ) {
		string control_style_value = request("EPS_CONTROL_LINE_STYLE");
		epsgraph_->control_style_ = MagTranslator<string, LineStyle>()(control_style_value);
	}
		
	
}

void EpsGraphWrapper::print(ostream& out)  const
{
	out << "EpsGraphWrapper[]";
}


    















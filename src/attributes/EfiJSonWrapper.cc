
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file EfiJSonAttributes.h
    \\brief Definition of EfiJSon Attributes class.

    This file is automatically generated.
    Do Not Edit!
*/

#include "MagRequest.h" 
#include "EfiJSonWrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"

using namespace magics;



EfiJSonWrapper::EfiJSonWrapper(): efijson_(new EfiJSon())


{

	
	
	
} 
EfiJSonWrapper::EfiJSonWrapper(EfiJSon* efijson): efijson_(efijson)
{
	
	
} 

EfiJSonWrapper::~EfiJSonWrapper()
{
	
}

void EfiJSonWrapper::set(const MagRequest& request)
{
	
	

	if  (request.countValues("EFIJSON_INPUT_FILENAME") ) {
		string path_value = request("EFIJSON_INPUT_FILENAME");
		efijson_->path_ = path_value;
		}
	if  (request.countValues("EFI_LONG_TITLE") ) {
		string long_title_value = request("EFI_LONG_TITLE");
		
		efijson_->long_title_ = MagTranslator<string, bool>()(long_title_value);
		
		}
	if  (request.countValues("EFI_TITLE") ) {
		string title_value = request("EFI_TITLE");
		
		efijson_->title_ = MagTranslator<string, bool>()(title_value);
		
		}
	if  (request.countValues("EFI_LEGEND") ) {
		string legend_value = request("EFI_LEGEND");
		
		efijson_->legend_ = MagTranslator<string, bool>()(legend_value);
		
		}
	stringarray  legend_colours_value;
	for (int i = 0; i < request.countValues("EFI_LEGEND_COLOUR_LIST"); i++)
		legend_colours_value.push_back((string)request("EFI_LEGEND_COLOUR_LIST", i));
	if ( !legend_colours_value.empty() ) 
		efijson_->legend_colours_ = legend_colours_value;
	if  (request.countValues("EFI_LEGEND_BOX_TYPE") ) {
		string legend_type_value = request("EFI_LEGEND_BOX_TYPE");
		efijson_->legend_type_ = legend_type_value;
		}
	if  (request.countValues("EFI_LEGEND_NORMAL_THICKNESS") ) {
		int legend_normal_thickness_value = request("EFI_LEGEND_NORMAL_THICKNESS");
		efijson_->legend_normal_thickness_ = legend_normal_thickness_value;
		}
	
	if  (request.countValues("EFI_LEGEND_NORMAL_COLOUR") ) {
		string legend_normal_colour_value = request("EFI_LEGEND_NORMAL_COLOUR");
		efijson_->legend_normal_colour_ = unique_ptr<Colour>(MagTranslator<string, Colour>()(legend_normal_colour_value));
	}
		
	
}

void EfiJSonWrapper::print(ostream& out)  const
{
	out << "EfiJSonWrapper[]";
}


    





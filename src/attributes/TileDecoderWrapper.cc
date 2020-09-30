
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file TileDecoderAttributes.h
    \\brief Definition of TileDecoder Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 2020-09-24
*/

#include "MagRequest.h" 
#include "TileDecoderWrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"

using namespace magics;


TileDecoderWrapper::TileDecoderWrapper(): tiledecoder_(new TileDecoder())

{

	
	
	
} 
TileDecoderWrapper::TileDecoderWrapper(TileDecoder* tiledecoder): tiledecoder_(tiledecoder)
{
	
	
} 

TileDecoderWrapper::~TileDecoderWrapper()
{
	
}

void TileDecoderWrapper::set(const MagRequest& request)
{
	
	

	if  (request.countValues("GRIB_INPUT_FILE_NAME") ) {
		string file_name_value = request("GRIB_INPUT_FILE_NAME");
		tiledecoder_->file_name_ = file_name_value;
		}
	if  (request.countValues("GRIB_TILE_PROJECTION") ) {
		string projection_value = request("GRIB_TILE_PROJECTION");
		tiledecoder_->projection_ = projection_value;
		}
	if  (request.countValues("GRIB_LOOP") ) {
		string loop_value = request("GRIB_LOOP");
		tiledecoder_->loop_ = MagTranslator<string, bool>()(loop_value);
		}
	if  (request.countValues("GRIB_TILE_Z") ) {
		int z_value = request("GRIB_TILE_Z");
		tiledecoder_->z_ = z_value;
		}
	if  (request.countValues("GRIB_TILE_X") ) {
		int x_value = request("GRIB_TILE_X");
		tiledecoder_->x_ = x_value;
		}
	if  (request.countValues("GRIB_TILE_Y") ) {
		int y_value = request("GRIB_TILE_Y");
		tiledecoder_->y_ = y_value;
		}
	if  (request.countValues("GRIB_AUTOMATIC_SCALING") ) {
		string scaling_value = request("GRIB_AUTOMATIC_SCALING");
		tiledecoder_->scaling_ = MagTranslator<string, bool>()(scaling_value);
		}
	if  (request.countValues("GRIB_SCALING_FACTOR") ) {
		double scaling_factor_value = request("GRIB_SCALING_FACTOR");
		tiledecoder_->scaling_factor_ = scaling_factor_value;
		}
	if  (request.countValues("GRIB_SCALING_OFFSET") ) {
		double scaling_offset_value = request("GRIB_SCALING_OFFSET");
		tiledecoder_->scaling_offset_ = scaling_offset_value;
		}
	
	
}

void TileDecoderWrapper::print(ostream& out)  const
{
	out << "TileDecoderWrapper[]";
}


    



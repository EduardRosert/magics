
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file GribDecoderAttributes.h
    \\brief Definition of GribDecoder Attributes class.

    This file is automatically generated.
    Do Not Edit!

*/

#include "MagRequest.h"
#include "GribDecoderWrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"
#include "MagicsGlobal.h"

using namespace magics;


GribDecoderWrapper::GribDecoderWrapper(): gribdecoder_(new GribDecoder())

{


	

}
GribDecoderWrapper::GribDecoderWrapper(GribDecoder* gribdecoder): gribdecoder_(gribdecoder)
{

	
}

GribDecoderWrapper::~GribDecoderWrapper()
{

}

void GribDecoderWrapper::set(const MagRequest& request)
{

	

	if  (request.countValues("GRIB_INPUT_FILE_NAME") ) {
		string file_name_value = request("GRIB_INPUT_FILE_NAME");
		gribdecoder_->file_name_ = file_name_value;
		}
	if  (request.countValues("GRIB_ID") ) {
		string id_value = request("GRIB_ID");
		gribdecoder_->id_ = id_value;
		}
	if  (request.countValues("GRIB_LOOP") ) {
		string loop_value = request("GRIB_LOOP");
		gribdecoder_->loop_ = MagTranslator<string, bool>()(loop_value);
		}
	if  (request.countValues("GRIB_AUTOMATIC_SCALING") ) {
		string scaling_value = request("GRIB_AUTOMATIC_SCALING");
		gribdecoder_->scaling_ = MagTranslator<string, bool>()(scaling_value);
		}
	if  (request.countValues("GRIB_AUTOMATIC_DERIVED_SCALING") ) {
		string derived_scaling_value = request("GRIB_AUTOMATIC_DERIVED_SCALING");
		gribdecoder_->derived_scaling_ = MagTranslator<string, bool>()(derived_scaling_value);
		}
	if  (request.countValues("GRIB_SCALING_FACTOR") ) {
		double scaling_factor_value = request("GRIB_SCALING_FACTOR");
		gribdecoder_->scaling_factor_ = scaling_factor_value;
		}
	if  (request.countValues("GRIB_SCALING_OFFSET") ) {
		double scaling_offset_value = request("GRIB_SCALING_OFFSET");
		gribdecoder_->scaling_offset_ = scaling_offset_value;
		}
	if  (request.countValues("GRIB_INTERPOLATION_REGULAR_RESOLUTION") ) {
		double regular_resolution_value = request("GRIB_INTERPOLATION_REGULAR_RESOLUTION");
		gribdecoder_->regular_resolution_ = regular_resolution_value;
		}
	if  (request.countValues("GRIB_INTERPOLATION_METHOD") ) {
		string interpolation_method_value = request("GRIB_INTERPOLATION_METHOD");
		gribdecoder_->interpolation_method_ = interpolation_method_value;
		}
	if  (request.countValues("GRIB_INTERPOLATION_METHOD_MISSING_FILL_COUNT") ) {
		int missing_fill_count_value = request("GRIB_INTERPOLATION_METHOD_MISSING_FILL_COUNT");
		gribdecoder_->missing_fill_count_ = missing_fill_count_value;
		}
	if  (request.countValues("GRIB_TEXT_EXPERIMENT") ) {
		string expver_value = request("GRIB_TEXT_EXPERIMENT");
		gribdecoder_->expver_ = MagTranslator<string, bool>()(expver_value);
		}
	if  (request.countValues("GRIB_TEXT_UNITS") ) {
		string units_value = request("GRIB_TEXT_UNITS");
		gribdecoder_->units_ = MagTranslator<string, bool>()(units_value);
		}
	if  (request.countValues("GRIB_FIELD_POSITION") ) {
		int field_position_value = request("GRIB_FIELD_POSITION");
		gribdecoder_->field_position_ = field_position_value;
		}
	if  (request.countValues("GRIB_WIND_POSITION_1") ) {
		int position_1_value = request("GRIB_WIND_POSITION_1");
		gribdecoder_->position_1_ = position_1_value;
		}
	if  (request.countValues("GRIB_WIND_POSITION_2") ) {
		int position_2_value = request("GRIB_WIND_POSITION_2");
		gribdecoder_->position_2_ = position_2_value;
		}
	if  (request.countValues("GRIB_WIND_POSITION_COLOUR") ) {
		int colour_position_value = request("GRIB_WIND_POSITION_COLOUR");
		gribdecoder_->colour_position_ = colour_position_value;
		}
	if  (request.countValues("GRIB_MISSING_VALUE_INDICATOR") ) {
		double missing_value_value = request("GRIB_MISSING_VALUE_INDICATOR");
		gribdecoder_->missing_value_ = missing_value_value;
		}
	
	
		string address_mode_value = request.countValues("GRIB_FILE_ADDRESS_MODE") ?  (string) request("GRIB_FILE_ADDRESS_MODE") : "record";
	MagLog::debug() << " GRIB_FILE_ADDRESS_MODE set to " << address_mode_value << endl;
	GribAddressModeWrapper* address_mode_wrapper = 0;
	try
	{
		address_mode_wrapper = SimpleFactory<GribAddressModeWrapper>::create(address_mode_value);
	}
	 catch (NoFactoryException&) {
		if (MagicsGlobal::strict()) {
            throw;
        }
		MagLog::warning() << "[" << address_mode_value << "] is not a valid value for address_mode: reset to default -> [record]" << endl;
		address_mode_wrapper = SimpleFactory<GribAddressModeWrapper>::create("record");
	}
	address_mode_wrapper->set(request);
	gribdecoder_->address_mode_ =  unique_ptr<GribAddressMode>(address_mode_wrapper->object());
	delete address_mode_wrapper;
	
		string wind_mode_value = request.countValues("GRIB_WIND_MODE") ?  (string) request("GRIB_WIND_MODE") : "uv";
	MagLog::debug() << " GRIB_WIND_MODE set to " << wind_mode_value << endl;
	WindModeWrapper* wind_mode_wrapper = 0;
	try
	{
		wind_mode_wrapper = SimpleFactory<WindModeWrapper>::create(wind_mode_value);
	}
	 catch (NoFactoryException&) {
		if (MagicsGlobal::strict()) {
            throw;
        }
		MagLog::warning() << "[" << wind_mode_value << "] is not a valid value for wind_mode: reset to default -> [uv]" << endl;
		wind_mode_wrapper = SimpleFactory<WindModeWrapper>::create("uv");
	}
	wind_mode_wrapper->set(request);
	gribdecoder_->wind_mode_ =  unique_ptr<WindMode>(wind_mode_wrapper->object());
	delete wind_mode_wrapper;
	
}

void GribDecoderWrapper::print(ostream& out)  const
{
	out << "GribDecoderWrapper[]";
}


#include "GribAddressRecordModeWrapper.h"
static SimpleObjectMaker<GribAddressRecordMode, GribAddressMode> GribDecoder_grib_file_address_mode_record ("record");
static SimpleObjectMaker<GribAddressRecordModeWrapper, GribAddressModeWrapper> GribDecoder_grib_file_address_mode_record_wrapper ("record");


#include "GribAddressByteModeWrapper.h"
static SimpleObjectMaker<GribAddressByteMode, GribAddressMode> GribDecoder_grib_file_address_mode_byte_offset ("byte_offset");
static SimpleObjectMaker<GribAddressByteModeWrapper, GribAddressModeWrapper> GribDecoder_grib_file_address_mode_byte_offset_wrapper ("byte_offset");



#include "UVWindModeWrapper.h"
static SimpleObjectMaker<UVWindMode, WindMode> GribDecoder_grib_wind_mode_uvmode ("uvmode");
static SimpleObjectMaker<UVWindModeWrapper, WindModeWrapper> GribDecoder_grib_wind_mode_uvmode_wrapper ("uvmode");


#include "UVWindModeWrapper.h"
static SimpleObjectMaker<UVWindMode, WindMode> GribDecoder_grib_wind_mode_uv ("uv");
static SimpleObjectMaker<UVWindModeWrapper, WindModeWrapper> GribDecoder_grib_wind_mode_uv_wrapper ("uv");


#include "SDWindModeWrapper.h"
static SimpleObjectMaker<SDWindMode, WindMode> GribDecoder_grib_wind_mode_vdmode ("vdmode");
static SimpleObjectMaker<SDWindModeWrapper, WindModeWrapper> GribDecoder_grib_wind_mode_vdmode_wrapper ("vdmode");


#include "SDWindModeWrapper.h"
static SimpleObjectMaker<SDWindMode, WindMode> GribDecoder_grib_wind_mode_sd ("sd");
static SimpleObjectMaker<SDWindModeWrapper, WindModeWrapper> GribDecoder_grib_wind_mode_sd_wrapper ("sd");





/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file MapGenDecoderAttributes.h
    \\brief Definition of MapGenDecoder Attributes class.

    This file is automatically generated.
    Do Not Edit!

*/

#include "MagRequest.h"
#include "MapGenDecoderWrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"
#include "MagicsGlobal.h"

using namespace magics;



MapGenDecoderWrapper::MapGenDecoderWrapper(): mapgendecoder_(new MapGenDecoder())


{


	

}
MapGenDecoderWrapper::MapGenDecoderWrapper(MapGenDecoder* mapgendecoder): mapgendecoder_(mapgendecoder)
{

	
}

MapGenDecoderWrapper::~MapGenDecoderWrapper()
{

}

void MapGenDecoderWrapper::set(const MagRequest& request)
{

	

	if  (request.countValues("MAPGEN_INPUT_FILE_NAME") ) {
		string path_value = request("MAPGEN_INPUT_FILE_NAME");
		mapgendecoder_->path_ = path_value;
		}
	if  (request.countValues("MAPGEN_RECORD") ) {
		int record_value = request("MAPGEN_RECORD");
		mapgendecoder_->record_ = record_value;
		}
	
	
}

void MapGenDecoderWrapper::print(ostream& out)  const
{
	out << "MapGenDecoderWrapper[]";
}



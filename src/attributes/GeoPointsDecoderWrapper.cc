
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file GeoPointsDecoderAttributes.h
    \\brief Definition of GeoPointsDecoder Attributes class.

    This file is automatically generated.
    Do Not Edit!

*/

#include "MagRequest.h"
#include "GeoPointsDecoderWrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"
#include "MagicsGlobal.h"

using namespace magics;


GeoPointsDecoderWrapper::GeoPointsDecoderWrapper(): geopointsdecoder_(new GeoPointsDecoder())

{


	

}
GeoPointsDecoderWrapper::GeoPointsDecoderWrapper(GeoPointsDecoder* geopointsdecoder): geopointsdecoder_(geopointsdecoder)
{

	
}

GeoPointsDecoderWrapper::~GeoPointsDecoderWrapper()
{

}

void GeoPointsDecoderWrapper::set(const MagRequest& request)
{

	

	if  (request.countValues("GEO_INPUT_FILE_NAME") ) {
		string path_value = request("GEO_INPUT_FILE_NAME");
		geopointsdecoder_->path_ = path_value;
		}
	if  (request.countValues("GEO_MISSING_VALUE") ) {
		double missing_value = request("GEO_MISSING_VALUE");
		geopointsdecoder_->missing_ = missing_value;
		}
	
	
}

void GeoPointsDecoderWrapper::print(ostream& out)  const
{
	out << "GeoPointsDecoderWrapper[]";
}



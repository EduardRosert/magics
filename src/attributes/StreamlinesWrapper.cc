
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file StreamlinesAttributes.h
    \\brief Definition of Streamlines Attributes class.

    This file is automatically generated.
    Do Not Edit!

*/

#include "MagRequest.h"
#include "StreamlinesWrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"
#include "MagicsSettings.h"

using namespace magics;


StreamlinesWrapper::StreamlinesWrapper(): streamlines_(new Streamlines())

{


	
	WindPlottingWrapper::object(streamlines_);
	

}
StreamlinesWrapper::StreamlinesWrapper(Streamlines* streamlines): streamlines_(streamlines)
{

	
	WindPlottingWrapper::object(streamlines_);
	
}

StreamlinesWrapper::~StreamlinesWrapper()
{

}

void StreamlinesWrapper::set(const MagRequest& request)
{

	

	WindPlottingWrapper::set(request);
	

	if  (request.countValues("WIND_STREAMLINE_MIN_DENSITY") ) {
		double min_density_value = request("WIND_STREAMLINE_MIN_DENSITY");
		streamlines_->min_density_ = min_density_value;
		}
	if  (request.countValues("WIND_STREAMLINE_MIN_SPEED") ) {
		double min_speed_value = request("WIND_STREAMLINE_MIN_SPEED");
		streamlines_->min_speed_ = min_speed_value;
		}
	if  (request.countValues("WIND_STREAMLINE_THICKNESS") ) {
		int thickness_value = request("WIND_STREAMLINE_THICKNESS");
		streamlines_->thickness_ = thickness_value;
		}
	if  (request.countValues("WIND_STREAMLINE_HEAD_SHAPE") ) {
		int head_value = request("WIND_STREAMLINE_HEAD_SHAPE");
		streamlines_->head_ = head_value;
		}
	if  (request.countValues("WIND_STREAMLINE_HEAD_RATIO") ) {
		double ratio_value = request("WIND_STREAMLINE_HEAD_RATIO");
		streamlines_->ratio_ = ratio_value;
		}
	
	if  (request.countValues("WIND_STREAMLINE_COLOUR") ) {
		string colour_value = request("WIND_STREAMLINE_COLOUR");
		streamlines_->colour_ = unique_ptr<Colour>(MagTranslator<string, Colour>()(colour_value));
	}
		
	
	if  (request.countValues("WIND_STREAMLINE_STYLE") ) {
		string style_value = request("WIND_STREAMLINE_STYLE");
		streamlines_->style_ = MagTranslator<string, LineStyle>()(style_value);
	}
		
	
}

void StreamlinesWrapper::print(ostream& out)  const
{
	out << "StreamlinesWrapper[]";
}





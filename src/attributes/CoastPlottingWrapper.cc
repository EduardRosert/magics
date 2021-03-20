
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file CoastPlottingAttributes.h
    \\brief Definition of CoastPlotting Attributes class.

    This file is automatically generated.
    Do Not Edit!

*/

#include "MagRequest.h"
#include "CoastPlottingWrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"
#include "MagicsGlobal.h"

using namespace magics;


CoastPlottingWrapper::CoastPlottingWrapper(): coastplotting_(new CoastPlotting())

{


	
	NoCoastPlottingWrapper::object(coastplotting_);
	

}
CoastPlottingWrapper::CoastPlottingWrapper(CoastPlotting* coastplotting): coastplotting_(coastplotting)
{

	
	NoCoastPlottingWrapper::object(coastplotting_);
	
}

CoastPlottingWrapper::~CoastPlottingWrapper()
{

}

void CoastPlottingWrapper::set(const MagRequest& request)
{

	

	NoCoastPlottingWrapper::set(request);
	

	if  (request.countValues("MAP_COASTLINE_THICKNESS") ) {
		int thickness_value = request("MAP_COASTLINE_THICKNESS");
		coastplotting_->thickness_ = thickness_value;
		}
	
	if  (request.countValues("MAP_COASTLINE_COLOUR") ) {
		string colour_value = request("MAP_COASTLINE_COLOUR");
		coastplotting_->colour_ = unique_ptr<Colour>(MagTranslator<string, Colour>()(colour_value));
	}
		
	
	if  (request.countValues("MAP_COASTLINE_STYLE") ) {
		string style_value = request("MAP_COASTLINE_STYLE");
		coastplotting_->style_ = MagTranslator<string, LineStyle>()(style_value);
	}
		
	
}

void CoastPlottingWrapper::print(ostream& out)  const
{
	out << "CoastPlottingWrapper[]";
}





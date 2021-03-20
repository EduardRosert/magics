
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file WindAttributes.h
    \\brief Definition of Wind Attributes class.

    This file is automatically generated.
    Do Not Edit!

*/

#include "MagRequest.h"
#include "WindWrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"
#include "MagicsGlobal.h"

using namespace magics;


WindWrapper::WindWrapper(): wind_(new Wind())

{


	

}
WindWrapper::WindWrapper(Wind* wind): wind_(wind)
{

	
}

WindWrapper::~WindWrapper()
{

}

void WindWrapper::set(const MagRequest& request)
{

	

	if  (request.countValues("WIND_THINNING_METHOD") ) {
		string thinning_method_value = request("WIND_THINNING_METHOD");
		wind_->thinning_method_ = thinning_method_value;
		}
	if  (request.countValues("WIND_THINNING_FACTOR") ) {
		double thinning_factor_value = request("WIND_THINNING_FACTOR");
		wind_->thinning_factor_ = thinning_factor_value;
		}
	if  (request.countValues("WIND_THINNING_DEBUG") ) {
		string thinning_debug_value = request("WIND_THINNING_DEBUG");
		wind_->thinning_debug_ = MagTranslator<string, bool>()(thinning_debug_value);
		}
	
	
		string type_value = request.countValues("WIND_FIELD_TYPE") ?  (string) request("WIND_FIELD_TYPE") : "arrows";
	MagLog::debug() << " WIND_FIELD_TYPE set to " << type_value << endl;
	WindPlottingWrapper* type_wrapper = 0;
	try
	{
		type_wrapper = SimpleFactory<WindPlottingWrapper>::create(type_value);
	}
	 catch (NoFactoryException&) {
		if (MagicsGlobal::strict()) {
            throw;
        }
		MagLog::warning() << "[" << type_value << "] is not a valid value for type: reset to default -> [arrows]" << endl;
		type_wrapper = SimpleFactory<WindPlottingWrapper>::create("arrows");
	}
	type_wrapper->set(request);
	wind_->type_ =  unique_ptr<WindPlotting>(type_wrapper->object());
	delete type_wrapper;
	
}

void WindWrapper::print(ostream& out)  const
{
	out << "WindWrapper[]";
}


#include "FlagPlottingWrapper.h"
static SimpleObjectMaker<FlagPlotting, WindPlotting> Wind_wind_field_type_flags ("flags");
static SimpleObjectMaker<FlagPlottingWrapper, WindPlottingWrapper> Wind_wind_field_type_flags_wrapper ("flags");


#include "ArrowPlottingWrapper.h"
static SimpleObjectMaker<ArrowPlotting, WindPlotting> Wind_wind_field_type_arrows ("arrows");
static SimpleObjectMaker<ArrowPlottingWrapper, WindPlottingWrapper> Wind_wind_field_type_arrows_wrapper ("arrows");


#include "StreamlinesWrapper.h"
static SimpleObjectMaker<Streamlines, WindPlotting> Wind_wind_field_type_streamlines ("streamlines");
static SimpleObjectMaker<StreamlinesWrapper, WindPlottingWrapper> Wind_wind_field_type_streamlines_wrapper ("streamlines");




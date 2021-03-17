
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file CartesianTransformationAttributes.h
    \\brief Definition of CartesianTransformation Attributes class.

    This file is automatically generated.
    Do Not Edit!

*/

#include "MagRequest.h"
#include "CartesianTransformationWrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"
#include "MagicsSettings.h"

using namespace magics;


CartesianTransformationWrapper::CartesianTransformationWrapper(): cartesiantransformation_(new CartesianTransformation())

{


	
	TransformationWrapper::object(cartesiantransformation_);
	

}
CartesianTransformationWrapper::CartesianTransformationWrapper(CartesianTransformation* cartesiantransformation): cartesiantransformation_(cartesiantransformation)
{

	
	TransformationWrapper::object(cartesiantransformation_);
	
}

CartesianTransformationWrapper::~CartesianTransformationWrapper()
{

}

void CartesianTransformationWrapper::set(const MagRequest& request)
{

	

	TransformationWrapper::set(request);
	

	
	
		string x_value = request.countValues("X_AXIS_TYPE") ?  (string) request("X_AXIS_TYPE") : "regular";
	MagLog::debug() << " X_AXIS_TYPE set to " << x_value << endl;
	XCoordinateWrapper* x_wrapper = 0;
	try
	{
		x_wrapper = SimpleFactory<XCoordinateWrapper>::create(x_value);
	}
	 catch (NoFactoryException&) {
		if (MagicsSettings::strict()) {
            throw;
        }
		MagLog::warning() << "[" << x_value << "] is not a valid value for x: reset to default -> [regular]" << endl;
		x_wrapper = SimpleFactory<XCoordinateWrapper>::create("regular");
	}
	x_wrapper->set(request);
	cartesiantransformation_->x_ =  unique_ptr<XCoordinate>(x_wrapper->object());
	delete x_wrapper;
	
		string y_value = request.countValues("Y_AXIS_TYPE") ?  (string) request("Y_AXIS_TYPE") : "regular";
	MagLog::debug() << " Y_AXIS_TYPE set to " << y_value << endl;
	YCoordinateWrapper* y_wrapper = 0;
	try
	{
		y_wrapper = SimpleFactory<YCoordinateWrapper>::create(y_value);
	}
	 catch (NoFactoryException&) {
		if (MagicsSettings::strict()) {
            throw;
        }
		MagLog::warning() << "[" << y_value << "] is not a valid value for y: reset to default -> [regular]" << endl;
		y_wrapper = SimpleFactory<YCoordinateWrapper>::create("regular");
	}
	y_wrapper->set(request);
	cartesiantransformation_->y_ =  unique_ptr<YCoordinate>(y_wrapper->object());
	delete y_wrapper;
	
}

void CartesianTransformationWrapper::print(ostream& out)  const
{
	out << "CartesianTransformationWrapper[]";
}


#include "XRegularCoordinateWrapper.h"
static SimpleObjectMaker<XRegularCoordinate, XCoordinate> CartesianTransformation_x_axis_type_x_regular ("x_regular");
static SimpleObjectMaker<XRegularCoordinateWrapper, XCoordinateWrapper> CartesianTransformation_x_axis_type_x_regular_wrapper ("x_regular");


#include "XRegularCoordinateWrapper.h"
static SimpleObjectMaker<XRegularCoordinate, XCoordinate> CartesianTransformation_x_axis_type_regular ("regular");
static SimpleObjectMaker<XRegularCoordinateWrapper, XCoordinateWrapper> CartesianTransformation_x_axis_type_regular_wrapper ("regular");


#include "XDateCoordinateWrapper.h"
static SimpleObjectMaker<XDateCoordinate, XCoordinate> CartesianTransformation_x_axis_type_x_date ("x_date");
static SimpleObjectMaker<XDateCoordinateWrapper, XCoordinateWrapper> CartesianTransformation_x_axis_type_x_date_wrapper ("x_date");


#include "XDateCoordinateWrapper.h"
static SimpleObjectMaker<XDateCoordinate, XCoordinate> CartesianTransformation_x_axis_type_date ("date");
static SimpleObjectMaker<XDateCoordinateWrapper, XCoordinateWrapper> CartesianTransformation_x_axis_type_date_wrapper ("date");


#include "XHyperCoordinateWrapper.h"
static SimpleObjectMaker<XHyperCoordinate, XCoordinate> CartesianTransformation_x_axis_type_x_hyper ("x_hyper");
static SimpleObjectMaker<XHyperCoordinateWrapper, XCoordinateWrapper> CartesianTransformation_x_axis_type_x_hyper_wrapper ("x_hyper");


#include "XHyperCoordinateWrapper.h"
static SimpleObjectMaker<XHyperCoordinate, XCoordinate> CartesianTransformation_x_axis_type_geoline ("geoline");
static SimpleObjectMaker<XHyperCoordinateWrapper, XCoordinateWrapper> CartesianTransformation_x_axis_type_geoline_wrapper ("geoline");


#include "XLogarithmicCoordinateWrapper.h"
static SimpleObjectMaker<XLogarithmicCoordinate, XCoordinate> CartesianTransformation_x_axis_type_x_logarithmic ("x_logarithmic");
static SimpleObjectMaker<XLogarithmicCoordinateWrapper, XCoordinateWrapper> CartesianTransformation_x_axis_type_x_logarithmic_wrapper ("x_logarithmic");


#include "XLogarithmicCoordinateWrapper.h"
static SimpleObjectMaker<XLogarithmicCoordinate, XCoordinate> CartesianTransformation_x_axis_type_logarithmic ("logarithmic");
static SimpleObjectMaker<XLogarithmicCoordinateWrapper, XCoordinateWrapper> CartesianTransformation_x_axis_type_logarithmic_wrapper ("logarithmic");



#include "YRegularCoordinateWrapper.h"
static SimpleObjectMaker<YRegularCoordinate, YCoordinate> CartesianTransformation_y_axis_type_y_regular ("y_regular");
static SimpleObjectMaker<YRegularCoordinateWrapper, YCoordinateWrapper> CartesianTransformation_y_axis_type_y_regular_wrapper ("y_regular");


#include "YRegularCoordinateWrapper.h"
static SimpleObjectMaker<YRegularCoordinate, YCoordinate> CartesianTransformation_y_axis_type_regular ("regular");
static SimpleObjectMaker<YRegularCoordinateWrapper, YCoordinateWrapper> CartesianTransformation_y_axis_type_regular_wrapper ("regular");


#include "YDateCoordinateWrapper.h"
static SimpleObjectMaker<YDateCoordinate, YCoordinate> CartesianTransformation_y_axis_type_y_date ("y_date");
static SimpleObjectMaker<YDateCoordinateWrapper, YCoordinateWrapper> CartesianTransformation_y_axis_type_y_date_wrapper ("y_date");


#include "YDateCoordinateWrapper.h"
static SimpleObjectMaker<YDateCoordinate, YCoordinate> CartesianTransformation_y_axis_type_date ("date");
static SimpleObjectMaker<YDateCoordinateWrapper, YCoordinateWrapper> CartesianTransformation_y_axis_type_date_wrapper ("date");


#include "YHyperCoordinateWrapper.h"
static SimpleObjectMaker<YHyperCoordinate, YCoordinate> CartesianTransformation_y_axis_type_y_hyper ("y_hyper");
static SimpleObjectMaker<YHyperCoordinateWrapper, YCoordinateWrapper> CartesianTransformation_y_axis_type_y_hyper_wrapper ("y_hyper");


#include "YHyperCoordinateWrapper.h"
static SimpleObjectMaker<YHyperCoordinate, YCoordinate> CartesianTransformation_y_axis_type_geoline ("geoline");
static SimpleObjectMaker<YHyperCoordinateWrapper, YCoordinateWrapper> CartesianTransformation_y_axis_type_geoline_wrapper ("geoline");


#include "YLogarithmicCoordinateWrapper.h"
static SimpleObjectMaker<YLogarithmicCoordinate, YCoordinate> CartesianTransformation_y_axis_type_y_logarithmic ("y_logarithmic");
static SimpleObjectMaker<YLogarithmicCoordinateWrapper, YCoordinateWrapper> CartesianTransformation_y_axis_type_y_logarithmic_wrapper ("y_logarithmic");


#include "YLogarithmicCoordinateWrapper.h"
static SimpleObjectMaker<YLogarithmicCoordinate, YCoordinate> CartesianTransformation_y_axis_type_logarithmic ("logarithmic");
static SimpleObjectMaker<YLogarithmicCoordinateWrapper, YCoordinateWrapper> CartesianTransformation_y_axis_type_logarithmic_wrapper ("logarithmic");




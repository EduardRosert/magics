
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file XmlViewNodeAttributes.h
    \\brief Definition of XmlViewNode Attributes class.

    This file is automatically generated.
    Do Not Edit!
*/

#include "MagRequest.h" 
#include "XmlViewNodeWrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"

using namespace magics;



XmlViewNodeWrapper::XmlViewNodeWrapper(): xmlviewnode_(new XmlViewNode())


{

	
	
	XmlBasicNodeWrapper::object(xmlviewnode_);
	
	
} 
XmlViewNodeWrapper::XmlViewNodeWrapper(XmlViewNode* xmlviewnode): xmlviewnode_(xmlviewnode)
{
	
	
	XmlBasicNodeWrapper::object(xmlviewnode_);
	
} 

XmlViewNodeWrapper::~XmlViewNodeWrapper()
{
	
}

void XmlViewNodeWrapper::set(const MagRequest& request)
{
	
	
	
	XmlBasicNodeWrapper::set(request);
	

	if  (request.countValues("VIEW_FITTED_MODE") ) {
		string fitted_value = request("VIEW_FITTED_MODE");
		xmlviewnode_->fitted_ = fitted_value;
		}
	
	
		string transformation_value = request.countValues("SUBPAGE_MAP_PROJECTION") ?  (string) request("SUBPAGE_MAP_PROJECTION") : "cylindrical";
	MagLog::debug() << " SUBPAGE_MAP_PROJECTION set to " << transformation_value << endl;
	TransformationWrapper* transformation_wrapper = 0;
	try
	{
		transformation_wrapper = SimpleFactory<TransformationWrapper>::create(transformation_value);
	}
	 catch (NoFactoryException) {
		MagLog::warning() << "[" << transformation_value << "] is not a valid value for transformation: reset to default -> [cylindrical]" << endl;
		transformation_wrapper = SimpleFactory<TransformationWrapper>::create("cylindrical");
	}
	transformation_wrapper->set(request);
	xmlviewnode_->transformation_ =  unique_ptr<Transformation>(transformation_wrapper->object());
	delete transformation_wrapper;
	
}

void XmlViewNodeWrapper::print(ostream& out)  const
{
	out << "XmlViewNodeWrapper[]";
}


    



#include "GeoRectangularProjectionWrapper.h"
static SimpleObjectMaker<GeoRectangularProjection, Transformation> XmlViewNode_subpage_map_projection_cylindrical ("cylindrical");
static SimpleObjectMaker<GeoRectangularProjectionWrapper, TransformationWrapper> XmlViewNode_subpage_map_projection_cylindrical_wrapper ("cylindrical");


#include "CartesianTransformationWrapper.h"
static SimpleObjectMaker<CartesianTransformation, Transformation> XmlViewNode_subpage_map_projection_cartesian ("cartesian");
static SimpleObjectMaker<CartesianTransformationWrapper, TransformationWrapper> XmlViewNode_subpage_map_projection_cartesian_wrapper ("cartesian");


#include "CartesianTransformationWrapper.h"
static SimpleObjectMaker<CartesianTransformation, Transformation> XmlViewNode_subpage_map_projection_none ("none");
static SimpleObjectMaker<CartesianTransformationWrapper, TransformationWrapper> XmlViewNode_subpage_map_projection_none_wrapper ("none");


#include "TaylorProjectionWrapper.h"
static SimpleObjectMaker<TaylorProjection, Transformation> XmlViewNode_subpage_map_projection_taylor ("taylor");
static SimpleObjectMaker<TaylorProjectionWrapper, TransformationWrapper> XmlViewNode_subpage_map_projection_taylor_wrapper ("taylor");


#include "TephigramWrapper.h"
static SimpleObjectMaker<Tephigram, Transformation> XmlViewNode_subpage_map_projection_tephigram ("tephigram");
static SimpleObjectMaker<TephigramWrapper, TransformationWrapper> XmlViewNode_subpage_map_projection_tephigram_wrapper ("tephigram");


#include "SkewtWrapper.h"
static SimpleObjectMaker<Skewt, Transformation> XmlViewNode_subpage_map_projection_skew_t ("skew_t");
static SimpleObjectMaker<SkewtWrapper, TransformationWrapper> XmlViewNode_subpage_map_projection_skew_t_wrapper ("skew_t");


#include "EmagramWrapper.h"
static SimpleObjectMaker<Emagram, Transformation> XmlViewNode_subpage_map_projection_emagram ("emagram");
static SimpleObjectMaker<EmagramWrapper, TransformationWrapper> XmlViewNode_subpage_map_projection_emagram_wrapper ("emagram");




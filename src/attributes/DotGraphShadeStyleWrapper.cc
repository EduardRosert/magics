
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file DotGraphShadeStyleAttributes.h
    \\brief Definition of DotGraphShadeStyle Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 2020-09-24
*/

#include "MagRequest.h" 
#include "DotGraphShadeStyleWrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"

using namespace magics;


DotGraphShadeStyleWrapper::DotGraphShadeStyleWrapper(): dotgraphshadestyle_(new DotGraphShadeStyle())

{

	
	
	GraphShadeStyleWrapper::object(dotgraphshadestyle_);
	
	
} 
DotGraphShadeStyleWrapper::DotGraphShadeStyleWrapper(DotGraphShadeStyle* dotgraphshadestyle): dotgraphshadestyle_(dotgraphshadestyle)
{
	
	
	GraphShadeStyleWrapper::object(dotgraphshadestyle_);
	
} 

DotGraphShadeStyleWrapper::~DotGraphShadeStyleWrapper()
{
	
}

void DotGraphShadeStyleWrapper::set(const MagRequest& request)
{
	
	
	
	GraphShadeStyleWrapper::set(request);
	

	if  (request.countValues("GRAPH_SHADE_DOT_DENSITY") ) {
		int density_value = request("GRAPH_SHADE_DOT_DENSITY");
		dotgraphshadestyle_->density_ = density_value;
		}
	if  (request.countValues("GRAPH_SHADE_DOT_SIZE") ) {
		double size_value = request("GRAPH_SHADE_DOT_SIZE");
		dotgraphshadestyle_->size_ = size_value;
		}
	
	
}

void DotGraphShadeStyleWrapper::print(ostream& out)  const
{
	out << "DotGraphShadeStyleWrapper[]";
}


    



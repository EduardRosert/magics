
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file HatchGraphShadeStyleAttributes.h
    \\brief Definition of HatchGraphShadeStyle Attributes class.

    This file is automatically generated.
    Do Not Edit!
*/

#include "MagRequest.h" 
#include "HatchGraphShadeStyleWrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"

using namespace magics;



HatchGraphShadeStyleWrapper::HatchGraphShadeStyleWrapper(): hatchgraphshadestyle_(new HatchGraphShadeStyle())


{

	
	
	GraphShadeStyleWrapper::object(hatchgraphshadestyle_);
	
	
} 
HatchGraphShadeStyleWrapper::HatchGraphShadeStyleWrapper(HatchGraphShadeStyle* hatchgraphshadestyle): hatchgraphshadestyle_(hatchgraphshadestyle)
{
	
	
	GraphShadeStyleWrapper::object(hatchgraphshadestyle_);
	
} 

HatchGraphShadeStyleWrapper::~HatchGraphShadeStyleWrapper()
{
	
}

void HatchGraphShadeStyleWrapper::set(const MagRequest& request)
{
	
	
	
	GraphShadeStyleWrapper::set(request);
	

	if  (request.countValues("GRAPH_SHADE_HATCH_INDEX") ) {
		int index_value = request("GRAPH_SHADE_HATCH_INDEX");
		hatchgraphshadestyle_->index_ = index_value;
		}
	
	
}

void HatchGraphShadeStyleWrapper::print(ostream& out)  const
{
	out << "HatchGraphShadeStyleWrapper[]";
}


    




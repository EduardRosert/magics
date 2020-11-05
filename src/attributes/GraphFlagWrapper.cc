
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file GraphFlagAttributes.h
    \\brief Definition of GraphFlag Attributes class.

    This file is automatically generated.
    Do Not Edit!
*/

#include "MagRequest.h" 
#include "GraphFlagWrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"

using namespace magics;


GraphFlagWrapper::GraphFlagWrapper(): graphflag_(new GraphFlag())

{

	
	
	GraphWrapper::object(graphflag_);
	
	
} 
GraphFlagWrapper::GraphFlagWrapper(GraphFlag* graphflag): graphflag_(graphflag)
{
	
	
	GraphWrapper::object(graphflag_);
	
} 

GraphFlagWrapper::~GraphFlagWrapper()
{
	
}

void GraphFlagWrapper::set(const MagRequest& request)
{
	
	
	
	GraphWrapper::set(request);
	

	if  (request.countValues("GRAPH_FLAG_LENGTH") ) {
		double length_value = request("GRAPH_FLAG_LENGTH");
		graphflag_->length_ = length_value;
		}
	
	if  (request.countValues("GRAPH_FLAG_COLOUR") ) {
		string colour_value = request("GRAPH_FLAG_COLOUR");
		graphflag_->colour_ = unique_ptr<Colour>(MagTranslator<string, Colour>()(colour_value));
	}
		
	
}

void GraphFlagWrapper::print(ostream& out)  const
{
	out << "GraphFlagWrapper[]";
}


    





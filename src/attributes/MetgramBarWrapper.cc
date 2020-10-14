
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file MetgramBarAttributes.h
    \\brief Definition of MetgramBar Attributes class.

    This file is automatically generated.
    Do Not Edit!
*/

#include "MagRequest.h" 
#include "MetgramBarWrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"

using namespace magics;


MetgramBarWrapper::MetgramBarWrapper(): metgrambar_(new MetgramBar())

{

	
	
	
} 
MetgramBarWrapper::MetgramBarWrapper(MetgramBar* metgrambar): metgrambar_(metgrambar)
{
	
	
} 

MetgramBarWrapper::~MetgramBarWrapper()
{
	
}

void MetgramBarWrapper::set(const MagRequest& request)
{
	
	

	if  (request.countValues("METGRAM_BAR_KEYWORD") ) {
		string keyword_value = request("METGRAM_BAR_KEYWORD");
		metgrambar_->keyword_ = keyword_value;
		}
	
	if  (request.countValues("METGRAM_BAR_COLOUR") ) {
		string colour_value = request("METGRAM_BAR_COLOUR");
		metgrambar_->colour_ = unique_ptr<Colour>(MagTranslator<string, Colour>()(colour_value));
	}
		
	
}

void MetgramBarWrapper::print(ostream& out)  const
{
	out << "MetgramBarWrapper[]";
}


    





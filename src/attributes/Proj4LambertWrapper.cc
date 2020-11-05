
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file Proj4LambertAttributes.h
    \\brief Definition of Proj4Lambert Attributes class.

    This file is automatically generated.
    Do Not Edit!
*/

#include "MagRequest.h" 
#include "Proj4LambertWrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"

using namespace magics;


Proj4LambertWrapper::Proj4LambertWrapper(): proj4lambert_(new Proj4Lambert())

{

	
	
	Proj4ProjectionWrapper::object(proj4lambert_);
	
	
} 
Proj4LambertWrapper::Proj4LambertWrapper(Proj4Lambert* proj4lambert): proj4lambert_(proj4lambert)
{
	
	
	Proj4ProjectionWrapper::object(proj4lambert_);
	
} 

Proj4LambertWrapper::~Proj4LambertWrapper()
{
	
}

void Proj4LambertWrapper::set(const MagRequest& request)
{
	
	
	
	Proj4ProjectionWrapper::set(request);
	

	
	
}

void Proj4LambertWrapper::print(ostream& out)  const
{
	out << "Proj4LambertWrapper[]";
}


    




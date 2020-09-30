
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file Proj4PolarSouthAttributes.h
    \\brief Definition of Proj4PolarSouth Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 2020-09-24
*/

#include "MagRequest.h" 
#include "Proj4PolarSouthWrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"

using namespace magics;


Proj4PolarSouthWrapper::Proj4PolarSouthWrapper(): proj4polarsouth_(new Proj4PolarSouth())

{

	
	
	Proj4ProjectionWrapper::object(proj4polarsouth_);
	
	
} 
Proj4PolarSouthWrapper::Proj4PolarSouthWrapper(Proj4PolarSouth* proj4polarsouth): proj4polarsouth_(proj4polarsouth)
{
	
	
	Proj4ProjectionWrapper::object(proj4polarsouth_);
	
} 

Proj4PolarSouthWrapper::~Proj4PolarSouthWrapper()
{
	
}

void Proj4PolarSouthWrapper::set(const MagRequest& request)
{
	
	
	
	Proj4ProjectionWrapper::set(request);
	

	
	
}

void Proj4PolarSouthWrapper::print(ostream& out)  const
{
	out << "Proj4PolarSouthWrapper[]";
}


    



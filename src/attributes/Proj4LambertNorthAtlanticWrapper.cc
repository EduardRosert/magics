
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file Proj4LambertNorthAtlanticAttributes.h
    \\brief Definition of Proj4LambertNorthAtlantic Attributes class.

    This file is automatically generated.
    Do Not Edit!

*/

#include "MagRequest.h"
#include "Proj4LambertNorthAtlanticWrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"
#include "MagicsGlobal.h"

using namespace magics;


Proj4LambertNorthAtlanticWrapper::Proj4LambertNorthAtlanticWrapper(): proj4lambertnorthatlantic_(new Proj4LambertNorthAtlantic())

{


	
	Proj4ProjectionWrapper::object(proj4lambertnorthatlantic_);
	

}
Proj4LambertNorthAtlanticWrapper::Proj4LambertNorthAtlanticWrapper(Proj4LambertNorthAtlantic* proj4lambertnorthatlantic): proj4lambertnorthatlantic_(proj4lambertnorthatlantic)
{

	
	Proj4ProjectionWrapper::object(proj4lambertnorthatlantic_);
	
}

Proj4LambertNorthAtlanticWrapper::~Proj4LambertNorthAtlanticWrapper()
{

}

void Proj4LambertNorthAtlanticWrapper::set(const MagRequest& request)
{

	

	Proj4ProjectionWrapper::set(request);
	

	
	
}

void Proj4LambertNorthAtlanticWrapper::print(ostream& out)  const
{
	out << "Proj4LambertNorthAtlanticWrapper[]";
}



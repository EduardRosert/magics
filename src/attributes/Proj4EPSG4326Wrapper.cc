
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file Proj4EPSG4326Attributes.h
    \\brief Definition of Proj4EPSG4326 Attributes class.

    This file is automatically generated.
    Do Not Edit!

*/

#include "MagRequest.h"
#include "Proj4EPSG4326Wrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"
#include "MagicsGlobal.h"

using namespace magics;


Proj4EPSG4326Wrapper::Proj4EPSG4326Wrapper(): proj4epsg4326_(new Proj4EPSG4326())

{


	
	Proj4ProjectionWrapper::object(proj4epsg4326_);
	

}
Proj4EPSG4326Wrapper::Proj4EPSG4326Wrapper(Proj4EPSG4326* proj4epsg4326): proj4epsg4326_(proj4epsg4326)
{

	
	Proj4ProjectionWrapper::object(proj4epsg4326_);
	
}

Proj4EPSG4326Wrapper::~Proj4EPSG4326Wrapper()
{

}

void Proj4EPSG4326Wrapper::set(const MagRequest& request)
{

	

	Proj4ProjectionWrapper::set(request);
	

	
	
}

void Proj4EPSG4326Wrapper::print(ostream& out)  const
{
	out << "Proj4EPSG4326Wrapper[]";
}



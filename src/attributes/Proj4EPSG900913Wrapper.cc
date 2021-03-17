
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file Proj4EPSG900913Attributes.h
    \\brief Definition of Proj4EPSG900913 Attributes class.

    This file is automatically generated.
    Do Not Edit!

*/

#include "MagRequest.h"
#include "Proj4EPSG900913Wrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"
#include "MagicsSettings.h"

using namespace magics;


Proj4EPSG900913Wrapper::Proj4EPSG900913Wrapper(): proj4epsg900913_(new Proj4EPSG900913())

{


	
	Proj4ProjectionWrapper::object(proj4epsg900913_);
	

}
Proj4EPSG900913Wrapper::Proj4EPSG900913Wrapper(Proj4EPSG900913* proj4epsg900913): proj4epsg900913_(proj4epsg900913)
{

	
	Proj4ProjectionWrapper::object(proj4epsg900913_);
	
}

Proj4EPSG900913Wrapper::~Proj4EPSG900913Wrapper()
{

}

void Proj4EPSG900913Wrapper::set(const MagRequest& request)
{

	

	Proj4ProjectionWrapper::set(request);
	

	
	
}

void Proj4EPSG900913Wrapper::print(ostream& out)  const
{
	out << "Proj4EPSG900913Wrapper[]";
}



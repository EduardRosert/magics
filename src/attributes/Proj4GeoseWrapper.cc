
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file Proj4GeoseAttributes.h
    \\brief Definition of Proj4Geose Attributes class.

    This file is automatically generated.
    Do Not Edit!

*/

#include "MagRequest.h"
#include "Proj4GeoseWrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"
#include "MagicsGlobal.h"

using namespace magics;


Proj4GeoseWrapper::Proj4GeoseWrapper(): proj4geose_(new Proj4Geose())

{


	
	Proj4ProjectionWrapper::object(proj4geose_);
	

}
Proj4GeoseWrapper::Proj4GeoseWrapper(Proj4Geose* proj4geose): proj4geose_(proj4geose)
{

	
	Proj4ProjectionWrapper::object(proj4geose_);
	
}

Proj4GeoseWrapper::~Proj4GeoseWrapper()
{

}

void Proj4GeoseWrapper::set(const MagRequest& request)
{

	

	Proj4ProjectionWrapper::set(request);
	

	
	
}

void Proj4GeoseWrapper::print(ostream& out)  const
{
	out << "Proj4GeoseWrapper[]";
}




/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file YCoordinateAttributes.h
    \\brief Definition of YCoordinate Attributes class.

    This file is automatically generated.
    Do Not Edit!

*/

#include "MagRequest.h"
#include "YCoordinateWrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"
#include "MagicsGlobal.h"

using namespace magics;



YCoordinateWrapper::YCoordinateWrapper(): ycoordinate_(new YCoordinate())


{


	

}
YCoordinateWrapper::YCoordinateWrapper(YCoordinate* ycoordinate): ycoordinate_(ycoordinate)
{

	
}

YCoordinateWrapper::~YCoordinateWrapper()
{

}

void YCoordinateWrapper::set(const MagRequest& request)
{

	

	
	
}

void YCoordinateWrapper::print(ostream& out)  const
{
	out << "YCoordinateWrapper[]";
}



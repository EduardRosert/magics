
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file HiLoMarkerBaseAttributes.h
    \\brief Definition of HiLoMarkerBase Attributes class.

    This file is automatically generated.
    Do Not Edit!

*/

#include "MagRequest.h"
#include "HiLoMarkerBaseWrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"
#include "MagicsGlobal.h"

using namespace magics;


HiLoMarkerBaseWrapper::HiLoMarkerBaseWrapper(): hilomarkerbase_(new HiLoMarkerBase())

{


	

}
HiLoMarkerBaseWrapper::HiLoMarkerBaseWrapper(HiLoMarkerBase* hilomarkerbase): hilomarkerbase_(hilomarkerbase)
{

	
}

HiLoMarkerBaseWrapper::~HiLoMarkerBaseWrapper()
{

}

void HiLoMarkerBaseWrapper::set(const MagRequest& request)
{

	

	
	
}

void HiLoMarkerBaseWrapper::print(ostream& out)  const
{
	out << "HiLoMarkerBaseWrapper[]";
}



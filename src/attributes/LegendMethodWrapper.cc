
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file LegendMethodAttributes.h
    \\brief Definition of LegendMethod Attributes class.

    This file is automatically generated.
    Do Not Edit!

*/

#include "MagRequest.h"
#include "LegendMethodWrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"
#include "MagicsGlobal.h"

using namespace magics;



LegendMethodWrapper::LegendMethodWrapper(): legendmethod_(new LegendMethod())


{


	

}
LegendMethodWrapper::LegendMethodWrapper(LegendMethod* legendmethod): legendmethod_(legendmethod)
{

	
}

LegendMethodWrapper::~LegendMethodWrapper()
{

}

void LegendMethodWrapper::set(const MagRequest& request)
{

	

	
	
}

void LegendMethodWrapper::print(ostream& out)  const
{
	out << "LegendMethodWrapper[]";
}



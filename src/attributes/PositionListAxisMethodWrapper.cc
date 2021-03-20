
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file PositionListAxisMethodAttributes.h
    \\brief Definition of PositionListAxisMethod Attributes class.

    This file is automatically generated.
    Do Not Edit!

*/

#include "MagRequest.h"
#include "PositionListAxisMethodWrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"
#include "MagicsGlobal.h"

using namespace magics;


PositionListAxisMethodWrapper::PositionListAxisMethodWrapper(): positionlistaxismethod_(new PositionListAxisMethod())

{


	
	AxisMethodWrapper::object(positionlistaxismethod_);
	

}
PositionListAxisMethodWrapper::PositionListAxisMethodWrapper(PositionListAxisMethod* positionlistaxismethod): positionlistaxismethod_(positionlistaxismethod)
{

	
	AxisMethodWrapper::object(positionlistaxismethod_);
	
}

PositionListAxisMethodWrapper::~PositionListAxisMethodWrapper()
{

}

void PositionListAxisMethodWrapper::set(const MagRequest& request)
{

	

	AxisMethodWrapper::set(request);
	

	
	
}

void PositionListAxisMethodWrapper::print(ostream& out)  const
{
	out << "PositionListAxisMethodWrapper[]";
}



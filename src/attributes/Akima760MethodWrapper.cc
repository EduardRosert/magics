
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file Akima760MethodAttributes.h
    \\brief Definition of Akima760Method Attributes class.

    This file is automatically generated.
    Do Not Edit!

*/

#include "MagRequest.h"
#include "Akima760MethodWrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"
#include "MagicsGlobal.h"

using namespace magics;


Akima760MethodWrapper::Akima760MethodWrapper(): akima760method_(new Akima760Method())

{


	
	ContourMethodWrapper::object(akima760method_);
	

}
Akima760MethodWrapper::Akima760MethodWrapper(Akima760Method* akima760method): akima760method_(akima760method)
{

	
	ContourMethodWrapper::object(akima760method_);
	
}

Akima760MethodWrapper::~Akima760MethodWrapper()
{

}

void Akima760MethodWrapper::set(const MagRequest& request)
{

	

	ContourMethodWrapper::set(request);
	

	if  (request.countValues("CONTOUR_AKIMA_X_RESOLUTION") ) {
		double resolutionX_value = request("CONTOUR_AKIMA_X_RESOLUTION");
		akima760method_->resolutionX_ = resolutionX_value;
		}
	if  (request.countValues("CONTOUR_AKIMA_Y_RESOLUTION") ) {
		double resolutionY_value = request("CONTOUR_AKIMA_Y_RESOLUTION");
		akima760method_->resolutionY_ = resolutionY_value;
		}
	
	
}

void Akima760MethodWrapper::print(ostream& out)  const
{
	out << "Akima760MethodWrapper[]";
}



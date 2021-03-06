
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file EmagramGridAttributes.h
    \\brief Definition of EmagramGrid Attributes class.

    This file is automatically generated.
    Do Not Edit!

*/

#include "MagRequest.h"
#include "EmagramGridWrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"
#include "MagicsGlobal.h"

using namespace magics;



EmagramGridWrapper::EmagramGridWrapper(): emagramgrid_(new EmagramGrid())


{


	
	TephiGridWrapper::object(emagramgrid_);
	

}
EmagramGridWrapper::EmagramGridWrapper(EmagramGrid* emagramgrid): emagramgrid_(emagramgrid)
{

	
	TephiGridWrapper::object(emagramgrid_);
	
}

EmagramGridWrapper::~EmagramGridWrapper()
{

}

void EmagramGridWrapper::set(const MagRequest& request)
{

	

	TephiGridWrapper::set(request);
	

	
	
}

void EmagramGridWrapper::print(ostream& out)  const
{
	out << "EmagramGridWrapper[]";
}



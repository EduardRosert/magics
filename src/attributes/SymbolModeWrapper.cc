
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file SymbolModeAttributes.h
    \\brief Definition of SymbolMode Attributes class.

    This file is automatically generated.
    Do Not Edit!

*/

#include "MagRequest.h"
#include "SymbolModeWrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"
#include "MagicsSettings.h"

using namespace magics;


SymbolModeWrapper::SymbolModeWrapper(): symbolmode_(new SymbolMode())

{


	

}
SymbolModeWrapper::SymbolModeWrapper(SymbolMode* symbolmode): symbolmode_(symbolmode)
{

	
}

SymbolModeWrapper::~SymbolModeWrapper()
{

}

void SymbolModeWrapper::set(const MagRequest& request)
{

	

	
	
}

void SymbolModeWrapper::print(ostream& out)  const
{
	out << "SymbolModeWrapper[]";
}



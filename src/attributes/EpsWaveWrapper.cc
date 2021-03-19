
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file EpsWaveAttributes.h
    \\brief Definition of EpsWave Attributes class.

    This file is automatically generated.
    Do Not Edit!

*/

#include "MagRequest.h"
#include "EpsWaveWrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"
#include "MagicsSettings.h"

using namespace magics;


EpsWaveWrapper::EpsWaveWrapper(): epswave_(new EpsWave())

{


	

}
EpsWaveWrapper::EpsWaveWrapper(EpsWave* epswave): epswave_(epswave)
{

	
}

EpsWaveWrapper::~EpsWaveWrapper()
{

}

void EpsWaveWrapper::set(const MagRequest& request)
{

	

	stringarray  colour_value;
	for (int i = 0; i < request.countValues("EPS_ROSE_WAVE_COLOUR"); i++)
		colour_value.push_back((string)request("EPS_ROSE_WAVE_COLOUR", i));
	if ( !colour_value.empty() )
		epswave_->colour_ = colour_value;
	
	
}

void EpsWaveWrapper::print(ostream& out)  const
{
	out << "EpsWaveWrapper[]";
}



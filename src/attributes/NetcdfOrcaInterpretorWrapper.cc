
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file NetcdfOrcaInterpretorAttributes.h
    \\brief Definition of NetcdfOrcaInterpretor Attributes class.

    This file is automatically generated.
    Do Not Edit!

*/

#include "MagRequest.h"
#include "NetcdfOrcaInterpretorWrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"
#include "MagicsGlobal.h"

using namespace magics;


NetcdfOrcaInterpretorWrapper::NetcdfOrcaInterpretorWrapper(): netcdforcainterpretor_(new NetcdfOrcaInterpretor())

{


	
	NetcdfInterpretorWrapper::object(netcdforcainterpretor_);
	

}
NetcdfOrcaInterpretorWrapper::NetcdfOrcaInterpretorWrapper(NetcdfOrcaInterpretor* netcdforcainterpretor): netcdforcainterpretor_(netcdforcainterpretor)
{

	
	NetcdfInterpretorWrapper::object(netcdforcainterpretor_);
	
}

NetcdfOrcaInterpretorWrapper::~NetcdfOrcaInterpretorWrapper()
{

}

void NetcdfOrcaInterpretorWrapper::set(const MagRequest& request)
{

	

	NetcdfInterpretorWrapper::set(request);
	

	
	
}

void NetcdfOrcaInterpretorWrapper::print(ostream& out)  const
{
	out << "NetcdfOrcaInterpretorWrapper[]";
}



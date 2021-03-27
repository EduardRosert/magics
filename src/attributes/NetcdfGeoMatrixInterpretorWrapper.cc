
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file NetcdfGeoMatrixInterpretorAttributes.h
    \\brief Definition of NetcdfGeoMatrixInterpretor Attributes class.

    This file is automatically generated.
    Do Not Edit!
*/

#include "MagRequest.h" 
#include "NetcdfGeoMatrixInterpretorWrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"

using namespace magics;



NetcdfGeoMatrixInterpretorWrapper::NetcdfGeoMatrixInterpretorWrapper(): netcdfgeomatrixinterpretor_(new NetcdfGeoMatrixInterpretor())


{

	
	
	NetcdfInterpretorWrapper::object(netcdfgeomatrixinterpretor_);
	
	
} 
NetcdfGeoMatrixInterpretorWrapper::NetcdfGeoMatrixInterpretorWrapper(NetcdfGeoMatrixInterpretor* netcdfgeomatrixinterpretor): netcdfgeomatrixinterpretor_(netcdfgeomatrixinterpretor)
{
	
	
	NetcdfInterpretorWrapper::object(netcdfgeomatrixinterpretor_);
	
} 

NetcdfGeoMatrixInterpretorWrapper::~NetcdfGeoMatrixInterpretorWrapper()
{
	
}

void NetcdfGeoMatrixInterpretorWrapper::set(const MagRequest& request)
{
	
	
	
	NetcdfInterpretorWrapper::set(request);
	

	
	
}

void NetcdfGeoMatrixInterpretorWrapper::print(ostream& out)  const
{
	out << "NetcdfGeoMatrixInterpretorWrapper[]";
}


    




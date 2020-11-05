
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file NetcdfGeoVectorInterpretorAttributes.h
    \\brief Definition of NetcdfGeoVectorInterpretor Attributes class.

    This file is automatically generated.
    Do Not Edit!
*/

#include "MagRequest.h" 
#include "NetcdfGeoVectorInterpretorWrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"

using namespace magics;


NetcdfGeoVectorInterpretorWrapper::NetcdfGeoVectorInterpretorWrapper(): netcdfgeovectorinterpretor_(new NetcdfGeoVectorInterpretor())

{

	
	
	NetcdfInterpretorWrapper::object(netcdfgeovectorinterpretor_);
	
	
} 
NetcdfGeoVectorInterpretorWrapper::NetcdfGeoVectorInterpretorWrapper(NetcdfGeoVectorInterpretor* netcdfgeovectorinterpretor): netcdfgeovectorinterpretor_(netcdfgeovectorinterpretor)
{
	
	
	NetcdfInterpretorWrapper::object(netcdfgeovectorinterpretor_);
	
} 

NetcdfGeoVectorInterpretorWrapper::~NetcdfGeoVectorInterpretorWrapper()
{
	
}

void NetcdfGeoVectorInterpretorWrapper::set(const MagRequest& request)
{
	
	
	
	NetcdfInterpretorWrapper::set(request);
	

	
	
}

void NetcdfGeoVectorInterpretorWrapper::print(ostream& out)  const
{
	out << "NetcdfGeoVectorInterpretorWrapper[]";
}


    





/*******************************  LICENSE  *******************************

 * (C) Copyright 1996-2016 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \fileNetcdfGeoPolarMatrixInterpretorAttributes.h
    \brief Definition of NetcdfGeoPolarMatrixInterpretor Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 
*/
   

#ifndef NetcdfGeoPolarMatrixInterpretorWrapper_H
#define NetcdfGeoPolarMatrixInterpretorWrapper_H

#include "magics.h"
#include "ParameterManager.h"
#include "Factory.h"



#include "NetcdfVectorInterpretor.h"


 
#include "NetcdfInterpretorWrapper.h"






 

namespace magics {

class MagRequest;


class NetcdfGeoPolarMatrixInterpretorWrapper: public NetcdfInterpretorWrapper

{
public:
//  --  constructor
    NetcdfGeoPolarMatrixInterpretorWrapper();
    NetcdfGeoPolarMatrixInterpretorWrapper(NetcdfGeoPolarMatrixInterpretor*);
//  --  destructor
    virtual ~NetcdfGeoPolarMatrixInterpretorWrapper();
    virtual void set(const MagRequest&);
    
    NetcdfGeoPolarMatrixInterpretor* me()   { return netcdfgeopolarmatrixinterpretor_; }
   	
   	virtual NetcdfGeoPolarMatrixInterpretor* object() { return netcdfgeopolarmatrixinterpretor_; }
	

	virtual void object(NetcdfGeoPolarMatrixInterpretor* o) { 
		// Remember to delete the previous object
		netcdfgeopolarmatrixinterpretor_ = o;
		NetcdfInterpretorWrapper::object(o);
		

	}
    
  

protected:
    NetcdfGeoPolarMatrixInterpretor* netcdfgeopolarmatrixinterpretor_;


//  --  method
	virtual void print(ostream&) const;
	

private:
    string tag_;
	friend ostream& operator<<(ostream& s,const NetcdfGeoPolarMatrixInterpretorWrapper& p)
	{ p.print(s); return s; }
};

} // namespace magics

#endif


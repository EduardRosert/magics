
/*******************************  LICENSE  *******************************

 * (C) Copyright 1996-2016 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \fileNetcdfMatrixInterpretorAttributes.h
    \brief Definition of NetcdfMatrixInterpretor Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 
*/


#ifndef NetcdfMatrixInterpretorWrapper_H
#define NetcdfMatrixInterpretorWrapper_H

#include "magics.h"
#include "ParameterManager.h"
#include "Factory.h"



#include "NetcdfMatrixInterpretor.h"



#include "NetcdfInterpretorWrapper.h"








namespace magics {

class MagRequest;


class NetcdfMatrixInterpretorWrapper: public NetcdfInterpretorWrapper

{
public:
//  --  constructor
    NetcdfMatrixInterpretorWrapper();
    NetcdfMatrixInterpretorWrapper(NetcdfMatrixInterpretor*);
//  --  destructor
    virtual ~NetcdfMatrixInterpretorWrapper();
    virtual void set(const MagRequest&);

    NetcdfMatrixInterpretor* me()   { return netcdfmatrixinterpretor_; }

   	virtual NetcdfMatrixInterpretor* object() { return netcdfmatrixinterpretor_; }


	virtual void object(NetcdfMatrixInterpretor* o) {
		// Remember to delete the previous object
		netcdfmatrixinterpretor_ = o;
		NetcdfInterpretorWrapper::object(o);
		

	}



protected:
    NetcdfMatrixInterpretor* netcdfmatrixinterpretor_;


//  --  method
	virtual void print(ostream&) const;


private:
    string tag_;
	friend ostream& operator<<(ostream& s,const NetcdfMatrixInterpretorWrapper& p)
	{ p.print(s); return s; }
};

} // namespace magics

#endif
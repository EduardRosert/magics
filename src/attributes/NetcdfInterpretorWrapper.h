
/*******************************  LICENSE  *******************************

 * (C) Copyright 1996-2016 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \fileNetcdfInterpretorAttributes.h
    \brief Definition of NetcdfInterpretor Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 
*/


#ifndef NetcdfInterpretorWrapper_H
#define NetcdfInterpretorWrapper_H

#include "magics.h"
#include "ParameterManager.h"
#include "Factory.h"



#include "NetcdfInterpretor.h"










namespace magics {

class MagRequest;



class NetcdfInterpretorWrapper

{
public:
//  --  constructor
    NetcdfInterpretorWrapper();
    NetcdfInterpretorWrapper(NetcdfInterpretor*);
//  --  destructor
    virtual ~NetcdfInterpretorWrapper();
    virtual void set(const MagRequest&);

    NetcdfInterpretor* me()   { return netcdfinterpretor_; }

   	virtual NetcdfInterpretor* object() { return netcdfinterpretor_; }


	virtual void object(NetcdfInterpretor* o) {
		// Remember to delete the previous object
		netcdfinterpretor_ = o;
		

	}



protected:
    NetcdfInterpretor* netcdfinterpretor_;


//  --  method
	virtual void print(ostream&) const override;


private:
    string tag_;
	friend ostream& operator<<(ostream& s,const NetcdfInterpretorWrapper& p)
	{ p.print(s); return s; }
};

} // namespace magics

#endif

/*******************************  LICENSE  *******************************

 * (C) Copyright 1996-2016 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \fileNetcdfGeoVectorInterpretorAttributes.h
    \brief Definition of NetcdfGeoVectorInterpretor Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 
*/


#ifndef NetcdfGeoVectorInterpretorWrapper_H
#define NetcdfGeoVectorInterpretorWrapper_H

#include "magics.h"
#include "ParameterManager.h"
#include "Factory.h"



#include "NetcdfVectorInterpretor.h"



#include "NetcdfInterpretorWrapper.h"








namespace magics {

class MagRequest;


class NetcdfGeoVectorInterpretorWrapper: public NetcdfInterpretorWrapper

{
public:
//  --  constructor
    NetcdfGeoVectorInterpretorWrapper();
    NetcdfGeoVectorInterpretorWrapper(NetcdfGeoVectorInterpretor*);
//  --  destructor
    virtual ~NetcdfGeoVectorInterpretorWrapper();
    virtual void set(const MagRequest&);

    NetcdfGeoVectorInterpretor* me()   { return netcdfgeovectorinterpretor_; }

   	virtual NetcdfGeoVectorInterpretor* object() { return netcdfgeovectorinterpretor_; }


	virtual void object(NetcdfGeoVectorInterpretor* o) {
		// Remember to delete the previous object
		netcdfgeovectorinterpretor_ = o;
		NetcdfInterpretorWrapper::object(o);
		

	}



protected:
    NetcdfGeoVectorInterpretor* netcdfgeovectorinterpretor_;


//  --  method
	virtual void print(ostream&) const;


private:
    string tag_;
	friend ostream& operator<<(ostream& s,const NetcdfGeoVectorInterpretorWrapper& p)
	{ p.print(s); return s; }
};

} // namespace magics

#endif
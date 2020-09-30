
/*******************************  LICENSE  *******************************

 * (C) Copyright 1996-2016 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \fileProj4LambertAttributes.h
    \brief Definition of Proj4Lambert Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 
*/
   

#ifndef Proj4LambertWrapper_H
#define Proj4LambertWrapper_H

#include "magics.h"
#include "ParameterManager.h"
#include "Factory.h"



#include "Proj4Projection.h"


 
#include "Proj4ProjectionWrapper.h"






 

namespace magics {

class MagRequest;


class Proj4LambertWrapper: public Proj4ProjectionWrapper

{
public:
//  --  constructor
    Proj4LambertWrapper();
    Proj4LambertWrapper(Proj4Lambert*);
//  --  destructor
    virtual ~Proj4LambertWrapper();
    virtual void set(const MagRequest&);
    
    Proj4Lambert* me()   { return proj4lambert_; }
   	
   	virtual Proj4Lambert* object() { return proj4lambert_; }
	

	virtual void object(Proj4Lambert* o) { 
		// Remember to delete the previous object
		proj4lambert_ = o;
		Proj4ProjectionWrapper::object(o);
		

	}
    
  

protected:
    Proj4Lambert* proj4lambert_;


//  --  method
	virtual void print(ostream&) const;
	

private:
    string tag_;
	friend ostream& operator<<(ostream& s,const Proj4LambertWrapper& p)
	{ p.print(s); return s; }
};

} // namespace magics

#endif



/*******************************  LICENSE  *******************************

 * (C) Copyright 1996-2016 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \fileProj4TPersAttributes.h
    \brief Definition of Proj4TPers Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 
*/
   

#ifndef Proj4TPersWrapper_H
#define Proj4TPersWrapper_H

#include "magics.h"
#include "ParameterManager.h"
#include "Factory.h"



#include "Proj4Projection.h"


 
#include "Proj4ProjectionWrapper.h"






 

namespace magics {

class MagRequest;


class Proj4TPersWrapper: public Proj4ProjectionWrapper

{
public:
//  --  constructor
    Proj4TPersWrapper();
    Proj4TPersWrapper(Proj4TPers*);
//  --  destructor
    virtual ~Proj4TPersWrapper();
    virtual void set(const MagRequest&);
    
    Proj4TPers* me()   { return proj4tpers_; }
   	
   	virtual Proj4TPers* object() { return proj4tpers_; }
	

	virtual void object(Proj4TPers* o) { 
		// Remember to delete the previous object
		proj4tpers_ = o;
		Proj4ProjectionWrapper::object(o);
		

	}
    
  

protected:
    Proj4TPers* proj4tpers_;


//  --  method
	virtual void print(ostream&) const;
	

private:
    string tag_;
	friend ostream& operator<<(ostream& s,const Proj4TPersWrapper& p)
	{ p.print(s); return s; }
};

} // namespace magics

#endif


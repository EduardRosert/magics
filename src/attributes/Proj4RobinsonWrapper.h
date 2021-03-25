
/*******************************  LICENSE  *******************************

 * (C) Copyright 1996-2016 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \fileProj4RobinsonAttributes.h
    \brief Definition of Proj4Robinson Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 
*/
   

#ifndef Proj4RobinsonWrapper_H
#define Proj4RobinsonWrapper_H

#include "magics.h"
#include "ParameterManager.h"
#include "Factory.h"



#include "Proj4Projection.h"


 
#include "Proj4ProjectionWrapper.h"






 

namespace magics {

class MagRequest;


class Proj4RobinsonWrapper: public Proj4ProjectionWrapper

{
public:
//  --  constructor
    Proj4RobinsonWrapper();
    Proj4RobinsonWrapper(Proj4Robinson*);
//  --  destructor
    virtual ~Proj4RobinsonWrapper();
    virtual void set(const MagRequest&);
    
    Proj4Robinson* me()   { return proj4robinson_; }
   	
   	virtual Proj4Robinson* object() { return proj4robinson_; }
	

	virtual void object(Proj4Robinson* o) { 
		// Remember to delete the previous object
		proj4robinson_ = o;
		Proj4ProjectionWrapper::object(o);
		

	}
    
  

protected:
    Proj4Robinson* proj4robinson_;


//  --  method
	virtual void print(ostream&) const;
	

private:
    string tag_;
	friend ostream& operator<<(ostream& s,const Proj4RobinsonWrapper& p)
	{ p.print(s); return s; }
};

} // namespace magics

#endif



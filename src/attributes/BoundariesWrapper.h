
/*******************************  LICENSE  *******************************

 * (C) Copyright 1996-2016 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \fileBoundariesAttributes.h
    \brief Definition of Boundaries Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 
*/
   

#ifndef BoundariesWrapper_H
#define BoundariesWrapper_H

#include "magics.h"
#include "ParameterManager.h"
#include "Factory.h"



#include "Boundaries.h"


 
#include "NoBoundariesWrapper.h"






 

namespace magics {

class MagRequest;


class BoundariesWrapper: public NoBoundariesWrapper

{
public:
//  --  constructor
    BoundariesWrapper();
    BoundariesWrapper(Boundaries*);
//  --  destructor
    virtual ~BoundariesWrapper();
    virtual void set(const MagRequest&);
    
    Boundaries* me()   { return boundaries_; }
   	
   	virtual Boundaries* object() { return boundaries_; }
	

	virtual void object(Boundaries* o) { 
		// Remember to delete the previous object
		boundaries_ = o;
		NoBoundariesWrapper::object(o);
		

	}
    
  

protected:
    Boundaries* boundaries_;


//  --  method
	virtual void print(ostream&) const;
	

private:
    string tag_;
	friend ostream& operator<<(ostream& s,const BoundariesWrapper& p)
	{ p.print(s); return s; }
};

} // namespace magics

#endif



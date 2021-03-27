
/*******************************  LICENSE  *******************************

 * (C) Copyright 1996-2016 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \fileProj4EfasAttributes.h
    \brief Definition of Proj4Efas Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 
*/
   

#ifndef Proj4EfasWrapper_H
#define Proj4EfasWrapper_H

#include "magics.h"
#include "ParameterManager.h"
#include "Factory.h"



#include "Proj4Projection.h"


 
#include "Proj4ProjectionWrapper.h"






 

namespace magics {

class MagRequest;


class Proj4EfasWrapper: public Proj4ProjectionWrapper

{
public:
//  --  constructor
    Proj4EfasWrapper();
    Proj4EfasWrapper(Proj4Efas*);
//  --  destructor
    virtual ~Proj4EfasWrapper();
    virtual void set(const MagRequest&);
    
    Proj4Efas* me()   { return proj4efas_; }
   	
   	virtual Proj4Efas* object() { return proj4efas_; }
	

	virtual void object(Proj4Efas* o) { 
		// Remember to delete the previous object
		proj4efas_ = o;
		Proj4ProjectionWrapper::object(o);
		

	}
    
  

protected:
    Proj4Efas* proj4efas_;


//  --  method
	virtual void print(ostream&) const;
	

private:
    string tag_;
	friend ostream& operator<<(ostream& s,const Proj4EfasWrapper& p)
	{ p.print(s); return s; }
};

} // namespace magics

#endif



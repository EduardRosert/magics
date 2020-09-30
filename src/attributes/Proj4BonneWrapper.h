
/*******************************  LICENSE  *******************************

 * (C) Copyright 1996-2016 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \fileProj4BonneAttributes.h
    \brief Definition of Proj4Bonne Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 
*/
   

#ifndef Proj4BonneWrapper_H
#define Proj4BonneWrapper_H

#include "magics.h"
#include "ParameterManager.h"
#include "Factory.h"



#include "Proj4Projection.h"


 
#include "Proj4ProjectionWrapper.h"






 

namespace magics {

class MagRequest;


class Proj4BonneWrapper: public Proj4ProjectionWrapper

{
public:
//  --  constructor
    Proj4BonneWrapper();
    Proj4BonneWrapper(Proj4Bonne*);
//  --  destructor
    virtual ~Proj4BonneWrapper();
    virtual void set(const MagRequest&);
    
    Proj4Bonne* me()   { return proj4bonne_; }
   	
   	virtual Proj4Bonne* object() { return proj4bonne_; }
	

	virtual void object(Proj4Bonne* o) { 
		// Remember to delete the previous object
		proj4bonne_ = o;
		Proj4ProjectionWrapper::object(o);
		

	}
    
  

protected:
    Proj4Bonne* proj4bonne_;


//  --  method
	virtual void print(ostream&) const;
	

private:
    string tag_;
	friend ostream& operator<<(ostream& s,const Proj4BonneWrapper& p)
	{ p.print(s); return s; }
};

} // namespace magics

#endif


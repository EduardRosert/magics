
/*******************************  LICENSE  *******************************

 * (C) Copyright 1996-2016 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \fileContourMethodAttributes.h
    \brief Definition of ContourMethod Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 
*/
   

#ifndef ContourMethodWrapper_H
#define ContourMethodWrapper_H

#include "magics.h"
#include "ParameterManager.h"
#include "Factory.h"



#include "ContourMethod.h"








 

namespace magics {

class MagRequest;


 	
class ContourMethodWrapper 

{
public:
//  --  constructor
    ContourMethodWrapper();
    ContourMethodWrapper(ContourMethod*);
//  --  destructor
    virtual ~ContourMethodWrapper();
    virtual void set(const MagRequest&);
    
    ContourMethod* me()   { return contourmethod_; }
   	
   	virtual ContourMethod* object() { return contourmethod_; }
	

	virtual void object(ContourMethod* o) { 
		// Remember to delete the previous object
		contourmethod_ = o;
		

	}
    
  

protected:
    ContourMethod* contourmethod_;


//  --  method
	virtual void print(ostream&) const;
	

private:
    string tag_;
	friend ostream& operator<<(ostream& s,const ContourMethodWrapper& p)
	{ p.print(s); return s; }
};

} // namespace magics

#endif



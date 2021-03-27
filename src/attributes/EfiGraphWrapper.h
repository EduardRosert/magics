
/*******************************  LICENSE  *******************************

 * (C) Copyright 1996-2016 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \fileEfiGraphAttributes.h
    \brief Definition of EfiGraph Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 
*/
   

#ifndef EfiGraphWrapper_H
#define EfiGraphWrapper_H

#include "magics.h"
#include "ParameterManager.h"
#include "Factory.h"



#include "EfiGraph.h"








 

namespace magics {

class MagRequest;


 	
class EfiGraphWrapper 

{
public:
//  --  constructor
    EfiGraphWrapper();
    EfiGraphWrapper(EfiGraph*);
//  --  destructor
    virtual ~EfiGraphWrapper();
    virtual void set(const MagRequest&);
    
    EfiGraph* me()   { return efigraph_; }
   	
   	virtual EfiGraph* object() { return efigraph_; }
	

	virtual void object(EfiGraph* o) { 
		// Remember to delete the previous object
		efigraph_ = o;
		

	}
    
  

protected:
    EfiGraph* efigraph_;


//  --  method
	virtual void print(ostream&) const;
	

private:
    string tag_;
	friend ostream& operator<<(ostream& s,const EfiGraphWrapper& p)
	{ p.print(s); return s; }
};

} // namespace magics

#endif



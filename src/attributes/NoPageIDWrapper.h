
/*******************************  LICENSE  *******************************

 * (C) Copyright 1996-2016 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \fileNoPageIDAttributes.h
    \brief Definition of NoPageID Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 
*/
   

#ifndef NoPageIDWrapper_H
#define NoPageIDWrapper_H

#include "magics.h"
#include "ParameterManager.h"
#include "Factory.h"



#include "PageID.h"








 

namespace magics {

class MagRequest;


 	
class NoPageIDWrapper 

{
public:
//  --  constructor
    NoPageIDWrapper();
    NoPageIDWrapper(NoPageID*);
//  --  destructor
    virtual ~NoPageIDWrapper();
    virtual void set(const MagRequest&);
    
    NoPageID* me()   { return nopageid_; }
   	
   	virtual NoPageID* object() { return nopageid_; }
	

	virtual void object(NoPageID* o) { 
		// Remember to delete the previous object
		nopageid_ = o;
		

	}
    
  

protected:
    NoPageID* nopageid_;


//  --  method
	virtual void print(ostream&) const;
	

private:
    string tag_;
	friend ostream& operator<<(ostream& s,const NoPageIDWrapper& p)
	{ p.print(s); return s; }
};

} // namespace magics

#endif



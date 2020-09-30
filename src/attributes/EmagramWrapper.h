
/*******************************  LICENSE  *******************************

 * (C) Copyright 1996-2016 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \fileEmagramAttributes.h
    \brief Definition of Emagram Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 
*/
   

#ifndef EmagramWrapper_H
#define EmagramWrapper_H

#include "magics.h"
#include "ParameterManager.h"
#include "Factory.h"



#include "Emagram.h"


 
#include "TransformationWrapper.h"






 

namespace magics {

class MagRequest;


class EmagramWrapper: public TransformationWrapper

{
public:
//  --  constructor
    EmagramWrapper();
    EmagramWrapper(Emagram*);
//  --  destructor
    virtual ~EmagramWrapper();
    virtual void set(const MagRequest&);
    
    Emagram* me()   { return emagram_; }
   	
   	virtual Emagram* object() { return emagram_; }
	

	virtual void object(Emagram* o) { 
		// Remember to delete the previous object
		emagram_ = o;
		TransformationWrapper::object(o);
		

	}
    
  

protected:
    Emagram* emagram_;


//  --  method
	virtual void print(ostream&) const;
	

private:
    string tag_;
	friend ostream& operator<<(ostream& s,const EmagramWrapper& p)
	{ p.print(s); return s; }
};

} // namespace magics

#endif


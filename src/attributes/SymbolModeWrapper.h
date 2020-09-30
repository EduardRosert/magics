
/*******************************  LICENSE  *******************************

 * (C) Copyright 1996-2016 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \fileSymbolModeAttributes.h
    \brief Definition of SymbolMode Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 
*/
   

#ifndef SymbolModeWrapper_H
#define SymbolModeWrapper_H

#include "magics.h"
#include "ParameterManager.h"
#include "Factory.h"



#include "SymbolMode.h"








 

namespace magics {

class MagRequest;


 	
class SymbolModeWrapper 

{
public:
//  --  constructor
    SymbolModeWrapper();
    SymbolModeWrapper(SymbolMode*);
//  --  destructor
    virtual ~SymbolModeWrapper();
    virtual void set(const MagRequest&);
    
    SymbolMode* me()   { return symbolmode_; }
   	
   	virtual SymbolMode* object() { return symbolmode_; }
	

	virtual void object(SymbolMode* o) { 
		// Remember to delete the previous object
		symbolmode_ = o;
		

	}
    
  

protected:
    SymbolMode* symbolmode_;


//  --  method
	virtual void print(ostream&) const;
	

private:
    string tag_;
	friend ostream& operator<<(ostream& s,const SymbolModeWrapper& p)
	{ p.print(s); return s; }
};

} // namespace magics

#endif


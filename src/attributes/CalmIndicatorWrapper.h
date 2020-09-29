
/*******************************  LICENSE  *******************************

 * (C) Copyright 1996-2016 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \fileCalmIndicatorAttributes.h
    \brief Definition of CalmIndicator Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 
*/
   

#ifndef CalmIndicatorWrapper_H
#define CalmIndicatorWrapper_H

#include "magics.h"
#include "ParameterManager.h"
#include "Factory.h"



#include "CalmIndicator.h"








 

namespace magics {

class MagRequest;


 	
class CalmIndicatorWrapper 

{
public:
//  --  constructor
    CalmIndicatorWrapper();
    CalmIndicatorWrapper(CalmIndicator*);
//  --  destructor
    virtual ~CalmIndicatorWrapper();
    virtual void set(const MagRequest&);
    
    CalmIndicator* me()   { return calmindicator_; }
   	
   	virtual CalmIndicator* object() { return calmindicator_; }
	

	virtual void object(CalmIndicator* o) { 
		// Remember to delete the previous object
		calmindicator_ = o;
		

	}
    
  

protected:
    CalmIndicator* calmindicator_;


//  --  method
	virtual void print(ostream&) const;
	

private:
    string tag_;
	friend ostream& operator<<(ostream& s,const CalmIndicatorWrapper& p)
	{ p.print(s); return s; }
};

} // namespace magics

#endif



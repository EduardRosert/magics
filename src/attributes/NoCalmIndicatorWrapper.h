
/*******************************  LICENSE  *******************************

 * (C) Copyright 1996-2016 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \fileNoCalmIndicatorAttributes.h
    \brief Definition of NoCalmIndicator Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 
*/
   

#ifndef NoCalmIndicatorWrapper_H
#define NoCalmIndicatorWrapper_H

#include "magics.h"
#include "ParameterManager.h"
#include "Factory.h"



#include "CalmIndicator.h"


 
#include "CalmIndicatorWrapper.h"






 

namespace magics {

class MagRequest;


class NoCalmIndicatorWrapper: public CalmIndicatorWrapper

{
public:
//  --  constructor
    NoCalmIndicatorWrapper();
    NoCalmIndicatorWrapper(NoCalmIndicator*);
//  --  destructor
    virtual ~NoCalmIndicatorWrapper();
    virtual void set(const MagRequest&);
    
    NoCalmIndicator* me()   { return nocalmindicator_; }
   	
   	virtual NoCalmIndicator* object() { return nocalmindicator_; }
	

	virtual void object(NoCalmIndicator* o) { 
		// Remember to delete the previous object
		nocalmindicator_ = o;
		CalmIndicatorWrapper::object(o);
		

	}
    
  

protected:
    NoCalmIndicator* nocalmindicator_;


//  --  method
	virtual void print(ostream&) const;
	

private:
    string tag_;
	friend ostream& operator<<(ostream& s,const NoCalmIndicatorWrapper& p)
	{ p.print(s); return s; }
};

} // namespace magics

#endif


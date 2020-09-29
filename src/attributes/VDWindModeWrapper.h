
/*******************************  LICENSE  *******************************

 * (C) Copyright 1996-2016 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \fileVDWindModeAttributes.h
    \brief Definition of VDWindMode Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 
*/
   

#ifndef VDWindModeWrapper_H
#define VDWindModeWrapper_H

#include "magics.h"
#include "ParameterManager.h"
#include "Factory.h"



#include "WindMode.h"


 
#include "WindModeWrapper.h"






 

namespace magics {

class MagRequest;


class VDWindModeWrapper: public WindModeWrapper

{
public:
//  --  constructor
    VDWindModeWrapper();
    VDWindModeWrapper(VDWindMode*);
//  --  destructor
    virtual ~VDWindModeWrapper();
    virtual void set(const MagRequest&);
    
    VDWindMode* me()   { return vdwindmode_; }
   	
   	virtual VDWindMode* object() { return vdwindmode_; }
	

	virtual void object(VDWindMode* o) { 
		// Remember to delete the previous object
		vdwindmode_ = o;
		WindModeWrapper::object(o);
		

	}
    
  

protected:
    VDWindMode* vdwindmode_;


//  --  method
	virtual void print(ostream&) const;
	

private:
    string tag_;
	friend ostream& operator<<(ostream& s,const VDWindModeWrapper& p)
	{ p.print(s); return s; }
};

} // namespace magics

#endif



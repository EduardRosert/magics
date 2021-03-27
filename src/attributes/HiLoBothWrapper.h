
/*******************************  LICENSE  *******************************

 * (C) Copyright 1996-2016 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \fileHiLoBothAttributes.h
    \brief Definition of HiLoBoth Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 
*/
   

#ifndef HiLoBothWrapper_H
#define HiLoBothWrapper_H

#include "magics.h"
#include "ParameterManager.h"
#include "Factory.h"



#include "HiLoBoth.h"


 
#include "HiLoTechniqueWrapper.h"






 

namespace magics {

class MagRequest;


class HiLoBothWrapper: public HiLoTechniqueWrapper

{
public:
//  --  constructor
    HiLoBothWrapper();
    HiLoBothWrapper(HiLoBoth*);
//  --  destructor
    virtual ~HiLoBothWrapper();
    virtual void set(const MagRequest&);
    
    HiLoBoth* me()   { return hiloboth_; }
   	
   	virtual HiLoBoth* object() { return hiloboth_; }
	

	virtual void object(HiLoBoth* o) { 
		// Remember to delete the previous object
		hiloboth_ = o;
		HiLoTechniqueWrapper::object(o);
		

	}
    
  

protected:
    HiLoBoth* hiloboth_;


//  --  method
	virtual void print(ostream&) const;
	

private:
    string tag_;
	friend ostream& operator<<(ostream& s,const HiLoBothWrapper& p)
	{ p.print(s); return s; }
};

} // namespace magics

#endif




/*******************************  LICENSE  *******************************

 * (C) Copyright 1996-2016 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \fileIsoHighlightAttributes.h
    \brief Definition of IsoHighlight Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 
*/
   

#ifndef IsoHighlightWrapper_H
#define IsoHighlightWrapper_H

#include "magics.h"
#include "ParameterManager.h"
#include "Factory.h"



#include "IsoHighlight.h"


 
#include "NoIsoHighlightWrapper.h"






 

namespace magics {

class MagRequest;


class IsoHighlightWrapper: public NoIsoHighlightWrapper

{
public:
//  --  constructor
    IsoHighlightWrapper();
    IsoHighlightWrapper(IsoHighlight*);
//  --  destructor
    virtual ~IsoHighlightWrapper();
    virtual void set(const MagRequest&);
    
    IsoHighlight* me()   { return isohighlight_; }
   	
   	virtual IsoHighlight* object() { return isohighlight_; }
	

	virtual void object(IsoHighlight* o) { 
		// Remember to delete the previous object
		isohighlight_ = o;
		NoIsoHighlightWrapper::object(o);
		

	}
    
  

protected:
    IsoHighlight* isohighlight_;


//  --  method
	virtual void print(ostream&) const;
	

private:
    string tag_;
	friend ostream& operator<<(ostream& s,const IsoHighlightWrapper& p)
	{ p.print(s); return s; }
};

} // namespace magics

#endif



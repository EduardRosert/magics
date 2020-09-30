
/*******************************  LICENSE  *******************************

 * (C) Copyright 1996-2016 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \fileValuePlotMethodAttributes.h
    \brief Definition of ValuePlotMethod Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 
*/
   

#ifndef ValuePlotMethodWrapper_H
#define ValuePlotMethodWrapper_H

#include "magics.h"
#include "ParameterManager.h"
#include "Factory.h"



#include "ValuePlotMethod.h"








 

namespace magics {

class MagRequest;


 	
class ValuePlotMethodWrapper 

{
public:
//  --  constructor
    ValuePlotMethodWrapper();
    ValuePlotMethodWrapper(ValuePlotMethod*);
//  --  destructor
    virtual ~ValuePlotMethodWrapper();
    virtual void set(const MagRequest&);
    
    ValuePlotMethod* me()   { return valueplotmethod_; }
   	
   	virtual ValuePlotMethod* object() { return valueplotmethod_; }
	

	virtual void object(ValuePlotMethod* o) { 
		// Remember to delete the previous object
		valueplotmethod_ = o;
		

	}
    
  

protected:
    ValuePlotMethod* valueplotmethod_;


//  --  method
	virtual void print(ostream&) const;
	

private:
    string tag_;
	friend ostream& operator<<(ostream& s,const ValuePlotMethodWrapper& p)
	{ p.print(s); return s; }
};

} // namespace magics

#endif


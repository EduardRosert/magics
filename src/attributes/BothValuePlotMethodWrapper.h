
/*******************************  LICENSE  *******************************

 * (C) Copyright 1996-2016 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \fileBothValuePlotMethodAttributes.h
    \brief Definition of BothValuePlotMethod Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 
*/


#ifndef BothValuePlotMethodWrapper_H
#define BothValuePlotMethodWrapper_H

#include "magics.h"
#include "ParameterManager.h"
#include "Factory.h"



#include "BothValuePlotMethod.h"



#include "ValuePlotMethodWrapper.h"








namespace magics {

class MagRequest;


class BothValuePlotMethodWrapper: public ValuePlotMethodWrapper

{
public:
//  --  constructor
    BothValuePlotMethodWrapper();
    BothValuePlotMethodWrapper(BothValuePlotMethod*);
//  --  destructor
    virtual ~BothValuePlotMethodWrapper();
    virtual void set(const MagRequest&);

    BothValuePlotMethod* me()   { return bothvalueplotmethod_; }

   	virtual BothValuePlotMethod* object() { return bothvalueplotmethod_; }


	virtual void object(BothValuePlotMethod* o) {
		// Remember to delete the previous object
		bothvalueplotmethod_ = o;
		ValuePlotMethodWrapper::object(o);
		

	}



protected:
    BothValuePlotMethod* bothvalueplotmethod_;


//  --  method
	virtual void print(ostream&) const;


private:
    string tag_;
	friend ostream& operator<<(ostream& s,const BothValuePlotMethodWrapper& p)
	{ p.print(s); return s; }
};

} // namespace magics

#endif
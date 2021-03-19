
/*******************************  LICENSE  *******************************

 * (C) Copyright 1996-2016 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \fileMarkerValuePlotMethodAttributes.h
    \brief Definition of MarkerValuePlotMethod Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 
*/


#ifndef MarkerValuePlotMethodWrapper_H
#define MarkerValuePlotMethodWrapper_H

#include "magics.h"
#include "ParameterManager.h"
#include "Factory.h"



#include "MarkerValuePlotMethod.h"



#include "ValuePlotMethodWrapper.h"








namespace magics {

class MagRequest;


class MarkerValuePlotMethodWrapper: public ValuePlotMethodWrapper

{
public:
//  --  constructor
    MarkerValuePlotMethodWrapper();
    MarkerValuePlotMethodWrapper(MarkerValuePlotMethod*);
//  --  destructor
    virtual ~MarkerValuePlotMethodWrapper();
    virtual void set(const MagRequest&);

    MarkerValuePlotMethod* me()   { return markervalueplotmethod_; }

   	virtual MarkerValuePlotMethod* object() { return markervalueplotmethod_; }


	virtual void object(MarkerValuePlotMethod* o) {
		// Remember to delete the previous object
		markervalueplotmethod_ = o;
		ValuePlotMethodWrapper::object(o);
		

	}



protected:
    MarkerValuePlotMethod* markervalueplotmethod_;


//  --  method
	virtual void print(ostream&) const;


private:
    string tag_;
	friend ostream& operator<<(ostream& s,const MarkerValuePlotMethodWrapper& p)
	{ p.print(s); return s; }
};

} // namespace magics

#endif
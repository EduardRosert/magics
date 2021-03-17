
/*******************************  LICENSE  *******************************

 * (C) Copyright 1996-2016 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \fileSimplePolylineAttributes.h
    \brief Definition of SimplePolyline Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 
*/


#ifndef SimplePolylineWrapper_H
#define SimplePolylineWrapper_H

#include "magics.h"
#include "ParameterManager.h"
#include "Factory.h"



#include "SimplePolyline.h"



#include "SimplePolylineInputWrapper.h"






#include "LevelSelectionWrapper.h"
#include "ColourTechniqueWrapper.h"


namespace magics {

class MagRequest;


class SimplePolylineWrapper: public SimplePolylineInputWrapper

{
public:
//  --  constructor
    SimplePolylineWrapper();
    SimplePolylineWrapper(SimplePolyline*);
//  --  destructor
    virtual ~SimplePolylineWrapper();
    virtual void set(const MagRequest&);

    SimplePolyline* me()   { return simplepolyline_; }

   	virtual SimplePolyline* object() { return simplepolyline_; }


	virtual void object(SimplePolyline* o) {
		// Remember to delete the previous object
		simplepolyline_ = o;
		SimplePolylineInputWrapper::object(o);
		

	}



protected:
    SimplePolyline* simplepolyline_;


//  --  method
	virtual void print(ostream&) const override;


private:
    string tag_;
	friend ostream& operator<<(ostream& s,const SimplePolylineWrapper& p)
	{ p.print(s); return s; }
};

} // namespace magics

#endif

/*******************************  LICENSE  *******************************

 * (C) Copyright 1996-2016 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \fileContinuousLegendMethodAttributes.h
    \brief Definition of ContinuousLegendMethod Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 
*/


#ifndef ContinuousLegendMethodWrapper_H
#define ContinuousLegendMethodWrapper_H

#include "magics.h"
#include "ParameterManager.h"
#include "Factory.h"



#include "LegendMethod.h"



#include "LegendMethodWrapper.h"








namespace magics {

class MagRequest;


class ContinuousLegendMethodWrapper: public LegendMethodWrapper

{
public:
//  --  constructor
    ContinuousLegendMethodWrapper();
    ContinuousLegendMethodWrapper(ContinuousLegendMethod*);
//  --  destructor
    virtual ~ContinuousLegendMethodWrapper();
    virtual void set(const MagRequest&);

    ContinuousLegendMethod* me()   { return continuouslegendmethod_; }

   	virtual ContinuousLegendMethod* object() { return continuouslegendmethod_; }


	virtual void object(ContinuousLegendMethod* o) {
		// Remember to delete the previous object
		continuouslegendmethod_ = o;
		LegendMethodWrapper::object(o);
		

	}



protected:
    ContinuousLegendMethod* continuouslegendmethod_;


//  --  method
	virtual void print(ostream&) const override;


private:
    string tag_;
	friend ostream& operator<<(ostream& s,const ContinuousLegendMethodWrapper& p)
	{ p.print(s); return s; }
};

} // namespace magics

#endif
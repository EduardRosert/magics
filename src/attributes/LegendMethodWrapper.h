
/*******************************  LICENSE  *******************************

 * (C) Copyright 1996-2016 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \fileLegendMethodAttributes.h
    \brief Definition of LegendMethod Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 
*/


#ifndef LegendMethodWrapper_H
#define LegendMethodWrapper_H

#include "magics.h"
#include "ParameterManager.h"
#include "Factory.h"



#include "LegendMethod.h"










namespace magics {

class MagRequest;



class LegendMethodWrapper

{
public:
//  --  constructor
    LegendMethodWrapper();
    LegendMethodWrapper(LegendMethod*);
//  --  destructor
    virtual ~LegendMethodWrapper();
    virtual void set(const MagRequest&);

    LegendMethod* me()   { return legendmethod_; }

   	virtual LegendMethod* object() { return legendmethod_; }


	virtual void object(LegendMethod* o) {
		// Remember to delete the previous object
		legendmethod_ = o;
		

	}



protected:
    LegendMethod* legendmethod_;


//  --  method
	virtual void print(ostream&) const;


private:
    string tag_;
	friend ostream& operator<<(ostream& s,const LegendMethodWrapper& p)
	{ p.print(s); return s; }
};

} // namespace magics

#endif
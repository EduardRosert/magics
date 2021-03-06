
/*******************************  LICENSE  *******************************

 * (C) Copyright 1996-2016 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \fileFixedTableModeAttributes.h
    \brief Definition of FixedTableMode Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 
*/


#ifndef FixedTableModeWrapper_H
#define FixedTableModeWrapper_H

#include "magics.h"
#include "ParameterManager.h"
#include "Factory.h"



#include "FixedTableMode.h"



#include "LookupTableModeWrapper.h"








namespace magics {

class MagRequest;


class FixedTableModeWrapper: public LookupTableModeWrapper

{
public:
//  --  constructor
    FixedTableModeWrapper();
    FixedTableModeWrapper(FixedTableMode*);
//  --  destructor
    virtual ~FixedTableModeWrapper();
    virtual void set(const MagRequest&);

    FixedTableMode* me()   { return fixedtablemode_; }

   	virtual FixedTableMode* object() { return fixedtablemode_; }


	virtual void object(FixedTableMode* o) {
		// Remember to delete the previous object
		fixedtablemode_ = o;
		LookupTableModeWrapper::object(o);
		

	}



protected:
    FixedTableMode* fixedtablemode_;


//  --  method
	virtual void print(ostream&) const;


private:
    string tag_;
	friend ostream& operator<<(ostream& s,const FixedTableModeWrapper& p)
	{ p.print(s); return s; }
};

} // namespace magics

#endif
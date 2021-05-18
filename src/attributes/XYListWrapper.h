
/*******************************  LICENSE  *******************************

 * (C) Copyright 1996-2016 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \fileXYListAttributes.h
    \brief Definition of XYList Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 
*/


#ifndef XYListWrapper_H
#define XYListWrapper_H

#include "magics.h"
#include "ParameterManager.h"
#include "Factory.h"



#include "XYList.h"










namespace magics {

class MagRequest;



class XYListWrapper

{
public:
//  --  constructor
    XYListWrapper();
    XYListWrapper(XYList*);
//  --  destructor
    virtual ~XYListWrapper();
    virtual void set(const MagRequest&);

    XYList* me()   { return xylist_; }

   	virtual XYList* object() { return xylist_; }


	virtual void object(XYList* o) {
		// Remember to delete the previous object
		xylist_ = o;
		

	}



protected:
    XYList* xylist_;


//  --  method
	virtual void print(ostream&) const;


private:
    string tag_;
	friend ostream& operator<<(ostream& s,const XYListWrapper& p)
	{ p.print(s); return s; }
};

} // namespace magics

#endif
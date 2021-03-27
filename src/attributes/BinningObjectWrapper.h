
/*******************************  LICENSE  *******************************

 * (C) Copyright 1996-2016 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \fileBinningObjectAttributes.h
    \brief Definition of BinningObject Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 
*/


#ifndef BinningObjectWrapper_H
#define BinningObjectWrapper_H

#include "magics.h"
#include "ParameterManager.h"
#include "Factory.h"



#include "BinningObject.h"










namespace magics {

class MagRequest;



class BinningObjectWrapper

{
public:
//  --  constructor
    BinningObjectWrapper();
    BinningObjectWrapper(BinningObject*);
//  --  destructor
    virtual ~BinningObjectWrapper();
    virtual void set(const MagRequest&);

    BinningObject* me()   { return binningobject_; }

   	virtual BinningObject* object() { return binningobject_; }


	virtual void object(BinningObject* o) {
		// Remember to delete the previous object
		binningobject_ = o;
		

	}



protected:
    BinningObject* binningobject_;


//  --  method
	virtual void print(ostream&) const;


private:
    string tag_;
	friend ostream& operator<<(ostream& s,const BinningObjectWrapper& p)
	{ p.print(s); return s; }
};

} // namespace magics

#endif
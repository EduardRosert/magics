
/*******************************  LICENSE  *******************************

 * (C) Copyright 1996-2016 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \fileCapeBoxAttributes.h
    \brief Definition of CapeBox Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 
*/


#ifndef CapeBoxWrapper_H
#define CapeBoxWrapper_H

#include "magics.h"
#include "ParameterManager.h"
#include "Factory.h"



#include "CapeBox.h"










namespace magics {

class MagRequest;



class CapeBoxWrapper

{
public:
//  --  constructor
    CapeBoxWrapper();
    CapeBoxWrapper(CapeBox*);
//  --  destructor
    virtual ~CapeBoxWrapper();
    virtual void set(const MagRequest&);

    CapeBox* me()   { return capebox_; }

   	virtual CapeBox* object() { return capebox_; }


	virtual void object(CapeBox* o) {
		// Remember to delete the previous object
		capebox_ = o;
		

	}



protected:
    CapeBox* capebox_;


//  --  method
	virtual void print(ostream&) const;


private:
    string tag_;
	friend ostream& operator<<(ostream& s,const CapeBoxWrapper& p)
	{ p.print(s); return s; }
};

} // namespace magics

#endif
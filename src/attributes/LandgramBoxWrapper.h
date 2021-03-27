
/*******************************  LICENSE  *******************************

 * (C) Copyright 1996-2016 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \fileLandgramBoxAttributes.h
    \brief Definition of LandgramBox Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 
*/


#ifndef LandgramBoxWrapper_H
#define LandgramBoxWrapper_H

#include "magics.h"
#include "ParameterManager.h"
#include "Factory.h"



#include "LandgramBox.h"










namespace magics {

class MagRequest;



class LandgramBoxWrapper

{
public:
//  --  constructor
    LandgramBoxWrapper();
    LandgramBoxWrapper(LandgramBox*);
//  --  destructor
    virtual ~LandgramBoxWrapper();
    virtual void set(const MagRequest&);

    LandgramBox* me()   { return landgrambox_; }

   	virtual LandgramBox* object() { return landgrambox_; }


	virtual void object(LandgramBox* o) {
		// Remember to delete the previous object
		landgrambox_ = o;
		

	}



protected:
    LandgramBox* landgrambox_;


//  --  method
	virtual void print(ostream&) const;


private:
    string tag_;
	friend ostream& operator<<(ostream& s,const LandgramBoxWrapper& p)
	{ p.print(s); return s; }
};

} // namespace magics

#endif
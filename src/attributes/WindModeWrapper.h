
/*******************************  LICENSE  *******************************

 * (C) Copyright 1996-2016 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \fileWindModeAttributes.h
    \brief Definition of WindMode Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 
*/


#ifndef WindModeWrapper_H
#define WindModeWrapper_H

#include "magics.h"
#include "ParameterManager.h"
#include "Factory.h"



#include "WindMode.h"










namespace magics {

class MagRequest;



class WindModeWrapper

{
public:
//  --  constructor
    WindModeWrapper();
    WindModeWrapper(WindMode*);
//  --  destructor
    virtual ~WindModeWrapper();
    virtual void set(const MagRequest&);

    WindMode* me()   { return windmode_; }

   	virtual WindMode* object() { return windmode_; }


	virtual void object(WindMode* o) {
		// Remember to delete the previous object
		windmode_ = o;
		

	}



protected:
    WindMode* windmode_;


//  --  method
	virtual void print(ostream&) const override;


private:
    string tag_;
	friend ostream& operator<<(ostream& s,const WindModeWrapper& p)
	{ p.print(s); return s; }
};

} // namespace magics

#endif
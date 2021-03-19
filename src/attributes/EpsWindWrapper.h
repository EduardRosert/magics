
/*******************************  LICENSE  *******************************

 * (C) Copyright 1996-2016 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \fileEpsWindAttributes.h
    \brief Definition of EpsWind Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 
*/


#ifndef EpsWindWrapper_H
#define EpsWindWrapper_H

#include "magics.h"
#include "ParameterManager.h"
#include "Factory.h"



#include "EpsWind.h"










namespace magics {

class MagRequest;



class EpsWindWrapper

{
public:
//  --  constructor
    EpsWindWrapper();
    EpsWindWrapper(EpsWind*);
//  --  destructor
    virtual ~EpsWindWrapper();
    virtual void set(const MagRequest&);

    EpsWind* me()   { return epswind_; }

   	virtual EpsWind* object() { return epswind_; }


	virtual void object(EpsWind* o) {
		// Remember to delete the previous object
		epswind_ = o;
		

	}



protected:
    EpsWind* epswind_;


//  --  method
	virtual void print(ostream&) const;


private:
    string tag_;
	friend ostream& operator<<(ostream& s,const EpsWindWrapper& p)
	{ p.print(s); return s; }
};

} // namespace magics

#endif
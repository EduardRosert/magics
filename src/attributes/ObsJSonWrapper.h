
/*******************************  LICENSE  *******************************

 * (C) Copyright 1996-2016 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \fileObsJSonAttributes.h
    \brief Definition of ObsJSon Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 
*/


#ifndef ObsJSonWrapper_H
#define ObsJSonWrapper_H

#include "magics.h"
#include "ParameterManager.h"
#include "Factory.h"



#include "ObsJSon.h"










namespace magics {

class MagRequest;



class ObsJSonWrapper

{
public:
//  --  constructor
    ObsJSonWrapper();
    ObsJSonWrapper(ObsJSon*);
//  --  destructor
    virtual ~ObsJSonWrapper();
    virtual void set(const MagRequest&);

    ObsJSon* me()   { return obsjson_; }

   	virtual ObsJSon* object() { return obsjson_; }


	virtual void object(ObsJSon* o) {
		// Remember to delete the previous object
		obsjson_ = o;
		

	}



protected:
    ObsJSon* obsjson_;


//  --  method
	virtual void print(ostream&) const;


private:
    string tag_;
	friend ostream& operator<<(ostream& s,const ObsJSonWrapper& p)
	{ p.print(s); return s; }
};

} // namespace magics

#endif
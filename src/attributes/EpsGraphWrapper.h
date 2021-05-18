
/*******************************  LICENSE  *******************************

 * (C) Copyright 1996-2016 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \fileEpsGraphAttributes.h
    \brief Definition of EpsGraph Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 
*/


#ifndef EpsGraphWrapper_H
#define EpsGraphWrapper_H

#include "magics.h"
#include "ParameterManager.h"
#include "Factory.h"



#include "EpsGraph.h"










namespace magics {

class MagRequest;



class EpsGraphWrapper

{
public:
//  --  constructor
    EpsGraphWrapper();
    EpsGraphWrapper(EpsGraph*);
//  --  destructor
    virtual ~EpsGraphWrapper();
    virtual void set(const MagRequest&);

    EpsGraph* me()   { return epsgraph_; }

   	virtual EpsGraph* object() { return epsgraph_; }


	virtual void object(EpsGraph* o) {
		// Remember to delete the previous object
		epsgraph_ = o;
		

	}



protected:
    EpsGraph* epsgraph_;


//  --  method
	virtual void print(ostream&) const;


private:
    string tag_;
	friend ostream& operator<<(ostream& s,const EpsGraphWrapper& p)
	{ p.print(s); return s; }
};

} // namespace magics

#endif
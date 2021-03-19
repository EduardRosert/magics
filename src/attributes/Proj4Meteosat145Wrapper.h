
/*******************************  LICENSE  *******************************

 * (C) Copyright 1996-2016 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \fileProj4Meteosat145Attributes.h
    \brief Definition of Proj4Meteosat145 Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 
*/


#ifndef Proj4Meteosat145Wrapper_H
#define Proj4Meteosat145Wrapper_H

#include "magics.h"
#include "ParameterManager.h"
#include "Factory.h"



#include "Proj4Projection.h"



#include "Proj4ProjectionWrapper.h"








namespace magics {

class MagRequest;


class Proj4Meteosat145Wrapper: public Proj4ProjectionWrapper

{
public:
//  --  constructor
    Proj4Meteosat145Wrapper();
    Proj4Meteosat145Wrapper(Proj4Meteosat145*);
//  --  destructor
    virtual ~Proj4Meteosat145Wrapper();
    virtual void set(const MagRequest&);

    Proj4Meteosat145* me()   { return proj4meteosat145_; }

   	virtual Proj4Meteosat145* object() { return proj4meteosat145_; }


	virtual void object(Proj4Meteosat145* o) {
		// Remember to delete the previous object
		proj4meteosat145_ = o;
		Proj4ProjectionWrapper::object(o);
		

	}



protected:
    Proj4Meteosat145* proj4meteosat145_;


//  --  method
	virtual void print(ostream&) const;


private:
    string tag_;
	friend ostream& operator<<(ostream& s,const Proj4Meteosat145Wrapper& p)
	{ p.print(s); return s; }
};

} // namespace magics

#endif
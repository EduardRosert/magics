
/*******************************  LICENSE  *******************************

 * (C) Copyright 1996-2016 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \fileYDateCoordinateAttributes.h
    \brief Definition of YDateCoordinate Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 
*/
   

#ifndef YDateCoordinateWrapper_H
#define YDateCoordinateWrapper_H

#include "magics.h"
#include "ParameterManager.h"
#include "Factory.h"



#include "Coordinate.h"


 
#include "YCoordinateWrapper.h"






 

namespace magics {

class MagRequest;


class YDateCoordinateWrapper: public YCoordinateWrapper

{
public:
//  --  constructor
    YDateCoordinateWrapper();
    YDateCoordinateWrapper(YDateCoordinate*);
//  --  destructor
    virtual ~YDateCoordinateWrapper();
    virtual void set(const MagRequest&);
    
    YDateCoordinate* me()   { return ydatecoordinate_; }
   	
   	virtual YDateCoordinate* object() { return ydatecoordinate_; }
	

	virtual void object(YDateCoordinate* o) { 
		// Remember to delete the previous object
		ydatecoordinate_ = o;
		YCoordinateWrapper::object(o);
		

	}
    
  

protected:
    YDateCoordinate* ydatecoordinate_;


//  --  method
	virtual void print(ostream&) const;
	

private:
    string tag_;
	friend ostream& operator<<(ostream& s,const YDateCoordinateWrapper& p)
	{ p.print(s); return s; }
};

} // namespace magics

#endif



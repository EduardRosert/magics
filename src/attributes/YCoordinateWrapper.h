
/*******************************  LICENSE  *******************************

 * (C) Copyright 1996-2016 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \fileYCoordinateAttributes.h
    \brief Definition of YCoordinate Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 
*/
   

#ifndef YCoordinateWrapper_H
#define YCoordinateWrapper_H

#include "magics.h"
#include "ParameterManager.h"
#include "Factory.h"



#include "Coordinate.h"








 

namespace magics {

class MagRequest;


 	
class YCoordinateWrapper 

{
public:
//  --  constructor
    YCoordinateWrapper();
    YCoordinateWrapper(YCoordinate*);
//  --  destructor
    virtual ~YCoordinateWrapper();
    virtual void set(const MagRequest&);
    
    YCoordinate* me()   { return ycoordinate_; }
   	
   	virtual YCoordinate* object() { return ycoordinate_; }
	

	virtual void object(YCoordinate* o) { 
		// Remember to delete the previous object
		ycoordinate_ = o;
		

	}
    
  

protected:
    YCoordinate* ycoordinate_;


//  --  method
	virtual void print(ostream&) const;
	

private:
    string tag_;
	friend ostream& operator<<(ostream& s,const YCoordinateWrapper& p)
	{ p.print(s); return s; }
};

} // namespace magics

#endif


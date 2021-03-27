
/*******************************  LICENSE  *******************************

 * (C) Copyright 1996-2016 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \fileObsTableAttributes.h
    \brief Definition of ObsTable Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 
*/
   

#ifndef ObsTableWrapper_H
#define ObsTableWrapper_H

#include "magics.h"
#include "ParameterManager.h"
#include "Factory.h"



#include "ObsTable.h"








 

namespace magics {

class MagRequest;


 	
class ObsTableWrapper 

{
public:
//  --  constructor
    ObsTableWrapper();
    ObsTableWrapper(ObsTable*);
//  --  destructor
    virtual ~ObsTableWrapper();
    virtual void set(const MagRequest&);
    
    ObsTable* me()   { return obstable_; }
   	
   	virtual ObsTable* object() { return obstable_; }
	

	virtual void object(ObsTable* o) { 
		// Remember to delete the previous object
		obstable_ = o;
		

	}
    
  

protected:
    ObsTable* obstable_;


//  --  method
	virtual void print(ostream&) const;
	

private:
    string tag_;
	friend ostream& operator<<(ostream& s,const ObsTableWrapper& p)
	{ p.print(s); return s; }
};

} // namespace magics

#endif



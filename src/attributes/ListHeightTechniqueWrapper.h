
/*******************************  LICENSE  *******************************

 * (C) Copyright 1996-2016 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \fileListHeightTechniqueAttributes.h
    \brief Definition of ListHeightTechnique Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 
*/
   

#ifndef ListHeightTechniqueWrapper_H
#define ListHeightTechniqueWrapper_H

#include "magics.h"
#include "ParameterManager.h"
#include "Factory.h"



#include "HeightTechnique.h"


 
#include "HeightTechniqueWrapper.h"






 

namespace magics {

class MagRequest;


class ListHeightTechniqueWrapper: public HeightTechniqueWrapper

{
public:
//  --  constructor
    ListHeightTechniqueWrapper();
    ListHeightTechniqueWrapper(ListHeightTechnique*);
//  --  destructor
    virtual ~ListHeightTechniqueWrapper();
    virtual void set(const MagRequest&);
    
    ListHeightTechnique* me()   { return listheighttechnique_; }
   	
   	virtual ListHeightTechnique* object() { return listheighttechnique_; }
	

	virtual void object(ListHeightTechnique* o) { 
		// Remember to delete the previous object
		listheighttechnique_ = o;
		HeightTechniqueWrapper::object(o);
		

	}
    
  

protected:
    ListHeightTechnique* listheighttechnique_;


//  --  method
	virtual void print(ostream&) const;
	

private:
    string tag_;
	friend ostream& operator<<(ostream& s,const ListHeightTechniqueWrapper& p)
	{ p.print(s); return s; }
};

} // namespace magics

#endif



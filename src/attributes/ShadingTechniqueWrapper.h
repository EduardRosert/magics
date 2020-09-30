
/*******************************  LICENSE  *******************************

 * (C) Copyright 1996-2016 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \fileShadingTechniqueAttributes.h
    \brief Definition of ShadingTechnique Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 
*/
   

#ifndef ShadingTechniqueWrapper_H
#define ShadingTechniqueWrapper_H

#include "magics.h"
#include "ParameterManager.h"
#include "Factory.h"



#include "ShadingTechnique.h"








 

namespace magics {

class MagRequest;


 	
class ShadingTechniqueWrapper 

{
public:
//  --  constructor
    ShadingTechniqueWrapper();
    ShadingTechniqueWrapper(ShadingTechnique*);
//  --  destructor
    virtual ~ShadingTechniqueWrapper();
    virtual void set(const MagRequest&);
    
    ShadingTechnique* me()   { return shadingtechnique_; }
   	
   	virtual ShadingTechnique* object() { return shadingtechnique_; }
	

	virtual void object(ShadingTechnique* o) { 
		// Remember to delete the previous object
		shadingtechnique_ = o;
		

	}
    
  

protected:
    ShadingTechnique* shadingtechnique_;


//  --  method
	virtual void print(ostream&) const;
	

private:
    string tag_;
	friend ostream& operator<<(ostream& s,const ShadingTechniqueWrapper& p)
	{ p.print(s); return s; }
};

} // namespace magics

#endif


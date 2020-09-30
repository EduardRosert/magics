
/*******************************  LICENSE  *******************************

 * (C) Copyright 1996-2016 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \fileUserLogoPlottingAttributes.h
    \brief Definition of UserLogoPlotting Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 
*/
   

#ifndef UserLogoPlottingWrapper_H
#define UserLogoPlottingWrapper_H

#include "magics.h"
#include "ParameterManager.h"
#include "Factory.h"



#include "LogoPlotting.h"


 
#include "NoLogoPlottingWrapper.h"






 

namespace magics {

class MagRequest;


class UserLogoPlottingWrapper: public NoLogoPlottingWrapper

{
public:
//  --  constructor
    UserLogoPlottingWrapper();
    UserLogoPlottingWrapper(UserLogoPlotting*);
//  --  destructor
    virtual ~UserLogoPlottingWrapper();
    virtual void set(const MagRequest&);
    
    UserLogoPlotting* me()   { return userlogoplotting_; }
   	
   	virtual UserLogoPlotting* object() { return userlogoplotting_; }
	

	virtual void object(UserLogoPlotting* o) { 
		// Remember to delete the previous object
		userlogoplotting_ = o;
		NoLogoPlottingWrapper::object(o);
		

	}
    
  

protected:
    UserLogoPlotting* userlogoplotting_;


//  --  method
	virtual void print(ostream&) const;
	

private:
    string tag_;
	friend ostream& operator<<(ostream& s,const UserLogoPlottingWrapper& p)
	{ p.print(s); return s; }
};

} // namespace magics

#endif


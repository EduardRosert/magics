
/*******************************  LICENSE  *******************************

 * (C) Copyright 1996-2016 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \fileLogoPlottingAttributes.h
    \brief Definition of LogoPlotting Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 
*/
   

#ifndef LogoPlottingWrapper_H
#define LogoPlottingWrapper_H

#include "magics.h"
#include "ParameterManager.h"
#include "Factory.h"



#include "LogoPlotting.h"


 
#include "NoLogoPlottingWrapper.h"






 

namespace magics {

class MagRequest;


class LogoPlottingWrapper: public NoLogoPlottingWrapper

{
public:
//  --  constructor
    LogoPlottingWrapper();
    LogoPlottingWrapper(LogoPlotting*);
//  --  destructor
    virtual ~LogoPlottingWrapper();
    virtual void set(const MagRequest&);
    
    LogoPlotting* me()   { return logoplotting_; }
   	
   	virtual LogoPlotting* object() { return logoplotting_; }
	

	virtual void object(LogoPlotting* o) { 
		// Remember to delete the previous object
		logoplotting_ = o;
		NoLogoPlottingWrapper::object(o);
		

	}
    
  

protected:
    LogoPlotting* logoplotting_;


//  --  method
	virtual void print(ostream&) const;
	

private:
    string tag_;
	friend ostream& operator<<(ostream& s,const LogoPlottingWrapper& p)
	{ p.print(s); return s; }
};

} // namespace magics

#endif



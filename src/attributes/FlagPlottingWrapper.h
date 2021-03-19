
/*******************************  LICENSE  *******************************

 * (C) Copyright 1996-2016 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \fileFlagPlottingAttributes.h
    \brief Definition of FlagPlotting Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 
*/


#ifndef FlagPlottingWrapper_H
#define FlagPlottingWrapper_H

#include "magics.h"
#include "ParameterManager.h"
#include "Factory.h"



#include "FlagPlotting.h"



#include "WindPlottingWrapper.h"






#include "CalmIndicatorWrapper.h"
#include "OriginMarkerWrapper.h"


namespace magics {

class MagRequest;


class FlagPlottingWrapper: public WindPlottingWrapper

{
public:
//  --  constructor
    FlagPlottingWrapper();
    FlagPlottingWrapper(FlagPlotting*);
//  --  destructor
    virtual ~FlagPlottingWrapper();
    virtual void set(const MagRequest&);

    FlagPlotting* me()   { return flagplotting_; }

   	virtual FlagPlotting* object() { return flagplotting_; }


	virtual void object(FlagPlotting* o) {
		// Remember to delete the previous object
		flagplotting_ = o;
		WindPlottingWrapper::object(o);
		

	}



protected:
    FlagPlotting* flagplotting_;


//  --  method
	virtual void print(ostream&) const override;


private:
    string tag_;
	friend ostream& operator<<(ostream& s,const FlagPlottingWrapper& p)
	{ p.print(s); return s; }
};

} // namespace magics

#endif
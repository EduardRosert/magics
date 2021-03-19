
/*******************************  LICENSE  *******************************

 * (C) Copyright 1996-2016 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \fileGraphPlottingAttributes.h
    \brief Definition of GraphPlotting Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 
*/


#ifndef GraphPlottingWrapper_H
#define GraphPlottingWrapper_H

#include "magics.h"
#include "ParameterManager.h"
#include "Factory.h"



#include "GraphPlotting.h"








#include "GraphWrapper.h"


namespace magics {

class MagRequest;



class GraphPlottingWrapper

{
public:
//  --  constructor
    GraphPlottingWrapper();
    GraphPlottingWrapper(GraphPlotting*);
//  --  destructor
    virtual ~GraphPlottingWrapper();
    virtual void set(const MagRequest&);

    GraphPlotting* me()   { return graphplotting_; }

   	virtual GraphPlotting* object() { return graphplotting_; }


	virtual void object(GraphPlotting* o) {
		// Remember to delete the previous object
		graphplotting_ = o;
		

	}



protected:
    GraphPlotting* graphplotting_;


//  --  method
	virtual void print(ostream&) const;


private:
    string tag_;
	friend ostream& operator<<(ostream& s,const GraphPlottingWrapper& p)
	{ p.print(s); return s; }
};

} // namespace magics

#endif
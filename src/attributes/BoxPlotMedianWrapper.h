
/*******************************  LICENSE  *******************************

 * (C) Copyright 1996-2016 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \fileBoxPlotMedianAttributes.h
    \brief Definition of BoxPlotMedian Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 
*/
   

#ifndef BoxPlotMedianWrapper_H
#define BoxPlotMedianWrapper_H

#include "magics.h"
#include "ParameterManager.h"
#include "Factory.h"



#include "BoxPlotItem.h"


 
#include "NoBoxPlotMedianWrapper.h"






 

namespace magics {

class MagRequest;


class BoxPlotMedianWrapper: public NoBoxPlotMedianWrapper

{
public:
//  --  constructor
    BoxPlotMedianWrapper();
    BoxPlotMedianWrapper(BoxPlotMedian*);
//  --  destructor
    virtual ~BoxPlotMedianWrapper();
    virtual void set(const MagRequest&);
    
    BoxPlotMedian* me()   { return boxplotmedian_; }
   	
   	virtual BoxPlotMedian* object() { return boxplotmedian_; }
	

	virtual void object(BoxPlotMedian* o) { 
		// Remember to delete the previous object
		boxplotmedian_ = o;
		NoBoxPlotMedianWrapper::object(o);
		

	}
    
  

protected:
    BoxPlotMedian* boxplotmedian_;


//  --  method
	virtual void print(ostream&) const;
	

private:
    string tag_;
	friend ostream& operator<<(ostream& s,const BoxPlotMedianWrapper& p)
	{ p.print(s); return s; }
};

} // namespace magics

#endif



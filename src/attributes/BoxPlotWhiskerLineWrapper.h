
/*******************************  LICENSE  *******************************

 * (C) Copyright 1996-2016 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \fileBoxPlotWhiskerLineAttributes.h
    \brief Definition of BoxPlotWhiskerLine Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 
*/


#ifndef BoxPlotWhiskerLineWrapper_H
#define BoxPlotWhiskerLineWrapper_H

#include "magics.h"
#include "ParameterManager.h"
#include "Factory.h"



#include "BoxPlotWhiskerLine.h"










namespace magics {

class MagRequest;



class BoxPlotWhiskerLineWrapper

{
public:
//  --  constructor
    BoxPlotWhiskerLineWrapper();
    BoxPlotWhiskerLineWrapper(BoxPlotWhiskerLine*);
//  --  destructor
    virtual ~BoxPlotWhiskerLineWrapper();
    virtual void set(const MagRequest&);

    BoxPlotWhiskerLine* me()   { return boxplotwhiskerline_; }

   	virtual BoxPlotWhiskerLine* object() { return boxplotwhiskerline_; }


	virtual void object(BoxPlotWhiskerLine* o) {
		// Remember to delete the previous object
		boxplotwhiskerline_ = o;
		

	}



protected:
    BoxPlotWhiskerLine* boxplotwhiskerline_;


//  --  method
	virtual void print(ostream&) const;


private:
    string tag_;
	friend ostream& operator<<(ostream& s,const BoxPlotWhiskerLineWrapper& p)
	{ p.print(s); return s; }
};

} // namespace magics

#endif
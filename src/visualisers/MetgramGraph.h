/******************************** LICENSE ********************************

 Copyright 2007 European Centre for Medium-Range Weather Forecasts (ECMWF)

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at 

    http://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.

 ******************************** LICENSE ********************************/

/*! \file MetgramGraph.h
    \brief Definition of the Template class MetgramGraph.
    
    Magics Team - ECMWF 2004
    
    Started: Wed 5-May-2004
    
    Changes:
    
*/

#ifndef MetgramGraph_H
#define MetgramGraph_H

#include "magics.h"


#include "MetgramGraphAttributes.h"


#include "magics.h"
#include "Polyline.h"
#include "Graph.h"

namespace magics {

class XmlNode;


class MetgramGraph:  public MetgramGraphAttributes, public Visdef {



public:
	MetgramGraph();
	virtual ~MetgramGraph();
    
   
    
	virtual void operator()(Data&, BasicGraphicsObjectContainer&);
    void visit(LegendVisitor&);
    
    
    // Implements the set method ... 
    void set(const map<string, string>& map ) { MetgramGraphAttributes::set(map); }
    void set(const XmlNode& node) { MetgramGraphAttributes::set(node); }
    
    
protected:
     //! Method to print string about this class on to a stream of type ostream (virtual).
	 virtual void print(ostream&) const; 
	 double resolution_;
 
    

private:
    //! Copy constructor - No copy allowed
	MetgramGraph(const MetgramGraph&);
    //! Overloaded << operator to copy - No copy allowed
	MetgramGraph& operator=(const MetgramGraph&);

// -- Friends
    //! Overloaded << operator to call print().
	friend ostream& operator<<(ostream& s,const MetgramGraph& p)
		{ p.print(s); return s; }

};

} // namespace magics
#endif

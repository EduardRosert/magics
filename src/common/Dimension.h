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

/*! \file Dimension.h
    \brief Definition of the Template class Dimension.
    
    Magics Team - ECMWF 2005
    
    Started: Thu 16-Jun-2005
    
    Changes:
    
*/

#ifndef Dimension_H
#define Dimension_H

#include "magics.h"


namespace magics {

class Dimension {

public:
	Dimension(const string& , double, double = 100. );
	virtual ~Dimension() {}
	double absolute()  { return absolute_;}
	double percent() { return percent_;}
	string str() const { 
		ostringstream  percent;
		percent << percent_ << "%"; 
		return percent.str(); 
	}
protected:
     //! Method to print string about this class on to a stream of type ostream (virtual).
	 virtual void print(ostream& out) const { out << "Dimension"; } 
	 double  absolute_;
	 double  percent_;
	 int       pixel_;

private:
    //! Copy constructor - No copy allowed
	Dimension(const Dimension&);
    //! Overloaded << operator to copy - No copy allowed
	Dimension& operator=(const Dimension&);

// -- Friends
    //! Overloaded << operator to call print().
	friend ostream& operator<<(ostream& s,const Dimension& p)
		{ p.print(s); return s; }

};

} // namespace magics
#endif

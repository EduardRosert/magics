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

/*! \file NormalTableMode.cc
    \brief Definition of the Template class NormalTableMode.
    
    Magics Team - ECMWF 2005
    
    Started: Tue 14-July-2005
    
    Changes:
    
*/

#ifndef NormalTableMode_H
#define NormalTableMode_H

#include "magics.h"

#include "LookupTableMode.h"

namespace magics {

class NormalTableMode: public LookupTableMode {

public:
	NormalTableMode();
	virtual ~NormalTableMode();
	void set(const map<string, string>& map ) // for MagML
		 { LookupTableModeAttributes::set(map); }

	virtual void operator()(Image&, Raster&);

protected:
     //! Method to print string about this class on to a stream of type ostream (virtual).
	 virtual void print(ostream&) const; 

private:
    //! Copy constructor - No copy allowed
	NormalTableMode(const NormalTableMode&);
    //! Overloaded << operator to copy - No copy allowed
	NormalTableMode& operator=(const NormalTableMode&);

// -- Friends
    //! Overloaded << operator to call print().
	friend ostream& operator<<(ostream& s,const NormalTableMode& p)
		{ p.print(s); return s; }

};

} // namespace magics
#endif

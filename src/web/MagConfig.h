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

/*! \file EpsgramDecoder.h
    \brief Definition of the Template class EpsgramDecoder.
    
    Magics Team - ECMWF 2005
    
    Started: Mon 19-Sep-2005
    
    Changes:
    
*/

#ifndef MagConfig_H
#define MagConfig_H

#include "magics.h"



#include "json_spirit.h"
#include <limits>

namespace magics {
class MagConfig
{
public:
	MagConfig();
	~MagConfig();

	string convert(const json_spirit::Value&);

	virtual void callback(const string&, const json_spirit::Value&) = 0;

};


class MagConfigHandler

{
public:
	MagConfigHandler(const string& config, MagConfig& object);
	virtual ~MagConfigHandler();

	void dig(const json_spirit::Value&);
	void ignore(const json_spirit::Value&) {}

protected:
     //! Method to print string about this class on to a stream of type ostream (virtual).
	 virtual void print(ostream&) const; 


private:
    //! Copy constructor - No copy allowed
	MagConfigHandler(const MagConfigHandler&);
    //! Overloaded << operator to copy - No copy allowed
	MagConfigHandler& operator=(const MagConfigHandler&);

// -- Friends
    //! Overloaded << operator to call print().
	friend ostream& operator<<(ostream& s,const MagConfigHandler& p)
		{ p.print(s); return s; }

};











} // namespace magics
#endif

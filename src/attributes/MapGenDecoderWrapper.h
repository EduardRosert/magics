
/*******************************  LICENSE  *******************************

 * (C) Copyright 1996-2016 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \fileMapGenDecoderAttributes.h
    \brief Definition of MapGenDecoder Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 
*/
   

#ifndef MapGenDecoderWrapper_H
#define MapGenDecoderWrapper_H

#include "magics.h"
#include "ParameterManager.h"
#include "Factory.h"



#include "MapGenDecoder.h"








 

namespace magics {

class MagRequest;


 	
class MapGenDecoderWrapper 

{
public:
//  --  constructor
    MapGenDecoderWrapper();
    MapGenDecoderWrapper(MapGenDecoder*);
//  --  destructor
    virtual ~MapGenDecoderWrapper();
    virtual void set(const MagRequest&);
    
    MapGenDecoder* me()   { return mapgendecoder_; }
   	
   	virtual MapGenDecoder* object() { return mapgendecoder_; }
	

	virtual void object(MapGenDecoder* o) { 
		// Remember to delete the previous object
		mapgendecoder_ = o;
		

	}
    
  

protected:
    MapGenDecoder* mapgendecoder_;


//  --  method
	virtual void print(ostream&) const;
	

private:
    string tag_;
	friend ostream& operator<<(ostream& s,const MapGenDecoderWrapper& p)
	{ p.print(s); return s; }
};

} // namespace magics

#endif



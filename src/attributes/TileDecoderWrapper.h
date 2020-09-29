
/*******************************  LICENSE  *******************************

 * (C) Copyright 1996-2016 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \fileTileDecoderAttributes.h
    \brief Definition of TileDecoder Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 
*/
   

#ifndef TileDecoderWrapper_H
#define TileDecoderWrapper_H

#include "magics.h"
#include "ParameterManager.h"
#include "Factory.h"



#include "TileDecoder.h"








 

namespace magics {

class MagRequest;


 	
class TileDecoderWrapper 

{
public:
//  --  constructor
    TileDecoderWrapper();
    TileDecoderWrapper(TileDecoder*);
//  --  destructor
    virtual ~TileDecoderWrapper();
    virtual void set(const MagRequest&);
    
    TileDecoder* me()   { return tiledecoder_; }
   	
   	virtual TileDecoder* object() { return tiledecoder_; }
	

	virtual void object(TileDecoder* o) { 
		// Remember to delete the previous object
		tiledecoder_ = o;
		

	}
    
  

protected:
    TileDecoder* tiledecoder_;


//  --  method
	virtual void print(ostream&) const;
	

private:
    string tag_;
	friend ostream& operator<<(ostream& s,const TileDecoderWrapper& p)
	{ p.print(s); return s; }
};

} // namespace magics

#endif



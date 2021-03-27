
/*******************************  LICENSE  *******************************

 * (C) Copyright 1996-2016 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \fileEpsgramDecoderAttributes.h
    \brief Definition of EpsgramDecoder Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 
*/
   

#ifndef EpsgramDecoderWrapper_H
#define EpsgramDecoderWrapper_H

#include "magics.h"
#include "ParameterManager.h"
#include "Factory.h"



#include "EpsgramDecoder.h"








 

namespace magics {

class MagRequest;


 	
class EpsgramDecoderWrapper 

{
public:
//  --  constructor
    EpsgramDecoderWrapper();
    EpsgramDecoderWrapper(EpsgramDecoder*);
//  --  destructor
    virtual ~EpsgramDecoderWrapper();
    virtual void set(const MagRequest&);
    
    EpsgramDecoder* me()   { return epsgramdecoder_; }
   	
   	virtual EpsgramDecoder* object() { return epsgramdecoder_; }
	

	virtual void object(EpsgramDecoder* o) { 
		// Remember to delete the previous object
		epsgramdecoder_ = o;
		

	}
    
  

protected:
    EpsgramDecoder* epsgramdecoder_;


//  --  method
	virtual void print(ostream&) const;
	

private:
    string tag_;
	friend ostream& operator<<(ostream& s,const EpsgramDecoderWrapper& p)
	{ p.print(s); return s; }
};

} // namespace magics

#endif



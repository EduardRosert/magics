
/*******************************  LICENSE  *******************************

 * (C) Copyright 1996-2016 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \fileEpsCloudAttributes.h
    \brief Definition of EpsCloud Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 
*/


#ifndef EpsCloudWrapper_H
#define EpsCloudWrapper_H

#include "magics.h"
#include "ParameterManager.h"
#include "Factory.h"



#include "EpsCloud.h"










namespace magics {

class MagRequest;



class EpsCloudWrapper

{
public:
//  --  constructor
    EpsCloudWrapper();
    EpsCloudWrapper(EpsCloud*);
//  --  destructor
    virtual ~EpsCloudWrapper();
    virtual void set(const MagRequest&);

    EpsCloud* me()   { return epscloud_; }

   	virtual EpsCloud* object() { return epscloud_; }


	virtual void object(EpsCloud* o) {
		// Remember to delete the previous object
		epscloud_ = o;
		

	}



protected:
    EpsCloud* epscloud_;


//  --  method
	virtual void print(ostream&) const override;


private:
    string tag_;
	friend ostream& operator<<(ostream& s,const EpsCloudWrapper& p)
	{ p.print(s); return s; }
};

} // namespace magics

#endif
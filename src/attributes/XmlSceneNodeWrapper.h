
/*******************************  LICENSE  *******************************

 * (C) Copyright 1996-2016 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \fileXmlSceneNodeAttributes.h
    \brief Definition of XmlSceneNode Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 
*/
   

#ifndef XmlSceneNodeWrapper_H
#define XmlSceneNodeWrapper_H

#include "magics.h"
#include "ParameterManager.h"
#include "Factory.h"



#include "XmlSceneNode.h"








#include "NoPageIDWrapper.h"
 

namespace magics {

class MagRequest;


 	
class XmlSceneNodeWrapper 

{
public:
//  --  constructor
    XmlSceneNodeWrapper();
    XmlSceneNodeWrapper(XmlSceneNode*);
//  --  destructor
    virtual ~XmlSceneNodeWrapper();
    virtual void set(const MagRequest&);
    
    XmlSceneNode* me()   { return xmlscenenode_; }
   	
   	virtual XmlSceneNode* object() { return xmlscenenode_; }
	

	virtual void object(XmlSceneNode* o) { 
		// Remember to delete the previous object
		xmlscenenode_ = o;
		

	}
    
  

protected:
    XmlSceneNode* xmlscenenode_;


//  --  method
	virtual void print(ostream&) const;
	

private:
    string tag_;
	friend ostream& operator<<(ostream& s,const XmlSceneNodeWrapper& p)
	{ p.print(s); return s; }
};

} // namespace magics

#endif



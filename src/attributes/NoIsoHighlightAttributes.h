
/*******************************  LICENSE  *******************************

 * (C) Copyright 1996-2016 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \fileNoIsoHighlightAttributes.h
    \brief Definition of NoIsoHighlight Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 
*/
   

#ifndef NoIsoHighlightAttributes_H
#define NoIsoHighlightAttributes_H

#include "magics.h"
namespace magics {

class XmlNode;
class NoIsoHighlightAttributes 
{
public:
//  --  constructor
    NoIsoHighlightAttributes();
    
//  --  destructor
    virtual ~NoIsoHighlightAttributes();
    
    virtual void set(const std::map<std::string, std::string>&);
    virtual void set(const XmlNode&);
    virtual void copy(const NoIsoHighlightAttributes&);
    virtual bool accept(const std::string&);

    void setTag(const std::string& tag) { tag_ = tag; }

public:
	//  --  method
	virtual void print(std::ostream&) const;
	virtual void toxml(std::ostream& out) const;
	//  --  members:
	string tag_;
	 

private:
	friend ostream& operator<<(ostream& s,const NoIsoHighlightAttributes& p)
	{ p.print(s); return s; }
};

} // namespace magics

#endif


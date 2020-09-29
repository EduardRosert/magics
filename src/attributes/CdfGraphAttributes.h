
/*******************************  LICENSE  *******************************

 * (C) Copyright 1996-2016 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \fileCdfGraphAttributes.h
    \brief Definition of CdfGraph Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 
*/
   

#ifndef CdfGraphAttributes_H
#define CdfGraphAttributes_H

#include "magics.h"
#include "Colour.h"
namespace magics {

class XmlNode;
class CdfGraphAttributes 
{
public:
//  --  constructor
    CdfGraphAttributes();
    
//  --  destructor
    virtual ~CdfGraphAttributes();
    
    virtual void set(const std::map<std::string, std::string>&);
    virtual void set(const XmlNode&);
    virtual void copy(const CdfGraphAttributes&);
    virtual bool accept(const std::string&);

    void setTag(const std::string& tag) { tag_ = tag; }

public:
	//  --  method
	virtual void print(std::ostream&) const;
	virtual void toxml(std::ostream& out) const;
	//  --  members:
	string tag_;
	string type_;
	stringarray colour_;
	stringarray style_;
	intarray thickness_;
	int clim_thickness_;
	bool legend_;
	unique_ptr<Colour> clim_colour_;
	LineStyle clim_style_;
	 

private:
	friend ostream& operator<<(ostream& s,const CdfGraphAttributes& p)
	{ p.print(s); return s; }
};

} // namespace magics

#endif


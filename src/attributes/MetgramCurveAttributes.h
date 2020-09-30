
/*******************************  LICENSE  *******************************

 * (C) Copyright 1996-2016 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \fileMetgramCurveAttributes.h
    \brief Definition of MetgramCurve Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 
*/
   

#ifndef MetgramCurveAttributes_H
#define MetgramCurveAttributes_H

#include "magics.h"
#include "Colour.h"
namespace magics {

class XmlNode;
class MetgramCurveAttributes 
{
public:
//  --  constructor
    MetgramCurveAttributes();
    
//  --  destructor
    virtual ~MetgramCurveAttributes();
    
    virtual void set(const std::map<std::string, std::string>&);
    virtual void set(const XmlNode&);
    virtual void copy(const MetgramCurveAttributes&);
    virtual bool accept(const std::string&);

    void setTag(const std::string& tag) { tag_ = tag; }

public:
	//  --  method
	virtual void print(std::ostream&) const;
	virtual void toxml(std::ostream& out) const;
	//  --  members:
	string tag_;
	string keyword1_;
	string keyword2_;
	int thickness_;
	int thickness2_;
	LineStyle style_;
	LineStyle style2_;
	unique_ptr<Colour> colour_;
	unique_ptr<Colour> colour2_;
	 

private:
	friend ostream& operator<<(ostream& s,const MetgramCurveAttributes& p)
	{ p.print(s); return s; }
};

} // namespace magics

#endif


/*******************************  LICENSE  *******************************

 * (C) Copyright 1996-2016 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \fileFortranSceneNodeAttributes.h
    \brief Definition of FortranSceneNode Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 
*/
   

#ifndef FortranSceneNodeAttributes_H
#define FortranSceneNodeAttributes_H

#include "magics.h"
#include "PageID.h"
#include "Colour.h"
namespace magics {

class XmlNode;
class FortranSceneNodeAttributes 
{
public:
//  --  constructor
    FortranSceneNodeAttributes();
    
//  --  destructor
    virtual ~FortranSceneNodeAttributes();
    
    virtual void set(const std::map<std::string, std::string>&);
    virtual void set(const XmlNode&);
    virtual void copy(const FortranSceneNodeAttributes&);
    virtual bool accept(const std::string&);

    void setTag(const std::string& tag) { tag_ = tag; }

public:
	//  --  method
	virtual void print(std::ostream&) const;
	virtual void toxml(std::ostream& out) const;
	//  --  members:
	string tag_;
	double x_;
	double y_;
	double width_;
	double height_;
	bool frame_;
	int frame_thickness_;
	string plot_layout_;
	string plot_start_;
	string plot_direction_;
	string theme_;
	bool skinny_;
	unique_ptr<Colour> frame_colour_;
	LineStyle frame_line_style_;
	unique_ptr<NoPageID> page_id_;
	 

private:
	friend ostream& operator<<(ostream& s,const FortranSceneNodeAttributes& p)
	{ p.print(s); return s; }
};

} // namespace magics

#endif


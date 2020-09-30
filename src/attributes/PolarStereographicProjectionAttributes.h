
/*******************************  LICENSE  *******************************

 * (C) Copyright 1996-2016 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \filePolarStereographicProjectionAttributes.h
    \brief Definition of PolarStereographicProjection Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 
*/
   

#ifndef PolarStereographicProjectionAttributes_H
#define PolarStereographicProjectionAttributes_H

#include "magics.h"
namespace magics {

class XmlNode;
class PolarStereographicProjectionAttributes 
{
public:
//  --  constructor
    PolarStereographicProjectionAttributes();
    
//  --  destructor
    virtual ~PolarStereographicProjectionAttributes();
    
    virtual void set(const std::map<std::string, std::string>&);
    virtual void set(const XmlNode&);
    virtual void copy(const PolarStereographicProjectionAttributes&);
    virtual bool accept(const std::string&);

    void setTag(const std::string& tag) { tag_ = tag; }

public:
	//  --  method
	virtual void print(std::ostream&) const;
	virtual void toxml(std::ostream& out) const;
	//  --  members:
	string tag_;
	string system_;
	string area_;
	double min_latitude_;
	double min_longitude_;
	double max_latitude_;
	double max_longitude_;
	double vertical_longitude_;
	double centre_latitude_;
	double centre_longitude_;
	double map_scale_;
	Hemisphere hemisphere_;
	 

private:
	friend ostream& operator<<(ostream& s,const PolarStereographicProjectionAttributes& p)
	{ p.print(s); return s; }
};

} // namespace magics

#endif

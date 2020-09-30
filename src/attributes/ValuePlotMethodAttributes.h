
/*******************************  LICENSE  *******************************

 * (C) Copyright 1996-2016 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \fileValuePlotMethodAttributes.h
    \brief Definition of ValuePlotMethod Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 
*/
   

#ifndef ValuePlotMethodAttributes_H
#define ValuePlotMethodAttributes_H

#include "magics.h"
#include "Colour.h"
namespace magics {

class XmlNode;
class ValuePlotMethodAttributes 
{
public:
//  --  constructor
    ValuePlotMethodAttributes();
    
//  --  destructor
    virtual ~ValuePlotMethodAttributes();
    
    virtual void set(const std::map<std::string, std::string>&);
    virtual void set(const XmlNode&);
    virtual void copy(const ValuePlotMethodAttributes&);
    virtual bool accept(const std::string&);

    void setTag(const std::string& tag) { tag_ = tag; }

public:
	//  --  method
	virtual void print(std::ostream&) const;
	virtual void toxml(std::ostream& out) const;
	//  --  members:
	string tag_;
	double min_;
	double max_;
	int lat_frequency_;
	int lon_frequency_;
	double height_;
	string format_;
	string quality_;
	string vertical_align_;
	unique_ptr<Colour> colour_;
	Justification justification_;
	 

private:
	friend ostream& operator<<(ostream& s,const ValuePlotMethodAttributes& p)
	{ p.print(s); return s; }
};

} // namespace magics

#endif

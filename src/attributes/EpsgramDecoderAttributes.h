
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
   

#ifndef EpsgramDecoderAttributes_H
#define EpsgramDecoderAttributes_H

#include "magics.h"
namespace magics {

class XmlNode;
class EpsgramDecoderAttributes 
{
public:
//  --  constructor
    EpsgramDecoderAttributes();
    
//  --  destructor
    virtual ~EpsgramDecoderAttributes();
    
    virtual void set(const std::map<std::string, std::string>&);
    virtual void set(const XmlNode&);
    virtual void copy(const EpsgramDecoderAttributes&);
    virtual bool accept(const std::string&);

    void setTag(const std::string& tag) { tag_ = tag; }

public:
	//  --  method
	virtual void print(std::ostream&) const;
	virtual void toxml(std::ostream& out) const;
	//  --  members:
	string tag_;
	stringarray title_;
	string type_;
	string database_;
	string title_text_;
	string param_;
	string param_title_;
	double latitude_;
	double longitude_;
	double param_hour_shift_;
	double param_scaling_factor_;
	double param_offset_factor_;
	string date_;
	string time_;
	bool long_title_;
	bool long_title_station_;
	bool long_title_height_;
	bool long_title_point_;
	string station_;
	double height_;
	bool correction_;
	double percentile_;
	double threshold_;
	 

private:
	friend ostream& operator<<(ostream& s,const EpsgramDecoderAttributes& p)
	{ p.print(s); return s; }
};

} // namespace magics

#endif


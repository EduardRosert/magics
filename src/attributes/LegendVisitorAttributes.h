
/*******************************  LICENSE  *******************************

 * (C) Copyright 1996-2016 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \fileLegendVisitorAttributes.h
    \brief Definition of LegendVisitor Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 
*/
   

#ifndef LegendVisitorAttributes_H
#define LegendVisitorAttributes_H

#include "magics.h"
#include "LegendMethod.h"
#include "Colour.h"
namespace magics {

class XmlNode;
class LegendVisitorAttributes 
{
public:
//  --  constructor
    LegendVisitorAttributes();
    
//  --  destructor
    virtual ~LegendVisitorAttributes();
    
    virtual void set(const std::map<std::string, std::string>&);
    virtual void set(const XmlNode&);
    virtual void copy(const LegendVisitorAttributes&);
    virtual bool accept(const std::string&);

    void setTag(const std::string& tag) { tag_ = tag; }

public:
	//  --  method
	virtual void print(std::ostream&) const;
	virtual void toxml(std::ostream& out) const;
	//  --  members:
	string tag_;
	bool title_;
	string title_text_;
	string title_orientation_;
	double title_font_size_;
	double title_ratio_;
	string units_text_;
	bool use_min_;
	string use_min_text_;
	bool use_max_;
	string use_max_text_;
	string format_;
	string box_;
	string box_position_;
	double box_margin_;
	string font_;
	string font_style_;
	string font_dimension_;
	string text_quality_;
	double orientation_;
	stringarray lines_;
	int columns_;
	string direction_;
	string entry_orientation_;
	string composition_;
	doublearray values_list_;
	string text_;
	string text1_;
	string text2_;
	string text3_;
	string text4_;
	string text5_;
	string text6_;
	string text7_;
	string text8_;
	string text9_;
	string text10_;
	double symbol_factor_;
	double box_x_;
	double box_y_;
	double box_width_;
	double box_height_;
	bool blanking_;
	bool border_;
	int border_thickness_;
	bool wrep_;
	bool only_;
	double text_width_;
	bool entry_border_;
	unique_ptr<Colour> colour_;
	unique_ptr<Colour> title_font_colour_;
	Position title_position_;
	unique_ptr<LegendMethod> method_;
	LineStyle border_line_style_;
	unique_ptr<Colour> border_colour_;
	unique_ptr<Colour> entry_border_colour_;
	 

private:
	friend ostream& operator<<(ostream& s,const LegendVisitorAttributes& p)
	{ p.print(s); return s; }
};

} // namespace magics

#endif

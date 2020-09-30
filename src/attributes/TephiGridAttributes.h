
/*******************************  LICENSE  *******************************

 * (C) Copyright 1996-2016 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \fileTephiGridAttributes.h
    \brief Definition of TephiGrid Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 
*/
   

#ifndef TephiGridAttributes_H
#define TephiGridAttributes_H

#include "magics.h"
#include "Colour.h"
namespace magics {

class XmlNode;
class TephiGridAttributes 
{
public:
//  --  constructor
    TephiGridAttributes();
    
//  --  destructor
    virtual ~TephiGridAttributes();
    
    virtual void set(const std::map<std::string, std::string>&);
    virtual void set(const XmlNode&);
    virtual void copy(const TephiGridAttributes&);
    virtual bool accept(const std::string&);

    void setTag(const std::string& tag) { tag_ = tag; }

public:
	//  --  method
	virtual void print(std::ostream&) const;
	virtual void toxml(std::ostream& out) const;
	//  --  members:
	string tag_;
	double annotation_width_;
	bool isotherm_;
	int isotherm_thickness_;
	double isotherm_interval_;
	double isotherm_reference_;
	int isotherm_reference_thickness_;
	string isotherm_label_font_;
	string isotherm_label_style_;
	double isotherm_label_size_;
	int isotherm_label_frequency_;
	bool isobar_;
	int isobar_thickness_;
	double isobar_interval_;
	double isobar_reference_;
	string isobar_label_font_;
	string isobar_label_style_;
	double isobar_label_size_;
	int isobar_label_frequency_;
	bool dry_adiabatic_;
	int dry_adiabatic_thickness_;
	double dry_adiabatic_interval_;
	double dry_adiabatic_reference_;
	string dry_adiabatic_label_font_;
	string dry_adiabatic_label_style_;
	double dry_adiabatic_label_size_;
	int dry_adiabatic_label_frequency_;
	bool saturated_adiabatic_;
	int saturated_adiabatic_thickness_;
	double saturated_adiabatic_interval_;
	double saturated_adiabatic_reference_;
	string saturated_adiabatic_label_font_;
	string saturated_adiabatic_label_style_;
	double saturated_adiabatic_label_size_;
	int saturated_adiabatic_label_frequency_;
	bool mixing_ratio_;
	int mixing_ratio_thickness_;
	int mixing_ratio_frequency_;
	string mixing_ratio_label_font_;
	string mixing_ratio_label_style_;
	double mixing_ratio_label_size_;
	int mixing_ratio_label_frequency_;
	unique_ptr<Colour> isotherm_colour_;
	LineStyle isotherm_style_;
	unique_ptr<Colour> isotherm_reference_colour_;
	LineStyle isotherm_reference_style_;
	unique_ptr<Colour> isotherm_label_colour_;
	unique_ptr<Colour> isobar_colour_;
	LineStyle isobar_style_;
	unique_ptr<Colour> isobar_label_colour_;
	unique_ptr<Colour> dry_adiabatic_colour_;
	LineStyle dry_adiabatic_style_;
	unique_ptr<Colour> dry_adiabatic_label_colour_;
	unique_ptr<Colour> saturated_adiabatic_colour_;
	LineStyle saturated_adiabatic_style_;
	unique_ptr<Colour> saturated_adiabatic_label_colour_;
	unique_ptr<Colour> mixing_ratio_colour_;
	LineStyle mixing_ratio_style_;
	unique_ptr<Colour> mixing_ratio_label_colour_;
	 

private:
	friend ostream& operator<<(ostream& s,const TephiGridAttributes& p)
	{ p.print(s); return s; }
};

} // namespace magics

#endif

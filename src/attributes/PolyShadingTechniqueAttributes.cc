
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file PolyShadingTechniqueAttributes.h
    \\brief Definition of PolyShadingTechnique Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 2020-09-24
*/

#include "PolyShadingTechniqueAttributes.h"
#include "MagicsParameter.h"
#include "ParameterSettings.h"

using namespace magics;

PolyShadingTechniqueAttributes::PolyShadingTechniqueAttributes():
	
	method_(MagTranslator<string, PolyShadingMethod>().magics("contour_shade_method"))
	 
{
} 


PolyShadingTechniqueAttributes::~PolyShadingTechniqueAttributes()
{
	
}

    
void PolyShadingTechniqueAttributes::set(const std::map<string, string>& params)
{
	vector<string> prefix(5);
	int i = 0;
	prefix[i++] = "contour";
	prefix[i++] = "contour";
	prefix[i++] = "contour_shade";
	prefix[i++] = "contour_shade";
	prefix[i++] = "contour_shade";
	
	
	setMember(prefix, "contour_shade_method", method_, params);
	
}

void PolyShadingTechniqueAttributes::copy(const PolyShadingTechniqueAttributes& other)
{
	method_ = unique_ptr<PolyShadingMethod>(other.method_->clone());
	
} 


bool PolyShadingTechniqueAttributes::accept(const string& node)
{	
	
	if ( magCompare(node, "polygon")  )
		return true;
	if ( acceptNode(node, method_) )
		return true;
	
	return false;
}

void PolyShadingTechniqueAttributes::set(const XmlNode& node)
{
	bool apply = false;

	if ( this->accept(node.name()) == false ) 
		return;

	if ( magCompare(node.name(), "polygon")  )
		apply = true;
	

	if ( apply )
		set(node.attributes());
	else {
		setMember(node.name(), method_, node);
		
	}
	for (auto &elt : node.elements())
	{
		setMember(elt->name(), method_, *elt); 
		
	}
}

void PolyShadingTechniqueAttributes::print(ostream& out)  const
{
	out << "Attributes[";
	out << " method = " <<  *method_;
	
	out << "]" << "\n";
}

void PolyShadingTechniqueAttributes::toxml(ostream& out)  const
{
	out <<  "\"polygon\""; 
	out << ", \"contour_shade_method\":";
	method_->toxml(out);
	
}

static MagicsParameter<string> contour_shade_method("contour_shade_method", "dot", ""); 
#include "HatchPolyShadingMethod.h"
#include "DotPolyShadingMethod.h"
#include "PolyShadingMethod.h"
static SimpleObjectMaker<PolyShadingMethod , PolyShadingMethod> area_PolyShadingMethod("area");
static SimpleObjectMaker<PolyShadingMethod , PolyShadingMethod> area_fill_PolyShadingMethod("area_fill");
static SimpleObjectMaker<PolyShadingMethod , PolyShadingMethod> solid_PolyShadingMethod("solid");
static SimpleObjectMaker<DotPolyShadingMethod , PolyShadingMethod> dot_DotPolyShadingMethod("dot");
static SimpleObjectMaker<HatchPolyShadingMethod , PolyShadingMethod> hatch_HatchPolyShadingMethod("hatch");
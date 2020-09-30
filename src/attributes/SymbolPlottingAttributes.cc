
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file SymbolPlottingAttributes.h
    \\brief Definition of SymbolPlotting Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 2020-09-24
*/

#include "SymbolPlottingAttributes.h"
#include "MagicsParameter.h"
#include "ParameterSettings.h"

using namespace magics;

SymbolPlottingAttributes::SymbolPlottingAttributes():
	legend_(ParameterManager::getBool("legend")),
	scaling_method_(ParameterManager::getBool("symbol_scaling_method")),
	scaling_level_0_(ParameterManager::getDouble("symbol_scaling_level_0_height")),
	scaling_factor_(ParameterManager::getDouble("symbol_scaling_factor")),
	type_(ParameterManager::getString("symbol_type")),
	marker_mode_(ParameterManager::getString("symbol_marker_mode")),
	format_(ParameterManager::getString("symbol_format")),
	text_blanking_(ParameterManager::getBool("symbol_text_blanking")),
	outline_(ParameterManager::getBool("symbol_outline")),
	outline_thickness_(ParameterManager::getInt("symbol_outline_thickness")),
	connect_(ParameterManager::getBool("symbol_connect_line")),
	automatic_connect_colour_(ParameterManager::getBool("symbol_connect_automatic_line_colour")),
	connect_thickness_(ParameterManager::getInt("symbol_connect_line_thickness")),
	legend_only_(ParameterManager::getBool("symbol_legend_only"))
	,
	mode_(MagTranslator<string, SymbolMode>().magics("symbol_table_mode")),
	outline_colour_(MagTranslator<string, Colour>().magics("symbol_outline_colour")),
	outline_style_(MagTranslator<string, LineStyle>().magics("symbol_outline_style")),
	connect_colour_(MagTranslator<string, Colour>().magics("symbol_connect_line_colour")),
	connect_style_(MagTranslator<string, LineStyle>().magics("symbol_connect_line_style"))
	 
{
} 


SymbolPlottingAttributes::~SymbolPlottingAttributes()
{
	
}

    
void SymbolPlottingAttributes::set(const std::map<string, string>& params)
{
	vector<string> prefix(1);
	int i = 0;
	prefix[i++] = "symbol";
	
	setAttribute(prefix, "legend", legend_, params);
	setAttribute(prefix, "symbol_scaling_method", scaling_method_, params);
	setAttribute(prefix, "symbol_scaling_level_0_height", scaling_level_0_, params);
	setAttribute(prefix, "symbol_scaling_factor", scaling_factor_, params);
	setAttribute(prefix, "symbol_type", type_, params);
	setAttribute(prefix, "symbol_marker_mode", marker_mode_, params);
	setAttribute(prefix, "symbol_format", format_, params);
	setAttribute(prefix, "symbol_text_blanking", text_blanking_, params);
	setAttribute(prefix, "symbol_outline", outline_, params);
	setAttribute(prefix, "symbol_outline_thickness", outline_thickness_, params);
	setAttribute(prefix, "symbol_connect_line", connect_, params);
	setAttribute(prefix, "symbol_connect_automatic_line_colour", automatic_connect_colour_, params);
	setAttribute(prefix, "symbol_connect_line_thickness", connect_thickness_, params);
	setAttribute(prefix, "symbol_legend_only", legend_only_, params);
	
	setMember(prefix, "symbol_table_mode", mode_, params);
	setMember(prefix, "symbol_outline_colour", outline_colour_, params);
	setAttribute(prefix, "symbol_outline_style", outline_style_, params);
	setMember(prefix, "symbol_connect_line_colour", connect_colour_, params);
	setAttribute(prefix, "symbol_connect_line_style", connect_style_, params);
	
}

void SymbolPlottingAttributes::copy(const SymbolPlottingAttributes& other)
{
	legend_ = other.legend_;
	scaling_method_ = other.scaling_method_;
	scaling_level_0_ = other.scaling_level_0_;
	scaling_factor_ = other.scaling_factor_;
	type_ = other.type_;
	marker_mode_ = other.marker_mode_;
	format_ = other.format_;
	text_blanking_ = other.text_blanking_;
	outline_ = other.outline_;
	outline_thickness_ = other.outline_thickness_;
	connect_ = other.connect_;
	automatic_connect_colour_ = other.automatic_connect_colour_;
	connect_thickness_ = other.connect_thickness_;
	legend_only_ = other.legend_only_;
	mode_ = unique_ptr<SymbolMode>(other.mode_->clone());
	outline_colour_ = unique_ptr<Colour>(other.outline_colour_->clone());
	outline_style_ = other.outline_style_;
	connect_colour_ = unique_ptr<Colour>(other.connect_colour_->clone());
	connect_style_ = other.connect_style_;
	
} 


bool SymbolPlottingAttributes::accept(const string& node)
{	
	
	if ( magCompare(node, "symbol")  )
		return true;
	if ( acceptNode(node, mode_) )
		return true;
	
	return false;
}

void SymbolPlottingAttributes::set(const XmlNode& node)
{
	bool apply = false;

	if ( this->accept(node.name()) == false ) 
		return;

	if ( magCompare(node.name(), "symbol")  )
		apply = true;
	

	if ( apply )
		set(node.attributes());
	else {
		setMember(node.name(), mode_, node);
		
	}
	for (auto &elt : node.elements())
	{
		setMember(elt->name(), mode_, *elt); 
		
	}
}

void SymbolPlottingAttributes::print(ostream& out)  const
{
	out << "Attributes[";
	out << " legend = " <<  legend_;
	out << " scaling_method = " <<  scaling_method_;
	out << " scaling_level_0 = " <<  scaling_level_0_;
	out << " scaling_factor = " <<  scaling_factor_;
	out << " type = " <<  type_;
	out << " marker_mode = " <<  marker_mode_;
	out << " format = " <<  format_;
	out << " text_blanking = " <<  text_blanking_;
	out << " outline = " <<  outline_;
	out << " outline_thickness = " <<  outline_thickness_;
	out << " connect = " <<  connect_;
	out << " automatic_connect_colour = " <<  automatic_connect_colour_;
	out << " connect_thickness = " <<  connect_thickness_;
	out << " legend_only = " <<  legend_only_;
	out << " mode = " <<  *mode_;
	out << " outline_colour = " <<  *outline_colour_;
	out << " outline_style = " <<  outline_style_;
	out << " connect_colour = " <<  *connect_colour_;
	out << " connect_style = " <<  connect_style_;
	
	out << "]" << "\n";
}

void SymbolPlottingAttributes::toxml(ostream& out)  const
{
	out <<  "\"symbol\""; 
	out << ", \"legend\":";
	niceprint(out,legend_);
	out << ", \"symbol_scaling_method\":";
	niceprint(out,scaling_method_);
	out << ", \"symbol_scaling_level_0_height\":";
	niceprint(out,scaling_level_0_);
	out << ", \"symbol_scaling_factor\":";
	niceprint(out,scaling_factor_);
	out << ", \"symbol_type\":";
	niceprint(out,type_);
	out << ", \"symbol_marker_mode\":";
	niceprint(out,marker_mode_);
	out << ", \"symbol_format\":";
	niceprint(out,format_);
	out << ", \"symbol_text_blanking\":";
	niceprint(out,text_blanking_);
	out << ", \"symbol_outline\":";
	niceprint(out,outline_);
	out << ", \"symbol_outline_thickness\":";
	niceprint(out,outline_thickness_);
	out << ", \"symbol_connect_line\":";
	niceprint(out,connect_);
	out << ", \"symbol_connect_automatic_line_colour\":";
	niceprint(out,automatic_connect_colour_);
	out << ", \"symbol_connect_line_thickness\":";
	niceprint(out,connect_thickness_);
	out << ", \"symbol_legend_only\":";
	niceprint(out,legend_only_);
	out << ", \"symbol_table_mode\":";
	mode_->toxml(out);
	out << ", \"symbol_outline_colour\":";
	niceprint(out, *outline_colour_);
	out << ", \"symbol_outline_style\":";
	niceprint(out, outline_style_);
	out << ", \"symbol_connect_line_colour\":";
	niceprint(out, *connect_colour_);
	out << ", \"symbol_connect_line_style\":";
	niceprint(out, connect_style_);
	
}

static MagicsParameter<string> legend("legend", "off", "");
static MagicsParameter<string> symbol_scaling_method("symbol_scaling_method", "off", "");
static MagicsParameter<double> symbol_scaling_level_0_height("symbol_scaling_level_0_height", 0.1, "");
static MagicsParameter<double> symbol_scaling_factor("symbol_scaling_factor", 4., "");
static MagicsParameter<string> symbol_type("symbol_type", "number", "");
static MagicsParameter<string> symbol_marker_mode("symbol_marker_mode", "index", "");
static MagicsParameter<string> symbol_format("symbol_format", "(automatic)", "");
static MagicsParameter<string> symbol_text_blanking("symbol_text_blanking", "off", "");
static MagicsParameter<string> symbol_outline("symbol_outline", "off", "");
static MagicsParameter<int> symbol_outline_thickness("symbol_outline_thickness", 1, "");
static MagicsParameter<string> symbol_connect_line("symbol_connect_line", "off", "");
static MagicsParameter<string> symbol_connect_automatic_line_colour("symbol_connect_automatic_line_colour", "on", "");
static MagicsParameter<int> symbol_connect_line_thickness("symbol_connect_line_thickness", 1, "");
static MagicsParameter<string> symbol_legend_only("symbol_legend_only", "off", "");
static MagicsParameter<string> symbol_table_mode("symbol_table_mode", "OFF", ""); 
static MagicsParameter<string> symbol_outline_colour("symbol_outline_colour", "black", ""); 
static MagicsParameter<string> symbol_outline_style("symbol_outline_style", "solid", ""); 
static MagicsParameter<string> symbol_connect_line_colour("symbol_connect_line_colour", "black", ""); 
static MagicsParameter<string> symbol_connect_line_style("symbol_connect_line_style", "solid", ""); 
#include "SymbolAdvancedTableMode.h"
#include "SymbolMode.h"
static SimpleObjectMaker<SymbolIndividualMode , SymbolMode> individual_SymbolIndividualMode("individual");
static SimpleObjectMaker<SymbolIndividualMode , SymbolMode> off_SymbolIndividualMode("off");
static SimpleObjectMaker<SymbolAdvancedTableMode , SymbolMode> advanced_SymbolAdvancedTableMode("advanced");
static SimpleObjectMaker<SymbolTableMode , SymbolMode> table_SymbolTableMode("table");
static SimpleObjectMaker<SymbolTableMode , SymbolMode> on_SymbolTableMode("on");
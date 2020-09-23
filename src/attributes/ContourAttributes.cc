
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file ContourAttributes.h
    \\brief Definition of Contour Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 2020-09-22
*/

#include "ContourAttributes.h"
#include "MagicsParameter.h"
#include "ParameterSettings.h"

using namespace magics;

ContourAttributes::ContourAttributes():
	legend_(ParameterManager::getBool("legend")),
	floor_(ParameterManager::getDouble("contour_interpolation_floor")),
	ceiling_(ParameterManager::getDouble("contour_interpolation_ceiling")),
	setting_(ParameterManager::getString("contour_automatic_setting")),
	predefined_(ParameterManager::getString("contour_style_name")),
	metadata_only_(ParameterManager::getBool("contour_metadata_only")),
	library_path_(ParameterManager::getString("contour_automatic_library_path"))
	,
	contour_(MagTranslator<string, IsoPlot>().magics("contour")),
	method_(MagTranslator<string, ContourMethod>().magics("contour_method")),
	hilo_(MagTranslator<string, HiLoBase>().magics("contour_hilo")),
	grid_(MagTranslator<string, ValuePlotBase>().magics("contour_grid_value_plot"))
	 
{
} 


ContourAttributes::~ContourAttributes()
{
	
}

    
void ContourAttributes::set(const std::map<string, string>& params)
{
	vector<string> prefix(1);
	int i = 0;
	prefix[i++] = "contour";
	
	setAttribute(prefix, "legend", legend_, params);
	setAttribute(prefix, "contour_interpolation_floor", floor_, params);
	setAttribute(prefix, "contour_interpolation_ceiling", ceiling_, params);
	setAttribute(prefix, "contour_automatic_setting", setting_, params);
	setAttribute(prefix, "contour_style_name", predefined_, params);
	setAttribute(prefix, "contour_metadata_only", metadata_only_, params);
	setAttribute(prefix, "contour_automatic_library_path", library_path_, params);
	
	setMember(prefix, "contour", contour_, params);
	setMember(prefix, "contour_method", method_, params);
	setMember(prefix, "contour_hilo", hilo_, params);
	setMember(prefix, "contour_grid_value_plot", grid_, params);
	
}

void ContourAttributes::copy(const ContourAttributes& other)
{
	legend_ = other.legend_;
	floor_ = other.floor_;
	ceiling_ = other.ceiling_;
	setting_ = other.setting_;
	predefined_ = other.predefined_;
	metadata_only_ = other.metadata_only_;
	library_path_ = other.library_path_;
	contour_ = unique_ptr<IsoPlot>(other.contour_->clone());
	method_ = unique_ptr<ContourMethod>(other.method_->clone());
	hilo_ = unique_ptr<HiLoBase>(other.hilo_->clone());
	grid_ = unique_ptr<ValuePlotBase>(other.grid_->clone());
	
} 


bool ContourAttributes::accept(const string& node)
{	
	
	if ( magCompare(node, "contour")  )
		return true;
	if ( acceptNode(node, contour_) )
		return true;
	if ( acceptNode(node, method_) )
		return true;
	if ( acceptNode(node, hilo_) )
		return true;
	if ( acceptNode(node, grid_) )
		return true;
	
	return false;
}

void ContourAttributes::set(const XmlNode& node)
{
	bool apply = false;

	if ( this->accept(node.name()) == false ) 
		return;

	if ( magCompare(node.name(), "contour")  )
		apply = true;
	

	if ( apply )
		set(node.attributes());
	else {
		setMember(node.name(), contour_, node);
		setMember(node.name(), method_, node);
		setMember(node.name(), hilo_, node);
		setMember(node.name(), grid_, node);
		
	}
	for (auto &elt : node.elements())
	{
		setMember(elt->name(), contour_, *elt); 
		setMember(elt->name(), method_, *elt); 
		setMember(elt->name(), hilo_, *elt); 
		setMember(elt->name(), grid_, *elt); 
		
	}
}

void ContourAttributes::print(ostream& out)  const
{
	out << "Attributes[";
	out << " legend = " <<  legend_;
	out << " floor = " <<  floor_;
	out << " ceiling = " <<  ceiling_;
	out << " setting = " <<  setting_;
	out << " predefined = " <<  predefined_;
	out << " metadata_only = " <<  metadata_only_;
	out << " library_path = " <<  library_path_;
	out << " contour = " <<  *contour_;
	out << " method = " <<  *method_;
	out << " hilo = " <<  *hilo_;
	out << " grid = " <<  *grid_;
	
	out << "]" << "\n";
}

void ContourAttributes::toxml(ostream& out)  const
{
	out <<  "\"contour\""; 
	out << ", \"legend\":";
	niceprint(out,legend_);
	out << ", \"contour_interpolation_floor\":";
	niceprint(out,floor_);
	out << ", \"contour_interpolation_ceiling\":";
	niceprint(out,ceiling_);
	out << ", \"contour_automatic_setting\":";
	niceprint(out,setting_);
	out << ", \"contour_style_name\":";
	niceprint(out,predefined_);
	out << ", \"contour_metadata_only\":";
	niceprint(out,metadata_only_);
	out << ", \"contour_automatic_library_path\":";
	niceprint(out,library_path_);
	out << ", \"contour\":";
	contour_->toxml(out);
	out << ", \"contour_method\":";
	method_->toxml(out);
	out << ", \"contour_hilo\":";
	hilo_->toxml(out);
	out << ", \"contour_grid_value_plot\":";
	grid_->toxml(out);
	
}

static MagicsParameter<string> legend("legend", "off", "");
static MagicsParameter<double> contour_interpolation_floor("contour_interpolation_floor", -INT_MAX, "");
static MagicsParameter<double> contour_interpolation_ceiling("contour_interpolation_ceiling", INT_MAX, "");
static MagicsParameter<string> contour_automatic_setting("contour_automatic_setting", "off", "");
static MagicsParameter<string> contour_style_name("contour_style_name", "", "");
static MagicsParameter<string> contour_metadata_only("contour_metadata_only", "off", "");
static MagicsParameter<string> contour_automatic_library_path("contour_automatic_library_path", "", "");
static MagicsParameter<string> contour("contour", "on", ""); 
static MagicsParameter<string> contour_method("contour_method", "automatic", ""); 
static MagicsParameter<string> contour_hilo("contour_hilo", "off", ""); 
static MagicsParameter<string> contour_grid_value_plot("contour_grid_value_plot", "off", ""); 
#include "IsoPlot.h"
#include "HiLo.h"
#include "Akima474Method.h"
#include "ContourMethod.h"
#include "Akima760Method.h"
#include "ValuePlot.h"
#include "AutomaticContourMethod.h"
static SimpleObjectMaker<IsoPlot , IsoPlot> isoline_IsoPlot("isoline");
static SimpleObjectMaker<IsoPlot , IsoPlot> on_IsoPlot("on");
static SimpleObjectMaker<NoIsoPlot , IsoPlot> noisoline_NoIsoPlot("noisoline");
static SimpleObjectMaker<NoIsoPlot , IsoPlot> off_NoIsoPlot("off");
static SimpleObjectMaker<AutomaticContourMethod , ContourMethod> automatic_AutomaticContourMethod("automatic");
static SimpleObjectMaker<ContourMethod , ContourMethod> linear_ContourMethod("linear");
static SimpleObjectMaker<Akima760Method , ContourMethod> akima760_Akima760Method("akima760");
static SimpleObjectMaker<Akima474Method , ContourMethod> akima474_Akima474Method("akima474");
static SimpleObjectMaker<HiLo , HiLoBase> hilo_HiLo("hilo");
static SimpleObjectMaker<HiLo , HiLoBase> on_HiLo("on");
static SimpleObjectMaker<NoHiLo , HiLoBase> nohilo_NoHiLo("nohilo");
static SimpleObjectMaker<NoHiLo , HiLoBase> off_NoHiLo("off");
static SimpleObjectMaker<HighHiLo , HiLoBase> high_HighHiLo("high");
static SimpleObjectMaker<HighHiLo , HiLoBase> hi_HighHiLo("hi");
static SimpleObjectMaker<LowHiLo , HiLoBase> low_LowHiLo("low");
static SimpleObjectMaker<LowHiLo , HiLoBase> lo_LowHiLo("lo");
static SimpleObjectMaker<ValuePlot , ValuePlotBase> gridvalues_ValuePlot("gridvalues");
static SimpleObjectMaker<ValuePlot , ValuePlotBase> on_ValuePlot("on");
static SimpleObjectMaker<NoValuePlot , ValuePlotBase> nogridvalues_NoValuePlot("nogridvalues");
static SimpleObjectMaker<NoValuePlot , ValuePlotBase> off_NoValuePlot("off");

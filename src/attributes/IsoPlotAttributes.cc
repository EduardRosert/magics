
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file IsoPlotAttributes.h
    \\brief Definition of IsoPlot Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 2020-09-22
*/

#include "IsoPlotAttributes.h"
#include "MagicsParameter.h"
#include "ParameterSettings.h"

using namespace magics;

IsoPlotAttributes::IsoPlotAttributes():
	legend_special_(ParameterManager::getString("contour_special_legend")),
	user_thread_(ParameterManager::getInt("contour_threads")),
	resolution_(ParameterManager::getDouble("contour_internal_reduction_factor")),
	technique_(ParameterManager::getString("contour_internal_technique")),
	legend_text_(ParameterManager::getString("contour_legend_text")),
	thickness_(ParameterManager::getInt("contour_line_thickness")),
	rainbow_(ParameterManager::getBool("contour_line_colour_rainbow")),
	rainbowDirection_(ParameterManager::getString("contour_line_colour_rainbow_direction")),
	rainbowColours_(ParameterManager::getStringArray("contour_line_colour_rainbow_colour_list")),
	rainbowThicknessList_(ParameterManager::getIntArray("contour_line_thickness_rainbow_list")),
	rainbowStyleList_(ParameterManager::getStringArray("contour_line_style_rainbow_list")),
	legend_only_(ParameterManager::getBool("contour_legend_only"))
	,
	style_(MagTranslator<string, LineStyle>().magics("contour_line_style")),
	colour_(MagTranslator<string, Colour>().magics("contour_line_colour")),
	rainbowMethod_(MagTranslator<string, ColourTechnique>().magics("contour_line_colour_rainbow_method")),
	rainbowMaxColour_(MagTranslator<string, Colour>().magics("contour_line_colour_rainbow_max_level_colour")),
	rainbowMinColour_(MagTranslator<string, Colour>().magics("contour_line_colour_rainbow_min_level_colour")),
	rainbowColourPolicy_(MagTranslator<string, ListPolicy>().magics("contour_line_colour_rainbow_colour_list_policy")),
	rainbowThicknessListPolicy_(MagTranslator<string, ListPolicy>().magics("contour_line_thickness_rainbow_list_policy")),
	rainbowStyleListPolicy_(MagTranslator<string, ListPolicy>().magics("contour_line_style_rainbow_list_policy")),
	highlight_(MagTranslator<string, NoIsoHighlight>().magics("contour_highlight")),
	levelSelection_(MagTranslator<string, LevelSelection>().magics("contour_level_selection_type")),
	label_(MagTranslator<string, NoIsoLabel>().magics("contour_label")),
	shading_(MagTranslator<string, NoIsoShading>().magics("contour_shade"))
	 
{
} 


IsoPlotAttributes::~IsoPlotAttributes()
{
	
}

    
void IsoPlotAttributes::set(const std::map<string, string>& params)
{
	vector<string> prefix(2);
	int i = 0;
	prefix[i++] = "contour";
	prefix[i++] = "contour_line";
	
	setAttribute(prefix, "contour_special_legend", legend_special_, params);
	setAttribute(prefix, "contour_threads", user_thread_, params);
	setAttribute(prefix, "contour_internal_reduction_factor", resolution_, params);
	setAttribute(prefix, "contour_internal_technique", technique_, params);
	setAttribute(prefix, "contour_legend_text", legend_text_, params);
	setAttribute(prefix, "contour_line_thickness", thickness_, params);
	setAttribute(prefix, "contour_line_colour_rainbow", rainbow_, params);
	setAttribute(prefix, "contour_line_colour_rainbow_direction", rainbowDirection_, params);
	setAttribute(prefix, "contour_line_colour_rainbow_colour_list", rainbowColours_, params);
	setAttribute(prefix, "contour_line_thickness_rainbow_list", rainbowThicknessList_, params);
	setAttribute(prefix, "contour_line_style_rainbow_list", rainbowStyleList_, params);
	setAttribute(prefix, "contour_legend_only", legend_only_, params);
	
	setAttribute(prefix, "contour_line_style", style_, params);
	setMember(prefix, "contour_line_colour", colour_, params);
	setMember(prefix, "contour_line_colour_rainbow_method", rainbowMethod_, params);
	setMember(prefix, "contour_line_colour_rainbow_max_level_colour", rainbowMaxColour_, params);
	setMember(prefix, "contour_line_colour_rainbow_min_level_colour", rainbowMinColour_, params);
	setAttribute(prefix, "contour_line_colour_rainbow_colour_list_policy", rainbowColourPolicy_, params);
	setAttribute(prefix, "contour_line_thickness_rainbow_list_policy", rainbowThicknessListPolicy_, params);
	setAttribute(prefix, "contour_line_style_rainbow_list_policy", rainbowStyleListPolicy_, params);
	setMember(prefix, "contour_highlight", highlight_, params);
	setMember(prefix, "contour_level_selection_type", levelSelection_, params);
	setMember(prefix, "contour_label", label_, params);
	setMember(prefix, "contour_shade", shading_, params);
	
}

void IsoPlotAttributes::copy(const IsoPlotAttributes& other)
{
	legend_special_ = other.legend_special_;
	user_thread_ = other.user_thread_;
	resolution_ = other.resolution_;
	technique_ = other.technique_;
	legend_text_ = other.legend_text_;
	thickness_ = other.thickness_;
	rainbow_ = other.rainbow_;
	rainbowDirection_ = other.rainbowDirection_;
	rainbowColours_ = other.rainbowColours_;
	rainbowThicknessList_ = other.rainbowThicknessList_;
	rainbowStyleList_ = other.rainbowStyleList_;
	legend_only_ = other.legend_only_;
	style_ = other.style_;
	colour_ = unique_ptr<Colour>(other.colour_->clone());
	rainbowMethod_ = unique_ptr<ColourTechnique>(other.rainbowMethod_->clone());
	rainbowMaxColour_ = unique_ptr<Colour>(other.rainbowMaxColour_->clone());
	rainbowMinColour_ = unique_ptr<Colour>(other.rainbowMinColour_->clone());
	rainbowColourPolicy_ = other.rainbowColourPolicy_;
	rainbowThicknessListPolicy_ = other.rainbowThicknessListPolicy_;
	rainbowStyleListPolicy_ = other.rainbowStyleListPolicy_;
	highlight_ = unique_ptr<NoIsoHighlight>(other.highlight_->clone());
	levelSelection_ = unique_ptr<LevelSelection>(other.levelSelection_->clone());
	label_ = unique_ptr<NoIsoLabel>(other.label_->clone());
	shading_ = unique_ptr<NoIsoShading>(other.shading_->clone());
	
} 


bool IsoPlotAttributes::accept(const string& node)
{	
	
	if ( magCompare(node, "isoline")  )
		return true;
	if ( acceptNode(node, rainbowMethod_) )
		return true;
	if ( acceptNode(node, highlight_) )
		return true;
	if ( acceptNode(node, levelSelection_) )
		return true;
	if ( acceptNode(node, label_) )
		return true;
	if ( acceptNode(node, shading_) )
		return true;
	
	return false;
}

void IsoPlotAttributes::set(const XmlNode& node)
{
	bool apply = false;

	if ( this->accept(node.name()) == false ) 
		return;

	if ( magCompare(node.name(), "isoline")  )
		apply = true;
	

	if ( apply )
		set(node.attributes());
	else {
		setMember(node.name(), rainbowMethod_, node);
		setMember(node.name(), highlight_, node);
		setMember(node.name(), levelSelection_, node);
		setMember(node.name(), label_, node);
		setMember(node.name(), shading_, node);
		
	}
	for (auto &elt : node.elements())
	{
		setMember(elt->name(), rainbowMethod_, *elt); 
		setMember(elt->name(), highlight_, *elt); 
		setMember(elt->name(), levelSelection_, *elt); 
		setMember(elt->name(), label_, *elt); 
		setMember(elt->name(), shading_, *elt); 
		
	}
}

void IsoPlotAttributes::print(ostream& out)  const
{
	out << "Attributes[";
	out << " legend_special = " <<  legend_special_;
	out << " user_thread = " <<  user_thread_;
	out << " resolution = " <<  resolution_;
	out << " technique = " <<  technique_;
	out << " legend_text = " <<  legend_text_;
	out << " thickness = " <<  thickness_;
	out << " rainbow = " <<  rainbow_;
	out << " rainbowDirection = " <<  rainbowDirection_;
	out << " rainbowColours = " <<  rainbowColours_;
	out << " rainbowThicknessList = " <<  rainbowThicknessList_;
	out << " rainbowStyleList = " <<  rainbowStyleList_;
	out << " legend_only = " <<  legend_only_;
	out << " style = " <<  style_;
	out << " colour = " <<  *colour_;
	out << " rainbowMethod = " <<  *rainbowMethod_;
	out << " rainbowMaxColour = " <<  *rainbowMaxColour_;
	out << " rainbowMinColour = " <<  *rainbowMinColour_;
	out << " rainbowColourPolicy = " <<  rainbowColourPolicy_;
	out << " rainbowThicknessListPolicy = " <<  rainbowThicknessListPolicy_;
	out << " rainbowStyleListPolicy = " <<  rainbowStyleListPolicy_;
	out << " highlight = " <<  *highlight_;
	out << " levelSelection = " <<  *levelSelection_;
	out << " label = " <<  *label_;
	out << " shading = " <<  *shading_;
	
	out << "]" << "\n";
}

void IsoPlotAttributes::toxml(ostream& out)  const
{
	out <<  "\"isoline\""; 
	out << ", \"contour_special_legend\":";
	niceprint(out,legend_special_);
	out << ", \"contour_threads\":";
	niceprint(out,user_thread_);
	out << ", \"contour_internal_reduction_factor\":";
	niceprint(out,resolution_);
	out << ", \"contour_internal_technique\":";
	niceprint(out,technique_);
	out << ", \"contour_legend_text\":";
	niceprint(out,legend_text_);
	out << ", \"contour_line_thickness\":";
	niceprint(out,thickness_);
	out << ", \"contour_line_colour_rainbow\":";
	niceprint(out,rainbow_);
	out << ", \"contour_line_colour_rainbow_direction\":";
	niceprint(out,rainbowDirection_);
	out << ", \"contour_line_colour_rainbow_colour_list\":";
	niceprint(out,rainbowColours_);
	out << ", \"contour_line_thickness_rainbow_list\":";
	niceprint(out,rainbowThicknessList_);
	out << ", \"contour_line_style_rainbow_list\":";
	niceprint(out,rainbowStyleList_);
	out << ", \"contour_legend_only\":";
	niceprint(out,legend_only_);
	out << ", \"contour_line_style\":";
	niceprint(out, style_);
	out << ", \"contour_line_colour\":";
	niceprint(out, *colour_);
	out << ", \"contour_line_colour_rainbow_method\":";
	rainbowMethod_->toxml(out);
	out << ", \"contour_line_colour_rainbow_max_level_colour\":";
	niceprint(out, *rainbowMaxColour_);
	out << ", \"contour_line_colour_rainbow_min_level_colour\":";
	niceprint(out, *rainbowMinColour_);
	out << ", \"contour_line_colour_rainbow_colour_list_policy\":";
	niceprint(out, rainbowColourPolicy_);
	out << ", \"contour_line_thickness_rainbow_list_policy\":";
	niceprint(out, rainbowThicknessListPolicy_);
	out << ", \"contour_line_style_rainbow_list_policy\":";
	niceprint(out, rainbowStyleListPolicy_);
	out << ", \"contour_highlight\":";
	highlight_->toxml(out);
	out << ", \"contour_level_selection_type\":";
	levelSelection_->toxml(out);
	out << ", \"contour_label\":";
	label_->toxml(out);
	out << ", \"contour_shade\":";
	shading_->toxml(out);
	
}

static MagicsParameter<string> contour_special_legend("contour_special_legend", "", "");
static MagicsParameter<int> contour_threads("contour_threads", 4, "");
static MagicsParameter<double> contour_internal_reduction_factor("contour_internal_reduction_factor", 4, "");
static MagicsParameter<string> contour_internal_technique("contour_internal_technique", "interpolate", "");
static MagicsParameter<string> contour_legend_text("contour_legend_text", " ", "");
static MagicsParameter<int> contour_line_thickness("contour_line_thickness", 1, "");
static MagicsParameter<string> contour_line_colour_rainbow("contour_line_colour_rainbow", "off", "");
static MagicsParameter<string> contour_line_colour_rainbow_direction("contour_line_colour_rainbow_direction", "anti_clockwise", "");
static MagicsParameter<stringarray> contour_line_colour_rainbow_colour_list("contour_line_colour_rainbow_colour_list", stringarray(), "");
static MagicsParameter<intarray> contour_line_thickness_rainbow_list("contour_line_thickness_rainbow_list", intarray(), "");
static MagicsParameter<stringarray> contour_line_style_rainbow_list("contour_line_style_rainbow_list", stringarray(), "");
static MagicsParameter<string> contour_legend_only("contour_legend_only", "off", "");
static MagicsParameter<string> contour_line_style("contour_line_style", "solid", ""); 
static MagicsParameter<string> contour_line_colour("contour_line_colour", "blue", ""); 
static MagicsParameter<string> contour_line_colour_rainbow_method("contour_line_colour_rainbow_method", "calculate", ""); 
static MagicsParameter<string> contour_line_colour_rainbow_max_level_colour("contour_line_colour_rainbow_max_level_colour", "blue", ""); 
static MagicsParameter<string> contour_line_colour_rainbow_min_level_colour("contour_line_colour_rainbow_min_level_colour", "red", ""); 
static MagicsParameter<string> contour_line_colour_rainbow_colour_list_policy("contour_line_colour_rainbow_colour_list_policy", "lastone", ""); 
static MagicsParameter<string> contour_line_thickness_rainbow_list_policy("contour_line_thickness_rainbow_list_policy", "lastone", ""); 
static MagicsParameter<string> contour_line_style_rainbow_list_policy("contour_line_style_rainbow_list_policy", "lastone", ""); 
static MagicsParameter<string> contour_highlight("contour_highlight", "on", ""); 
static MagicsParameter<string> contour_level_selection_type("contour_level_selection_type", "count", ""); 
static MagicsParameter<string> contour_label("contour_label", "on", ""); 
static MagicsParameter<string> contour_shade("contour_shade", "off", ""); 
#include "IsoLabel.h"
#include "IsoHighlight.h"
#include "LevelListSelectionType.h"
#include "IntervalSelectionType.h"
#include "CountSelectionType.h"
#include "IsoShading.h"
static SimpleObjectMaker<IsoHighlight , NoIsoHighlight> highlight_IsoHighlight("highlight");
static SimpleObjectMaker<IsoHighlight , NoIsoHighlight> on_IsoHighlight("on");
static SimpleObjectMaker<NoIsoHighlight , NoIsoHighlight> nohighlight_NoIsoHighlight("nohighlight");
static SimpleObjectMaker<NoIsoHighlight , NoIsoHighlight> off_NoIsoHighlight("off");
static SimpleObjectMaker<CountSelectionType , LevelSelection> count_CountSelectionType("count");
static SimpleObjectMaker<IntervalSelectionType , LevelSelection> interval_IntervalSelectionType("interval");
static SimpleObjectMaker<LevelListSelectionType , LevelSelection> list_LevelListSelectionType("list");
static SimpleObjectMaker<LevelListSelectionType , LevelSelection> level_list_LevelListSelectionType("level_list");
static SimpleObjectMaker<IsoLabel , NoIsoLabel> label_IsoLabel("label");
static SimpleObjectMaker<IsoLabel , NoIsoLabel> on_IsoLabel("on");
static SimpleObjectMaker<NoIsoLabel , NoIsoLabel> nolabel_NoIsoLabel("nolabel");
static SimpleObjectMaker<NoIsoLabel , NoIsoLabel> off_NoIsoLabel("off");
static SimpleObjectMaker<IsoShading , NoIsoShading> shading_IsoShading("shading");
static SimpleObjectMaker<IsoShading , NoIsoShading> on_IsoShading("on");
static SimpleObjectMaker<NoIsoShading , NoIsoShading> noshading_NoIsoShading("noshading");
static SimpleObjectMaker<NoIsoShading , NoIsoShading> off_NoIsoShading("off");

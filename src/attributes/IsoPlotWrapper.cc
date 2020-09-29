
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

    Generated: 2020-09-24
*/

#include "MagRequest.h" 
#include "IsoPlotWrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"

using namespace magics;


IsoPlotWrapper::IsoPlotWrapper(): isoplot_(new IsoPlot())

{

	
	
	
} 
IsoPlotWrapper::IsoPlotWrapper(IsoPlot* isoplot): isoplot_(isoplot)
{
	
	
} 

IsoPlotWrapper::~IsoPlotWrapper()
{
	
}

void IsoPlotWrapper::set(const MagRequest& request)
{
	
	

	if  (request.countValues("CONTOUR_SPECIAL_LEGEND") ) {
		string legend_special_value = request("CONTOUR_SPECIAL_LEGEND");
		isoplot_->legend_special_ = legend_special_value;
		}
	if  (request.countValues("CONTOUR_THREADS") ) {
		int user_thread_value = request("CONTOUR_THREADS");
		isoplot_->user_thread_ = user_thread_value;
		}
	if  (request.countValues("CONTOUR_INTERNAL_REDUCTION_FACTOR") ) {
		double resolution_value = request("CONTOUR_INTERNAL_REDUCTION_FACTOR");
		isoplot_->resolution_ = resolution_value;
		}
	if  (request.countValues("CONTOUR_INTERNAL_TECHNIQUE") ) {
		string technique_value = request("CONTOUR_INTERNAL_TECHNIQUE");
		isoplot_->technique_ = technique_value;
		}
	if  (request.countValues("CONTOUR_LEGEND_TEXT") ) {
		string legend_text_value = request("CONTOUR_LEGEND_TEXT");
		isoplot_->legend_text_ = legend_text_value;
		}
	if  (request.countValues("CONTOUR_LINE_THICKNESS") ) {
		int thickness_value = request("CONTOUR_LINE_THICKNESS");
		isoplot_->thickness_ = thickness_value;
		}
	if  (request.countValues("CONTOUR_LINE_COLOUR_RAINBOW") ) {
		string rainbow_value = request("CONTOUR_LINE_COLOUR_RAINBOW");
		isoplot_->rainbow_ = MagTranslator<string, bool>()(rainbow_value);
		}
	if  (request.countValues("CONTOUR_LINE_COLOUR_RAINBOW_DIRECTION") ) {
		string rainbowDirection_value = request("CONTOUR_LINE_COLOUR_RAINBOW_DIRECTION");
		isoplot_->rainbowDirection_ = rainbowDirection_value;
		}
	stringarray  rainbowColours_value;
	for (int i = 0; i < request.countValues("CONTOUR_LINE_COLOUR_RAINBOW_COLOUR_LIST"); i++)
		rainbowColours_value.push_back((string)request("CONTOUR_LINE_COLOUR_RAINBOW_COLOUR_LIST", i));
	if ( !rainbowColours_value.empty() ) 
		isoplot_->rainbowColours_ = rainbowColours_value;
	intarray rainbowThicknessList_value;
	for (int i = 0; i < request.countValues("CONTOUR_LINE_THICKNESS_RAINBOW_LIST"); i++)
		rainbowThicknessList_value.push_back((int)request("CONTOUR_LINE_THICKNESS_RAINBOW_LIST", i));
	if ( !rainbowThicknessList_value.empty() ) 
		isoplot_->rainbowThicknessList_ = rainbowThicknessList_value;
	stringarray  rainbowStyleList_value;
	for (int i = 0; i < request.countValues("CONTOUR_LINE_STYLE_RAINBOW_LIST"); i++)
		rainbowStyleList_value.push_back((string)request("CONTOUR_LINE_STYLE_RAINBOW_LIST", i));
	if ( !rainbowStyleList_value.empty() ) 
		isoplot_->rainbowStyleList_ = rainbowStyleList_value;
	if  (request.countValues("CONTOUR_LEGEND_ONLY") ) {
		string legend_only_value = request("CONTOUR_LEGEND_ONLY");
		isoplot_->legend_only_ = MagTranslator<string, bool>()(legend_only_value);
		}
	
	
	if  (request.countValues("CONTOUR_LINE_STYLE") ) {
		string style_value = request("CONTOUR_LINE_STYLE");
		isoplot_->style_ = MagTranslator<string, LineStyle>()(style_value);
	}
		
	if  (request.countValues("CONTOUR_LINE_COLOUR") ) {
		string colour_value = request("CONTOUR_LINE_COLOUR");
		isoplot_->colour_ = unique_ptr<Colour>(MagTranslator<string, Colour>()(colour_value));
	}
		
	
		string rainbowMethod_value = request.countValues("CONTOUR_LINE_COLOUR_RAINBOW_METHOD") ?  (string) request("CONTOUR_LINE_COLOUR_RAINBOW_METHOD") : "calculate";
	MagLog::debug() << " CONTOUR_LINE_COLOUR_RAINBOW_METHOD set to " << rainbowMethod_value << endl;
	ColourTechniqueWrapper* rainbowMethod_wrapper = 0;
#ifdef MAGICS_EXCEPTION
	try
#endif
	{
		rainbowMethod_wrapper = SimpleFactory<ColourTechniqueWrapper>::create(rainbowMethod_value);
	}
#ifdef MAGICS_EXCEPTION
	 catch (NoFactoryException) {
#else
	 if (!rainbowMethod_wrapper) {
#endif
		MagLog::warning() << "[" << rainbowMethod_value << "] is not a valid value for rainbowMethod: reset to default -> [calculate]" << endl;
		rainbowMethod_wrapper = SimpleFactory<ColourTechniqueWrapper>::create("calculate");
	}
	rainbowMethod_wrapper->set(request);
	isoplot_->rainbowMethod_ =  unique_ptr<ColourTechnique>(rainbowMethod_wrapper->object());
	delete rainbowMethod_wrapper;
	if  (request.countValues("CONTOUR_LINE_COLOUR_RAINBOW_MAX_LEVEL_COLOUR") ) {
		string rainbowMaxColour_value = request("CONTOUR_LINE_COLOUR_RAINBOW_MAX_LEVEL_COLOUR");
		isoplot_->rainbowMaxColour_ = unique_ptr<Colour>(MagTranslator<string, Colour>()(rainbowMaxColour_value));
	}
		
	if  (request.countValues("CONTOUR_LINE_COLOUR_RAINBOW_MIN_LEVEL_COLOUR") ) {
		string rainbowMinColour_value = request("CONTOUR_LINE_COLOUR_RAINBOW_MIN_LEVEL_COLOUR");
		isoplot_->rainbowMinColour_ = unique_ptr<Colour>(MagTranslator<string, Colour>()(rainbowMinColour_value));
	}
		
	
	if  (request.countValues("CONTOUR_LINE_COLOUR_RAINBOW_COLOUR_LIST_POLICY") ) {
		string rainbowColourPolicy_value = request("CONTOUR_LINE_COLOUR_RAINBOW_COLOUR_LIST_POLICY");
		isoplot_->rainbowColourPolicy_ = MagTranslator<string, ListPolicy>()(rainbowColourPolicy_value);
	}
		
	
	if  (request.countValues("CONTOUR_LINE_THICKNESS_RAINBOW_LIST_POLICY") ) {
		string rainbowThicknessListPolicy_value = request("CONTOUR_LINE_THICKNESS_RAINBOW_LIST_POLICY");
		isoplot_->rainbowThicknessListPolicy_ = MagTranslator<string, ListPolicy>()(rainbowThicknessListPolicy_value);
	}
		
	
	if  (request.countValues("CONTOUR_LINE_STYLE_RAINBOW_LIST_POLICY") ) {
		string rainbowStyleListPolicy_value = request("CONTOUR_LINE_STYLE_RAINBOW_LIST_POLICY");
		isoplot_->rainbowStyleListPolicy_ = MagTranslator<string, ListPolicy>()(rainbowStyleListPolicy_value);
	}
		
	
		string highlight_value = request.countValues("CONTOUR_HIGHLIGHT") ?  (string) request("CONTOUR_HIGHLIGHT") : "on";
	MagLog::debug() << " CONTOUR_HIGHLIGHT set to " << highlight_value << endl;
	NoIsoHighlightWrapper* highlight_wrapper = 0;
#ifdef MAGICS_EXCEPTION
	try
#endif
	{
		highlight_wrapper = SimpleFactory<NoIsoHighlightWrapper>::create(highlight_value);
	}
#ifdef MAGICS_EXCEPTION
	 catch (NoFactoryException) {
#else
	 if (!highlight_wrapper) {
#endif
		MagLog::warning() << "[" << highlight_value << "] is not a valid value for highlight: reset to default -> [on]" << endl;
		highlight_wrapper = SimpleFactory<NoIsoHighlightWrapper>::create("on");
	}
	highlight_wrapper->set(request);
	isoplot_->highlight_ =  unique_ptr<NoIsoHighlight>(highlight_wrapper->object());
	delete highlight_wrapper;
	
		string levelSelection_value = request.countValues("CONTOUR_LEVEL_SELECTION_TYPE") ?  (string) request("CONTOUR_LEVEL_SELECTION_TYPE") : "count";
	MagLog::debug() << " CONTOUR_LEVEL_SELECTION_TYPE set to " << levelSelection_value << endl;
	LevelSelectionWrapper* levelSelection_wrapper = 0;
#ifdef MAGICS_EXCEPTION
	try
#endif
	{
		levelSelection_wrapper = SimpleFactory<LevelSelectionWrapper>::create(levelSelection_value);
	}
#ifdef MAGICS_EXCEPTION
	 catch (NoFactoryException) {
#else
	 if (!levelSelection_wrapper) {
#endif
		MagLog::warning() << "[" << levelSelection_value << "] is not a valid value for levelSelection: reset to default -> [count]" << endl;
		levelSelection_wrapper = SimpleFactory<LevelSelectionWrapper>::create("count");
	}
	levelSelection_wrapper->set(request);
	isoplot_->levelSelection_ =  unique_ptr<LevelSelection>(levelSelection_wrapper->object());
	delete levelSelection_wrapper;
	
		string label_value = request.countValues("CONTOUR_LABEL") ?  (string) request("CONTOUR_LABEL") : "on";
	MagLog::debug() << " CONTOUR_LABEL set to " << label_value << endl;
	NoIsoLabelWrapper* label_wrapper = 0;
#ifdef MAGICS_EXCEPTION
	try
#endif
	{
		label_wrapper = SimpleFactory<NoIsoLabelWrapper>::create(label_value);
	}
#ifdef MAGICS_EXCEPTION
	 catch (NoFactoryException) {
#else
	 if (!label_wrapper) {
#endif
		MagLog::warning() << "[" << label_value << "] is not a valid value for label: reset to default -> [on]" << endl;
		label_wrapper = SimpleFactory<NoIsoLabelWrapper>::create("on");
	}
	label_wrapper->set(request);
	isoplot_->label_ =  unique_ptr<NoIsoLabel>(label_wrapper->object());
	delete label_wrapper;
	
		string shading_value = request.countValues("CONTOUR_SHADE") ?  (string) request("CONTOUR_SHADE") : "off";
	MagLog::debug() << " CONTOUR_SHADE set to " << shading_value << endl;
	NoIsoShadingWrapper* shading_wrapper = 0;
#ifdef MAGICS_EXCEPTION
	try
#endif
	{
		shading_wrapper = SimpleFactory<NoIsoShadingWrapper>::create(shading_value);
	}
#ifdef MAGICS_EXCEPTION
	 catch (NoFactoryException) {
#else
	 if (!shading_wrapper) {
#endif
		MagLog::warning() << "[" << shading_value << "] is not a valid value for shading: reset to default -> [off]" << endl;
		shading_wrapper = SimpleFactory<NoIsoShadingWrapper>::create("off");
	}
	shading_wrapper->set(request);
	isoplot_->shading_ =  unique_ptr<NoIsoShading>(shading_wrapper->object());
	delete shading_wrapper;
	
}

void IsoPlotWrapper::print(ostream& out)  const
{
	out << "IsoPlotWrapper[]";
}


    











#include "IsoHighlightWrapper.h"
static SimpleObjectMaker<IsoHighlight, NoIsoHighlight> IsoPlot_contour_highlight_highlight ("highlight");
static SimpleObjectMaker<IsoHighlightWrapper, NoIsoHighlightWrapper> IsoPlot_contour_highlight_highlight_wrapper ("highlight");


#include "IsoHighlightWrapper.h"
static SimpleObjectMaker<IsoHighlight, NoIsoHighlight> IsoPlot_contour_highlight_on ("on");
static SimpleObjectMaker<IsoHighlightWrapper, NoIsoHighlightWrapper> IsoPlot_contour_highlight_on_wrapper ("on");


#include "NoIsoHighlightWrapper.h"

static SimpleObjectMaker<NoIsoHighlightWrapper> IsoPlot_contour_highlight_nohighlight_Wrapper("nohighlight");


#include "NoIsoHighlightWrapper.h"

static SimpleObjectMaker<NoIsoHighlightWrapper> IsoPlot_contour_highlight_off_Wrapper("off");



#include "CountSelectionTypeWrapper.h"
static SimpleObjectMaker<CountSelectionType, LevelSelection> IsoPlot_contour_level_selection_type_count ("count");
static SimpleObjectMaker<CountSelectionTypeWrapper, LevelSelectionWrapper> IsoPlot_contour_level_selection_type_count_wrapper ("count");


#include "IntervalSelectionTypeWrapper.h"
static SimpleObjectMaker<IntervalSelectionType, LevelSelection> IsoPlot_contour_level_selection_type_interval ("interval");
static SimpleObjectMaker<IntervalSelectionTypeWrapper, LevelSelectionWrapper> IsoPlot_contour_level_selection_type_interval_wrapper ("interval");


#include "LevelListSelectionTypeWrapper.h"
static SimpleObjectMaker<LevelListSelectionType, LevelSelection> IsoPlot_contour_level_selection_type_list ("list");
static SimpleObjectMaker<LevelListSelectionTypeWrapper, LevelSelectionWrapper> IsoPlot_contour_level_selection_type_list_wrapper ("list");


#include "LevelListSelectionTypeWrapper.h"
static SimpleObjectMaker<LevelListSelectionType, LevelSelection> IsoPlot_contour_level_selection_type_level_list ("level_list");
static SimpleObjectMaker<LevelListSelectionTypeWrapper, LevelSelectionWrapper> IsoPlot_contour_level_selection_type_level_list_wrapper ("level_list");



#include "IsoLabelWrapper.h"
static SimpleObjectMaker<IsoLabel, NoIsoLabel> IsoPlot_contour_label_label ("label");
static SimpleObjectMaker<IsoLabelWrapper, NoIsoLabelWrapper> IsoPlot_contour_label_label_wrapper ("label");


#include "IsoLabelWrapper.h"
static SimpleObjectMaker<IsoLabel, NoIsoLabel> IsoPlot_contour_label_on ("on");
static SimpleObjectMaker<IsoLabelWrapper, NoIsoLabelWrapper> IsoPlot_contour_label_on_wrapper ("on");


#include "NoIsoLabelWrapper.h"

static SimpleObjectMaker<NoIsoLabelWrapper> IsoPlot_contour_label_nolabel_Wrapper("nolabel");


#include "NoIsoLabelWrapper.h"

static SimpleObjectMaker<NoIsoLabelWrapper> IsoPlot_contour_label_off_Wrapper("off");



#include "IsoShadingWrapper.h"
static SimpleObjectMaker<IsoShading, NoIsoShading> IsoPlot_contour_shade_shading ("shading");
static SimpleObjectMaker<IsoShadingWrapper, NoIsoShadingWrapper> IsoPlot_contour_shade_shading_wrapper ("shading");


#include "IsoShadingWrapper.h"
static SimpleObjectMaker<IsoShading, NoIsoShading> IsoPlot_contour_shade_on ("on");
static SimpleObjectMaker<IsoShadingWrapper, NoIsoShadingWrapper> IsoPlot_contour_shade_on_wrapper ("on");


#include "NoIsoShadingWrapper.h"

static SimpleObjectMaker<NoIsoShadingWrapper> IsoPlot_contour_shade_noshading_Wrapper("noshading");


#include "NoIsoShadingWrapper.h"

static SimpleObjectMaker<NoIsoShadingWrapper> IsoPlot_contour_shade_off_Wrapper("off");




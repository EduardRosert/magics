
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file FortranRootSceneNodeAttributes.h
    \\brief Definition of FortranRootSceneNode Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 2020-09-24
*/

#include "MagRequest.h" 
#include "FortranRootSceneNodeWrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"

using namespace magics;


FortranRootSceneNodeWrapper::FortranRootSceneNodeWrapper(): fortranrootscenenode_(new FortranRootSceneNode())

{

	
	
	
} 
FortranRootSceneNodeWrapper::FortranRootSceneNodeWrapper(FortranRootSceneNode* fortranrootscenenode): fortranrootscenenode_(fortranrootscenenode)
{
	
	
} 

FortranRootSceneNodeWrapper::~FortranRootSceneNodeWrapper()
{
	
}

void FortranRootSceneNodeWrapper::set(const MagRequest& request)
{
	
	

	if  (request.countValues("SUPER_PAGE_X_LENGTH") ) {
		double width_value = request("SUPER_PAGE_X_LENGTH");
		fortranrootscenenode_->width_ = width_value;
		}
	if  (request.countValues("SUPER_PAGE_Y_LENGTH") ) {
		double height_value = request("SUPER_PAGE_Y_LENGTH");
		fortranrootscenenode_->height_ = height_value;
		}
	if  (request.countValues("SUPER_PAGE_FRAME") ) {
		string frame_value = request("SUPER_PAGE_FRAME");
		fortranrootscenenode_->frame_ = MagTranslator<string, bool>()(frame_value);
		}
	if  (request.countValues("SUPER_PAGE_THEME") ) {
		string theme_value = request("SUPER_PAGE_THEME");
		fortranrootscenenode_->theme_ = theme_value;
		}
	if  (request.countValues("SUPER_PAGE_FRAME_THICKNESS") ) {
		int thickness_value = request("SUPER_PAGE_FRAME_THICKNESS");
		fortranrootscenenode_->thickness_ = thickness_value;
		}
	if  (request.countValues("LAYOUT") ) {
		string plot_layout_value = request("LAYOUT");
		fortranrootscenenode_->plot_layout_ = plot_layout_value;
		}
	if  (request.countValues("PLOT_START") ) {
		string plot_start_value = request("PLOT_START");
		fortranrootscenenode_->plot_start_ = plot_start_value;
		}
	if  (request.countValues("PLOT_DIRECTION") ) {
		string plot_direction_value = request("PLOT_DIRECTION");
		fortranrootscenenode_->plot_direction_ = plot_direction_value;
		}
	if  (request.countValues("LEGEND") ) {
		string legend_value = request("LEGEND");
		fortranrootscenenode_->legend_ = MagTranslator<string, bool>()(legend_value);
		}
	if  (request.countValues("MAGICS_SILENT") ) {
		string silent_value = request("MAGICS_SILENT");
		fortranrootscenenode_->silent_ = MagTranslator<string, bool>()(silent_value);
		}
	
	if  (request.countValues("SUPER_PAGE_FRAME_COLOUR") ) {
		string colour_value = request("SUPER_PAGE_FRAME_COLOUR");
		fortranrootscenenode_->colour_ = unique_ptr<Colour>(MagTranslator<string, Colour>()(colour_value));
	}
		
	
	if  (request.countValues("SUPER_PAGE_FRAME_LINE_STYLE") ) {
		string style_value = request("SUPER_PAGE_FRAME_LINE_STYLE");
		fortranrootscenenode_->style_ = MagTranslator<string, LineStyle>()(style_value);
	}
		
	
}

void FortranRootSceneNodeWrapper::print(ostream& out)  const
{
	out << "FortranRootSceneNodeWrapper[]";
}


    





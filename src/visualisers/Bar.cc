/******************************** LICENSE ********************************

 Copyright 2007 European Centre for Medium-Range Weather Forecasts (ECMWF)

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at 

    http://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.

 ******************************** LICENSE ********************************/

/*! \file Bar.cc
    \brief Implementation of the Template class Bar.
    
    Magics Team - ECMWF 2004
    
    Started: Wed 5-May-2004
    
    Changes:
    
*/



#include "Bar.h"
#include "PointsHandler.h"
#include "LegendVisitor.h"
#include "Flag.h"
#include "XmlNode.h"
using namespace magics;

Bar::Bar() 
{
	renderers_["bar"] = &Bar::fullbar;
	renderers_["linebar"] = &Bar::linebar;
}


Bar::~Bar() 
{}

/*!
 Class information are given to the output-stream.
*/		
void Bar::print(ostream& out)  const
{
	out << "Bar[";
	out << "]";
}
void Bar::set(const XmlNode& node) { 
		// Set the name to bar! 
		XmlNode bar = node;
        bar.name("bar");
    	BarAttributes::set(bar); 
		
		
    	Graph::set(node);
    }
void  Bar::visit(Transformation& transformation, Data&)
{
	if ( !annotation_.empty() )
		transformation.needTopAxis(true);
}

void Bar::operator()(Data& data, BasicGraphicsObjectContainer& out)
{
	vector<double> xpos;
	
	vector<double> ypos;
    
    const Transformation& transformation= out.transformation();
    double y = transformation.getMinY() + (transformation.getMaxY()-transformation.getMinY())*0.2;

	CustomisedPointsList points; 
	std::set<string> request;
	request.insert("bar");

	data.customisedPoints(out.transformation(), request, points, true);
	if (points.empty()) return;
	double previous =  (**points.begin())["x"];
	double next =  (**points.begin())["x"];
	double x, top, bottom, left, right;
	
	if (width_ == INT_MAX) {
		if ( points.size() > 1 ) 
			width_ = abs((*points[0])["x"] - (*points[1])["x"])*0.8;
		else 
			width_ = abs((*points[0])["x"] - (*points[1])["x"]);
			 
	}
	
	vector<string>::iterator annotation = annotation_.begin();
	
	for (CustomisedPointsList::const_iterator point = points.begin(); point != points.end(); ++point)
	{
		
		x = (**point)["x"];
		next = ((point+1) != points.end() ) ? (**(point+1))["x"] : x;
		bottom = (min_value_ == INT_MAX) ? (**point)["y_lower"]: min_value_;
		top = (**point)["y_upper"];
		
		map<string,  Renderer>::iterator renderer = renderers_.find(lowerCase(bar_style_) );

		if ( renderer != renderers_.end() ) {
			(this->*renderer->second)(x, top, bottom, out);
		}
		else {
			MagLog::warning() << "Coud not find the method " << bar_style_ << " to plot the bar\n"
					<< "      Revert to default : bar " << endl;
			fullbar(x, top, bottom, out);
		}
		

		

		PaperPoint xy(transformation.x(x), y);
		if ( annotation != annotation_.end() && transformation.in(xy) ) {
			Text* annot = new Text();
			MagFont font;
			font.colour(*annotation_colour_);
			font.size(annotation_size_);
			annot->setFont(font);
			annot->setText(*annotation);
			annot->setVerticalAlign(MBOTTOM);
			annot->push_back(xy);
			texts_.push_back(annot);
			annotation++;
		}
		

	}



}

void Bar::fullbar(double x, double top, double bottom, BasicGraphicsObjectContainer& out)
{
	const Transformation& transformation= out.transformation();
	double left = x - width_/2;
	double right = x + width_/2;
	if ( justification_ == MLEFT ) {
		left = x-width_;
		right = x;
	}
	if ( justification_ == MRIGHT ) {
			left = x;
			right = x+width_;
	}


	Polyline* box  = new Polyline();
	box->setColour(*line_colour_);

	box->setThickness(thickness_);
	box->setLineStyle(style_);

	box->push_back(transformation(UserPoint(left, bottom)));
	box->push_back(transformation(UserPoint(left, top)));
	box->push_back(transformation(UserPoint(right, top)));
	box->push_back(transformation(UserPoint(right, bottom)));
	box->push_back(transformation(UserPoint(left, bottom)));

	(*shade_)(*box);
	if (clipping_) {
		transformation(*box, out);
	}
	else
		out.push_back(box);

}

void Bar::linebar(double x, double top, double bottom, BasicGraphicsObjectContainer& out)
{
	const Transformation& transformation= out.transformation();
	double left = x - width_/2;
	double right = x + width_/2;

	Polyline* line  = new Polyline();
	line->setColour(*line_colour_);
	line->setThickness(thickness_);
	line->setLineStyle(style_);
	line->push_back(transformation(UserPoint(x, bottom)));
	line->push_back(transformation(UserPoint(x, top)));


	Polyline* topline = new Polyline();
	topline->setColour(*line_colour_);
	topline->setThickness(thickness_);
	topline->setLineStyle(style_);
	topline->push_back(transformation(UserPoint(left, top)));
	topline->push_back(transformation(UserPoint(right, top)));

	Polyline* bottomline = new Polyline();
	bottomline->setColour(*line_colour_);
	bottomline->setThickness(thickness_);
	bottomline->setLineStyle(style_);
	bottomline->push_back(transformation(UserPoint(left, bottom)));
	bottomline->push_back(transformation(UserPoint(right, bottom)));

	transformation(*line, out);
	transformation(*topline, out);
	transformation(*bottomline, out);
}

void Bar::visit(LegendVisitor& legend)
{
	if ( !legend_) return;
	if ( magCompare(bar_style_, "bar") ) {
		Polyline* curve  = new Polyline();
		curve->setColour(*colour_);
		curve->setLineStyle(style_);
		curve->setThickness(thickness_);
		curve->setFilled(true);
		shade_->legend(*curve);
		LegendEntry * entry = new BoxEntry(legend_text_, curve);
		entry->userText(legend_text_);
		legend.add(entry);
	}
	else if ( magCompare(bar_style_, "linebar") ) {
		Polyline* curve  = new Polyline();
		curve->setColour(*colour_);
		curve->setLineStyle(style_);
		curve->setThickness(thickness_);
		curve->setFilled(true);
		shade_->legend(*curve);
		LegendEntry * entry = new LineEntry(legend_text_, curve);
		entry->userText(legend_text_);
		legend.add(entry);
	}
}

GraphFlag::GraphFlag() 
{}


GraphFlag::~GraphFlag() 
{}

/*!
 Class information are given to the output-stream.
*/		

void GraphFlag::print(ostream& out)  const
{
	out << "GraphFlag[";
	out << "]";
}



void GraphFlag::operator()(Data& data, BasicGraphicsObjectContainer& out)
{
	const Transformation& transformation = out.transformation();
	CustomisedPointsList points; 
	std::set<string> request;
	request.insert("intensity");
	request.insert("direction");
	data.customisedPoints(transformation, request, points, true);
    
    if (points.empty() ) return;
	
	Flag* flags = new Flag();
	flags->setColour(*colour_); 
	flags->setLength(length_);
   
	flags->setOriginMarker("magics_15");
	flags->setOriginHeight(0.05);
	flags->setConvention(KNOTS);
	int i = 0;
	double x, y, missing;
	double intensity, direction;
    
	for (CustomisedPointsList::const_iterator point = points.begin(); point != points.end(); ++point) {
		i++;
       
		x = (**point)["x"];
		y = (**point)["y"];
		missing  = ((*point)->find("intensity") != (*point)->end()) ? (**point)["missing"] : -99999999;
        double lat = 10;
        if ( (*point)->find("latitude") != (*point)->end() )
            lat = (**point)["latitude"];
        flags->setHemisphere(lat >0 ? NORTH: SOUTH);
		if ( (*point)->find("intensity") != (*point)->end() && (*point)->find("direction") != (*point)->end() )   {
			intensity = (**point)["intensity"];
			direction = (**point)["direction"];
			if ( intensity == missing || direction == missing) 
				continue;	
			UserPoint pos(x, y);
			if ( transformation.in(pos) ) {
				flags->push_back(ArrowPoint(intensity, direction, transformation(pos)));
				flags->back().set(intensity, direction);
			}
		}
	}
	if ( !flags->empty() ) out.push_back(flags);	
	
	

}







void GraphFlag::visit(LegendVisitor& legend)
{
	if ( !legend_) return;
	Flag* flags = new Flag();
	flags->setColour(*colour_);
	flags->setLength(length_);

	flags->setOriginMarker("magics_15");
	flags->setOriginHeight(0.05);
	flags->setConvention(KNOTS);


	 LegendEntry * entry = new FlagEntry(legend_text_, flags);
	 legend.add(entry);

}
GraphArrow::GraphArrow() 
{}


GraphArrow::~GraphArrow() 
{}

/*!
 Class information are given to the output-stream.
*/		

void GraphArrow::print(ostream& out)  const
{
	out << "GraphArrow[";
	out << "]";
}



void GraphArrow::operator()(Data& data, BasicGraphicsObjectContainer& out)
{
	const Transformation& transformation = out.transformation();
	CustomisedPointsList points; 
	std::set<string> request;
	request.insert("intensity");
	request.insert("direction");
	data.customisedPoints(transformation, request, points, true);
	
	Arrow* arrow = new Arrow();
	arrow->setColour(*colour_); 
	
   
	arrow->setOriginMarker("magics_15");
	arrow->setOriginHeight(0.05);
	arrow->setScale(unit_velocity_);
	int i = 0;
	double x, y, missing;
	double intensity, direction;
	for (CustomisedPointsList::const_iterator point = points.begin(); point != points.end(); ++point) {
		i++;
       
		x = (**point)["x"];
		y = (**point)["y"];
		missing  = ((*point)->find("intensity") != (*point)->end()) ? (**point)["missing"] : -99999999;
        
		if ( (*point)->find("intensity") != (*point)->end() && (*point)->find("direction") != (*point)->end() )   {
			intensity = (**point)["intensity"];
			direction = (**point)["direction"];
			if ( intensity == missing || direction == missing) 
				continue;	
			UserPoint pos(x, y);
			if ( transformation.in(pos) ) {
				arrow->push_back(ArrowPoint(intensity, direction, transformation(pos)));
				arrow->back().set(intensity, direction);
			}
		}
	}
	if ( !arrow->empty() ) out.push_back(arrow);	
	
	

}




void Bar::visit(TopAxisVisitor& top)
{

	for ( vector<Text*>::iterator text = texts_.begin(); text != texts_.end(); ++text)
		top.push_back(*text);


}


void GraphArrow::visit(LegendVisitor& legend)
{
	if ( !legend_) return;
	Arrow* arrow = new Arrow();
	arrow->setColour(*colour_);


	arrow->setOriginMarker("magics_15");
	arrow->setOriginHeight(0.05);
	arrow->setScale(unit_velocity_);
	


	LegendEntry * entry = new ArrowEntry(legend_text_, arrow);

	 legend.add(entry);
}

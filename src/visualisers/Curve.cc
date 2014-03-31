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

/*! \file Curve.cc
    \brief Implementation of the Template class Curve.
    
    Magics Team - ECMWF 2004
    
    Started: Wed 5-May-2004
    
    Changes:
    
*/



#include "Curve.h"
#include "PointsHandler.h"
#include "LegendVisitor.h"
#include "Symbol.h"

using namespace magics;

Curve::Curve() 
{
	missingMethods_["ignore"] = &Curve::ignore;
	missingMethods_["join"] = &Curve::join;
	missingMethods_["drop"] = &Curve::drop;

	curveMethods_["straight"] = &Curve::straight;
	curveMethods_["stepped"] = &Curve::stepped;

}


Curve::~Curve() 
{}

/*!
 Class information are given to the output-stream.
*/		
void Curve::print(ostream& out)  const
{
	out << "Curve[";
	out << "]";
}

Polyline* Curve::newCurve(BasicGraphicsObjectContainer& task) const
{

	Polyline* curve  = new Polyline();
	(*curve).setColour(*colour_);
	(*curve).setLineStyle(style_);
	(*curve).setThickness(thickness_);

	return curve;
	
}
	
bool  Curve::missing(CustomisedPoint& point) const
{
	if ( point.missing() ) return true;
	double x = point["x"];

	if ( x < this->x_below_ ) return true;
	if ( x > this->x_above_ ) return true;
	if ( same(x, this->x_below_) ) return true;
	if ( same(x, this->x_above_) ) return true;

	double y = point["y"];

	if ( y < this->y_below_ ) return true;
	if ( y > this->y_above_ ) return true;
	if ( same(y, this->y_below_) ) return true;
	if ( same(y, this->y_above_) ) return true;
	return false;
}

void  Curve::stepped(const UserPoint& point, vector<UserPoint>& out)
{


}

void Curve::operator()(Data& data, BasicGraphicsObjectContainer& task)
{

	vector<double> xpos;
	vector<double> ypos;
    const Transformation& transformation = task.transformation();


    std::set<string> needs;
    CustomisedPointsList points;

    data.customisedPoints(transformation, needs, points, true);

	if ( legend_text_ == "?" ) legend_text_ = data.legend(); 
	
	
	Polyline* curve_ = newCurve(task);
	bool last_out = false;	
	
	vector<PaperPoint> missing, sv;
	PaperPoint last, current, toadd;
	
	CustomisedPointsList::iterator point = points.begin();

    while ( point != points.end() ) {
    	if ( this->missing(**point) ) {
    		++point;
    	}
    	else
    		break;
    }
    
    if ( point == points.end() )
    	return;

    PaperPoint last_current = transformation(UserPoint((**point)["x"], (**point)["y"]));

    while ( point != points.end() ) {

    	vector<UserPoint> todo;
    	UserPoint up((**point)["x"], (**point)["y"]);


    		current = transformation(up);
    		if (!this->missing(**point) ) {
    			if ( last_out ) {
    				bool result;
    				std::map<string, MissingMethod>::iterator method = missingMethods_.find(lowerCase(missing_mode_));
    				result = (method == missingMethods_.end() ) ?
    						ignore(last, missing.front(), missing, task) :
    						(this->*method->second)(last, current, missing, task);
    				if ( result ) {
    					if ( line_ )
    						transformation(*curve_, task);
    					curve_ = newCurve(task);
    				}
    				missing.clear();
    			}

    			if ( magCompare(plot_method_, "stepped" ) ) {
    				if ( current.x_ != last_current.x_ && current.y_ != last_current.y_ ) {
    					toadd = PaperPoint((current.x_ + last_current.x_)/2., last_current.y_);
    					curve_->push_back(toadd);
    					sv.push_back(toadd);
    					toadd = PaperPoint((current.x_ + last_current.x_)/2., current.y_);
    				}
                    else 
                        toadd = current;

    			}
    			else
    				toadd = current;

    			last = toadd;
    			last_current = current;

    			last_out = false;
    			curve_->push_back(toadd);
    			sv.push_back(toadd);

    		}
    		else {
    			missing.push_back( current );
    			last_out = true;
    		}

		++point;

	}
    // add the last current if stepped method ..
    if ( magCompare(plot_method_, "stepped" ) ) {
    	curve_->push_back(current);
    	sv.push_back(current);
    }

    if ( missing.empty() == false ) {
    	std::map<string, MissingMethod>::iterator method = missingMethods_.find(lowerCase(missing_mode_));
    	if ( method == missingMethods_.end() )
    	{
    		ignore(last, missing.front(), missing, task);
    	}
    	(this->*method->second)(last, missing.front(), missing, task);

    }

	
	
	// apply the symbol

	if ( line_ ) transformation(*curve_, task);
	 symbol(sv, task);

}

void CurveArea::operator()(Data& data, BasicGraphicsObjectContainer& task)
{

	vector<double> xpos;
	vector<double> ypos;
    const Transformation& transformation = task.transformation();


    std::set<string> needs;
    CustomisedPointsList points;
    if ( shade_->needCustomised() ) {
    	needs.insert("area");
    }
    data.customisedPoints(transformation, needs, points, true);

	if ( legend_text_ == "?" ) legend_text_ = data.legend();


	Polyline* curve_ = newCurve(task);
	bool last_out = false;

	vector<PaperPoint> missing, sv;
	PaperPoint last, current;

	CustomisedPointsList::iterator point = points.begin();

    while ( point != points.end() ) {

    	if ( this->missing(**point) ) {
    		++point;
    	}
    	else
    		break;
    }



    while ( point != points.end() ) {

    	UserPoint up((**point)["x"], (**point)["y"]);

    	current = transformation(up);

		if (!this->missing(**point) ) {
			if ( last_out ) {
				bool result;
				std::map<string, MissingMethod>::iterator method = missingMethods_.find(lowerCase(missing_mode_));
				result = (method == missingMethods_.end() ) ?
							ignore(last, missing.front(), missing, task) :
							(this->*method->second)(last, missing.front(), missing, task);
				if ( result ) {
					if ( line_ )
						transformation(*curve_, task);
					curve_ = newCurve(task);
				}
				missing.clear();
			}

			last = current;
			last_out = false;
			curve_->push_back(current);
			sv.push_back(current);

		}
		else {
			missing.push_back( current );
			last_out = true;
		}
		++point;

	}
    if ( missing.empty() == false ) {
    	std::map<string, MissingMethod>::iterator method = missingMethods_.find(lowerCase(missing_mode_));
    	if ( method == missingMethods_.end() )
    	{
    		ignore(last, missing.front(), missing, task);
    	}
    	(this->*method->second)(last, missing.front(), missing, task);

    }


	// apply the symbol

	(*shade_)(*curve_);
	if ( line_ ) transformation(*curve_, task);
	 symbol(sv, task);
	
}


class CurveEntry : public LegendEntry
{
public:
	CurveEntry(const string& legend, Curve& curve) : 
		LegendEntry(legend), curve_(curve) {}
	void set(const PaperPoint& point, BasicGraphicsObjectContainer& legend) 
		{ curve_.set(point, legend, *this); }
protected:
	Curve& curve_;
};

void Curve::visit(LegendVisitor& legend)
{
	if ( !legend_) return;
	CurveEntry* entry = new CurveEntry(legend_text_, *this);
	entry->userText(legend_text_);
	legend.add(entry);
}

void  Curve::set(const PaperPoint& point, BasicGraphicsObjectContainer& legend, LegendEntry& entry)
{
	Polyline* curve  = new Polyline();
	curve->setColour(*colour_);
	curve->setLineStyle(style_);
	curve->setThickness(thickness_);
	
	double width = entry.computeWidth(0.8)/2;

	PaperPoint p = entry.centreSymbolBox(point);

	
	double x = p.x();
	double y = point.y();

	curve->push_back(PaperPoint(x-width, y));
	curve->push_back(PaperPoint(x+width,  y));
	

	this->legend(*curve);
	
	    
	legend.push_back(curve);
	legend_symbol(p, legend);
	
}
void CurveArea::legend(Polyline& curve)
{
	shade_->legend(curve);
}
void Curve::symbol(vector<PaperPoint>& points, BasicGraphicsObjectContainer& out)
{
	if ( !symbol_ ) return;

	Symbol* symbol = new Symbol();

    symbol->setMarker(symbol_marker_);
    symbol->setHeight(symbol_height_);
    symbol->setColour(*symbol_colour_);
    symbol->outline(outline_, *outline_colour_, outline_thickness_, outline_style_);


	const Transformation& transformation = out.transformation();

    for ( vector<PaperPoint>::const_iterator point = points.begin(); point != points.end(); ++point) {
    	if ( !point->missing() && transformation.in(*point) )
    		symbol->push_back(transformation(*point));
    }

    out.push_back(symbol);
}

void Curve::legend_symbol(PaperPoint& point, BasicGraphicsObjectContainer& task)
{
	if ( !symbol_ ) return;

	Symbol* symbol = new Symbol();

    symbol->setMarker(symbol_marker_);
    symbol->setHeight(symbol_height_);
    symbol->setColour(*symbol_colour_);
    symbol->outline(outline_, *outline_colour_, outline_thickness_, outline_style_);
    symbol->push_back(point);

    task.push_back(symbol);
}


bool Curve::ignore(const PaperPoint&, const PaperPoint&, const vector<PaperPoint>&, BasicGraphicsObjectContainer&)
{
	return true; // need new line!
}

bool Curve::join(const PaperPoint& p1, const PaperPoint& p2, const vector<PaperPoint>& , BasicGraphicsObjectContainer& task)
{
	Polyline* curve  = new Polyline();
	(*curve).setColour(*missing_colour_);
	(*curve).setLineStyle(missing_style_);
	(*curve).setThickness(missing_thickness_);

	curve->push_back(p1);
	curve->push_back(p2);
	task.transformation()(*curve, task);
	return true;
}
bool Curve::drop(const PaperPoint& p1, const PaperPoint& p2, const vector<PaperPoint>& points, BasicGraphicsObjectContainer& task)
{
	Polyline* curve  = new Polyline();
	(*curve).setColour(*missing_colour_);
	(*curve).setLineStyle(missing_style_);
	(*curve).setThickness(missing_thickness_);

	curve->push_back(p1);
	for ( vector<PaperPoint>::const_iterator point = points.begin(); point != points.end(); ++point)
		curve->push_back(*point);
	curve->push_back(p2);
	task.transformation()(*curve, task);
	return true;
}

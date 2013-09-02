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

/*! \file Polyline.h
    \brief Definition of polyline graphics class.
    \author Meteorological Visualisation Section, ECMWF

    Started: Jan 2004

*/
#ifndef Polyline_H
#define Polyline_H

#include "magics.h"

#include "BasicGraphicsObject.h"
#include "BaseDriver.h"
#include "VectorOfPointers.h"
#include "Label.h"
#include "Arrow.h"
#include <boost/geometry/geometry.hpp>
#include <boost/geometry/geometries/polygon.hpp>
#include <boost/geometry/geometries/linestring.hpp>
#include <boost/geometry/geometries/register/point.hpp>
#include <boost/geometry/geometries/register/ring.hpp>
#include <boost/geometry/geometries/register/linestring.hpp>
#include <boost/geometry/core/tags.hpp>

BOOST_GEOMETRY_REGISTER_POINT_2D(magics::PaperPoint, double, boost::geometry::cs::cartesian, x_, y_)
BOOST_GEOMETRY_REGISTER_RING(deque<magics::PaperPoint>);
BOOST_GEOMETRY_REGISTER_LINESTRING(vector<magics::PaperPoint>);

namespace magics {

struct ShadingProperties
{
    ShadingProperties() 
    {}
    virtual ~ShadingProperties() {}
    virtual ShadingProperties* clone() = 0;
    virtual void draw(const BaseDriver& driver) const = 0;
   
    virtual void print(ostream& out) const
    {
       out << "ShadingProperties[";
       out << "]";
    }
    friend ostream& operator<<(ostream& s,const ShadingProperties& p)
		{ p.print(s); return s; }
};

struct FillShadingProperties : public ShadingProperties
{
    FillShadingProperties() {}
    ~FillShadingProperties() {}
    ShadingProperties* clone()
    {	
        FillShadingProperties* shading = new FillShadingProperties();
        return shading;
    }
    void draw(const BaseDriver& driver) const { driver.shade(*this); }
    void print(ostream& out) const
    {
       out << "FillShadingProperties[";
       out << "]";
   }
};


struct DotShadingProperties : public ShadingProperties
{
    DotShadingProperties() : angle_(45), size_(0.02), density_(25){}
    ~DotShadingProperties() {}
    void draw(const BaseDriver& driver) const { driver.shade(*this);}
    double angle_;
    double size_;
    double density_;
    ShadingProperties* clone()
    {
        DotShadingProperties* shading = new DotShadingProperties();

        shading->size_ = size_;
        shading->density_ = density_;
        return shading;
    }

    void print(ostream& out) const
    {
       out << "DotShadingProperties["   
           << ", angle=" << angle_
           << ", size=" << size_
           << ", density=" << density_
           << "]";
   }
};

struct HatchShadingProperties : public ShadingProperties 
{
    HatchShadingProperties() : index_(0), thickness_(1), density_(18) {}
    ~HatchShadingProperties() {}
    void draw(const BaseDriver& driver) const {driver.shade(*this);} 
    int index_;
    int thickness_;
    double density_;
    ShadingProperties* clone() {
        HatchShadingProperties* shading = new HatchShadingProperties();
        
        shading->index_ = index_;
        shading->thickness_ = thickness_;
        shading->density_ = density_;
        return shading;
    }
    void print(ostream& out) const {
       out << "HatchShadingProperties[";
       out << ", thickness=" << thickness_;
       out << ", index=" << index_;
       out << ", density=" << density_;
       out << "]";
   }
};


class PolylineProperties : public BasicGraphicsObject 
{
public :
	PolylineProperties() :  thickness_(1), dash_length_(10), style_(M_SOLID), fill_(false), shading_(0), arrow_(0), stroke_(true), antialiasing_(true) {}
	virtual ~PolylineProperties() { if (shading_) delete shading_;  if (arrow_) delete arrow_; }
	
	virtual void copy(const PolylineProperties& other)
	{			
		label_.copy(other.label_) ;
		colour_ = other.colour_;
		thickness_ 	 = other.thickness_;
		dash_length_ = other.dash_length_;	
		style_       = other.style_;
		fill_        = other.fill_;
		antialiasing_ = other.antialiasing_;
		fill_colour_ = other.fill_colour_;
		stroke_ = other.stroke_;
		if ( shading_ ) delete shading_;
		shading_     = other.shading_ ? other.shading_->clone() : 0;
		arrow_     = other.arrow_ ? other.arrow_->clone() : 0;
	}
	//! Method to set the thickness of a drawn line.
	void setThickness(int t){thickness_ = t;}
	//! Method to get the thickness of a drawn line.
	int getThickness() const {return thickness_;}

	//! Method to set the length of dashes in the line.
	void setDashLength(int dl){dash_length_ = dl;}
	//! Method to get the length of dashes in the line.
	int getDashLength() const {return dash_length_;}

	//! Method to set the style for the drawn line.
	void  setLineStyle(LineStyle ls){style_ = ls;}
	//! Method to get the style for the drawn line.
	LineStyle getLineStyle() const {return style_;}
	
	//! Method to set the colour for the drawn line.
	void  setColour(const Colour& colour){colour_ = colour;}
	//! Method to get the colour for the drawn line.
	const Colour& getColour() const {return colour_;}
	
	//! Method to set filling.
	void  setFilled(bool fill){fill_ = fill;}
	//! Method to get the style for the drawn line.
	bool isFilled() const {return fill_;}
	
	void setFillColour(Colour col){  fill_colour_ = col;}
	Colour getFillColour() const {return fill_colour_;}
	
	void setLabel(const Label& label){  label_ = label;}
	const Label& getLabel() const {return label_;}
	void setAntiAliasing(bool antialiasing){ antialiasing_ = antialiasing; }
	bool getAntiAliasing() const {return antialiasing_;}
	
	void setStroke(bool stroke){ stroke_ = stroke; }
	bool isStroked() const {return stroke_;}

	void setShading(ShadingProperties* shading)
	{ 
		if ( shading_) delete shading_; 
		shading_ = shading; 
	}
	void setArrow(ArrowProperties* arrow)
	{
		if ( arrow_) delete arrow_;
		arrow_ = arrow;
	}

	ArrowProperties* arrowProperties() const { return arrow_; }
	ShadingProperties* getShading() const { return shading_; }

protected:
	int			thickness_;
	int			dash_length_;	
	LineStyle		style_;
	bool			fill_;
	Colour			fill_colour_;
	ShadingProperties*	shading_; 
	Label                   label_;
	ArrowProperties*        arrow_;
	Colour                  colour_;
	bool                    stroke_;
	bool                    antialiasing_;
};


using namespace magics;


class Polyline:

	public PolylineProperties
{
public:
	typedef boost::geometry::model::polygon<PaperPoint, true, true, deque, deque > BoostPoly;
	typedef boost::geometry::model::linestring<PaperPoint, deque > BoostLine;
	typedef BoostPoly::inner_container_type Holes;
	typedef deque<PaperPoint> MagLine;
	Polyline();
	~Polyline();
	
	void reproject(const Transformation&);
	bool reproject(BasicGraphicsObjectContainer& out) const;
	void redisplay(const BaseDriver& driver) const;

	Colour cellColour_;
	double cellValue_;
	int index_;

	const Colour& cellColour() const { return cellColour_; }
	double cellValue() const { return cellValue_; }

	int index() const { return index_; }
	void index(int index)  { index_ = index; }

	void cellColour(const Colour& colour ) { cellColour_ = colour; }
	void cellValue(double value ) { cellValue_ = value; }
	void cellInfo(const Colour& colour, double value) { cellColour_ = colour; cellValue_ = value; }

	bool concatenate(Polyline&);
	void intersection(Polyline&);
	Polyline*  clone() const;
	void push_back(const PaperPoint& point)
	{	
		if ( empty() ) {
			polygon_.outer().push_back(point);
			return;
		}
		PaperPoint last = back();
		if ( point.x_ !=  last.x_ ||  point.y_ !=  last.y_)
			polygon_.outer().push_back(point);
	}
	void push_back(double x, double y)
	{
		polygon_.outer().push_back(PaperPoint(x, y));
	} 
	void box(const PaperPoint&, const PaperPoint&);
	bool empty() const {
		return polygon_.outer().empty();
	}
	bool closed() const { return polygon_.outer().front() == polygon_.outer().back(); }
	MagLine::const_iterator end() const { return polygon_.outer().end(); }
	MagLine::const_iterator begin() const { return polygon_.outer().begin(); }
	unsigned int size() const { return polygon_.outer().size(); }
	const PaperPoint& get(int i) const { return polygon_.outer()[i]; }
	const PaperPoint& front() const { return polygon_.outer().front(); }
	const PaperPoint& back() const { return polygon_.outer().back(); }
	void push_front(const PaperPoint& point)
	{	
		polygon_.outer().push_front(point);
	} 
	
	void push_front(Polyline&);
	void push_back(Polyline&);


	// Is the poyline included in the "other" polyline"
	bool in(const Polyline& other);

	// Is the pointincluded in the polyline"
	bool in(const PaperPoint&);

	bool sanityCheck();
	void correct();

	void reserve(double);

	/*!
	  Counts checks if a given point is in the Polyline
	  This method can be used to see if a point at x_in and y_in
	  lies inside a CLOSED Polyline. If counts is odd the point
	  should lie inside.
	*/
	bool inside(const float x_in,const float y_in) const;


	bool allMissing() const
	{		
	    deque<PaperPoint>::const_iterator p = polygon_.outer().begin();
	    while (p != polygon_.outer().end() )
	    {
	    	if ( !p->missing() ) 
	    		return false;
	    	p++;
	    }
	    return true;
	}
	    	
	bool someMissing() const
	{
		deque<PaperPoint>::const_iterator p = polygon_.outer().begin();
	    while (p != polygon_.outer().end() )
	    {
	    	if ( p->missing() ) 
	    		return true;
	    	p++;
	    }
	    return false;
	}		 


	bool within(const PaperPoint& point) const {
		return boost::geometry::covered_by(point, polygon_);
	}

	void clip(const Polyline& poly, vector<Polyline>&) const;
	void intersect(const Polyline& poly, vector<Polyline>&) const;

	Polyline* simplify(double);
	Polyline* getNew() const;


	// Holes
	void newHole(const Polyline&);
	void newHole();
	void push_back_hole(const PaperPoint& point);


	void hole(Holes::const_iterator, Polyline&) const;
	Holes::const_iterator beginHoles() const;
	Holes::const_iterator endHoles() const;

	void hole(Holes::const_iterator, vector<double>&, vector<double>&) const;
	unsigned int numberOfHoles() const {return polygon_.inners().size();}
	void  clearHoles()  { polygon_.inners().clear();}
	void  clear()  { polygon_.clear();}
	Holes& holes();

protected:
	void print(ostream&) const;



public:



	BoostPoly polygon_;


private: 
	//Polyline(const Polyline&);
//
// -- Friends
	friend ostream& operator<<(ostream& s,const Polyline& p)
		{ p.print(s); return s; }
};


class PolylineSet : public BasicGraphicsObjectContainer
	{
	public:
	    PolylineSet() {}
	    ~PolylineSet() { }

	    void redisplay(const BaseDriver& driver) const
	        { driver.redisplay(*this); }
	protected:
	    void print(ostream& out) const { out << "PolylineSet[ " << objects_.size() << " elts]\n" << endl; }

	private:
	    PolylineSet(const Polyline&);
	    PolylineSet& operator=(const PolylineSet&);

	// -- Friends
	    friend ostream& operator<<(ostream& s,const PolylineSet& p)
	        { p.print(s); return s; }
	};



} // namespace magics




#endif

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

/*! \file AxisItem.h
    \brief Definition of the Template class AxisItem.
    
    Magics Team - ECMWF 2005
    
    Started: Tue 11-Oct-2005
    
    Changes:
    
*/

#ifndef AxisItem_H
#define AxisItem_H

#include "magics.h"
#include "VectorOfPointers.h"
#include "DateTime.h"



namespace magics {

class Axis;
class MagFont;

class AxisItem 
{

public:
	AxisItem(double position, const string label, int level = 0);
	AxisItem(double position, const string label, int level, const string& colour, double height);
	AxisItem(double x);
	virtual ~AxisItem();
	virtual AxisItem* clone() const { 
		AxisItem* item = new AxisItem(position_, label_, level_, colour_, height_); 
		return item;
		}
	virtual const string& id() const { return label_; }

	virtual void format(const string&, int) const     {}
	
	virtual bool sunday() const { return false; }

	virtual bool date() const { return false; }
	
	virtual bool isFirst() { return false; } 
	virtual bool isLast() { return false; } 
	
	double  position() const { return position_; }
	void    position(double position) { position_ = position; }

	const string& label() const { return label_; }
	const string& colour() const { return colour_; } 
	void  colour(const string& colour)   { colour_ = colour; } 
	void  resetColour() const { colour_ = "undef"; }
	double height() const                { return height_; }
	void   height(double height, const string& font, const string& style) const
		{ height_ = height; font_ = font; style_ = style; }
	void   label(const string& label) { label_ = label; }

	void setFont(MagFont& font);
	
	int         level()  { return level_; }
	void           level(int level)  { level_ = level;  }
	virtual void id(const string&) {}
	
	virtual bool isTick() const { return true; }
	virtual bool isLabel() const { return true; }
	virtual bool isGrid() const { return true; }
	virtual bool isMinorTick() const { return false; }
protected:
     //! Method to print string about this class on to a stream of type ostream (virtual).
	 virtual void print(ostream&) const; 
     double   position_;
     mutable string  label_;
     int  level_;
     mutable string  colour_;
     mutable double  height_;
     mutable string font_;
     mutable string style_;
private:
    //! Copy constructor - No copy allowed
	AxisItem(const AxisItem&);
    //! Overloaded << operator to copy - No copy allowed
	AxisItem& operator=(const AxisItem&);

// -- Friends
    //! Overloaded << operator to call print().
	friend ostream& operator<<(ostream& s,const AxisItem& p)
		{ p.print(s); return s; }

};


class AxisHyperItem : public AxisItem
{
public:
	AxisHyperItem(double, vector<double>&);
	~AxisHyperItem();
};

class AxisTickItem : public AxisItem
{
public:
	AxisTickItem(double pos) : AxisItem(pos) { label_ = ""; }
	~AxisTickItem() {}
	bool isLabel() const { return false; }

};

class AxisDateItem : public AxisItem
{
public:
	AxisDateItem(double position, DateTime date, int level = 0, const string& colour ="undef", double height = 0.3 );
	~AxisDateItem() {}
	AxisItem* clone() const {
		AxisDateItem* item = new AxisDateItem(position_, date_, level_, colour_, height_);
		return item; 
	}
	const string& id () const { return id_; }
	void format(const string&, int) const;
	
	string label(const Axis&) const  { return label_; }

	bool sunday() const;
	
	bool date() const { return true; }
	void id(const string& id) {id_ = id; }
	
	bool isTick() const   { return false; }
	bool isGrid() const   { return false; }

protected:
	DateTime date_;
	mutable string defaultColour_;
	mutable string id_;
	
};

class AxisMinorTickItem : public AxisItem
{
public:
	AxisMinorTickItem(double pos) : AxisItem(pos) { label_ = ""; }
	~AxisMinorTickItem() {}
	bool isTick() const   { return false; }
	bool isLabel() const { return false; }
	bool isGrid() const { return false; }
	bool isMinorTick() const { return true; }
};


typedef VectorOfPointers<vector<AxisItem*> > AxisItems;


} // namespace magics
#endif

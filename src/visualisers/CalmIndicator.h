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

/*! \file CalmIndicator.h
    \brief Definition of the Template class CalmIndicator.
    
    Magics Team - ECMWF 2005
    
    Started: Thu 17-Mar-2005
    
    Changes:
    
*/

#ifndef CalmIndicator_H
#define CalmIndicator_H

#include "magics.h"
#include "MagTranslator.h"
#include "Factory.h"
#include "Symbol.h"


namespace magics {
	

class CalmIndicator {
public:
	CalmIndicator() { marker_ = 1; }
	virtual ~CalmIndicator() {}
	virtual void set(const map<string, string>&) {}
	virtual void set(const XmlNode&) {}
	virtual bool accept(const string& node) { return magCompare(node, "calm"); }
	virtual void toxml(ostream&) {}
	virtual CalmIndicator* clone() { return new CalmIndicator(); }
	void colour(const Colour& colour) { colour_ = colour; }
	void marker(double marker)      { marker_ = marker; }
	void height(double height)      { height_ = height; }
	void below(double below)        { below_  = below * below; }
	
	
	virtual void prepare(BasicGraphicsObjectContainer& task) {
		calm_ = new Symbol();
		calm_->setColour(colour_);
	    calm_->setMarker(marker_);
	    calm_->setHeight(height_);
	    task.push_back(calm_);
	    
	    dot_ = new Symbol();
		dot_->setColour(colour_);
	    dot_->setMarker(15);
	    dot_->setHeight(0.1);
		task.push_back(dot_);	
	}
		
	
	virtual bool operator()(const PaperPoint& point, double x, double y)
	{
		if ( ((x*x) + (y*y)) < below_ ) {
			calm_->push_back(point);
			dot_->push_back(point);
			return true;
		}
		return false; 
	}
	

protected:
     //! Method to print string about this class on to a stream of type ostream (virtual).
	 virtual void print(ostream& out) const { out << "CalmIndicator"; } 
	 Symbol* calm_;
	 Symbol* dot_;
	 Colour     colour_;
	 int     marker_;
	 double   height_;
	 double   below_;
	 
private:
    //! Copy constructor - No copy allowed
	CalmIndicator(const CalmIndicator&);
    //! Overloaded << operator to copy - No copy allowed
	CalmIndicator& operator=(const CalmIndicator&);

// -- Friends
    //! Overloaded << operator to call print().
	friend ostream& operator<<(ostream& s,const CalmIndicator& p)
		{ p.print(s); return s; }

};



class NoCalmIndicator : public CalmIndicator
{
public:
	NoCalmIndicator()  {}
	~NoCalmIndicator() {}
	virtual CalmIndicator* clone() { return new NoCalmIndicator(); }
	virtual bool accept(const string& node) { return magCompare(node, "nocalm"); }

	
	void prepare(BasicGraphicsObjectContainer&) {}
	virtual bool operator()(const PaperPoint&, double x, double y)
	{
	    return (((x*x) + (y*y)) < this->below_ ) ? true : false;
	}
	
	
};

template <>
class MagTranslator<string, CalmIndicator> { 
public:
	CalmIndicator* operator()(const string& val ) {
		 return SimpleObjectMaker<CalmIndicator >::create(val);
	}     
    CalmIndicator* magics(const string& param)
    {
        CalmIndicator* object=0;
		ParameterManager::update(param, object);
		return object;
    }

};
} // namespace magics
#endif

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

/*! \file ViewNode.h
    \brief Definition of the Template class ViewNode.
    
    Magics Team - ECMWF 2007
    
    Started: Tue 6-Mar-2007
    
    Changes:
    
*/

#ifndef ViewNode_H
#define ViewNode_H

#include "magics.h"
#include "BasicSceneObject.h"
#include "FortranViewNodeAttributes.h"
#include "XmlBasicNodeAttributes.h"
#include "XmlViewNodeAttributes.h"
#include "XmlNode.h"
#include "Layout.h"


namespace magics {

class Transformation;
class AnimationRules;

class ViewNode: public BasicSceneNode {

public:
	ViewNode();
	virtual ~ViewNode();
	void setInteractiveInfo(const string& id, int levels, int level) {
		name(id);
		ASSERT(layout_);
		layout_->id(id);
		id_ = id;
		zoomLevels_ = levels;
		zoomCurrentLevel_ = level;
		layout_->zoomLevels(levels);
		layout_->zoomCurrentLevel(level)	;
	}
	
	virtual void text(TextVisitor* text);
	virtual void legend(LegendVisitor* legend);
	
	
	
	
	
	void visit(MetaDataCollector&);


protected:
     //! Method to print string about this class on to a stream of type ostream (virtual).
	 void print(ostream&) const; 
	 void prepareLayout(SceneLayer&);
	 virtual void updateLayout() {}
	
	 void getReady();
	 
	 void visit(SceneLayer&);	
	 void visit(MetaDataVisitor&);
	 void visit(PreviewVisitor&);
	 void visit(HistoVisitor&);
	
	 virtual void copy(const ViewNode&);

	 Transformation& transformation() const { ASSERT(viewTransformation_); return *viewTransformation_; }
	 
	 Transformation* viewTransformation_;
	 
	 // The margin are used to position the drawing area, inside the node! 
	 double drawing_top_; //In automatic mode : The top should always be greater that 15% to allow a space for the automatic title, and automatic legend!
	 double drawing_bottom_;
	 double drawing_left_;
	 double drawing_right_;
	 string animation_; 
	 
	 DrawingVisitor* 		drawing_;
	 DrawingVisitor* 		frameHelper_;
	 TopAxisVisitor*    	topAxis_;
	 BottomAxisVisitor*     bottomAxis_;
	 LeftAxisVisitor*    	leftAxis_;
	 RightAxisVisitor*    	rightAxis_;
	 double                 vaxis_;
	 double                 haxis_;

	 AnimationRules*        rules_;

	 LegendVisitor* 		legend_;
	 vector<TextVisitor*>   texts_;
	 vector<LayoutVisitor*> components_;
	
	
	 // Infomation about the zoom! 
	 string id_;
	 int zoomLevels_;
	 int zoomCurrentLevel_;
	

private:
	 //! Overloaded << operator to copy - No copy allowed
   ViewNode(const ViewNode&);
    //! Overloaded << operator to copy - No copy allowed
	ViewNode& operator=(const ViewNode&);

// -- Friends
    //! Overloaded << operator to call print().
	friend ostream& operator<<(ostream& s,const ViewNode& p)
		{ p.print(s); return s; }
	
};

class FortranViewNode : public ViewNode, public FortranViewNodeAttributes
{
public: 
	FortranViewNode();
	~FortranViewNode();
    
	BasicSceneNode* clone();
	
	void getReady();


protected:
	void print(ostream&) const;
	
	
};

class XmlViewNode : public ViewNode, public XmlBasicNodeAttributes, public XmlViewNodeAttributes
{
public: 
	XmlViewNode();
	~XmlViewNode();
	void set(const XmlNode& node) {
		if ( magCompare(node.name(), "map" ) ) {
			XmlNode view = node;
		    view.name("view");
			XmlBasicNodeAttributes::set(view);
		}
		XmlViewNodeAttributes::set(node);
	}

	
	void updateLayout();
	void getReady();
protected:
	void print(ostream&) const;
};





} // namespace magics
#endif

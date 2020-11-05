
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file ImportPlotAttributes.h
    \\brief Definition of ImportPlot Attributes class.

    This file is automatically generated.
    Do Not Edit!

    Generated: 2020-10-14
*/

#include "ImportPlotAttributes.h"
#include "MagicsParameter.h"
#include "ParameterSettings.h"

using namespace magics;

ImportPlotAttributes::ImportPlotAttributes():
	format_(ParameterManager::getString("import_format")),
	system_(ParameterManager::getString("import_system_coordinates")),
	x_(ParameterManager::getDouble("import_x_position")),
	y_(ParameterManager::getDouble("import_y_position")),
	width_(ParameterManager::getDouble("import_width")),
	crs_(ParameterManager::getString("crs")),
	crs_minx_(ParameterManager::getDouble("crs_minx")),
	crs_maxx_(ParameterManager::getDouble("crs_maxx")),
	crs_miny_(ParameterManager::getDouble("crs_miny")),
	crs_maxy_(ParameterManager::getDouble("crs_maxy")),
	height_(ParameterManager::getDouble("import_height"))
	
	 
{
} 


ImportPlotAttributes::~ImportPlotAttributes()
{
	
}

    
void ImportPlotAttributes::set(const std::map<string, string>& params)
{
	vector<string> prefix(1);
	int i = 0;
	prefix[i++] = "";
	
	setAttribute(prefix, "import_format", format_, params);
	setAttribute(prefix, "import_system_coordinates", system_, params);
	setAttribute(prefix, "import_x_position", x_, params);
	setAttribute(prefix, "import_y_position", y_, params);
	setAttribute(prefix, "import_width", width_, params);
	setAttribute(prefix, "crs", crs_, params);
	setAttribute(prefix, "crs_minx", crs_minx_, params);
	setAttribute(prefix, "crs_maxx", crs_maxx_, params);
	setAttribute(prefix, "crs_miny", crs_miny_, params);
	setAttribute(prefix, "crs_maxy", crs_maxy_, params);
	setAttribute(prefix, "import_height", height_, params);
	
	
}

void ImportPlotAttributes::copy(const ImportPlotAttributes& other)
{
	format_ = other.format_;
	system_ = other.system_;
	x_ = other.x_;
	y_ = other.y_;
	width_ = other.width_;
	crs_ = other.crs_;
	crs_minx_ = other.crs_minx_;
	crs_maxx_ = other.crs_maxx_;
	crs_miny_ = other.crs_miny_;
	crs_maxy_ = other.crs_maxy_;
	height_ = other.height_;
	
} 


bool ImportPlotAttributes::accept(const string& node)
{	
	
	if ( magCompare(node, "")  )
		return true;
	
	return false;
}

void ImportPlotAttributes::set(const XmlNode& node)
{
	bool apply = false;

	if ( this->accept(node.name()) == false ) 
		return;

	if ( magCompare(node.name(), "")  )
		apply = true;
	

	if ( apply )
		set(node.attributes());
	else {
		
	}
	for (auto &elt : node.elements())
	{
		
	}
}

void ImportPlotAttributes::print(ostream& out)  const
{
	out << "Attributes[";
	out << " format = " <<  format_;
	out << " system = " <<  system_;
	out << " x = " <<  x_;
	out << " y = " <<  y_;
	out << " width = " <<  width_;
	out << " crs = " <<  crs_;
	out << " crs_minx = " <<  crs_minx_;
	out << " crs_maxx = " <<  crs_maxx_;
	out << " crs_miny = " <<  crs_miny_;
	out << " crs_maxy = " <<  crs_maxy_;
	out << " height = " <<  height_;
	
	out << "]" << "\n";
}

void ImportPlotAttributes::toxml(ostream& out)  const
{
	out <<  "\"\""; 
	out << ", \"import_format\":";
	niceprint(out,format_);
	out << ", \"import_system_coordinates\":";
	niceprint(out,system_);
	out << ", \"import_x_position\":";
	niceprint(out,x_);
	out << ", \"import_y_position\":";
	niceprint(out,y_);
	out << ", \"import_width\":";
	niceprint(out,width_);
	out << ", \"crs\":";
	niceprint(out,crs_);
	out << ", \"crs_minx\":";
	niceprint(out,crs_minx_);
	out << ", \"crs_maxx\":";
	niceprint(out,crs_maxx_);
	out << ", \"crs_miny\":";
	niceprint(out,crs_miny_);
	out << ", \"crs_maxy\":";
	niceprint(out,crs_maxy_);
	out << ", \"import_height\":";
	niceprint(out,height_);
	
}

static MagicsParameter<string> import_format("import_format", "PNG", "");
static MagicsParameter<string> import_system_coordinates("import_system_coordinates", "user", "");
static MagicsParameter<double> import_x_position("import_x_position", 0, "");
static MagicsParameter<double> import_y_position("import_y_position", 0, "");
static MagicsParameter<double> import_width("import_width", -1, "");
static MagicsParameter<string> crs("crs", "", "");
static MagicsParameter<double> crs_minx("crs_minx", -180., "");
static MagicsParameter<double> crs_maxx("crs_maxx", 180., "");
static MagicsParameter<double> crs_miny("crs_miny", -90., "");
static MagicsParameter<double> crs_maxy("crs_maxy", -90., "");
static MagicsParameter<double> import_height("import_height", -1, "");

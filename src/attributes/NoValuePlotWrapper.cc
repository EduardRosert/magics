
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file NoValuePlotAttributes.h
    \\brief Definition of NoValuePlot Attributes class.

    This file is automatically generated.
    Do Not Edit!

*/

#include "MagRequest.h"
#include "NoValuePlotWrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"
#include "MagicsSettings.h"

using namespace magics;


NoValuePlotWrapper::NoValuePlotWrapper(): novalueplot_(new NoValuePlot())

{


	
	ValuePlotBaseWrapper::object(novalueplot_);
	

}
NoValuePlotWrapper::NoValuePlotWrapper(NoValuePlot* novalueplot): novalueplot_(novalueplot)
{

	
	ValuePlotBaseWrapper::object(novalueplot_);
	
}

NoValuePlotWrapper::~NoValuePlotWrapper()
{

}

void NoValuePlotWrapper::set(const MagRequest& request)
{

	

	ValuePlotBaseWrapper::set(request);
	

	
	
}

void NoValuePlotWrapper::print(ostream& out)  const
{
	out << "NoValuePlotWrapper[]";
}



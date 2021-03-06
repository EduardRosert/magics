
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file ImageListColourTechniqueAttributes.h
    \\brief Definition of ImageListColourTechnique Attributes class.

    This file is automatically generated.
    Do Not Edit!

*/

#include "MagRequest.h"
#include "ImageListColourTechniqueWrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"
#include "MagicsGlobal.h"

using namespace magics;



ImageListColourTechniqueWrapper::ImageListColourTechniqueWrapper(): imagelistcolourtechnique_(new ImageListColourTechnique())


{


	

}
ImageListColourTechniqueWrapper::ImageListColourTechniqueWrapper(ImageListColourTechnique* imagelistcolourtechnique): imagelistcolourtechnique_(imagelistcolourtechnique)
{

	
}

ImageListColourTechniqueWrapper::~ImageListColourTechniqueWrapper()
{

}

void ImageListColourTechniqueWrapper::set(const MagRequest& request)
{

	

	stringarray  values_value;
	for (int i = 0; i < request.countValues("IMAGE_COLOUR_TABLE"); i++)
		values_value.push_back((string)request("IMAGE_COLOUR_TABLE", i));
	if ( !values_value.empty() )
		imagelistcolourtechnique_->values_ = values_value;
	
	
}

void ImageListColourTechniqueWrapper::print(ostream& out)  const
{
	out << "ImageListColourTechniqueWrapper[]";
}



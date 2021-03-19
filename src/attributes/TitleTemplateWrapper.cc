
/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file TitleTemplateAttributes.h
    \\brief Definition of TitleTemplate Attributes class.

    This file is automatically generated.
    Do Not Edit!

*/

#include "MagRequest.h"
#include "TitleTemplateWrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"
#include "MagicsSettings.h"

using namespace magics;


TitleTemplateWrapper::TitleTemplateWrapper(): titletemplate_(new TitleTemplate())

{


	

}
TitleTemplateWrapper::TitleTemplateWrapper(TitleTemplate* titletemplate): titletemplate_(titletemplate)
{

	
}

TitleTemplateWrapper::~TitleTemplateWrapper()
{

}

void TitleTemplateWrapper::set(const MagRequest& request)
{

	

	if  (request.countValues("TITLE_TEMPLATE_FILENAME") ) {
		string file_value = request("TITLE_TEMPLATE_FILENAME");
		titletemplate_->file_ = file_value;
		}
	
	
}

void TitleTemplateWrapper::print(ostream& out)  const
{
	out << "TitleTemplateWrapper[]";
}




/******************************  LICENSE  *******************************

 * (C) Copyright 1996-2017 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.

 *******************************  LICENSE  *******************************/

/*! \\file ImportObjectHandlerAttributes.h
    \\brief Definition of ImportObjectHandler Attributes class.

    This file is automatically generated.
    Do Not Edit!
*/

#include "MagRequest.h" 
#include "ImportObjectHandlerWrapper.h"
#include "MagicsParameter.h"
#include "Factory.h"
#include "MagTranslator.h"

using namespace magics;


ImportObjectHandlerWrapper::ImportObjectHandlerWrapper(): importobjecthandler_(new ImportObjectHandler())

{

	
	
	
} 
ImportObjectHandlerWrapper::ImportObjectHandlerWrapper(ImportObjectHandler* importobjecthandler): importobjecthandler_(importobjecthandler)
{
	
	
} 

ImportObjectHandlerWrapper::~ImportObjectHandlerWrapper()
{
	
}

void ImportObjectHandlerWrapper::set(const MagRequest& request)
{
	
	

	if  (request.countValues("IMPORT_FILE_NAME") ) {
		string path_value = request("IMPORT_FILE_NAME");
		importobjecthandler_->path_ = path_value;
		}
	if  (request.countValues("IMPORT_FORMAT") ) {
		string format_value = request("IMPORT_FORMAT");
		importobjecthandler_->format_ = format_value;
		}
	if  (request.countValues("IMPORT_OVERLAY") ) {
		string overlay_value = request("IMPORT_OVERLAY");
		importobjecthandler_->overlay_ = MagTranslator<string, bool>()(overlay_value);
		}
	if  (request.countValues("IMPORT_X_POSITION") ) {
		double import_x_value = request("IMPORT_X_POSITION");
		importobjecthandler_->import_x_ = import_x_value;
		}
	if  (request.countValues("IMPORT_Y_POSITION") ) {
		double import_y_value = request("IMPORT_Y_POSITION");
		importobjecthandler_->import_y_ = import_y_value;
		}
	if  (request.countValues("IMPORT_WIDTH") ) {
		double import_width_value = request("IMPORT_WIDTH");
		importobjecthandler_->import_width_ = import_width_value;
		}
	if  (request.countValues("IMPORT_HEIGHT") ) {
		double import_height_value = request("IMPORT_HEIGHT");
		importobjecthandler_->import_height_ = import_height_value;
		}
	
	
}

void ImportObjectHandlerWrapper::print(ostream& out)  const
{
	out << "ImportObjectHandlerWrapper[]";
}


    




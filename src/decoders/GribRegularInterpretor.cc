/*
 * (C) Copyright 1996-2016 ECMWF.
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 * In applying this licence, ECMWF does not waive the privileges and immunities 
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.
 */

/*! \file GribRegularInterpretor.cc
 \brief Implementation of the Template class GribRegularInterpretor.
 \author Meteorological Visualisation Section, ECMWF

 Started: Mon 18-Apr-2005

 Changes:
 */

#include <limits>

#include "CustomisedPoint.h"
#include "GribRegularInterpretor.h"
#include "GribDecoder.h"
#include "Matrix.h"
#include "LocalTable.h"
#include "RasterData.h"
#include "Timer.h"

using namespace magics;

GribRegularInterpretor::GribRegularInterpretor() {
}

GribRegularInterpretor::~GribRegularInterpretor() {
}

void GribInterpretor::longitudesSanityCheck(double& west, double& east) const {
    // make sure that the west longitudes is always inferior to teh East longitudes and always
    // betwwen -180 and 360...

    while (east <= west) {
        // We add 360 to the east ...
        east += 360;
    }

    // We reposition if needed

    while (east > 360) {
        west -= 360.;
        east -= 360.;
    }
}
void GribInterpretor::scaling(const GribDecoder& grib, double& scaling,
        double& offset) const {
    string originalUnits, derivedUnits;
   this->scaling(grib, scaling, offset, originalUnits, derivedUnits);
}

/// @brief The usual PI/180 constant
//static const double DEG_TO_RAD = 0.017453292519943295769236907684886;
/// @brief Earth's quatratic mean radius for WGS-84
static const double EARTH_RADIUS_IN_METERS = 6372797.560856;

/** @brief Computes the arc, in radian, between two WGS-84 positions.
  *
  * The result is equal to <code>Distance(from,to)/EARTH_RADIUS_IN_METERS</code>
  *    <code>= 2*asin(sqrt(h(d/EARTH_RADIUS_IN_METERS )))</code>
  *
  * where:<ul>
  *    <li>d is the distance in meters between 'from' and 'to' positions.</li>
  *    <li>h is the haversine function: <code>h(x)=sin²(x/2)</code></li>
  * </ul>
  *
  * The haversine formula gives:
  *    <code>h(d/R) = h(from.lat-to.lat)+h(from.lon-to.lon)+cos(from.lat)*cos(to.lat)</code>
  *
  * @sa http://en.wikipedia.org/wiki/Law_of_haversines
  */
double distance(double lat1, double lon1, double lat2, double lon2) {
    double latitudeArc  = (lat1 - lat2) * DEG_TO_RAD;
    double longitudeArc = (lon1 - lon2) * DEG_TO_RAD;
    double latitudeH = sin(latitudeArc * 0.5);
    latitudeH *= latitudeH;
    double lontitudeH = sin(longitudeArc * 0.5);
    lontitudeH *= lontitudeH;
    double tmp = cos(lat1*DEG_TO_RAD) * cos(lat2*DEG_TO_RAD);
    return EARTH_RADIUS_IN_METERS* (2.0 * asin(sqrt(latitudeH + tmp*lontitudeH)));
}

void GribInterpretor::new_index(const GribDecoder& grib)
{
    //Use the grib Iterator to create the index

    grib_handle* handle = grib.handle();


    int error;

    grib_iterator* iter = grib_iterator_new(handle, 0, &error);

    double lat1, lon1, lat2, lon2, val;
    grib_iterator_next(iter, &lat1, &lon1, &val) ;
    grib_iterator_next(iter, &lat2, &lon2, &val) ;



    grib_iterator_delete(iter);
    // Get the fisrt 2 points ...


    indexStep_ = distance(lat1, lon1, lat2, lon2) * 4;
    indexStep_ = 0.5;

    indexLon_ = 360./indexStep_;
    indexLat_ = 180./indexStep_;


/* scanning mode :
    bit	value	meaning
    1	0	Points scan in +i direction
    1	1	Points scan in -i direction
    2	0	Points scan in -j direction
    2	1	Points scan in +j direction
    3	0	Adjacent points in i direction are consecutive
    3	1	Adjacent points in j direction are consecutive
*/
    if ( grib.getLong("jScansPositively") == 1 || grib.getLong("iScansPositively") == 0 ) {
    	MagLog::error() << " Scanning mode not yet supported" << endl;
    	return;
    }

    helper_ = vector<vector<Index> >((indexLon_+1)*(indexLat_+1), vector<Index>());

    iter = grib_iterator_new(handle, 0, &error);


    double lat, lon, u;
    int ilat, ilon;
    {

    Timer timer("index", "index");
    int i = 0;
    bool flag_error = true;
    //prepare enveloppe
    minlon_ = 360;
    maxlon_ = 0;
    minlat_ = 90;
    maxlat_ = -90;

    while (grib_iterator_next(iter, &lat, &lon, &u) ) {
    	// Send a warning if lat lon are not in the expected rangs :
    	if ( lat < -90 || lat > 90 || lon < -180 || lon > 360) {
    		if ( flag_error ) {
                MagLog::warning() << "Check Grib Iterator: Position is not in the expected range [" << lat << ", " << lon << "]" << endl;
                flag_error = false;
            }
            continue;
    	}

        if ( minlat_ > lat) minlat_ = lat;
        if ( maxlat_ < lat) maxlat_ = lat;
        if ( minlon_ > lon) minlon_ = lon;
        if ( maxlon_ < lon) maxlon_ = lon;

    	ilat = floor((lat+90)/indexStep_);
        ilon = floor(lon/indexStep_);



        helper_[ilat * indexLon_ + ilon].push_back(Index(i, lat, lon));

        i++;
    }


    west_ = 0;
    east_ = 360.;
    grib_iterator_delete(iter);
    }


}



Index GribInterpretor::nearest(double ulat, double ulon)
{



    Index index(-1, 0, 0);
    if ( ulat < minlat_ ) 
        return index;
    if ( ulat > maxlat_ ) 
        return index;
    if ( ulon < minlon_ ) 
        return index;
    if ( ulon > maxlon_ ) 
        return index;

    
    if ( ulat == -1000. || ulon == -1000.)
          return index;
    if ( ulat >= 90 || ulat <= -90)
          return index;




    int ilat = floor((ulat+90)/indexStep_);
    int ilon = floor(ulon/indexStep_);
    int lat1, lat2;

    if ( ilon == indexLon_ )
        ilon = 0;




    lat1 = (ilat==0) ? ilat : ilat - 1;
    lat2 = (ilat == indexLat_) ? ilat : ilat + 1;

    // now make sure that we have






    

    double nearest = std::numeric_limits<double>::max();
    for ( int clat = lat1; clat <= lat2; clat++ ) {
        // find the first non empty cell
        // Try ilon ..
        vector<Index> points = helper_[clat * indexLon_ + ilon];
        set<int> lonn;

        lonn.insert(ilon);
        bool empty = true;
        int count = 0;
        // Try the first cell not empty on the left
        int lon = ilon-1;

        while ( empty  && count <  indexLon_) {
        	if ( lon < 0 ) {
        		lon = indexLon_ -1;
        	}

        	points = helper_[clat * indexLon_ + lon];
        	if ( !points.empty() ) {
        		lonn.insert(lon);
        		empty = false;
        	}
        	count++;
        	lon--;
        }
        empty = true;
        count = 0;
        lon = ilon +1;
        // try the first cell not empty on the right
        while ( empty  && count <  indexLon_ ) {
        	if ( lon >= indexLon_ ) {
        		lon = 0;
        	}

        	points = helper_[clat * indexLon_ + lon];
        	if ( !points.empty() ) {
        		lonn.insert(lon);
        		empty = false;
        	}
        	count++;
        	lon++;
        }



        for ( set<int>::iterator lon = lonn.begin(); lon != lonn.end(); ++lon ) {

            vector<Index> points = helper_[clat * indexLon_ + (*lon)];



            for (vector<Index>::iterator point = points.begin(); point != points.end(); ++point) {
                Index i = *point;

                double dist = distance(ulat, ulon, i.lat_, i.lon_);

                if ( dist < nearest ) {
                    nearest = dist;
                    index = i;

                }
            }

        }


    }

    //if ( index.lon_ < 0 )
      //  index.lon_ += 360.;

    return index;
}



void GribInterpretor::scaling(const GribDecoder& grib, double& scaling,
        double& offset, string& originalUnits, string& derivedUnits) const {
    scaling = 1;
    offset = 0;

    // First check that they are not derived fields!

    if (grib.scaling_ || grib.derived_scaling_) {
        long derived = grib.getLong("generatingProcessIdentifier");

        if ((derived != 254 && grib.scaling_)
                || (derived == 254 && grib.derived_scaling_)) {
            // The key 'paramId' embodies a number of features such as centre, parameter,
            // level, etc. This means that we should not need to worry about table
            // numbers, etc as we did with GRIBEX. However, it's not entirely clear
            // what we can do with non-ECMWF data, as we don't seem to have tables
            // giving scaling factors & offsets for such data. The code, as originally
            // written here takes a table-based approach, but this will probably
            // become redundant. What we really need is something more based on paramIds.
            // In the meantime, we will take the paramIds as if they are from ECMWF data.
            // In practice, this means pretending that all data is from
            // centre=98,table=128.

            long table = 128; // hard-coded in case of GRIB 2
            long centre = 98;  // hard-coded in case of GRIB 2

            //long edition = grib.getLong("edition");
            //
            //if (edition == 1)
            //{
            //  table  = grib.getLong("table2Version");
            //  centre = grib.getLong("centre");
            //}
            //else
            //{
            //  // GRIB 2 does not use the table-based approach, so we just hope that this will
            //  // work with most data if we use the standard ECMWF tables...
            //}

            long id = grib.getLong("paramId");

            try {
                const ParamDef& paramdef = LocalTable::localInfo(id, table,
                        centre);
                scaling = paramdef.scaling();
                offset = paramdef.offset();
                originalUnits = paramdef.originalUnit();
                derivedUnits = paramdef.derivedUnit();
                if ( paramdef.code() == -1 ) {
                    originalUnits = grib.getString("units");
                    derivedUnits = originalUnits;
                }
            }
            catch (exception) { 
               
                MagLog::warning()
                        << " Can not find information for the parameter [" << id
                        << "." << table << "]\n";
            }
        }
        
    } else {
        scaling = grib.scaling_factor_;
        offset = grib.scaling_offset_;
    }
    // Add a sanity check : the factor can not be 0..
    if (scaling == 0)
        scaling = 1;
}

void GribInterpretor::scaling(const GribDecoder& grib, Matrix** matrix) const {
    double factor, offset;

    scaling(grib, factor, offset);

    (*matrix)->multiply(factor);
    (*matrix)->plus(offset);
}
void  GribInterpretor::index(const GribDecoder& grib)
{
    throw MethodNotYetImplemented("GribInterpretor::index");
}



int GribInterpretor::nearest(double lon, double lat, double& nlon, double& nlat)
{
/*
    map<double, map<double, int> >::iterator y1, y2, y;
    map<double, int>::iterator x1, x2, x;

    if ( lat < index_.begin()->first)
        return -1;
    if ( lat > index_.rbegin()->first)
        return -1;
    y2 = index_.lower_bound(lat);
    if ( y2 == index_.begin() ) {
        y = y2;
    }
    else {
        y1 = y2;
        y1--;
        y  = (lat - y1->first < y2->first - lat) ? y1 : y2;
    }
    nlat = y->first;



    if ( lon < y->second.begin()->first)
        return -1;
    if ( lon > y->second.rbegin()->first)
        return -1;
    x2 = y->second.lower_bound(lon);
    if ( x2 == y->second.begin() ) {
        x = x2;
    }
    else {
        x1 = x2;
        x1--;
        x = (lon - x1->first < x2->first - lon) ? x1 : x2;
    }
    nlon = x->first;
    return x->second;
*/
}

void GribInterpretor::raw(GribDecoder& grib,
        const Transformation& transformation,
        vector<pair<double, vector<pair<double, CustomisedPoint*> > > >& points,
        double& minlon, double& maxlon) const
{
    Timer timer("grib", "raw");
    double factor, offset;
    scaling(grib, factor, offset);
    int err;

    string uname, vname;

    grib_handle* uc = grib.uHandle(uname);
    grib_handle* vc = grib.vHandle(vname);


    long nblat = grib.getLong("numberOfPointsAlongAMeridian");
    long nblon = grib.getLong("numberOfPointsAlongAParallel");

    points.reserve(nblat);

    grib_iterator* uiter = grib_iterator_new(uc, 0, &err);
    grib_iterator* viter = grib_iterator_new(vc, 0, &err);
    double missing = grib.getDouble("missingValue");

    double lat, lon, u, v;
    double last = -99999999;

    minlon = 999999;
    maxlon = -999999;

    while (grib_iterator_next(uiter, &lat, &lon, &u)
            && grib_iterator_next(viter, &lat, &lon, &v)) {

        if (transformation.in(lon, lat) || transformation.in(lon - 360, lat)) {
            if (minlon > lon)
                minlon = lon;
            if (maxlon < lon)
                maxlon = lon;
            if (u != missing)
                u = (u * factor) + offset;
            if (v != missing)
                v = (v * factor) + offset;

            if (lat != last) {
                last = lat;
                points.push_back(
                        make_pair(lat,
                                vector<pair<double, CustomisedPoint*> >()));
                points.back().second.reserve(nblat * 2);
//              points.back().second.reserve(nblat * 2);	// RV: nblat * 2??
                points.back().second.reserve(nblon + 1);

            }

            CustomisedPoint* point = new CustomisedPoint(lon, lat, "");
            point->insert(make_pair(uname, u));
            point->insert(make_pair(vname, v));
            points.back().second.push_back(make_pair(lon, point));

        }

    }

    grib_iterator_delete(viter);
    grib_iterator_delete(uiter);

    for (vector<pair<double, vector<pair<double, CustomisedPoint*> > > >::iterator ilat =
            points.begin(); ilat != points.end(); ++ilat) {
        vector < pair<double, CustomisedPoint*> > &lons = ilat->second;

        CustomisedPoint* first = lons.front().second;
        ;

        //if (last->longitude() - first->longitude() > XResolution(grib)) {
        CustomisedPoint* dup = new CustomisedPoint(first->longitude() + 360,first->latitude(), "");
        dup->insert(make_pair("x_component", (*first)["x_component"]));
        dup->insert(make_pair("y_component", (*first)["y_component"]));
        lons.push_back(make_pair(dup->longitude(), dup));
        //}

    }

}

void GribInterpretor::raw(const GribDecoder& grib,
        const Transformation& transformation, const string& key,
        map<double, map<double, CustomisedPoint*> >& points) const {
    Timer timer("grib", "raw");
    double factor, offset;
    scaling(grib, factor, offset);
    int err;
    size_t nb;
    grib_get_size(grib.id(), "values", &nb);

    map<double, map<double, CustomisedPoint*> >::iterator ilat;
    map<double, CustomisedPoint*>::iterator ilon;

    grib_iterator* iter = grib_iterator_new(grib.handle(), 0, &err);
    double missing = grib.getDouble("missingValue");

    double lat, lon, value;

    /* Loop on all the lat/lon/values. */
    while (grib_iterator_next(iter, &lat, &lon, &value)) {

        if (transformation.in(lon, lat) || transformation.in(lon - 360, lat)) {
            if (value != missing)
                value = (value * factor) + offset;

            ilat = points.find(lat);
            if (ilat == points.end()) {

                points.insert(make_pair(lat, map<double, CustomisedPoint*>()));
                ilat = points.find(lat);

            }
            ilon = ilat->second.find(lon);

            if (ilon == ilat->second.end()) {
                CustomisedPoint* pt = new CustomisedPoint(lon, lat, "");
                pt->missing(true);
                ilat->second.insert(make_pair(lon, pt));
                ilon = ilat->second.find(lon);

            }
            ilon->second->insert(make_pair(key, value));

        }

    }

    /* At the end the iterator is deleted to free memory. */
    grib_iterator_delete(iter);

}
/*!
 Class information are given to the output-stream.
 */
void GribRegularInterpretor::print(ostream& out) const {
    out << "GribRegularInterpretor[";
    out << "]";
}

void GribRegularInterpretor::interpretAsMatrix(const GribDecoder& grib,
        Matrix** matrix, const Transformation&) const {
    interpretAsMatrix(grib, matrix);
}

void GribRegularInterpretor::index(const GribDecoder& grib)
{
    if ( !index_.empty() )
        return;
    long nblon = grib.getLong("numberOfPointsAlongAParallel");

    west_ = grib.getDouble("longitudeOfFirstGridPointInDegrees");

    east_ = grib.getDouble("longitudeOfLastGridPointInDegrees");

    longitudesSanityCheck(west_, east_);


    double lon = (east_ - west_) / (nblon - 1);

    vector<double> latitudes;
    vector<double> longitudes;

    this->latitudes(grib, latitudes);

    double x = west_;
    for (int i = 0; i < nblon; i++) {
        longitudes.push_back(x);
        x = west_ + (i + 1) * lon;
    }




    long jPointsAreConsecutive = grib.getLong("jPointsAreConsecutive");
    int index = 0;
    try {


        if (jPointsAreConsecutive) {
            for ( vector<double>::iterator lat = latitudes.begin(); lat != latitudes.end(); ++lat) {
                index_.insert(make_pair(*lat, map<double, int>()));
            }
            for ( vector<double>::iterator lon = longitudes.begin(); lon != longitudes.end(); ++lon) {

                for ( vector<double>::iterator lat = latitudes.begin(); lat != latitudes.end(); ++lat) {

                    index_[*lat].insert(make_pair(*lon, index));
                    index++;
                }
            }

        }
        else  // otherwise, just copy the array of values as they are
        {
            for ( vector<double>::iterator lat = latitudes.begin(); lat != latitudes.end(); ++lat) {
                index_.insert(make_pair(*lat, map<double, int>()));
                for ( vector<double>::iterator lon = longitudes.begin(); lon != longitudes.end(); ++lon) {
                    index_[*lat].insert(make_pair(*lon, index));
                    index++;
                }
            }
        }

    }

    catch (...) {
        throw MagicsException("GribRegularInterpretor - Not enough memory");
    }



}

void GribRegularInterpretor::interpretAsMatrix(const GribDecoder& grib,
        Matrix** matrix,  Matrix** matrix2) const {
    Timer timer("gribapi", " read grib");
    MagLog::dev() << "GribRegularInterpretor::interpretAsMatrix" << "\n";
    long nblon = grib.getLong("numberOfPointsAlongAParallel");
    long nblat = grib.getLong("numberOfPointsAlongAMeridian");

    if (*matrix == 0)
        *matrix = new Matrix(nblat, nblon);
    if ( matrix2 )
    	*matrix2 = new Matrix(nblat, nblon);

    size_t nb;
    grib_get_size(grib.id(), "values", &nb);

    MagLog::dev() << "numberOfFieldValues[" << nb << "]" << "\n";
    double missing = INT_MAX;
    grib.setDouble("missingValue", missing);
    (*matrix)->missing(missing);
    (*matrix)->akimaEnabled();

    double north = grib.getDouble("latitudeOfFirstGridPointInDegrees");
    double west = grib.getDouble("longitudeOfFirstGridPointInDegrees");
    double south = grib.getDouble("latitudeOfLastGridPointInDegrees");
    double east = grib.getDouble("longitudeOfLastGridPointInDegrees");

    longitudesSanityCheck(west, east);

    MagLog::dev() << "NewAPI---> area[" << west << ", " << north << ", " << east
            << ", " << south << "]" << "\n";
    double loni = longitudeIncrement(grib);

    double lon = (east - west) / (nblon - 1);

    MagLog::dev() << "increment -->" << loni << " (from->" << west << " to-->"
            << west + (nblon - 1) * loni << ")" << endl;
    MagLog::dev() << "calcul -->" << lon << " (from->" << west << " to-->"
            << west + (nblon - 1) * lon << ")" << endl;

    latitudes(grib, (*matrix)->rowsAxis());

    if ( matrix2 != NULL) {

    	(*matrix)->xIndex_.reserve((*matrix)->rowsAxis().size());
    	int offset = 0;
    	int l = 0;
    	for ( vector<double>::iterator lat = (*matrix)->rowsAxis().begin(); lat != (*matrix)->rowsAxis().end(); ++lat) {
    		(*matrix)->yIndex_.insert(make_pair(*lat, l));
    		l++;
    		(*matrix)->xIndex_.push_back(InfoIndex(west, east, nblon, offset));
    		offset += nblon;
    	}
    	 (*matrix)->data_.resize(nb);
    	 (*matrix2)->data_.resize(nb);
    }
    double x = west;
    for (int i = 0; i < nblon; i++) {
        (*matrix)->columnsAxis().push_back(x);
        x = west + (i + 1) * lon;
    }

    (*matrix)->setMapsAxis();

    long jPointsAreConsecutive = grib.getLong("jPointsAreConsecutive");

    try {
        (*matrix)->resize(nb);
        size_t aux = size_t(nb);

        // if jPointsAreConsecutive=1 then the values represent columns of data instead
        // of rows, so we have to 'reshape' the array so that it is reorganised into rows.

        if (jPointsAreConsecutive) {
            vector<double> *d = new vector<double>(nb);  // temporary array
            double *d1 = &d->front();                 // temporary array pointer
            double *d2 = &(*matrix)->front();            // final array

            grib_get_double_array(grib.id(), "values", d1, &aux);

            for (int i = 0; i < nblon; i++) {
                for (int j = 0; j < nblat; j++) {
                    d2[j * nblon + i] = d1[i * nblat + j];
                }
            }
            delete d;

        } else  // otherwise, just copy the array of values as they are
        {


            if ( matrix2 != NULL ) {
            	grib_get_double_array(grib.uHandle(), "values", &(*matrix)->front(),
            	                    &aux);
            	grib_get_double_array(grib.uHandle(), "values", &(*matrix)->data_.front(),
                    	                    &aux);
            	grib_get_double_array(grib.vHandle(), "values", &(*matrix2)->front(),
                            &aux);
            	grib_get_double_array(grib.vHandle(), "values", &(*matrix2)->data_.front(),
                                    &aux);
            }
            else
            	grib_get_double_array(grib.handle(), "values", &(*matrix)->front(),
            	            	                    &aux);
        }
        for (int i = 0; i < nblon; i++) {
        	double lon = (*matrix)->columnsAxis()[i];
        	for (int j = 0; j < nblat; j++) {
        		double lat = (*matrix)->rowsAxis()[j];


        	}
        }
        (*matrix)->missing(missing);

    } catch (...) {
        throw MagicsException("GribRegularInterpretor - Not enough memory");
    }
}




void GribRegularInterpretor::latitudes(const GribDecoder& grib,
        vector<double>& latitudes) const {
    double north = grib.getDouble("latitudeOfFirstGridPointInDegrees");

    long nblat = grib.getLong("numberOfPointsAlongAMeridian");
    int scanning = grib.getLong("jScansPositively") ? 1 : -1;
    double lat = scanning * grib.getDouble("jDirectionIncrementInDegrees");

    double y = north;
    for (int i = 0; i < nblat; i++) {
        latitudes.push_back(y);
        y += lat;

    }

}

void GribRegularGaussianInterpretor::latitudes(const GribDecoder& grib,
        vector<double>& latitudes) const {
    long res = grib.getLong("numberOfParallelsBetweenAPoleAndTheEquator");
    double array[2 * res];
    grib_get_gaussian_latitudes(res, array);
    double first = grib.getDouble("latitudeOfFirstGridPointInDegrees");
    double last = grib.getDouble("latitudeOfLastGridPointInDegrees");
    ;
    // get the scanning mode !
    double north = first;
    double south = last;
    long scanning = grib.getLong("jScansPositively");
    ;
    if (scanning == 1) {
        north = last;
        south = first;
    }

    for (int i = 0; i < 2 * res; i++) {
        if (same(array[i], north, 10e-2)) {
            latitudes.push_back(array[i]);
            continue;
        }
        if (same(array[i], south, 10e-2)) {
            latitudes.push_back(array[i]);
            continue;
        }
        if (array[i] < north && array[i] > south)
            latitudes.push_back(array[i]);
    }

    if (scanning == 1)
        std::reverse(latitudes.begin(), latitudes.end());
}

double GribRegularInterpretor::longitudeIncrement(
        const GribDecoder& grib) const {
    int scanning = grib.getLong("iScansNegatively") ? -1 : 1;
    return scanning * grib.getDouble("iDirectionIncrementInDegrees");

}

PaperPoint GribInterpretor::reference(const GribDecoder& grib, const Transformation& transformation)
{
    double lon = grib.getDouble("longitudeOfFirstGridPointInDegrees");
    double lat = grib.getDouble("latitudeOfFirstGridPointInDegrees");

    UserPoint point(grib.getDouble("longitudeOfFirstGridPointInDegrees"),
            grib.getDouble("latitudeOfFirstGridPointInDegrees"));

//  [RV]: Pour thinning vents. Les barbules tracées ne dependront ainsi
//  que du facteur de thinning et non du domaine
//  ( Bien meilleure impression lors de scrollings ... )
    if (1)
//  if (transformation.in(point))
        return transformation(point);
    int err;
    grib_iterator* iter = grib_iterator_new(grib.handle(), 0, &err);

    double value;
    /* Loop on all the lat/lon/values. */
    while (grib_iterator_next(iter, &lat, &lon, &value)) {
        point = UserPoint(lon, lat);
        if (transformation.in(point)) {
            grib_iterator_delete(iter);
            return transformation(point);
        }
    }

    /* At the end the iterator is deleted to free memory. */
    grib_iterator_delete(iter);
    return PaperPoint(transformation.getMinPCX(), transformation.getMinPCY());
}

void GribRegularInterpretor::interpretAsRaster(const GribDecoder& grib,
        RasterData& raster, const Transformation& transformation) const {
    MagLog::dev() << "GribRegularInterpretor::interpretAsRaster" << "\n";

    BoxMatrixHandler box(const_cast<GribDecoder*>(&grib)->matrix(),
            transformation);

    int nblon = box.columns();
    int nblat = box.rows();
    double east = box.column(0, nblon - 1);
    double west = box.column(0, 0);
    double south = box.row(0, 0);
    double north = box.row(nblat - 1, 0);

    raster.setUpperRightCorner(east, north);
    raster.setLowerLeftCorner(west, south);

    double lon = (east - west) / (nblon - 1);
    double lat = (north - south) / (nblat - 1);

    raster.setXResolution(lon);
    raster.setYResolution(lat);

    raster.setColumns(nblon);
    raster.setRows(nblat);
    //
    raster.setProjection(new TeLatLong(TeDatum()));

    raster.reserve(nblon * nblat);

    for (int j = nblat - 1; j >= 0; j--)
        for (int i = 0; i < nblon; i++)
            raster.push_back(box(j, i));
}

void GribReducedGaussianInterpretor::interpretAsRaster(const GribDecoder& grib,
        RasterData& raster, const Transformation& transformation) const {
    MagLog::dev() << "GribRegularInterpretor::interpretAsRaster" << "\n";
    Timer timer("grib api", "read grib");
    BoxMatrixHandler box(const_cast<GribDecoder*>(&grib)->matrix(),
            transformation);

    int nblon = box.columns();
    int nblat = box.rows();
    double east = box.column(0, nblon - 1);
    double west = box.column(0, 0);
    double south = box.row(0, 0);
    double north = box.row(nblat - 1, 0);

    raster.setUpperRightCorner(east, north);
    raster.setLowerLeftCorner(west, south);

    double lon = (east - west) / (nblon - 1);
    double lat = (north - south) / (nblat - 1);

    raster.setXResolution(lon);
    raster.setYResolution(lat);

    raster.setColumns(nblon);
    raster.setRows(nblat);
    //
    raster.setProjection(new TeLatLong(TeDatum()));

    raster.reserve(nblon * nblat);

    for (int j = nblat - 1; j >= 0; j--)
        for (int i = 0; i < nblon; i++)
            raster.push_back(box(j, i));
}

void GribReducedGaussianInterpretor::print(ostream& out) const {
    out << "GribRegularInterpretor[";
    out << "]";
}

void GribReducedGaussianInterpretor::interpretAsMatrix(const GribDecoder& grib,
        Matrix** matrix, const Transformation& transformation) const {
    interpretAsMatrix(grib, matrix);

}

double GribReducedLatLonInterpretor::XResolution(
        const GribDecoder& grib) const {
    long res = grib.getLong("Nj");

    double west = grib.getDouble("longitudeOfFirstGridPointInDegrees");
    double east = grib.getDouble("longitudeOfLastGridPointInDegrees");
    ;

    longitudesSanityCheck(west, east);

    return (east - west) / (2 * res);
}
double GribReducedGaussianInterpretor::XResolution(
        const GribDecoder& grib) const {
    long res = grib.getLong("numberOfParallelsBetweenAPoleAndTheEquator");
    double west = grib.getDouble("longitudeOfFirstGridPointInDegrees");

    double east = grib.getDouble("longitudeOfLastGridPointInDegrees");
    ;

    longitudesSanityCheck(west, east);
    return (east - west) / (4 * res);
}

void GribReducedGaussianInterpretor::interpretAsMatrix(const GribDecoder& grib,
        Matrix** matrix, Matrix** matrix2) const {


    Timer timer("gribapi", " read grib");
    *matrix = new Matrix();
    if ( matrix2 )
    	 *matrix2 = new Matrix();
    size_t nb;
    grib_get_size(grib.id(), "values", &nb);
    GribDecoder::InterpolateMethod interpolate = grib.interpolateMethod();
    MagLog::dev() << "numberOfFieldValues[" << nb << "]" << "\n";
    double missing = std::numeric_limits<double>::max();

    grib.setDouble("missingValue", missing);

    (*matrix)->missing(missing);
    (*matrix)->akimaEnabled();

    double north = grib.getDouble("latitudeOfFirstGridPointInDegrees");
    double west = grib.getDouble("longitudeOfFirstGridPointInDegrees");
    double south = grib.getDouble("latitudeOfLastGridPointInDegrees");
    double east = grib.getDouble("longitudeOfLastGridPointInDegrees");
    double plp = grib.getDouble("PLPresent");
    long res = grib.getLong("numberOfParallelsBetweenAPoleAndTheEquator");
    long nblat = grib.getLong("Nj");
    longitudesSanityCheck(west, east);
    MagLog::dev() << "NewAPI---> area[" << west << ", " << north << ", " << east << ", " << south << "]" << "\n";
    MagLog::dev() << "PLPresent---> " << plp << "\n";
    MagLog::dev() << "Res---> " << res << "\n";

    double pl[2 * res];
    size_t aux = 2 * res;
    grib_get_double_array(grib.id(), "pl", pl, &aux);
    int nblon = 0;
    int ii = 0;


    long global = grib.getLong("global");

    // We have to determine if the field is global!
    if (global) {
        east = west + 360.;
    }
    vector<vector<double> > rows;


    for ( int i = 0; i < nblat; i++) {
        long numPts = 0;
        long indexFirst, indexLast;
        int globalPointsInThisRow = pl[i];
        double dx = 360./pl[i];


        // find which points are in this row; a sub-area of a reduced Gaussian grid
        // contains a subset of the points from the global grid, with the points
        // in exactly the same positions as the corresponding ones in the
        // global grid. The GRIB_API function grib_get_reduced_row() does not
        // produce the correct result when given a global field, so we need
        // to make that a separate case.

        double add = 0;

        if (global) {
            numPts     = globalPointsInThisRow;
            indexFirst = 0;
            indexLast  = numPts-1;

        }
        else {
            grib_get_reduced_row(globalPointsInThisRow, west, east,
                                 &numPts, &indexFirst,&indexLast);
            add = 2*dx;
        }

        rows.push_back(vector<double>());

        int n = indexFirst;


        // the index of the first point is not necessarily smaller than the index
        // of the second point, depending on the sub-area.
        // we need to check whether the last index is the last point; however,
        // grib_get_reduced_row() seems to sometimes return a numPoints which is 1
        // greater than the number of global points in the row so we need a double
        // check.
        bool lastSubAreaIndexIsNotLastGlobalIndex = (indexLast != globalPointsInThisRow-1) &&
                                                    (indexLast != globalPointsInThisRow);

        while (n != indexLast+1){
            double thisLon = n*dx;
            if ( thisLon > east +add) thisLon -= 360.;

            rows.back().push_back(thisLon);
            n++;
            if (n == globalPointsInThisRow && lastSubAreaIndexIsNotLastGlobalIndex )  // wrap around?
                n = 0;
        }


        if ( rows.back().size() > nblon) nblon = rows.back().size();
        ii +=  rows.back().size();
    }

// Find the latitudes
    map<double, map<double, int> > index;
    double array[2 * res];
    grib_get_gaussian_latitudes(res, array);

    for (int i = 0; i < 2*res; i++) {
    	if ( same(array[i], north, 0.001) ) {
    		(*matrix)->rowsAxis().push_back(array[i]);
    		(*matrix)->yIndex_.insert(make_pair(array[i], i));
    		continue;
    	}
    	if ( same(array[i], south, 0.001) ) {
    		(*matrix)->rowsAxis().push_back(array[i]);
    		(*matrix)->yIndex_.insert(make_pair(array[i], i));
    		continue;
    	}
    	if ( array[i] < north && array[i] > south) {
    		(*matrix)->rowsAxis().push_back(array[i]);
    		(*matrix)->yIndex_.insert(make_pair(array[i], i));
    	}

    }
    if ( matrix2 ) {
    	(*matrix)->xIndex_.reserve((*matrix)->rowsAxis().size());
	}

    // compute the number of points we'll be adding to the matrix so that we can
    // allocate them in one go, rather than allowing the STL to re-allocate
    // when we reach the capacity

    double *data = new double[nb];
    double *data2 = new double[nb];




    (*matrix)->reserve(aux * nblon);
       if ( matrix2) {
       	(*matrix2)->reserve(aux * nblon);
       	(*matrix2)->data_.reserve(nb);
       	(*matrix)->data_.reserve(nb);
       }

    double width = east - west;
    double step = (width) / (nblon);

    grib_get_double_array(grib.id(), "values", data, &aux);
    if ( matrix2 ) {
    	grib_get_double_array(grib.uHandle(), "values", data, &aux);
    	grib_get_double_array(grib.vHandle(), "values", data2, &aux);
    }
    else
    	grib_get_double_array(grib.id(), "values", data, &aux);

    int d = 0;

    vector<double> missingLon;

    d = 0;
    vector<double>::iterator ll = (*matrix)->rowsAxis().begin();
    {
    Timer timer("map2", " pair");
    bool first = true;
    for (vector<vector<double> >::iterator row = rows.begin(); row != rows.end(); ++row) {

    	vector<double> p;
        p.reserve(row->size());
        if ( matrix2 ) {

        	(*matrix)->xIndex_.push_back(InfoIndex(row->front(), row->back(), row->size(), d));

        }
        ++ll;
        for (int ii = 0; ii < row->size(); ii++) {
            p.push_back(data[d]);
            if ( matrix2 ) {
                   	(*matrix)->data_.push_back(data[d]);
                   	(*matrix2)->data_.push_back(data2[d]);
                   }
            d++;
        }


        if (interpolate == GribDecoder::nearest_valid ) {
        	// Fill left vector
        	vector<double> left;
        	int last = 0;
        	int c = 0;
        	bool print = false;
        	for ( vector<double>::iterator val = p.begin(); val != p.end(); ++val) {
        		if ( *val != missing ) {
        			last = c;
        		}
        		else {
        			print = true;
        		}
        		left.push_back(last);
        		c++;
        	}
        	// Fill right vector
        	vector<double> right(p.size(), 0);
        	last = 0;
        	c = p.size()-1;
        	for ( vector<double>::reverse_iterator val = p.rbegin(); val != p.rend(); ++val) {
        		if ( *val != missing ) {
        			last = c;
        		}
        		right[c] = last;
        		c--;
        	}

        	int fill = grib.missingFill();

        	int todo = 0;
        	for (int ii = 0; ii < p.size(); ii++) {
        		double keep = p[ii];
        		if ( p[ii] == missing && todo < fill ) {
        			double lon = (*row)[ii];
        			double lon1 = (*row)[left[ii]];
        			double lon2 = (*row)[right[ii]];
        			double d1 = (lon2 - lon) / (lon2 - lon1);
        			double d2 = 1 - d1;
        			p[ii] = (d2 < 0.5) ? p[left[ii]] : p[right[ii]];
        			todo++;
        		}
        		if ( keep != missing ) {
        			todo = 0;
        		}
        	}

        	todo = 0;
        	for (int ii =  p.size()-1; ii >= 0; ii--) {
        		double keep = p[ii];
        		if ( p[ii] == missing && todo < fill ) {
        			double lon = (*row)[ii];
        			double lon1 = (*row)[left[ii]];
        			double lon2 = (*row)[right[ii]];
        			double d1 = (lon2 - lon) / (lon2 - lon1);
        			double d2 = 1 - d1;
        			p[ii] = (d2 < 0.5) ? p[left[ii]] : p[right[ii]];
        			todo++;
        		}
        		if ( keep != missing ) {
        			todo = 0;
        		}

        	}
        }





        double lon = west;
        unsigned int p1 = 0;
        unsigned int p2 = 1;

        vector<double>::iterator r = row->begin();
        double lon1 = *r;
        r++;
        double lon2 = *r;

        int x = 0;
      

        while (x < nblon) {

            if ( lon < lon1 ) {
                (*matrix)->push_back(p[0]);
                x++;
                lon = west + ( x*step);
                continue;
            }
            if ( lon >= row->back() ) { 
                if ( global ) {
                    p2 = 0;
                    lon2 = 360.;
                    lon1 = row->back();
                    p1 = p.size()-1;
                   

                } 
                else { 
                    (*matrix)->push_back(p.back());
                    x++;
                    lon = west + ( x*step);
                    continue;
                }
            }
            if ( lon > lon2) {
                
                p1++;
                p2++;
                
                lon1 = lon2;
                
                r++;
                if ( r == row->end() ) 
                    r--;
                lon2 = (*r);   
                
            }

            double d1 = (lon2 - lon) / (lon2 - lon1);
            double d2 = 1 - d1;
            double val;

            if (interpolate == GribDecoder::interpolate) {
                  if (p[p1] == missing )
                        val = p[p2];
                   else
                	   if ( p[p2] != missing )
                		   val = (p[p1] * d1) + (p[p2] * d2);
               
                  (*matrix)->push_back(val);

            }
            else {
                 val = (d2 < 0.5) ? p[p1] : p[p2];
                 (*matrix)->push_back(val);
            }

            x++;
            lon = west + ( x*step);
        }
        

    }
    }
    delete[] data;

    for (int x = 0; x < nblon; x++) {
        (*matrix)->columnsAxis().push_back(west + (x * step));
    }

    (*matrix)->setMapsAxis();
}


void GribReducedLatLonInterpretor::print(ostream& out) const {
    out << "GribReducedLatLonInterpretor[";
    out << "]";
}

void GribReducedGaussianInterpretor::index(GribDecoder const& grib)
{



}
void GribReducedLatLonInterpretor::interpretAsMatrix(const GribDecoder& grib,
        Matrix** matrix, Matrix** matrix2) const {

    Timer timer("gribapi", " read grib");
    *matrix = new Matrix();
    size_t nb;
    grib_get_size(grib.id(), "values", &nb);
    GribDecoder::InterpolateMethod interpolate = grib.interpolateMethod();

    double missing = std::numeric_limits<double>::max();
    grib.setDouble("missingValue", missing);

    (*matrix)->missing(missing);
    (*matrix)->akimaEnabled();
    if ( matrix2 )
    	*matrix2 = new Matrix();

    double north = grib.getDouble("latitudeOfFirstGridPointInDegrees");
    double west = grib.getDouble("longitudeOfFirstGridPointInDegrees");
    double south = grib.getDouble("latitudeOfLastGridPointInDegrees");
    double east = grib.getDouble("longitudeOfLastGridPointInDegrees");

    longitudesSanityCheck(west, east);
    size_t res = grib.getLong("Nj");

    MagLog::dev() << "NewAPI---> area[" << west << ", " << north << ", " << east
            << ", " << south << "]" << "\n";
    MagLog::dev() << "Res---> " << res << "\n";

    double pl[res];

    long nblat = grib.getLong("numberOfPointsAlongAMeridian");
    int scanning = grib.getLong("jScansPositively") ? 1 : -1;
    double lat = scanning * grib.getDouble("jDirectionIncrementInDegrees");

    grib_get_double_array(grib.id(), "pl", pl, &res);

    double *data = new double[nb];
    double *data2 = new double[nb];

    size_t aux = size_t(nb);

    int nblon = 0;
    for ( int i = 0; i < res; i++)
        if (nblon < pl[i] )
            nblon = pl[i];

    double width = east - west;
    double step = width / nblon;

    // We have to determine if the field is global!
    // We have to determine if the field is global!
    bool global = east - west > 360 - 5 * step;

    if (global) {
        east = west + 360;
        width = east - west;
        step = width / nblon;
    }

    map<double, map<double, int> > index;
    for (int x = 0; x < nblon; x++) {
           (*matrix)->columnsAxis().push_back(west + (x * step));
       }

       double y = north;
       for (long i = 0; i < nblat; i++) {
           (*matrix)->rowsAxis().push_back(y);
           if ( matrix2)
        	   (*matrix)->index_.insert(make_pair(y, map<double, pair<double, double> >()));

           y += lat;
       }

    if ( matrix2) {
          	(*matrix2)->reserve(aux * nblon);
          	(*matrix2)->data_.reserve(nb);
          	(*matrix)->data_.reserve(nb);
          }

    if ( matrix2 ) {
    	 grib_get_double_array(grib.uHandle(), "values", data, &aux);
    	 grib_get_double_array(grib.uHandle(), "values", data2, &aux);
    }
    else
    	 grib_get_double_array(grib.id(), "values", data, &aux);
    int d = 0;


    for (size_t i = 0; i < res; i++) {
    	double lat = (*matrix)->rowsAxis()[i];
    	(*matrix)->yIndex_.insert(make_pair(lat, i));
    	if ( matrix2 )
    	    (*matrix)->xIndex_.push_back(InfoIndex(west, east, pl[i], d));

        if (pl[i] == 0) {
            // add missing data
            for (int x = 0; x < nblon; x++)
                (*matrix)->push_back(missing);
        }
        else {

            vector<double> p;
            vector<double> lons;

            double datastep = width / pl[i];
            {
            	Timer timer("map", "pair");

            for (int ii = 0; ii < pl[i]; ii++) {
                p.push_back(data[d]);
                double lon = west + (ii*datastep);
                lons.push_back( lon );
                if ( matrix2 ) {
                      (*matrix)->data_.push_back(data[d]);
                      (*matrix2)->data_.push_back(data2[d]);
                }

                d++;
            }
            }


            vector<double>::iterator val = p.begin();
            vector<double>::iterator lval = lons.begin();
            vector<double>::iterator nval = p.begin();
            nval++;
            vector<double>::iterator nlval = lons.begin();
            nlval++;

            for (int x = 0; x < nblon; x++) {

                double lon = west + (x*step);

                if ( lon > *nlval ) {

                    lval++;
                    val++;

                    if ( lval == lons.end() ) {
                        val = p.begin();
                        lval = lons.begin();

                    }
                    nval++;
                    nlval++;
                    if ( nlval == lons.end() ) {
                        nval = p.begin();
                        nlval = lons.begin();


                    }


                }





                double d1 = ( *nlval - lon) / (datastep);
                if ( d1 <  0 ) d1 = 1;
                double d2 = 1 - d1;
                double value;

                if (interpolate == GribDecoder::interpolate) {
                    if (*val == missing || *nval == missing)
                        value = missing;
                    else
                        value =  (d1 * (*val)) + (d2 * (*nval));
                }
                else {
                    value = (d2 < 0.5) ? *val : *nval;
                }
                (*matrix)->push_back(value);
            }





        }
    }

    delete[] data;
    delete[] data2;



    (*matrix)->setMapsAxis();
}

/*
 * Imported from Metview MvGrid...
 */

void GribRotatedInterpretor::print(ostream& out) const {
    out << "GribRotatedInterpretor[]";
}

UserPoint GribLambertAzimutalInterpretor::unrotate(double lat,
        double lon) const {

    return UserPoint(lon, lat);
}

double GribLambertAzimutalInterpretor::XResolution(const GribDecoder& grib) const
{
    return 0.0125;
}

pair<double, double> GribRotatedInterpretor::unrotate(double lat_y,
        double lon_x) const {
    const double cToRadians = M_PI / 180.0;
    double ZRADI = 1. / cToRadians;
    double ZSYCEN = sin(cToRadians * (southPoleLat_ + 90.));
    double ZCYCEN = cos(cToRadians * (southPoleLat_ + 90.));
    double ZSXROT = sin(cToRadians * lon_x);
    double ZCXROT = cos(cToRadians * lon_x);
    double ZSYROT = sin(cToRadians * lat_y);
    double ZCYROT = cos(cToRadians * lat_y);
    double ZSYREG = ZCYCEN * ZSYROT + ZSYCEN * ZCYROT * ZCXROT;
    ZSYREG = MAX(MIN(ZSYREG, +1.0), -1.0);
    double PYREG = asin(ZSYREG) * ZRADI;
    double ZCYREG = cos(PYREG * cToRadians);
    double ZCXMXC = (ZCYCEN * ZCYROT * ZCXROT - ZSYCEN * ZSYROT) / ZCYREG;
    ZCXMXC = MAX(MIN(ZCXMXC, +1.0), -1.0);
    double ZSXMXC = ZCYROT * ZSXROT / ZCYREG;
    double ZXMXC = acos(ZCXMXC) * ZRADI;
    if (ZSXMXC < 0.0)
        ZXMXC = -ZXMXC;
    double PXREG = ZXMXC + southPoleLon_;
    return std::make_pair(PYREG, PXREG);
}

PaperPoint GribRotatedInterpretor::reference(const GribDecoder& grib, const Transformation& transformation) {
    double lon = grib.getDouble("longitudeOfFirstGridPointInDegrees");
    double lat = grib.getDouble("latitudeOfFirstGridPointInDegrees");
    pair<double, double> xy = unrotate(lat, lon);
    UserPoint point(xy.second, xy.first);
//  [RV]: Cf GribInterpretor::reference()
    if (1)
//  if (transformation.in(point))
            return transformation(point);


    int err;
    grib_iterator* iter = grib_iterator_new(grib.handle(), 0, &err);

    double value;
    /* Loop on all the lat/lon/values. */
    while (grib_iterator_next(iter, &lat, &lon, &value)) {
        pair<double, double> xy = unrotate(lat, lon);
        point = UserPoint(xy.second, xy.first);
        if (transformation.in(point)) {
            grib_iterator_delete(iter);
            return transformation(point);
        }
    }

    /* At the end the iterator is deleted to free memory. */
    grib_iterator_delete(iter);
    return PaperPoint(transformation.getMinPCX(), transformation.getMinPCY());
}
pair<double, double> GribRotatedInterpretor::rotate(double lat_y,
        double lon_x) const {
    const double cToRadians = M_PI / 180.0;
    double ZRADI = 1. / cToRadians;
    double ZSYCEN = sin(cToRadians * (southPoleLat_ + 90.));
    double ZCYCEN = cos(cToRadians * (southPoleLat_ + 90.));

    double ZXMXC = cToRadians * (lon_x - southPoleLon_);
    double ZSXMXC = sin(ZXMXC);
    double ZCXMXC = cos(ZXMXC);
    double ZSYREG = sin(cToRadians * lat_y);
    double ZCYREG = cos(cToRadians * lat_y);
    double ZSYROT = ZCYCEN * ZSYREG - ZSYCEN * ZCYREG * ZCXMXC;
    ZSYROT = MAX(MIN(ZSYROT, +1.0), -1.0);

    double PYROT = asin(ZSYROT) * ZRADI;

    double ZCYROT = cos(PYROT * cToRadians);
    double ZCXROT = (ZCYCEN * ZCYREG * ZCXMXC + ZSYCEN * ZSYREG) / ZCYROT;
    ZCXROT = MAX(MIN(ZCXROT, +1.0), -1.0);
    double ZSXROT = ZCYREG * ZSXMXC / ZCYROT;

    double PXROT = acos(ZCXROT) * ZRADI;

    if (ZSXROT < 0.0)
        PXROT = -PXROT;

    return std::make_pair(PYROT, PXROT);
}

void GribLambertAzimutalInterpretor::interpretAsMatrix(const GribDecoder& grib,
        Matrix** matrix, Matrix** matrix2) const {
    long im = grib.getLong("numberOfPointsAlongXAxis");
    long jm = grib.getLong("numberOfPointsAlongYAxis");

/*
    RotatedMatrix *rotated = new RotatedMatrix(jm, im);
    *matrix = rotated;

    size_t nb;
    grib_get_size(grib.id(), "values", &nb);

    MagLog::dev() << "numberOfFieldValues[" << nb << "]" << "\n";

    double missing = -std::numeric_limits<double>::max();

    missing = grib.getDouble("missingValue");
    rotated->missing(missing);

    double north = grib.getDouble("latitudeOfFirstGridPointInDegrees");
    double west = grib.getDouble("longitudeOfFirstGridPointInDegrees");

    MagLog::dev() << "NewAPI---> area[" << west << ", " << north << "]" << "\n";

    try {
        Timer time("Grib", "lambert");

        MagLog::debug() << "Version" << grib_get_api_version() << endl;

        vector<double>& data = rotated->values();
        vector<double>& latm = rotated->rowsArray();
        vector<double>& lonm = rotated->columnsArray();

        size_t aux = size_t(nb);

        grib_get_double_array(grib.id(), "latitudes", &(latm.front()), &aux);
        grib_get_double_array(grib.id(), "values", &(data.front()), &aux);
        grib_get_double_array(grib.id(), "longitudes", &(lonm.front()), &aux);
        for (int i = 0; i < nb; i++) {

            if (lonm[i] > 180.)
                lonm[i] -= 360.;

        }

    } catch (MagicsException& e) {
        MagLog::error() << e << "\n";
    }
*/
}

void GribLambertAzimutalInterpretor::print(ostream& out) const {
    out << "GribLambertAzimutalInterpretor[]";
}

void GribRotatedInterpretor::interpretAsMatrix(const GribDecoder& grib,
        Matrix** matrix, Matrix** matrix2) const {

    southPoleLat_ = grib.getDouble("latitudeOfSouthernPoleInDegrees");
    southPoleLon_ = grib.getDouble("longitudeOfSouthernPoleInDegrees");
    angle_ = grib.getDouble("angleOfRotationInDegrees") * 180.0 / M_PI;
    uvRelativeToGrid_ = grib.getLong("uvRelativeToGrid");


     Timer timer("gribapi", " read grib");
    MagLog::dev() << "GribRegularInterpretor::interpretAsMatrix" << "\n";
    long nblon = grib.getLong("numberOfPointsAlongAParallel");
    long nblat = grib.getLong("numberOfPointsAlongAMeridian");

    if (*matrix == 0)
        *matrix = new RotatedMatrix(nblat, nblon, southPoleLat_, southPoleLon_);
    if ( matrix2 )
        *matrix2 = new RotatedMatrix(nblat, nblon, southPoleLat_, southPoleLon_);

    size_t nb;
    grib_get_size(grib.id(), "values", &nb);

    MagLog::dev() << "numberOfFieldValues[" << nb << "]" << "\n";
    double missing = INT_MAX;
    grib.setDouble("missingValue", missing);
    (*matrix)->missing(missing);
    

    double north = grib.getDouble("latitudeOfFirstGridPointInDegrees");
    double west = grib.getDouble("longitudeOfFirstGridPointInDegrees");
    double south = grib.getDouble("latitudeOfLastGridPointInDegrees");
    double east = grib.getDouble("longitudeOfLastGridPointInDegrees");

    longitudesSanityCheck(west, east);

    MagLog::dev() << "NewAPI---> area[" << west << ", " << north << ", " << east
            << ", " << south << "]" << "\n";
    double loni = longitudeIncrement(grib);

    double lon = (east - west) / (nblon - 1);

    MagLog::dev() << "increment -->" << loni << " (from->" << west << " to-->"
            << west + (nblon - 1) * loni << ")" << endl;
    MagLog::dev() << "calcul -->" << lon << " (from->" << west << " to-->"
            << west + (nblon - 1) * lon << ")" << endl;

    latitudes(grib, (*matrix)->rowsAxis());

    if ( matrix2 != NULL) {

        (*matrix)->xIndex_.reserve((*matrix)->rowsAxis().size());
        int offset = 0;
        int l = 0;
        for ( vector<double>::iterator lat = (*matrix)->rowsAxis().begin(); lat != (*matrix)->rowsAxis().end(); ++lat) {
            (*matrix)->yIndex_.insert(make_pair(*lat, l));
            l++;
            (*matrix)->xIndex_.push_back(InfoIndex(west, east, nblon, offset));
            offset += nblon;
        }
         (*matrix)->data_.resize(nb);
         (*matrix2)->data_.resize(nb);
    }
    double x = west;
    for (int i = 0; i < nblon; i++) {
        (*matrix)->columnsAxis().push_back(x);
        x = west + (i + 1) * lon;
    }

    (*matrix)->setMapsAxis();

    long jPointsAreConsecutive = grib.getLong("jPointsAreConsecutive");

    try {
        (*matrix)->resize(nb);
        size_t aux = size_t(nb);

        // if jPointsAreConsecutive=1 then the values represent columns of data instead
        // of rows, so we have to 'reshape' the array so that it is reorganised into rows.

        if (jPointsAreConsecutive) {
            vector<double> *d = new vector<double>(nb);  // temporary array
            double *d1 = &d->front();                 // temporary array pointer
            double *d2 = &(*matrix)->front();            // final array

            grib_get_double_array(grib.id(), "values", d1, &aux);

            for (int i = 0; i < nblon; i++) {
                for (int j = 0; j < nblat; j++) {
                    d2[j * nblon + i] = d1[i * nblat + j];
                }
            }
            delete d;

        } else  // otherwise, just copy the array of values as they are
        {


            if ( matrix2 != NULL ) {
                grib_get_double_array(grib.uHandle(), "values", &(*matrix)->front(),
                                    &aux);
                grib_get_double_array(grib.uHandle(), "values", &(*matrix)->data_.front(),
                                            &aux);
                grib_get_double_array(grib.vHandle(), "values", &(*matrix2)->front(),
                            &aux);
                grib_get_double_array(grib.vHandle(), "values", &(*matrix2)->data_.front(),
                                    &aux);
            }
            else
                grib_get_double_array(grib.handle(), "values", &(*matrix)->front(),
                                                    &aux);
        }
        for (int i = 0; i < nblon; i++) {
            double lon = (*matrix)->columnsAxis()[i];
            for (int j = 0; j < nblat; j++) {
                double lat = (*matrix)->rowsAxis()[j];


            }
        }
        (*matrix)->missing(missing);

    } catch (...) {
        throw MagicsException("GribRegularInterpretor - Not enough memory");
    }
   
}

void GribRotatedInterpretor::interpret2D(double& lat, double& lon, double& uc,
        double& vc) const {
    if (!uvRelativeToGrid_)
        return;
    double speed = sqrt((uc * uc) + (vc * vc));
    double angle = atan2(vc, uc);

    std::pair<double, double> pt = rotate(lat, lon);
    std::pair<double, double> pv = unrotate(pt.first, pt.second + 1);

    double rangle = atan2(pv.first - lat, pv.second - lon) + angle;
    //components.second *= f;
    // we the angle and the spped we compute u/v...
    uc = speed * cos(rangle);
    vc = speed * sin(rangle);
}

void GribRotatedInterpretor::raw(const GribDecoder& grib,
        const Transformation& transformation, const string& key,
        map<double, map<double, CustomisedPoint*> >& points) const {
    double factor, offset;
    scaling(grib, factor, offset);
    int err;
    southPoleLat_ = grib.getDouble("latitudeOfSouthernPoleInDegrees");
    southPoleLon_ = grib.getDouble("longitudeOfSouthernPoleInDegrees");
    angle_ = grib.getDouble("angleOfRotationInDegrees") * 180.0 / M_PI;
    ;
    grib_iterator* iter = grib_iterator_new(grib.handle(), 0, &err);
    double missing = grib.getDouble("missingValue");

    double lat, lon, value;
    /* Loop on all the lat/lon/values. */
    while (grib_iterator_next(iter, &lat, &lon, &value)) {

        pair<double, double> coords = unrotate(lat, lon);
        lat = coords.first;
        lon = coords.second;
        if (value != missing) {
            /*
             std::stack<UserPoint>   duplicates;
             UserPoint geo(lon, lat);
             value = (value*factor)+offset;
             transformation.populate(lon, lat, value, points);
             */
        }
    }
    /* At the end the iterator is deleted to free memory. */
    grib_iterator_delete(iter);
}

void GribLambertInterpretor::interpretAsMatrix(const GribDecoder& grib,
        Matrix** matrix, Matrix** matrix2) const {
    long im = grib.getLong("numberOfPointsAlongXAxis");
    long jm = grib.getLong("numberOfPointsAlongYAxis");

    *matrix = new Matrix(im, jm);

    size_t nb;
    grib_get_size(grib.id(), "values", &nb);

    MagLog::dev() << "numberOfFieldValues[" << nb << "]" << "\n";
    double missing = -std::numeric_limits<double>::max();
    missing = grib.getDouble("missingValue");

    double north = grib.getDouble("latitudeOfFirstGridPointInDegrees");
    double west = grib.getDouble("longitudeOfFirstGridPointInDegrees");

    MagLog::dev() << "NewAPI---> area[" << west << ", " << north << "]" << "\n";

    try {
        Timer time("Grib", "lambert");

        MagLog::debug() << "Version" << grib_get_api_version() << endl;

        vector<double> latm;
        vector<double> lonm;
        vector<double> data;
        latm.reserve(nb);
        lonm.reserve(nb);
        data.reserve(nb);

        size_t aux = size_t(nb);

        grib_get_double_array(grib.id(), "latitudes", &(latm.front()), &aux);

        double minlat = *min_element(latm.begin(), latm.end());
        double maxlat = *max_element(latm.begin(), latm.end());
        ;
        grib_get_double_array(grib.id(), "longitudes", &(lonm.front()), &aux);

        double minlon = *min_element(lonm.begin(), lonm.end());
        double maxlon = *max_element(lonm.begin(), lonm.end());
        ;

        // This test needs to be improved ...

        if (minlon > 50.)
            minlon -= 360;
        if (maxlon > 50.)
            maxlon -= 360;

        grib_get_double_array(grib.id(), "values", &(data.front()), &aux);



        for (int i = 0; i < nb; i++) {
            if (lonm[i] > 50.)
                lonm[i] = lonm[i] - 360;

            if (minlat > latm[i])
                minlat = latm[i];
            if (maxlat < latm[i])
                maxlat = latm[i];
            if (minlon > lonm[i])
                minlon = lonm[i];
            if (maxlon < lonm[i])
                maxlon = lonm[i];
        }

        MagLog::debug() << "lat [" << minlat << ", " << maxlat << "]"
                << std::endl;
        MagLog::debug() << "lon [" << minlon << ", " << maxlon << "]"
                << std::endl;

        vector<double>& lon = (*matrix)->columnsAxis();
        vector<double>& lat = (*matrix)->rowsAxis();

        // for the lon we take the fisrt line :
        double inci = (maxlon - minlon) / ((im) - 1);
        double incj = (maxlat - minlat) / ((jm) - 1);
        for (int i = 0; i < im; i++)
            lon.push_back(minlon + (i * inci));
        // for the lon we take the fisrt column :
        for (int i = 0; i < jm; i++)
            lat.push_back(minlat + (i * incj));

        typedef map<double, map<double, pair<int, int> > > Helper;

        //typedef map<double, double> Helper;
        Helper helper;
        int row = 0;
        for (vector<double>::iterator y = lat.begin(); y != lat.end(); ++y) {

            helper.insert(make_pair(*y, map<double, pair<int, int> >()));

            Helper::iterator h = helper.find(*y);

            int column = 0;
            for (vector<double>::iterator x = lon.begin(); x != lon.end();
                    ++x) {
                h->second.insert(make_pair(*x, std::make_pair(row, column)));

                (*matrix)->push_back(missing);
                column++;

            }
            row++;
        }

        double lat11, lat12, lat21, lat22;
        double lon11, lon12, lon21, lon22;
        double val11, val12, val21, val22;

        for (int r = 0; r < jm - 1; r++) {
            for (int c = 0; c < im - 1; c++) {

                lat11 = latm[c + (im * r)];

                lat12 = latm[(c + 1) + (im * r)];
                minlat = std::min(lat11, lat12);
                maxlat = std::max(lat11, lat12);
                lat21 = latm[c + (im * (r + 1))];
                minlat = std::min(minlat, lat21);
                maxlat = std::max(maxlat, lat21);
                lat22 = latm[(c + 1) + (im * (r + 1))];
                minlat = std::min(minlat, lat22);
                maxlat = std::max(maxlat, lat22);

                lon11 = lonm[c + (im * r)];
                lon12 = lonm[(c + 1) + (im * r)];
                if (lon12 < lon11)
                    lon12 += 360.;
                minlon = std::min(lon11, lon12);
                maxlon = std::max(lon11, lon12);
                lon21 = lonm[c + (im * (r + 1))];
                minlon = std::min(minlon, lon21);
                maxlon = std::max(maxlon, lon21);
                lon22 = lonm[(c + 1) + (im * (r + 1))];
                if (lon22 < lon21)
                    lon22 += 360.;
                minlon = std::min(minlon, lon22);
                maxlon = std::max(maxlon, lon22);

                val11 = data[c + (im * r)];
                val12 = data[(c + 1) + (im * r)];
                val21 = data[c + (im * (r + 1))];
                val22 = data[(c + 1) + (im * (r + 1))];

                // find the points from the helper!
                Helper::iterator low, up;
                low = helper.lower_bound(minlat);
                up = helper.lower_bound(maxlat);
                if (low == helper.end() || up == helper.end())
                    break;
                for (Helper::iterator it = low; it != up; ++it) {
                    if (it == helper.end())
                        break;
                    map<double, pair<int, int> >& lons = it->second;
                    map<double, pair<int, int> >::iterator llow =
                            lons.lower_bound(minlon);
                    map<double, pair<int, int> >::iterator lup =
                            lons.lower_bound(maxlon);
                    if (llow == lons.end() || lup == lons.end())
                        break;;
                    for (map<double, pair<int, int> >::iterator lit = llow;
                            lit != lup; ++lit) {

                        double lat = it->first;
                        double lon = lit->first;
                        std::pair<int, int> index = lit->second;

                        // we interpolate at the point using the 4 points found!
                        double val = missing;
                        if (val11 != missing && val12 != missing
                                && val21 != missing && val22 != missing) {
                            double val1 = ((lon12 - lon) / (lon12 - lon11))
                                    * val11
                                    + ((lon - lon11) / (lon12 - lon11)) * val12;

                            double val2 = ((lon22 - lon) / (lon22 - lon21))
                                    * val21
                                    + ((lon - lon21) / (lon22 - lon21)) * val22;
                            if (std::isnan(val1)) {
                                if (std::isnan(val2)) {
                                    val = missing;
                                } else
                                    val = ((lat - lat11) / (lat22 - lat11))
                                            * val2;
                            } else {
                                if (std::isnan(val2)) {
                                    val = ((lat22 - lat) / (lat22 - lat11))
                                            * val1;
                                } else {
                                    val = ((lat22 - lat) / (lat22 - lat11))
                                            * val1
                                            + ((lat - lat11) / (lat22 - lat11))
                                                    * val2;
                                }
                            }

                            if (std::isnan(val) || std::isinf(val) || std::isinf(-val)) {
                                val = missing;
                            }
                        }
                        if (std::isnan(val))
                            val = missing;
                        if ((**matrix)[index.second + (index.first * im)]
                                == missing) {
                            (**matrix)[index.second + (index.first * im)] = val;
                        }
                    }
                }
            }
            (*matrix)->setMapsAxis();
            (*matrix)->missing(missing);
        }

        MagLog::dev() << **matrix << "\n";
    }

    catch (MagicsException& e) {
        MagLog::error() << e << "\n";
    }
}

void GribLambertInterpretor::print(ostream& out) const {
    out << "GribLambertInterpretor[";
    out << "]";
}



PaperPoint GribLambertAzimutalInterpretor::reference(const GribDecoder&, const Transformation&)
{
    return PaperPoint();
}

void GribPolarStereoInterpretor::print(ostream& out) const {
    out << "GribLambertInterpretor[";
    out << "]";
}

void GribPolarStereoInterpretor::interpretAsMatrix(const GribDecoder& grib,
        Matrix** matrix, Matrix** matrix2) const {
    long im = 3600;
    long jm = 1800;

    *matrix = new Matrix(im, jm);
    double steplon= 0.1;
    double steplat= 0.1;

    double missing =  grib.getDouble("missingValue");
    for (int i = 0; i < im; i++) {
        double x = 0 + (i*steplon);
        (*matrix)->columnsAxis().push_back(x);
    }

    for (int i = 0; i < jm; i++) {
        double y = -90 + (i*steplat);
        (*matrix)->rowsAxis().push_back(y);
    }
    vector<double> distance(im*jm, 999999);

    for (int i = 0; i < im; i++) {
        for (int j = 0; j < jm; j++)
        (**matrix)[i + (j * im)] = missing;
    }
    (*matrix)->missing(missing);
    (*matrix)->setMapsAxis();

    interpolate(grib, **matrix);

    MagLog::dev() << **matrix << "\n";
}

void GribInterpretor::interpolate(const GribDecoder& grib, Matrix& matrix) const
{
    int err;

    grib_iterator* iter = grib_iterator_new(grib.handle(), 0, &err);
    if ( err ) {
        MagLog::warning() << "Grib Iterator not available : Chech Grib Api Version " << grib_get_api_version() << endl;
        return;
    }
    double xres = matrix.XResolution();
    double yres = matrix.YResolution();

    double xbase = matrix.left() - (xres/2);
    double ybase = matrix.bottom() - (yres/2);
    double columns = matrix.columns();
    double rows = matrix.rows();

    vector<double> distance(columns*rows, 999999);

    double lat, lon, value;
    /* Loop on all the lat/lon/values. */
    while (grib_iterator_next(iter, &lat, &lon, &value)) {
        int ix =  (lon - xbase )/xres;
        double x = (ix * xres) + xbase;
        int iy =  (lat - ybase )/yres;
        double y = (iy * yres) + ybase;
        double dist = ((lon - x)*(lon - x)) + ((lat - y)*(lat - y));
        if ( dist < distance[ix + (iy * columns)] ) {
            matrix[ix + (iy * columns)] = value;
            distance[ix + (iy * columns)]= dist;
        }
    }
    /* At the end the iterator is deleted to free memory. */
    grib_iterator_delete(iter);
}

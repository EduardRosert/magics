/*
 * (C) Copyright 1996-2016 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation
 * nor does it submit to any jurisdiction.
 */

#ifndef ProjP_H
#define ProjP_H

#include <proj.h>

#include "magics.h"

namespace magics {

class ProjP {
 public:
  ProjP();
  ProjP(const string&, const string&);
  ~ProjP();

  bool valid() const { return !converter_ || !reverter_; }

  static string error(int error) { return proj_errno_string(error); }

  virtual int convert(double&, double&);
  virtual int revert(double&, double&);

 protected:
  //! Method to print string about this class on to a stream of type ostream
  //! (virtual).
  virtual void print(ostream&) const;
  string from_;
  string to_;
  PJ* converter_;
  PJ* reverter_;

 private:
  //! Copy constructor - No copy allowed
  ProjP(const ProjP&);

  // -- Friends
  //! Overloaded << operator to call print().
  friend ostream& operator<<(ostream& s, const ProjP& p) {
    p.print(s);
    return s;
  }
};

class LatLonProjP : public ProjP {
 public:
  LatLonProjP(const string& to)
      : ProjP("+proj=longlat +ellps=WGS84 +datum=WGS84", to) {}
  int convert(double&, double&);
  int revert(double&, double&);
};

}  // namespace magics
#endif

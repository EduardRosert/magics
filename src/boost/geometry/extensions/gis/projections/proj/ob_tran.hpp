#ifndef BOOST_GEOMETRY_PROJECTIONS_OB_TRAN_HPP
#define BOOST_GEOMETRY_PROJECTIONS_OB_TRAN_HPP

// Boost.Geometry - extensions-gis-projections (based on PROJ4)
// This file is automatically generated. DO NOT EDIT.

// Copyright (c) 2008-2011 Barend Gehrels, Amsterdam, the Netherlands.

// Use, modification and distribution is subject to the Boost Software License,
// Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

// This file is converted from PROJ4, http://trac.osgeo.org/proj
// PROJ4 is originally written by Gerald Evenden (then of the USGS)
// PROJ4 is maintained by Frank Warmerdam
// PROJ4 is converted to Boost.Geometry by Barend Gehrels (Geodan, Amsterdam)

// Original copyright notice:

// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the "Software"),
// to deal in the Software without restriction, including without limitation
// the rights to use, copy, modify, merge, publish, distribute, sublicense,
// and/or sell copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included
// in all copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
// OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
// THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.

#include <boost/shared_ptr.hpp>
#include <boost/math/special_functions/hypot.hpp>

#include <boost/geometry/extensions/gis/projections/impl/base_static.hpp>
#include <boost/geometry/extensions/gis/projections/impl/base_dynamic.hpp>
#include <boost/geometry/extensions/gis/projections/impl/projects.hpp>
#include <boost/geometry/extensions/gis/projections/impl/factory_entry.hpp>

namespace boost { namespace geometry { namespace projection
{

    template <typename Geographic, typename Cartesian, typename Parameters> class factory;

    #ifndef DOXYGEN_NO_DETAIL
    namespace detail { namespace ob_tran{
            static const double TOL = 1e-10;

            template <typename Geographic, typename Cartesian>
            struct par_ob_tran
            {
                boost::shared_ptr<projection<Geographic, Cartesian> > link;
                double    lamp;
                double    cphip, sphip;
            };

            // template class, using CRTP to implement forward/inverse
            template <typename Geographic, typename Cartesian, typename Parameters>
            struct base_ob_tran_oblique : public base_t_fi<base_ob_tran_oblique<Geographic, Cartesian, Parameters>,
                     Geographic, Cartesian, Parameters>
            {

                 typedef double geographic_type;
                 typedef double cartesian_type;

                par_ob_tran<Geographic, Cartesian> m_proj_parm;

                inline base_ob_tran_oblique(const Parameters& par)
                    : base_t_fi<base_ob_tran_oblique<Geographic, Cartesian, Parameters>,
                     Geographic, Cartesian, Parameters>(*this, par) {}

                inline void fwd(geographic_type& lp_lon, geographic_type& lp_lat, cartesian_type& xy_x, cartesian_type& xy_y) const
                {
                    double coslam, sinphi, cosphi;



                    coslam = cos(lp_lon);
                    sinphi = sin(lp_lat);
                    cosphi = cos(lp_lat);
                    lp_lon = adjlon(aatan2(cosphi * sin(lp_lon), this->m_proj_parm.sphip * cosphi * coslam +
                        this->m_proj_parm.cphip * sinphi) + this->m_proj_parm.lamp);
                    lp_lat = aasin(this->m_proj_parm.sphip * sinphi - this->m_proj_parm.cphip * cosphi * coslam);
                    m_proj_parm.link->fwd(lp_lon, lp_lat, xy_x, xy_y);
                }

                inline void inv(cartesian_type& xy_x, cartesian_type& xy_y, geographic_type& lp_lon, geographic_type& lp_lat) const
                {
                    double coslam, sinphi, cosphi;

                    m_proj_parm.link->inv(xy_x, xy_y, lp_lon, lp_lat);
                    if (lp_lon != HUGE_VAL) {
                        coslam = cos(lp_lon -= this->m_proj_parm.lamp);
                        sinphi = sin(lp_lat);
                        cosphi = cos(lp_lat);
                        lp_lat = aasin(this->m_proj_parm.sphip * sinphi + this->m_proj_parm.cphip * cosphi * coslam);
                        lp_lon = aatan2(cosphi * sin(lp_lon), this->m_proj_parm.sphip * cosphi * coslam -
                            this->m_proj_parm.cphip * sinphi);
                    }
                }
            };

            // template class, using CRTP to implement forward/inverse
            template <typename Geographic, typename Cartesian, typename Parameters>
            struct base_ob_tran_transverse : public base_t_fi<base_ob_tran_transverse<Geographic, Cartesian, Parameters>,
                     Geographic, Cartesian, Parameters>
            {

                 typedef double geographic_type;
                 typedef double cartesian_type;

                par_ob_tran<Geographic, Cartesian> m_proj_parm;

                inline base_ob_tran_transverse(const Parameters& par)
                    : base_t_fi<base_ob_tran_transverse<Geographic, Cartesian, Parameters>,
                     Geographic, Cartesian, Parameters>(*this, par) {}

                inline void fwd(geographic_type& lp_lon, geographic_type& lp_lat, cartesian_type& xy_x, cartesian_type& xy_y) const
                {
                    double cosphi, coslam;



                    cosphi = cos(lp_lat);
                    coslam = cos(lp_lon);
                    lp_lon = adjlon(aatan2(cosphi * sin(lp_lon), sin(lp_lat)) + this->m_proj_parm.lamp);
                    lp_lat = aasin(- cosphi * coslam);
                    m_proj_parm.link->fwd(lp_lon, lp_lat, xy_x, xy_y);
                }

                inline void inv(cartesian_type& xy_x, cartesian_type& xy_y, geographic_type& lp_lon, geographic_type& lp_lat) const
                {
                    double cosphi, t;

                    m_proj_parm.link->inv(xy_x, xy_y, lp_lon, lp_lat);
                    if (lp_lon != HUGE_VAL) {
                        cosphi = cos(lp_lat);
                        t = lp_lon - this->m_proj_parm.lamp;
                        lp_lon = aatan2(cosphi * sin(t), - sin(lp_lat));
                        lp_lat = aasin(cosphi * cos(t));
                    }
                }
            };

            // General Oblique Transformation
            template <typename Geographic, typename Cartesian, typename Parameters>
            double setup_ob_tran(Parameters& par, par_ob_tran<Geographic, Cartesian>& proj_parm, bool create = true)
            {
                int i;
                double phip;


                Parameters pj;
                /* copy existing header into new */
                par.es = 0.;
             /* force to spherical */
                pj.params = par.params;
                pj.over = par.over;
                pj.geoc = par.geoc;
                pj.a = par.a;
                pj.es = par.es;
                pj.ra = par.ra;
                pj.lam0 = par.lam0;
                pj.phi0 = par.phi0;
                pj.x0 = par.x0;
                pj.y0 = par.y0;
                pj.k0 = par.k0;
                /* force spherical earth */
                pj.one_es = pj.rone_es = 1.;
                pj.es = pj.e = 0.;
                pj.name = pj_param(par.params, "so_proj").s;

                factory<Geographic, Cartesian, Parameters> fac;
                if (create)
                {
                    proj_parm.link.reset(fac.create_new(pj));
                    if (! proj_parm.link.get()) throw proj_exception(-26);
                }
                if (pj_param(par.params, "to_alpha").i) {
                    double lamc, phic, alpha;
                    lamc    = pj_param(par.params, "ro_lon_c").f;
                    phic    = pj_param(par.params, "ro_lat_c").f;
                    alpha    = pj_param(par.params, "ro_alpha").f;
            /*
                    if (fabs(phic) <= TOL ||
                        fabs(fabs(phic) - HALFPI) <= TOL ||
                        fabs(fabs(alpha) - HALFPI) <= TOL)
            */
                    if (fabs(fabs(phic) - HALFPI) <= TOL)
                        throw proj_exception(-32);
                    proj_parm.lamp = lamc + aatan2(-cos(alpha), -sin(alpha) * sin(phic));
                    phip = aasin(cos(phic) * sin(alpha));
                } else if (pj_param(par.params, "to_lat_p").i) { /* specified new pole */
                    proj_parm.lamp = pj_param(par.params, "ro_lon_p").f;
                    phip = pj_param(par.params, "ro_lat_p").f;
                } else { /* specified new "equator" points */
                    double lam1, lam2, phi1, phi2, con;
                    lam1 = pj_param(par.params, "ro_lon_1").f;
                    phi1 = pj_param(par.params, "ro_lat_1").f;
                    lam2 = pj_param(par.params, "ro_lon_2").f;
                    phi2 = pj_param(par.params, "ro_lat_2").f;
                    if (fabs(phi1 - phi2) <= TOL ||
                        (con = fabs(phi1)) <= TOL ||
                        fabs(con - HALFPI) <= TOL ||
                        fabs(fabs(phi2) - HALFPI) <= TOL) throw proj_exception(-33);
                    proj_parm.lamp = atan2(cos(phi1) * sin(phi2) * cos(lam1) -
                        sin(phi1) * cos(phi2) * cos(lam2),
                        sin(phi1) * cos(phi2) * sin(lam2) -
                        cos(phi1) * sin(phi2) * sin(lam1));
                    phip = atan(-cos(proj_parm.lamp - lam1) / tan(phi1));
                }
                if (fabs(phip) > TOL) { /* oblique */
                    proj_parm.cphip = cos(phip);
                    proj_parm.sphip = sin(phip);
                // par.fwd = o_forward;
                // par.inv = pj.inv ? o_inverse : 0;
                } else { /* transverse */
                // par.fwd = t_forward;
                // par.inv = pj.inv ? t_inverse : 0;
                }
                boost::ignore_unused_variable_warning(i);
                // return phip to choose model
                return phip;
            }

        }} // namespace detail::ob_tran
    #endif // doxygen

    /*!
        \brief General Oblique Transformation projection
        \ingroup projections
        \tparam Geographic latlong point type
        \tparam Cartesian xy point type
        \tparam Parameters parameter type
        \par Projection characteristics
         - Miscellaneous
         - Spheroid
         - o_proj= plus parameters for projection
         - o_lat_p= o_lon_p= (new pole) or
         - o_alpha= o_lon_c= o_lat_c= or
         - o_lon_1= o_lat_1= o_lon_2= o_lat_2=
        \par Example
        \image html ex_ob_tran.gif
    */
    template <typename Geographic, typename Cartesian, typename Parameters = parameters>
    struct ob_tran_oblique : public detail::ob_tran::base_ob_tran_oblique<Geographic, Cartesian, Parameters>
    {
        inline ob_tran_oblique(const Parameters& par) : detail::ob_tran::base_ob_tran_oblique<Geographic, Cartesian, Parameters>(par)
        {
            detail::ob_tran::setup_ob_tran(this->m_par, this->m_proj_parm);
        }
    };

    /*!
        \brief General Oblique Transformation projection
        \ingroup projections
        \tparam Geographic latlong point type
        \tparam Cartesian xy point type
        \tparam Parameters parameter type
        \par Projection characteristics
         - Miscellaneous
         - Spheroid
         - o_proj= plus parameters for projection
         - o_lat_p= o_lon_p= (new pole) or
         - o_alpha= o_lon_c= o_lat_c= or
         - o_lon_1= o_lat_1= o_lon_2= o_lat_2=
        \par Example
        \image html ex_ob_tran.gif
    */
    template <typename Geographic, typename Cartesian, typename Parameters = parameters>
    struct ob_tran_transverse : public detail::ob_tran::base_ob_tran_transverse<Geographic, Cartesian, Parameters>
    {
        inline ob_tran_transverse(const Parameters& par) : detail::ob_tran::base_ob_tran_transverse<Geographic, Cartesian, Parameters>(par)
        {
            detail::ob_tran::setup_ob_tran(this->m_par, this->m_proj_parm);
        }
    };

    #ifndef DOXYGEN_NO_DETAIL
    namespace detail
    {

        // Factory entry(s)
        template <typename Geographic, typename Cartesian, typename Parameters>
        class ob_tran_entry : public detail::factory_entry<Geographic, Cartesian, Parameters>
        {
            public :
                virtual projection<Geographic, Cartesian>* create_new(const Parameters& par) const
                {
                    detail::ob_tran::par_ob_tran<Geographic, Cartesian> proj_parm;
                    Parameters p = par;
                    double phip = setup_ob_tran(p, proj_parm, false);
                    if (fabs(phip) > detail::ob_tran::TOL)
                        return new base_v_fi<ob_tran_oblique<Geographic, Cartesian, Parameters>, Geographic, Cartesian, Parameters>(par);
                    else
                        return new base_v_fi<ob_tran_transverse<Geographic, Cartesian, Parameters>, Geographic, Cartesian, Parameters>(par);
                }
        };

        template <typename Geographic, typename Cartesian, typename Parameters>
        inline void ob_tran_init(detail::base_factory<Geographic, Cartesian, Parameters>& factory)
        {
            factory.add_to_factory("ob_tran", new ob_tran_entry<Geographic, Cartesian, Parameters>);
        }

    } // namespace detail
    #endif // doxygen

}}} // namespace boost::geometry::projection

#endif // BOOST_GEOMETRY_PROJECTIONS_OB_TRAN_HPP


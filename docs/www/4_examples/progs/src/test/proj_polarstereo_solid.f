C (C) Copyright 1996-2016 ECMWF.
C 
C This software is licensed under the terms of the Apache Licence Version 2.0
C which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
C In applying this licence, ECMWF does not waive the privileges and immunities 
C granted to it by virtue of its status as an intergovernmental organisation nor
C does it submit to any jurisdiction.
C

      PROGRAM POLARSTEREO

C     This program demonstrates magics contouring facilities. 
C     The meteorological data field is a standard global 500 hpa
C     model output field on a regular 1.5 degree grid. 
C     Contours and coastlines are projected onto a 
C     polar stereographic map.


C     Open MAGICS and set the output device

      CALL POPEN
      CALL PARSE_COMMAND_LINE ('proj_polarstereo_solid')


C     Set up the polar stereographic projection

      CALL PSETC ('SUBPAGE_MAP_PROJECTION', 'POLAR_STEREOGRAPHIC')


C     Set up the coastline attributes

      CALL PSETC ('MAP_COASTLINE_COLOUR', 'GREY')
      CALL PSETC ('MAP_GRID_COLOUR',      'GREY')     


C     Pass the data to MAGICS

      CALL PSETC ('GRIB_INPUT_TYPE',      'FILE')
      CALL PSETC ('GRIB_INPUT_FILE_NAME', 'data/z500.grb')
      CALL PSETC ('GRIB_SPECIFICATION',   'OFF')
#if defined (MAGPLUS)
      CALL PSETC ('GRIB_AUTOMATIC_SCALING', 'OFF')
#else
      CALL PSETC ('GRIB_SCALING', 'OFF')
#endif
      CALL PGRIB
      

C     Define the contour     

      CALL PSETC ('CONTOUR_SHADE',            'ON')
      call PSETC ('CONTOUR_SHADE_TECHNIQUE',  'POLYGON_SHADING')
      call PSETC ('CONTOUR_SHADE_METHOD',     'AREA_FILL')
      CALL PSETC ('CONTOUR_LINE_COLOUR',      'BLUE')
      CALL PSETC ('CONTOUR_HIGHLIGHT_COLOUR', 'BLUE')
      CALL PSETC ('CONTOUR_GRID_VALUE_PLOT',  'ON')
      CALL PSETC ('CONTOUR_GRID_VALUE_PLOT_TYPE', 'MARKER')
      CALL PSETI ('CONTOUR_GRID_VALUE_LAT_FREQUENCY', 4)
      CALL PSETI ('CONTOUR_GRID_VALUE_LON_FREQUENCY', 4)
      CALL PCONT
      

C     Set up and plot the title text

      CALL PSETR ('TEXT_REFERENCE_CHARACTER_HEIGHT', 1.0)
      CALL PSETC ('TEXT_LINE_1',
     +            'Polar Stereographic, Northern Hemisphere')
      CALL PSETI ('TEXT_LINE_COUNT',1)
      CALL PSETC ('TEXT_JUSTIFICATION','CENTRE')
      CALL PTEXT


C     Plot the coastlines

      CALL PCOAST


C     New page, this time using a different area specification
C     Area specification (SOUTH, WEST, NORTH, EAST )

      CALL PNEW  ('SUPER_PAGE')
      CALL PSETC ('SUBPAGE_MAP_AREA_DEFINITION', 'CENTRE')
      CALL PSETR ('SUBPAGE_MAP_CENTRE_LONGITUDE',  0.0)
      CALL PSETR ('SUBPAGE_MAP_CENTRE_LATITUDE',  50.0)
      CALL PSETC ('SUBPAGE_MAP_HEMISPHERE',      'NORTH')

      CALL PSETC ('TEXT_LINE_1',
     +            'Polar Stereographic Projection, section')

c      CALL PSETR ('SUBPAGE_LOWER_LEFT_LATITUDE',   -20.1)
c      CALL PSETR ('SUBPAGE_LOWER_LEFT_LONGITUDE',  -44.7)
c      CALL PSETR ('SUBPAGE_UPPER_RIGHT_LONGITUDE', 134.5)
c      CALL PSETR ('SUBPAGE_UPPER_RIGHT_LATITUDE',  -20.0)

      CALL PCONT
      CALL PTEXT
      CALL PCOAST


      CALL PCLOSE

      STOP
      END



#include "parse_command_line.h"

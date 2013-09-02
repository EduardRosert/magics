      PROGRAM VIEWS_LARGE_AREA

C     This program demonstrates magics contouring facilities. 
C     The meteorological data field is a standard global 500 hpa
C     model output field on a regular 1.5 degree grid. 
C     Contours and coastlines are projected onto a map.


C     Open MAGICS and set the output device

      CALL POPEN
      CALL PARSE_COMMAND_LINE ('views_large_area')


      CALL PSETR ('SUBPAGE_LOWER_LEFT_LATITUDE',    -60.0)
      CALL PSETR ('SUBPAGE_LOWER_LEFT_LONGITUDE',  -220.0)
      CALL PSETR ('SUBPAGE_UPPER_RIGHT_LATITUDE',    60.0)
      CALL PSETR ('SUBPAGE_UPPER_RIGHT_LONGITUDE',  350.0)



C     Pass the data to MAGICS

      CALL PSETC ('GRIB_INPUT_TYPE',      'FILE')
      CALL PSETC ('GRIB_INPUT_FILE_NAME', 'data/z500.grb')
      CALL PGRIB
      


C     Set up the coastline attributes

      CALL PSETR ('MAP_GRID_LATITUDE_INCREMENT',  30.0)  
      CALL PSETR ('MAP_GRID_LONGITUDE_INCREMENT', 90.0)  



C     Define the contour     

      CALL PSETC  ('CONTOUR_SHADE',            'ON')      
      CALL PSETC  ('CONTOUR_SHADE_TECHNIQUE',  'POLYGON_SHADING')
      CALL PSETC  ('CONTOUR_SHADE_METHOD',     'AREA_FILL')
      CALL PSETC  ('CONTOUR_HILO',             'OFF')
      CALL PSETC  ('CONTOUR_LABEL',            'OFF')
      CALL PCONT


C     Set up and plot the title text

      CALL PSETC ('TEXT_LINE_1',
     x            'Area greater than 360 degrees longitude')
      CALL PSETC ('TEXT_FONT',   'ARIAL')
      CALL PTEXT


C     Plot the coastlines and then close

      CALL PCOAST
      CALL PCLOSE

      STOP
      END



#include "parse_command_line.h"

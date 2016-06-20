C (C) Copyright 1996-2016 ECMWF.
C 
C This software is licensed under the terms of the Apache Licence Version 2.0
C which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
C In applying this licence, ECMWF does not waive the privileges and immunities 
C granted to it by virtue of its status as an intergovernmental organisation nor
C does it submit to any jurisdiction.
C

      PROGRAM WIND03
*
*     THIS PROGRAM DEMONSTRATES MAGICS WIND FIELD PLOTTING FACILITIES
*
*     THE METEOROLOGICAL DATA FIELDS ARE 500 hPa U/V FIELDS IN GRIB CODE
*     ON A 1.5 DEGREE GRID.
*
*     THE WIND FLAGS AND COASTLINES ARE PROJECTED ONTO THE
*     REQUIRED PROJECTION.
*
*     OPEN MAGICS
*
      CALL POPEN
      CALL PSETC ('PS_DEVICE',    'ps_a4')
      CALL PSETC ('PS_FILE_NAME', 'wind03.ps')
      CALL PSETC ('PAGE_ID_LINE_USER_TEXT','Tests/Wind03')
      CALL PSETR ('SUBPAGE_X_LENGTH',17.0)
      CALL PSETR ('SUBPAGE_Y_LENGTH',17.0)
      CALL PSETC ('SUBPAGE_MAP_PROJECTION','POLAR_STEREOGRAPHIC')
      CALL PSETC ('SUBPAGE_MAP_AREA_DEFINITION','CENTRE')
      CALL PSETR ('SUBPAGE_MAP_SCALE',75.E6)
*
*     PASS THE DATA TO MAGICS
*
      CALL PSETC ('GRIB_INPUT_FILE_NAME',
     x  'data/500uv.grb')
      CALL PSETI ('GRIB_WIND_POSITION_1',1)
      CALL PSETI ('GRIB_WIND_POSITION_2',2)
      CALL PGRIB
      CALL PSETR ('TEXT_REFERENCE_CHARACTER_HEIGHT',0.4)
      CALL PSETC ('TEXT_JUSTIFICATION','CENTRE')
      CALL PSETC ('WIND_FIELD_TYPE','FLAGS')
      CALL PSETC ('MAP_COASTLINE_COLOUR','GREEN')
      CALL PSETC ('MAP_GRID_COLOUR','GREEN')

*
*     PLOT WIND FLAGS ON NORTHERN HEMISPHERE POLAR STEREOGRAPHIC MAP
*
      CALL WIND03_ONE
      CALL PNEW ('PAGE')
*
*     WIND FLAGS ON POLAR STEREO MAP + THINNING FACTOR = 3.0 AND
*     FLAG ORIGIN MARKER = OFF
*
      CALL WIND03_TWO
      CALL PNEW ('PAGE')
*
*     PLOT WIND FLAGS ON POLAR STEREO MAP + WIND FLAG MIN SPEED = 16
*
      CALL WIND03_THREE
      CALL PNEW ('PAGE')
*
*     PLOT WIND FLAGS ON SELECTED EUROPEAN AREA + THINNING FACTOR = 1
*     FLAG LENGTH = 2 cm
*
      CALL WIND03_FOUR
      CALL PNEW ('PAGE')
*
*     PLOT WIND FLAGS ON SELECTED EUROPEAN AREA + FLAG THICKNESS = 4
*     CROSS BOUNDARY = OFF
*
      CALL WIND03_FIVE
      CALL PNEW ('PAGE')
*
*     PLOT WIND FLAGS ON SELECTED EUROPEAN AREA + WIND FLAG MODE = OFF_LEVEL
*     FLAG THICKNESS = 1, CROSS BOUNDARY = ON, FLAG LENGTH = 1 cm
*
      CALL WIND03_SIX
*
*     CLOSE MAGICS
*
      CALL PCLOSE
*
      END
      SUBROUTINE WIND03_ONE
*
*     THIS SUBROUTINE PLOTS WIND FLAGS AND COASTLINES ON A
*     FULL NORTHERN HEMISPHERE POLAR STEREOGRAPHIC MAP.
*     DEFAULT VALUES FOR ALL WIND FLAG PARAMETERS
*
*     CALL PSETR ('WIND_THINNING_FACTOR',5.0)
      CALL PSETC ('WIND_FLAG_ORIGIN_MARKER','OFF')
      CALL PSETC ('TEXT_LINE_1',
     1           'Northern Hemisphere Polar Stereographic -'//
     1           '10 metre U/V on a Gaussian (T511) grid')
      CALL PSETC ('TEXT_LINE_2',
     1           'Default Values for Wind Flag Parameters')
      CALL PSETI ('TEXT_LINE_COUNT',2)
*
*     PLOT THE TITLE, COASTLINES AND WIND FLAGS
*
      CALL PTEXT
      CALL PCOAST
      CALL PWIND
*
      RETURN
      END
      SUBROUTINE WIND03_TWO
*
*     THIS SUBROUTINE PLOTS WIND FLAGS FROM THE GAUSSIAN (T511)
*     FIELD ON A FULL POLAR STEREOGRAPHIC PROJECTION.
*     THE THINNING FACTOR IS SET TO 3.0 AND THE FLAG ORIGIN MARKER IS
*     TURNED OFF TO IMPROVE THE APPEARANCE OF THE WIND FLAGS.
*
*     ALL WIND PARAMETERS THAT ARE NOT SET IN THIS SUBROUTINE TAKE
*     THEIR DEFAULT VALUES.
*
      CALL PSETR ('WIND_THINNING_FACTOR',3.0)
      CALL PSETC ('WIND_FLAG_ORIGIN_MARKER','OFF')
*
      CALL PSETC ('TEXT_LINE_1',
     1           'Northern Hemisphere Polar Stereographic -'//
     1           '10 metre U/V on a Gaussian (T511) grid')
      CALL PSETC ('TEXT_LINE_2',
     1 '+ Thinning factor = 3.0, Flag Origin Marker = OFF' )
      CALL PSETI ('TEXT_LINE_COUNT',2)
*
*     PLOT TITLE, COASTLINES AND WIND FLAGS
*
      CALL PTEXT
      CALL PCOAST
      CALL PWIND
*
      RETURN
      END
      SUBROUTINE WIND03_THREE
*
*     THIS SUBROUTINE PLOTS WIND FLAGS FROM THE GAUSSIAN (T511)
*     FIELD ON A POLAR STEREOGRAPHIC PROJECTION. 
*     THE WIND FLAG MINIMUM SPEED IS SET TO 16.0
*
      CALL PSETR ('WIND_FLAG_MIN_SPEED',16.0)             
*
      CALL PSETC ('TEXT_LINE_1',
     1           'Northern Hemisphere Polar Stereographic -'//
     1           '10 metre U/V on a Gaussian (T511) grid')
      CALL PSETC ('TEXT_LINE_2',
     1 '+ Thinning factor = 3.0, Flag Origin Marker = OFF' )
      CALL PSETC ('TEXT_LINE_3',
     1  ' + Wind Flag Min Speed = 16.0')
      CALL PSETI ('TEXT_LINE_COUNT',3)
*
*     PLOT THE TITLE, COASTLINES AND WIND FLAGS
*
      CALL PTEXT
      CALL PCOAST
      CALL PWIND
*
      RETURN
      END
      SUBROUTINE WIND03_FOUR
*
*     THIS SUBROUTINE PLOTS WIND FLAGS ON A SELECTED AREA EUROPEAN
*     AREA + THINNING FACTOR =1 AND FLAG LENGTH SET TO 2 cm.
*
      CALL PSETR ('SUBPAGE_X_LENGTH',26.)
      CALL PSETR ('SUBPAGE_MAP_CENTRE_LATITUDE',50.0)
      CALL PSETR ('SUBPAGE_MAP_CENTRE_LONGITUDE',10.0)
      CALL PSETR ('SUBPAGE_MAP_VERTICAL_LONGITUDE',10.0)
      CALL PSETR ('SUBPAGE_MAP_SCALE',10.E6)
*
      CALL PSETR ('WIND_THINNING_FACTOR',1.0)
      CALL PRESET ('WIND_FLAG_MIN_SPEED')             
      CALL PSETR ('WIND_FLAG_LENGTH',2.0)                 
*
      CALL PSETC ('TEXT_LINE_1',
     1           'Northern Hemisphere Polar Stereographic -'//
     1           '10 metre U/V on a Gaussian (T511) grid')
      CALL PSETC ('TEXT_LINE_2',
     1 '+ Flag Length = 2.0 cm, Thinning factor = 1.0, ')

      CALL PSETI ('TEXT_LINE_COUNT',2)
*
*     PLOT THE TITLE, COASTLINES AND WIND FLAGS
*
      CALL PTEXT
      CALL PCOAST
      CALL PWIND
*
      RETURN
      END
      SUBROUTINE WIND03_FIVE
*
*     THIS SUBROUTINE PLOTS WIND FLAGS ON A SELECTED AREA EUROPEAN
*     THE WIND FLAG THICKNESS IS SET TO 4 AND CROSS BOUNDARY IS OFF
*
      CALL PSETI ('WIND_FLAG_THICKNESS',4)       
      CALL PSETC ('WIND_FLAG_CROSS_BOUNDARY','OFF')
*
      CALL PSETC ('TEXT_LINE_1',
     1           'Northern Hemisphere Polar Stereographic -'//
     1           '10 metre U/V on a Gaussian (T511) grid')
      CALL PSETC ('TEXT_LINE_2',
     1 '+ Flag Length = 2.0 cm, Thinning factor = 1.0, ')
      CALL PSETC ('TEXT_LINE_3',
     2           '+ Flag Thickness = 4, '//
     2           'Cross Boundary = OFF ')
      CALL PSETI ('TEXT_LINE_COUNT',3)
*
*     PLOT THE TITLE, COASTLINES AND WIND FLAGS
*
      CALL PTEXT
      CALL PCOAST
      CALL PWIND
      RETURN
      END
      SUBROUTINE WIND03_SIX
*
*     THIS SUBROUTINE PLOTS WIND FLAGS ON A SELECTED AREA EUROPEAN
*     WIND FLAG MODE IS SET TO OFF_LEVEL, CROSS BOUNDARY IS ON,
*     FLAG THICKNESS IS 1 AND FLAG LENGTH IS 1 cm.
*
      CALL PSETI ('WIND_FLAG_THICKNESS',1)       
      CALL PSETC ('WIND_FLAG_CROSS_BOUNDARY','ON')
      CALL PSETC ('WIND_FLAG_MODE','OFF_LEVEL')           
      CALL PSETR ('WIND_FLAG_LENGTH',1.0)                 
*
      CALL PSETC ('TEXT_LINE_1',
     1           'Northern Hemisphere Polar Stereographic -'//
     1           '10 metre U/V on a Gaussian (T511) grid')
      CALL PSETC ('TEXT_LINE_2',
     2           'Wind Flag Mode = OFF_LEVEL, '//
     2           'Flag Thickness = 1, ')
      CALL PSETC ('TEXT_LINE_3',
     1           'Flag Length = 2.0 cm, '//
     1           'Cross Boundary = ON ')
      CALL PSETI ('TEXT_LINE_COUNT',3)
*
*     PLOT THE TITLE, COASTLINES AND WIND FLAGS
*
      CALL PTEXT
      CALL PCOAST
      CALL PWIND
      RETURN
      END

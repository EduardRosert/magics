C (C) Copyright 1996-2016 ECMWF.
C 
C This software is licensed under the terms of the Apache Licence Version 2.0
C which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
C In applying this licence, ECMWF does not waive the privileges and immunities 
C granted to it by virtue of its status as an intergovernmental organisation nor
C does it submit to any jurisdiction.
C

      PROGRAM SYMB02

*
*     SYMBOL PLOTTING EXAMPLE
*   
*     USING SYMBOL PLOTTING TO PLOT THE NAMES OF THE CAPITAL
*     CITIES OF EUROPE AND THEIR POSITIONS (WITH MARKERS)
*
      CALL POPEN 
      CALL PARSE_COMMAND_LINE ('symb02')
*
*     PLOT POLAR MAP OF EUROPE
*     ------------------------
      CALL PSETC('SYMBOL_POSITION_MODE','GEOGRAPHIC')
      CALL PSETC('SUBPAGE_MAP_PROJECTION','POLAR_STEREOGRAPHIC')
      CALL PSETC('SUBPAGE_MAP_AREA_DEFINITION','CENTRE')
      CALL PSETR('SUBPAGE_MAP_CENTRE_LATITUDE',50.0)     
      CALL PSETR('SUBPAGE_MAP_CENTRE_LONGITUDE',10.0)     
      CALL PSETR('SUBPAGE_MAP_VERTICAL_LONGITUDE',0.0)     
      CALL PSETR('SUBPAGE_MAP_SCALE',22.E6)     
      CALL PSETC('SYMBOL_QUALITY','HIGH')
      CALL PSETC('MAP_COASTLINE_COLOUR','BLACK')
      CALL PSETC('MAP_COASTLINE_RESOLUTION','HIGH')
      CALL PSETC('MAP_COASTLINE_LAND_SHADE','ON')
      CALL PSETC('MAP_COASTLINE_LAND_SHADE_COLOUR','CREAM')
      CALL PSETC('MAP_GRID_COLOUR','BLACK')
      CALL PCOAST
*
*     PLOT THE NAMES
*     --------------
      CALL SYMB02_ONE
*
*     PLOT THE POSITIONS
*     ------------------
      CALL SYMB02_TWO
      CALL PSETC('TEXT_JUSTIFICATION','CENTRE')
      CALL PSETC('TEXT_LINE_1',
     x 'MAGICS Symbol plotting using TEXT and MARKER options')
      CALL PSETI('TEXT_LINE_COUNT',1)
      CALL PTEXT
      CALL PCLOSE
      STOP
      END
      SUBROUTINE SYMB02_ONE
*
*     PLOT CITY NAMES
*     ---------------
      CHARACTER*32 TEX
      DIMENSION X(29),Y(29),TEX(29)
      DATA TEX/'Oslo','London','Wien','Ankara','Lisboa','Bruxelles',
     X  'Reykjavic','Madrid','Bern','Koebenhavn','Dublin',
     X   'The Hague','Athens','Paris','Helsinki','Roma','Bonn',
     X   'Stockholm',11*' '/
      DATA X/10.63,0.0,16.34,32.88,-9.13,4.53,-21.9,-3.72,7.5,
     X       12.53,-6.25,4.25,23.73,2.33,25.05,12.58,7.2,17.95,
     X       11*0.0/
      DATA Y/59.90,51.5,48.23,39.95,38.77,50.90,64.13,40.45,46.92,
     X       55.77,52.43,52.15,37.9,48.83,60.25,41.78,50.7,59.65,
     X       11*0.0/
      INUM=5
*
*     ADJUST POSITIONS OF NAMES TO AVOID CLUTTERING
*     ---------------------------------------------
      DO 100 J=1,29
         Y(J)=Y(J)+0.75
100   CONTINUE
      Y(2)=y(2)+0.25
      Y(12)=y(12)+0.25
      Y(17)=y(17)-1.25
*
*     PLOT SOME CITIES IN RED
*     -----------------------
      CALL PSETC('SYMBOL_TABLE_MODE','OFF')
      CALL PSETR('SYMBOL_HEIGHT',0.4)
      CALL PSETC('SYMBOL_TYPE','TEXT')
      CALL PSET1C('SYMBOL_INPUT_TEXT_LIST',TEX,INUM)
      CALL PSET1R('SYMBOL_INPUT_X_POSITION',X,INUM)
      CALL PSET1R('SYMBOL_INPUT_Y_POSITION',Y,INUM)
      CALL PSETC('SYMBOL_COLOUR','RED')
      CALL PSYMB
*
*     PLOT SOME CITIES IN BLUE
*     ------------------------
      CALL PSET1C('SYMBOL_INPUT_TEXT_LIST',TEX(6),INUM)
      CALL PSET1R('SYMBOL_INPUT_X_POSITION',X(6),INUM)
      CALL PSET1R('SYMBOL_INPUT_Y_POSITION',Y(6),INUM)
      CALL PSETC('SYMBOL_COLOUR','BLUE')
      CALL PSYMB
*
*     PLOT SOME CITIES IN GREEN
*     -------------------------
      CALL PSET1C('SYMBOL_INPUT_TEXT_LIST',TEX(11),INUM)
      CALL PSET1R('SYMBOL_INPUT_X_POSITION',X(11),INUM)
      CALL PSET1R('SYMBOL_INPUT_Y_POSITION',Y(11),INUM)
      CALL PSETC('SYMBOL_COLOUR','GREEN')
      CALL PSYMB
*
*     PLOT SOME CITIES IN MAGENTA
*     ---------------------------
      INUM=3
      CALL PSET1C('SYMBOL_INPUT_TEXT_LIST',TEX(16),INUM)
      CALL PSET1R('SYMBOL_INPUT_X_POSITION',X(16),INUM)
      CALL PSET1R('SYMBOL_INPUT_Y_POSITION',Y(16),INUM)
      CALL PSETC('SYMBOL_COLOUR','MAGENTA')
      CALL PSYMB
      RETURN
      END
      SUBROUTINE SYMB02_TWO
*
*     PLOT CITY POSITIONS
*     -------------------
      CHARACTER*32 XCLTAB,XTX
      DIMENSION XMNTAB(4),XMXTAB(4),XCLTAB(4),XHGTAB(4)
      DIMENSION X(29),Y(29),XNUM(29),ISYM(4)
      DATA ISYM/4*18/
      DATA XNUM/5.,5.,5.,5.,5.,15.,15.,15.,15.,15.,25.,25.,25.,
     X          25.,25.,35.,35.,35.,11*0.0/
      DATA XHGTAB/0.2,0.2,0.2,0.2/
      DATA XMNTAB/1.,11,21.,31./
      DATA XMXTAB/10.,20,30.,40./
      DATA XCLTAB/'RED','BLUE','GREEN','MAGENTA'/
      DATA X/10.63,0.0,16.34,32.88,-9.13,4.53,-21.9,-3.72,7.5,
     X       12.53,-6.25,4.25,23.73,2.33,25.05,12.58,7.2,17.95,
     X       11*0.0/
      DATA Y/59.90,51.5,48.23,39.95,38.77,50.90,64.13,40.45,46.92,
     X       55.77,52.43,52.15,37.9,48.83,60.25,41.78,50.7,59.65,
     X       11*0.0/
      INUM=18
*
*     USE 'TABLE' MODE TO PLOT DIFFERENT COLOURED SYMBOLS
*     ---------------------------------------------------
      CALL PSETC('SYMBOL_TABLE_MODE','ON')
      CALL PSET1R('SYMBOL_INPUT_X_POSITION',X,INUM)
      CALL PSET1R('SYMBOL_INPUT_Y_POSITION',Y,INUM)
      CALL PSET1R('SYMBOL_INPUT_NUMBER_LIST',XNUM,INUM)
      CALL PSETC('SYMBOL_TYPE','MARKER')
      CALL PSET1I('SYMBOL_MARKER_TABLE',ISYM,4)
      CALL PSET1R('SYMBOL_MIN_TABLE',XMNTAB,4)
      CALL PSET1R('SYMBOL_MAX_TABLE',XMXTAB,4)
      CALL PSET1C('SYMBOL_COLOUR_TABLE',XCLTAB,4)
      CALL PSET1R('SYMBOL_HEIGHT_TABLE',XHGTAB,4)
      CALL PSYMB
      RETURN
      END

#include "parse_command_line.h"

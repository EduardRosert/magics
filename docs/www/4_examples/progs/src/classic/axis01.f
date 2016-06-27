C (C) Copyright 1996-2016 ECMWF.
C 
C This software is licensed under the terms of the Apache Licence Version 2.0
C which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
C In applying this licence, ECMWF does not waive the privileges and immunities 
C granted to it by virtue of its status as an intergovernmental organisation nor
C does it submit to any jurisdiction.
C

 	PROGRAM AXIS01
C
C	THIS PROGRAM DEMONSTRATES AXIS PLOTTING
C
C	OPEN MAGICS
C
	CALL POPEN
	CALL PSETC ('PS_DEVICE','ps_a4')
	CALL PSETC ('PS_FILE_NAME','axis01.ps')
	CALL PSETC ('PAGE_ID_LINE_USER_TEXT','TESTS/AXIS01')
	CALL PSETC ('SUBPAGE_FRAME','OFF')
	CALL PSETC ('SUBPAGE_MAP_PROJECTION','NONE')
C
C	SET PAGE LAYOUT VALUES
C
	CALL PSETR ('SUBPAGE_X_POSITION',4.0)
	CALL PSETR ('SUBPAGE_Y_POSITION',5.0)
	CALL PSETR ('SUBPAGE_X_LENGTH',21.0)
	CALL PSETR ('SUBPAGE_Y_LENGTH',13.0)
C
C	PLOT DEFAULT REGULAR AND LOGARITHMIC AXIS
C
	CALL AXIS01_ONE
	CALL PNEW ('PAGE')
C
C	PLOT USER LABELS AND TICKS
C

	CALL AXIS01_TWO
	CALL PNEW ('PAGE')
C
C	PLOT MULTIPLE AXES AND LAT/LONG LABELLING
C
	CALL AXIS01_THREE
	CALL PNEW ('PAGE')
C
C	PLOT GRID AND AXIS LINE
C
	CALL AXIS01_FOUR
	CALL PNEW ('PAGE')
C
C	PLOT SIMPLE DATE/TIME AXIS
C
	CALL AXIS01_FIVE
	CALL PNEW ('PAGE')
C
C	XXX - NOT FOR DOCUMENTATION - START XXX
C	PLOT LONGER DATE/TIME AXIS
C
	CALL AXIS01_SIX
C	XXX - NOT FOR DOCUMENTATION - END XXX
C
C	CLOSE MAGICS
C
	CALL PCLOSE
C
	END
	SUBROUTINE AXIS01_ONE
C
C	DRAW REGULAR AXIS WITH MOSTLY DEFAULT VALUES
C
	CALL PSETR ('AXIS_MIN_VALUE',1.0)
	CALL PSETR ('AXIS_MAX_VALUE',9.0)
	CALL PSETC ('AXIS_TITLE_TEXT','Simple REGULAR Axis')
	CALL PAXIS
C
C	DRAW LOGARITHMIC AXIS WITH MOSTLY DEFAULT VALUES
C
	CALL PSETC ('AXIS_ORIENTATION','VERTICAL')
	CALL PSETC ('AXIS_TYPE','LOGARITHMIC')
	CALL PSETR ('AXIS_MIN_VALUE',0.1)
	CALL PSETR ('AXIS_MAX_VALUE',500.0)
	CALL PSETC ('AXIS_TITLE_TEXT','Simple LOGARITHMIC Axis')
	CALL PAXIS
C
C	RESET SOME PARAMETERS
C
	CALL PRESET ('AXIS_TYPE')
	CALL PRESET ('AXIS_TITLE_TEXT')
C
	RETURN
	END
	SUBROUTINE AXIS01_TWO
C
	CHARACTER*9 MONTHS
	DIMENSION MONTHS(3)
	DATA MONTHS/'APRIL','MAY','JUNE'/
C
C	USER LABELS AND TIP TITLE TEXT
C
	CALL PSETC ('AXIS_ORIENTATION','HORIZONTAL')
	CALL PSETR ('AXIS_MIN_VALUE',1.0)
	CALL PSETR ('AXIS_MAX_VALUE',4.0)
	CALL PSETR ('AXIS_TICK_INTERVAL',1.0)
	CALL PSETC ('AXIS_TICK_LABEL_TYPE','LABEL_LIST')
	CALL PSET1C ('AXIS_TICK_LABEL_LIST',MONTHS,3)
	CALL PSETC ('AXIS_TICK_LABEL_POSITION','INTER_TICK')
	CALL PSETC ('AXIS_TIP_TITLE','ON')
	CALL PSETC ('AXIS_TIP_TITLE_TEXT','1987')
	CALL PAXIS
C
C	ADJUST TICK MARKS AND MINOR TICKS MARKS
C
	CALL PSETC ('AXIS_ORIENTATION','VERTICAL')
	CALL PSETR ('AXIS_MIN_VALUE',3.5)
	CALL PSETR ('AXIS_MAX_VALUE',8.0)
	CALL PSETR ('AXIS_TICK_INTERVAL',0.25)
	CALL PSETC ('AXIS_TICK_LABEL_TYPE','NUMBER')
	CALL PSETC ('AXIS_TICK_LABEL_POSITION','ON_TICK')
	CALL PSETC ('AXIS_TICK_LABEL_FORMAT','(F3.1)')
	CALL PSETI ('AXIS_TICK_LABEL_FREQUENCY',2)
	CALL PSETC ('AXIS_MINOR_TICK','ON')
	CALL PSETI ('AXIS_MINOR_TICK_COUNT',5)
	CALL PSETC ('AXIS_TIP_TITLE','OFF')
	CALL PSETC ('AXIS_TITLE_TEXT','Forecast Days')
	CALL PAXIS
C
C	RESET SOME PARAMETERS
C
	CALL PRESET ('AXIS_TICK_LABEL_FORMAT')
	CALL PRESET ('AXIS_TICK_LABEL_FREQUENCY')
	CALL PRESET ('AXIS_MINOR_TICK')
	CALL PRESET ('AXIS_MINOR_TICK_COUNT')
C
	RETURN
	END
	SUBROUTINE AXIS01_THREE
C
C	PLOT HORIZONTAL LATITUDE AXIS.
C
	CALL PSETC ('AXIS_ORIENTATION','HORIZONTAL')
	CALL PSETR ('AXIS_MIN_VALUE',56.0)
	CALL PSETR ('AXIS_MAX_VALUE',38.0)
	CALL PSETR ('AXIS_TICK_INTERVAL',2.0)
	CALL PSETC ('AXIS_MINOR_TICK','ON')
	CALL PSETI ('AXIS_MINOR_TICK_COUNT',1)
	CALL PSETC ('AXIS_TICK_LABEL_TYPE','LATITUDE')
	CALL PSETC ('AXIS_TITLE','OFF')
	CALL PSETC ('AXIS_TIP_TITLE','ON')
	CALL PSETC ('AXIS_TIP_TITLE_TEXT','Lat')
	CALL PAXIS
C
C	PLOT HORIZONTAL LONGITUDE AXIS.
C
	CALL PSETR ('AXIS_MIN_VALUE',-42.0)
	CALL PSETR ('AXIS_MAX_VALUE',-28.0)
	CALL PSETR ('AXIS_TICK_INTERVAL',1.0)
	CALL PSETC ('AXIS_MINOR_TICK','OFF')
	CALL PSETC ('AXIS_TICK_LABEL_TYPE','LONGITUDE')
	CALL PSETC ('AXIS_TIP_TITLE_TEXT','Lon')
	CALL PAXIS
C
C	PLOT VERTICAL PRESSURE AXIS
C
	CALL PSETC ('AXIS_ORIENTATION','VERTICAL')
	CALL PSETR ('AXIS_MIN_VALUE',1050.0)
	CALL PSETR ('AXIS_MAX_VALUE',100.0)
	CALL PSETR ('AXIS_TICK_INTERVAL',100.0)
	CALL PSETC ('AXIS_TICK_LABEL_TYPE','NUMBER')
	CALL PSETC ('AXIS_TICK_LABEL_LAST','OFF')
	CALL PSETC ('AXIS_TITLE','ON')
	CALL PSETC ('AXIS_TITLE_TEXT','Pressure')
	CALL PSETC ('AXIS_TIP_TITLE','ON')
	CALL PSETC ('AXIS_TIP_TITLE_TEXT','hPa')
	CALL PAXIS
C
C	ADD CONTOURING
C
	CALL PSETC ('CONTOUR_HILO','OFF')
	CALL PSETR ('CONTOUR_INTERVAL',10.0)
C	CALL PCONT
C
C	RESET SOME PARAMETERS
C
	CALL PRESET ('AXIS_TICK_LABEL_LAST')
	CALL PRESET ('AXIS_TIP_TITLE')
C
	RETURN
	END
	SUBROUTINE AXIS01_FOUR
C
	DIMENSION ZPOS(5),YSTNS(5)
	CHARACTER*10 YSTNS
	DATA ZPOS/3.0,6.5,9.0,14.0,17.7/
	DATA YSTNS/'KEFLAVIK','SHIPI','SHIPJ','SHIPK','LAJES'/
C
C	PLOT USER DEFINED TICK POSITIONS AND GRID
C
	CALL PSETC ('AXIS_ORIENTATION','HORIZONTAL')
	CALL PSETC ('AXIS_POSITION','BOTTOM')
	CALL PSETC ('AXIS_TYPE','POSITION_LIST')
	CALL PSET1R ('AXIS_TICK_POSITION_LIST',ZPOS,5)
	CALL PSET1C ('AXIS_TICK_LABEL_LIST',YSTNS,5)
	CALL PSETC ('AXIS_GRID','ON')
	CALL PSETC ('AXIS_TITLE','OFF')
	CALL PAXIS
C
C	PLOT LOGARITHMIC GRID
C
	CALL PSETC ('AXIS_ORIENTATION','VERTICAL')
	CALL PSETC ('AXIS_POSITION','RIGHT')
	CALL PSETC ('AXIS_TYPE','LOGARITHMIC')
	CALL PSETR ('AXIS_MIN_VALUE',1000.0)
	CALL PSETR ('AXIS_MAX_VALUE',100.0)
	CALL PSETC ('AXIS_TICK','OFF')
	CALL PSETC ('AXIS_LINE','OFF')
	CALL PSETC ('AXIS_TITLE','ON')
	CALL PSETC ('AXIS_TITLE_ORIENTATION','HORIZONTAL')
	CALL PSETC ('AXIS_TITLE_TEXT','hPa')
	CALL PAXIS
C
	CALL PRESET ('AXIS_LINE')
	CALL PRESET ('AXIS_TICK')
	CALL PRESET ('AXIS_GRID')
	RETURN
	END
	SUBROUTINE AXIS01_FIVE
C
C	SIMPLE PROGRAM TO PLOT A DATE/TIME AXIS
C

	CALL PSETC ('AXIS_ORIENTATION','HORIZONTAL')
	CALL PSETC ('AXIS_POSITION','BOTTOM')        
C
C	SET THE DATE/TIME AXIS SYSTEM
C
	CALL PSETC ('AXIS_TYPE','DATE')
	CALL PSETC('AXIS_DATE_TYPE','DAYS')         
	CALL PSETC('AXIS_DATE_MIN_VALUE','1998-04-21')     
	CALL PSETC('AXIS_DATE_MAX_VALUE','1998-06-10')     
	CALL PSETR('AXIS_TICK_INTERVAL',1.0)        
	CALL PSETC ('AXIS_TITLE_TEXT','DATE/TIME Axes')
	CALL PAXIS 
	CALL PSETC ('AXIS_ORIENTATION','VERTICAL')
	CALL PSETC ('AXIS_POSITION','LEFT')
	CALL PSETC ('AXIS_TYPE','DATE')
	CALL PSETC('AXIS_DATE_TYPE','MONTHS')         
	CALL PSETC('AXIS_DATE_MIN_VALUE','1998-04-21')     
	CALL PSETC('AXIS_DATE_MAX_VALUE','2001-06-10')     
	CALL PSETR('AXIS_TICK_INTERVAL',1.0)        
	CALL PSETC('AXIS_TITLE','OFF')                     
	CALL PAXIS 
	RETURN     
	END
C
C
C	XXX - NOT FOR DOCUMENTATION - START XXX

	SUBROUTINE AXIS01_SIX
C	SIMPLE PROGRAM TO PLOT A DATE/TIME AXIS
C

	CALL PSETC ('AXIS_ORIENTATION','HORIZONTAL')
	CALL PSETC ('AXIS_POSITION','BOTTOM')        
C
C	SET THE DATE/TIME AXIS SYSTEM
C
	CALL PSETC ('AXIS_TYPE','DATE')
	CALL PSETC('AXIS_DATE_TYPE','DAYS')         
	CALL PSETC('AXIS_DATE_MIN_VALUE','1998-04-21 18:00')     
	CALL PSETC('AXIS_DATE_MAX_VALUE','1998-05-10 00:00')     
	CALL PSETR('AXIS_TICK_INTERVAL',1.0)        
	CALL PSETC('AXIS_TITLE','ON')
	CALL PSETC ('AXIS_TITLE_TEXT','DATE/TIME Axes')
	CALL PAXIS 
	CALL PSETC ('AXIS_ORIENTATION','VERTICAL')
	CALL PSETC ('AXIS_POSITION','LEFT')
	CALL PSETC ('AXIS_TYPE','DATE')
	CALL PSETC('AXIS_DATE_TYPE','MONTHS')         
	CALL PSETC('AXIS_DATE_MIN_VALUE','1998-04-21')     
	CALL PSETC('AXIS_DATE_MAX_VALUE','2001-06-10')     
	CALL PSETR('AXIS_TICK_INTERVAL',1.0)        
	CALL PSETC('AXIS_TITLE','OFF')                     
	CALL PAXIS 
	RETURN     
	END
C	XXX - NOT FOR DOCUMENTATION - END XXX

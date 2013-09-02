	PROGRAM LGND02
C
C	THIS PROGRAM DEMONSTRATES MAGICS LEGEND FACILITIES. 
C
C	OPEN MAGICS
C
	CALL POPEN
	CALL PSETC ('PS_DEVICE','ps_a4')
	CALL PSETC ('PS_FILE_NAME','legend02.ps')
	CALL PSETC ('PAGE_ID_LINE_USER_TEXT','Tests/Lgnd02')
C
C	DEFINE MAP AREA AND PROJECTION
C
	CALL PSETC ('SUBPAGE_MAP_PROJECTION','POLAR_STEREOGRAPHIC')
	CALL PSETC ('SUBPAGE_MAP_AREA_DEFINITION','CENTRE')
	CALL PSETR ('SUBPAGE_MAP_CENTRE_LATITUDE',50.0)
	CALL PSETR ('SUBPAGE_MAP_CENTRE_LONGITUDE',10.0)
	CALL PSETR ('SUBPAGE_MAP_VERTICAL_LONGITUDE',10.0)
	CALL PSETR ('SUBPAGE_MAP_SCALE',25.E6)
C
C	PASS THE DATA TO MAGICS
C
	CALL PSETC ('GRIB_INPUT_TYPE','FILE')
	CALL PSETC ('GRIB_INPUT_FILE_NAME',
     x 'data/oldts/500Z.grb')
	CALL PGRIB
C
C	PLOT THE CONTOURS AND COASTLINES
C
	CALL PSETC ('CONTOUR_SHADE','ON')
	CALL PSETC ('CONTOUR_SHADE_METHOD','AREA_FILL')
	CALL PSETC ('LEGEND','ON')
	CALL PSETC ('LEGEND_DISPLAY_TYPE','CONTINUOUS')
	CALL PCONT
	CALL PCOAST
C
C	GENERATE TEXT FOR TITLE
C
	CALL PSETC ('TEXT_LINE_1','500 hPa Geopotential Height FIeld')
	CALL PSETC ('TEXT_LINE_2','Example of CONTINUOUS Legend')
	CALL PSETI ('TEXT_LINE_COUNT',2)
	CALL PSETC ('TEXT_JUSTIFICATION','CENTRE')
	CALL PTEXT
	CALL PCLOSE
C
	STOP
	END





	PROGRAM SYMB01
C
C	PGRAM TO DEMONSTRATE THE FEATURES OF SYMBOL PLOTTING
C
C	OPEN MAGICS
C
	CALL POPEN
	CALL PSETC ('PS_DEVICE','ps_a4')
 	CALL PSETC ('PS_FILE_NAME','symb01.ps')
	CALL PSETC ('PAGE_ID_LINE_USER_TEXT','/Tests/Symb01')
C
C	DEFINE PLOT AREA
C
	CALL PSETR ('SUBPAGE_LOWER_LEFT_LATITUDE',0.0)
	CALL PSETR ('SUBPAGE_UPPER_RIGHT_LATITUDE',90.0)
	CALL PSETR ('SUBPAGE_LOWER_LEFT_LONGITUDE',-90.0)
	CALL PSETR ('SUBPAGE_UPPER_RIGHT_LONGITUDE',90.0)
	CALL PSETC ('MAP_COASTLINE_COLOUR','GOLD')
	CALL PSETC ('MAP_GRID','OFF') 
C
C	PLOT NUMBERS IN INDIVIDUAL AND TABLE MODE
C
	CALL SYMB01_ONE
	CALL PNEW ('PAGE') 
	CALL SYMB01_TWO
C
C	PLOT TEXT IN INDIVIDUAL AND TABLE MODE
C
	CALL PNEW ('PAGE') 
	CALL SYMB01_THREE
	CALL PNEW ('PAGE') 
	CALL SYMB01_FOUR
C
C	PLOT MARKERS IN INDIVIDUAL AND TABLE MODE
C
	CALL PNEW ('PAGE') 
	CALL SYMB01_FIVE
	CALL PNEW ('PAGE') 
	CALL SYMB01_SIX
C
C	PLOT WIND FLAGS AND ARROWS IN INDIVIDUAL MODE
C
	CALL PNEW ('PAGE') 
	CALL SYMB01_SEVEN
	CALL PNEW ('PAGE') 
	CALL SYMB01_EIGHT
C
C	PLOT WIND FLAGS AND ARROWS IN INDIVIDUAL MODE
C	ON AITOFF PROJECTION
C
	CALL PNEW ('PAGE') 
	CALL PSETC ('SUBPAGE_MAP_PROJECTION','AITOFF')
	CALL SYMB01_SEVEN
	CALL PNEW ('PAGE') 
	CALL PSETR ('WIND_ARROW_UNIT_VELOCITY',50.0)
	CALL SYMB01_EIGHT
C
C	CLOSE MAGICS
C 
	CALL PCLOSE 
	STOP 
	END 
	SUBROUTINE SYMB01_ONE
C
C	PLOT NUMBERS IN INDIVIDUAL MODE
C
	DIMENSION X(10),Y(10),RAR (10) 
C
C	DEFINE LAT/LON POSITIONS
C
	DATA X/10.0,30.0,-20.,-40.,0.,-50.,-60.,-30.,20.,40./ 
	DATA Y/40.0,40.0,40.,40.,40.,50.,50.,50.,50.,50./ 
	DATA RAR/2.5,4.,6.,8.,10.,12.,14.,16.,18.,20./ 

	CALL PSETC ('SYMBOL_TYPE','NUMBER') 
	CALL PSET1R ('SYMBOL_INPUT_NUMBER_LIST',RAR,10) 
	CALL PSET1R ('SYMBOL_INPUT_X_POSITION',X,10) 
	CALL PSET1R ('SYMBOL_INPUT_Y_POSITION',Y,10) 
C
C	INDIVIDUAL SETTING OF COLOUR, HEIGHT
C
	CALL PSETC ('SYMBOL_COLOUR','MAGENTA') 
	CALL PSETR ('SYMBOL_HEIGHT',0.5) 
	CALL PSETC ('SYMBOL_TABLE_MODE','OFF') 
C
C	SET TEXT
C
	CALL PSETC ('TEXT_LINE_1',
     X  'Symbol Plotting - NUMBER Plotting in INDIVIDUAL mode') 
C
C	PLOT COASTLINES, SYMBOLS AND TEXT
C
	CALL PCOAST
	CALL PSYMB 
	CALL PTEXT 

	RETURN 
	END 
	SUBROUTINE SYMB01_TWO
C
C	PLOT NUMBERS IN TABLE MODE
C
	CHARACTER*10 CTAB 
	DIMENSION ZRAR (10) 
	DIMENSION HTAB(8),CTAB(8),XMNTAB(8),XMXTAB(8) 
	DIMENSION XX(10),YY(10) 
C
C	NUMBER LIST AND MIN/MAX TABLES
C
	DATA ZRAR/2.5,4.,6.,8.,10.,12.,14.,16.,7.,13./ 
	DATA XMNTAB/1.,3.,5.,7.,9.,11.,13.,15./ 
	DATA XMXTAB/3.,5.,7.,9.,11.,13.,15.,17./ 
C
C	HEIGHT/COLOUR TABLES
C
	DATA HTAB/0.3,0.25,0.2,0.15,0.35,0.4,0.5,0.22/ 
	DATA CTAB/'RED','YELLOW','GREEN','MAGENTA','BLUE','RED',
     X        'CYAN','BLUE'/ 
C
C	DEFINE LAT/LON POSITIONS
C
	DATA XX/-25.0,-25.0,-25.,-25.,-25.,25.,25.,25.,25.,25./ 
	DATA YY/20.0,30.0,40.,50.,60.,20.,30.,40.,50.,60./ 
	CALL PSET1R ('SYMBOL_INPUT_X_POSITION',XX,10) 
	CALL PSET1R ('SYMBOL_INPUT_Y_POSITION',YY,10) 
	CALL PSETC ('SYMBOL_TYPE','NUMBER') 
	CALL PSET1R ('SYMBOL_INPUT_NUMBER_LIST',ZRAR,10) 
C
C	TABLE MODE 
C 
	CALL PSETC ('SYMBOL_TABLE_MODE','ON') 
	CALL PSET1R ('SYMBOL_MAX_TABLE',XMXTAB,8) 
	CALL PSET1R ('SYMBOL_MIN_TABLE',XMNTAB,8) 
	CALL PSET1C ('SYMBOL_COLOUR_TABLE',CTAB,8) 
	CALL PSET1R ('SYMBOL_HEIGHT_TABLE',HTAB,8) 
	CALL PSETC ('TEXT_LINE_1',
     X'Symbol Plotting - NUMBER Plotting in TABLE Mode') 
C
C	PLOT COASTLINES, TEXT AND SYMBOLS
C
	CALL PCOAST
	CALL PTEXT 
	CALL PSYMB 
	RETURN
	END 
	SUBROUTINE SYMB01_THREE
C
C	PLOT TEXT IN INDIVIDUAL MODE
C
	CHARACTER*10 TEXLIS 
	DIMENSION XX(10),YY(10),TEXLIS(10) 
C
C	ARRAY OF TEXT
C
	DATA TEXLIS /'IN','NOT','IS','TEXT','THIS','MODE',
     X'INDIVIDUAL','BUT IN','MODE','TABLE'/ 
C
C	LAT/LON POSITIONS
C
	DATA XX/-25.0,-25.0,-25.,-25.,-25.,25.,25.,25.,25.,25./ 
	DATA YY/20.0,30.0,40.,50.,60.,20.,30.,40.,50.,60./ 

	CALL PSET1R ('SYMBOL_INPUT_X_POSITION',XX,10) 
	CALL PSET1R ('SYMBOL_INPUT_Y_POSITION',YY,10) 
C
C	INDIVIDUAL MODE 
C
	CALL PSETC ('SYMBOL_TABLE_MODE','OFF') 
	CALL PSETC ('SYMBOL_TYPE','TEXT') 
	CALL PSET1C ('SYMBOL_INPUT_TEXT_LIST',TEXLIS,10) 
C
C	SET TEXT
C
	CALL PSETC ('TEXT_LINE_1',
     X  'Symbol Plotting - TEXT Plotting in INDIVIDUAL Mode')
C
C	PLOT COASTLINES, TEXT AND SYMBOLS
C
	CALL PCOAST 
	CALL PTEXT
	CALL PSYMB 
	RETURN 
	END
	SUBROUTINE SYMB01_FOUR
C
C	PLOT TEXT IN TABLE MODE
C
	CHARACTER*10 CTAB,TEXTAB 
	DIMENSION XX(10),YY(10),TEXTAB(8) 
	DIMENSION BRAR (10) 
	DIMENSION HTAB(8),CTAB(8),XMXTAB(8),XMNTAB(8)
C
C	NUMBER LIST
C
	DATA BRAR/2.5,4.,6.,8.,10.,12.,14.,6.,16.,1./ 
C
C	MAX/MIN TABLES + HEIGH AND COLOUR TABLES
C
	DATA XMNTAB/1.,3.,5.,7.,9.,11.,13.,15./ 
	DATA XMXTAB/3.,5.,7.,9.,11.,13.,15.,17./ 
	DATA HTAB/0.3,0.25,0.15,0.2,0.35,0.4,0.6,0.22/ 
	DATA CTAB/'RED','YELLOW','GREEN','MAGENTA','BLUE','RED',
     X  'CYAN','BLUE'/ 
C
C	TEXT TABLE AND LAT/LON POSITIONS
C
	DATA TEXTAB/'PLOT','TEST','A','IS','THIS','OF TEXT',
     X'TEST PLOT','IS ALSO'/ 
	DATA XX/-25.0,-25.0,-25.,-25.,-25.,25.,25.,25.,25.,25./ 
	DATA YY/20.0,30.0,40.,50.,60.,20.,30.,40.,50.,60./ 
	CALL PSET1R ('SYMBOL_INPUT_X_POSITION',XX,10) 
	CALL PSET1R ('SYMBOL_INPUT_Y_POSITION',YY,10) 
C	
C	TABLE MODE 
C
	CALL PSETC ('SYMBOL_TABLE_MODE','ON') 
	CALL PSET1R ('SYMBOL_INPUT_NUMBER_LIST',BRAR,10) 
	CALL PSETC ('SYMBOL_TYPE','TEXT') 
	CALL PSET1C ('SYMBOL_TEXT_TABLE',TEXTAB,8) 
	CALL PSET1R ('SYMBOL_MAX_TABLE',XMXTAB,8) 
	CALL PSET1R ('SYMBOL_MIN_TABLE',XMNTAB,8) 
	CALL PSET1C ('SYMBOL_COLOUR_TABLE',CTAB,8) 
	CALL PSET1R ('SYMBOL_HEIGHT_TABLE',HTAB,8) 
	CALL PSETC ('TEXT_LINE_1',
     X 'Symbol Plotting - TEXT Plotting in TABLE Mode') 
C
C	PLOT COASTLINES, TEXT AND SYMBOLS
C
	CALL PCOAST
	CALL PTEXT
	CALL PSYMB 
	RETURN 
	END 
	SUBROUTINE SYMB01_FIVE
C
C	PLOT MARKERS IN INDIVIDUAL MODE
C
	DIMENSION XX(10),YY(10) 
	DIMENSION IMAR (10) 
C
C	LIST OF MARKER INDICES AND LAT/LON POSITIONS
C
	DATA IMAR/1,2,3,4,5,6,7,8,9,10/ 
	DATA XX/-25.0,-25.0,-25.,-25.,-25.,25.,25.,25.,25.,25./ 
	DATA YY/20.0,30.0,40.,50.,60.,20.,30.,40.,50.,60./ 

	CALL PSET1R ('SYMBOL_INPUT_X_POSITION',XX,10) 
	CALL PSET1R ('SYMBOL_INPUT_Y_POSITION',YY,10) 
	CALL PSETC ('SYMBOL_TABLE_MODE','OFF') 
	CALL PSETC ('LEGEND','OFF') 
	CALL PSETC ('LEGEND_ENTRY','OFF') 
	CALL PSETC ('SYMBOL_TYPE','MARKER') 
	CALL PSET1I ('SYMBOL_INPUT_MARKER_LIST',IMAR,10) 
	CALL PSETC ('SYMBOL_COLOUR','GREEN') 
	CALL PSETR ('SYMBOL_HEIGHT',0.4) 
C
C	SET TEXT
C
	CALL PSETC ('TEXT_LINE_1',
     X 'Symbol Plotting - MARKER Plotting in INDIVIDUAL Mode') 
C
C	PLOT COASTLINES, TEXT AND SYMBOLS
C
	CALL PCOAST 
	CALL PTEXT 
	CALL PSYMB 
	RETURN 
	END 
	SUBROUTINE SYMB01_SIX
C
C	PLOT MARKERS IN TABLE MODE
C
	CHARACTER*10 CTAB
	DIMENSION XX(10),YY(10) 
	DIMENSION XRAR (10) 
	DIMENSION HTAB(8),CTAB(8),ISTAB(8),XMXTAB(8),XMNTAB(8)
C
C	NUMBER LIST
C
	DATA XRAR/2.5,4.,6.,8.,10.,12.,14.,16.,5.25,11./ 

C	MAX/MIN TABLES + HEIGHT, COLOUR AND SYMBOL TABLES
C
	DATA XMNTAB/1.,3.,5.,7.,9.,11.,13.,15./ 
	DATA XMXTAB/3.,5.,7.,9.,11.,13.,15.,17./ 
	DATA HTAB/0.3,0.25,0.15,0.1,0.35,0.4,0.5,0.22/ 
	DATA CTAB/'RED','YELLOW','GREEN','MAGENTA','BLUE','RED',
     X         'CYAN','BLUE'/ 
	DATA ISTAB/18,18,18,9,11,2,1,4/
C
C	LAT/LON POSITIONS
C
	DATA XX/-25.0,-25.0,-25.,-25.,-25.,25.,25.,25.,25.,25./ 
	DATA YY/20.0,30.0,40.,50.,60.,20.,30.,40.,50.,60./ 
C
C	TABLE MODE - LEGEND ON
C	 
	CALL PSETC ('SYMBOL_TABLE_MODE','ON') 
	CALL PSETC ('LEGEND','ON') 
	CALL PSETC ('LEGEND_ENTRY','ON') 
	CALL PSET1R ('SYMBOL_INPUT_X_POSITION',XX,10) 
	CALL PSET1R ('SYMBOL_INPUT_Y_POSITION',YY,10) 
	CALL PSET1R ('SYMBOL_INPUT_NUMBER_LIST',XRAR,10) 
	CALL PSETC ('SYMBOL_TYPE','MARKER') 
	CALL PSET1I ('SYMBOL_MARKER_TABLE',ISTAB,8) 
	CALL PSET1R ('SYMBOL_MAX_TABLE',XMXTAB,8) 
	CALL PSET1R ('SYMBOL_MIN_TABLE',XMNTAB,8) 
	CALL PSET1C ('SYMBOL_COLOUR_TABLE',CTAB,8) 
	CALL PSET1R ('SYMBOL_HEIGHT_TABLE',HTAB,8) 
	CALL PSETC ('TEXT_LINE_1',
     X 'Symbol Plotting - MARKER Plotting in TABLE Mode') 
C
C	PLOT COASTLINES, TEXT AND SYMBOLS
C
	CALL PCOAST 
	CALL PTEXT
	CALL PSYMB 
	RETURN
	END 
	SUBROUTINE SYMB01_SEVEN
C
C	PLOT WIND FLAGS IN INDIVIDUAL MODE
C
	DIMENSION XX(10),YY(10) 
	DIMENSION SPE(10),DIR (10)
C
C	LIST OF WIND SPEED/DIRECTIONS + LAT/LON POSITIONS
C
	DATA SPE/5.,10.,15.,20.,25.,30.,35.,40.,45.,52./
	DATA DIR/0.,30.,60.,90.,120.,160.,200.,250.,290.,330./
	DATA XX/-25.0,-25.0,-25.,-25.,-25.,25.,25.,25.,25.,25./ 
	DATA YY/20.0,30.0,40.,50.,60.,20.,30.,40.,50.,60./ 

	CALL PSET1R ('SYMBOL_INPUT_X_POSITION',XX,10) 
	CALL PSET1R ('SYMBOL_INPUT_Y_POSITION',YY,10) 
C
C	INDIVIDAL MODE - LEGEND OFF
C
	CALL PSETC ('SYMBOL_TABLE_MODE','OFF') 
	CALL PSETC ('LEGEND','OFF') 
	CALL PSETC ('LEGEND_ENTRY','OFF') 
	CALL PSETC ('SYMBOL_TYPE','WIND') 
	CALL PSETC ('WIND_FIELD_TYPE','FLAGS')
	CALL PSET1R ('SYMBOL_INPUT_WIND_SPEED',SPE,10) 
	CALL PSET1R ('SYMBOL_INPUT_WIND_DIRECTION',DIR,10) 
C
C	SET HEIGHT AND COLOUR FOR INDIVIDUAL MODE
C
	CALL PSETC ('SYMBOL_COLOUR','GREEN') 
	CALL PSETR ('SYMBOL_HEIGHT',0.4) 
C
C	SET TEXT
C
	CALL PSETC ('TEXT_LINE_1',
     X 'Symbol Plotting - WIND Plotting in INDIVIDUAL Mode') 
C
C	PLOT COASTLINES, TEXT AND SYMBOLS
C
	CALL PCOAST 
	CALL PTEXT 
	CALL PSYMB 
	RETURN 
	END
	SUBROUTINE SYMB01_EIGHT
C
C	PLOT WIND ARROWS IN INDIVIDUAL MODE
C
	DIMENSION XX(10),YY(10) 
	DIMENSION SPE(10),DIR (10)
C
C	LIST OF WIND SPEED/DIRECTIONS AND LAT/LON POSITIONS
C
	DATA SPE/5.,10.,15.,20.,25.,30.,35.,40.,45.,52./
	DATA DIR/0.,30.,60.,90.,120.,160.,200.,250.,290.,330./
	DATA XX/-25.0,-25.0,-25.,-25.,-25.,25.,25.,25.,25.,25./ 
	DATA YY/20.0,30.0,40.,50.,60.,20.,30.,40.,50.,60./ 

	CALL PSET1R ('SYMBOL_INPUT_X_POSITION',XX,10) 
	CALL PSET1R ('SYMBOL_INPUT_Y_POSITION',YY,10) 
C
C	INDIVIDAL MODE - LEGEND OFF
C
	CALL PSETC ('SYMBOL_TABLE_MODE','OFF') 
	CALL PSETC ('LEGEND','OFF') 
	CALL PSETC ('LEGEND_ENTRY','OFF') 
	CALL PSETC ('SYMBOL_TYPE','WIND') 
	CALL PSETC ('WIND_FIELD_TYPE','ARROWS')
	CALL PSET1R ('SYMBOL_INPUT_WIND_SPEED',SPE,10) 
	CALL PSET1R ('SYMBOL_INPUT_WIND_DIRECTION',DIR,10) 
C
C	SET HEIGHT AND COLOUR FOR INDIVIDUAL MODE
C
	CALL PSETC ('SYMBOL_COLOUR','GREEN') 
	CALL PSETR ('SYMBOL_HEIGHT',0.4) 
C
C	SET TEXT
C
	CALL PSETC ('TEXT_LINE_1',
     X 'Symbol Plotting - WIND Plotting in TABLE Mode') 
C
C	PLOT COASTLINE, TEXT AND SYMBOLS
C
	CALL PCOAST 
	CALL PTEXT 
	CALL PSYMB 
	RETURN 
	END 

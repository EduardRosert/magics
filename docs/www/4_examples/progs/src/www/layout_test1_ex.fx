      PROGRAM LAYOUT_TEST
C
C     MAGICS PAGE LAYOUT FACILITIES.  THIS EXAMPLE PRODUCES TWO
C     SUPERPAGES.  THE FIRST SUPERPAGE CONTAINS A SINGLE PAGE, AND THIS
C     PAGE CONTAINS A SINGLE SUBPAGE.  THE SECOND SUPERPAGE CONTAINS
C     TWO PAGES.  THE FIRST PAGE CONTAINS A SINGLE SUBPAGE AND THE
C     SECOND PAGE CONTAINS TWO SUBPAGES.
C
C
C     OPEN MAGICS
C
*include "work.h"
	CALL POPEN
	CALL PSETC ('PS_DEVICE','ps_a4')
	CALL PSETC ('PS_FILE_NAME','layout_test1.ps')
	CALL PSETR ('SUPER_PAGE_Y_LENGTH',29.7)
	CALL PSETR ('SUPER_PAGE_X_LENGTH',21.0)
	CALL PSETR ('PAGE_Y_LENGTH',14.85)
	CALL PSETR ('PAGE_X_LENGTH',21.0)
	CALL PSETC ('PAGE_ID_LINE_USER_TEXT','layout_test1_ex')
	CALL PSETC ('MAP_COASTLINE_COLOUR','GREEN')
	CALL PSETC ('MAP_GRID_COLOUR','GREEN')
C
C     FIRST SUPER-PAGE.
C
	CALL PSETC ('TEXT_LINE_1','Plot Layout Example')
	CALL PCOAST
	CALL PTEXT
	CALL PSETC ('TEXT_LINE_1','Page One')
	CALL PSETC ('TEXT_MODE','POSITIONAL')    
	CALL PSETC ('TEXT_BORDER','ON')    
	CALL PSETC ('TEXT_BOX_BLANKING','ON')    
	CALL PSETR ('TEXT_BOX_X_POSITION',8.0)   
	CALL PSETR ('TEXT_BOX_Y_POSITION',13.0)   
	CALL PSETR ('TEXT_BOX_X_LENGTH',5.0)     
	CALL PSETR ('TEXT_BOX_Y_LENGTH',1.5)     
	CALL PTEXT
	CALL PSETC ('TEXT_LINE_1','Subpage One')
	CALL PSETR ('TEXT_BOX_X_POSITION',9.0)   
	CALL PSETR ('TEXT_BOX_Y_POSITION',8.0)   
	CALL PSETR ('TEXT_BOX_X_LENGTH',3.5)     
	CALL PSETR ('TEXT_BOX_Y_LENGTH',1.0)     
	CALL PTEXT
	CALL PSETC ('SUPER_PAGE_FRAME','ON')
	CALL PNEW  ('PAGE')
	CALL PSETC ('SUBPAGE_FRAME','OFF')
	CALL PSETC ('PAGE_ID_LINE','OFF')
	CALL PSETC ('TEXT_LINE_1','Super-Page One')
	CALL PSETR ('TEXT_BOX_X_POSITION',4.0)   
	CALL PSETR ('TEXT_BOX_Y_POSITION',12.0)   
	CALL PSETR ('TEXT_BOX_X_LENGTH',13.0)     
	CALL PSETR ('TEXT_BOX_Y_LENGTH',2.5)     
	CALL PTEXT	
CALL PNEW  ('SUPER_PAGE')
C
C     SECOND SUPER-PAGE.
C
C     PLOT FIRST PAGE, WHICH HAS ONE SUBPAGE
C
CALL PSETC ('PAGE_ID_LINE','ON')
CALL PSETC ('SUBPAGE_FRAME','ON')
CALL PSETC ('TEXT_MODE','TITLE')    
CALL PSETC ('TEXT_BORDER','OFF')    
CALL PCOAST
CALL PSETC ('TEXT_LINE_1','Plot Layout Example')
CALL PTEXT
CALL PSETC ('TEXT_LINE_1','Page One')
CALL PSETC ('TEXT_MODE','POSITIONAL')    
CALL PSETC ('TEXT_BOX_BLANKING','ON')    
CALL PSETR ('TEXT_BOX_X_POSITION',8.0)   
CALL PSETR ('TEXT_BOX_Y_POSITION',13.0)   
CALL PSETR ('TEXT_BOX_X_LENGTH',5.0)     
CALL PSETR ('TEXT_BOX_Y_LENGTH',1.2)     
CALL PSETC ('TEXT_BORDER','ON')    
CALL PTEXT
CALL PSETC ('TEXT_LINE_1','Subpage One')
CALL PSETR ('TEXT_BOX_X_POSITION',9.0)   
CALL PSETR ('TEXT_BOX_Y_POSITION',8.0)   
CALL PSETR ('TEXT_BOX_X_LENGTH',3.5)     
CALL PSETR ('TEXT_BOX_Y_LENGTH',1.0)     
CALL PTEXT
CALL PNEW  ('PAGE')
C
C     PLOT SECOND PAGE, WHICH HAS TWO SUBPAGES
C
CALL PSETR ('SUBPAGE_X_LENGTH',8.25)
CALL PSETR ('SUBPAGE_Y_LENGTH',8.25)
CALL PSETR ('SUBPAGE_X_POSITION',1.5)
CALL PSETR ('SUBPAGE_Y_POSITION',1.5)
CALL PSETR ('SUBPAGE_UPPER_RIGHT_LONGITUDE',0.0)
CALL PSETC ('TEXT_MODE','TITLE')    
CALL PSETC ('TEXT_BORDER','OFF')    
CALL PSETC ('TEXT_LINE_1','Plot Layout Example')
CALL PCOAST
CALL PTEXT
CALL PNEW  ('SUBPAGE')
C
CALL PSETR ('SUBPAGE_X_POSITION',11.5)
CALL PSETR ('SUBPAGE_UPPER_RIGHT_LONGITUDE',180.0)
CALL PSETR ('SUBPAGE_LOWER_LEFT_LONGITUDE',0.0)
CALL PCOAST
CALL PTEXT
CALL PSETC ('TEXT_LINE_1','Page Two')
CALL PSETC ('TEXT_MODE','POSITIONAL')    
CALL PSETC ('TEXT_BORDER','ON')    
CALL PSETC ('TEXT_BOX_BLANKING','ON')    
CALL PSETR ('TEXT_BOX_X_POSITION',8.0)   
CALL PSETR ('TEXT_BOX_Y_POSITION',11.3)   
CALL PSETR ('TEXT_BOX_X_LENGTH',5.0)     
CALL PSETR ('TEXT_BOX_Y_LENGTH',1.2)     
CALL PTEXT
CALL PSETC ('TEXT_LINE_1','Super-Page Two')
CALL PSETR ('TEXT_BOX_X_POSITION',4.0)   
CALL PSETR ('TEXT_BOX_Y_POSITION',12.8)   
CALL PSETR ('TEXT_BOX_X_LENGTH',13.0)     
CALL PSETR ('TEXT_BOX_Y_LENGTH',1.9)     
CALL PTEXT
CALL PSETC ('TEXT_LINE_1','Subpage One')
CALL PSETR ('TEXT_BOX_X_POSITION',3.9)   
CALL PSETR ('TEXT_BOX_Y_POSITION',8.0)   
CALL PSETR ('TEXT_BOX_X_LENGTH',3.5)     
CALL PSETR ('TEXT_BOX_Y_LENGTH',1.0)     
CALL PTEXT
CALL PSETC ('TEXT_LINE_1','Subpage two')
CALL PSETR ('TEXT_BOX_X_POSITION',13.2)   
CALL PSETR ('TEXT_BOX_Y_POSITION',8.0)   
CALL PSETR ('TEXT_BOX_X_LENGTH',3.5)     
CALL PSETR ('TEXT_BOX_Y_LENGTH',1.0)     
CALL PTEXT
C
C     CLOSE MAGICS
C
	CALL PCLOSE
C
      END

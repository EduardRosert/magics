#include <magics_api.h>

int main()
{
    /* Set up our level and colour lists */
    
    double adLevels [] = 
    {-20.0, 0.0, 10.0, 20.0, 30.0, 40.0, 50.0, 60.0, 70.0, 80.0, 90.0, 100.0, 120.0};

    char *aszColours [] = 
    {"RGB(1,0,0)",     "RGB(0,0,1)",      "RGB(0.05,0.05,1)", "RGB(0.1,0.1,1)",
     "RGB(0.2,0.2,1)", "RGB(0.3,0.3,1)",  "RGB(0.4,0.4,1)",   "RGB(0.5,0.5,1)",
     "RGB(0.6,0.6,1)", "RGB(0.7,0.7,1)",  "RGB(0.8,0.8,1)",   "RGB(0.9,0.9,1)",
     "RGB(0,1,0)"
    };

    int nNumLevels  = sizeof (adLevels)   / sizeof (double);
    int nNumColours = sizeof (aszColours) / sizeof (char *);



    /* open magics and set the output device */

    mag_open ();
    mag_setc ("output_format",    "ps");
    mag_setc ("output_name",      "cont_solidshade_test2");


    /* set up the coastline attributes */

    mag_setc ("map_coastline_colour", "grey");
    mag_setc ("map_grid_colour",      "grey");     



    /* Set up the text attributes */

    mag_seti ("TEXT_LINE_COUNT", 3);


    /* Define the contour attributes */

    mag_setc  ("LEGEND",                       "ON");
    mag_setc  ("CONTOUR_LEVEL_SELECTION_TYPE", "LEVEL_LIST");
    mag_set1r ("CONTOUR_LEVEL_LIST",            adLevels, nNumLevels);  
    mag_setc  ("CONTOUR_LINE_COLOUR",          "BLUE");
    mag_setc  ("CONTOUR_HIGHLIGHT_COLOUR",     "BLUE");
    mag_setc  ("CONTOUR_SHADE",                "ON");
    mag_setc  ("CONTOUR_SHADE_TECHNIQUE",      "POLYGON_SHADING");
    mag_setc  ("CONTOUR_SHADE_METHOD",         "AREA_FILL");
    mag_setc  ("CONTOUR_SHADE_COLOUR_METHOD",  "LIST");
    mag_set1c ("CONTOUR_SHADE_COLOUR_LIST",     aszColours, nNumColours);


    /* load the data */

    mag_setc ("grib_input_type",      "file");
    mag_setc ("grib_input_file_name", "data/rh850.grib");
    mag_setc ("GRIB_SPECIFICATION",   "OFF");
    mag_setc ("GRIB_SCALING",         "OFF");
    mag_grib ();
 

    /* plot the data */

    mag_cont  ();
    mag_text  ();
    mag_coast ();


    mag_close ();

    return 0;
}


#importing Magics module
from Magics.macro import *

#Example reference
ref = 'streamlines'

#Setting of the output file name
output = output(output_formats= ['png'],
                output_name_first_page_number= 'off',
                output_name= ref)

#Setting the coordinates of the geographical area
area = mmap(subpage_upper_right_longitude= 60.,
                 subpage_upper_right_latitude= 20.,
                 subpage_lower_left_longitude= 20.,
                 subpage_map_projection= 'cylindrical',
                 subpage_lower_left_latitude= 0.)

#Background Coastlines 
background = mcoast( map_coastline_sea_shade_colour= 'white',
                     map_coastline_land_shade_colour= 'cream',
                     map_grid= 'off',
                     map_coastline_land_shade= 'on',
                     map_coastline_sea_shade= 'on',
                     map_label= 'off',
                     map_coastline_colour= 'tan')

#Foreground Coastlines
foreground = mcoast(  map_grid= 'on',
		      map_grid_colour = 'tan',
		      map_label= 'off',
		      map_coastline_colour= 'tan',
                      map_coastline_land_shade= 'off',
                      map_coastline_sea_shade= 'off')


#Import the  wind  at 200hPa uv200 
uv200 =  mgrib( grib_input_file_name = './uv500.grb',grib_id= 'uv200')

streamlines = mwind(
                legend= 'on',
                wind_field_type = 'streamlines',
                )

title = mtext( text_lines = ["<font size='1'>Streamlines</font>"],
	       text_justification = 'left',
	       text_font_size = 0.5,
	       text_colour = 'charcoal')

#add a legend
legend = mlegend(legend= 'on',
           legend_text_colour= 'charcoal',
           legend_box_mode= 'positional',
           legend_box_x_position= 27.5,
           legend_box_y_position= 4.,
           legend_box_x_length= 2.,
           legend_box_y_length= 12.,
           legend_border= 'off',
           legend_border_colour= 'charcoal',
           legend_box_blanking= 'on',
           legend_display_type= 'continuous',
           legend_title = 'on',
	   legend_title_text= 'Wind speed at 200 hPa',
	   legend_text_font_size = '0.5')

#To the plot
plot(output, area, background, uv200, streamlines,foreground, title, legend)



#importing Magics module
from Magics.macro import *

#Setting of the output file name
output = output({"output_formats":['ps', 'png'], 
			'output_name':'z500_t850_europe'})

#Setting the coordinates of the geographical area
europe = mmap({
				"subpage_upper_right_longitude": 65.,
                "subpage_map_projection": "polar_stereographic",
                "subpage_map_vertical_longitude": 0.,
                "subpage_lower_left_longitude": -37.27,
                "subpage_lower_left_latitude": 21.51,
                "subpage_upper_right_latitude": 51.28})

#Coastlines setting
coast = mcoast( { "map_grid": "on",
                 "map_grid_colour" : "tan",
                 "map_coastline_colour": "tan"})

#Import the z500 data 
z500 =  mgrib({ "grib_input_file_name" : "../z500.grb",
                "grib_id": "z500"})

#Define the simple contouring for z500
z500_contour = mcont({
				"legend": "off",
                "contour_level_selection_type": "interval",
                "contour_line_colour": "black",
                "contour_hilo_height": 0.25,
                "contour_line_thickness": 1,
                "contour_hilo": "on",
                "contour_hilo_quality": "high",
                "contour_label": "off",
                "contour_highlight_colour": "black",
                "contour_highlight_thickness": 2,
                "contour_interval": 5.})

#Import the t850 data 
t850 =  mgrib({ "grib_input_file_name" : "../t850.grb",
                "grib_id": "t850"})


#Define the shading for t850
t850_contour = mcont({
				 "legend":"on",
                 "contour_shade": "on",
                 "contour_hilo": "off",
                 "contour": "off",
                 "contour_label": "off",
                 "contour_shade_method": "area_fill",
                 "contour_shade_max_level": 48.,
                 "contour_shade_min_level": -48.,
                 "contour_level_selection_type": "interval",
                 "contour_interval": 4.,
                 "contour_shade_colour_method": "list",
                 "contour_shade_colour_list": ["rgb(0,0,0.5)","rgb(0,0,0.5)",
						"rgb(0,0,0.85)","rgb(0,0,0.5)","rgb(0,0,0.85)","rgb(0.25,0,1)",
					    "blue_purple","greenish_blue","blue_green","bluish_green",
						"yellow_green","greenish_yellow","yellow",
						"orangish_yellow","orange_yellow","yellowish_orange",
						"orange","reddish_orange","red_orange","orangish_red",
						"red","magenta","magenta","magenta"]
         })

lines = [ "<grib_info id='z500' key='base-date' format='Base Date:%A %d %B %Y at %H UTC'/>",
             "<grib_info id='z500' key='start-date' format='Valid Date:%A %d %B %Y at %H UTC'/>",
             "<grib_info id='z500' key='name' format='parameter %s'/> <grib_info id='z500' key='level' format=' at %s hPa' />",
             "<grib_info id='t850' key='name' format='parameter %s'/> <grib_info id='t850' key='level' format=' at %s hPa' />",
		  " I can also put my own title !"
		]

title = mtext({
           "text_lines" : lines,
           "text_html" : "true",
           "text_colour" : "black",
           "text_mode": "positional",
           "text_box_x_position": 1.5,
           "text_box_y_position": 14.,
           "text_box_x_length": 20.,
           "text_box_y_length": 3.5,
           "text_border": "on",
           "text_border_colour": "black",
           "text_box_blanking": "on",
           "text_justification" : "left"})

#add a legend
legend = mlegend({"legend":"on",
           "legend_text_colour":"black",
           "legend_box_mode": "positional",
           "legend_box_x_position": 28.3,
           "legend_box_y_position": 1.,
           "legend_box_x_length": 2.,
           "legend_box_y_length": 13.,
           "legend_display_type": "continuous" })

#To the plot
plot(output, europe, t850, t850_contour, z500, z500_contour, coast, title, legend)


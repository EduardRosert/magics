# importing Magics module

from Magics.macro import *

# Setting of the output file name
ref = "epswave"
output = output(output_formats = ['png'], 
		output_name_first_page_number = "off",
        output_width = 600,
		output_name = ref,
        super_page_y_length=10., 
        super_page_x_length=20.)


# define the cartesian projection

roseprojection = mmap(
    subpage_map_projection='cartesian',
    subpage_x_axis_type='date',
    subpage_x_automatic='on',
    subpage_y_axis_type='regular',
    subpage_y_automatic='off',
    subpage_y_min=-43000.,
    subpage_y_max=43000.,
    subpage_y_position=4.,
    subpage_y_length=2.,
    )

# define horizontal axis

horizontal = maxis(
    axis_orientation='horizontal',
    axis_type='date',
    axis_date_type='days',
    axis_days_label='both',
    axis_days_label_colour='Rgb(0.5, 0.5, 0.5)',
    axis_days_label_height=0.35,
    axis_grid='on',
    axis_grid_colour='Rgb(0.5, 0.5, 0.5)',
    axis_grid_line_style='solid',
    axis_line_colour='grey',
    axis_minor_tick='on',
    axis_minor_tick_colour='grey',
    axis_months_label_colour='Rgb(0.5, 0.5, 0.5)',
    axis_months_label_height=0.3,
    axis_tick_colour='grey',
    axis_years_label_colour='Rgb(0.5, 0.5, 0.5)',
    axis_years_label_height=0.3,
    )

# define vertical axis

vertical = maxis(
    axis_orientation='vertical',
    axis_grid='on',
    axis_grid_colour='Rgb(0.5, 0.5, 0.5)',
    axis_grid_line_style='dash',
    axis_line='on',
    axis_line_colour='grey',
    axis_tick='off',
    axis_tick_label='off',
    )

data = mwrepjson(wrepjson_family='eps',
                 wrepjson_input_filename='wave.json',
                 wrepjson_parameter='230.140',
                 wrepjson_parameter_information='Mean Wave Direction (oceanographic convention)')

rose = mepswave( eps_rose_wind_border_colour = "Rgb(0.5000, 0.5000, 0.5000)",
                 eps_rose_wind_colour = "RGB(0.925,0.609,0.953)",
                 eps_rose_wind_convention = "oceanographic"
                )

lines = ["<json_info key='parameter_info'/>",
         "Forecast from <json_info key='date'/> for location <json_info key='location'/>"
         ]

title = mtext(
    text_lines=lines,
    text_html='true',
    text_colour='black',
    text_font_size=0.4,
    text_mode='positional',
    text_box_x_position=1.,
    text_box_y_position=6.5,
    text_box_x_length=20.,
    text_box_y_length=2.5,
    text_border='off',
    text_justification='left',
    )

# To the plot
plot(
    output,
    roseprojection, horizontal, vertical, data, rose, title
    )


# To the Documentation
tohtml( ref,
    data, rose, title
    )

      program  magics

C Define teh variable to handle the title lines.
      character*25 title
      dimension title(1)
      data title / 'Monitoring of airep data' /

C OPen Magics
      call popen

C Set the output information
      call psetc('output_name', 'symbol')

C Set the coastlines 
      call psetc('map_coastline_sea_shade', 'on')
      call psetc('map_coastline_sea_shade_colour', 'white')
      call psetc('map_label', 'off')
      call psetc('map_coastline_land_shade_colour', 'grey')
      call psetc('map_grid', 'on')
      call psetc('map_coastline_colour', 'black')
      call psetc('map_coastline_land_shade', 'on')
      call pcoast

C Load the data
      call pset?(???)
      call pgeo

c Define the visualisation using the advanced symbol plotting
      call psetc('symbol_table_mode', 'advanced')
      call psetc('symbol_type', 'marker')
      call pseti('symbol_marker', 15)
      call pset?(???)

      call psymb

C Add  a title
      call pset1c('text_lines', title, 1)
      call pset?(???)
      call ptext

C Add a legend
      call pset?(???)
      call psetc('legend', 'on')

C Close Magics : execute the plot
      call ????

      end

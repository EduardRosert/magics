
add_magics_test(NAME thinning SOURCES thinning.F IMAGE thinning.ps DATA 500uv.grb THRESHOLD 5)
add_magics_test(NAME wind SOURCES wind.F IMAGE wind.ps DATA 500uv.grb THRESHOLD 5)
add_magics_test(NAME wind_arrows SOURCES wind_arrows.F IMAGE wind_arrows.ps DATA uv500.grb  THRESHOLD 5)
add_magics_test(NAME wind_arrows_new SOURCES wind_arrows_new.F IMAGE wind_arrows_new.ps DATA   uv500.grb  THRESHOLD 5)
add_magics_test(NAME wind_ex SOURCES wind_ex.F IMAGE wind_ex.ps DATA uv500.grb THRESHOLD 5)
add_magics_test(NAME wind_landshade SOURCES wind_landshade.F IMAGE wind_landshade.ps DATA   uv500.grb  THRESHOLD 5)
add_magics_test(NAME wind_polar_array SOURCES wind_polar_array.F IMAGE wind_polar_array.ps    THRESHOLD 5)
add_magics_test(NAME wind_test SOURCES wind_test.F IMAGE wind_test.ps DATA   windspeed.grb uv100.grb uv500.grb THRESHOLD 5)
add_magics_test(NAME wind_vector_array SOURCES wind_vector_array.F IMAGE wind_vector_array.ps  THRESHOLD 5)









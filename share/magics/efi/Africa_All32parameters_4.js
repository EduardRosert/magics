magics_height = 384; 
magics_left = 60.; 
magics_outside = function (x, y) { 
	if (smaller(x, 50.9091) )
		return true;
	if (greater(x, 627.879) )
		return true;
	if (smaller(y, 96.05) )
		return true;
	if (greater(y, 480.25) )
		return true;
	return false;
}
; 
magics_reprojection = function (x, y)
{
	return {
		lon: (x -  50.9091 ) * ( 120 /  576.97 ) + (-45),
		lat: ( 96.05 - y) * ( 80 / 384.2) + (40)
	}
}
; 
magics_top = 96.; 
magics_version = "2.6.0"; 
magics_width = 578.; 

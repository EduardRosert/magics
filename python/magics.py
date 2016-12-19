# (C) Copyright 2012-2016 ECMWF.
#
# This software is licensed under the terms of the Apache Licence Version 2.0
# which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
# In applying this licence, ECMWF does not waive the privileges and immunities
# granted to it by virtue of its status as an intergovernmental organisation nor
# does it submit to any jurisdiction.
#

import ctypes
import ctypes.util
import sys

import numpy as np
from numpy.ctypeslib import ndpointer
from functools import partial

lib = ctypes.util.find_library("MagPlus")

if lib is None:
    lib = "/tmp/lib/libMagPlus.so"
    #lib = "/usr/local/lib/libMagPlus.dylib"

dll  = ctypes.CDLL(lib)
libc = ctypes.CDLL(ctypes.util.find_library("c"))


class FILE(ctypes.Structure):
    pass


FILE_p = ctypes.POINTER(FILE)

######################## String conversions ##########################

def _string_to_char(x):
    return x.encode()


def _char_to_string(x):
    return x.decode()


def _convert_strings(fn):

    convert = False

    for a in fn.argtypes:
        if a is c_char_p:
            convert = True

    if fn.restype is c_char_p:
        convert = True

    if not convert:
        return fn

    def wrapped(*args):

        new_args = []
        for a, t in zip(args, fn.argtypes):
            if t is c_char_p:
                a = string_to_char(a)
            new_args.append(a)

        r = fn(*new_args)
        if fn.restype is c_char_p:
            r = char_to_string(r)
        return r

    return wrapped

if sys.version_info[0] > 2:
    convert_strings = _convert_strings
    char_to_string = _char_to_string
    string_to_char = _string_to_char
else:
    convert_strings = lambda x: x
    char_to_string = lambda x: x
    string_to_char = lambda x: x





####################################################################
c_int = ctypes.c_int
c_int_p = ctypes.POINTER(c_int)

c_double = ctypes.c_double
c_double_p = ctypes.POINTER(c_double)

c_char = ctypes.c_char
c_char_p = ctypes.c_char_p

c_void_p = ctypes.c_void_p


####################################################################
def checked_error_in_last_paramater(fn):

    def wrapped(*args):
        err = c_int(0)
        err_p = ctypes.cast(ctypes.addressof(err), c_int_p)
        params = [a for a in args]
        params.append(err_p)

        result = fn(*params)
        if err.value:
            raise MagicsError(err)
        return result

    return wrapped


def checked_return_code(fn):

    def wrapped(*args):
        err = fn(*args)
        if err:
            raise MagicsError(err)

    return wrapped


####################################################################

def return_type(fn, ctype):

    def wrapped(*args):
        result = ctype()
        result_p = ctypes.cast(ctypes.addressof(result), ctypes.POINTER(ctype))
        params = [a for a in args]
        params.append(result_p)
        fn(*params)
        return result.value

    return wrapped

####################################################################

init = dll.mag_open
init.restype = None
init.argtypes = None

####################################################################

finalize = dll.mag_close
finalize.restype = None
finalize.argtypes = None

####################################################################

coast = dll.mag_coast
coast.restype = None
coast.argtypes = None

####################################################################

grib = dll.mag_grib
grib.restype = None
grib.argtypes = None

####################################################################

cont = dll.mag_cont
cont.restype = None
cont.argtypes = None

####################################################################

legend = dll.mag_legend
legend.restype = None
legend.argtypes = None

####################################################################

odb = dll.mag_odb
odb.restype = None
odb.argtypes = None

####################################################################

obs = dll.mag_obs
obs.restype = None
obs.argtypes = None

####################################################################

raw = dll.mag_raw
raw.restype = None
raw.argtypes = None

####################################################################

netcdf = dll.mag_netcdf
netcdf.restype = None
netcdf.argtypes = None

####################################################################

image = dll.mag_image
image.restype = None
image.argtypes = None

####################################################################

plot = dll.mag_plot
plot.restype = None
plot.argtypes = None

####################################################################

text = dll.mag_text
text.restype = None
text.argtypes = None

####################################################################

wind = dll.mag_wind
wind.restype = None
wind.argtypes = None

####################################################################

line = dll.mag_line
line.restype = None
line.argtypes = None

####################################################################

symb = dll.mag_symb
symb.restype = None
symb.argtypes = None

####################################################################

boxplot = dll.mag_boxplot
boxplot.restype = None
boxplot.argtypes = None

####################################################################

taylor = dll.mag_taylor
taylor.restype = None
taylor.argtypes = None

####################################################################

tephi = dll.mag_tephi
tephi.restype = None
tephi.argtypes = None

####################################################################

graph = dll.mag_graph
graph.restype = None
graph.argtypes = None

####################################################################

axis = dll.mag_axis
axis.restype = None
axis.argtypes = None

####################################################################

geo = dll.mag_geo
geo.restype = None
geo.argtypes = None

####################################################################

mimport = dll.mag_import
mimport.restype = None
mimport.argtypes = None

####################################################################

info = dll.mag_info
info.restype = None
info.argtypes = None

####################################################################

minput = dll.mag_input
minput.restype = None
minput.argtypes = None

####################################################################

eps = dll.mag_eps
eps.restype = None
eps.argtypes = None

####################################################################
###
###  Please note: these two functions changed compared to the previous SWIG based Python interface
###
metgraph = dll.mag_metgraph
metgraph.restype = None
metgraph.argtypes = None

epsinput = dll.mag_epsinput
epsinput.restype = None
epsinput.argtypes = None

####################################################################
###
###  Please note: this function was called mmetbufr to the previous SWIG based Python interface
###
metbufr = dll.mag_metbufr
metbufr.restype = None
metbufr.argtypes = None

####################################################################

epsgraph = dll.mag_epsgraph
epsgraph.restype = None
epsgraph.argtypes = None

####################################################################

epscloud = dll.mag_epscloud
epscloud.restype = None
epscloud.argtypes = None

####################################################################

epslight = dll.mag_epslight
epslight.restype = None
epslight.argtypes = None

####################################################################

epsplumes = dll.mag_epsplumes
epsplumes.restype = None
epsplumes.argtypes = None

####################################################################

epswind = dll.mag_epswind
epswind.restype = None
epswind.argtypes = None

####################################################################

epswave = dll.mag_epswave
epswave.restype = None
epswave.argtypes = None

####################################################################

epsbar = dll.mag_epsbar
epsbar.restype = None
epsbar.argtypes = None

####################################################################

epsshading = dll.mag_epsshading
epsshading.restype = None
epsshading.argtypes = None

####################################################################

wrepjson = dll.mag_wrepjson
wrepjson.restype = None
wrepjson.argtypes = None

####################################################################

geojson = dll.mag_geojson
geojson.restype = None
geojson.argtypes = None

####################################################################

mapgen = dll.mag_mapgen
mapgen.restype = None
mapgen.argtypes = None

####################################################################

mtable = dll.mag_table
mtable.restype = None
mtable.argtypes = None

####################################################################

seti = dll.mag_seti
seti.restype = None
seti.argtypes = (c_char_p, c_int)

####################################################################

def set1i(name,data,size):
#    array = np.empty((size,), dtype=np.float64)
#    array_p = array.ctypes.data_as(c_double_p)
#    _set1r(name, array_p, size)
    array_p = (ctypes.c_int * size)(*data)
    dll.mag_set1i(name, array_p, size)
    return None

####################################################################

array_2d_int = ndpointer(dtype=np.int,ndim=2, flags='CONTIGUOUS')
set2i = dll.mag_set2i
set2i.restype = None
set2i.argtypes = (c_char_p, array_2d_int, c_int, c_int)

####################################################################

setr = dll.mag_setr
setr.restype = None
setr.argtypes = (c_char_p, c_double)

####################################################################

def set1r(name,data,size):
    array_p = (ctypes.c_double * size)(*data)
    dll.mag_set1r(name, array_p, size)
    return None

####################################################################

array_2d_double = ndpointer(dtype=np.double,ndim=2, flags='CONTIGUOUS')
set2r = dll.mag_set2r
set2r.restype = None
set2r.argtypes = (c_char_p, array_2d_double, c_int, c_int)

####################################################################

setc = dll.mag_setc
setc.restype = None
setc.argtypes = (c_char_p, c_char_p)

####################################################################

def set1c(name,data,size):
    array_p = (ctypes.c_char_p * size)(*data)
    dll.mag_set1c(name, array_p, size)
    return None


####################################################################

#enqi = dll.mag_enqi
#enqi.restype  = c_int
#enqi.argtypes = (c_char_p,)

####################################################################

#enqr = dll.mag_enqr
#enqr.restype = c_double
#enqr.argtypes = (c_char_p,)

####################################################################

#enqc = dll.mag_enqc
#enqc.restype = c_char_p
#enqc.argtypes = (c_char_p,)

####################################################################

new_page = dll.mag_new
new_page.restype = None
new_page.argtypes = (c_char_p,)

####################################################################

reset = dll.mag_reset
reset.restype = None
reset.argtypes = (c_char_p,)

####################################################################

class MagicsError(Exception):

    def __init__(self, err):
        super(MagicsError, self).__init__("Magics Error - to be made clearer!!! (%s)" % err)

####################################################################


if __name__ == "__main__":
    print "..."

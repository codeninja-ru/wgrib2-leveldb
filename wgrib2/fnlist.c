#include <stdio.h>
#include <stdlib.h>
#include "fnlist.h"

struct function functions[] = {
   {"0xSec",f_0xSec, inv, 1, "Hex dump of section X (0..8)", 400},
   {"aerosol_size",f_aerosol_size, inv, 0, "optical properties of an aerosol", 200},
   {"aerosol_wavelength",f_aerosol_wavelength, inv, 0, "optical properties of an aerosol", 200},
   {"bitmap",f_bitmap, inv, 0, "bitmap mode", 700},
   {"center",f_center, inv, 0, "center", 110},
   {"checksum",f_checksum, inv, 1, "CRC checksum of section X (0..8), whole message (X = -1/message) or (X=data)", 400},
   {"code_table_0.0",f_code_table_0_0, inv, 0, "code table 0.0 discipline", -1},
   {"code_table_1.0",f_code_table_1_0, inv, 0, "code table 1.0 master table version", -1},
   {"code_table_1.1",f_code_table_1_1, inv, 0, "code table 1.1 local table version", -1},
   {"code_table_1.2",f_code_table_1_2, inv, 0, "code table 1.2 significance of reference time", -1},
   {"code_table_1.3",f_code_table_1_3, inv, 0, "code table 1.3 production status of processed data", -1},
   {"code_table_1.4",f_code_table_1_4, inv, 0, "code table 1.4 type of processed data", -1},
   {"code_table_3.0",f_code_table_3_0, inv, 0, "code table 3.0 Source of grid definition", -1},
   {"code_table_3.1",f_code_table_3_1, inv, 0, "code table 3.1 Grid definition template number", -1},
   {"code_table_3.11",f_code_table_3_11, inv, 0, "code table 3.11 regional/global thinned/reduced grid", -1},
   {"code_table_3.15",f_code_table_3_15, inv, 0, "code table 3.15 Physical meaning of vertical coordinate", -1},
   {"code_table_3.2",f_code_table_3_2, inv, 0, "code table 3.2 Size (radius) and Shape of Earth", -1},
   {"code_table_3.20",f_code_table_3_20, inv, 0, "code table 3.20 Type of Horizontal line", -1},
   {"code_table_3.21",f_code_table_3_21, inv, 0, "code table 3.21 Vertical Dimension coordinate values defn", -1},
   {"code_table_3.6",f_code_table_3_6, inv, 0, "code table 3.6 Spectral data representation type", -1},
   {"code_table_3.7",f_code_table_3_7, inv, 0, "code table 3.7 Spectral data representation mode", -1},
   {"code_table_3.8",f_code_table_3_8, inv, 0, "code table 3.8 Grid point position", -1},
   {"code_table_4.0",f_code_table_4_0, inv, 0, "code table 4.0 Product Definition Template Number", -1},
   {"code_table_4.1",f_code_table_4_1, inv, 0, "code table 4.1", -1},
   {"code_table_4.10",f_code_table_4_10, inv, 0, "code table 4.10 statistical processing", -1},
   {"code_table_4.11",f_code_table_4_11, inv, 0, "code table 4.11 (first) type of time intervals", -1},
   {"code_table_4.11s",f_code_table_4_11s, inv, 0, "code table 4.11 (all) type of time intervals", -1},
   {"code_table_4.15",f_code_table_4_15, inv, 0, "code table 4.15 type of areal statistical processing", -1},
   {"code_table_4.2",f_code_table_4_2, inv, 0, "code table 4.2", -1},
   {"code_table_4.230",f_code_table_4_230, inv, 0, "code table 4.230 chemical constituent type", -1},
   {"code_table_4.233",f_code_table_4_233, inv, 0, "code table 4.233 aerosol type", -1},
   {"code_table_4.235",f_code_table_4_235, inv, 0, "code table 4.235 Wind-generated wave spectral description", -1},
   {"code_table_4.3",f_code_table_4_3, inv, 0, "code table 4.3 Type of Generating Process", -1},
   {"code_table_4.4",f_code_table_4_4, inv, 0, "code table 4.4", -1},
   {"code_table_4.5a",f_code_table_4_5a, inv, 0, "code table 4.5 (1st value)", -1},
   {"code_table_4.5b",f_code_table_4_5b, inv, 0, "code table 4.5 (2nd value)", -1},
   {"code_table_4.6",f_code_table_4_6, inv, 0, "code table 4.6 ensemble type", -1},
   {"code_table_4.7",f_code_table_4_7, inv, 0, "code table 4.7 derived forecast", -1},
   {"code_table_4.9",f_code_table_4_9, inv, 0, "code table 4.9 Probability Type", -1},
   {"code_table_4.91",f_code_table_4_91, inv, 0, "code table 4.91 type of interval", -1},
   {"code_table_4.91b",f_code_table_4_91b, inv, 0, "code table 4.91 type of interval (2nd copy)", -1},
   {"code_table_5.0",f_code_table_5_0, inv, 0, "code table 5.0 data representation number", -1},
   {"code_table_5.1",f_code_table_5_1, inv, 0, "code table 5.1 type of original field values", -1},
   {"code_table_5.4",f_code_table_5_4, inv, 0, "code table 5.4 group splitting method", -1},
   {"code_table_5.5",f_code_table_5_5, inv, 0, "code table 5.5 missing value management for complex packing", -1},
   {"code_table_5.6",f_code_table_5_6, inv, 0, "code table 5.5 complex packing spatial differencing", -1},
   {"code_table_5.7",f_code_table_5_7, inv, 0, "code table 5.7 precision in IEEE packing", -1},
   {"code_table_6.0",f_code_table_6_0, inv, 0, "code table 6.0 Bitmap indicator", -1},
   {"ctl_ens",f_ctl_ens, inv, 0, "ens info for g2ctl/GrADS", -1},
   {"ctl_inv",f_ctl_inv, inv, 0, "ctl inventory dump for g2ctl/GrADS", -1},
   {"cyclic",f_cyclic, inv, 0, "is grid cyclic? (not for for mercator and thinned grids)", -1},
   {"disc",f_code_table_0_0, inv, 0, "discipline (code table 0.0)", 200},
   {"domain",f_domain, inv, 0, "find rectangular domain for g2ctl/GrADS plots", 100},
   {"end_ft",f_end_ft, inv, 0, "verf time = reference_time + forecast_time + stat. proc time (YYYYMMDDHH) (same as -vt)", 400},
   {"end_FT",f_end_FT, inv, 0, "verf time = reference_time + forecast_time + stat. proc time (YYYYMMDDHHMMSS) (same as -VT)", 400},
   {"ens",f_ens, inv, 0, "ensemble information", 200},
   {"ext_name",f_ext_name, inv, 0, "extended name, var+qualifiers", 400},
   {"flag_table_3.10",f_flag_table_3_10, inv, 0, "flag table 3.10 scanning mode for one diamond", -1},
   {"flag_table_3.3",f_flag_table_3_3, inv, 0, "flag table 3.3, resolution and component flags", -1},
   {"flag_table_3.4",f_flag_table_3_4, inv, 0, "flag table 3.4, scanning mode", -1},
   {"flag_table_3.5",f_flag_table_3_5, inv, 0, "flag table 3.5 projection center", -1},
   {"flag_table_3.9",f_flag_table_3_9, inv, 0, "flag table 3.9 numbering order of diamonds seen from corresponding pole", -1},
   {"ftime",f_ftime, inv, 0, "forecast time", 440},
   {"full_name",f_full_name, inv, 0, "extended name, var+qualifiers", 400},
   {"gctpc",f_gctpc, inv, 1, " X=0,1 use gctpc library (testing)", 100},
   {"gdt",f_gdt, inv, 0, "contents of Grid Definition Template (g2c)", 200},
   {"get_byte",f_get_byte, inv, 3, "get bytes in Section X, Octet Y, number of bytes Z (decimal format)", 100},
   {"get_hex",f_get_hex, inv, 3, "get bytes in Section X, Octet Y, number of bytes Z (bytes in hexadecimal format)", 100},
   {"get_ieee",f_get_ieee, inv, 3, "get ieee float in Section X, Octet Y, number of floats Z", 100},
   {"get_int",f_get_int, inv, 3, "get 4-byte ints in Section X, Octet Y, number of ints Z", 100},
   {"get_int2",f_get_int2, inv, 3, "get 2-byte ints in Section X, Octet Y, number of ints Z", 100},
   {"grid",f_grid, inv, 0, "grid definition", 200},
   {"grid_id",f_grid_id, inv, 0, "show values from grid_id", 100},
   {"ij",f_ij, inv, 2, "value of field at grid(X,Y) X=1,..,nx Y=1,..,ny (WxText enabled)", 100},
   {"ijlat",f_ijlat, inv, 2, "lat,lon and grid value at grid(X,Y) X=1,..,nx Y=1,..,ny (WxText enabled)", 100},
   {"ilat",f_ilat, inv, 1, "lat,lon and grid value at Xth grid point, X=1,..,npnts (WxText enabled)", 100},
   {"lev",f_lev, inv, 0, "level (code table 4.5)", 200},
   {"lev0",f_lev0, inv, 0, "level for g2ctl/GrADS", -1},
   {"ll2i",f_ll2i, inv, 2, "x=lon y=lat, converts to (i)", 100},
   {"ll2ij",f_ll2ij, inv, 2, "x=lon y=lat, converts lon-lat (i,j)", 100},
   {"lon",f_lon, inv, 2, "value at grid point nearest lon=X lat=Y (WxText enabled)", 100},
   {"match_inv",f_match_inv, inv, 0, "inventory used by -match, -not, -if and -not_if", 100},
   {"max",f_max, inv, 0, "print maximum value", 100},
   {"min",f_min, inv, 0, "print minimum value", 100},
   {"misc",f_misc, inv, 0, "variable name qualifiers like chemical, ensemble, probability, etc", 100},
   {"MM",f_MM, inv, 0, "reference time MM", 105},
   {"n",f_n, inv, 0, "prints out inventory number", 100},
   {"N_ens",f_N_ens, inv, 0, "number of ensemble members", 200},
   {"nl",f_nl, inv, 0, "inserts new line into inventory", 100},
   {"nlons",f_nlons, inv, 0, "number of longitudes for each latitude", 200},
   {"nl_out",f_nl_out, inv, 1, "write new line in file X", 100},
   {"npts",f_npts, inv, 0, "number of grid points", 500},
   {"nxny",f_nxny, inv, 0, "nx and ny of grid", 200},
   {"packing",f_packing, inv, 0, "shows the packing mode (use -v for more details)", 510},
   {"pds_fcst_time",f_pds_fcst_time, inv, 0, "fcst_time(1) in units given by pds", -1},
   {"print",f_print, inv, 1, "inserts string into inventory", 100},
   {"prob",f_prob, inv, 0, "probability information", 100},
   {"process",f_code_table_4_3, inv, 0, "Process (code table 4.3)", 200},
   {"processid",f_processid, inv, 0, "process id (locally defined)", 400},
   {"proj4_ij2ll",f_proj4_ij2ll, inv, 2, "X=x Y=y, converts to (i,j) to lon-lat using proj.4 (experimental)", 100},
   {"proj4_ll2i",f_proj4_ll2i, inv, 2, "x=lon y=lat, converts to (i) using proj.4 (experimental)", 100},
   {"proj4_ll2ij",f_proj4_ll2ij, inv, 2, "x=lon y=lat, converts lon-lat (i,j) using proj.4 (experimental)", 100},
   {"radius",f_radius, inv, 0, "radius of Earth", 100},
   {"range",f_range, inv, 0, "print out location of record in bytes, 0 = first byte", 100},
   {"RT",f_RT, inv, 0, "type of reference Time", 110},
   {"s",f_s, inv, 0, "simple inventory", 100},
   {"S",f_S, inv, 0, "simple inventory with minutes and seconds (subject to change)", 100},
   {"scale",f_scale, inv, 0, "scale for packing", 510},
   {"scaling",f_scaling, inv, 0, "scaling for packing (old format)", 510},
   {"scan",f_scan, inv, 0, "scan order of grid", 200},
   {"Sec0",f_Sec0, inv, 0, "contents of section0", 200},
   {"Sec3",f_Sec3, inv, 0, "contents of section 3 (Grid Definition Section)", 200},
   {"Sec4",f_Sec4, inv, 0, "Sec 4 values (Product definition section)", 400},
   {"Sec5",f_Sec5, inv, 0, "Sec 5 values (Data representation section)", 400},
   {"Sec6",f_Sec6, inv, 0, "show bit-map section", 700},
   {"Sec_len",f_Sec_len, inv, 0, "length of various grib sections", 700},
   {"spatial_proc",f_spatial_proc, inv, 0, "show spacial processing, pdt=4.15", 400},
   {"spectral",f_spectral, inv, 0, "show spectral bands", 400},
   {"spectral_bands",f_spectral_bands, inv, 0, "spectral bands for satellite, pdt=4.31", 400},
   {"start_ft",f_start_ft, inv, 0, "verf time = reference_time + forecast_time (YYYYMMDDHH) : no stat. proc time", 400},
   {"start_FT",f_start_FT, inv, 0, "verf time = reference_time + forecast_time (YYYYMMDDHHMMSS) - no stat. proc time", 400},
   {"stats",f_stats, inv, 0, "statistical summary of data values", 100},
   {"subcenter",f_subcenter, inv, 0, "subcenter", 110},
   {"t",f_t, inv, 0, "reference time YYYYMMDDHH, -v2 for alt format", 100},
   {"T",f_T, inv, 0, "reference time YYYYMMDDHHMMSS", 101},
   {"table",f_table, inv, 0, "parameter table", 200},
   {"unix_time",f_unix_time, inv, 0, "print unix timestamp for rt & vt", 100},
   {"V",f_V, inv, 0, "diagnostic output", 100},
   {"var",f_var, inv, 0, "short variable name", 400},
   {"varX",f_varX, inv, 0, "raw variable name - discipline mastertab localtab center parmcat parmnum", 400},
   {"vector_dir",f_vector_dir, inv, 0, "grid or earth relative winds", 1},
   {"verf",f_verf, inv, 0, "simple inventory using verification time", 100},
   {"vt",f_vt, inv, 0, "verf time = reference_time + forecast_time, -v2 for alt format", 400},
   {"VT",f_VT, inv, 0, "verf time = reference_time + forecast_time (YYYYMMDDHHMMSS)", 400},
   {"wave_partition",f_wave_partition, inv, 0, "ocean surface wave partition (pdt=52)", 200},
   {"YY",f_YY, inv, 0, "reference time YYYY", 103},
   {"inv_f77",f_inv_f77, inv_output, 3, "match inventory written to Z with character*(Y) and options X", 100},
   {"s_out",f_s_out, inv_output, 1, "simple inventory written to X", 100},
   {"big_endian",f_big_endian, misc, 0, "sets ieee output to big endian (default is big endian)", 100},
   {"colon",f_colon, misc, 1, "replace item deliminator (:) with X", 100},
   {"config",f_config, misc, 0, "shows the configuration", 100},
   {"count",f_count, misc, 0, "prints number of fields", 100},
   {"end",f_end, misc, 0, "stop after first (sub)message (save time)", 100},
   {"fix_CFSv2_fcst",f_fix_CFSv2_fcst, misc, 3, "fixes CFSv2 monthly fcst X=daily or 00/06/12/18 Y=pert no. Z=number ens fcsts v1.0", 100},
   {"fix_ncep",f_fix_ncep, misc, 0, "fix ncep PDT=8 headers produced by cnvgrib", 100},
   {"grid_changes",f_grid_changes, misc, 0, "prints number of grid changes", 100},
   {"grid_def",f_grid_def, misc, 0, "read lon and lat data from grib file -- experimental", 100},
   {"h",f_h, misc, 0, "help, shows common options", 100},
   {"header",f_header, misc, 0, "f77 header or nx-ny header in text output (default)", 100},
   {"help",f_help, misc, 1, "help [search string|all], -help all, shows all options", 100},
   {"if",f_if, misc, 1, "if X (POSIX regular expression) matches, conditional execution up to next output/fi", 100},
   {"if_n",f_if_n, misc, 1, "if (inv numbers in range), X=(start:end:step)", 100},
   {"if_rec",f_if_rec, misc, 1, "if (record numbers in range), X=(start:end:step)", 100},
   {"if_reg",f_if_reg, misc, 1, "if rpn registers defined, X = A, A:B, A:B:C, etc A = register number", 100},
   {"ijundefine",f_ijundefine, misc, 3, "sets grid point values to undefined X=(in-box|out-box) Y=ix0:ix1 Z=iy0:iy1 ix=(1..nx) iy=(1..ny)", 100},
   {"import_bin",f_import_bin, misc, 1, "read binary file (X) for data", 100},
   {"import_ieee",f_import_ieee, misc, 1, "read ieee file (X) for data", 100},
   {"import_text",f_import_text, misc, 1, "read text file (X) for data", 100},
   {"inv",f_inv, misc, 1, "write inventory to X", 100},
   {"limit",f_limit, misc, 1, "stops after X fields decoded", 100},
   {"little_endian",f_little_endian, misc, 0, "sets ieee output to little endian (default is big endian)", 100},
   {"new_grid_interpolation",f_new_grid_interpolation, misc, 1, "new_grid interpolation X=bilinear,bicubic,neighbor,budget", 111},
   {"new_grid_ipopt",f_new_grid_ipopt, misc, 1, "new_grid ipopt values X=i1:i2..:iN N <= 20", 111},
   {"new_grid_vectors",f_new_grid_vectors, misc, 1, "change fields to vector interpolate: X=none,default,UGRD:VGRD", 111},
   {"new_grid_winds",f_new_grid_winds, misc, 1, "new_grid wind orientation: X = grid, earth (N/S, default) -- alpha", 111},
   {"no_header",f_no_header, misc, 0, "no f77 header or nx-ny header in text output", 100},
   {"not_if",f_not_if, misc, 1, "if not X (regular expression) matches, conditional execution until next output/fi", 100},
   {"quit",f_end, misc, 0, "stop after first (sub)message (save time)", -1},
   {"rpn",f_rpn, misc, 1, "reverse polish notation calculator (beta)", 100},
   {"set",f_set, misc, 2, "set X = Y, X=local_table,etc (help: -set help help)", 100},
   {"set_ave",f_set_ave, misc, 1, "set ave/acc .. only on pdt=4.0 only anl/fcst", 100},
   {"set_bin_prec",f_set_bin_prec, misc, 1, "X set number of binary bits for grib_out packing", 100},
   {"set_byte",f_set_byte, misc, 3, "set bytes in Section X, Octet Y, bytes Z (a|a:b:c)", 100},
   {"set_center",f_set_center, misc, 1, "changes center X = C or C:S C and S are center/subcenter numbers", -1},
   {"set_date",f_set_date, misc, 1, "changes date code .. keep old date code if not specified completely", 100},
   {"set_ensm_derived_fcst",f_set_ensm_derived_fcst, misc, 2, "convert PDT 0,1,2 -> 2, 8,11,12 -> 12, X=code table 4.7 Y=num ens members", 100},
   {"set_ens_num",f_set_ens_num, misc, 3, "convert PDT 0,1 -> 1, 8,11 -> 11, X=code table 4.6 Y=pert num Z=num ens members -1=No Change", 100},
   {"set_flag_table_3.3",f_set_flag_table_3_3, misc, 1, "flag table 3.3 = X", -1},
   {"set_flag_table_3.4",f_set_flag_table_3_4, misc, 1, "flag table 3.4 = X", -1},
   {"set_ftime",f_set_ftime, misc, 1, "set ftime", 100},
   {"set_grib_max_bits",f_set_grib_max_bits, misc, 1, "sets scaling so number of bits does not exceed N in (new) grib output", 100},
   {"set_grib_type",f_set_grib_type, misc, 1, "set grib type = jpeg, simple, ieee, complex(1|2|3), same", 100},
   {"set_hex",f_set_hex, misc, 3, "set bytes in Section X, Octet Y, bytes Z (a|a:b:c) in hexadecimal", 100},
   {"set_ieee",f_set_ieee, misc, 3, "set ieee float in Section X, Octet Y, floats Z (a|a:b:c)", 100},
   {"set_ijval",f_set_ijval, misc, 3, "sets grid point value X=ix Y=iy Z=val", 100},
   {"set_int",f_set_int, misc, 3, "set 4-byte ints in Section X, Octet Y, signed integers Z (a|a:b:c)", 100},
   {"set_int2",f_set_int2, misc, 3, "set 2-byte ints in Section X, Octet Y, signed integers Z (a|a:b:c)", 100},
   {"set_ival",f_set_ival, misc, 2, "sets grid point value X=i1:i2:.. Y=va1:val2:.. grid[i1] = val1,etc", 100},
   {"set_lev",f_set_lev, misc, 1, "changes level code .. not complete", 100},
   {"set_metadata",f_set_metadata, misc, 1, "read meta-data for grib writing from file X", 100},
   {"set_pdt",f_set_pdt, misc, 1, "makes new (clean) pdt, X=PDT_number or X=PDT_number:size of PDT in octets", 100},
   {"set_radius",f_set_radius, misc, 1, "set radius of Earth X= 0,2,4,5,6,8,9 (Code Table 3.2), 1:radius , 7:major:minor", 100},
   {"set_scaling",f_set_scaling, misc, 2, "set decimal scaling=X binary scaling=Y for grib_out packing", 100},
   {"set_sec_size",f_set_sec_size, misc, 2, "resizes section , X=section number, Y=size in octets, DANGEROUS", 100},
   {"set_ts_dates",f_set_ts_dates, misc, 3, "changes date code for time series X=YYYYMMDDHH(mmss) Y=dtime Z=#msgs/date", 100},
   {"set_var",f_set_var, misc, 1, "changes variable name", 100},
   {"submsg",f_submsg, misc, 1, "process submessage X (0=process all messages)", 100},
   {"sys",f_sys, misc, 1, "run system/shell command, X=shell command", 100},
   {"text_col",f_text_col, misc, 1, "number of columns on text output", 100},
   {"text_fmt",f_text_fmt, misc, 1, "format for text output (C)", 100},
   {"udf",f_udf, misc, 2, "run UDF, X=program+optional_args, Y=return file", 100},
   {"udf_arg",f_udf_arg, misc, 2, "add grib-data to UDF argument file, X=file Y=name", 100},
   {"undefine",f_undefine, misc, 3, "sets grid point values to undefined X=(in-box|out-box) Y=lon0:lon1 Z=lat0:lat1", 100},
   {"undefine_val",f_undefine_val, misc, 1, "grid point set to undefined if X=val or X=low:high", 100},
   {"v",f_v, misc, 0, "verbose (v=1)", 100},
   {"v0",f_v0, misc, 0, "not verbose (v=0)", 100},
   {"v1",f_v, misc, 0, "verbose (v=1)", -1},
   {"v2",f_v2, misc, 0, "really verbose (v=2)", 100},
   {"v98",f_v98, misc, 0, "verbose mode for debugging only (v=98)", -1},
   {"v99",f_v99, misc, 0, "verbose mode for debugging only (v=99)", -1},
   {"version",f_version, misc, 0, "print version", 100},
   {"AAIG",f_AAIG, output, 0, "writes Ascii ArcInfo Grid file, lat-lon grid only (alpha)", 100},
   {"ave",f_ave, output, 2, "average X=time step, Y=output grib file needs file is special order", 000},
   {"bin",f_bin, output, 1, "write binary data to X", 100},
   {"cress_lola",f_cress_lola, output, 4, "lon-lat grid values X=lon0:nlon:dlon Y=lat0:nlat:dlat Z=file A=radius1:radius2:..:radiusN", 111},
   {"csv",f_csv, output, 1, "make comma separated file, X=file (WxText enabled)", 100},
   {"fcst_ave",f_fcst_ave, output, 2, "average X=time step, Y=output grib file needs file is special order", 000},
   {"fi",f_fi, output, 0, "null output operation", 100},
   {"grib",f_grib, output, 1, "writes GRIB record (one submessage) to X", 100},
   {"GRIB",f_GRIB, output, 1, "writes entire GRIB record (all submessages)", 100},
   {"grib_ieee",f_grib_ieee, output, 1, "writes data[] to X.grb, X.head, X.tail, and X.h", 100},
   {"grib_out",f_grib_out, output, 1, "writes decoded/modified data in grib-2 format to file X", 100},
   {"grib_out_irr",f_grib_out_irr, output, 2, "writes irregular grid grib X=(all|defined) Y=(output file)", 100},
   {"ieee",f_ieee, output, 1, "write (default:big-endian) IEEE data to X", 100},
   {"ijbox",f_ijbox, output, 4, "grid values in bounding box X=i1:i2[:di] Y=j1:j2[:dj] Z=file A=[bin|text|spread]", 100},
   {"ijsmall_grib",f_ijsmall_grib, output, 3, "make small domain grib file X=ix0:ix1 Y=iy0:iy1 Z=file (beta)", 100},
   {"irr_grid",f_irr_grid, output, 3, "make irregular grid, nearest neighbor, X=lon-lat list Y=radius (km) Z=output grib file", 100},
   {"leveldb",f_leveldb, output, 1, "make levedb file", 100},
   {"lola",f_lola, output, 4, "lon-lat grid values X=lon0:nlon:dlon Y=lat0:nlat:dlat Z=file A=[bin|text|spread|grib]", 100},
   {"merge_fcst",f_merge_fcst, output, 2, "normalize NCEP-type ave/acc X=number to intervals to merge Y=output grib file", 100},
   {"mysql",f_mysql, output, 5, "H=[host] U=[user] P=[password] D=[db] T=[table] (alpha)", 100},
   {"mysql_dump",f_mysql_dump, output, 7, "H=[host] U=[user] P=[password] D=[db] T=[table] W=[western_lons:0|1] PV=[remove unlikely:0|1]", 100},
   {"mysql_speed",f_mysql_speed, output, 7, "H=[host] U=[user] P=[password] D=[db] T=[table] W=[western_lons:0|1] PV=[remove unlikely:0|1]", 100},
   {"ncep_norm",f_ncep_norm, output, 1, "normalize NCEP-type ave/acc X=output grib file", 100},
   {"ncep_uv",f_ncep_uv, output, 1, "combine U and V fields into one message like NCEP operations", 111},
   {"netcdf",f_netcdf, output, 1, "write netcdf data to X", 100},
   {"new_grid",f_new_grid, output, 4, "bilinear interpolate: X=projection Y=x0:nx:dx Z=y0:ny:dy A=grib_file alpha", 111},
   {"small_grib",f_small_grib, output, 3, "make small domain grib file X=lonW:lonE Y=latS:latN Z=file (beta)", 100},
   {"spread",f_spread, output, 1, "write text - spread sheet format into X (WxText enabled)", 100},
   {"text",f_text, output, 1, "write text data into X", 100},
   {"tosubmsg",f_tosubmsg, output, 1, "convert GRIB message to submessage and write to file X", 100},
   {"wind_dir",f_wind_dir, output, 1, "calculate wind direction, X = output gribfile (direction in degrees, 0=wind from north, 90=wind from east)", 100},
   {"wind_speed",f_wind_speed, output, 1, "calculate wind speed, X = output gribfile (U then V in datafile)", 100},
   {"append",f_append, setup, 0, "append mode, write to existing output files", 100},
   {"crlf",f_crlf, setup, 0, "make the end of the inventory a crlf (windows) instead of newline (unix)", 100},
   {"d",f_d, setup, 1, "dump message X (n or n.m), only 1 -d allowed", 200},
   {"eof_bin",f_eof_bin, setup, 2, "send (binary) integer to file upon EOF: X=file Y=integer", 100},
   {"eof_string",f_eof_string, setup, 2, "send string to file upon EOF: X=file Y=string", 100},
   {"err_bin",f_err_bin, setup, 2, "send (binary) integer to file upon err exit: X=file Y=integer", 100},
   {"err_string",f_err_string, setup, 2, "send string to file upon err exit: X=file Y=string", 100},
   {"fix_ncep_2",f_fix_ncep_2, setup, 0, "ncep bug fix 2, probability observation < -ve number", 100},
   {"fix_ncep_3",f_fix_ncep_3, setup, 0, "sets flag to fix ncep bug 3 (constant fields)", 200},
   {"fix_ncep_4",f_fix_ncep_4, setup, 0, "fixes NCEP grib2 files where DX and DY are undefined", 100},
   {"flush",f_flush, setup, 0, "flush output buffers after every write (interactive)", -1},
   {"for",f_for, setup, 1, "process record numbers in range, X=(start:end:step), only one -for allowed", 100},
   {"for_n",f_for_n, setup, 1, "process inv numbers in range, X=(start:end:step), only one -for allowed", 100},
   {"g2clib",f_g2clib, setup, 1, "X=0/1/2 0=WMO std 1=emulate g2clib 2=use g2clib", 100},
   {"i",f_i, setup, 0, "read Inventory from stdin", 100},
   {"match",f_match, setup, 1, "process data that matches X (POSIX regular expression)", 100},
   {"nc3",f_nc3, setup, 0, "use netcdf3 (classic)", 100},
   {"nc4",f_nc4, setup, 0, "use netcdf4 (compressed, controlled endianness etc)", 100},
   {"nc_grads",f_nc_grads, setup, 0, "require netcdf file to be grads v1.9b4 compatible (fixed time step only)", 100},
   {"nc_nlev",f_nc_nlev, setup, 1, "netcdf, X = max LEV dimension for {TIME,LEV,LAT,LON} data", 100},
   {"nc_pack",f_nc_pack, setup, 1, "pack/check limits of all NEW input variables, X=min:max[:byte|short|float]", 100},
   {"ncpu",f_ncpu, setup, 1, "number of threads, default is environment variable OMP_NUM_THREADS/number of cpus", 100},
   {"nc_table",f_nc_table, setup, 1, "X is conversion_to_netcdf_table file name", 100},
   {"nc_time",f_nc_time, setup, 1, "netcdf, [[-]yyyymmddhhnnss]:[dt{s[ec]|m[in]|h[our]|d[ay]}], [-] is for time alignment only", 100},
   {"no_append",f_no_append, setup, 0, "not append mode, write to new output files (default)", 100},
   {"no_flush",f_no_flush, setup, 0, "flush output buffers when full (default)", -1},
   {"no_nc_grads",f_no_nc_grads, setup, 0, "netcdf file may be not grads v1.9b4 compatible, variable time step", 100},
   {"no_nc_pack",f_no_nc_pack, setup, 0, "no packing in netcdf for NEW variables", 100},
   {"no_nc_table",f_no_nc_table, setup, 0, "disable previously defined conversion_to_netcdf_table", 100},
   {"no_nc_time",f_no_nc_time, setup, 0, "netcdf, disable previously defined initial or relative date and time step", 100},
   {"not",f_not, setup, 1, "process data that does not match X (POSIX regular expression)", 100},
   {"one_line",f_one_line, setup, 0, "puts all on one line (makes into inventory format)", 100},
   {"order",f_order, setup, 1, "decoded data in X (raw|we:sn|we:ns) order, we:sn is default", 200},
   {"set_ext_name",f_set_ext_name, setup, 1, "X=0/1 extended name on/off", 400},
   {"set_regex",f_set_regex, setup, 1, "set regex mode X = 0:extended regex (default) 1:pattern 2:extended regex & quote metacharacters", 100},
   {"tigge",f_tigge, setup, 0, "use modified-TIGGE grib table", 100},
};
 
int nfunctions = sizeof functions / sizeof functions[0];

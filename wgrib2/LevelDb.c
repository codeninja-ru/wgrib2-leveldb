/******************************************************************************************
 Copyright (C) 2008 Niklas Sondell, Storm Weather Center
 This file is part of wgrib2 and could be distributed under terms of the GNU General Public License

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grb2.h"
#include "wgrib2.h"
#include "fnlist.h"
#include <leveldb/c.h>

extern int decode, flush_mode;
extern int file_append;
extern int WxText, WxNum;

extern double *lat, *lon;
extern int decode, latlon;

/*
 * HEADER:100:leveldb:output:1:make comma separated file, X=file (WxText enabled)
 */

int f_leveldb(ARG1) {

    char new_inv_out[STRING_SIZE];
    char name[100], desc[100], unit[100];

    unsigned int j;
    char vt[20],rt[20];
    int year, month, day, hour, minute, second;
	
    /* initialization phase */

    leveldb_t *db;
    leveldb_options_t *options;
    leveldb_readoptions_t *roptions;
    leveldb_writeoptions_t *woptions;
    char *err = NULL;

    if (mode == -1) {
        WxText = decode = latlon = 1;
        options = leveldb_options_create();
        leveldb_options_set_create_if_missing(options, 1);
        leveldb_options_set_write_buffer_size(options, 64 * 1048576);
        leveldb_options_set_block_size(options, 2 * 1048576);
        db = leveldb_open(options, arg1, &err);

        *local = db;
        if (err != NULL)
          fatal_error("leveldb could not open file %s", arg1);  

        leveldb_free(err); err = NULL;
        return 0;
    }

    /* cleanup phase */

    if (mode == -2) {
      leveldb_close(db);
      return 0;
    }

    /* processing phase */

    if (lat == NULL || lon == NULL) {
      fprintf(stderr,"leveldb: latitude/longitude not defined, record skipped\n");
      return 0;
    }

    db = (leveldb_t *) *local;

    /*Collect runtime and validtime into vt and rt*/

    reftime(sec, &year, &month, &day, &hour, &minute, &second);
    sprintf(rt, "%4.4d%2.2d%2.2d%2.2d", year,month,day,hour,minute,second);

    vt[0] = 0;
    if (verftime(sec, &year, &month, &day, &hour, &minute, &second) == 0) {
        sprintf(vt,"%4.4d%2.2d%2.2d%2.2d", year,month,day,hour,minute,second);
    }

    /*Get levels, parameter name, description and unit*/

    *new_inv_out = 0;
    f_lev(call_ARG0(new_inv_out,NULL));

    if (strcmp(new_inv_out, "reserved")==0) return 0;
//    getName(sec, mode, NULL, name, desc, unit);
    getExtName(sec, mode, NULL, name, desc, unit,".","_");
//	fprintf(stderr,"Start processing of %s at %s\n", name, new_inv_out);
//	fprintf(stderr,"Gridpoints in data: %d\n", ndata);
//	fprintf(stderr,"Description: %s, Unit %s\n", desc,unit);

     /* Lage if-setning rundt hele som sjekker om alt eller deler skal ut*/

    woptions = leveldb_writeoptions_create();
    char key[255];
    char val[20];

    sprintf(key, "vars/%s", name);
    leveldb_put(db, woptions, key, strlen(key), name, strlen(name), &err);
    leveldb_put(db, woptions, "start_time", 10, rt, strlen(rt), &err);
    leveldb_put(db, woptions, "end_time", 8, vt, strlen(vt), &err);


    if (WxNum > 0) {
        for (j = 0; j < ndata; j++) {
            if (!UNDEFINED_VAL(data[j])) {
              sprintf(key, "data/%g/%g/%s/%s", lon[j] > 180.0 ?  lon[j]-360.0 : lon[j],lat[j], name, vt);
              sprintf(val, "%s", WxLabel(data[j]));
              leveldb_put(db, woptions, key, strlen(key), val, strlen(val), &err);
	    }
	}
    }
    else {
        for (j = 0; j < ndata; j++) {
            if (!UNDEFINED_VAL(data[j])) {
              sprintf(key, "data/%g/%g/%s/%s", lon[j] > 180.0 ?  lon[j]-360.0 : lon[j],lat[j], name, vt);
              sprintf(val, "%lg", data[j]);
              leveldb_put(db, woptions, key, strlen(key), val, strlen(val), &err);
	    }
	}
    }
    //leveldb_close(db);
    //if (flush_mode) fflush(out);
    return 0;
}

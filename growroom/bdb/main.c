#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>

#include "bdb.h"
#include "cache.h"
#include "symbol.h"
#include "tree2dot.h"

dbid_t
iter_cache_id (void *n)
{
    return ((cnode *) n)->id;
}

char *
iter_cache_string (void *n)
{
    return ((symbol *) ((cnode *) n)->data)->name;
}

void *
iter_cache_keys_left (void *n)
{
    return ((cnode *) n)->kleft;
}

void *
iter_cache_keys_right (void *n)
{
    return ((cnode *) n)->kright;
}

bdb_iter keyiter = {
    .id     = iter_cache_id,
    .string = iter_cache_string,
    .left   = iter_cache_keys_left,
    .right  = iter_cache_keys_right
};

int
main (int argc, char *argv[])
{
    (void) argc;
    (void) argv;

    printf ("Bielefeld DB is currently not with completed "
            "unit tests.  Please hang on for the first "
            "release.\n");

    return 0;
}

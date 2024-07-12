#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* This function tries if the *file exist or not */
extern void try(FILE *file);

extern void close_file(FILE *fd, FILE *fg);

extern void tail_with_no_options(FILE *fd, int len);

extern int getlen(FILE *fd);

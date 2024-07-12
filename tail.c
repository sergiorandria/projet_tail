#include "tail.h"
#include "def_opt.c"

int main(int argc, char **argv)
{
    int status, len;
    FILE *fd = NULL, *fg = NULL;

    if (argc < 2){
		status = 1;
		goto help;
	}
	
	if (argc == 2){
		fd = fopen(argv[1], "r+");
		fg = fopen(argv[1], "r+");
		len = getlen(fg);
		tail_with_no_options(fd, len);
		count_bytes(fd, 10);
		close_file(fd, fg);
	}

	if (argc > 2){
		
		
		
		
		}
help:
	help_display(status);
	return EXIT_FAILURE;
    
    return 0;
}

int getlen(FILE *fd)
{
    int c, n = 0;

    while((c=fgetc(fd)) != EOF)
        if (c == '\n')
            ++n;

    return n;
}

void open_file(FILE *fd, FILE *fg, char *args)
{
    fd = fopen(args, "r+");
    fg = fopen(args, "r+");

    try(fd);
    try(fg);
}

void try(FILE *file)
{
    if( file == NULL ){
        printf("File Error");
        exit(1);
    }
}

void close_file(FILE *fd, FILE *fg)
{
    fclose(fd);
    fclose(fg);
}

void tail_with_no_options(FILE *fd, int len)
{
    int c, ptr = 0;

    while((c=fgetc(fd)) != EOF)
    {
        if(c == '\n')
            ++ptr;

        if( ptr >= len - 10)
            putchar(c);
    }
}

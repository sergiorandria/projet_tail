#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int count_file_bytes(FILE *file)
{
	int buffer, c;
	
	while((c = fgetc(file)) != EOF)
		++buffer;
	
	return buffer;
}

/* The function for the -c option */
void count_bytes(FILE *file, int bytes)
{
	int i, c, buffer;
	
/* Have to count first the number of bytes in the file */
	for(i=0; (c = fgetc(file)) != EOF; ++i)
		;
/* The number of bytes in the file. Has the value 0 if the file is empty */	
	buffer = i;
	
	c = 0;
	for(i = 0; (c = fgetc(file)) != EOF; ++i){ 
		if (i >= (buffer - bytes))
			putchar(c);
	}
}

/* This function is for the -n option */
void number_of_line(FILE *fd, int len, int line)
{
	int c, ptr = 0;

    while((c=fgetc(fd)) != EOF)
    {
        if(c == '\n')
            ++ptr;

        if( ptr >= (len - line))
            putchar(c);
	
	}
} 

/* This function is for the -f function */
void follow_as_grows(FILE *fd, char *args)
{
    char c;
    int n, m;
	
	while ((c = fgetc(fd)) != EOF)
        putchar(c);
    
	while (1)
    {
        m = count_file_bytes(fd);
		if (m >= n)
        {
            n = m;
			fd = fopen(args, "r+");

			while ((c = fgetc(fd)) != EOF)
                putchar(c);
            
            fclose(fd);
        }
        sleep(1);
        system("clear");
    }
}

/* For the -v option */
void verbose(char *filename)
{
	printf("==> %s <==", filename);
/* It will continue with the standard tail_with_no_options */
}

/* For the --help option */
void help_display(int status)
{
	int c;
	FILE *fd = NULL;
	
	if (status != 0){
/* This file content the help output */
		fd = fopen("help.txt", "r+");
		if(fd == NULL){
			printf("No help file found");
			exit(1);
			}
		while((c = fgetc(fd)) != EOF )
			putchar(c);
	
		fclose(fd);
	}
}


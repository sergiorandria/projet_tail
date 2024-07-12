#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_OPT 15 

int *getopt(int argc, char **opt);
int verify_option(int argc, int *option, char **opt);
typedef enum 
{
		COUNT_BYTES,			/* this option is set to 0 */
		REAL_STATE_FOLLOW,
		LINE,
		MAX_UNCHANGED,
		PID,
		QUIET_STATE,
		RETRY,
		SLEEP_INTERVAL,
		VERBOSE,
		ZERO_TERMINATED,
		TAIL_HELP,
		TAIL_VERSION
}

int *getopt(int argc, char **opt) 
{
	int argv_index[MAX_OPT]; 
	int *option = NULL, *ptr_to_argv_index = NULL;

/* allocate an array which depends on the number of argument */
	option = (int *)malloc(argc * sizeof(int));
	if ( opt == NULL || option == NULL )
		goto error;

	
/* To get the option along the argv[] char
   Have to do a loop thru the end of the command line */
	
	ptr_to_argv_index = argv_index;
/* The loop test if the first letter of the option is a '-'. If so 
   it will append the pointer inside the option variable */
	for (int i = 1; i < argc; ++i){
		if (opt[i][0] == '-'){
			*ptr_to_argv_index = i;				/* To copy the content of the variable i to the argc */
			++ptr_to_argv_index;
			}		
		}
/* Verify if the option exist or not. If not, go to error*/
	if (verify_option(argc, argv_index, opt) != 0)
		goto error;
		
	return option;
	
error:
	perror(opt[1]);
	return NULL;
}

/* This function verify if the content of the command line exist */
int verify_option(int argc, int *option, char **opt)
{
	int i;
	int *nw_opt; 
	
/* This new pointer will store all integer corresponding to all options in **opt */
	nw_opt = (int *)malloc((strlen((char *)option)) * sizeof(int));
	if (nw_opt == NULL)
		return 0;
	
	for(i = 0; i < strlen(option); ++i)
	{
		switch((int)opt[option[i]]){
				case 'c':
					nw_opt[i] = COUNT_BYTES;
				case 'f':
					nw_opt[i] = REAL_STATE_FOLLOW;  
				case 'n':
					nw_opt[i] = LINE;
/*				case "--max-unchanged-stats=N":
					nw_opt[i] = MAX_UNCHANGED;			
				case "--pid=PID":
					nw_opt[i] = PID;			*/
				case 'q':
					nw_opt[i] = QUIET_STATE;
/*				case "--retry":
					nw_opt[i] = RETRY;			*/
				case 's':
					nw_opt[i] = SLEEP_INTERVAL;
				case 'v':
					nw_opt[i] = VERBOSE;
				case 'z':
					nw_opt[i] = ZERO_TERMINATED;
				default :
					return EXIT_SUCCESS;
				break;
			}
	}
	
	return EXIT_FAILURE;
}



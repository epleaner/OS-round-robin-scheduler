#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "schedule.h"

int quantum;

int main(int argc, char *argv[]) {

	if(argc < 2) {
		printf("usage: schedule quantum [prog 1 [args] [: prog 2 [args] [: prog3 [args] [: … ]]]]\n");
		exit(-1);
	}
	
	quantum = strtol(argv[1], NULL, 10);
	
	if(argc > 2) {
		processChildCmds(argc - 2, argv + 2);
	}	
}

void processChildCmds(int argc, char *argv[]) {
	char *currProc, *currArg;
	char **args;
	int i, ndx;
	for(i = 0; i < argc; ) {
	
		ndx = 0;
		args = (char **) malloc(sizeof(char *) * MAX_ARGUMENTS);
		
		currProc = argv[i++];
		
		do {
			currArg = argv[i++];
			
			if(strcmp(currArg, ":") != 0) {
				args[ndx++] = currArg;
			}	
			
		} while(strcmp(currArg, ":") != 0 && i < argc);
		
		startChild(currProc, args);
	}
}

void startChild(char *proc, char *args[]) {
	printf("Process to fork/exec: %s\n", proc);
	printf("Arguments: %s %s %s\n", args[0], args[1], args[2]);
}
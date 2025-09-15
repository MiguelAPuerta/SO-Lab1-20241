#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000
#define MAX_LEN 100000

int main(int argc, char **argv){
	
	FILE *input = NULL;
	FILE *output = NULL;
	char *lines[MAX_LINES];
	char buffer[MAX_LEN];
	int count = 0;
	
	for (int i = 0; i < MAX_LINES; i++) {
		lines[i] = NULL;
	}
	
	if (argc == 1) {
		
		input = stdin;
		output = stdout;
	} 
	else if (argc == 2) {
		
		input = fopen(argv[1], "r");
		if (!input) {
			
			fprintf(stderr,"error: cannot open file\n");
			exit(1);
		}
		output = stdout;
	}
	else if (argc == 3) {
		
		input = fopen(argv[1], "r");
		if (!input) {
			
			fprintf(stderr,"error: cannot open file\n");
			exit(1);
		}
		
		output = fopen(argv[2], "w");
		if (!output) {
			
			fprintf(stderr,"error: cannot open file\n");
			fclose(input);
			return 1;
		}
	}
	else {
		
		fprintf(stderr, "usage: reverse <input> <output>\n");
		exit(1);
	}
	
	
	while (fgets(buffer, MAX_LEN, input) != NULL) {
		
		if(count >= MAX_LINES) {
			
			fprintf(stderr, "Demasiadas lineas (maximo %d)\n", MAX_LINES);
			break;
		}
		
		lines[count] = malloc(strlen(buffer) + 1);
		if (!lines[count]) {
			fprintf(stderr, "malloc failed\n");
			exit(1);
		}
		
		strcpy(lines[count], buffer);
		
		count++;
	}
	
	
	for (int i = count - 1; i >= 0; i--) {
		if (lines[i]) {
			
			fputs(lines[i], output);
			free(lines[i]);
		}
	}
	
	
	if (input != stdin) {
		
		fclose(input);
	}
	if (output != stdout) {
		
		fclose(output);
	}
	
	
	return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000
#define MAX_LEN 1024

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
			
			perror("Error al abrir archivo de entrada");
			return 1;
		}
		output = stdout;
	}
	else if (argc == 3) {
		
		input = fopen(argv[1], "r");
		if (!input) {
			
			perror("Error al abrir archivo de entrada");
			return 1;
		}
		
		output = fopen(argv[2], "w");
		if (!output) {
			
			perror("Error al abrir archivo de salida");
			fclose(input);
			return 1;
		}
	}
	else {
		
		fprintf(stderr, "Uso: %s [input] [output]\n", argv[0]);
		return 1;
	}
	
	
	while (fgets(buffer, MAX_LEN, input) != NULL) {
		
		if(count >= MAX_LINES) {
			
			fprintf(stderr, "Demasiadas lineas (maximo %d)\n", MAX_LINES);
			break;
		}
		
		int len = strlen(buffer);
		
		lines[count] = malloc(strlen(buffer) + 1);
		if (!lines[count]) {
			perror("Error de memoria");
			return 1;
		}
		
		strncpy(lines[count], buffer, len + 1);
		
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


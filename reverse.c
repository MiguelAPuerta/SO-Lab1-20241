#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv){
	// inicializacion de las variables
	FILE *input = NULL;
	FILE *output = NULL;
	char **lines = NULL;
	char *line = NULL;
	int count = 0;
	size_t len = 0;
	ssize_t read;
	
	
	// analisis de los argumentos de entrada
	if (argc == 1) {
		// input y output por defecto cuando solo se usa ./reverse
		printf("Ingrese las lineas que quiera que sean reversadas, use Ctrl + D para finalizar\n");
		input = stdin;
		output = stdout;
	} 
	else if (argc == 2) {
		// lee el archivo y el output por defecto cuando se usa ./reverse <input>
		input = fopen(argv[1], "r");
		if (!input) {
			
			fprintf(stderr,"error: cannot open file\n");
			exit(1);
		}
		output = stdout;
	}
	else if (argc == 3) {
		// lee el archivo y el escribe al output cuando se usa ./reverse <input> <output>
		// comprueba que el input and output no sean el mismo
		if (strcmp(argv[1], argv[2]) == 0) {
			fprintf(stderr, "El archivo de entrada y salida deben diferir\n");
			exit(1);
		}
		
		input = fopen(argv[1], "r");
		if (!input) {
			
			fprintf(stderr,"error: cannot open file\n");
			exit(1);
		}
		output = fopen(argv[2], "w");
		if (!output) {
			
			fprintf(stderr,"error: cannot open file\n");
			fclose(input);
			exit(1);
		}
	}
	else {
		// se usaron mas argumentos de los esperados
		fprintf(stderr, "usage: reverse <input> <output>\n");
		exit(1);
	}
	
	// lectura del input con reajuste dinamico de memoria usando realloc para incrementar la memoria que se usa por linea
	while ((read = getline(&line, &len, input)) != -1) {
		// se lee y obtiene la linea y se realoca memoria dependiendo de cuanta se necesite
		char **tmp = realloc(lines, (count + 1) * sizeof(char*));
		if (!tmp) {
			// si se encuentra un problema se libera toda la memoria usada hasta ahora para evitar problemas
			fprintf(stderr, "Error al redimensionar memoria");
			free(line);
			for (int i = 0; i < count; i++) {
				free(lines[i]);
			}
			free(lines);
			exit(1);
		}
		lines = tmp;
		lines[count] = line;
		line = NULL;
		count++;
	}
	free(line);
	
	// se escribe las lineas al output que puede set stdout o un archivo
	printf("Este es el resultado devuelto por el programa\n");
	for (int i = count - 1; i >= 0; i--) {
		if (lines[i]) {
			fputs(lines[i], output);
			free(lines[i]);
		}
	}
	
	// se libera la memoria guardada y se cierran los archivos leidos que no sean stdin o stdout
	free(lines);
	if (input != stdin) {
		
		fclose(input);
	}
	if (output != stdout) {
		
		fclose(output);
	}
	
	return 0;
}


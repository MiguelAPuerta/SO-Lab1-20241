
# Práctica 1 de laboratorio - Introducción al lenguaje C

## Integrantes:

### Miguel Angel Puerta Vasquez - 1000760164
### N/A - 

## Desarrollo

Se realizo la practica dentro del archivo llamado reverse.c, este se encarga de reversar las lineas ingresadas en un input, este puede ser ingresado mediante un archivo dado por el usuario o ingresado por el usuario al ejecutar el programa.

Esta practica posee 3 documentos de prueba para probar la funcionalidad del programa:
- shortTest.txt
- longChain.txt
- longFile.txt
El primero se encargara de ser un archivo pequeño con solo 5 filas que no sean muy largas para pruebas basicas, el segundo tendra una fila con mas de 100 palabras y el ultimo tendra alrededor de 80 filas, todos estos con el fin de ser usados en la prueba y estando al mismo nivel que el archivo ./reverse base.

Se usara el siguiente comando para que el usuario ingrese el input dentro de la entrada estandar del programa, y este devolvera los resultados en la salida estandar, que en este caso es el output base de linux.

```sh
prompt> ./reverse
```

Este comando es usado para reversar un input dado por un documento de entrada, este sera leido y los resultados seran entregados a la salida estandar del programa.

```sh
prompt> ./reverse input.txt
```

Finalmente este comando se encargara de reversar un archivo de input y de entregar las lineas reversadas a un archivo output especificado por el usuario, este no mostrara los resultados en la salida estandar.

```sh
prompt> ./reverse input.txt output.txt
```

Esta implementacion realizada para el desarrollo del reversador de lineas se encarga de asignar memoria dinamicamente dependiendo de la cantidad de palabras que posea cada linea, esto permite que no se tenga un limite para la longitud de la cadena y la longitud del archivo, junto con esto se verifica que si se pueda asignar correctamente esta memoria, en cuyo caso de que falle se saldra del programa y se avisara de un problema de malloc.

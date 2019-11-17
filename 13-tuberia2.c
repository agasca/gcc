#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/file.h>
#include <stdio.h>	//in-out
#include <string.h> //Indagacion WEB,   warning: incompatible implicit declaration of built-in function ‘exit’ [enabled by default]
#include <stdlib.h> //Patrocinio Diego, warning: incompatible implicit declaration of built-in function ‘exit’ [enabled by default]

/*
Autor: John Doe,
Fecha: 	2018-05-16
		|    |  |
		|    |  --> Dia
		|    -----> Mes				
		----------> Año
			
Este proceso en concurrencia (se ejecutaran varios ejemplares del programa)
sobre los primeros 100 caracteres de un archivo 
Para resolver el porblema de la exclusion mutua sobre el acceso, se coloca 
un candado bloqueante (lock), utilizamos
la funcion lockf(), cuyo primer parametro es un descripto de archivo abiero, 
ya sea para lectura o para escritura.

F_UNLOCK	ELIMINACION DEL CANDADO
F_LOCK 		CANDADO EXCLUSIVO CON MODO BLOQUEANTE
F_TLOCK 	CANDADO EXCLUSIVO EN MODO NO BLOQUEANTE
F_TEST 		COMPORBACION DE LA EXISTENCADE UN CANDADO
//
*/

//se ejecutar
// ./13-tuberia2 & ./13-tuberia2 & ./13-tuberia2 &

void main(){
	//limpia pantalla
	system("clear");

	//inicializa
	int d;
	char buffer[100];

	d = open("archivo", O_RDWR | O_CREAT, S_IRWXU, 0);
	write(d, buffer, 100);

	if (lockf(d, F_LOCK, 100) == -1){
		perror("lockf");
	}
	printf("Proceso %d: candado colocado\n", getpid());
	sleep(5);
	printf("Proceso %d: candado eliminado\n", getpid());
	lockf(d, F_ULOCK, 100);
}

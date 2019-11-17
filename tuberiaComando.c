#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h> //warning: incompatible implicit declaration of built-in function ‘exit’ [enabled by default]
#include <stdlib.h> //warning: incompatible implicit declaration of built-in function ‘exit’ [enabled by default]

/*
Input
1) ls | wc
2) cat /etc/passwd | grep bash | wc –lines

Output:
Proceso de tuberia tipo linea de comando ls | wc
      7       7      64


12-tuberia
12-tuberia.c
13-tuberia2
13-tuberia2.c
archivo
palabra
palabra.c
	Nota:
	la lista desplegada contiene 76 letras, 7 saltos de linea o renglones,  7 palabras

Donde:
	ls - list directory contents
	wc - print newline, word, and byte counts for each file


URL:
	https://www.programacion.com.py/escritorio/c/pipes-en-c-linux
	https://www.geeksforgeeks.org/c-program-demonstrate-fork-and-pipe/	
	https://www.geeksforgeeks.org/c-program-demonstrate-fork-and-pipe/

Notas:
-The first argument is the program to run, the remaining arguments are the argv[] array for the program. 
    You were missing argv[0], which contains the name of the program being run.
    So gcc thought it was being run with the name shoum.c and no filename parameters.    
-main
    int main( int argc, char **argv )
    return 0;
*/

void main(void){
	//limpia pantalla
	system("clear");
	//inicializa
	printf("Proceso de tuberia tipo linea de comando ls | wc\n");
	int fd[2]; //arreglo para los dos procesos
	pid_t pid;
    char comando[] = "grep";
    char archivo[] = "grep";
    char parametro[] = "34";
	
	//
	if (pipe(fd) < 0){
		perror("Error en el tuberia");
		exit(-1);
	}

	//
	pid = fork();
	switch(pid){
		case -1: 					//error
			perror("error en el fork");
			exit(-1);
		case 0: 					//proceso hijo ejecuta ls
			close(fd[0]); 			//cierra pipe de lectura
			close(STDOUT_FILENO);	//cierra la salida estandar
			dup(fd[1]);
			close(fd[1]);
            //execlp("ls","ls",NULL);
            execlp("ls","ls","-l",NULL);
			perror("execlp");
			exit(-1);
		default:					//proceso padre ejecuta wc
			close(fd[1]); 			//cierra pipe de escritura
			close(STDIN_FILENO);	//cierra la salida estandar
			dup(fd[0]);
			close(fd[0]);
            //execlp("wc","wc",NULL);
            //execlp("grep","grep","34",NULL);
            //                      |
            //                      --parametro
            //Run Bash By Creating New Process
			//execlp("grep","grep","34",NULL);
            execlp(comando,archivo,parametro,NULL);
            
			perror("execlp");
	}
}

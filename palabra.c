#include <stdio.h>
#include <stdbool.h>				//gestion de bool
#include <string.h>					//gestion de cadenas
#include <stdlib.h>					//System(clear)


//20191101
//main
//
int main(int argc, char *argv[]){
	//inicializa
	char caracter = 'a';			//comilla sencilla letra
	char cadena[7] = "México";		//comilla doble para cadena
	char name[25]; 
	char str[] = "NovemBeR"; 
	char str1[] = "Look Here";
	char string[26] = {'\0'}; 		//utilizar uno mas 25 -> 25+1 = 26; null symbol 
	char delimitador = 'b';

	int  contadorDelimitador = 0;
	int av = 0;						//declaracion de variable: ejemplo apuntador entero
	int *ay;						//apuntador de la declaracion de variable: ejemplo apuntador
									//equivalencia en una linea, ver debajo
									//int *ay = &av;
	ay = &av;						//almacena la direccion de la variable av dentro del apuntador *ay
	
	char *ch1;						//ejemplo apuntador caracter
	char aStr[]="Hello Guru99!";
	char *ap;
	ap=aStr;


	system("clear"); 				//clears the screen


									//https://www.codingame.com/playgrounds/14213/how-to-play-with-strings-in-c/string-length-string-comparison
	printf("Numero de caractéres en la palabra \'%s\' es.........: %ld\n", str1, strlen(str1)); 
	printf("El valor de la variable 'caracter' tipo de dato 'char' es.: %c<-\n", caracter);
	printf("El valor de la variable 'cadena' tipo de dato 'char' es...: %s<-\n", cadena);	
	printf("El valor de la variable 'string' tipo de dato 'char' es...: %s<-\n", string);	


	printf("         1         2         3         4         5\n");
	printf("12345678901234567890123456789012345678901234567890\n");
		  //Francisco Irwin Arroyo
									/*
									sin utilizar espacios porque...
									https://stackoverflow.com/questions/36467134/confused-about-gcc-and-scanf-in-c
									can read the input till the first white-space. So the input buffer from the white-space is unused which is
									available for the next scanf which automatically starts reading from the buffer. So if you enter a string with
									spaces, the white-space will be assigned to the character
									*/

									//https://www.includehelp.com/c/c-program-to-read-string-with-spaces-using-scanf-function.aspx
	printf("Registra nombre..: "); 
									//se reemplaza scanf("%s", string);
	fgets(string,26,stdin); 		//https://stackoverflow.com/questions/36467134/confused-about-gcc-and-scanf-in-c
									/*	
									if( scanf(" %s", string) == 1){
										while(getchar()!='\n'){
											printf("1----\n");
										continue;
										}
									}
									*/
	printf("El nombre es.....: %s<-\n", string);
									//https://www.geeksforgeeks.org/difference-strlen-sizeof-string-c-reviewed/
	printf("Longitud de la cadena es.: %lu<-\n", strlen(string)); 
	printf("Tamaño de la cadena es...: %lu<-\n", sizeof(string)); 
	printf("\n");
									//ciclo leer letra
	for(int i = 0; i < strlen(string); i++){
									//printf("el valor de la letra es %c\n", string[i]);
		if(string[i] == delimitador){
									//printf("el valor de la letra es %c y el indice es %d\n", string[i], i);
			contadorDelimitador+=1;
		}
	}
	printf("Delimitador--->%c<---\n",delimitador);
	printf("total de contadores %d\n", contadorDelimitador);
	printf("\n\n");


									/*
									Apuntadores
									https://www.guru99.com/c-pointers.html
									* declara apuntador, develve el valor de la varable referenciada
									& devuelve la direccion de la variable

									Conversion specs format
									http://www.pixelbeat.org/programming/gcc/format_specs.html
									*/
	printf("Apuntadores con datos numericos\n");
	printf("valor de av.....->%d<-\n", av);
	printf("apuntador de &av->%p<-\n", &av);
	printf("apuntador de &ay->%p<-\n", &ay);
	printf("apuntador de *ay->%d<-\n", *ay);
									//accesando la direccion
	printf("Direccion almacenada en av variable ay es :%p\n",ay);
									//accesando el valor
	printf("Valor almacenado en av variable ay es     :%d\n",*ay);
	
	printf("\n\n");
	printf("Apuntadores con cadenas\n");
	printf("El primer caracter de la cadena es.:%c\n",*ap);
	ap+=1;
	printf("El siguiente caracter es...........:%c\n",*ap);
	printf("todos los caracteres de la cadena..:\n");
									//reset al apuntador
	ap=aStr;  
	for(int i=0;i<strlen(aStr);i++){
		printf("%c\n",*ap);
		ap++;
	}
}



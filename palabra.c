#include <stdio.h>
#include <stdbool.h>
#include <string.h>


//main
//
int main(int argc, char *argv[]){
	//inicializa
	char caracter = 'a'; //comilla sencilla letra
	char cadena[6] = "México";
    char name[25]; 
	char str[] = "NovemBeR"; 
	char str1[] = "Look Here";
	char string[26] = {'\0'}; //utilizar uno mas 25 -> 25+1 = 26; null symbol 
	char delimitador = 'b';
	int  contadorDelimitador = 0;



	system("clear"); //clears the screen

	printf("Numero de caracteres en la palabra \'%s\' es.........: %d\n", str1, strlen(str1)); //https://www.codingame.com/playgrounds/14213/how-to-play-with-strings-in-c/string-length-string-comparison
	printf("El valor de la variable 'caracter' tipo de dato 'char' es.: %c<-\n", caracter);
	printf("El valor de la variable 'cadena' tipo de dato 'char' es...: %s<-\n", cadena);	
	printf("El valor de la variable 'string' tipo de dato 'char' es...: %s<-\n", string);	


	printf("         1         2         3         4\n");
	printf("1234567890123456789012345678901234567890\n");
    //                    alberto gasca bernal
	/*
	sin utilizar espacios porque...
	https://stackoverflow.com/questions/36467134/confused-about-gcc-and-scanf-in-c
	can read the input till the first white-space. So the input buffer from the white-space is unused which is
	available for the next scanf which automatically starts reading from the buffer. So if you enter a string with
	 spaces, the white-space will be assigned to the character
	*/

	printf("Registra nombre..: \n"); //https://www.includehelp.com/c/c-program-to-read-string-with-spaces-using-scanf-function.aspx
	//scanf("%s", string);
	fgets(string,26,stdin); //https://stackoverflow.com/questions/36467134/confused-about-gcc-and-scanf-in-c
	/*	
	if( scanf(" %s", string) == 1){
		while(getchar()!='\n'){
			printf("1----\n");
		continue;
		}
	}
	*/

	printf("El nombre es.....: %s<-\n", string);
	printf("Longitud de la cadena es.: %lu<-\n", strlen(string)); //https://www.geeksforgeeks.org/difference-strlen-sizeof-string-c-reviewed/
	printf("Tamaño de la cadena es...: %lu<-\n", sizeof(string)); 
	printf("\n");


	//ciclo letra
	for(int i = 0; i < strlen(string); i++){
		//printf("el valor de la letra es %c\n", string[i]);
		if(string[i] == delimitador){
			//printf("el valor de la letra es %c y el indice es %d\n", string[i], i);
			contadorDelimitador+=1;
		}
	}
	printf("Delimitador--->%c<---\n",delimitador);
	printf("total de contadores %d\n", contadorDelimitador);
	printf("\n");
}


/*
apuntadores
*/

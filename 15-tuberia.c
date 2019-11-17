#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/file.h>
#include <stdio.h>	//in-out
#include <string.h> //Indagacion WEB,   warning: incompatible implicit declaration of built-in function ‘exit’ [enabled by default]
#include <stdlib.h> //Patrocinio Diego, warning: incompatible implicit declaration of built-in function ‘exit’ [enabled by default]


//URL: https://www.geeksforgeeks.org/pipe-system-call/

// C program to illustrate 
// pipe system call in C 
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/file.h>
#include <stdio.h>	//in-out
#include <string.h> //Indagacion WEB,   warning: incompatible implicit declaration of built-in function ‘exit’ [enabled by default]
#include <stdlib.h> //Patrocinio Diego, warning: incompatible implicit declaration of built-in function ‘exit’ [enabled by default]


//url: https://www.geeksforgeeks.org/pipe-system-call/


#define MSGSIZE 16 

char* msg1 = "hello, world #1"; 
char* msg2 = "hello, world #2"; 
char* msg3 = "hello, world #3"; 

int main() 
{ 
	char inbuf[MSGSIZE]; 
	int p[2], i; 

	if (pipe(p) < 0) 
		exit(1); 

	/* continued */
	/* write pipe */

	write(p[1], msg1, MSGSIZE); 
	write(p[1], msg2, MSGSIZE); 
	write(p[1], msg3, MSGSIZE); 

	for (i = 0; i < 3; i++) { 
		/* read pipe */
		read(p[0], inbuf, MSGSIZE); 
		printf("%s\n", inbuf); 
	} 
	return 0; 
} 

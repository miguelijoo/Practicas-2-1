#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv){
	if(argc!=2){
		printf("Error, introduzca el programa y el número a calcular el factorial.\n");
		exit(EXIT_FAILURE);
	}
	int n=atoi(argv[1]);
	if(n<0){
		printf("Error, el número debe ser positivo.\n");
		exit(EXIT_FAILURE);
	}
	else if(n==0){
		printf("El factorial es 1.\n");
		exit(EXIT_SUCCESS);
	}
	else{
	int resultado=1;
		for(int i=n;i>0;i--){
			resultado=resultado*i;
			printf("%d ", resultado);
			fflush(stdout);
			sleep(1);
		}
		printf("\n");
		printf("El factorial es %d.\n", resultado);
		exit(EXIT_SUCCESS);
	}
}

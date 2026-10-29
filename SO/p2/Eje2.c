#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void * leerlineas(void *pfich){
	FILE 
}

int main(int argc, char **argv){
	if(argc<2){
		printf("Introduce al menos un fichero para leer las lineas.\n");
		exit(EXIT_FAILURE);
	}
	pthread_t vth[argc-1];
	FILE *fich;
	for(int i=1;i<=argc;i++){
		fich=fopen(argv[i], "r");
		pthread_create(&idth[i-1], NULL, (void *) leerlineas, (void *) fich);
	}
}

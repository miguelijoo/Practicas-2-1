#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void * leerlineas(void *pfich){
	FILE *fich = (FILE *) pfich;
	int *n=(int *) malloc(sizeof(int));
	if(n==NULL){
		printf("Error al crear el puntero del elemento que cuenta líneas.\n");
		exit(EXIT_FAILURE);
	}
	char cad[100];
	while(fgets(cad, 100, fich)!=NULL){
		(*n)++;
	}
	pthread_exit((void *) n);
}

int main(int argc, char **argv){
	if(argc<2){
		printf("Introduce al menos un fichero para leer las lineas.\n");
		exit(EXIT_FAILURE);
	}
	pthread_t vth[argc-1];
	FILE *fich;
	for(int i=0;i<argc;i++){
		fich=fopen(argv[i+1], "r");
		if(pthread_create(&(vth[i]), NULL, (void *) leerlineas, (void *) fich)){
			fprintf(stderr, "Error al crear la hebra.\n");
			exit(EXIT_FAILURE);
		};
	}
	int *num;
	for(int i=0;i<argc;i++){
		if(pthread_join(vth[i],(void**) &num)){
			fprintf(stderr, "Error esperando a los hilos.\n");
			exit(EXIT_FAILURE);
		}
		printf("Fichero %d, total de líneas: %d.\n", i, *num);
	}
	printf("Hilo principal, no hay más hilos a esperar.\n");
	exit(EXIT_SUCCESS);
}

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
	*n=0;
	char cad[300];
	while(fgets(cad, 300, fich)!=NULL){
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
	for(int i=0;i<argc-1;i++){ //Sólo quiero leer todos los argumentos menos el inicial. Si hago solamente i<argc para "./Eje2 Eje1.c Hola.txt Leería fichero en argv[1], luego en argv[2] y por último en argv[3] dando un fallo de segmentación.
		fich=fopen(argv[i+1], "r");
		if(fich==NULL){
			fprintf(stderr, "Error al abrir el fichero.\n");
			exit(EXIT_FAILURE);
		}
		if(pthread_create(&(vth[i]), NULL, (void *) leerlineas, (void *) fich)){
			fprintf(stderr, "Error al crear la hebra.\n");
			exit(EXIT_FAILURE);
		};
	}
	int *num;
	for(int i=0;i<argc-1;i++){
		if(pthread_join(vth[i],(void**) &num)){
			fprintf(stderr, "Error esperando a los hilos.\n");
			exit(EXIT_FAILURE);
		}
		printf("Fichero %d, total de líneas: %d.\n", i+1, *num);
	}
	printf("Hilo principal, no hay más hilos a esperar.\n");
	exit(EXIT_SUCCESS);
}

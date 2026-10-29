#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <errno.h>
#include <time.h>
#include <string.h>

void* sumaral(void* v_arg){
	printf("Hilo hijo.\n");
	int *v_argu=(int *) v_arg;
	v_argu[0]=rand() % 10; //He puesto %10 para capar el rango entre 0 y 9, por probar y no desbordar el tipo de variable int.
	v_argu[1]=rand() %10;
	printf("Numero aleatorio 1: %d.\nNumero aleatorio 2:%d.\n", v_argu[0], v_argu[1]);
	v_argu[1]=v_argu[0]+v_argu[1];
	printf("Suma parcial: %d.\n", v_argu[1]);
	pthread_exit(NULL);
}

int main(){
	srand(time(NULL));
	printf("Ponga el numero de hebras a crear: ");
	int n, al[2], suma=0;
	scanf("%d", &n);
	if(n<=0){
		printf("Error, debe introducir un numero mayor que 0.\n");
		exit(EXIT_FAILURE);
	}
	pthread_t v_hebras[n];
	for(int i=0;i<n;i++){
		if(pthread_create(&v_hebras[i], NULL, (void *) sumaral, (void *) al)){
			fprintf(stderr,"Error creating thread. Errno value: %d meaning: %s.\n", errno, strerror(errno));
			exit(EXIT_FAILURE);
		}
		printf("Esperando a la hebra %d.\n", i);
		if(pthread_join(v_hebras[i], NULL)){
			fprintf(stderr, "Error waiting thread. Errno value: %d meaning: %s.\n", errno, strerror(errno));
		}
		suma=suma+al[1];
		printf("Suma hebra principal parcial: %d.\n", suma);
	}
	printf("Hilo principal, no hay más hilos que esperar.\n");
	exit(EXIT_SUCCESS);
}

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;

int n=0;

void *suma(void *arg){
	int *inc = (int *) arg;
	pthread_mutex_lock(&mtx);
	printf("Soy el hilo %lu y voy a incrementar la variable en %d.\n", pthread_self(), *inc); 
	n+=*inc;
	pthread_mutex_unlock(&mtx);
	pthread_exit(NULL);
}

int main(int argc, char **argv){
	if(argc!=2){
		printf("Error, introduzca solamente el programa y el número de hilos a crear.\n");
		exit(EXIT_FAILURE);
	}
	int nhilos = atoi(argv[1]), vcont[nhilos];
	pthread_t vth[nhilos];
	for(int i=0;i<nhilos;i++){
		vcont[i]=i+1;
		if(pthread_create(&vth[i], NULL, (void *) suma, (void *) &vcont[i])){
			fprintf(stderr, "Error al crear el hilo.\n");
			exit(EXIT_FAILURE);
		}
	}
	for(int i=0;i<nhilos;i++){
		if(pthread_join(vth[i], NULL)){
			fprintf(stderr, "Error al recoger el  hilo.\n");
			exit(EXIT_FAILURE);
		}
	}
	printf("Hilo principal, imprimiendo el valor de la variable global: %d.\n", n);
	pthread_mutex_destroy(&mtx);
	exit(EXIT_FAILURE);
}

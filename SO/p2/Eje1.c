#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

void* sumaral(void* v_arg){
	printf("Hilo hijo.\n");
	int *v_argu=(int *) v_arg;
}

int main(){
	srand(time(NULL))
	printf("Ponga el numero de hebras a crear: ");
	int n, al[2], suma=0;
	scanf("%d", &n);
	if(n<=0){
		printf("Error, debe introducir un numero mayor que 0.\n");
		exit(EXIT_FAILURE);
	}
	pthread_t v_hebras[n];
	for(int i=0;i<n;i++{
		if(pthread(&v_hebras[i], NULL, (void *) sumaral, (void *) al)){
			fprintf(stderr,"Erro creating thread.\n");
			exit(EXIT_FAILURE);
		}
		suma=suma+al[1];
	}
}

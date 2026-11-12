#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

struct indices{
		int *p1, *p2;
}indices;

void *sumaparcial(void *stind){
	struct indice *ith=(struct indice*) stind;
	int *resp= (int *) malloc(sizeof(int));
	if(resp==NULL){
		fprintf(stderr, "No ha sido posible crear la variable con malloc.\n");
		exit(EXIT_FAILURE);
	}
	*resp=0;
	while(ith->p1<=ith->p2){
		*resp+=ith->(*p1);
		(ith->p1)++;
	}
	pthread_exit((void *) resp);
}

int main(int argc, char **argv){
	srandtime(NULL));
	if(argc!=2){
		printf("No hay argumentos suficientes, ponga si reparte en 2 o 5 hilos.\n");
		exit(EXIT_FAILURE);
	}
	int n=atoi(argv[1]);
	if(n!=2 && n!=5){
		printf("Error, introduzca 2 o 5 como números.\n");
		exit(EXIT_FAILURE);
	}
	int v[10];
	for(int i=0;i<10;i++){
		v[i]=1+(rand() % 9);
	}
	int x=0, *sumap, sumatotal=0;
	*sumap=0;
	sumatotal=0;
	pthread vth[n];
	struct indice i_;
	for(int i=0;i<n;i++){
		if(n==2){
			i_.p1=&(v[x]);
			x+=4;
			i_.p2=&(v[x]);
			x++;
			if(pthread_create(&(vth[i]), NULL, (void *) sumaparcial, &indice i_)){
				fprintf(stderr, "Error al crear el hilo");
				exit(EXIT_FAILURE);
			}
			if(pthread_join(vth[i], (void **) &sumap)){
				fprintf(stderr, "No se ha podido hacer join.\n");
				exit(EXIT_FAILURE);
			}
			sumatotal+=*sumap;
		}
		else{
		
		}
	}
	printf("Hilo principal ejecutando, el resultado final de la suma de elementos es: %d.\n", sumatotal);
	exit(EXIT_SUCCESS);
}


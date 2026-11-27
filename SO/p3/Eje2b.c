#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

struct datos_main{
	int *num, inc;
	pthread_mutex_t *mtxaux;
};

void *suma(void *arg){
	struct datos_main *dth=(struct datos_main *) arg;
	pthread_mutex_lock(dth->mtxaux);
	printf("Soy el hilo %lu y voy a incrementar la variable %d veces.\n", pthread_self(), dth->inc);
	*(dth->num)+=dth->inc; //Primero se accede al atributo con la flecha ya que dth es puntero de estructura y luego se accede al interior del atributo con el asterisco puesto fuera del paréntesis. Si fuese una variable de estructura y no un puntero, también se hace así.
	pthread_mutex_unlock(dth->mtxaux);
	pthread_exit(NULL);
}

int main(int argc, char **argv){
	if(argc!=2){
		printf("Error, introduzca el nombre del programa y el número de hilos a crear.\n");
		exit(EXIT_FAILURE);
	}
	pthread_mutex_t mtx;
	if(pthread_mutex_init(&mtx, NULL)){
		fprintf(stderr, "Error al crear el mutex.\n");
		exit(EXIT_FAILURE);
	}
	int n=atoi(argv[1]), nsuma=0;
	struct datos_main d[n]; //Declaro un vector de estructuras ya que cada hilo incrementa en uno la variable contador, por tanto podría ocurrir que el hilo 1 tenga la variable con valor más alto del debido. LA suma, sin embargo, queda protegida ya que aunque la variable la use primero el hilo 2 luego el 1 y luego el 5, al estar protegida por el semáforo el dato cambia de manera uniforme, es lo mismo sumar 2+1+5 que 1+2+5.
	pthread_t vth[n];
	for(int i=0;i<n;i++){
		d[i].num=&nsuma;
		d[i].mtxaux=&mtx;
		d[i].inc=i+1;
		if(pthread_create(&vth[i], NULL, (void *) suma, (void *) &d[i])){
			fprintf(stderr, "Error al crear el hilo.\n");
			exit(EXIT_FAILURE);
		}
	}
	for(int i=0;i<n;i++){
		if(pthread_join(vth[i], NULL)){
			fprintf(stderr, "Error al recoger el hilo.\n");
			exit(EXIT_FAILURE);
		}
	}
	printf("Hilo principal, imprimiendo el valor final de la variable: %d.\n", *(d[0].num));
	exit(EXIT_SUCCESS);
}
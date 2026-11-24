#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;

struct datos_tienda{
	int *stock;
	int num_modelos;
};

void *compras(void *arg1){
	struct datos_tienda *daux=(struct datos_tienda*) arg1;
	srand(time(NULL));
	pthread_mutex_lock(&mtx);
	int ncompras, nelem;
	ncompras=1+(rand()%10); //Número del 1 al 10 de camisetas a comprar
	nelem=rand()%(daux->num_modelos); //Número de 0 al tamaño del vector de modelos de camisetas
	if(ncompras>=daux->stock[nelem]){ //Si compramos más camisetas de las disponibles se pondrá a 0 el contador de ese modelo de camiseta y se mostrarán todas las compradas
		printf("Soy el cliente %d y he comprado %d unidades de la camiseta %d.\n", pthread_self(), daux->stock[nelem], nelem);
		daux->stock[nelem]=0;
	}
	else{
		printf("Soy el cliente %d y he comprado %d unidades de la camiseta %d.\n", pthread_self(), daux->stock[nelem], nelem);
		daux->stock[nelem]-=ncompras;
	}
	pthread_mutex_unlock(&mtx);
	pthread_exit(NULL);
}

void *repuesta(void *arg2){
	struct datos_tienda *daux2=(struct datos_tienda *) arg2;
	srand(time(NULL));
	pthread_mutex_lock(&mtx);
	
	pthread_mutex_unlock(&mtx);
}



int main(int argc, char **argv){
	srand(time(NULL));
	if(argc!=3){
		printf("Error, debe escribir el programa y seguidamente el número de clientes y el de proveedores.\n");
		exit(EXIT_FAILURE);
	}
	int n1=atoi(argv[1]), n2=atoi(argv[2]); //Número de clientes y de proveedores y tipos de camisetas
	int vcam[n2];
	printf("Hay stock de %d tipos de camisetas antes de abrir la tienda.\n", n2);
	for(int i=0;i<n2;i++){
		vcam[i]=1+(rand() % 100);
		printf("%d ", vcam[i]);
	}
	
	pthread_t vthcl[n1], vthpr[n2]; //Declaración hilos de clientes y proveedores
	struct datos_tienda d1; //Estructura que se rellena con los datos del vector de camisetas y su tamaño para que las funciones lo usen. Se usará una sola estructura ya que será de sólo lectura, no se modifican datos de la estructura por tanto no habría problemas de concurrencia con esta estructura.
	d1.stock=vcam;
	d1.num_modelos=n2;
	//Creación hilos de clientes
	for(int i=0;i<n1;i++){
		if(pthread_create(&(vthcl[i], NULL, (void *) compras, (void *) &d1))){
			fprintf(stderr, "Error al crear el hilo.\n");
			exit(EXIT_FAILURE);
		}
	}
	//Creación hilos de proveedores	
	for(int i=0;i<n2;i++){
		if(pthread_create(&(vthpr[i]), NULL, (void *) repuesta, (void *) &d1)){
			fprintf(stderr, "Error al crear el hilo.\n");
			exit(EXIT_FAILURE);
		}
	}
	//Recogida de hilos de clientes
	for(int i=0;i<n1;i++){
		if(pthread_join(vthcl[i], NULL)){
			fprintf(stderr, "Error al recoger al hilo.\n");
			exit(EXIT_FAILURE);
		}
	}
	//Recogida de hilos de proveedores.
	for(int i=0;i<n2;i++){
		if(pthread_join(vthpr[i], NULL)){
			fprintf(stderr, "Error al recoger al hilo.\n");
			exit(EXIT_FAILURE);
		}
	}
	//Contador que cuenta el número de camisetas aún en stock.
	int cont=0;
	for(int i=0;i<n2;i++){
		if(vcam[i]!=0){
			cont++;
		}
	}
	printf("Hay stock de %d camisetas al cerrar la tienda.\n", cont);
	//Muestra del stock de todas las camisetas sean 0 o distinto de 0.
	for(int i=0;i<n2;i++){
		printf("%d ", vcam[i]);
	}
	exit(EXIT_SUCCESS);
}

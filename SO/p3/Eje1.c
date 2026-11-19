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

}

void *repuesta(void *arg2){

}



int main(int argc, char **argv){
	srand(time(NULL));
	if(argc!=3){
		printf("Error, debe escribir el programa y seguidamente el número de clientes y el de proveedores.\n");
		exit(EXIT_FAILURE);
	}
	int n1=atoi(argv[1]), n2=atoi(argv[2]); //Número de clientes y de proveedores y tipos de camisetas
	int vcam[n2];
	printf("Hay stock de %d camisetas antes de abrir la tienda.\n", n2);
	for(int i=0;i<n2;i++){
		vcam[i]=1+(rand() % 100);
		printf("%d ", vcam[i]);
	}
	
	pthread_t vthcl[n1], vthpr[n2]; //Declaración hilos de clientes y proveedores
	struct datos_tienda d1; //Estructura que se rellena con los datos del vector de camisetas y su tamaño para que las funciones lo usen. Se usará una sola estructura ya que será de sólo lectura, no se modifican datos de la estructura por tanto no habría problemas de concurrencia con esta estructura.
	d1.stock=vcam;
	d1.num_modelos=n2;
	
	for(int i=0;i<n1;i++){ //Creación hilos de clientes
		if(pthread_create(&(vthcl[i], NULL, ))){
			fprintf(sderr, "Error al crear el hilo.\n");
			exit(EXIT_FAILURE);
		}
	}
	for(int i=0;i<n2;i++){ //Creación hilos de proveedores
		if(pthread_create()){
			fprintf(sderr, "Error al crear el hilo.\n");
			exit(EXIT_FAILURE);
		}
	}
	for(int i=0;i<n1;i++){ //Recogida de hilos de clientes
		if(pthread_join(vthcl[i], )){
			fprintf(stderr, "Error al recoger al hilo.\n");
			exit(EXIT_FAILURE);
		}
	}
	for(int i=0;i<n2;i++){ //Recogida de hilos de proveedores.
		if(pthread_join(vthpr[i], )){
			fprintf(stderr, "Error al recoger al hilo.\n");
			exit(EXIT_FAILURE);
		}
	}
	int cont=0;
	for(int i=0;i<n2;i++){
		if(vcam[i]==0){
			cont++;
		}
	}
	printf("Hay stock de %d camisetas al cerrar la tienda.\n");
	for(int i=0;i<n2;i++){
		if(vcam[i]!=0){
			printf("%d ", v[i]);
		}
	}
	exit(EXIT_SUCCESS);
}

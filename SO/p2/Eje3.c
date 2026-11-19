#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

struct indice{
		int *p1, *p2;
}indice;

void *sumaparcial(void *stind){
	struct indice *ith=(struct indice*) stind;
	int *resp= (int *) malloc(sizeof(int));
	if(resp==NULL){
		fprintf(stderr, "No ha sido posible crear la variable con malloc.\n");
		exit(EXIT_FAILURE);
	}
	*resp=0;
	while(ith->p1<=ith->p2){
		*resp+=*(ith->p1);
		(ith->p1)++;
	}
	pthread_exit((void *) resp);
}

int main(int argc, char **argv){
	srand(time(NULL));
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
	//Asignación aleatorios
	for(int i=0;i<10;i++){
		v[i]=1+(rand() % 9);
		printf("%d\n", v[i]);
	}
	//Creación de variables necesarias para el ejercicio
	int x=0, *sumap, sumatotal=0;
	*sumap;
	sumatotal=0;
	pthread_t vth[n];
	struct indice i_;
	//Bucle que selecciona con los if si la suma se hará para 2 hilos o para 5
	for(int i=0;i<n;i++){
		if(n==2){
			i_.p1=&(v[x]);
			x+=4;
			i_.p2=&(v[x]);
			x++;
			if(pthread_create(&(vth[i]), NULL, (void *) sumaparcial, (void *) &i_)){
				fprintf(stderr, "Error al crear el hilo.\n");
				exit(EXIT_FAILURE);
			}

		}
		else{
			i_.p1=&(v[x]);
			x++;
			i_.p2=&(v[x]);
			x++;
			if(pthread_create(&(vth[i]), NULL, (void *) sumaparcial, (void *) &i_)){
				fprintf(stderr, "Error al crear el hilo.\n");
				exit(EXIT_FAILURE);
			}
		}
		//Se recogen también los hilos uno por uno para evitar concurrencia. Si no lo hiciese, el planificador a corto plazo podría meter antes en CPU el hilo principal, prosiguiendo el bucle y cambiando los índices de la estructura provocando que se pierdan sumas. Ejemplo: Para 2 hilos -> Hilo 1: de 0 a 4 hilo 2: de 5 a 9. Si el hilo principal ejecuta la segunda vuelta al bucle antes de que el hilo 1 haga las sumas, podría pasar que el hilo 1 tenga al ejecutarse (dado que se pasa la estructura como dirección de memoria, por tanto en la función sumaparcial hay un puntero que apunta a la estructura) los valores 5 y 9 en los punteros, perdiendo así datos de la suma y para el hilo 2 se repetiría esa suma u otra diferente si hubiera más hilos como el caso de repartir 5 hilos que ocurre lo mismo que aquí pero con más casos.
		if(pthread_join(vth[i], (void **) &sumap)){
			fprintf(stderr, "No se ha podido hacer join.\n");
			exit(EXIT_FAILURE);
		}
		sumatotal+=*sumap;
	}a
//NOTA: si no hago la recogida de hilos, necesitaría semáforos para evitar la concurrencia y no perder el paralelismo de hilos del todo.
	printf("Hilo principal ejecutando, el resultado final de la suma de elementos es: %d.\n", sumatotal);
	exit(EXIT_SUCCESS);
}


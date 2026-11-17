#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
int n=0;

void *incremento(void* arg){
	for(int i=0;i<1000000;i++){
		n++;
	}
	pthread_exit(NULL);
}

int main(){
	pthread_t vth[2];
	for(int i=0;i<2;i++){
		if(pthread_create(&(vth[i]), NULL, (void *) incremento, NULL)){
			fprintf(stderr, "Error al crear el hilo.\n");
			exit(EXIT_FAILURE);
		}
	}
	for(int i=0;i<2;i++){
		if(pthread_join(vth[i], NULL)){
			fprintf(stderr, "Error al recoger al hilo.\n");
			exit(EXIT_FAILURE);
		}
	}
	printf("Hilo principal, variable global incrementada exitosamente, resultado final: %d.\n", n);
	exit(EXIT_SUCCESS);
}

//No devuelve siempre 2 millones debido a que ocurre el efecto de concurrencia, donde un hilo lee una variable y quizá no ejecute el incremento antes que el otro hilo, por tanto si el hilo 1 lee en la variable 0, sale de CPU para entrar otro proceso o el hilo 2 que lee también 0 y este hilo 2 ejecuta un incremento, saliendo de CPU (o no) y entrando de nuevo el hilo 1, este tendrá igualmente el valor 0 en lectura, incrementará la variable y guardará el resultado en dicha variable, por tanto habrá habido no 2 incrementos tal que 0->1->2 sino que sería algo más como 0->1 (hilo 2) -- 0->1 (hilo 1)

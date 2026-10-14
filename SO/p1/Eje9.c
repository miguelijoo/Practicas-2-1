#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>

void tratarSennal(int);

void recibiralarma(int);

int main(){
	pid_t val;
	if(signal(SIGUSR1, tratarSennal) == SIG_ERR){
		perror("Error de signal");
		printf("Valor de errno: %d.\n", errno);
		exit(EXIT_FAILURE);
	}
	if(signal(SIGALRM, recibiralarma) == SIG_ERR){
		perror("Error de signal");
		printf("Valor de errno: %d.\n", errno);
		exit(EXIT_FAILURE);
	}
	val=fork();
	for(int i=0;i<5;i++){
		switch(val){
			case -1:
				perror("Error en fork");
				printf("Valor de errno: %d.\n", errno);
				exit(EXIT_FAILURE);
			case 0:
				pause();
				break; //CUIDADO QUE SI NO SE HACE BREAK SE METE EL HIJO AL DEFAULT Y APARECEN MÁS DE 5 MENSAJES PORQUE EJECUTA VARIAS VECES EL MISMO CÓDIGO EL HIJO JUNTO CON EL PADRE
			default:
				kill(val, SIGUSR1);
				alarm(1); //Es como un sleep pero con una alarma al usar como función el SIG_IGN
				pause();
		}
	}
	kill(getpid(), SIGKILL);
}

void tratarSennal(int sign){
	printf("Señal recibida.\n");
}

void recibiralarma(int sign2){
	/*Vacío, solamente para la alarma y volver al ciclo*/
}

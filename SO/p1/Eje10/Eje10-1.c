#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <signal.h>

void imprimirsenal(int);

int main(){
	if(signal(SIGUSR1, imprimirsenal) == SIG_ERR){
		perror("Error de signal");
		printf("Valor de errno: %d.\n", errno);
		exit(EXIT_FAILURE);
	}
	while(1){};
}

void imprimirsenal(int sign){
	printf("Mi id es %d.\n", getpid());
}

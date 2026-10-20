#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <signal.h>
#include <string.h>

void recibiralarma(int);

int main(int argc, char **argv){
	if(argc!=2){
		printf("Error, debe poner el proceso al que enviar la señal");
		exit(EXIT_FAILURE);
	}
	pid_t val;
	val=atoi(argv[1]);
	if(signal(SIGALRM, recibiralarma) == SIG_ERR){
		perror("Error en signal");
		printf("Valor de errno: %d.\n", errno),
		exit(EXIT_FAILURE);
	}
	kill(val, SIGUSR1);
	alarm(1);
	pause();
	kill(val, SIGKILL);
	
}

void recibiralarma(int sign){}

#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>

void sig_alarm(int);

int main(){
	pid_t idpadre;
	if(signal(SIGALRM, sig_alarm) == SIG_ERR){
		perror("Signal error");
		printf("Valor de errno: %d\n", errno);
		exit(EXIT_FAILURE);
	}
	int n=5, cont=0;
	while(1){
		if(cont==4){
			kill(getpid(), SIGKILL);
		}
		printf("Timbrazo %d\n", cont+1);
		if(n==1){
			alarm(n);
			cont++;
			pause(); //Lo pongo para que no se solapen alarmas y se omitan.
		}
		else{
			alarm(n);
			n=n-2;
			cont++;
			pause();
		}	
	}
}

void sig_alarm(int sig){
	printf("RING\n");
}

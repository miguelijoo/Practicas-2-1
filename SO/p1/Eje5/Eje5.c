#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char **argv){
	if(argc!=3){
		printf("Error, debe poner el programa y los 2 números a hacer factorial.\n");
		exit(EXIT_FAILURE);
	}
	pid_t hijo_pid, val;
	int status;
	for(int i=0;i<2;i++){
		val=fork();
		switch(val){
			case -1:
				perror("Error en fork:");
				printf("Valor de errno: %d.\n", errno);
				exit(EXIT_FAILURE);
			case 0:
				if(execl("./factorial","./factorial", argv[i+1], NULL)==-1){
					perror("Fallo en exec:");
					printf("Valor de errno: %d.\n", errno);
					exit(EXIT_FAILURE);
				}
			default:
				break;
		}
	}
	while((hijo_pid=wait(&status))>0){
		if(WIFEXITED(status)){
			printf("Hijo con id %d terminado correctamente con status: %d.\n", hijo_pid, WEXITSTATUS(status));
		}
		if(WIFSIGNALED(status)){
			printf("Hijo con id %d terminado por una señal de valor: %d.\n", hijo_pid, WTERMSIG(status));
		}
	}
	if(hijo_pid == (pid_t) -1 && errno == ECHILD){
		printf("Proceso padre, no hay más hijos que esperar. Valor de errno: %d definido como: %s.\n", errno, strerror(errno));
		exit(EXIT_SUCCESS);
	}
	else{
		printf("Error en el wait. Valor de errno: %d definido como: %s.\n", errno, strerror(errno));
		exit(EXIT_FAILURE);
	}
}

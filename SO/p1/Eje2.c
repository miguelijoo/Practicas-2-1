#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>

int main(int argc, char **argv){
	pid_t hijo_pid, val;
	int status, n=atoi(argv[1]);
	if(argc!=2){
		printf("Error, debe introducir como argumento el numero de procesos a crear\n");
		exit(EXIT_FAILURE);
	}
	
	for(int i=0;i<n;i++){
		val=fork();
		switch(val){
			case -1:
				perror("Ha habido un error en fork. ");
				printf("Valor de errno:%d\n", errno);
				exit(EXIT_FAILURE);
			case 0:
				printf("Soy el proceso hijo %d, con id %d. El id de mi padre es %d.\n", i, getpid(), getppid());
				exit(EXIT_SUCCESS);
			default:
				while((hijo_pid=wait(&status))>0){
					if(WIFEXITED(status)){
						printf("Soy el proceso padre y mi hijo con id %d ha terminado correctamente con status %d.\n", getpid(), hijo_pid, WEXITSTATUS(status));
					}
					else if(WIFSIGNALED(status)){
						printf("Soy el proceso padre y mi hijo con id %d no ha terminado correctamente, debido a la señal: %d.\n", hijo_pid, WTERMSIG(status));
					}
				}
		}
	}
	printf("Soy el proceso padre y no hay más hijos que esperar, fin del programa.\n");
	exit(EXIT_SUCCESS);
}

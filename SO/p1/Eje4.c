#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char **argv){
	if(argc<4){
		printf("Error, debe introducir el programa de calculadora, el de edicion de ficheros junto con al menos 1 fichero a editar\n");
		exit(EXIT_FAILURE);
	}
	pid_t hijo_pid, val;
	int status;
	for(int i=0;i<2;i++){
		val=fork();
		switch(val){
			case -1:
				perror("Error en fork");
				printf("Valor de errno: %d\n", errno);
				exit(EXIT_FAILURE);
			case 0:
				if(i==0){
					if(execlp(argv[1], argv[1], NULL)==-1){
						perror("Fallo en exec");
						printf("Valor de errno: %d\n", errno);
						exit(EXIT_FAILURE);
					}
				}
				else if(i==1){
					if(execvp(argv[2], argv+2)==-1){
						perror("Fallo en exec");
						printf("Valor de errno: %d\n", errno);
						exit(EXIT_FAILURE);
					}
				}
			default:
				break;
		}
	}
	while((hijo_pid=wait(&status))>0){
		if(WIFEXITED(status)){
			printf("Soy el padre y mi hijo de id %d ha terminado correctamente con status: %d.\n", hijo_pid, WEXITSTATUS(status));
		}
		if(WIFSIGNALED(status)){
			printf("Soy el padre y mi hijo de id %d no ha terminado con normalidad debido a la señal: %d.\n", hijo_pid, WTERMSIG(status));
		}
	}
	if(hijo_pid==(pid_t) -1 && errno==ECHILD){
		printf("Soy el padre, no hay más hijos que esperar. Valor de errno: %d definido como: %s\n", errno, strerror(errno));
	}
	else{
		printf("Error en wait, valor de errno: %d definido como %s\n", errno, strerror(errno));
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}

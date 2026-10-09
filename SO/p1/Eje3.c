#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char **argv){
	if(argc!=2){
		printf("Error, hay que poner el número de procesos a crear como argumento. \n");
		exit(EXIT_FAILURE);
	}
	pid_t hijo_pid, val;
	int n=atoi(argv[1]), status;
	if(n==0){
		printf("No hay procesos a crear, saliendo del programa.\n");
		exit(EXIT_FAILURE);
	}
	for(int i=0; i<n; i++){
		val=fork();
		switch(val){
			case -1:
				perror("Error en fork");
				printf("Valor de errno = %d\n", errno);
				exit(EXIT_FAILURE);
			case 0:
				printf("Soy el proceso hijo %d y mi id es %d, la de mi padre es %d\n", i, getpid(), getppid());
				sleep(10*(i+1));
				exit(EXIT_SUCCESS);
			default:
				break; //Aquí el padre no hace nada, simplemente ha creado a los hijos seguidos y ya, así lo tenemos todo en paralelo
		}
	}
	n=1;
	while((hijo_pid=wait(&status))>0){
		if(WIFEXITED(status)){
						printf("Soy el padre con id %d y mi hijo número %d ha finalizado correctamente con id %d y estado=%d\n", getpid(), n, hijo_pid, WEXITSTATUS(status));
						n++;
		}
		else if(WIFSIGNALED(status)){
						printf("Soy el padre con id %d y mi hijo  ha finalizado mal, con la señal: %d\n", getpid(), hijo_pid, WTERMSIG(status));
		}	
	}
	if(hijo_pid==(pid_t)-1 && errno==ECHILD){
		printf("Soy el proceso padre y no tengo más hijos que esperar. Valor de errno: %d definido como: %s\n", errno, strerror(errno));
	}
	printf("Soy el padre, ha terminado mi ejecución.\n");
	exit(EXIT_SUCCESS);
}

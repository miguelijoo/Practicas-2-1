#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char **argv){
	if(argc!=2){
		printf("Error, hay que poner el número de procesos a crear como argumento. \n");
		exit(EXIT_FAILURE);
	}
	pid_t hijo_pid, val;
	int n=atoi(argv[1]), status;
	for(int i=0; i<n;i++){
		val=fork();
		switch(val){
			case -1:
				perror("Error en fork");
				printf("Valor de errno = %d\n", errno);
				exit(EXIT_FAILURE);
			case 0:
				printf("Soy el proceso hijo %d y mi id es %d, la de mi padre es %d\n", i, getpid(), getppid());
				exit(EXIT_SUCCESS);
			default:
				break; //Aquí el padre no hace nada, simplemente ha creado a los hijos seguidos y ya, así lo tenemos todo en paralelo
		}
	}
	while((hijo_pid=wait(&status))>0){//Aplico el while porque el profe lo dice, pero en este ejercicio dado que por cada vez que se recorre el bucle se hace un fork(), sólo vamos a tener que hacer wait() para un hijo. Tras hacer el wait se acabará el bucle y se repetirá de nuevo, hasta terminar el bucle y hacer un exit final.
		if(WIFEXITED(status)){
						printf("Soy el padre con id %d y mi hijo ha finalizado correctamente con id %d y estado=%d\n",getpid(), hijo_pid, WEXITSTATUS(status));
		}
		else if(WIFSIGNALED(status)){
						printf("Soy el padre con id %d y mi hijo ha finalizado mal, con la señal: %d\n", getpid(), hijo_pid, WTERMSIG(status));
		}
	}
	printf("Soy el padre, ha terminado mi ejecución");
	exit(EXIT_SUCCESS);
}

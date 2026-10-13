#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <wait.h>
#include <errno.h>
#include <string.h>

int main(){
	printf("Introduzca el nombre del fichero a crear: ");
	char cad[100];
	int n, status;
	FILE *fichero;
	pid_t val, hijo_pid;
	fgets(cad, 100, stdin);
	if(cad[strlen(cad)-1]=='\n'){
		cad[strlen(cad)-1]='\0';
	}
	fichero=fopen(cad, "w");
	printf("Introduzca el número de proecsos hijos a crear: ");
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		val=fork();
		switch(val){
			case -1:
				perror("Error en fork:");
				printf("Valor de errno: %d.\n", errno);
				exit(EXIT_FAILURE);
			case 0:
				fprintf(fichero, "%d\n", i);
				fflush(fichero);
				exit(EXIT_SUCCESS);
			default:
				break;
		}
	}
	while((hijo_pid=wait(&status))>0){
		if(WIFEXITED(status)){
			printf("Proceso hijo con id %d terminado correctamente con estado: %d.\n", hijo_pid, WEXITSTATUS(status));
		}
		else if(WIFSIGNALED(status)){
			printf("Proceso hijo con id %d terminado por la señal: %d.\n", hijo_pid, WTERMSIG(status));
		}
	}
	fclose(fichero);
	if(hijo_pid = -1 && errno == ECHILD){
		printf("No hay procesos hijos a esperar, mostrando el fichero:\n");
		if(execlp("cat", "cat", cad, NULL)== -1){
			perror("Fallo en el exec de cat:");
			printf("Valor de errno: %d.\n", errno);
			exit(EXIT_FAILURE);
		}
	}
	exit(EXIT_SUCCESS);	//¿Es necesario esto o ya con el exec el proceso finaliza tras el cat automáticamente?
}

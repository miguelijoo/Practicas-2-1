#Temporal de comparación
3B 0
#Contador del bucle
3C 0
#Puntero al elemento actual
3D 0
#Índice de posición del vector
3E 0
#Inicio del vector
3F 42
#Fin del vector
40 46
#Clave a buscar
41 FFF2
#Elementos del vector
42 5
43 FFFF
44 9
45 FFF2
46 9
@
0
@
#Llamada a la búsqueda y fin del programa principal
CSR 2
HALT
#Casilla de retorno de la búsqueda
HALT
#Cálculo del contador inicial: -(N+1)
CRA
ITA
ITA
ADD 40
CTA
ITA
ADD 3F
STA 3C
#Preparación del puntero al inicio del vector
CRA
ADD 3F
STA 3D
#Control del bucle: continuar o terminar sin coincidencia
ISZ 3C
JMP 11
JMP 1B
#Comparación del elemento actual con la clave
CSR 20
#Si coinciden, saltar para devolver el índice
ROR_F_ACC
SFZ
JMP 18
#Avanzar índice y puntero; repetir el recorrido
ISZ 3E
ISZ 3D
JMP E
#Devolver el índice de la primera coincidencia
CRA
ADD 3E
JMPI 2
#Devolver 7FFF si no se encuentra la clave
CRA
CTA
CRF
ROR_F_ACC
JMPI 2
#Casilla de retorno de la comparación
HALT
#Calcular clave menos elemento actual
CRA
ADDI 3D
CTA
ITA
ADD 41
STA 3B
#Preparar diferencia menos uno para comprobarla con ISZ
CRA
CTA
ADD 3B
STA 3B
#Devolver 0 si son distintos o 1 si son iguales
CRA
ISZ 3B
JMPI 20
ITA
JMPI 20

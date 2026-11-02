#Elemento actual
1E 0
#Contador de bucle, al llegar a 0 para
1F 0
#Inicio y fin vector
20 23
21 2A
#Contador de negativos
22 0
#Elementos del vector
23 5
24 FFFF
25 9
26 FFF2
27 8000
28 0
29 FFF3
2A FFF4
@
0
@
#Cálculo de longitud del vector N=-(final-inicio+2). Al llegar a 0 fin de bucle
CRA
ITA
ITA
ADD 21
CTA
ITA
ADD 20
STA 1F
CRA
ADD 20
STA 1E
ISZ 1F
JMP E
JMP 17
#Bucle
CRA
ADDI 1E
ROL_F_ACC
#Si F es 0, positivo, si es 1, negativo
SFZ
#Si no es negativo (F=0), se salta a 15, si lo es (F=1), se salta a 14
JMP 14
JMP 15
#Se incrementa 22 (ya valía 0 así que no valdrá 0 en adelante) y se comprueba si es cero, que no lo será así que se pasa a la siguiente instrucción.
ISZ 22
#Se incrementa 1E para ir al siguiente elemento del vector, 1E nunca será 0 así que sería un incremento más cómodo que hacer ITA y otras instrucciones
ISZ 1E
#Se vuelve fuera del bucle a incrementar el contador y comprobar si es 0
JMP B
#Fin de programa
HALT

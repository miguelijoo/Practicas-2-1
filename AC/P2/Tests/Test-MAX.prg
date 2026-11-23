0 2
1 5
2 FFFE
3 FFFB
4 0
5 0
6 0
7 0
8 0
9 0
A 0
@
B
@
#ACC<GPR ambos positivos
CRA
ADD 0
MAX 1
STA 4
#ACC>GPR ambos positivos
CRA
ADD 1
MAX 0
STA 5
#ACC>GPR ambos negativos
CRA
ADD 2
MAX 3
STA 6
#ACC<GPR ambos negativos
CRA
ADD 3
MAX 2
STA 7
#ACC<GPR ACC negativo GPR positivo
CRA
ADD 2
MAX 0
STA 8
#ACC>GPR ACC positivo GPR negativo
CRA
ADD 0
MAX 2
STA 9
#ACC=GPR, da igual si positivo o negativo
CRA
ADD 2
MAX 2
STA A
HALT

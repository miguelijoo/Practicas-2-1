--Eje1
SELECT v.nombrecompleto FROM votantes v
WHERE SUBSTR(v.dni, -1)=v.localidad + 1;
--Eje2
SELECT v.nombrecompleto, DECODE(l.idlocalidad,
1, 'Madrid',
2, 'Madrid',
3, 'Madrid',
l.NOMBRE) nombre
FROM votantes v, localidades l
WHERE v.LOCALIDAD=l.IDLOCALIDAD;
--Eje3
SELECT p.siglas FROM partidos p, eventos_resultados er
WHERE p.idpartido=er.partido
GROUP BY p.siglas, p.idpartido --Se puede agrupar por siglas únicamente y funciona, pero pongo idpartido para que agrupe tal que (1, PP) (2, PSOE) y no PP PSOE
HAVING COUNT(*) >= ALL( --2. El COUNT externo hace su recuento en base al GROUP BY y comprueba si es mayor que lo devuelto en la consulta interna, es decir, si el externo para PP vale 10, comrpueba si 10>=10, 10>=5, 10>=8, etc... Si cumple todas se pone
                        SELECT COUNT(*) FROM EVENTOS_RESULTADOS --1. Hacemos recuento de todas las veces que aparece x partido en la tabla de eventos_resultados
                        GROUP BY partido
                    );
--Eje 4
SELECT v.dni FROM votantes v
WHERE v.fechanacimiento = (
                            SELECT MIN(fechanacimiento) FROM votantes
                            WHERE fechanacimiento >(
                                                        SELECT MIN(fechanacimiento) FROM votantes
                                                    )
                        );
SELECT MIN(fechanacimiento) FROM votantes;

SELECT * FROM votantes;
SELECT * FROM localidades;
SELECT * FROM eventos;
SELECT * FROM eventos_resultados;
SELECT * FROM partidos;
SELECT * FROM consultas_datos;
SELECT * FROM consultas;
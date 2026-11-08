--Eje 1
SELECT SUBSTR(v.nombrecompleto, 1, INSTR(v.nombrecompleto,' ')) AS nombre, l.nombre AS  Localidad, p.comunidad FROM votantes v, localidades l, provincias p
WHERE v.localidad=l.idlocalidad AND l.provincia=p.idprovincia AND (v.localidad=1 OR v.localidad=3 OR v.localidad=9);
--Eje 2
SELECT CONCAT(CONCAT(l.nombre, ' va antes que '), (
                                            SELECT nombre FROM localidades s
                                            WHERE s.idlocalidad = l.idlocalidad+1
                                        )
            ) AS Ordenación FROM localidades l; --Se pueden hacer subconsultas donde se haga referencia a atributos de la externa, como en este caso el idlocalidad interno con el id externo
--Eje 3
SELECT nombre FROM (
                    SELECT * FROM LOCALIDADES
                    WHERE numerohabitantes > (
                                                SELECT numerohabitantes FROM votantes, localidades
                                                WHERE localidad=idlocalidad AND fechanacimiento = (
                                                                                                    SELECT MIN(fechanacimiento) from votantes
                                                                                                    WHERE fechanacimiento > (
                                                                                                                    SELECT MIN(fechanacimiento) from votantes
                                                                                                                            )
                                                                                                    )
                                            )
                    );
--Eje 4
SELECT v.nombrecompleto, v.localidad, DECODE(( --En este decode lo que hacemos es establecer la fuente de donde pillaremos valores, que será un COUNT que irá votante a votante y devolverá 1 si cumple la condicición o 0 si no, aplicando el decode a dicho valor
                                                SELECT COUNT(*) FROM votantes s
                                                WHERE s.dni=v.dni AND s.fechanacimiento < ADD_MONTHS(SYSDATE, -50*12)
                                            ),
                                            1, 'mayor',
                                            'menor'
) AS mayoriaedad
FROM votantes v
WHERE v.localidad IN (2,4,8)
ORDER BY mayoriaedad DESC;
--Eje 5
SELECT l.nombre, l.numerohabitantes, p.comunidad FROM localidades l, provincias p
WHERE l.provincia=p.idprovincia AND p.idprovincia IN(1,2,3) AND l.numerohabitantes>ANY(
                                                                                        SELECT numerohabitantes FROM localidades
                                                                                        WHERE provincia=4
                                                                                        );
--Eje 6
SELECT v.nombrecompleto, COUNT(*) FROM votantes v, consultas c
WHERE v.dni=c.votante AND v.situacionlaboral='Activo'
GROUP BY v.nombrecompleto
HAVING COUNT(*)<(
                    SELECT AVG(r.participaciones) FROM (
                                            SELECT COUNT(*) AS participaciones FROM consultas c1
                                            GROUP BY c1.votante
                                        ) r
);
--Eje7
SELECT l.nombre FROM localidades l, votantes v
WHERE v.localidad=l.idlocalidad --Faltan localidades puesto que si no hay votantes con un v.localidad que coincida con algún l.idlocalidad no aparecerá. Si l.idlocalidad vale 10, aparecerá si hay al menos un votante con v.localidad=10 de modo que 10=10
GROUP BY l.nombre
ORDER BY AVG(
                DECODE(v.estudiossuperiores, --DECODE devuelve una columna entera de números que tiene el valor numérico de todos los votantes según sus estudios. AVG puede usar dicha columna de números
                        'Ninguno', 0,
                        'Basicos', 1,
                        'Superiores', 2,
                        'Doctorado', 3
                    )
            )DESC;
--Eje 8

SELECT * FROM votantes;
SELECT * FROM localidades;
SELECT * FROM provincias;
SELECT * FROM consultas;
SELECT * FROM consultas_datos;
SELECT * FROM eventos;
SELECT * FROM eventos_resultados;

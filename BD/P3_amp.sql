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

SELECT * FROM votantes;
SELECT * FROM localidades;
SELECT * FROM provincias;
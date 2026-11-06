--Eje 1
SELECT SUBSTR(v.nombrecompleto, 1, INSTR(v.nombrecompleto,' ')) AS nombre, l.nombre AS  Localidad, p.comunidad FROM votantes v, localidades l, provincias p
WHERE v.localidad=l.idlocalidad AND l.provincia=p.idprovincia AND (v.localidad=1 OR v.localidad=3 OR v.localidad=9);
--Eje 2
SELECT CONCAT(CONCAT(l.nombre, ' va antes que '), (
                                            SELECT nombre FROM localidades s
                                            WHERE s.idlocalidad = l.idlocalidad+1
                                        )
            ) AS Ordenación FROM localidades l; --Se pueden hacer subconsultas donde se haga referencia a atributos de la externa, como en este caso el idlocalidad interno con el id externo
SELECT * FROM votantes;
SELECT * FROM localidades;
SELECT * FROM provincias;
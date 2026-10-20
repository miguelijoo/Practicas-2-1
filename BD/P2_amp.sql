--Eje1
SELECT v.dni FROM votantes v
WHERE v.telefono LIKE '%6%6%' AND v.telefono NOT LIKE '%6%6%6%';
--Eje2
SELECT v.dni FROM votantes v
WHERE (v.telefono LIKE '%6%66%' OR v.telefono LIKE '%66%6%') AND v.telefono NOT LIKE '%6%6%6%6%';
--Eje3
SELECT l.nombre localidad_nombre, p.nombre nombre_provincia FROM localidades l, provincias p
WHERE substr(l.numerohabitantes, -1) LIKE substr(l.provincia, -1) AND l.provincia=p.idprovincia; --Redundante este último argumento ya que solo tienen un dígito las provincias, pero si tuviesen varios sería lo correcto
--Eje4
SELECT nombrecompleto FROM votantes
WHERE substr(DNI, -1) LIKE substr (telefono, -1);
--Eje5
SELECT nombrecompleto FROM votantes
WHERE nombrecompleto LIKE '%s%' AND fechanacimiento < '12/2/1990';
--Eje6
SELECT DISTINCT v.DNI, v.nombrecompleto FROM votantes v, consultas c --Aplico el distinct a DNI que es la clave primaria y es unívoca, a diferencia de nombre que puede haber 2 votantes con mismo nombre y omitiríamos 1 ya que tienen diferente DNI pero mismo nombre y hacemos el DISTINCT para el nombre
WHERE v.DNI = c.votante
ORDER BY v.DNI DESC;
--Eje7
SELECT c.votante FROM votantes v, consultas c
WHERE v.dni = c.votante
GROUP BY c.votante
HAVING COUNT(c.votante)>3;
--Eje8
SELECT c.votante, v.nombrecompleto, COUNT(c.votante) AS numero_consultas FROM votantes v, consultas c
WHERE v.dni = c.votante
GROUP BY c.votante, v.nombrecompleto
HAVING COUNT(c.votante)>3
ORDER BY COUNT(c.votante) ASC;
--Eje9
SELECT v.nombrecompleto, l.nombre FROM votantes v, localidades l
WHERE v.localidad=l.idlocalidad AND l.numerohabitantes>300000;
--Eje10
SELECT p.nombrecompleto, MAX(cd.certidumbre) AS maxima_certidumbre FROM partidos p, consultas_datos cd
GROUP BY p.nombrecompleto;
--Eje11
SELECT v.nombrecompleto, AVG(cd.certidumbre) FROM votantes v, consultas_datos cd, consultas c
WHERE c.idconsulta=cd.consulta AND cd.respuesta='Si'
GROUP BY v.nombrecompleto;
--Eje12
SELECT v.nombrecompleto, AVG(cd.certidumbre) FROM votantes v, consultas_datos cd, consultas c
WHERE c.idconsulta=cd.consulta AND cd.respuesta='Si'
GROUP BY v.nombrecompleto
HAVING AVG(cd.certidumbre)>=0.5 AND AVG(cd.certidumbre)<=0.8;
--Eje13
SELECT p.nombrecompleto, AVG(cd.certidumbre) FROM partidos p, consultas_datos cd
WHERE cd.partido=p.idpartido AND cd.respuesta='No' AND certidumbre>0.6
GROUP BY p.nombrecompleto;

SELECT * FROM consultas_datos;
SELECT * FROM consultas;
SELECT * FROM partidos;

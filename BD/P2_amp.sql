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
WHERE nombrecompleto LIKE '%s%' AND fechanacimiento < DATE '1990-02-12';
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

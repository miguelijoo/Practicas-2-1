--Eje1
SELECT nombrecompleto FROM votantes
WHERE nombrecompleto LIKE '%n';
--Eje2
SELECT dni FROM votantes 
WHERE dni LIKE '%5%5%5%';
--Eje3
SELECT nombrecompleto FROM votantes 
WHERE fechanacimiento>'1/1/90';
--Eje4
SELECT v.nombrecompleto, l.nombre FROM votantes v, localidades l 
WHERE l.numerohabitantes>300000 AND v.localidad=l.idlocalidad;
--Eje5
SELECT v.nombrecompleto, p.comunidad FROM votantes v, provincias p, localidades l
WHERE v.localidad=l.idlocalidad 
AND l.provincia=p.idprovincia
AND l.numerohabitantes>300000; --Hago que la clave foránea de localidad en votantes apunte al idlocalidad de localidad, luego hago que la clave foránea de localidad que apunta a provincia apunte a dicha tabla
--Eje 6 Decir para cada partido cuántas consultas tiene. Duda aquí es en qué tabla mirar
SELECT partido, COUNT(*) AS NIGGER FROM consultas_datos
GROUP BY partido;
--Eje 7
SELECT pa.idpartido, COUNT(*) FROM partidos pa, consultas_datos cd
WHERE pa.idpartido=cd.partido
GROUP BY pa.idpartido; --Podría hacerse con pa.idpartido o cd.partido, ambos son el mismo atributo solo que uno es clave primaria y otro foránea
--Eje 8
SELECT pa.nombrecompleto, COUNT(*) FROM partidos pa, consultas_datos cd
WHERE pa.idpartido=cd.partido
GROUP BY pa.nombrecompleto
HAVING COUNT(*)>10;
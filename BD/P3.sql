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
SELECT FROM ;
SELECT * FROM votantes;
SELECT * FROM localidades;
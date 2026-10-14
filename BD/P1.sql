-- Ejercicio 2
SELECT table_name FROM user_tables;

-- Ejercicio 3
DESCRIBE eventos

-- Ejercicio 4
DROP TABLE votantes CASCADE CONSTRAINTS;

-- Ejercicio 5
INSERT INTO votantes VALUES (30653845, 'Margia Gonzalez Ramirez', 'Doctorado', 'Activo', 'goram@telefonica.es', 1, '21/8/1989', 677544822);

-- Ejercicio 7
DELETE FROM votantes WHERE dni=30653845;

-- Ejercicio 9
SELECT NOMBRE, TIPO, FECHA FROM eventos;

-- Ejercicio 10
SELECT NOMBRE || ' de tipo ' || TIPO "Convocatoria" FROM eventos;

--Eje 1
clear screen;
set serveroutput on;
declare
    CURSOR cur_vot IS SELECT * FROM votantes;
    v_fila votantes%rowtype;
    v_recuento number :=0;
begin
    OPEN cur_vot;
    LOOP
        FETCH cur_vot INTO v_fila;
        EXIT WHEN cur_vot%NOTFOUND;
        IF substr(v_fila.dni, -1)=v_fila.localidad+1 THEN
        v_recuento := v_recuento +1; --No se usa un AND u OR para sentencias IF, se separan por 2 puntos y serían en sucesión, como un AND
        dbms_output.put_line(v_fila.nombrecompleto);
        END IF;
    END LOOP;
    CLOSE cur_vot;
    dbms_output.put_line('Total de votantes que cumplen la condición: ' || v_recuento);
end;
/

clear screen;
set serveroutput on;
declare
    CURSOR cur_vot IS SELECT * FROM votantes;
    v_fila votantes%rowtype;
    v_recuento number :=0;
begin
    OPEN cur_vot;
    FETCH cur_vot INTO v_fila; --Aquí se usa un FETCH antes del bucle de modo que se sitúe el cursor en la primera fila
    WHILE cur_vot%FOUND LOOP
        IF substr(v_fila.dni, -1)=v_fila.localidad+1 THEN
        v_recuento := v_recuento +1; --No se usa un AND u OR para sentencias IF, se separan por 2 puntos y serían en sucesión, como un AND
        dbms_output.put_line(v_fila.nombrecompleto);
        END IF;
        FETCH cur_vot INTO v_fila;
    END LOOP;
    CLOSE cur_vot;
    dbms_output.put_line('Total de votantes que cumplen la condición: ' || v_recuento);
end;
/

clear screen;
set serveroutput on;
declare
    CURSOR cur_vot IS SELECT * FROM votantes;
    v_recuento number :=0;
begin
    FOR v_fila IN cur_vot LOOP
        IF substr(v_fila.dni, -1)=v_fila.localidad+1 THEN
        v_recuento := v_recuento +1; --No se usa un AND u OR para sentencias IF, se separan por 2 puntos y serían en sucesión, como un AND
        dbms_output.put_line(v_fila.nombrecompleto);
        END IF;
    END LOOP;
    dbms_output.put_line('Total de votantes que cumplen la condición: ' || v_recuento);
end;
/

--Eje 2
clear screen;
set serveroutput on;
declare
    v_recuento NUMBER :=0;
    CURSOR cur_vot IS SELECT nombrecompleto, localidad, nombre FROM votantes, localidades WHERE localidad=idlocalidad;
begin
    FOR fila IN cur_vot LOOP
        CASE
            WHEN fila.localidad = 1 OR fila.localidad=2 OR fila.localidad=3 THEN fila.nombre := 'Madrid';
            ELSE NULL;
        END CASE;
        dbms_output.put_line(fila.nombrecompleto || ' vive en ' || fila.nombre);
        IF fila.nombre = 'Madrid' THEN v_recuento := v_recuento+1;
        END IF;
    END LOOP;
    dbms_output.put_line('Hay ' || v_recuento || ' votantes viviendo en Madrid.');
end;
/

--Eje 3
clear screen;
set serveroutput on;
declare
    CURSOR cur_vot IS SELECT dni FROM votantes ORDER BY dni DESC;
    CURSOR cur_vot2 IS SELECT dni FROM votantes ORDER BY dni DESC;
    v_dni cur_vot%rowtype;
begin
    OPEN cur_vot2;
    FETCH cur_vot2 INTO v_dni;
    FOR dniaux IN cur_vot LOOP
        FETCH cur_vot2 INTO v_dni;
        IF cur_vot2%NOTFOUND THEN dbms_output.put_line(v_dni.dni || ' es el más pequeño');
        ELSE dbms_output.put_line(dniaux.dni || ' va antes que ' || v_dni.dni);
        END IF;
    END LOOP;
    CLOSE cur_vot2;
end;
/
--Eje 4
clear screen;
set serveroutput on;
declare --RECORDATORIO: AVG trabaja con un solo valor, es decir, si hago AVG(SELECT COUNT(*) ...) no funcionaría ya que recibe un montón de valores del tirón, el AVG se basa en hacer media de valor en valor, no de recibir todos de una vez.
    CURSOR cur_vot IS SELECT COUNT(*) AS recuento, dni FROM votantes, consultas WHERE dni=votante GROUP BY dni HAVING COUNT(*)>(SELECT AVG(COUNT(*)) FROM consultas GROUP BY votante) ORDER BY recuento DESC;
begin
    FOR v_dni IN cur_vot LOOP
        dbms_output.put_line(v_dni.dni|| ' ha participado ' || v_dni.recuento ||' veces.');
    END LOOP;
end;
/
--Eje 5
clear screen;
set serveroutput on;
declare

begin

end;
/

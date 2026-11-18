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
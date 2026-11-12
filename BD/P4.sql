--Eje 1
clear screen;
set serveroutput on;
declare
    fechactual date := sysdate;
begin
    dbms_output.put_line('Hola mundo ' || fechactual);
end;
/
--Eje 2
clear screen;
set serveroutput on;
declare
    v_dni votantes.dni%type := 30983712;
    v_nombre votantes.nombrecompleto%type;
    v_correo votantes.email%type;
begin
    SELECT nombre, email 
    INTO v_nombre, v_correo
    FROM votantes
    WHERE dni=v_dni;
    dbms_output.put_line(v_nombre ||' Con correo: ' || v_correo);
end;
/
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
    SELECT nombrecompleto, email 
    INTO v_nombre, v_correo
    FROM votantes
    WHERE dni=v_dni;
    dbms_output.put_line(v_nombre ||' con correo: ' || v_correo);
end;
/
--Eje 3
clear screen;
set serveroutput on;
declare
    v_nombre votantes.nombrecompleto%type;
    v_correo votantes.email%type;
    v_dni votantes.dni%type := 30983712;
begin
    SELECT nombrecompleto, email
    INTO v_nombre, v_correo
    FROM votantes
    WHERE dni=v_dni;
    dbms_output.put_line(SUBSTR(v_nombre, 1, INSTR(v_nombre, ' ') -1) || ' con correo: ' || v_correo||'.'); --INSTR devuelve la posición donde se encuentra el primer caracter que encuentre del tipo especificado. Si a la posición del espacio le quito uno, me pone el fin en el último caracter antes del espacio cogiendo el primer nombre.
end;
/
--Eje 4
clear screen;
set serveroutput on;
declare
    v_nombre votantes.nombrecompleto%type;
    v_dni votantes.dni%type := 30983712;
begin
    SELECT nombrecompleto
    INTO v_nombre
    FROM votantes
    WHERE dni=v_dni;
    dbms_output.put_line('Pepe ' || SUBSTR(v_nombre, INSTR(v_nombre, ' ')+1) || '.');
end;
/
--Eje 5
clear screen;
set serveroutput on;
declare
    v_nombre votantes.nombrecompleto%type;
    v_dni votantes.dni%type;
begin
    SELECT nombrecompleto, dni
    INTO v_nombre, v_dni
    FROM votantes
    WHERE fechanacimiento<=ALL(SELECT fechanacimiento FROM votantes);
    dbms_output.put_line('El señor ' || v_nombre || ' con dni ' || v_dni || ' es el votante más longevo.');
end;
/
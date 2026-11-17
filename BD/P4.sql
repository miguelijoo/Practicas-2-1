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
--Eje 6
clear screen;
set serveroutput on;
declare
    v_nombreviejo votantes.nombrecompleto%type;
    v_correoviejo votantes.email%type; --Con una variable de cada tipo da de sobra para hacerlo
    v_nombrejoven votantes.nombrecompleto%type;
    v_correojoven votantes.email%type;
begin
    SELECT nombrecompleto, email
    INTO v_nombreviejo, v_correoviejo
    FROM votantes
    WHERE fechanacimiento <= (SELECT MIN(fechanacimiento) FROM votantes);
    dbms_output.put_line(v_nombreviejo || ' -- Email: ' || SUBSTR(v_correoviejo, 1, INSTR(v_correoviejo, '@')) || 'uco.es');
    
    SELECT nombrecompleto, email
    INTO v_nombrejoven, v_correojoven
    FROM votantes
    WHERE fechanacimiento >= (SELECT MAX(fechanacimiento) FROM votantes);
    dbms_output.put_line(v_nombrejoven || ' -- Email: ' || SUBSTR(v_correojoven, 1, INSTR(v_correojoven, '@')) || 'uco.es');

end;
/
--Eje 7
clear screen;
set serveroutput on;
declare
    v_ap1 votantes.nombrecompleto%type;
    v_ap2 votantes.nombrecompleto%type;
begin
    SELECT SUBSTR(nombrecompleto, INSTR(nombrecompleto, ' ')+1)
    INTO v_ap1
    FROM votantes
    WHERE fechanacimiento = (SELECT MAX(fechanacimiento) FROM votantes);
    
    SELECT SUBSTR(nombrecompleto, INSTR(nombrecompleto, ' ')+1)
    INTO v_ap2
    FROM votantes
    WHERE fechanacimiento=(SELECT MAX(fechanacimiento) FROM votantes
                            WHERE fechanacimiento<(SELECT MAX(fechanacimiento) FROM votantes));
    dbms_output.put_line('El hijo se llama Juan ' || SUBSTR(v_ap2, 1, INSTR(v_ap2, ' ')) || SUBSTR (v_ap1, 1, INSTR(v_ap1, ' ')-1));
end;
/
--Eje 8
clear screen;
set serveroutput on;
declare
    l_suma1 localidades.numerohabitantes%type;
    l_suma2 localidades.numerohabitantes%type;
    l_idmenor localidades.idlocalidad%type;
    l_idmenor2 localidades.idlocalidad%type;
    l_recuento number;
begin
    SELECT MIN(idlocalidad)
    INTO l_idmenor
    FROM localidades;
    
    SELECT MIN(idlocalidad)
    INTO l_idmenor2
    FROM localidades
    WHERE idlocalidad>l_idmenor;
    
    SELECT numerohabitantes
    INTO l_suma1
    FROM localidades
    WHERE idlocalidad=l_idmenor;
    
    SELECT numerohabitantes
    INTO l_suma2
    FROM localidades
    WHERE idlocalidad=l_idmenor2;
    l_suma1:=l_suma1+l_suma2;
    
    SELECT COUNT(*)
    INTO l_recuento
    FROM localidades
    WHERE numerohabitantes>l_suma1;
    
    dbms_output.put_line('Hay ' || l_recuento || ' ciudades con más de ' || l_suma1 || ' habitantes, que es la suma de las dos localidades con IDs más pequeños.');
end;
/
--Eje 9
clear screen;
set serveroutput on;
declare
    v_apellidos votantes.nombrecompleto%type;
    v_dominio votantes.email%type;
begin
    SELECT nombrecompleto, email
    INTO v_apellidos, v_dominio
    FROM votantes
    WHERE dni=30983712;
    
    dbms_output.put_line('Apellidos: ' || SUBSTR(v_apellidos, INSTR(v_apellidos, ' ')+1) || ' - ' || 'Dominio: ' || SUBSTR(v_dominio, INSTR(v_dominio, '@')+1));
end;
/
--Eje 10
clear screen;
set serveroutput on;
declare
    l_max localidades.numerohabitantes%type;
    l_min localidades.numerohabitantes%type;
    l_diferencia number;
    l_recuento number;
    l_media number;
begin
    SELECT MAX(numerohabitantes), MIN(numerohabitantes)
    INTO l_max, l_min
    FROM localidades;
    l_diferencia := l_max-l_min;
    
    SELECT AVG(numerohabitantes)
    INTO l_media
    FROM localidades;
    
    SELECT COUNT(*)
    INTO l_recuento
    FROM localidades
    WHERE numerohabitantes > l_media;
    
    dbms_output.put_line('La diferencia de habitantes entre la localidad más y menos poblada es de ' || l_diferencia || ' habitantes, y ' || l_recuento ||' localidades superan la media de ' || l_media || ' habitantes.');
    
end;
/
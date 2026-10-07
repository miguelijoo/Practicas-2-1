select v.nombrecompleto "Fulanito", l.nombre "Pueblo", p.nombre "Provincia", p.comunidad "Comunidad" 
from localidades l, provincias p, votantes v 
where l.provincia=p.idprovincia and v.localidad=l.idlocalidad;
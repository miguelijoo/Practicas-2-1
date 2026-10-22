#include "catalog.h"
#include <string>
#include <iostream>

int main(){
    CyclistCatalog c;
    DirectorCatalog d;
    std::string path, name, team, id;
    int birthyear, dirsince;
    std::vector <Cyclist> cyclists;
    std::vector <Director> directors;
    path=std::string(PROJECT_ROOT) + "/data/cyclists.csv";
    c.Load(path);
    path=std::string(PROJECT_ROOT) + "/data/directors.csv";
    d.Load(path);
    //Funciones para comprobar CyclistCatalog
    int n=c.Size();
    std::cout<<"Objeto cyclist:"<<std::endl;
    std::cout<<"Hay "<<n<<" ciclistas en el vector."<<std::endl;
    std::cout<<"Elementos del vector: "<<std::endl;
    cyclists=c.Data();
    for(int i=0;i<cyclists.size();i++){
        name=cyclists[i].GetName();
        team=cyclists[i].GetTeam();
        birthyear=cyclists[i].GetBirthYear();
        id=cyclists[i].GetCyclistId();
        std::cout<<"Ciclista numero: "<<i+1<<std::endl;
        std::cout<<"Nombre: "<<name<<std::endl;
        std::cout<<"Año nacimiento: "<<birthyear<<std::endl;
        std::cout<<"Equipo: "<<team<<std::endl;
        std::cout<<"Id: "<<id<<std::endl;
    }
    std::cout<<"Introduce un id de un ciclista a borrar: ";
    std::getline(std::cin, id);
    c.Remove(id);
    std::cout<<"Numero de ciclistas tras el borrado: ";
    n=c.Size();
    std::cout<<n<<std::endl;
    std::cout<<"Elementos del vector: "<<std::endl;
    cyclists=c.Data();
    for(int i=0;i<cyclists.size();i++){
        name=cyclists[i].GetName();
        team=cyclists[i].GetTeam();
        birthyear=cyclists[i].GetBirthYear();
        id=cyclists[i].GetCyclistId();
        std::cout<<"Ciclista numero: "<<i+1<<std::endl;
        std::cout<<"Nombre: "<<name<<std::endl;
        std::cout<<"Año nacimiento: "<<birthyear<<std::endl;
        std::cout<<"Equipo: "<<team<<std::endl;
        std::cout<<"Id: "<<id<<std::endl;
    }

    //Funciones para comprobar DirectorCatalog

    std::cout<<"Objeto director:"<<std::endl;
    n=d.Size();
    std::cout<<"Hay "<<n<<" directores en el vector"<<std::endl;
    std::cout<<"Elementos del vector: "<<std::endl;
    directors=d.Data();
    int i=1;
    for(Director &d: directors){
            name=d.GetName();
            birthyear=d.GetBirthYear();
            team=d.GetTeam();
            id=d.GetUciLicenseId();
            dirsince=d.GetDirectorSince();
            std::cout<<"Director numero "<<i<<std::endl;
            i++;
            std::cout<<"Nombre: "<<name<<std::endl;
            std::cout<<"Año nacimiento: "<<birthyear<<std::endl;
            std::cout<<"Equipo: "<<team<<std::endl;
            std::cout<<"Id: "<<id<<std::endl;
            std::cout<<"Director desde: "<<dirsince<<std::endl;
    }
    std::cout<<"Introduce un id de un director a borrar: ";
    std::getline(std::cin, id);
    d.Remove(id);
    std::cout<<"Numero de directores tras el borrado: ";
    n=d.Size();
    std::cout<<n<<std::endl;
    std::cout<<"Elementos del vector: "<<std::endl;
    directors=d.Data();
    i=1;
    for(const Director &d: directors){
        name=d.GetName();
        birthyear=d.GetBirthYear();
        team=d.GetTeam();
        id=d.GetUciLicenseId();
        dirsince=d.GetDirectorSince();
        std::cout<<"Director numero "<<i<<std::endl;
        i++;
        std::cout<<"Nombre: "<<name<<std::endl;
        std::cout<<"Año nacimiento: "<<birthyear<<std::endl;
        std::cout<<"Equipo: "<<team<<std::endl;
        std::cout<<"Id: "<<id<<std::endl;
        std::cout<<"Director desde: "<<dirsince<<std::endl;
    }

    //Funciones de la práctica 3

    //GetByTeam
    std::cout<<"Introduzca un nombre de equipo: "; 
    std::getline(std::cin, team);
    cyclists=c.GetByTeam(team);
    for(int i=0;i<cyclists.size();i++){
        name=cyclists[i].GetName();
        team=cyclists[i].GetTeam();
        birthyear=cyclists[i].GetBirthYear();
        id=cyclists[i].GetCyclistId();
        std::cout<<"Ciclista numero: "<<i+1<<std::endl;
        std::cout<<"Nombre: "<<name<<std::endl;
        std::cout<<"Año nacimiento: "<<birthyear<<std::endl;
        std::cout<<"Equipo: "<<team<<std::endl;
        std::cout<<"Id: "<<id<<std::endl;
    }
    //GetYoungest
    std::cout<<"Se va a proceder a mostrar los ciclistas más jovenes: "<<std::endl;
    cyclists=c.GetYoungest();
    for(int i=0;i<cyclists.size();i++){
        name=cyclists[i].GetName();
        team=cyclists[i].GetTeam();
        birthyear=cyclists[i].GetBirthYear();
        id=cyclists[i].GetCyclistId();
        std::cout<<"Ciclista numero: "<<i+1<<std::endl;
        std::cout<<"Nombre: "<<name<<std::endl;
        std::cout<<"Año nacimiento: "<<birthyear<<std::endl;
        std::cout<<"Equipo: "<<team<<std::endl;
        std::cout<<"Id: "<<id<<std::endl;
    }
    //GetTeam
    std::cout<<"Introduzca un id para ver el equipo del ciclista: ";
    std::getline(std::cin, id);
    team=c.GetTeam(id);
    std::cout<<team<<std::endl;
    //RemoveFirst y RemoveLast
    std::cout<<"Se borra al primer ciclista y al último: "<<std::endl;
    if(c.RemoveFirst()==false){
        std::cout<<"No se ha podido borrar al primer ciclista"<<std::endl;
    }
    if(c.RemoveLast()==false){
        std::cout<<"No se ha podido borrar al último ciclista"<<std::endl;
    }
    //RemoveAt
    std::cout<<"Introduzca una posición a borrar: ";
    int pos;
    std::cin>>pos;
    std::cin.ignore();
    if(c.RemoveAt(pos)==false){
        std::cout<<"No se ha podido borrar el ciclista de la posición "<<pos<<std::endl;
    }
    cyclists=c.Data();
    for(int i=0;i<cyclists.size();i++){
        name=cyclists[i].GetName();
        team=cyclists[i].GetTeam();
        birthyear=cyclists[i].GetBirthYear();
        id=cyclists[i].GetCyclistId();
        std::cout<<"Ciclista numero: "<<i+1<<std::endl;
        std::cout<<"Nombre: "<<name<<std::endl;
        std::cout<<"Año nacimiento: "<<birthyear<<std::endl;
        std::cout<<"Equipo: "<<team<<std::endl;
        std::cout<<"Id: "<<id<<std::endl;
    }
    //AddFirst y AddLast
    Cyclist c1;
    std::cout<<"Introduzca los datos para meter a un ciclista al principio."<<std::endl;
    std::cout<<"Nombre :";
    std::getline(std::cin, name);
    c1.SetName(name);
    std::cout<<"Nacimiento: ";
    std::cin>>birthyear;
    c1.SetBirthYear(birthyear);
    std::cin.ignore();
    std::cout<<"Equipo: ";
    std::getline(std::cin, team);
    c1.SetTeam(team);
    std::cout<<"Id: ";
    std::getline(std::cin, id);
    c1.SetCyclistId(id);
    c.AddFirst(c1);
    std::cout<<"Introduzca los datos para meter a un ciclista al final."<<std::endl;
    std::cout<<"Nombre :";
    std::getline(std::cin, name);
    c1.SetName(name);
    std::cout<<"Nacimiento: ";
    std::cin>>birthyear;
    c1.SetBirthYear(birthyear);
    std::cin.ignore();
    std::cout<<"Equipo: ";
    std::getline(std::cin, team);
    c1.SetTeam(team);
    std::cout<<"Id: ";
    std::getline(std::cin, id);
    c1.SetCyclistId(id);
    c.AddLast(c1);
    cyclists=c.Data();
    for(int i=0;i<cyclists.size();i++){
        name=cyclists[i].GetName();
        team=cyclists[i].GetTeam();
        birthyear=cyclists[i].GetBirthYear();
        id=cyclists[i].GetCyclistId();
        std::cout<<"Ciclista numero: "<<i+1<<std::endl;
        std::cout<<"Nombre: "<<name<<std::endl;
        std::cout<<"Año nacimiento: "<<birthyear<<std::endl;
        std::cout<<"Equipo: "<<team<<std::endl;
        std::cout<<"Id: "<<id<<std::endl;
    }
    //RemoveByTeam
    std::cout<<"Introduzca un equipo para borrar los ciclistas: ";
    std::getline(std::cin, team);
    if(c.RemoveByTeam(team)==false){
        std::cout<<"No se ha podido eliminar a los ciclistas del equipo "<<team<<std::endl;
    }
    else{
        cyclists=c.Data();
        for(int i=0;i<cyclists.size();i++){
            name=cyclists[i].GetName();
            team=cyclists[i].GetTeam();
            birthyear=cyclists[i].GetBirthYear();
            id=cyclists[i].GetCyclistId();
            std::cout<<"Ciclista numero: "<<i+1<<std::endl;
            std::cout<<"Nombre: "<<name<<std::endl;
            std::cout<<"Año nacimiento: "<<birthyear<<std::endl;
            std::cout<<"Equipo: "<<team<<std::endl;
            std::cout<<"Id: "<<id<<std::endl;
        }
    }
    //RemoveRange
    std::cout<<"Introduzca un rango de principio a fin para eliminar a los ciclistas del vector: ";
    std::size_t inicio, fin;
    std::cin>>inicio;
    std::cin>>fin;
    c.RemoveRange(inicio, fin);
    cyclists=c.Data();
    for(int i=0;i<cyclists.size();i++){
        name=cyclists[i].GetName();
        team=cyclists[i].GetTeam();
        birthyear=cyclists[i].GetBirthYear();
        id=cyclists[i].GetCyclistId();
        std::cout<<"Ciclista numero: "<<i+1<<std::endl;
        std::cout<<"Nombre: "<<name<<std::endl;
        std::cout<<"Año nacimiento: "<<birthyear<<std::endl;
        std::cout<<"Equipo: "<<team<<std::endl;
        std::cout<<"Id: "<<id<<std::endl;
    }
    std::cout<<"Se procede a limpiar todo el vector."<<std::endl;
    c.Clear();
    n=c.Size();
    std::cout<<"Tamaño final del vector: "<<n<<std::endl;
    return(0);
}

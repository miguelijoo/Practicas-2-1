#include "catalog.h"
#include <iostream>
#include <string>
#include <sstream>
#include <ostream>
#include <fstream>
#include "../person/person.h"


//Funciones CyclistCatalog

bool CyclistCatalog::Load(const std::string& path) {
    Cyclist c;
    std::string name, birth_s, id, team;
    int birthyear = 0;
    cyclists_.clear(); // Elimina todos los elementos si hubiera
    std::ifstream in(path);
    if (!in) {
        std::cerr << "-ERROR: No se pudo abrir " << path << "\n";
        return false;
    }
    std::string line;
    if (!std::getline(in, line)) return false; // saltar cabecera
    while (std::getline(in, line)) {
        if (line.empty()) continue;
        std::istringstream iss(line); // Define un stream de lectura a partir de line
        if (!std::getline(iss, name, ',')) continue;
        if (!std::getline(iss, birth_s, ',')) continue;
        if (!std::getline(iss, id, ',')) continue;
        if (!std::getline(iss, team)) continue;
        birthyear = std::stoi(birth_s);
        c.SetName(name);
        c.SetBirthYear(birthyear);
        c.Setcyclist_id(id);
        c.Setteam(team);
        cyclists_.push_back(c); // se hace una copia al final del vector
    }
    return !cyclists_.empty();
}

int CyclistCatalog::Size(){ //Errores varios, como el acceder al vector de private que como tal no puedo hacerlo
    if(cyclists_.empty()==true){
        return -1;
    }
    else{
        int n;
        n=cyclists_.size();
        return n;
    }
}

void CyclistCatalog:: Data(){ //Recorrido con un bucle for normal y haciendo uso de [].
    if(cyclists_.empty()==true){
        std::cout<<"El vector está vacío, no hay datos."<<std::endl;
    }
    else{
        std::string name, team, id;
        int birthyear;
        for(int i=0;i<cyclists_.size();i++){
            name=cyclists_[i].GetName();
            team=cyclists_[i].Getteam();
            birthyear=cyclists_[i].GetYear();
            id=cyclists_[i].Getcyclist_id();
            std::cout<<"Ciclista numero: "<<i<<std::endl;
            std::cout<<"Nombre: "<<name<<std::endl;
            std::cout<<"Año nacimiento: "<<birthyear<<std::endl;
            std::cout<<"Equipo: "<<team<<std::endl;
            std::cout<<"Id: "<<id<<std::endl;
        }
    }
}

void CyclistCatalog:: Remove(std::string id){
    if(cyclists_.empty()==true){
        std::cout<<"El vector está vacío, no hay datos para borrar."<<std::endl;
    }
    else{
        std::string idcopia;
        for(auto it = cyclists_.begin(); it != cyclists_.end();){
            idcopia=it->Getcyclist_id();
            if(idcopia==id){
                it=cyclists_.erase(it);
            }
            else{
                it++;
            }
        }
    }
}

//Funciones DirectorCatalog

bool DirectorCatalog::Load(const std::string& path) {
    Director d;
    std::string name, birth_s, id, team, dirsince_;
    int birthyear = 0, dirsince=0;
    directors_.clear(); // Elimina todos los elementos si hubiera
    std::ifstream in(path);
    if (!in) {
        std::cerr << "-ERROR: No se pudo abrir " << path << "\n";
        return false;
    }
    std::string line;
    if (!std::getline(in, line)) return false; // saltar cabecera
    while (std::getline(in, line)) {
        if (line.empty()) continue;
        std::istringstream iss(line); // Define un stream de lectura a partir de line
        if (!std::getline(iss, name, ',')) continue;
        if (!std::getline(iss, birth_s, ',')) continue;
        if (!std::getline(iss, id, ',')) continue;
        if (!std::getline(iss, team, ',')) continue;
        if (!std::getline(iss, dirsince_)) continue;
        dirsince = std::stoi(dirsince_);
        birthyear = std::stoi(birth_s);
        d.SetName(name);
        d.SetBirthYear(birthyear);
        d.Setid(id);
        d.Setteam(team);
        d.Setdirsince(dirsince);
        directors_.push_back(d); // se hace una copia al final del vector
    }
    return !directors_.empty();
}

int DirectorCatalog::Size(){ //Errores varios, como el acceder al vector de private que como tal no puedo hacerlo
    if(directors_.empty()==true){
        return -1;
    }
    else{
        int n;
        n=directors_.size();
        return n;
    }
}

void DirectorCatalog:: Data(){ //Recorrido con un range for con referencia
    if(directors_.empty()==true){
        std::cout<<"El vector está vacío, no hay datos."<<std::endl;
    }
    else{
        std::string name, team, id;
        int birthyear, dirsince, i=1;
        for(Director &d: directors_){
            name=d.GetName();
            birthyear=d.GetYear();
            team=d.Getteam();
            id=d.Getid();
            dirsince=d.Getdirsince();
            std::cout<<"Director numero "<<i<<std::endl;
            i++;
            std::cout<<"Nombre: "<<name<<std::endl;
            std::cout<<"Año nacimiento: "<<birthyear<<std::endl;
            std::cout<<"Equipo: "<<team<<std::endl;
            std::cout<<"Id: "<<id<<std::endl;
            std::cout<<"Director desde: "<<dirsince<<std::endl;
        }
    }
}

void DirectorCatalog:: Remove(std::string id){
    if(directors_.empty()==true){
        std::cout<<"El vector está vacío, no hay datos para borrar."<<std::endl;
    }
    else{
        std::string idcopia;
        for(auto it = directors_.begin(); it != directors_.end();){
            idcopia=it->Getid();
            if(idcopia==id){
                it=directors_.erase(it);
            }
            else{
                it++;
            }
        }
    }
}
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
        c.SetCyclistId(id);
        c.SetTeam(team);
        cyclists_.push_back(c); // se hace una copia al final del vector
    }
    return !cyclists_.empty();
}

bool CyclistCatalog:: Remove(std::string id){
    if(cyclists_.empty()==true){
        std::cout<<"El vector está vacío, no hay datos para borrar."<<std::endl;
        return false;
    }
    else{
        bool test=false;
        std::string idcopia;
        for(auto it = cyclists_.begin(); it != cyclists_.end();){
            idcopia=it->GetCyclistId();
            if(idcopia==id){
                it=cyclists_.erase(it);
                test=true;
            }
            else{
                it++;
            }
        }
        return test;
    }
}

std::string CyclistCatalog::GetTeam(std::string id){
    for(auto &it: cyclists_){
        if(id==it.GetCyclistId()){
            return it.GetTeam();
        }
    }
    return "NOT_IN_CATALOG";
}

std::vector <Cyclist> CyclistCatalog::GetByTeam(std::string team){
    std::vector<Cyclist>teamcyclists;
    for(auto &it: cyclists_){
        if(team==it.GetTeam()){
            teamcyclists.push_back(it);
        }
    }
    return teamcyclists;
}

std::vector <Cyclist> CyclistCatalog:: GetYoungest(){
    if(cyclists_.empty() == true){
        return cyclists_;
    }
    else{
        std::vector<Cyclist> Jovenes;
        int i=cyclists_[0].GetBirthYear();
        for(auto &it: cyclists_){
            if(i<it.GetBirthYear()){
                i=it.GetBirthYear();
            }
        }
        for(auto &it: cyclists_){
            if(it.GetBirthYear()==i){
                Jovenes.push_back(it);
            }
        }
        return Jovenes;
    }
}

void CyclistCatalog::Clear(){
    cyclists_.clear();
}

void CyclistCatalog:: AddFirst(Cyclist c_){
    cyclists_.insert(cyclists_.begin(), c_);
}

void CyclistCatalog:: AddLast(Cyclist c_){
    cyclists_.insert(cyclists_.end(), c_);
}

bool CyclistCatalog:: RemoveFirst(){
    if(cyclists_.empty()==true){
        return false;
    }
    else{
        cyclists_.erase(cyclists_.begin());
        return true;
    }
}

bool CyclistCatalog:: RemoveLast(){
    if(cyclists_.empty()==true){
        return false;
    }
    else{
        cyclists_.pop_back();
        return true;
    }
}

bool CyclistCatalog:: RemoveAt(int pos){
    if(pos>=cyclists_.size()){
        return false;
    }
    else if(pos<0){
        return false;
    }
    else{
        std::vector<Cyclist>::iterator it = cyclists_.begin()+pos;
        cyclists_.erase(it);
        return true;
    }
}

int CyclistCatalog:: RemoveByTeam(const std::string &team){
    // int i=0, cont=0;
    // std::vector<Cyclist>::iterator it_ = cyclists_.begin();
    // for(auto &it: cyclists_){
    //     if(it.GetTeam()==team){
    //         cyclists_.erase(it_);
    //         it_=std::next(cyclists_.begin(), i);
    //         cont++;
    //     }
    //     i++;
    // }
    // return cont;
    int counter = 0; 

    for (auto it = cyclists_.begin(); it != cyclists_.end();) { //Revisar bucle
        if (it->GetTeam() == team){
            it = cyclists_.erase(it);
            counter++;
        }
        else 
            ++it;
    }

    return counter;
}

bool CyclistCatalog:: RemoveRange(std::size_t first, std::size_t last){
    if(first<=last && last<=cyclists_.size()){ 
        std::vector<Cyclist>::iterator it=cyclists_.begin()+first, it2=cyclists_.begin()+last;
        cyclists_.erase(it, it2);
        return true;
    }
    else{
        std::cout<<"Rango no válido."<<std::endl;
        return false;
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
        d.SetUciLicenseId(id);
        d.SetTeam(team);
        d.SetDirectorSince(dirsince);
        directors_.push_back(d); // se hace una copia al final del vector
    }
    return !directors_.empty();
}

bool DirectorCatalog:: Remove(std::string id){
    if(directors_.empty()==true){
        std::cout<<"El vector está vacío, no hay datos para borrar."<<std::endl;
        return false;
    }
    else{
        std::string idcopia;
        bool confirm=false;
        for(auto it = directors_.begin(); it != directors_.end();){
            idcopia=it->GetUciLicenseId();
            if(idcopia==id){
                it=directors_.erase(it);
                confirm=true;
            }
            else{
                it++;
            }
        }
        return confirm;
    }
}
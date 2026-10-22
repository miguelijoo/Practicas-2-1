#include "person.h"
#include <string>

//Funciones Person

Person::Person(std::string name, int birth_year){
    if(name==""){
        name_="UNKNOWN";
    }
    else{
        name_=name;
    }
    if(birth_year<1990){
        birth_year_=-1;
    }
    else{
        birth_year_=birth_year;
    }
}

bool Person::SetName(std::string name){
    if(name==""){
        return false;
    }
    else{
        name_=name;
        return true;
    }
}

bool Person::SetBirthYear(int birth_year){
    birth_year_=birth_year;
    return true;
}

//Funciones Cyclist

Cyclist:: Cyclist(std::string name, int birthyear, std::string team, std::string cyclist_id): Person(name, birthyear){
    if(team==""){
        team_="UNKNOWN";
    }
    else{
        team_=team;
    }
    if(cyclist_id==""){
        cyclist_id_="UNKNOWN";
    }
    else{
        cyclist_id_=cyclist_id;
    }
}

std::string Cyclist::GetTeam()const{return team_;}
std::string Cyclist::GetCyclistId()const{return cyclist_id_;}

bool Cyclist:: SetTeam(std::string team){
    if(team==""){
        return false;
    }
    else{
        team_=team;
        return true;
    }
}
bool Cyclist:: SetCyclistId(std::string cyclist_id){
    if(cyclist_id==""){
        return false;
    }
    else{
        cyclist_id_=cyclist_id;
        return true;
    }
}

//Funciones Director

Director:: Director(std::string name, int birthyear, std::string team, std::string uci_license_id, int director_since): Person(name, birthyear){
    if(team==""){
        team_="UNKNOWN";
    }
    else{
        team_=team;
    }
    if(uci_license_id==""){
        uci_license_id_="UNKNOWN";
    }
    else{
        uci_license_id_=uci_license_id;
    }
    if(director_since<1990){
        director_since_=-1;
    }
    else{
        director_since_=director_since;
    }
}

std::string Director:: GetTeam()const{return team_;}
std::string Director:: GetUciLicenseId()const{return uci_license_id_;}
int Director:: GetDirectorSince()const{return director_since_;}
bool Director:: SetTeam(std::string team){
    if(team==""){
        return false;
    }
    else{
        team_=team;
        return true;
    }
}

bool Director:: SetUciLicenseId(std::string uci_licens_id){
    if(uci_licens_id==""){
        return false;
    }
    else{
        uci_license_id_=uci_licens_id;
        return true;
    }
}

bool Director:: SetDirectorSince(int director_since){
    if(director_since<1990){
        return false;
    }
    else{
        director_since_=director_since;
        return true;
    }
}
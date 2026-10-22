#ifndef PERSON_H
#define PERSON_H

#include <string>

//Clase base Person

class Person{
    private:
    std::string name_;
    int birth_year_;

    public:
    Person(){
        name_="UNKNOWN";
        birth_year_=-1;
    }

    Person(std::string name, int birth_year);

    std::string GetName()const{return name_;}
    int GetBirthYear()const{return birth_year_;}

    bool SetName(std::string name);

    bool SetBirthYear(int birth_year);

};

//Clase que hereda de Person, Cyclist

class Cyclist: public Person{
    private:
        std::string team_, cyclist_id_;
    public:
        Cyclist(){
            team_="UNKNOWN";
            cyclist_id_="UNKNOWN";
        }
        Cyclist(std::string name, int birthyear, std::string team, std::string cyclist_id);
        std::string GetTeam() const;
        std::string GetCyclistId() const;
        bool SetTeam(std::string team);
        bool SetCyclistId(std::string cyclist_id);
};

//Clase Director, que hereda de Person

class Director: public Person{
    private:
        std::string team_, uci_license_id_;
        int director_since_;
    public:
        Director(){
            team_="UNKNOWN";
            uci_license_id_="UNKNOWN";
            director_since_=-1;
        }
        Director(std::string name, int birthyear, std::string team, std::string uci_license_id, int director_since);
        std::string GetTeam() const;
        std::string GetUciLicenseId() const;
        int GetDirectorSince() const;
        bool SetTeam(std::string team);
        bool SetUciLicenseId(std::string uci_licens_id);
        bool SetDirectorSince(int director_since);
};

#endif
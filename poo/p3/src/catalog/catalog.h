#ifndef CATALOG_H
#define CATALOG_H

#include "../person/person.h"
#include <vector>
#include <string>

class CyclistCatalog{
    private:
        std::vector<Cyclist>cyclists_;
    public:
        bool Load(const std::string& path);
        const int Size(){return cyclists_.size();}
        std::vector<Cyclist> Data(){return cyclists_;}
        bool Remove(std::string id);
        std::string GetTeam(std::string id);
        std::vector<Cyclist> GetByTeam(std::string team);
        std::vector<Cyclist>GetYoungest();
        void Clear();
        void AddFirst(Cyclist c_);
        void AddLast(Cyclist c_);
        bool RemoveFirst();
        bool RemoveLast();
        bool RemoveAt(int pos);
        int RemoveByTeam(const std::string &team);
        bool RemoveRange(std::size_t first, std::size_t last);
};

class DirectorCatalog{
    private:
        std::vector<Director>directors_;
    public:
        bool Load(const std::string& path);
        const int Size() const {return directors_.size();}
        const std::vector <Director> Data() const {return directors_;}
        bool Remove(std::string id);
};

#endif
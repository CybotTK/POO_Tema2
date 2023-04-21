#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

class Persoana{
    protected:
        int id;
        std::string nume;
    
    public:
        Persoana();
        Persoana(const int ID, const std::string Nume);
        Persoana(const Persoana &other);
        virtual ~Persoana();

        Persoana& operator= (const Persoana& other);

        friend std::ostream& operator << (std::ostream &out, const Persoana &p);
        friend std::istream& operator >> (std::istream &in, Persoana &p);
};
#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <typeinfo>
#include "Abonat.h"
#include "Abonat_Skype.h"
#include "Abonat_Skype_Extern.h"
#include "Abonat_Skype_Romania.h"

class Agenda{
    private:
        std::vector <Abonat*> abonati;
        static int NrAbonati;

    public:

        Agenda();
        ~Agenda();
        Agenda& operator+=(const Abonat& ab);
        Agenda& operator+=(const Abonat_Skype& ab);
        Agenda& operator+=(const Abonat_Skype_Extern& ab);
        Agenda& operator+=(const Abonat_Skype_Romania& ab);
        void GetAgenda();
        static int GetNrAbonati();
        Agenda& operator[](const std::string& Nume);

        friend std::ostream& operator << (std::ostream& out, const Agenda& ag);

};
#include "Agenda.h"
#include "Abonat_Skype.h"
#include "Abonat_Skype_Extern.h"
#include "Abonat_Skype_Romania.h"

Agenda::Agenda(){
}

Agenda::~Agenda(){
}

void Agenda::GetAgenda(){
    for (auto i:abonati)
    { if (typeid(*i)==typeid(Abonat_Skype_Extern))
      { Abonat* auxab;
        auxab=dynamic_cast<Abonat_Skype_Extern*>(i);
        auxab->Afisare();
      }
      else if (typeid(*i)==typeid(Abonat_Skype_Romania))
      { Abonat* auxab;
        auxab=dynamic_cast<Abonat_Skype_Romania*>(i);
        auxab->Afisare();
      }
      else if (typeid(*i)==typeid(Abonat_Skype))
      { Abonat* auxab;
        auxab=dynamic_cast<Abonat_Skype*>(i);
        auxab->Afisare();
      }
      else std::cout<<*i;
    }
}

Agenda& Agenda::operator+=(const Abonat& ab){
  NrAbonati++;
  abonati.push_back(new Abonat(ab));
  return *this;
}

Agenda& Agenda::operator+=(const Abonat_Skype& ab){
  NrAbonati++;
  abonati.push_back(new Abonat_Skype(ab));
  return *this;
}

Agenda& Agenda::operator+=(const Abonat_Skype_Extern& ab){
  NrAbonati++;
  abonati.push_back(new Abonat_Skype_Extern(ab));
  return *this;
}

Agenda& Agenda::operator+=(const Abonat_Skype_Romania& ab){
  NrAbonati++;
  abonati.push_back(new Abonat_Skype_Romania(ab));
  return *this;
}

int Agenda::GetNrAbonati(){
  return NrAbonati;
}

Agenda& Agenda::operator[](const std::string& Nume){
  bool ok=0;
  for (auto x:abonati)
  { if (typeid(*x)==typeid(Abonat_Skype_Extern))
      { Abonat* auxab;
        auxab=dynamic_cast<Abonat_Skype_Extern*>(x);
        if (auxab->GetNume()==Nume)
        { ok=1;
          auxab->Afisare();
          break;
        }
      }
      else if (typeid(*x)==typeid(Abonat_Skype_Romania))
      { Abonat* auxab;
        auxab=dynamic_cast<Abonat_Skype_Romania*>(x);
        if (auxab->GetNume()==Nume)
        { ok=1;
          auxab->Afisare();
          break;
        }
      }
      else if (typeid(*x)==typeid(Abonat_Skype))
      { Abonat* auxab;
        auxab=dynamic_cast<Abonat_Skype*>(x);
        if (auxab->GetNume()==Nume)
        { ok=1;
          auxab->Afisare();
          break;
        }
      }
      else{
        if (x->GetNume()==Nume)
        { ok=1;
          x->Afisare();
          break;
        }
      }
  }
  
  if (ok==0){
    throw std::invalid_argument("Numele introdus nu se gaseste in agenda.\n");
  }

}


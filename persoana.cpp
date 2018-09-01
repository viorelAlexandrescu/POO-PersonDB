#include "persoana.h"

persoana::persoana()
{
    //ctor
}

persoana::~persoana()
{
    //dtor
}

//Functiile de afisare
string persoana::get_nume()
{
    return nume;
}

int persoana::get_anul_nasterii()
{
    return anul_nasterii;
}

char persoana::get_sex()
{
    return sex;
}

//Functiile de set
void persoana::set_nume(string Nume_Ales)
{
    nume = Nume_Ales;
}

void persoana::set_anul_nasterii(int An_al_nasterii_Ales)
{
    anul_nasterii = An_al_nasterii_Ales;
}

void persoana::set_sex(char Sex_Ales)
{
   sex = Sex_Ales;
}

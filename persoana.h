#ifndef PERSOANA_H
#define PERSOANA_H
#include <iostream>
#include <string.h>
using namespace std;

class persoana
{
private:
    string nume;
    int anul_nasterii;
    char sex;
public:
//Metodele de get
    string get_nume();
    int get_anul_nasterii();
    char get_sex();

//Metodele de set
    void set_nume(string Nume_Ales);
    void set_anul_nasterii(int An_al_nasterii_Ales);
    void set_sex(char Sex_Ales);

    persoana();
    ~persoana();
};
#endif // PERSOANA_H

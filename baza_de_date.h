#ifndef BAZA_DE_DATE_H
#define BAZA_DE_DATE_H
#include <cstring>
#include "persoana.h"

class baza_de_date
{
private:
    persoana **vector_pointeri_la_persoane;
    unsigned int numar_persoane;
public:

    int get_nr_persoane();       //Return Numarul de Persoane
    void add_persoana(string Nume_Ales, int An_al_nasterii_Ales, char Sex_Ales, persoana* New_Persoana);//Metoda de adaugare persoane

    void delete_persoana_toate();//Metoda de stergere a bazei de date
    void delete_persoana(string);//Metoda de stergere dupa nume
    void delete_persoana(int);   //Metoda de stergere dupa anul nasterii
    void delete_persoana(char);  //Metoda de stergere dupa sex

    int comparare_alfabetica(int);
    void sortare_alfabetica();

    void afisare_alfabetica();    //Functia de afisare in ordine alfabetica
    void afisare_dupa_anul_nasterii();//Functia de afisare in ordine crescatoare dupa anul nasterii

    void afiseaza_corect(); //EASTER EGG
    baza_de_date();
    ~baza_de_date();

    friend class persoana;
};

#endif // BAZA_DE_DATE_H

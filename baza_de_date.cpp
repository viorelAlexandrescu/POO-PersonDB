#include "baza_de_date.h"
#include <cstdio>
#include <cstring>
#include <limits.h>
#include <algorithm>

int baza_de_date::get_nr_persoane()
{
    return numar_persoane;
}

void baza_de_date::add_persoana(string Nume_Ales, int An_al_nasterii_Ales,
                                char Sex_Ales, persoana* Persoana_Noua)
{
    if(numar_persoane == 0)
    {
        vector_pointeri_la_persoane = new persoana*;
        *vector_pointeri_la_persoane = Persoana_Noua;
        vector_pointeri_la_persoane[0]->set_nume(Nume_Ales);
        vector_pointeri_la_persoane[0]->set_anul_nasterii(An_al_nasterii_Ales);
        vector_pointeri_la_persoane[0]->set_sex(Sex_Ales);
        numar_persoane++;

    }
    else
    {
        persoana **temp;
        temp = new persoana*[numar_persoane+1];
        for(unsigned int i=0; i<numar_persoane; i++)
        {
            temp[i] = vector_pointeri_la_persoane[i];
            vector_pointeri_la_persoane[i] = NULL;
        }

        temp[numar_persoane] = Persoana_Noua;
        temp[numar_persoane]->set_nume(Nume_Ales);
        temp[numar_persoane]->set_anul_nasterii(An_al_nasterii_Ales);
        temp[numar_persoane]->set_sex(Sex_Ales);

        vector_pointeri_la_persoane = temp;

        numar_persoane++;

    }

}

void baza_de_date::delete_persoana_toate()
{
    for(unsigned int i=0; i<numar_persoane; i++)
    {
        delete vector_pointeri_la_persoane[i];
        vector_pointeri_la_persoane[i] = NULL;
    }

    numar_persoane = 0;
}

void baza_de_date::delete_persoana(string Nume_Ales)
{
    int contor = 0;
    for(unsigned int i=0; i<numar_persoane-contor; i++)
        if( Nume_Ales == vector_pointeri_la_persoane[i]->get_nume() )
        {
            delete vector_pointeri_la_persoane[i];
            vector_pointeri_la_persoane[i] = NULL;


            for(unsigned int j=i; j<numar_persoane-1-contor; j++)
                vector_pointeri_la_persoane[j] = vector_pointeri_la_persoane[j+1];

            contor++;
            i--;

        }
    if(contor == 0)
    {
        cout << "Nu exista persoane cu numele - " << Nume_Ales << "\n";
    }
    system("pause");
    numar_persoane -= contor;
}

void baza_de_date::delete_persoana(int An_Ales)
{
    int contor = 0;
    for(unsigned int i=0; i<numar_persoane-contor; i++)
        if(vector_pointeri_la_persoane[i]->get_anul_nasterii() == An_Ales)
        {
            delete vector_pointeri_la_persoane[i];
            vector_pointeri_la_persoane[i] = NULL;

            for(unsigned int j=i; j<numar_persoane-1-contor; j++)
                vector_pointeri_la_persoane[j] = vector_pointeri_la_persoane[j+1];

            contor++;
            i--;
        }
    if(contor == 0)
    {
        cout << "Nu exista persoane nascute in anul - " << An_Ales << "\n" ;
    }

    system("pause");
    numar_persoane -= contor;
}

void baza_de_date::delete_persoana(char Sex_Ales)
{
    int contor = 0;
    for(unsigned int i=0; i<numar_persoane; i++)
        if(vector_pointeri_la_persoane[i]->get_sex() == Sex_Ales)
        {
            delete vector_pointeri_la_persoane[i];
            vector_pointeri_la_persoane[i] = NULL;

            for(unsigned int j=i; j<numar_persoane-1-contor; j++)
                vector_pointeri_la_persoane[j] = vector_pointeri_la_persoane[j+1];

            contor++;
            i--;
        }
    if(contor == 0)
    {
        cout << "Nu exista persoane de sex - " << Sex_Ales << "\n";
    }

    system("pause");
    numar_persoane -= contor;
}

int baza_de_date::comparare_alfabetica(int i)
{

    string Nume_Comparare_1 = vector_pointeri_la_persoane[i]->get_nume();
    string Nume_Comparare_2 = vector_pointeri_la_persoane[i+1]->get_nume();
    if(Nume_Comparare_1 > Nume_Comparare_2)
        return 1;
    else
        return 0;

}

void baza_de_date::sortare_alfabetica()
{
    persoana *aux_temp;
    if(numar_persoane > 0)
    {
        for(unsigned int i=0; i<numar_persoane; i++)
            for(unsigned int j=0; j<numar_persoane-1; j++)
                if(comparare_alfabetica(j)==1)
                {
                    aux_temp = vector_pointeri_la_persoane[j];
                    vector_pointeri_la_persoane[j] = vector_pointeri_la_persoane[j+1];
                    vector_pointeri_la_persoane[j+1] = aux_temp;
                }

    }
    else
    {
        cout << "\t Baza de date momentan este goala!\n\n";
        system("pause");
    }

}

void baza_de_date::afisare_alfabetica()
{
    if(numar_persoane > 0)
    {
        for(unsigned int i=0; i<numar_persoane; i++)
            cout << vector_pointeri_la_persoane[i]->get_nume() << endl;

            afiseaza_corect();

    }
    else
        cout << "\t Nu exista persoane in baza de date momentan!\n\n";


        system("pause");
}

void baza_de_date::afisare_dupa_anul_nasterii()
{
    if(numar_persoane > 0)
    {
        int an_min = INT_MAX;//Anul Minim Gasit
        int an_max = INT_MIN;//Anul Maxim Gasit
        for(unsigned int i=0; i<numar_persoane; i++)
        {
            if( vector_pointeri_la_persoane[i]->get_anul_nasterii() < an_min)
                an_min = vector_pointeri_la_persoane[i]->get_anul_nasterii();
            if( vector_pointeri_la_persoane[i]->get_anul_nasterii() > an_max)
                an_max = vector_pointeri_la_persoane[i]->get_anul_nasterii();
        }

        for(int k = an_min; k <= an_max; k++)
        {
            for(unsigned int j=0; j<numar_persoane; j++)
                if((vector_pointeri_la_persoane[j]->get_anul_nasterii() == k ) )
                    cout << vector_pointeri_la_persoane[j]->get_nume() << " - ANUL:" << k << endl;

        }

    }
    else
        cout << "\t Nu exista persoane in baza de date momentan!\n\n";

    system("pause");
}

void baza_de_date::afiseaza_corect()
{
    string Numai_Baieti = "Victorie! Baza de date este coplesita de Cromozomul Y!!!\n";
    string Numai_Fete = "Cromozomul Y lipseste cu desavarsire :( \n";
    string Egal_Egal = "Lupta sexelor continua pentru suprematie!\n";
    unsigned int fete = 0;
    unsigned int baieti = 0;
    for(unsigned int i=0 ; i<numar_persoane; i++)
        if(vector_pointeri_la_persoane[i]->get_sex() == 'F')
            fete++;
        else
            baieti++;

    string Multe_Fete = "Ai facut-o de oaie! Femeile te distrug, sunt %d baieti la %d fete. Lupta continua! \n";
    string Multi_Baieti = "Suntem %d baieti la %d fete! Curand vom domina campul de bataie! \n";


    if(fete == 0)
        cout << Numai_Baieti;
    else
        if(baieti == 0)
            cout << Numai_Fete;
        else
        {
            if(fete > baieti)
               printf(Multe_Fete.c_str(),baieti,fete);
            else
                printf(Multi_Baieti.c_str(),baieti,fete);
        }
}

baza_de_date::baza_de_date()
{
    //vector_pointeri_la_persoane = NULL; // CRAPA deoarece din start este initializat cu NULL;
                                           // CRAPA deoarece nu are ce element sa initializeze cu NULL, nr pers = 0 la pasul asta;
    numar_persoane = 0;

};

baza_de_date::~baza_de_date()
{
    for(unsigned int i=0; i<numar_persoane; i++)
    {
        delete vector_pointeri_la_persoane[i];
        vector_pointeri_la_persoane[i] = NULL;
    }

  //  delete vector_pointeri_la_persoane;
};

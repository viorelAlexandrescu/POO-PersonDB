#include <iostream>      //C++ Standard I/O Library
#include <cstring>       //C String Library
#include <cstdlib>       //C Standard Library
#include "persoana.h" //Header-ul pentru clasa persoana
#include "baza_de_date.h"//Header-ul pentru clasa baza_de_date_a_persoanelor_de_date


using namespace std;

int main()
{
    int selectie;
    baza_de_date baza_de_date_a_persoanelor;
    do
    {
        system("cls");
        cout<<"\t Buna ziua! Aceasta este baza de date a unor persoane !"<<endl;
        if(baza_de_date_a_persoanelor.get_nr_persoane()==0 || baza_de_date_a_persoanelor.get_nr_persoane()>1)
        {
            cout<<"\t Momentan sunt "<< baza_de_date_a_persoanelor.get_nr_persoane() <<" persoane in baza de date!\n";
        }
        else
        {
            cout<<"\t Momentan este "<< baza_de_date_a_persoanelor.get_nr_persoane()  <<" persoana in baza de date!\n";
        }

        cout<<"\t    Ce ati dori sa faceti? \n\n";
        cout<<"\t (1)Sa adaugati o peroana\n";
        cout<<"\t (2)Sa stergeti o persoana\n";
        cout<<"\t (3)Sa stergeti intreaga baza de date\n";
        cout<<"\t (4)Afisati in ordine alfabetica!\n";
        cout<<"\t (5)Afisati in functie de anul nasterii\n";
        cout<<"\t (6)Sa iesiti din program!\n\n\n\t\t - ";
        cin>>selectie;

        switch(selectie)
        {

        case 1:
        {
            int n;//numarul de persoane a fii adaugate
            int An_al_nasterii_Ales;
            string Nume_Ales;
            char Sex_Ales;
            persoana *Persoana_Noua;

            cout<<"\t Cate persoane doriti adaugate? - ";
            cin>>n;

            for(int i=0; i<n; i++)
            {   cout<<endl;

                do{
                cout << "Nume: ";
                cin>>Nume_Ales;
                }while(Nume_Ales.length()==1);

                do{
                cout<< "Anul Nasteri: ";
                cin>>An_al_nasterii_Ales;
                }while(An_al_nasterii_Ales<1955 || An_al_nasterii_Ales>2015);

                do{
                cout<< "Sex: ";
                cin>>Sex_Ales;
                }while(Sex_Ales!='M' &&    Sex_Ales!='F');

                Persoana_Noua = new persoana;

                baza_de_date_a_persoanelor.add_persoana(Nume_Ales, An_al_nasterii_Ales, Sex_Ales, Persoana_Noua);
                baza_de_date_a_persoanelor.sortare_alfabetica();
                cout<<endl;

            }

            break;
        }

        case 2:
        {
            int alegere;
            cout<<"Dupa ce criteriu doriti sa stergeti? \n\t1 - Nume \n\t2 - An al nasterii \n\t3 - Sex\n\n\t-";
            cin>>alegere;
            if(alegere == 1)
            {
                string Nume_Ales;
                cout<<"Dupa ce nume? - ";
                cin>>Nume_Ales;
                baza_de_date_a_persoanelor.delete_persoana(Nume_Ales);
            }
            if(alegere == 2)
            {
                int an_ales;
                cout<<"Dupa ce an? - ";
                cin>>an_ales;
                baza_de_date_a_persoanelor.delete_persoana(an_ales);
            }
            if(alegere == 3)
            {
                char sex_ales;
                cout<<"Dupa ce sex(M/F) - ";
                cin>>sex_ales;
                baza_de_date_a_persoanelor.delete_persoana(sex_ales);
            }

            break;
        }

        case 3:
        {
            baza_de_date_a_persoanelor.delete_persoana_toate();
            cout << "\t Baza de date a fost stearsa in intregime!\n\n";
            system("pause");
            break;
        }
        case 4:
        {
            baza_de_date_a_persoanelor.afisare_alfabetica();
            break;
        }
        case 5:
        {
            baza_de_date_a_persoanelor.afisare_dupa_anul_nasterii();
            break;
        }

        }
        system("cls");

    }
    while(selectie!=6);

    cout<<"\t O zi buna va doresc!\n";
    return 0;


}

//knihovny
#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cmath>
#include "../fgw_headers/fgw_text.h"

using namespace std;
using namespace fgw;

int main()
{
    //nacitani souboru
    ifstream file("km.txt");
    ifstream kmfile("km.txt");
    ifstream kcfile("kc.txt");
    ifstream litryfile("litry.txt");
    //definovani promennych
    char a[80];
    string kms, kcs, litrys, s, unused;
    int line = 0;
    double pocet=0, spotreba=0, litry=0, km=0, kc=0, kmcelkem=0, kccelkem=0, litrycelkem=0, kmprumer=0, jedenkm=0, spotrebacelkem=0, spotrebaprumer=0;

    //menu
    cout << "Vyberte jednu z nasledujicich moznosti zadanim\n"
         << "cisla a stisknutim Enter.\n\n"
         << "Moznosti:\n\n";
    cout << "\t1. Rucni zadavani hodnot.\n"
         << "\t2. Nacteni hodnot ze souboru. \n\n";
    //vyber menu
    int const hodnota(read<int>("Cislo: "));

    switch (hodnota)
    {
    case 1:

        cout << "\nKolikrat budete chtit zadat hodnoty (kilometry, cena a litry)? \n\nPocet: ";
        cin >> pocet;
        //cyklus for
        for (int i=1;i<pocet+1;i++){
        cout << "\nZadani prikladu cislo " << i << ".\n"<< endl;
        cout << "Zadej ujete kilometry. \nCislo: ";
        cin >> km;
        //ukladani udaju do souboru
        ofstream kmfile;
        kmfile.open ("km.txt", ofstream::out | ofstream::app);
        kmfile << km << endl;
        kmfile.close();

        cout << "\nZadej natankovane litry. \nCislo: ";
        cin >> litry;
        ofstream litryfile;
        litryfile.open ("litry.txt", ofstream::out | ofstream::app);
        litryfile << litry << endl;
        litryfile.close();

        cout << "\nZadej cenu natankovani. \nCislo: ";
        cin >> kc;
        ofstream kcfile;
        kcfile.open ("kc.txt", ofstream::out | ofstream::app);
        kcfile << kc << endl;
        kcfile.close();
        //vypocty
        kmcelkem=kmcelkem+km;
        jedenkm=kc/km;
        kmprumer=(kmcelkem)/pocet;
        litrycelkem=litrycelkem+litry;
        spotreba=(litrycelkem/kmcelkem)*100;
        spotrebacelkem=spotrebacelkem+spotreba;
        spotrebaprumer=spotrebacelkem/pocet;
        }
        //vypsani
        //cout << "\nKilometry celkem " << kmcelkem << endl;
        //cout << "Litry celkem " << litrycelkem << endl;
        cout << "Kilometry prumer " << kmprumer << endl;
        cout << "Cena za jeden kilometr " << jedenkm << endl;
        //cout << "Prumerna spotreba " << spotreba << endl;
        //cout << "Spotreba celkem " << spotrebacelkem << endl;
        cout << "Prumerna spotreba celkem " << spotrebaprumer << endl;
        break;

    case 2:
        //spocitani radku
        if(file.is_open())
        {
        while (getline(file, unused)){
        ++line;}
        cout << "Data nacteny z " << line << " radku." << endl;
        }
        else
        {
            cout << "Soubor km.txt nenalezen \n";
        }

        //kontola souboru
        if(!kmfile)
        {
            cout << "Soubor nenalezen!" << endl;
        }
        else;
        //vypis ze souboru
        while(!kmfile.eof())
        {
            kmfile >> a;
            km = atof(a); //pretypovani ze stringu do double
            kmcelkem = kmcelkem+km;
        }
            //zde bylo potreba odecist jednu hodnotu, protoze cyklus pripocital 2x posledni hodnotu
            kmcelkem = kmcelkem-km;

        if(!kcfile)
        {
            cout << "Soubor nenalezen!" << endl;
        }
        else;
        while(!kcfile.eof())
        {
            kcfile >> a;
            kc = atof(a);
            kccelkem=kccelkem+kc;
        }
            kccelkem=kccelkem-kc;
            jedenkm=kccelkem/kmcelkem;

        if(!litryfile)
        {
            cout << "Soubor nenalezen!" << endl;
        }
        else;
        while(!litryfile.eof())
        {
            litryfile >> a;
            litry = atof(a);
            litrycelkem=litrycelkem+litry;
        }
            litrycelkem=litrycelkem-litry;

        //vypocty
        kmprumer=(kmcelkem)/line;
        spotreba=litry/km*100;
        spotrebacelkem=spotrebacelkem+((litrycelkem/kmcelkem)*100);
        spotrebaprumer=spotrebacelkem/line;

        //cout << "\nKilometry celkem " << kmcelkem << endl;
        //cout << "Litry celkem " << litrycelkem << endl;
        cout << "Kilometry prumer " << kmprumer << endl;
        cout << "Cena za jeden kilometr " << jedenkm << endl;
        //cout << "Cena celkem " << kccelkem << endl;
        //cout << "Prumerna spotreba (posledni zadana hodnota) " << spotreba << endl;
        cout << "Spotreba celkem " << spotrebacelkem << endl;
        cout << "Prumerna spotreba celkem " << spotrebaprumer << endl;

        break;

    default:
        //v pripade ze zada jinou hodnotu nez je ve switchi
        cout << hodnota << " neni prijatelna.";
    }

    return 0;
}

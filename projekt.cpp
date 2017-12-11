#include <iostream>
#include <string>
#include <fstream>
#include "projekt.h"
#include "../fgw_headers/fgw_text.h"

using namespace std;

int vezmi_int(){
int vezmi_int(istream &); /*Pretezovani */
    for(;;){
        int hodnota;
        cin >> hodnota;
        if (cin.fail()){
            cin.clear(); //reset
            string nesmysl;
            getline(cin,nesmysl);
            cout << nesmysl << " = tohle neni cele cislo, zadej ho znovu.\n";
        }
        else{
            return hodnota;
        }
    }
}

int vezmi_int(istream & zdroj) {
    int docas;
    zdroj >> docas;
    if(zdroj.fail()){
        zdroj.clear();
        cerr << "Ve funkci vezmi_int byl pouzit poskozeny datovy soubor.\n"; //cout
        throw fgw::problem("poskozeny datovy proud.");
        }
    else return docas;
}

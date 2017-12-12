#include <iostream>
#include <string>
#include <fstream>
#include "projekt.h"
#include "../fgw_headers/fgw_text.h"

using namespace std;



double spotrebacpp(double litry, double km){
   double spotreba=litry/km*100;

    return spotreba;
}

double spotrebacelkemcpp(double spotrebacelkem, double litrycelkem, double kmcelkem){
   double spotrebacelkemm=spotrebacelkem+((litrycelkem/kmcelkem)*100);

    return spotrebacelkemm;
}

double spotrebaprumercpp(double spotrebacelkem){
   double spotrebaprumer=spotrebacelkem/2;

    return spotrebaprumer;
}

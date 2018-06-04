#include "std_lib_facilities.h"

// converts Celsius to Kelvin
double ctok(double c)
{
    return c + 273.15;
}

int main()
{
    double c = 0;   // declare input variable
    cin>>c;   // retrieve temperature to input variable
    double k = ctok(c);   // convert temperature
    cout<<k<<'\n';  // print out temperature

    return 0;
}
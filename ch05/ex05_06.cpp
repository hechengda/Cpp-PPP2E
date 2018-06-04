#include "std_lib_facilities.h"

// converts Celsius to Fahrenheit
double ctof(double c)
{
    if (c<-273.15) {
        error("lower than 0K");
    }
    return 9.0*c/5.0+32.0;
}

// converts Fahrenheit to Celsius
double ktoc(double f)
{
    if (f<-459.67) {
        error("lower than 0K");
    }
    return 5.0*(f-32.0)/9.0;
}

int main()
{
    double c = 0;   // declare input variable
    cin>>c;   // retrieve temperature to input variable
    double f = ctof(c);   // convert temperature
    cout<<f<<'\n';  // print out temperature

    return 0;
}
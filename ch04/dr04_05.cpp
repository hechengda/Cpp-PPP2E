#include "std_lib_facilities.h"

int main()
{
    double ival1, ival2;

    while (cin>>ival1>>ival2) {
        double smaller = ival1, larger = ival2;

        if (ival1>ival2) {
            smaller = ival2;
            larger = ival1;
        }
        if (ival1==ival2) {
            cout<<"the numbers are equal\n";
        }
        else {
            cout<<"the smaller value is: "<<smaller<<'\n';
            cout<<"the larger value is: "<<larger<<'\n';
            constexpr double diff = 1.0/100.0;

            if (larger-smaller<diff) {
                cout<<"the numbers are almost equal\n";
            }
        }
    }

    return 0;
}
#include "std_lib_facilities.h"

int main()
{
    double val;
    string unit;

    while (cin>>val>>unit) {
        if (unit!="cm" && unit!="m" && unit!="in" && unit!="ft") {
            cout<<"illegal units, try again.\n";
            continue;
        }
        cout<<val<<unit<<'\n';
    }

    return 0;
}
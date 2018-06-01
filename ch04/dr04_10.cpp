#include "std_lib_facilities.h"

int main()
{
    constexpr double cm_per_m = 0.01;
    constexpr double in_per_m = 2.54*cm_per_m;
    constexpr double ft_per_m = 12*in_per_m;
    vector<double> v;
    double val;
    string unit;

    while (cin>>val>>unit) {
        if (unit!="cm" && unit!="m" && unit!="in" && unit!="ft") {
            cout<<"illegal units, try again.\n";
            continue;
        }

        // converted into meters
        if (unit=="cm") {
            val *= cm_per_m;
        }
        else if (unit=="in") {
            val *= in_per_m;
        }
        else if (unit=="ft") {
            val *= ft_per_m;
        }
        v.push_back(val);   // push the value into vector
    }

    // output the values
    for (double d : v) {
        cout<<d<<' ';
    }
    cout<<'\n';

    return 0;
}
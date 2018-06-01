#include "std_lib_facilities.h"

int main()
{
    constexpr double cm_per_m = 0.01;
    constexpr double in_per_m = 2.54*cm_per_m;
    constexpr double ft_per_m = 12*in_per_m;
    double sum = 0.0, smallest = DBL_MAX, largest = DBL_MIN;
    int num = 0;    // # of values
    double val;
    string unit;

    while (cin>>val>>unit) {
        if (unit!="cm" && unit!="m" && unit!="in" && unit!="ft") {
            cout<<"illegal units, try again.\n";
            continue;
        }
        if (unit=="cm") {
            val *= cm_per_m;
        }
        else if (unit=="in") {
            val *= in_per_m;
        }
        else if (unit=="ft") {
            val *= ft_per_m;
        }
        if (val<smallest) {
            smallest = val;
        }
        if (val>largest) {
            largest = val;
        }
        ++num;
        sum += val; // sum the values
    }
    cout<<"the smallest is "<<smallest
        <<", the largest is "<<largest
        <<", the # of values is "<<num
        <<", the sum of values is "<<sum<<'\n';

    return 0;
}
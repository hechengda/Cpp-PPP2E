#include "std_lib_facilities.h"

int main()
{
    double val, smallest = DBL_MAX, largest = DBL_MIN;

    while (cin>>val) {
        cout<<val<<'\n';

        if (val<smallest) {
            smallest = val;
            cout<<"the smallest so far\n";
        }
        if (val>largest) {
            largest = val;
            cout<<"the largest so far\n";
        }
    }

    return 0;
}
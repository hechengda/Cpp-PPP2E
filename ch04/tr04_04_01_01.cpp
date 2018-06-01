#include "std_lib_facilities.h"

int main()
{
    constexpr double yen_per_dollar = 0.0092;
    constexpr double euro_per_dollar = 1.15;
    constexpr double pound_per_dollar = 1.32;
    char unit;

    for (double currency;
        cout<<"Please enter a length followed by a unit (y e or p):\n", cin>>currency>>unit;) {
        if (unit=='y') {
            cout<<currency<<"yen=="<<yen_per_dollar*currency<<"dollars\n";
        }
        else if (unit=='e') {
            cout<<currency<<"euro=="<<euro_per_dollar*currency<<"dollars\n";
        }
        else if (unit=='p') {
            cout<<currency<<"pound=="<<pound_per_dollar*currency<<"dollars\n";
        }
        else {
            cout<<"Sorry, I don't know a unit called "<<unit<<'\n';
        }
    }

    return 0;
}
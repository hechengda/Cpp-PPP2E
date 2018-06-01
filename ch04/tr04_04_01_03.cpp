#include "std_lib_facilities.h"

int main()
{
    constexpr double yen_per_dollar = 0.0092;
    constexpr double euro_per_dollar = 1.15;
    constexpr double pound_per_dollar = 1.32;
    constexpr double yuan_per_dollar = 0.16;
    constexpr double kroner_per_dollar = 0.16;
    char unit;

    for (double currency;
        cout<<"Please enter a length followed by a unit (j u p y or k):\n", cin>>currency>>unit;) {
        switch (unit) {
        case 'j':
            cout<<currency<<"yen=="<<yen_per_dollar*currency<<"dollars\n";
            break;
        case 'u':
            cout<<currency<<"euro=="<<euro_per_dollar*currency<<"dollars\n";
            break;
        case 'p':
            cout<<currency<<"pound=="<<pound_per_dollar*currency<<"dollars\n";
            break;
        case 'y':
            cout<<currency<<"yuan=="<<yuan_per_dollar*currency<<"dollars\n";
            break;
        case 'k':
            cout<<currency<<"kroner=="<<kroner_per_dollar*currency<<"dollars\n";
            break;
        default:
            cout<<"Sorry, I don't know a unit called "<<unit<<"\n";
            break;
        }
    }

    return 0;
}
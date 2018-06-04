#include "std_lib_facilities.h"

int main()
{
    cout<<"Please enter for a, b and c, seperated by whitespace: ";

    for (double a, b, c; cin>>a>>b>>c;) {
        if (!a) {
            cout<<"a should't be zero, try again?"<<'\n';
            continue;
        }
        double sq = b*b-4*a*c;

        if (sq<0) {
            cout<<"no real solutions, try again?"<<'\n';
            continue;
        }
        else if (!sq) {
            cout<<"both solutions are: "<<-b/(2*a)<<'\n';
        }
        else {
            cout<<"one solution is: "<<(-b+sqrt(sq))/(2*a)<<", the other is: "<<(-b-sqrt(sq))/(2*a)<<'\n';
        }
    }

    return 0;
}
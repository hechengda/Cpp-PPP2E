#include "std_lib_facilities.h"

int main()
{
    cout<<"Please enter for a, b and c, seperated by whitespace: ";

    for (double a, b, c; cin>>a>>b>>c;) {
        if (!a) {
            cout<<"a should't be zero, try again?"<<'\n';
            continue;
        }
        double D = b*b-4*a*c;

        if (D<0) {
            cout<<"no real solutions, try again?"<<'\n';
            continue;
        }
        else {
            double x1 = (-b+sqrt(D))/(2*a);
            double x2 = (-b-sqrt(D))/(2*a);

            if (x1==x2) {
                cout<<"both solutions are: "<<x1<<'\n';
            }
            else {
                cout<<"one solution is: "<<x1<<", the other is: "<<x2<<'\n';
            }
        }
    }

    return 0;
}
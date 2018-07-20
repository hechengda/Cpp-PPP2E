// Chapter 3 Exercise 11

#include "std_lib_facilities.h"

int main()
try {
    cout<<"How many pennies do you have?\n";
    int pen;
    cin>>pen;
    if (cin && pen>0) {
        cout<<"You have "<<pen<<(pen==1 ? " pennie." : " pennies.");
    }

    cout<<"\nHow many nickels do you have?\n";
    int nic;
    cin>>nic;
    if (cin && nic>0) {
        cout<<"You have "<<nic<<(nic==1 ? " nickel." : " nickels.");
    }

    cout<<"\nHow many dimes do you have?\n";
    int dim;
    cin>>dim;
    if (cin && dim>0) {
        cout<<"You have "<<dim<<(dim==1 ? " dime." : " dimes.");
    }

    cout<<"\nHow many quarters do you have?\n";
    int qua;
    cin>>qua;
    if (cin && qua>0) {
        cout<<"You have "<<qua<<(qua==1 ? " quarter." : " quarters.");
    }

    cout<<"\nHow many half dollars do you have?\n";
    int hfd;
    cin>>hfd;
    if (cin && hfd>0) {
        cout<<"You have "<<hfd<<(hfd==1 ? " half dollar." : " half dollars.");
    }

    cout<<"\nHow many one-dollar coins do you have?\n";
    int od;
    cin>>od;
    if (cin && od>0) {
        cout<<"You have "<<od<<(od==1 ? " one-dollar coin." : " one-dollar coins.");
    }

    double total = (pen+5*nic+10*dim+25*qua+50*hfd+100*od)/100.0;
    if (total>0) {
        cout<<"\nThe value of all of your coins is $"<<total<<"\n";
    }
    return 0;
}
catch (runtime_error e) {
    cout<<e.what()<<'\n';
    return 1;
}

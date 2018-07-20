// Bjarne Stroustrup 7/20/2009
// Chapter 3 Exercise 9

#include "std_lib_facilities.h"

int main()
try {
    for (string s; cout<<"Please enter another integer as a text string: ", cin>>s;) {
        if (s=="zero") {
            cout<<s<<" has the value 0\n";
        }
        else if (s=="one") {
            cout<<s<<" has the value 1\n";
        }
        else if (s=="two") {
            cout<<s<<" has the value 2\n";
        }
        else if (s=="three") {
            cout<<s<<" has the value 3\n";
        }
        else if (s=="four") {
            cout<<s<<" has the value 4\n";
        }
        else {
            cout<<s<<" does not have a numeric value I understand\n";
        }
    }
    return 0;
}
catch (runtime_error e) {   // this code is to produce error messages; it will be described in Chapter 5
    cout<<e.what()<<'\n';
    return 1;
}

/*
To make it less tedious to test I made a loop testing strings. I "forgot" to provide a way to exit
that loop so you must either kill the program or enter an end-of-input (cntrl-Z for Windows or cntrl-D
for Unix). Maybe you could modify the program to end if it sees "Quit"?

All of those ifs can get tedious (and anything tedious is error prone), but for now we don't have
the tools to do better. later (e.g. Chapter 4), we'll see how this code can be simplified by using
a for-loop and a vector of strings.
*/
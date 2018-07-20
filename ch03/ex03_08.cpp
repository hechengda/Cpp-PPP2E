// Bjarne Stroustrup 7/20/2009
// Chapter 3 Exercise 8

#include "std_lib_facilities.h"

int main()
try {
    for (int val = 0; cout<<"Please enter an integer: ", cin>>val;) {
        string res = "even";
        if (val%2) {    // a number is even if it is 0 modulo 2 and odd otherwise
            res = "odd";
        }
        cout<<"The value "<<val<<" is an "<<res<<" number\n";
    }
    return 0;
}
catch (runtime_error e) {   // this code is to produceerror messages; it will be described in Chapter 5
    cout<<e.what()<<'\n';
    return 1;
}

/*
Note the technique of picking a default value for the result ("even") and changing it only if needed.
The alternative would be to use a conditional expression and write
string res = (val%2) ? "even" : "odd";

Did I get it right? Does it work for negative numbers? For 0?

It would be less tedious to check the program if it had a loop so that we could read and check
several numbers in one run.
*/
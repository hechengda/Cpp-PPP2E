// Bjarne Stroustrup 3/26/2009
// Chapter 4 Exercise 5

#include "std_lib_facilities.h"

// Correction/errata: % is not defined for floating-point numbers, so we don't implement %
// the alternative would be to use integers for the input values.

// How do you exit?

int main()
try {
    cout<<"please enter two floating-point values separated by an operator\nThe operator can be + - * or / : ";
    double val1;
    double val2;
    char op;

    while (cin>>val1>>op>>val2) { // read number operation number
        string oper;
        double result;

        switch (op) {
            case '+':
                oper = "sum of ";
                result = val1+val2;
                break;
            case '-':
                oper = "difference between ";
                result = val1-val2;
                break;
            case '*':
                oper = "product of ";
                result = val1*val2;
                break;
            case '/':
                if (!val2) {
                    error("trying to divide by zero");
                }
                oper = "ratio of ";
                result = val1/val2;
                break;
            default:
                error("bad operator");
                break;
        }
        cout<<oper<<val1<<" and "<<val2<<" is "<<result<<'\n';
        cout<<"Try again: ";
    }
    return 0;
}
catch (runtime_error e) {   // this code is to produce error messages; it will be described in Chapter 5
    cout<<e.what()<<'\n';
    return 1;
}
catch (...) {   // this code is to produce error messages; it will be described in Chapter 5
    cout<<"exiting\n";
    return 2;
}

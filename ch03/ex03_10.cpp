// Bjarne Stroustrup 4/4/2009
// Chapter 3 Exercise 10

#include "std_lib_facilities.h"

int main()
{
    try {
        for (string operation, double val1, val2;
            cout<<"Please enter an operation (+, -, *, /, plus, minus, mul, div) followed by two floating-point values separated by a space: ",
            cin>>operation>>val1>>val2;) {  // we do the following as long as we get "good" input
            // and then stop loops will be explainied in detail in Chapter 4
            double res = 0.0;
            if (operation=="plus" || operation=="+") {
                res = val1+val2;
            }
            else if (operation=="minus" || operation=="-") {
                res = val1-val2;
            }
            else if (operation=="mul" || operation=="*") {
                res = val1*val2;
            }
            else if (operation=="div" || operation=="/") {
                if (val2==0.0) {
                    error("trying to divide by zero");
                }
                res = val1/val2;
            }
            else {
                error("sorry: bad operator: ", operation);
            }
            cout << val1 << operation << val2 << " == " << res <<'\n';
        }
        cout << "exit because of bad input\n";
    }
    catch (runtime_error e) {   // this code is to produceerror messages; it will be described in Chapter 5
        cout << e.what() << '\n';
    }
    return 0;
}

/*
While testing, I found it tedious to keep re-starting the program to enter a new set of values,
so I added the while-loop. I know that loops won't be explained in detail until Chapter 4, but
we did show a while loop in Chapter 3 and anyway, you *know* about doing things repeatedly from
everyday life so "keep doing this until you run out of inputs" is well known.

It is always a good idea to be sure that a divisor isn't zero.
*/
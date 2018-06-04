// Bjarne Stroustrup 1/15/2010
// Chapter 5 Exercise 11

#include "std_lib_facilities.h"

/*
Compute the series and note when the int overflows; the previous value was the largest that fit
*/

int main()
{
    int a = 1;
    int b = 2;

    while (a<b) {
        cout<<a<<'\n';
        int c = a+b;
        a = b;  // drop the lowest number
        b = c;  // add a new highest number
    }
    cout<<"the largest Fibonacci number that fits in an int is "<<a<<'\n';

    return 0;
}
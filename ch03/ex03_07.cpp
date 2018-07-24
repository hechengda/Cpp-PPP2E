// Chapter 3 Exercise 7

#include "std_lib_facilities.h"	

int main()
try {
    string val1;
    string val2;
    string val3;
    cout << "Please enter three string values separated by a space: ";
    cin >> val1 >> val2 >> val3;
    if (!cin) error("something went bad with the read");
    cout << "values read : " << val1 << ", " << val2 << ", " << val3 <<'\n';

    string smallest;
    string middle;
    string largest;
    if (val1<=val2 && val1<=val3) {	// && means and
        smallest = val1;
        if (val2<=val3) {
            middle = val2;
            largest = val3;
        }
        else {
            middle = val3;
            largest = val2;
        }
    }
    else if (val2<=val1 && val2<=val3) {
        smallest = val2;
        if (val1<=val3) {
            middle = val1;
            largest = val3;
        }
        else {
            middle = val3;
            largest = val1;
        }
    }
    else {	// since neither val1 nor val2 was smaller than val3, val3 must be the smallest
        smallest = val3;
        if (val1<=val2) {
            middle = val1;
            largest = val2;
        }
        else {
            middle = val2;
            largest = val1;
        }
    }

    cout << "values sorted : " << smallest << ", " << middle << ", " << largest <<'\n';
    return 0;
}
catch (runtime_error e) {	// this code is to produceerror messages; it will be described in Chapter 5
    cout << e.what() << '\n';
    return 1;
}

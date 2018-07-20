// Bjarne Stroustrup 3/22/2009
// Chapter 3 Exercise 4

#include "std_lib_facilities.h"	

int main()
try {
    for (int val1 = 0, val2 = 0;
        cout<<"Please enter two integer values separated by a space: ", cin>>val1>>val2;) {
        cout<<"values : "<<val1<<" "<<val2<<'\n';

        if (val1<val2) cout<<val1<<" is smallest\n";
        if (val2<val1) cout<<val2<<" is smallest\n";
        if (val1==val2) cout<<val1<<" and "<<val2<<" are equal\n"; // I "forgot" to ask for that possibility

        cout<<"sum : "<<val1+val2<<'\n';
        cout<<"product : "<<val1*val2<<'\n';
        if (val2==0)
            cout<<"good try! but I don't divide by zero\n";
        else
            cout<<"ratio (val1/val2): "<<val1/val2<<'\n';	// note that this is integer division so 5/2 is 2 (not 2.5)

        // some more tests:
        if (val1<0) cout<<val1<<" is negative\n";
        cout<<"difference (val1-val2) : "<<val1-val2<<'\n';
        if (val2!=0) cout<<"remainder (val1%val2) : "<<val1%val2<<'\n';
        cout<<"square(val1) : "<<val1*val1<<'\n';
    }
    return 0;
}
catch (runtime_error e) {	// this code is to produceerror messages; it will be described in Chapter 5
    cout<<e.what()<<'\n';
    return 1;
}

/*

How would you test this?
First try some sensible numbers
1 2
99999 44
-23 9
etc.

When that gets boring try to see if you can break the code by giving
"bad" input:
0 0
-123456789 987654321
one two
Etc.
*/
// Bjarne Stroustrup 7/25/2009
// Chapter 4 Exercise 19

#include "std_lib_facilities.h"

/*
enter name-and-value pairs into a pair of vectors
check that each name is unique
exit when we see the input "NoName 0"
output the pairs
*/

int main()
try {
    vector<string> names;
    vector<int> scores;
    string s;
    int val;

    while (cin>>s>>val && s!="NoName") {    // read string int pair
        for (int i = 0; i!=names.size(); ++i) {
            if (names[i]==s) {   // chek for duplicate
                error("duplicate", s);
            }
        }
        names.push_back(s);   // insert new one
        scores.push_back(val);
        cout<<"("<<s<<", "<<val<<")\n";
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

/*
(name,value) pairs are useful in many contexts. This is just the first and simplest variant.
Exercise 6.4 is another variant.

Note how we could read a (name,value) pair and used a specific name to indicated the end of input.
There is a second (undocumented) way of terminating the input. Try leaving out an integer; for example,
frank 3 joe bill 7
You may consider that a bug or a feature. If you consider it a bug, you'll find it a bit hard to detect
it reliably.

Checking for duplicates is another common activity, and easy.
*/
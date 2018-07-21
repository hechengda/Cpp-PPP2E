#include "std_lib_facilities.h"

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
    cout<<"Please enter a score: ";

    for (int v; cin>>v;) {
        string res;

        for (int i = 0; i!=scores.size(); ++i) {
            if (scores[i]==v) {   // search the target
                res += names[i]+' ';
            }
        }
        if (!res.size()) {  // not found
            cout<<"score not found. try again: ";
            continue;
        }
        cout<<res<<'\n';
        cout<<"Enter another score: ";
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

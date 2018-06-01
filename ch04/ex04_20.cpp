#include "std_lib_facilities.h"

int main()
{
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
        cout<<"Please enter a name: ";

        for (string n; cin>>n;) {
            int i = 0;

            for (; i!=names.size(); ++i) {
                if (names[i]==n) {   // search the target
                    cout<<scores[i]<<'\n';
                    cout<<"Enter another name: ";
                    break;
                }
            }
            if (i==names.size()) {  // not found
                cout<<"name not found. try again: ";
            }
        }

    }
    catch (runtime_error e) {   // this code is to produce error messages; it will be described in Chapter 5
        cout<<e.what()<<'\n';
    }
    catch (...) {   // this code is to produce error messages; it will be described in Chapter 5
        cout<<"exiting\n";
    }

    return 0;
}
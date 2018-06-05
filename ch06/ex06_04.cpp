#include "std_lib_facilities.h"

/*
enter name-and-value pairs into a pair of vectors
check that each name is unique
exit when we see the input "NoName 0"
output the pairs
*/

using Name_value = pair<string, int>;

int main()
try {
    vector<Name_value> values;
    string s;
    int val;

    while (cin>>s>>val && s!="NoName") {    // read string int pair
        int i = 0;

        for (; i!=values.size(); ++i) {
            if ((values[i]).first==s) {   // chek for duplicate
                error("duplicate - ", s);
            }
        }
        values.push_back({s,val});   // insert new one
        cout<<"("<<s<<", "<<val<<")\n";
    }
    return 0;
}
catch (runtime_error e) {
    cerr<<e.what()<<'\n';
    return 1;
}
catch (...) {
    cerr<<"exiting\n";
    return 2;
}

#include "std_lib_facilities.h"

int main()
try {
    vector<string> v {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    while (true) {
        int val;
        if (cin>>val) { // try to read an integer
            if (val<0 || val>9) {
                error("out of boundaries");
            }
            cout<<v[val]<<'\n';
            continue;   // succeed reading
        }
        cin.clear();    // clear string after failed attempt to read an integer
        string str;
        cin>>str;

        int i = 0;
        for (; i != v.size(); ++i) {
            if (str==v[i]) {    // find the target
                cout<<i<<'\n';
                break;
            }
        }
        if (i==v.size()) {  // not found
            error("unexpected number string: ", str);
        }
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

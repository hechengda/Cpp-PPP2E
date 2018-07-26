#include "std_lib_facilities.h"

int main()
try {
    cout<<"Please enter the number of values you want to difference: ";
    int val = -1;   // initializing to a negative number means that a failed read will be handled by the check of the value
    cin>>val;

    if (val<2) {
        error("the number of elements must be greater than 1");
    }
    cout<<"Please enter some doubles (press '|' to stop): ";
    vector<double> v;

    for (double val; cin>>val;) {  // read until we find something that's not a double
        v.push_back(val);
    }
    if (v.size()<size_t(val)) {
        error("too few numbers; we need ", val);
    }
    vector<double> diff;

    for (int i = 0; i+1<val; ++i) {
        diff.push_back(v[i+1]-v[i]);
    }
    cout<<"The differences between the first "<<val<<" adjacent values ( ";

    for (int i = 0; i<val; ++i) {
        cout<<v[i]<<' ';
    }
    cout<<") is ( ";

    for (double d : diff) {
        cout<<d<<' ';
    }
    cout<<")\n";
    return 0;
}
catch (const runtime_error& e) {
    cout<<e.what()<<'\n';
    return 1;
}

#include "std_lib_facilities.h"

int index_of(const vector<string>& v, string str);

int main()
try {
    cout<<"enter several names, end by '|': ";
    vector<string> names;

    for (string name; cin>>name;) {
        if (name=="|") {
            break;
        }
        names.push_back(name);
    }
    cout<<"enter the corresponding ages, end by '|': ";
    vector<double> ages;

    for (double age; cin>>age;) {
        ages.push_back(age);
    }
    cout<<"before sorting: ";

    for (size_t i = 0; i<names.size(); ++i) {
        cout<<"("<<names[i]<<","<<ages[i]<<") ";
    }
    cout<<'\n';
    vector<string> name_copies(names);      // copies
    sort(names.begin(), names.end());       // sort
    vector<double> age_copies;      // empty

    for (size_t i = 0; i<names.size(); ++i) {       // ordered already
        age_copies.push_back(ages[index_of(name_copies, names[i])]);        // add in order
    }
    cout<<"after sorting: ";

    for (size_t i = 0; i<names.size(); ++i) {
        cout<<"("<<names[i]<<","<<age_copies[i]<<") ";
    }
    cout<<'\n';

    return 0;
}
catch (const std::exception& e) {
    cout<<e.what()<<'\n';
    return 1;
}

int index_of(const vector<string>& v, string str)
{
    for (size_t i = 0; i<v.size(); ++i) {       // simple search
        if (v[i]==str) {
            return i;
        }
    }
    return -1;
}

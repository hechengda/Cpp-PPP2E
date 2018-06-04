#include "std_lib_facilities.h"

int main()
{
    try {
        cout<<"Please enter the number of values you want to sum: ";
        int val = -1;   // initializing to a negative number means that a failed read will be handled by the check of the value
        cin>>val;

        if (val<1) {
            error("the number of elements must be a positive integer");
        }
        cout<<"Please enter some integers (press '|' to stop): ";
        vector<int> v;

        for (int val; cin>>val;) {  // read until we find something that's not an integer
            v.push_back(val);
        }
        if (v.size()<size_t(val)) {
            error("too few numbers; we need ", val);
        }
        int sum = 0;

        for (int i = 0; i<val; ++i) {
            sum += v[i];
        }
        cout<<"The sum of the first "<<val<<" numbers ( ";

        for (int i = 0; i<val; ++i) {
            cout<<v[i]<<' ';
        }
        cout<<") is "<<sum<<'\n';
        return 0;
    }
    catch (const runtime_error& e) {
        cout<<e.what()<<'\n';
        return 1;
    }
}
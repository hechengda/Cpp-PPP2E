#include "std_lib_facilities.h"

int main()
{
    cout<<"Please enter a series of integer numbers, seperated by whitespace: ";
    vector<pair<int, int>> vp;  // pair.first is the #, pair.second is the occur times

    for (int val; cin>>val;) {
        int i = 0;

        for (; i!=vp.size(); ++i) {
            if ((vp[i]).first==val) {   // already exist
                ++(vp[i].second);   // increase the count
                break;
            }
        }
        if (i==vp.size()) { // no found
            vp.push_back({ val, 1 });   // insert new one
        }
    }
    int mode = 0;   // the mode of the given seq
    int max = 0;    // max times occured

    for (auto p : vp) {
        if (p.second>max) {
            max = p.second;
            mode = p.first;
        }
    }
    cout<<"The mode of the given seq is: "<<mode
        <<", and occurs "<<max<<" times"<<'\n';

    return 0;
}
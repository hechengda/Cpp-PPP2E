#include "std_lib_facilities.h"

int main()
{
    cout<<"Please enter a series of words, seperated by whitespace: ";
    vector<pair<string, int>> vp;  // pair.first is the word, pair.second is the occur times
    string max_s;   // the max of the given seq
    string min_s;   // the min of the given seq

    for (string s; cin>>s;) {
        if (s>max_s) {
            max_s = s;
        }
        if (s<min_s) {
            min_s = s;
        }
        int i = 0;

        for (; i!=vp.size(); ++i) {
            if ((vp[i]).first==s) {   // already exist
                ++(vp[i].second);   // increase the count
                break;
            }
        }
        if (i==vp.size()) { // no found
            vp.push_back({ s, 1 });   // insert new one
        }
    }
    string mode;   // the mode of the given seq
    int max = 0;    // max times occured

    for (auto p : vp) {
        if (p.second>max) {
            max = p.second;
            mode = p.first;
        }
    }
    cout<<"The max of the given seq is: "<<max_s
        <<", and the min is: "<<min_s<<'\n';
    cout<<"The mode of the given seq is: "<<mode
        <<", and occurs "<<max<<" times"<<'\n';

    return 0;
}
#include "std_lib_facilities.h"

vector<int>& sizes(const vector<string>& v)
{
    static vector<int> res;
    res.clear();
    
    for (const auto& s : v) {
        res.push_back(int(s.size()));
    }
    return res;
}

void super(const vector<string>& v, string& longest, string& shortest)
{
    size_t lo = 0;
    size_t sh = UINT_MAX;

    for (const auto& s : v) {
        size_t size = s.size();

        if (size>lo) {
            lo = size;
            longest = s;
        }
        if (size<sh) {
            sh = size;
            shortest = s;
        }
    }

}

void order(vector<string>& v, string& first, string& last)
{
    sort(v.begin(), v.end());
    first = v[0];
    last = v[v.size()-1];
}

int main()
{
    vector<string> v{"Hello","C++","type","quit","to","quit","immediately"};
    vector<int>& iv = sizes(v);

    for (const auto& i : iv) {
        cout<<i<<' ';
    }
    cout<<'\n';

    string longest;
    string shortest;
    super(v, longest, shortest);
    cout<<"longest="<<longest<<", shortest="<<shortest<<'\n';

    string first;
    string last;
    order(v, first, last);
    cout<<"first="<<first<<", last="<<last<<'\n';

    return 0;
}
#include "std_lib_facilities.h"

void print(const string& label, const vector<int>& v);

int main()
{
    vector<int> v = {1,2,3,4,5};
    print("elements", v);

    return 0;
}

void print(const string& label, const vector<int>& v)
{
    cout<<label<<": ";

    for (const auto& i : v) {
        cout<<i<<' ';
    }
    cout<<'\n';
}

#include "std_lib_facilities.h"

void fibonacci(int x, int y, vector<int>& v, int n);
void print(const string& label, const vector<int>& v);

int main()
{
    while (cin) {
        try {
            int x;
            int y;
            int n;
            cin>>x>>y>>n;
            vector<int> v;
            fibonacci(x, y, v, n);
            print("fibonacci series", v);
        }
        catch (const std::exception& e) {
            cout<<e.what()<<'\n';
            return 1;
        }
    }

    return 0;
}

void fibonacci(int x, int y, vector<int>& v, int n)
{
    if (n<2) {
        error("at least 2 elements expected");
    }
    v.clear();      // make sure v is empty
    v.push_back(x);
    v.push_back(y);

    while (n-2 > 0) {
        int z = x+y;
        x = y;
        y = z;
        v.push_back(z);
        --n;
    }
}

void print(const string& label, const vector<int>& v)
{
    cout<<label<<": ";

    for (const auto& i : v) {
        cout<<i<<' ';
    }
    cout<<'\n';
}

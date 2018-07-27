#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

vector<int> gv{1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024};

//------------------------------------------------------------------------------

void print_vector(vector<int> v)
{
    for (int i = 0; i<v.size(); ++i)
        cout<<v[i]<<' ';
    cout<<'\n';
}

//------------------------------------------------------------------------------

void f(vector<int> v)
{
    vector<int> lv(v.size());
    lv = gv;
    print_vector(lv);

    vector<int> lv2{v};
    print_vector(lv2);
}

//------------------------------------------------------------------------------

int fact(int x)
{
    int res = 1;
    while (x) {
        res *= x;
        --x;
    }
    return res;
}

//------------------------------------------------------------------------------

int main()
{
    f(gv);

    vector<int> vv(10);
    for (int i = 0; i<10; ++i)
        vv[i] = fact(i+1);

    f(vv);
}

//------------------------------------------------------------------------------

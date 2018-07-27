#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

void print_array(ostream& os, int* a, int n);

//------------------------------------------------------------------------------

int main()
{
    int i1 = 7;
    int* p1 = &i1;
    cout<<"p1="<<p1<<" i1="<<*p1<<'\n';

    int* a7 = new int[7];
    for (int i = 0; i<7; ++i)
        a7[i] = pow(2, i);
    int* p2 = a7;
    cout<<"p2="<<p2<<'\n';
    print_array(cout, a7, 7);

    int* p3 = p2;
    p2 = p1;
    p2 = p3;
    cout<<"p1="<<p1<<" *p1="<<*p1<<'\n'
        <<"p2="<<p2<<" *p2="<<*p2<<'\n';

    delete[] a7;

    int* a10 = new int[10];
    for (int i = 0; i<10; ++i)
        a10[i] = pow(2, i);
    p1 = a10;

    vector<int> v10(10);
    for (int i = 0; i<10; ++i)
        v10[i] = pow(2, i);
    p1 = &v10[0];

    int* b10 = new int[10];
    p2 = b10;

    vector<int> u10(10);
    p2 = &u10[0];

    copy(p1, p1+10, p2);
    u10 = v10;

    print_array(cout, p2, 10);

    delete[] a10;
    delete[] b10;
}

//------------------------------------------------------------------------------

void print_array(ostream& os, int* a, int n)
{
    for (int i = 0; i<n; ++i)
        os<<"a["<<i<<"]="<<a[i]<<' ';
    os<<'\n';
}

//------------------------------------------------------------------------------

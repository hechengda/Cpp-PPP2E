#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

void print_array10(ostream& os, int* a);
void print_array(ostream& os, int* a, int n);
void print_vector(ostream& os, const vector<int>& v);

//------------------------------------------------------------------------------

int main()
{
    int* a = new int[10];
    for (int i = 0; i<10; ++i)
        cout<<"a["<<i<<"]="<<a[i]<<' ';
    cout<<'\n';
    delete[] a;

    int* a10 = new int[10];
    for (int i = 0; i<10; ++i)
        a10[i] = 100+i;
    print_array10(cout, a10);
    delete[] a10;

    vector<int> v10(10);
    for (int i = 0; i<10; ++i)
        v10[i] = 100+i;
    print_vector(cout, v10);

    int* a11 = new int[11];
    for (int i = 0; i<11; ++i)
        a11[i] = 100+i;
    for (int i = 0; i<11; ++i)
        cout<<"a["<<i<<"]="<<a11[i]<<' ';
    cout<<'\n';
    delete[] a11;

    vector<int> v11(11);
    for (int i = 0; i<11; ++i)
        v11[i] = 100+i;
    print_vector(cout, v11);

    int* a20 = new int[20];
    for (int i = 0; i<20; ++i)
        a20[i] = 100+i;
    print_array(cout, a20, 20);
    delete[] a20;

    vector<int> v20(20);
    for (int i = 0; i<20; ++i)
        v20[i] = 100+i;
    print_vector(cout, v20);
}

//------------------------------------------------------------------------------

void print_array10(ostream& os, int* a)
{
    for (int i = 0; i<10; ++i)
        os<<"a["<<i<<"]="<<a[i]<<' ';
    os<<'\n';
}

//------------------------------------------------------------------------------

void print_array(ostream& os, int* a, int n)
{
    for (int i = 0; i<n; ++i)
        os<<"a["<<i<<"]="<<a[i]<<' ';
    os<<'\n';
}

//------------------------------------------------------------------------------

void print_vector(ostream& os, const vector<int>& v)
{
    for (int i = 0; i<v.size(); ++i)
        os<<"v["<<i<<"]="<<v[i]<<' ';
    os<<'\n';
}

//------------------------------------------------------------------------------

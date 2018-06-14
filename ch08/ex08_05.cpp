#include "std_lib_facilities.h"

void reverse(const vector<int>& v1, vector<int>& v2);
void reverse(vector<int>& v);
void swap(int& a, int& b);
void print(const string& label, const vector<int>& v);

int main()
{
    vector<int> v1{1,3,5,7};
    vector<int> v2;
    reverse(v1, v2);
    print("v1", v1);
    print("v2", v2);

    reverse(v1);
    print("v1", v1);

    return 0;
}

void reverse(const vector<int>& v1, vector<int>& v2)
{
    for (size_t i = 0; i<v1.size(); ++i) {
        v2.push_back(v1[v1.size()-1-i]);
    }
}

void reverse(vector<int>& v)
{
    for (size_t i = 0; i<v.size()/2; ++i) {
        swap(v[i], v[v.size()-1-i]);
    }
}

void swap(int & a, int & b)
{
    int temp = a;
    a = b;
    b = temp;
}

void print(const string& label, const vector<int>& v)
{
    cout<<label<<": ";

    for (const auto& i : v) {
        cout<<i<<' ';
    }
    cout<<'\n';
}
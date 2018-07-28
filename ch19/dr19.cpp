#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

template<typename T>
struct S {
    S() : val{T()} { }
    S(T value) : val{value} { }

    T& get();
    T get() const;
    T& operator=(const T& new_val);

private:
    T val;
};

//------------------------------------------------------------------------------

template<typename T>
void read_val(T& v);

template<typename T>
istream& operator>>(istream& is, vector<T>& v);

template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v);

//------------------------------------------------------------------------------

int main()
try {
    S<int> is;
    read_val(is.get());

    S<char> cs;
    read_val(cs.get());

    S<double> ds;
    read_val(ds.get());

    S<string> ss;
    read_val(ss.get());

    S<vector<int>> vis;
    read_val(vis.get());

    cout<<is.get()<<'\n'
        <<cs.get()<<'\n'
        <<ds.get()<<'\n'
        <<ss.get()<<'\n';
    cout<<vis.get()<<'\n';

    return 0;
}
catch (const std::exception& e) {
    cerr<<e.what()<<'\n';
    return 1;
}

//------------------------------------------------------------------------------

template<typename T>
T& S<T>::get()
{
    return val;
}

//------------------------------------------------------------------------------

template<typename T>
T S<T>::get() const
{
    return val;
}

//------------------------------------------------------------------------------

template<typename T>
T& S<T>::operator=(const T& new_val)
{
    val = new_val;
}

//------------------------------------------------------------------------------

template<typename T>
void read_val(T& v)
{
    cin>>v;
}

//------------------------------------------------------------------------------

template<typename T>
istream& operator>>(istream& is, vector<T>& v)
{
    int val;
    char c1, c2;
    cin>>c1;
    if (c1!='{') error("'{' expected");
    while (cin>>val>>c2) {
        v.push_back(val);
        if (c2=='}') break;
        if (c2!=',') error("',' expected");
    }
    if (!cin) error("int expected");
    return is;
}

//------------------------------------------------------------------------------

template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v)
{
    os<<"{ ";
    for (const auto& t : v) {
        os<<t;
        if (t!=v[v.size()-1]) os<<", ";
    }
    os<<" }";
    return os;
}

//------------------------------------------------------------------------------

#include "std_lib_facilities.h"

string plural(int n)
{
    return (n==1) ? " " : "s ";
}

int main()
try {
    vector<int> v;

    for (char c; cin>>c;) {
        if (c=='|') {
            break;
        }
        if (c<'0' || c>'9') {
            error("0 to 9 expected\n");
        }
        v.push_back(c-'0');
    }
    switch (v.size()) {
    case 4:
        cout<<v[0]<<" thousand"+plural(v[0])<<"and "
            <<v[1]<<" hundred"+plural(v[1])<<"and "
            <<v[2]<<" ten"+plural(v[2])<<"and "
            <<v[3]<<" one"+plural(v[3])
            <<'\n';
        break;
    case 3:
        cout<<v[0]<<" hundred"+plural(v[0])<<"and "
            <<v[1]<<" ten"+plural(v[1])<<"and "
            <<v[2]<<" one"+plural(v[2])
            <<'\n';
        break;
    case 2:
        cout<<v[0]<<" ten"+plural(v[0])<<"and "
            <<v[1]<<" one"+plural(v[1])
            <<'\n';
        break;
    case 1:
        cout<<v[0]<<" one"+plural(v[0])
            <<'\n';
        break;
    default:
        error("at most four digits expected\n");
    }
    return 0;
}
catch (const runtime_error& e) {
    cerr<<e.what()<<'\n';
    return 1;
}
catch (...) {
    cerr<<"oops\n";
    return 2;
}
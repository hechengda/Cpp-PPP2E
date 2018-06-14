#include "std_lib_facilities.h"

void print_until_s(const vector<string>& v, string quit)
{
    for (const auto& s : v) {
        if (s==quit) {
            return;
        }
        cout<<s<<'\n';
    }
}

void print_until_ss(const vector<string>& v, string quit)
{
    int count = 0;      // "quit" count

    for (const auto& s : v) {
        if (s==quit) {
            ++count;
        }
        if (count==2) {
            return;
        }
        cout<<s<<'\n';
    }
}

int main()
{
    vector<string> v{"Hello","C++","type","quit","to","quit","immediately"};
    print_until_s(v, "quit");
    print_until_ss(v, "quit");

    return 0;
}
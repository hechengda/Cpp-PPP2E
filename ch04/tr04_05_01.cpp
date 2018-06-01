#include "std_lib_facilities.h"

int square(int x)   // definition of square
{
    int val = 0;

    for (int i = 0; i!=x; ++i) {
        val += x;
    }
    return val;
}

int main()
{
    cout<<square(2)<<'\n';  // print 4
    cout<<square(10)<<'\n'; // print 100

    return 0;
}
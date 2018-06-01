// calculate and print a table of squares 0¨C99

#include "std_lib_facilities.h"

int main()
{
    int i = 0;  // start from 0

    while (i != 100) {
        cout<<i<<'\t'<<pow(i, 2)<<'\n';
        ++i;
    }

    return 0;
}
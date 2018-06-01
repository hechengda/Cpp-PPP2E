#include "std_lib_facilities.h"

int main()
{
    char c = 'a';  // start from 'a'

    while (c!='z'+1) {
        cout<<c<<'\t'<<int(c)<<'\n';
        ++c;
    }

    return 0;
}
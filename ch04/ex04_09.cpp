#include "std_lib_facilities.h"

int main()
{
    cout<<static_cast<int>(log2(INT_MAX)+1)<<" is the largest number of squares for which you can"
        <<" calculate the exact number of grains (using an int)\n";
    cout<<static_cast<int>(log2(DBL_MAX)+1)<<" is the largest number of squares for which you can"
        <<" calculate the exact number of grains (using a double)\n";

    return 0;
}
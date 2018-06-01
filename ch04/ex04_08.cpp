#include "std_lib_facilities.h"

int main()
{
    constexpr int square_num = 64;
    vector<long long> grains_num = { 1000, 1000000, 1000000000 };

    for (long long g : grains_num) {
        cout<<int(log2(g))+1<<" squares are required to give the inventor at least "<<g<<" grains of rice\n";
    }

    return 0;
}
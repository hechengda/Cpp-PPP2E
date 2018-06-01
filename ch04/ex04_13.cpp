#include "std_lib_facilities.h"

int main()
{
    constexpr int begin = 2;    // it requires starting from 2
    constexpr int end = 100;
    vector<int> bv;

    for (int i = 0; i<=end; ++i) {
        bv.push_back(1); // initially all set to true
    }
    for (int i = begin; i<=sqrt(end); ++i) {  // not exceeding ¡Ìn
        if (bv[i]) {
            for (int j = i*i; j<=end; j += i) {   // not exceeding n
                bv[j] = 0;
            }
        }
    }
    cout << "Primes: ";

    for (int i = begin; i<=end; ++i) {
        if (bv[i]) {
            cout<<i<<' ';
        }
    }
    cout<<'\n';

    return 0;
}
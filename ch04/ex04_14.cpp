#include "std_lib_facilities.h"

int main()
{
    cout<<"Please input an integer: ";

    for (int val = 0; cin>>val;) {
        constexpr int begin = 2;
        const int end = val;
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
        cout<<"Please try again: ";
    }

    return 0;
}
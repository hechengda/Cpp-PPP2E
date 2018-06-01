#include "std_lib_facilities.h"

vector<int> prime;

bool is_prime(int n)
{
    if (n<=1) {
        return false;
    }
    if (n<=3) {
        return true;
    }
    for (int i = 0; prime[i]<=sqrt(n); ++i) {
        if (n%prime[i]==0) {    // no remainder: prime[p] divided
            return false;
        }
    }
    return true;    // no smaller prime could divide
}

int main()
{
    cout<<"Please input an integer: ";
    constexpr int begin = 0;
    constexpr int end = INT_MAX;

    for (int val = 0; cin>>val;) {
        cout << "Primes: ";
        int count = 0;  // the # of prime

        for (int i = begin; i<=end; ++i) {  // test all integers [begin:end]
            if (is_prime(i)) {
                prime.push_back(i); // add new prime to vector
                cout<<i<<' ';
                
                if (val==++count) {
                    break;
                }
            }
        }
        cout<<'\n';
        cout << "Please try again: ";
    }

    return 0;
}
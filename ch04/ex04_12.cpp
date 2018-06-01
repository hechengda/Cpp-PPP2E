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

    for (int val = 0; cin>>val;) {
        constexpr int begin = 1;
        const int end = val;
        cout << "Primes: ";

        for (int i = begin; i<=end; ++i) {  // test all integers [begin:end]
            if (is_prime(i)) {
                prime.push_back(i); // add new prime to vector
                cout<<i<<' ';
            }
        }
        cout<<'\n';
        cout << "Please try again: ";
    }

    return 0;
}
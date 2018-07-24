// Chapter 4 Exercise 12

#include "std_lib_facilities.h"	

vector<int> prime;

bool is_prime(int n)
{
    for (int p = 0; prime[p]<=sqrt(n); ++p)
        if (n%prime[p]==0) return false;	// no remainder: prime[p] divided
    return true;	// no smaller prime could divide
}

int main()
try {
    cout<<"Enter max: ";
    int max;
    cin>>max;
    if (!cin) error("bad input");
    if (max<2) error("2+ expected");

    prime.push_back(2);	// consider the smallest prime

    for (int i = 3; i<=max; ++i)	// test all integers [3:max]
        if (is_prime(i)) prime.push_back(i);	// add new prime to vector

    cout << "Primes: ";
    for (int p = 0; p<prime.size(); ++p)
        cout << prime[p] << '\n';
    return 0;
}
catch (runtime_error e) {	// this code is to produce error messages; it will be described in Chapter 5
    cout << e.what() << '\n';
    return 1;
}
catch (...) {	// this code is to produce error messages; it will be described in Chapter 5
    cout << "exiting\n";
    return 2;
}

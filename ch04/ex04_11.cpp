// Bjarne Stroustrup 7/20/2009
// Chapter 4 Exercise 11

#include "std_lib_facilities.h"

/*
Compute prime numbers: 2 3 5 7 11 ...

In case you forgot, a prime is a positive integer that can be divided only by 1 and by itself.
For this exercise, we decided to consider 2 the first prime (ignoring 1).

Our general strategy (our algorithm) is to see if a number can be divided by a prime smaller
than itself and if not it is itself a prime and we add it to our vector of primes.

I didn't bother with a separate vector of primes to compare with. Instead, I simply checked
that the primes computed were the correct.
*/

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
    constexpr int begin = 1;
    constexpr int end = 100;

    for (int i = begin; i<=end; ++i) {  // test all integers [1:100]
        if (is_prime(i)) {
            prime.push_back(i); // add new prime to vector
        }
    }
    cout << "Primes: ";

    for (auto p : prime) {
        cout<<p<<" ";
    }
    cout<<'\n';

    return 0;
}

/*
Look at the algorithm. Can you see a way of checking against fewer primes?
*/
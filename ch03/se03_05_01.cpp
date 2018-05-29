// detect repeated words

#include "std_lib_facilities.h"

int main()
{
    string prev;    // previous word
    string curr;    // current word
    while (cin>>curr) { // read a stream of words
        if (curr == prev) { // check if the word is the same as last
            cout<<"repeated word: "<<curr<<"\n";
        }
        prev = curr;
    }
    return 0;
}
// detect repeated words

#include "std_lib_facilities.h"

int main()
{
    int number_of_words = 0;
    string prev;    // previous word
    string curr;    // current word
    while (cin>>curr) { // read a stream of words
        ++number_of_words;  // increase word count
        if (curr==prev) { // check if the word is the same as last
            cout<<"word number "<<number_of_words
                <<"repeated: "<<curr<<"\n";
        }
        prev = curr;
    }
    return 0;
}
// simple dictionary: list of sorted words

#include "std_lib_facilities.h"

int main()
{
    vector<string> words;

    for (string temp; cin>>temp;) { // read whitespace-separated words
        words.push_back(temp);  // put temp into vector
    }
    cout<<"Number of words: "<<words.size()<<'\n';
    sort(words);    // sort words

    for (int i = 0; i!=words.size(); ++i) {
        if (i==0 || words[i]!=words[i-1]) { // is this a new word?
            cout<<words[i]<<'\n';
        }
    }

    return 0;
}
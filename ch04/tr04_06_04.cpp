#include "std_lib_facilities.h"

int main()
{
    vector<string> disliked = { "Broccoli" };

    for (string temp; cin>>temp;) { // read whitespace-separated words
        int i = 0;

        for (; i!=disliked.size(); ++i) {
            if (temp==disliked[i]) {    // search if there is a disliked word
                cout << "\a\n";
                break;
            }
        }
        if (i==disliked.size()) {   // no disliked words
            cout << temp << '\n';
        }
    }

    return 0;
}
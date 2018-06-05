#include "std_lib_facilities.h"

int main()
try {
    vector<char> ans{'a','h','o','u'};
    vector<char> guess;
    cout<<"Please guess four different chars in the range 'a' to 'z'(end with '|'): ";

    for (char ch; cin>>ch;) {
        if (ch=='|') {
            break;
        }
        if (ch<'a' || ch>'z') {
            error("char must be in the range 'a' to 'z'");
        }
        for (char g : guess) {
            if (g==ch) {
                error("duplicated char");
            }
        }
        guess.push_back(ch);
    }
    if (guess.size()!=4) {
        error("we need four chars");
    }
    int bull = 0;
    int cow = 0;

    for (size_t i = 0; i!=ans.size(); ++i) {
        for (size_t j = 0; j!=guess.size(); ++j) {
            if (ans[i]==guess[j]) { // found the target
                i==j ? ++bull : ++cow;
                break;  // break to start from outer loop
            }
        }
    }
    if (bull==4) {
        cout<<"Congratulations.\n";
    }
    else {
        cout<<"You got "<<bull<<" bulls, and "<<cow<<" cows.\n";
    }
    return 0;
}
catch (const runtime_error& e) {
    cerr<<e.what()<<'\n';
    return 1;
}
catch (...) {
    cerr<<"exceptions\n";
    return 2;
}

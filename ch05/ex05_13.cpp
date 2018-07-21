#include "std_lib_facilities.h"

int main()
try {
    cout<<"Please enter a number (any number): ";
    int seed = 1;
    cin>>seed;
    srand(seed);   // init the seed
    vector<int> ans;

    while (true) {
        int r = rand()%10;  // give the range 0 to 9
        int i = 0;

        for (; i!=ans.size(); ++i) {
            if (r==ans[i]) {    // check if there's duplicate int
                break;
            }
        }
        if (i==ans.size()) {    // no duplicate
            ans.push_back(r);   // add to vector
            //cout<<r<<'\n';
        }
        if (ans.size()==4) {    // we need four ints
            break;  // break the outer loop
        }
    }
    cout<<"Please guess four different integers in the range 0 to 9: ";
    vector<int> guess;

    for (int val; cin>>val;) {
        //cout<<val<<'\n';
        if (val<0 || val>9) {
            error("integer must be in the range 0 to 9");
        }
        for (auto g : guess) {
            if (g==val) {
                error("duplicated integer");
            }
        }
        guess.push_back(val);

        if (guess.size()==4) {
            int bull = 0;
            int cow = 0;

            for (size_t i = 0; i!=ans.size(); ++i) {
                for (size_t j = 0; j!=guess.size(); ++j) {
                    if (ans[i]==guess[j]) { // found the target
                        i==j ? ++bull : ++cow;
                        break;  // break to start from outer for loop
                    }
                }
            }
            if (bull==4) {
                cout<<"Congratulations. Game's over.\n";
                break;
            }
            else {
                cout<<"You got "<<bull<<" bulls, and "<<cow<<" cows.\n";
                cout<<"Please try again: ";
            }
            guess.clear();
        }
    }
    cout<<"exit because of bad input\n";
    return 0;
}
catch (const runtime_error& e) {
    cout<<e.what()<<'\n';
    return 1;
}

#include "std_lib_facilities.h"

int main()
{
    try {
        vector<int> ans{ 0,9,8,7 };
        vector<int> guess;
        cout<<"Please guess four different integers in the range 0 to 9(end with '|'): ";

        for (int val; cin>>val;) {
            if (val<0 || val>9) {
                error("integer must be in the range 0 to 9");
            }
            for (int g : guess) {
                if (g==val) {
                    error("duplicated integer");
                }
            }
            guess.push_back(val);
        }
        if (guess.size()!=4) {
            error("we need four integers");
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
        cout<<e.what()<<'\n';
        return 1;
    }
}
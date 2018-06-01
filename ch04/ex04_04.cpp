#include "std_lib_facilities.h"

int main()
{
    int lower = 1;  // lower boundary
    int upper = 100;    // upper boundary
    int count = 0;  // times to guess
    cout << "Please enter the number: ";
    int num;    // # to be guessed

    while (cin>>num) {
        // we don't consider "no input" case
        if (num<1 || num > 100) {
            cout<<"out of boundaries, repeat again?\n";
            continue;
        }
        break;  // valid input
    }
    int mean = (lower+upper)/2;

    while (lower<=upper) {
        ++count;    // increase the count
        cout<<"Is the number you are thinking of less than "<<mean<<"?\n";

        if (num==mean) {
            cout<<"Congratulations! You use "<<count<<" times.\n";
            break;  // don't forget to break the loop
        }
        else if (num<mean) {
            upper = mean-1;
        }
        else {
            lower = mean+1;
        }
        mean = (lower+upper)/2;
    }

    return 0;
}
#include "std_lib_facilities.h"

int main()
try {
    ifstream ist{"ex10_01.txt"};
    if (!ist) {
        error("can't open input file");
    }

    int sum = 0;
    for (int val; ist >> val;) {
        sum += val;
    }
    cout << "sum = " << sum << '\n';
    return 0;
}
catch (const std::exception& e) {
    cout << e.what() << '\n';
    return 1;
}
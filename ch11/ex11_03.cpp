#include "std_lib_facilities.h"

char disemvowels(char& c);

int main()
try {
    ifstream ifs{"ex11_03_in.txt"};
    if (!ifs) {
        error("can't open input file");
    }

    for (char c, lastc = '\0'; ifs.get(c);) {
        c = disemvowels(c);
        if (c=='\0') {
            continue;
        }
        if (c!=' ' || lastc!=' ') {
            cout << c;
        }
        lastc = c;
    }
    cout << '\n';
    return 0;
}
catch (const std::exception& e) {
    cout << e.what() << '\n';
    return 1;
}

char disemvowels(char& c)
{
    if (c=='a' || c=='A'
        || c=='e' || c=='E'
        || c=='i' || c=='I'
        || c=='o' || c=='O'
        || c=='u' || c=='U') {
        c = '\0';
    }
    return c;
}

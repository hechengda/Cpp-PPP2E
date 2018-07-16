#include "std_lib_facilities.h"

int main()
try {
    ifstream ifs{"ex11_01_in.txt"};
    if (!ifs) {
        error("can't open input file");
    }

    ofstream ofs{"ex11_01_out.txt"};
    if (!ofs) {
        error("can't open output file");
    }

    for (char c; ifs.get(c);) {
        c = tolower(c);
        ofs << c;
    }
    return 0;
}
catch (const std::exception& e) {
    cout << e.what() << '\n';
    return 1;
}
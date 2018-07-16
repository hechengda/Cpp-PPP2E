#include "std_lib_facilities.h"
#include <chrono>

int main()
try {
    int birth_year{1990};
    cout << showbase;
    cout << birth_year << "\tdecimal\n"
        << hex << birth_year << "\thexadecimal\n"
        << oct << birth_year << "\toctal\n";
    cout << dec << 2018 - birth_year << '\n';

    int a, b, c, d;
    cin >> a >> oct >> b >> hex >> c >> d;
    cout << a << '\t' << b << '\t' << c << '\t' << d << '\n';

    cout << 1234567.89 << "\t\n"
        << fixed << 1234567.89 << "\t\n"
        << scientific << 1234567.89 << '\n';

    cout << setw(5) << "He" << '\t'
        << setw(10) << "Chengda" << '\t'
        << setw(15) << "hechengda@gmail.com" << '\n';
    return 0;
}
catch (const std::exception& e) {
    cout << e.what() << '\n';
    return 1;
}

#include "std_lib_facilities.h"

struct Date
{
    int y;
    int m;
    int d;
};

void init_day(Date& dd, int y, int m, int d);
void add_day(Date& dd, int n);
ostream& operator<<(ostream& os, const Date& d);

int main()
try {
    Date today;
    init_day(today, 1978, 6, 25);
    cout << today << '\n';

    Date tomorrow{today};
    add_day(tomorrow, 1);
    cout << tomorrow << '\n';

    return 0;
}
catch (const std::exception& e) {
    cout << e.what() << '\n';
    return 1;
}

void init_day(Date& dd, int y, int m, int d)
{
    if (m<1 || m>12) {
        error("range 1 to 12 expected");
    }
    if (d<1 || d>31) {
        error("range 1 to 31 expected");
    }

    dd.y = y;
    dd.m = m;
    dd.d = d;
}

void add_day(Date& dd, int n)
{
    dd.d += n;
}

ostream& operator<<(ostream& os, const Date& d)
{
    return os << '(' << d.y << ',' << d.m << ',' << d.d << ')';
}

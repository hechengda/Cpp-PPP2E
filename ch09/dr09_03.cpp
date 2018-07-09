#include "std_lib_facilities.h"

class Date
{
public:
    Date(int y, int m, int d);
    void add_day(int n);
    int year() const { return y; }
    int month() const { return m; }
    int day() const { return d; }

private:
    int y;
    int m;
    int d;

    void init_day(int y, int m, int d);
};

ostream& operator<<(ostream& os, const Date& d);

int main()
try {
    Date today{1978, 6, 25};
    cout << today << '\n';

    Date tomorrow{today};
    tomorrow.add_day(1);
    cout << tomorrow << '\n';

    return 0;
}
catch (const std::exception& e) {
    cout << e.what() << '\n';
    return 1;
}

ostream& operator<<(ostream& os, const Date& d)
{
    return os << '(' << d.year() << ',' << d.month() << ',' << d.day() << ')';
}

// implementation of Date
Date::Date(int y, int m, int d)
{
    init_day(y, m, d);
}

void Date::add_day(int n)
{
    d += n;
}

void Date::init_day(int y, int m, int d)
{
    if (m<1 || m>12) {
        error("range 1 to 12 expected");
    }
    if (d<1 || d>31) {
        error("range 1 to 31 expected");
    }

    this->y = y;
    this->m = m;
    this->d = d;
}

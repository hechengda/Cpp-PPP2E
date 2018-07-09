#include "std_lib_facilities.h"

const int DEFAULT_YEAR = 1978;

class Year
{
public:
    Year() : y{DEFAULT_YEAR} {}
    Year(int x) : y{x} {}
    int year() const { return y; }

private:
    int y;
};

enum class Month
{
    jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

class Date
{
public:
    Date(Year y, Month m, int d);
    void add_day(int n);
    int year() const { return y.year(); }
    int month() const { return int(m); }
    int day() const { return d; }

private:
    Year y;
    Month m;
    int d;

    void init_day(Year y, Month m, int d);
};

ostream& operator<<(ostream& os, const Date& d);

int main()
try {
    Date today{Year{1978}, Month::jun, 25};
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
Date::Date(Year y, Month m, int d)
{
    init_day(y, m, d);
}

void Date::add_day(int n)
{
    d += n;
}

void Date::init_day(Year y, Month m, int d)
{
    if (int(m)<1 || int(m)>12) {
        error("range 1 to 12 expected");
    }
    if (d<1 || d>31) {
        error("range 1 to 31 expected");
    }

    this->y = y;
    this->m = m;
    this->d = d;
}

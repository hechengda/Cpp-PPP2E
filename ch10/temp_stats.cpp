#include "std_lib_facilities.h"

struct Reading      // a temperature reading
{
    int hour;       // hour after midnight [0:23]
    double temperature;     // in Fahrenheit
};

istream& operator>>(istream& is, Reading& r);

int main()
try {
    ifstream ist{"raw_temps.txt"};
    if (!ist) {
        error("can't open input file");
    }

    vector<Reading> temps;
    for (Reading r; ist >> r;) {
        if (r.hour<0 || r.hour>23) error("hour out of range");
        temps.push_back(Reading{r.hour, r.temperature});
    }

    double sum = 0.0;
    for (const auto& t : temps) {
        sum += t.temperature;
    }
    cout << "mean = " << (sum / temps.size())
         << ", median = " << (temps[temps.size() / 2].temperature) << '\n';
    return 0;
}
catch (const std::exception& e) {
    cout << e.what() << '\n';
    return 1;
}

istream & operator>>(istream & is, Reading & r)
{
    int hour;
    double temperature;
    char ch1, ch2, ch3;
    is >> ch1 >> hour >> ch2 >> temperature >> ch3;
    if (!is) {
        return is;
    }
    if (ch1 != '(' || ch2 != ',' || ch3 != ')') {        // oops: format error
        is.clear(ios_base::failbit);
        return is;
    }
    r = Reading{hour, temperature};                       // update r
    return is;
}

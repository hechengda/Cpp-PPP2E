#include "std_lib_facilities.h"

struct Reading      // a temperature reading
{
    int hour;       // hour after midnight [0:23]
    double temperature;     // in Fahrenheit
};

int main()
try {
    ofstream ost{"raw_temps.txt"};
    if (!ost) {
        error("can't open output file");
    }

    vector<Reading> temps;
    for (int n = 0; n < 50; ++n) {
        temps.push_back(Reading{n % 24, 60.0 + (rand() % 10) / 10.0});
    }

    for (const auto& t : temps) {
        ost << '(' << t.hour << ',' << t.temperature << ")\n";
    }
    return 0;
}
catch (const std::exception& e) {
    cout << e.what() << '\n';
    return 1;
}
#include "std_lib_facilities.h"

enum Day {
    inv, mon, tue, wed, thu, fri, sat, sun
};

Day day(string);        // convert string to int
int sum(const vector<int>&);        // sum of values in the vector

int main()
try {
    vector<vector<int>> val_of_day(7);      // 7 vectors of ints
    int reject = 0;

    while (cin) {
        string day_of_week;
        int val;
        cin>>day_of_week>>val;

        switch (day(day_of_week)) {
            case mon:
                val_of_day[0].push_back(val);
                break;
            case tue:
                val_of_day[1].push_back(val);
                break;
            case wed:
                val_of_day[2].push_back(val);
                break;
            case thu:
                val_of_day[3].push_back(val);
                break;
            case fri:
                val_of_day[4].push_back(val);
                break;
            case sat:
                val_of_day[5].push_back(val);
                break;
            case sun:
                val_of_day[6].push_back(val);
                break;
            default:
                ++reject;
                break;
        }
    }

    // print the sum of values of each day
    for (size_t i = 0; i<val_of_day.size(); ++i)
        if (val_of_day[i].size())       // only output existing value
            cout<<"Sum of day "<<i+1<<" is "<<sum(val_of_day[i])<<'\n';

    if (reject) cout<<"The number of illegal days is "<<reject<<'\n';

    return 0;
}
catch (const std::exception& e) {
    cerr<<e.what()<<'\n';
    return 1;
}

Day day(string s)
{
    Day res = inv;
    if (s=="Monday" || s=="Mon" || s=="monday") {
        res = mon;
    }
    else if (s=="Tuesday" || s=="Tue" || s=="tuesday") {
        res = tue;
    }
    else if (s=="Wednesday" || s=="Wed" || s=="wednesday") {
        res = wed;
    }
    else if (s=="Thursday" || s=="Thu" || s=="thursday") {
        res = thu;
    }
    else if (s=="Friday" || s=="Fri" || s=="friday") {
        res = fri;
    }
    else if (s=="Saturday" || s=="Sat" || s=="saturday") {
        res = sat;
    }
    else if (s=="Sunday" || s=="Sun" || s=="sunday") {
        res = sun;
    }
    return res;
}

int sum(const vector<int>& v)
{
    int sum = 0;
    for (auto val : v) sum += val;
    return sum;
}

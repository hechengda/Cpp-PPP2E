#include "std_lib_facilities.h"

// compute mean and median temperatures
int main()
{
    vector<double> temps;        // temperatures
    double temp;
    while (cin>>temp)            // read 
        temps.push_back(temp);   // put into vector

    // compute mean temperature:
    double sum = 0;
    auto size = temps.size();
    for (int i = 0; i<size; ++i) sum += temps[i];
    cout<<"Average temperature: "<<sum/size<<endl;

    // compute median temperature:
    sort(temps.begin(), temps.end()); // sort temps
                                      // "from the beginning to the end."
    double median = size%2 ? temps[size/2]
        : (temps[size/2-1] + temps[size/2]) / 2.0;
    cout<<"Median temperature: "<<median<<endl;
    return 0;
}

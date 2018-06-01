// compute mean and median temperatures

#include "std_lib_facilities.h"

int main()
{
    vector<double> temps;   // temperatures

    for (double temp; cin>>temp;) { // read into temp
        temps.push_back(temp);  // put temp into vector
    }

    // compute mean temperature:
    double sum = 0.0;

    for (double t : temps) {
        sum += t;
    }
    cout<<"Average temperature: "<<sum/temps.size()<<'\n';

    // compute median temperature:
    sort(temps);    // sort temperatures
    cout<<"Median temperature: "<<temps[temps.size()/2]<<'\n';

    return 0;
}
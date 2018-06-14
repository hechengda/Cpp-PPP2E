#include "std_lib_facilities.h"

struct Result
{
    double smallest;
    double greatest;
    double mean;
    double median;

    void print()
    {
        cout<<"("<<smallest<<","<<greatest<<","<<mean<<","<<median<<")\n";
    }
};

Result find(const vector<double>& v);
void find(const vector<double>& v, double& smallest, double& greatest, double& mean, double& median);

int main()
{
    vector<double> v{1.0,2.0,3.0,4.0,5.0};
    Result r = find(v);
    r.print();

    double smallest = DBL_MAX;
    double greatest = DBL_MIN;
    double mean = 0.0;
    double median = 0.0;
    find(v, smallest, greatest, mean, median);
    cout<<"("<<smallest<<","<<greatest<<","<<mean<<","<<median<<")\n";

    return 0;
}

Result find(const vector<double>& v)
{
    if (v.empty()) {
        error("empty vector");
    }
    Result r;
    double sum = 0.0;
    double smallest = DBL_MAX;
    double greatest = DBL_MIN;

    for (size_t i = 0; i<v.size(); ++i) {
        if (v[i]<smallest) {
            smallest = v[i];
        }
        if (v[i]>greatest) {
            greatest = v[i];
        }
        sum += v[i];
    }
    r.smallest = smallest;
    r.greatest = greatest;
    r.mean = sum/v.size();
    r.median = v[v.size()/2];
    return r;
}

void find(const vector<double>& v, double& smallest, double& greatest, double& mean, double& median)
{
    if (v.empty()) {
        error("empty vector");
    }
    double sum = 0.0;

    for (size_t i = 0; i<v.size(); ++i) {
        if (v[i]<smallest) {
            smallest = v[i];
        }
        if (v[i]>greatest) {
            greatest = v[i];
        }
        sum += v[i];
    }
    mean = sum/v.size();
    median = v[v.size()/2];
}

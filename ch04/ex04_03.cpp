// Bjarne Stroustrup 7/20/2009
// Chapter 4 Exercise 3

#include "std_lib_facilities.h"

/*
Immediately, we are faced with the question "when do we stop reading in distance values?
My choice here is "whenever we find a 0 or a negative distance"

I decided to compute the sum of the distances, the smallest distance, and the largest distance
as we read along. I could have waited until every value had been read and then go through the
read values (now stored in the vector dist).
*/

vector<double> dist;
double sum = 0.0;   // accumulate total distance in sum
double smallest = DBL_MAX;  // smallest distance
double greatest = DBL_MIN;  // greatest distance

void print_dist()
{
    if (!dist.size()) {
        error("no distances");
    }
    cout<<"total distance "<<sum<< '\n';
    cout<<"smallest distance "<<smallest<<'\n';
    cout<<"greatest distance "<<greatest<<'\n';
    cout<<"mean distance "<<sum/dist.size()<<'\n';
}

int main()
try {
    cout << "please enter a whitespace-separated sequence of doubles (representing distances) : ";

    for (double val; cin>>val;) { // read distance
        if (val<=0) {
            print_dist();
            return 0;
        }
        dist.push_back(val);  // store the value

        // update the "running" values:
        sum += val;

        if (val<smallest) {
            smallest = val;
        }
        if (val>greatest) {
            greatest = val;
        }
    }
    print_dist();
    return 0;
}
catch (runtime_error e) {   // this code is to produce error messages; it will be described in Chapter 5
    cout<<e.what()<<'\n';
    return 1;
}
catch (...) {   // this code is to produce error messages; it will be described in Chapter 5
    cout<<"exiting\n";
    return 2;
}


/*
Note the test for "no distances entered". Forgetting the case of "no input" is a common error.

Why are the min and max correctly computed?

Is the mean correctly computed?

what reason might I have had for computing sum, max, and mean as we read along? Could the code
have been cleaner if I had postponed computation until after the last read?

Why did I repeat the output statements? Replicating code is tedious and error-prone. Can you see
a way of removing that replication?
*/
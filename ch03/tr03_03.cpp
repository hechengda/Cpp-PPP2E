// This is "Try" code from Chapter 3.3

#include "std_lib_facilities.h"

// Read name and age
int main()
{
    cout<<"please enter your first_name and age\n";
    string first_name;
    double age;
    cin>>first_name>>age;  // read a string followed by an integer
    cout<<"Hello, "<<first_name<<" (age "<<age*12<<")\n";
    return 0;
}

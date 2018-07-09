// Bjarne Stroustrup 3/26/2009
// Chapter 4 Exercise 7

#include "std_lib_facilities.h"

/*
the problem here is to handle numbers written out using letters as well as numbers written using digits, e.g.
2 + two
two + 2
two + five
2 + 5
The basic idea for a solution is to try to read integers (as in exercise 5)
and if that doesn't work (the input operation fails) try reading a string
and see if that string represents a number (e.g. "nine").

You will note that a space after a number expressed as a letter is essential:
two+ 3
will not work because the string read will also read the +

The solution uses two functions (in addition to main():
initialize_numbers() to initialize the vector of number string representations
get_number() to read a number that is either a string or a sequence of digits
*/

vector<string> numbers; // representation of numbers as strings

void initialize_numbers()
{
    numbers.push_back("zero");
    numbers.push_back("one");
    numbers.push_back("two");
    numbers.push_back("three");
    numbers.push_back("four");
    numbers.push_back("five");
    numbers.push_back("six");
    numbers.push_back("seven");
    numbers.push_back("eight");
    numbers.push_back("nine");
}

/*
An apology: To use cin again after a failed read, you need to use a function call "cin.clear();" to "clear" it.
That isn't explained in the book until chapter 10. Sorry.

Solutions that do not use this technique can get very complicated.
*/
int get_number()
{
    int val;

    if (cin>>val) { // try to read an integer
        return val;
    }
    cin.clear();    // clear string after failed attempt to read an integer
    string s;
    cin>>s;
    int i = 0;

    for (; i != numbers.size(); ++i) {  // see if the string is in numbers
        if (s==numbers[i]) {    // found the target
            val = i;
            break;
        }
    }
    if (i==numbers.size()) {    // not found
        error("unexpected number string: ", s);
    }
    return val;
}

int main()
{
    try {
        initialize_numbers();
        cout<< "please enter two floating-point values separated by an operator\nThe operator can be + - * or / : ";

        while (true) { // "forever"; that is until we give an unacceptable input or make a computations error
            int val1 = get_number();
            char op;
            cin>>op;    // get the operator
            int val2 = get_number();
            string oper;    // text appropriate for an operator
            double result;

            switch (op) {
            case '+':
                oper = "sum of ";
                result = val1+val2;
                break;
            case '-':
                oper = "difference between ";
                result = val1-val2;
                break;
            case '*':
                oper = "product of ";
                result = val1*val2;
                break;
            case '/':
                if (!val2) {
                    error("trying to divide by zero");
                }
                oper = "ratio of ";
                result = val1/val2;
                break;
            default:
                error("bad operator", op);
                break;
            }
            cout << oper << val1 << " and " << val2 << " is " << result << '\n';
            cout << "Try again: ";
        }
    }
    catch (runtime_error e) {   // this code is to produce error messages; it will be described in Chapter 5
        cout<<e.what()<<'\n';
    }
    catch (...) {   // this code is to produce error messages; it will be described in Chapter 5
        cout<<"exiting\n";
    }

    return 0;
}
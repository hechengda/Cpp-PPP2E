//
// This is example code from Chapter 6.6 "Trying the first version" of
// "Software - Principles and Practice using C++" by Bjarne Stroustrup
//

#include "std_lib_facilities.h"

using Token = pair<char, double>;
constexpr char digit = '0';

Token get_token();
double primary();
double term();
double expression();

int main()
{
    try {
        while (cin) {
            cout<<'='<<expression()<<'\n';
        }
        return 0;
    }
    catch (const runtime_error& e) {
        cerr<<e.what()<<'\n';
        return 1;
    }
    catch (...) {
        cerr<<"exception\n";
        return 2;
    }
}

// read a token from cin
Token get_token()
{
    char c;
    cin>>c; // note that >> skips whitespace (space, newline, tab, etc.)

    switch (c) {
    case '(': case ')': case '+': case '-': case '*': case '/':
        return Token(c, 0.0);   // let each character represent itself
    case '.':
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
    {
        cin.putback(c); // put digit back into the input stream
        double val;
        cin>>val;   // read a floating-point number
        return Token(digit, val);
    }
    default:
        error("Bad token");
    }
}

double primary()
{
    Token t = get_token();

    switch (t.first) {
    case '(':   // handle ¡®(¡® expression ¡®)¡¯
    {
        double d = expression();
        t = get_token();

        if (t.first!=')') {
            error("')' expected");
        }
        return d;
    }
    case digit:
        return t.second;    // return the number¡¯s value
    default:
        error("primary expected");
    }
}

double term()
{
    double left = primary();
    Token t = get_token();

    while (true) {
        switch (t.first) {
        case '*':
            left *= primary();
            t = get_token();
            break;
        case '/':
        {
            double d = primary();

            if (!d) {
                error("divide by zero");
            }
            left /= d;
            t = get_token();
            break;
        }
        default:
            return left;
        }
    }
}

double expression()
{
    double left = term(); // read and evaluate a Term
    Token t = get_token();  // get the next token

    while (true) {
        switch (t.first) {
        case '+':
            left += term(); // evaluate Term and add
            t = get_token();
            break;
        case '-':
            left -= term(); // evaluate Term and subtract
            t = get_token();
            break;
        default:
            return left;    // finally: no more + or ¨C; return the answer
        }
    }
}
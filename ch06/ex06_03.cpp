// Chapter 6 Excercise 2 & 3

#include "std_lib_facilities.h"

constexpr char digit = '0';
using Token = pair<char, double>;

class Token_stream
{
public:
    Token_stream(); // make a Token_stream that reads from cin
    ~Token_stream();
    Token get();    // get a Token
    void putback(Token t);  // put a Token back

private:
    bool full;  // is there a Token in the buffer?
    Token buff; // here is where we keep a Token put back using putback()
};

Token_stream ts;    // provides get() and putback()
double primary();   // deal with numbers and parentheses
double term();  // deal with * and /
double expression();    // deal with + and จC
int factorial(int); // deal with integers

int main()  // main loop and deal with errors
try {
    double val = 0.0;

    while (cin) {
        Token t = ts.get();

        if (t.first=='q') { // 'q' for "quit"
            break;
        }
        if (t.first==';') { // ';' for "print"
            cout<<'='<<val<<'\n';
        }
        else {
            ts.putback(t);
        }
        val = expression();
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

// implementation of Token_stream
Token_stream::Token_stream() :full(false)
{
}

Token_stream::~Token_stream()
{
}

Token Token_stream::get()
{
    if (full) {
        full = false;
        return buff;
    }
    char c;
    cin>>c; // note that >> skips whitespace (space, newline, tab, etc.)

    switch (c) {
    case ';':   // for "print"
    case 'q':   // for "quit"
    case '!':   // for "factorial"
    case '{': case '}': case '(': case ')':
    case '+': case '-': case '*': case '/':
        return Token{c,0.0};   // let each character represent itself
    case '.':
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
    {
        cin.putback(c); // put digit back into the input stream
        double val;
        cin>>val;   // read a floating-point number
        return Token{digit,val};
    }
    default:
        error("Bad token");
    }
}

void Token_stream::putback(Token t)
{
    if (full) {
        error("putback() into a full buffer");
    }
    buff = t;   // copy t to buffer
    full = true;    // buffer is now full
}

double primary()
{
    double d = 0.0;
    Token t = ts.get();

    switch (t.first) {
    case '{':   // handle กฎ{กฎ expression กฎ}กฏ
        d = expression();
        t = ts.get();
        if (t.first!='}') error("'}' expected");
        break;
    case '(':   // handle กฎ(กฎ expression กฎ)กฏ
        d = expression();
        t = ts.get();
        if (t.first!=')') error("'}' expected");
        break;
    case digit:
        d = t.second;
        break;
    default:
        error("primary expected");
    }

    // check if we have the case Primary "!" (a factorial)
    t = ts.get();
    if (t.first=='!') { // handle factorial '!'
        return factorial(int(d));
    }
    ts.putback(t);  // put t back into the token stream
    return d;
}

double term()
{
    double left = primary();
    Token t = ts.get();

    while (true) {
        switch (t.first) {
        case '*':
            left *= primary();
            t = ts.get();
            break;
        case '/':
        {
            double d = primary();

            if (!d) {
                error("divide by zero");
            }
            left /= d;
            t = ts.get();
            break;
        }
        default:
            ts.putback(t);  // put t back into the token stream
            return left;
        }
    }
}

double expression()
{
    double left = term(); // read and evaluate a Term
    Token t = ts.get();  // get the next token

    while (true) {
        switch (t.first) {
        case '+':
            left += term(); // evaluate Term and add
            t = ts.get();
            break;
        case '-':
            left -= term(); // evaluate Term and subtract
            t = ts.get();
            break;
        default:
            ts.putback(t);  // put t back into the token stream
            return left;    // finally: no more + or จC; return the answer
        }
    }
}

int factorial(int n)
{
    if (n<0) {
        error("nonnegative integers expected");
    }
    else if (!n) {
        return 1;
    }
    
    int prev = 1;
    int curr = 1;
    int i = 0;
    while (i<n) {
        curr = prev*++i;
        prev = curr;
    }
    return curr;
}
#include "std_lib_facilities.h"

constexpr char PROMPT = '>';
constexpr char DIGIT = '0';
constexpr char PRINT = ';';
constexpr char QUIT = 'q';

class Token
{
public:
    char kind;
    double value;

    Token(char k);
    Token(char k, double v);
};

class Token_stream
{
public:
    Token_stream();
    Token get();
    void putback(Token t);
    void ignore(char ch);

private:
    bool m_full;
    Token m_buffer;
};

Token_stream ts;
void calculate();
void clean_up_mess();
double expression();
double term();
double primary();

int main()
try {
    calculate();
    return 0;
}
catch (const exception& e) {
    cout<<e.what()<<'\n';
    return 1;
}

// implementation of Token
Token::Token(char k) : kind(k)
{
}

Token::Token(char k, double v) : kind(k), value(v)
{
}

// implementation of Token_stream
Token_stream::Token_stream() : m_full(false), m_buffer(0)
{
}

Token Token_stream::get()
{
    if (m_full) {
        m_full = false;
        return m_buffer;
    }
    char c;
    cin>>c;

    switch (c) {
    case PRINT:
    case QUIT:
    case '(': case ')':
    case '+': case '-': case '*': case '/': case '%':
        return Token(c);
    case '.':
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
    {
        cin.putback(c);
        double d;
        cin>>d;
        return Token(DIGIT, d);
    }
    default:
        error("bad token");
    }
}

void Token_stream::putback(Token t)
{
    if (m_full) {
        error("buffer is full");
    }
    m_full = true;
    m_buffer = t;
}

void Token_stream::ignore(char ch)
{
    if (m_full) {
        m_full = false;

        if (ch==m_buffer.kind) {
            return;
        }
    }
    char c = 0;

    while (cin>>c) {
        if (ch==c) {
            return;
        }
    }
}

void calculate()
{
    while (cin)
    try {
        cout<<PROMPT;
        Token t = ts.get();

        while (t.kind==PRINT) {
            t = ts.get();
        }
        if (t.kind==QUIT) {
            return;
        }
        ts.putback(t);
        cout<<'='<<expression()<<'\n';
    }
    catch (const exception& e) {
        cout<<e.what()<<'\n';
        clean_up_mess();
    }
}

void clean_up_mess()
{
    ts.ignore(PRINT);
}

// implementation of Grammar
double expression()
{
    double lval = term();

    while (true) {
        Token t = ts.get();

        switch (t.kind) {
        case '+':
            lval += term();
            break;
        case '-':
            lval -= term();
            break;
        default:
            ts.putback(t);
            return lval;
        }
    }
}

double term()
{
    double lval = primary();

    while (true) {
        Token t = ts.get();

        switch (t.kind) {
        case '*':
            lval *= primary();
            break;
        case '/':
        {
            double rval = primary();
            if (!rval) {
                error("divisor is zero");
            }
            lval /= rval;
            break;
        }
        case '%':
        {
            double rval = primary();
            if (!rval) {
                error("divisor is zero");
            }
            lval = fmod(lval, rval);
            break;
        }
        default:
            ts.putback(t);
            return lval;
        }
    }
}

double primary()
{
    Token t = ts.get();

    switch (t.kind) {
    case '(':
    {
        double val = expression();
        t = ts.get();

        if (t.kind!=')') {
            error("')' expected");
        }
        return val;
    }
    case '+':
        return primary();
    case '-':
        return -primary();
    case DIGIT:
        return t.value;
    default:
        error("primary expected");
    }
}

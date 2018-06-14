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
    Token_stream(istream& is);
    Token get();
    void putback(Token t);
    void ignore(char ch);

private:
    bool m_full;
    Token m_buffer;
    istream& m_input;
};

void calculate(Token_stream& ts);
void clean_up_mess(Token_stream& ts);
double expression(Token_stream& ts);
double term(Token_stream& ts);
double primary(Token_stream& ts);

int main()
try {
    Token_stream ts;    // use std::cin by default

    calculate(ts);
    return 0;
}
catch (const exception& e) {
    cout<<e.what()<<'\n';
    return 1;
}

void calculate(Token_stream& ts)
{
    while (true)
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
        cout<<'='<<expression(ts)<<'\n';
    }
    catch (const exception& e) {
        cout<<e.what()<<'\n';
        clean_up_mess(ts);
    }
}

void clean_up_mess(Token_stream& ts)
{
    ts.ignore(PRINT);
}

// implementation of Grammar
double expression(Token_stream& ts)
{
    double lval = term(ts);

    while (true) {
        Token t = ts.get();

        switch (t.kind) {
        case '+':
            lval += term(ts);
            break;
        case '-':
            lval -= term(ts);
            break;
        default:
            ts.putback(t);
            return lval;
        }
    }
}

double term(Token_stream& ts)
{
    double lval = primary(ts);

    while (true) {
        Token t = ts.get();

        switch (t.kind) {
        case '*':
            lval *= primary(ts);
            break;
        case '/':
        {
            double rval = primary(ts);
            if (!rval) {
                error("divisor is zero");
            }
            lval /= rval;
            break;
        }
        case '%':
        {
            double rval = primary(ts);
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

double primary(Token_stream& ts)
{
    Token t = ts.get();

    switch (t.kind) {
    case '(':
    {
        double val = expression(ts);
        t = ts.get();

        if (t.kind!=')') {
            error("')' expected");
        }
        return val;
    }
    case '+':
        return primary(ts);
    case '-':
        return -primary(ts);
    case DIGIT:
        return t.value;
    default:
        error("primary expected");
    }
}

// implementation of Token
Token::Token(char k) : kind(k)
{
}

Token::Token(char k, double v) : kind(k), value(v)
{
}

// implementation of Token_stream
Token_stream::Token_stream() : m_full(false), m_buffer(0), m_input(cin)
{
}

Token_stream::Token_stream(istream& input) : m_full(false), m_buffer(0), m_input(input)
{
}

Token Token_stream::get()
{
    if (m_full) {
        m_full = false;
        return m_buffer;
    }
    char c;
    m_input>>c;

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
        m_input.putback(c);
        double d;
        m_input>>d;
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

    while (m_input>>c) {
        if (ch==c) {
            return;
        }
    }
}

#include "std_lib_facilities.h"

constexpr char PROMPT = '>';
constexpr char DIGIT = '0';
constexpr char PRINT = ';';
constexpr char QUIT = 'q';
constexpr char HELP = 'h';
constexpr char LET = 'l';
constexpr char CONST = 'c';
constexpr char VARIABLE = 'v';
constexpr char EQUAL = '=';
const string DECL_KEY = "let";
const string CONST_KEY = "const";

class Token
{
public:
    char kind;
    double value;
    string name;

    Token(char k);
    Token(char k, double v);
    Token(char k, string s);
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

class Variable
{
public:
    string name;
    double value;

    Variable(string s, double d, bool b = false);    // ex03
    bool is_const();

private:
    bool m_const;
};

class Symbol_table      // ex04
{
public:
    Symbol_table();

    double get_value(string s);
    void set_value(string s, double d);
    bool is_declared(string s);
    double define_name(string s, double d, bool is_const = false);

private:
    vector<Variable> m_table;
};

Token_stream ts;
Symbol_table st;
void calculate();
void clean_up_mess();
double statement();
double declaration(bool is_const = false);
double expression();
double term();
double primary();

int main()
try {
    st.define_name("pi", 3.1415926535, true);
    st.define_name("e", 2.7182818284, true);

    calculate();
    return 0;
}
catch (const exception& e) {
    cout<<e.what()<<'\n';
    return 1;
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
        if (t.kind==HELP) {
            cout<<"----HELP INFORMATION----"<<'\n';
            continue;
        }
        ts.putback(t);
        cout<<'='<<statement()<<'\n';
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
double statement()
{
    Token t = ts.get();

    switch (t.kind) {
    case LET:
        return declaration();
    case CONST:
        return declaration(true);
    default:
        ts.putback(t);
        return expression();
    }
}

double declaration(bool is_const)
{
    Token t = ts.get();

    if (t.kind!=VARIABLE) {
        error("name expected in declaration");
    }
    string var_name = t.name;
    t = ts.get();

    if (t.kind!=EQUAL) {
        error("= missing in declaration of ", var_name);
    }
    double val = expression();
    st.define_name(var_name, val, is_const);
    return val;
}

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
    case VARIABLE:
    {
        string var_name = t.name;
        double val = st.get_value(var_name);
        t = ts.get();

        if (t.kind==EQUAL) {    // ex02
            val = expression();
            st.set_value(var_name, val);
            return val;
        }
        ts.putback(t);
        return val;
    }
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

Token::Token(char k, string s) : kind(k), name(s)
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

    while (cin.get(c) && isspace(c)) {      // ex05
        if (c=='\n') {
            return Token(PRINT);
        }
    }

    switch (c) {
    case PRINT:
    case QUIT:
    case EQUAL:
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
        if (isalpha(c)) {
            string s;
            s += c;

            while (cin.get(c) && (isalnum(c) || c=='_')) {  // ex01
                s += c;
            }
            cin.putback(c);

            if (s==DECL_KEY) {
                return Token(LET);
            }
            else if (s==CONST_KEY) {    // ex03
                return Token(CONST);
            }
            else if (s=="H" || s=="h" || s=="help") { // ex06
                return Token(HELP);
            }
            else if (s=="quit") {       // ex07
                return Token(QUIT);
            }
            return Token(VARIABLE, s);
        }
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

// implementation of Variable
Variable::Variable(string s, double d, bool b) : name(s), value(d), m_const(b)
{
}

bool Variable::is_const()   // ex03
{
    return m_const;
}

// implementation of Symbol_table
Symbol_table::Symbol_table()
{
}

double Symbol_table::get_value(string s)
{
    for (const auto& var : m_table) {
        if (s==var.name) {
            return var.value;
        }
    }
    error("get: undefined variable ", s);
}

void Symbol_table::set_value(string s, double d)
{
    for (auto& var : m_table) {
        if (s==var.name) {
            if (var.is_const()) {   // ex03
                error("constants can't be changed");
            }
            var.value = d;
            return;
        }
    }
    error("set: undefined variable ", s);
}

bool Symbol_table::is_declared(string s)
{
    for (const auto& var : m_table) {
        if (s==var.name) {
            return true;
        }
    }
    return false;
}

double Symbol_table::define_name(string s, double d, bool is_const)
{
    if (is_declared(s)) {
        error(s, " declared twice");
    }
    m_table.push_back(Variable(s, d, is_const));
    return d;
}

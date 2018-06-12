
/*
calculator08buggy.cpp

Helpful comments removed.

We have inserted 3 bugs that the compiler will catch and 3 that it won't.
*/

#include "std_lib_facilities.h"

struct Token {
    char kind;
    double value;
    string name;
    Token(char ch) :kind(ch), value(0) { }
    Token(char ch, double val) :kind(ch), value(val) { }
    Token(char ch, string n) :kind(ch), name(n) { }     // constructor expected
};

class Token_stream {
    bool full;
    Token buffer;
public:
    Token_stream() :full(0), buffer(0) { }

    Token get();
    void unget(Token t) {
        buffer = t; full = true;
    }

    void ignore(char);
};

const char let = '#';
const char quit = 'Q';
const char print = ';';
const char number = '8';
const char name = 'a';
const char SQRT = 's';
const char POW = 'p';
const string CMD_QUIT = "exit";
const string CMD_SQRT = "sqrt";
const string CMD_POW = "pow";

Token Token_stream::get()
{
    if (full) {
        full = false; return buffer;
    }
    char ch;
    cin >> ch;
    switch (ch) {
    case quit:      // case 'quit' expected
    case let:
    case '(':
    case ')':
    case '+':
    case '-':
    case '*':
    case '/':
    case '%':
    case ';':
    case ',':
    case '=':
        return Token(ch);
    case '.':
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
    {	cin.unget();
    double val;
    cin >> val;
    return Token(number, val);
    }
    default:
        if (isalpha(ch)) {
            string s;
            s += ch;
            while (cin.get(ch) && (isalpha(ch) || isdigit(ch))) s += ch;     // '+=' expected
            cin.unget();
            //if (s == CMD_LET) return Token(let);
            if (s == CMD_QUIT) return Token(quit);        // 'quit' parameter expected
            if (s == CMD_SQRT) {
                return Token(SQRT);
            }
            if (s == CMD_POW) {
                return Token(POW);
            }
            return Token(name, s);
        }
        error("Bad token");
    }
}

void Token_stream::ignore(char c)
{
    if (full && c==buffer.kind) {
        full = false;
        return;
    }
    full = false;

    char ch;
    while (cin>>ch)
        if (ch==c) return;
}

struct Variable {
    string name;
    double value;
    Variable(string n, double v) :name(n), value(v) { }
};

vector<Variable> names;

double get_value(string s)
{
    for (int i = 0; i<names.size(); ++i)
        if (names[i].name == s) return names[i].value;
    error("get: undefined name ", s);
}

void set_value(string s, double d)
{
    for (int i = 0; i<names.size(); ++i)       // '<' or '!=' expected
        if (names[i].name == s) {
            names[i].value = d;
            return;
        }
    error("set: undefined name ", s);
}

bool is_declared(string s)
{
    for (int i = 0; i<names.size(); ++i)
        if (names[i].name == s) return true;
    return false;
}

double define_name(string s, double d)
{
    if (is_declared(s)) {
        error(s, " declared twice");
    }
    names.push_back(Variable(s, d));
    return d;
}

Token_stream ts;

double expression();

double primary()
{
    Token t = ts.get();
    switch (t.kind) {
    case '(':
    {	double d = expression();
    t = ts.get();
    if (t.kind != ')') error("')' expected");
    return d;       // return statement expected
    }
    case '-':
        return -primary();
    case '+':       // case '+' expected
        return primary();
    case number:
        return t.value;
    case name:
        return get_value(t.name);
    case SQRT:
    {
        t = ts.get();

        if (t.kind!='(') {
            error("'(' expected");
        }
        double d = expression();
        t = ts.get();

        if (t.kind!=')') {
            error("')' expected");
        }
        if (d<0) {
            error("non-negative numbers expected");
        }
        return sqrt(d);
    }
    case POW:
    {
        t = ts.get();

        if (t.kind!='(') {
            error("'(' expected");
        }
        double d1 = expression();
        t = ts.get();

        if (t.kind!=',') {
            error("',' expected");
        }
        double d2 = expression();
        t = ts.get();

        if (t.kind!=')') {
            error("')' expected");
        }
        return pow(d1, narrow_cast<int>(d2));
    }
    default:
        error("primary expected");
    }
}

double term()
{
    double left = primary();
    while (true) {
        Token t = ts.get();
        switch (t.kind) {
        case '*':
            left *= primary();
            break;
        case '/':
        {	double d = primary();
        if (d == 0) error("divide by zero");
        left /= d;
        break;
        }
        default:
            ts.unget(t);
            return left;
        }
    }
}

double expression()
{
    double left = term();
    while (true) {
        Token t = ts.get();
        switch (t.kind) {
        case '+':
            left += term();
            break;
        case '-':
            left -= term();
            break;
        default:
            ts.unget(t);
            return left;
        }
    }
}

double declaration()
{
    Token t = ts.get();
    if (t.kind != 'a') error("name expected in declaration");
    string name = t.name;
    if (is_declared(name)) error(name, " declared twice");
    Token t2 = ts.get();
    if (t2.kind != '=') error("= missing in declaration of ", name);
    double d = expression();
    names.push_back(Variable(name, d));
    return d;
}

double statement()
{
    Token t = ts.get();
    switch (t.kind) {
    case let:
        return declaration();
    default:
        ts.unget(t);
        return expression();
    }
}

void clean_up_mess()
{
    ts.ignore(print);
}

const string prompt = "> ";
const string result = "= ";

void calculate()
{
    while (true) try {
        cout << prompt;
        Token t = ts.get();
        while (t.kind == print) t = ts.get();
        if (t.kind == quit) return;
        ts.unget(t);
        cout << result << statement() << endl;
    }
    catch (runtime_error& e) {
        cerr << e.what() << endl;
        clean_up_mess();
    }
}

int main()

try {
    define_name("k", 1000);

    calculate();
    return 0;
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
    char c;
    while (cin >>c&& c!=';');
    return 1;
}
catch (...) {
    cerr << "exception\n";
    char c;
    while (cin>>c && c!=';');
    return 2;
}
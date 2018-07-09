#include "std_lib_facilities.h"

class Patron
{
public:
    Patron();
    ~Patron();

    string user_name() const { return m_uname; }
    int card_number() const { return m_cnumber; }
    double fee() const { return m_fee; }

    void fee(double fee) { m_fee = fee; }

private:
    string m_uname;
    int m_cnumber;
    double m_fee;
};

bool owe_fee(const Patron& p);

// implementation of class Patron
Patron::Patron()
{
}

Patron::~Patron()
{
}

bool owe_fee(const Patron& p)
{
    return p.fee() > 0.0;
}

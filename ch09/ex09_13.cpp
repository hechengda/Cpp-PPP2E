#include "std_lib_facilities.h"

class Rational
{
public:
    Rational(int numerator, int denominator);
    ~Rational();

    int numerator() const { return m_num; }
    int denominator() const { return m_den; }
    double value() const { return m_num / m_den; }

private:
    int m_num;      // numerator
    int m_den;      // denominator
};

// helper functions
Rational operator+(const Rational& r1, const Rational& r2);
Rational operator-(const Rational& r1, const Rational& r2);
Rational operator*(const Rational& r1, const Rational& r2);
Rational operator/(const Rational& r1, const Rational& r2);
bool operator==(const Rational& r1, const Rational& r2);
bool operator!=(const Rational& r1, const Rational& r2);

// implementation of class Rational
Rational::Rational(int numerator, int denominator) : m_num{numerator}
{
    if (!denominator) {
        error("divisor is zero");
    }
    m_den{denominator};
}

Rational::~Rational()
{
}

Rational operator+(const Rational& r1, const Rational& r2)
{
    return Rational{r1.numerator()*r2.denominator() + r1.denominator()*r2.numerator(), r1.denominator() * r2.denominator()};
}

Rational operator-(const Rational& r1, const Rational& r2)
{
    return Rational{r1.numerator()*r2.denominator() - r1.denominator()*r2.numerator(), r1.denominator() * r2.denominator()};
}

Rational operator*(const Rational& r1, const Rational& r2)
{
    return Rational{r1.numerator() * r2.numerator(), r1.denominator() * r2.denominator()};
}

Rational operator/(const Rational& r1, const Rational& r2)
{
    return Rational{r1.numerator() * r2.denominator(), r1.denominator() * r2.numerator()};
}

bool operator==(const Rational& r1, const Rational& r2)
{
    return r1.value() == r2.value();
}

bool operator!=(const Rational& r1, const Rational& r2)
{
    return !(r1 == r2);
}

#include "Fraction.h"
#include <stdexcept>
#include <numeric>
#include <cstdlib>

void Fraction::reduce()
{
    if (m_denominator == 0)
        throw std::invalid_argument("Denominator cannot be zero");

    if (m_numerator == 0)
    {
        m_denominator = 1;
        return;
    }

    int gcd = std::gcd(std::abs(m_numerator), static_cast<int>(m_denominator));
    m_numerator /= gcd;
    m_denominator /= gcd;

    if (static_cast<int>(m_denominator) < 0)
    {
        m_numerator = -m_numerator;
        m_denominator = static_cast<unsigned>(-static_cast<int>(m_denominator));
    }
}

Fraction::Fraction(int numerator, unsigned int denominator)
    : m_numerator(numerator), m_denominator(denominator)
{
    if (denominator == 0)
        throw std::invalid_argument("Denominator cannot be zero");

    reduce();
}

void Fraction::numerator(int numerator)
{
    m_numerator = numerator;
    reduce();
}

void Fraction::denominator(unsigned denominator)
{
    if (denominator == 0)
        throw std::invalid_argument("Denominator cannot be zero");

    m_denominator = denominator;
    reduce();
}

Fraction Fraction::operator+(const Fraction& other) const
{
    int num = m_numerator * other.m_denominator
              + other.m_numerator * m_denominator;

    unsigned denom = m_denominator * other.m_denominator;

    return Fraction(num, denom);
}

Fraction Fraction::operator-(const Fraction& other) const
{
    int num = m_numerator * other.m_denominator
              - other.m_numerator * m_denominator;

    unsigned denom = m_denominator * other.m_denominator;

    return Fraction(num, denom);
}

Fraction Fraction::operator*(const Fraction& other) const
{
    return Fraction(
        m_numerator * other.m_numerator,
        m_denominator * other.m_denominator
        );
}

Fraction Fraction::operator/(const Fraction& other) const
{
    if (other.m_numerator == 0)
        throw std::invalid_argument("Division by zero fraction");

    int num = m_numerator * static_cast<int>(other.m_denominator);
    int denomSigned = static_cast<int>(m_denominator) * other.m_numerator;

    if (denomSigned < 0)
    {
        num = -num;
        denomSigned = -denomSigned;
    }

    return Fraction(num, static_cast<unsigned>(denomSigned));
}

Fraction& Fraction::operator+=(const Fraction& other)
{
    *this = *this + other;
    return *this;
}

Fraction& Fraction::operator-=(const Fraction& other)
{
    *this = *this - other;
    return *this;
}

Fraction& Fraction::operator*=(const Fraction& other)
{
    *this = *this * other;
    return *this;
}

Fraction& Fraction::operator/=(const Fraction& other)
{
    *this = *this / other;
    return *this;
}

// ++f
Fraction& Fraction::operator++()
{
    m_numerator += m_denominator;
    reduce();
    return *this;
}

// f++
Fraction Fraction::operator++(int)
{
    Fraction temp(*this);
    ++(*this);
    return temp;
}

Fraction::operator double() const
{
    return m_numerator / static_cast<double>(m_denominator);
}

Fraction::operator QString() const
{
    return QString::number(m_numerator) + "/" +
           QString::number(m_denominator);
}

bool operator==(const Fraction& a, const Fraction& b)
{
    return a.m_numerator == b.m_numerator &&
           a.m_denominator == b.m_denominator;
}

bool operator!=(const Fraction& a, const Fraction& b)
{
    return !(a == b);
}

bool operator<(const Fraction& a, const Fraction& b)
{
    return static_cast<long long>(a.m_numerator) * b.m_denominator <
           static_cast<long long>(b.m_numerator) * a.m_denominator;
}

bool operator<=(const Fraction& a, const Fraction& b)
{
    return (a < b) || (a == b);
}

bool operator>(const Fraction& a, const Fraction& b)
{
    return b < a;
}

bool operator>=(const Fraction& a, const Fraction& b)
{
    return !(a < b);
}

std::ostream& operator<<(std::ostream& out, const Fraction& f)
{
    out << f.numerator() << "/" << f.denominator();
    return out;
}

std::istream& operator>>(std::istream& in, Fraction& f)
{
    int num;
    unsigned denom;
    char slash;

    in >> num >> slash >> denom;

    if (!in || slash != '/')
    {
        in.setstate(std::ios::failbit);
        return in;
    }

    f = Fraction(num, denom);
    return in;
}

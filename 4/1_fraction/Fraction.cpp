#include "Fraction.hpp"
#include <stdexcept>
#include <numeric>


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

    return Fraction(
        m_numerator * other.m_denominator,
        m_denominator * static_cast<unsigned>(std::abs(other.m_numerator))
    );
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

bool operator==(const Fraction& a, const Fraction& b)
{
    return a.m_numerator == b.m_numerator
        && a.m_denominator == b.m_denominator;
}

bool operator!=(const Fraction& a, const Fraction& b)
{
    return !(a == b);
}

bool operator<(const Fraction& a, const Fraction& b)
{
    return static_cast<long long>(a.m_numerator) * b.m_denominator
         < static_cast<long long>(b.m_numerator) * a.m_denominator;
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

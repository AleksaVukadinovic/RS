#ifndef FRACTION_H
#define FRACTION_H

#include <ostream>
#include <istream>
#include <QString>

class Fraction
{
private:
    int m_numerator;
    unsigned m_denominator;

    void reduce();

    friend std::istream& operator>>(std::istream& in, Fraction& f);

public:
    Fraction(int numerator = 0, unsigned denominator = 1u);

    int numerator() const { return m_numerator; }
    unsigned denominator() const { return m_denominator; }

    void numerator(int numerator);
    void denominator(unsigned denominator);

    Fraction operator+(const Fraction& other) const;
    Fraction operator-(const Fraction& other) const;
    Fraction operator*(const Fraction& other) const;
    Fraction operator/(const Fraction& other) const;

    Fraction& operator+=(const Fraction& other);
    Fraction& operator-=(const Fraction& other);
    Fraction& operator*=(const Fraction& other);
    Fraction& operator/=(const Fraction& other);

    Fraction& operator++();     // ++f
    Fraction operator++(int);   // f++

    operator double() const;
    operator QString() const;

    friend bool operator==(const Fraction& a, const Fraction& b);
    friend bool operator!=(const Fraction& a, const Fraction& b);
    friend bool operator<(const Fraction& a, const Fraction& b);
    friend bool operator<=(const Fraction& a, const Fraction& b);
    friend bool operator>(const Fraction& a, const Fraction& b);
    friend bool operator>=(const Fraction& a, const Fraction& b);
};

std::ostream& operator<<(std::ostream& out, const Fraction& f);

#endif // FRACTION_H

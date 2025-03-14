#include "rational.h"

Rational::Rational()
{
	numer = 0; denom = 1;
}

Rational::Rational(int number)
{
	numer = number;
	denom = 1;
}

Rational::Rational(int n, int d)
{
	numer = n; 
	denom = d;
}

int Rational::gcd(int a, int b) {
    a = babs(a); b = babs(b);
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

void Rational::simplify() {
    int g = gcd(babs(numer), babs(denom));
    numer /= g;
    denom /= g;
    if (denom < 0) {
        numer = -numer;
        denom = -denom;
    }
}

Rational& Rational::operator +=(const Rational& r)
{
	numer = (numer * r.denom + denom * r.numer);
	denom *= r.denom;
	simplify();
	return *this;
}

Rational Rational::operator +(const Rational& r) const
{
    Rational res(*this);
    return res += r;
}

Rational Rational::operator -() const
{
    Rational r(-numer, denom);
    return r;
}

Rational Rational::operator - (const Rational& r) const {
    return (*this + (-r));
}


Rational& Rational::operator -=(const Rational& r)
{
    return (*this += (-r));
}

Rational& Rational::operator *=(const Rational& r)
{
    numer *= r.numer;
    denom *= r.denom;
    simplify();
    return *this;
}

Rational Rational::operator *(const Rational& r) const
{
    Rational res(*this);
    return res *= r;
}

Rational& Rational::operator /=(const Rational& r)
{
    numer *= r.denom;
    denom *= r.numer;
    simplify();
    return *this;
}

Rational Rational::operator /(const Rational& r) const
{
    Rational res(*this);
    return res /= r;
}

// пост и префиксные инкременты
Rational& Rational::operator ++()
{
    numer += denom;
    return *this;
}
Rational Rational::operator ++(int)
{
    Rational r(*this);
    numer += denom;
    return r;
}

// сравнение

bool Rational::operator ==(const Rational& r) const
{
    return (numer == r.numer && denom == r.denom);
}

bool Rational::operator !=(const Rational& r) const
{
    return !(*this == r);
}

bool Rational::operator >(const Rational& r) const {
    return numer * r.denom > denom * r.numer;
}

bool Rational::operator <(const Rational& r) const {
    return r > *this;
}

// преобразование типов

Rational::operator int() const
{
    return numer / denom;
}

Rational::operator double() const
{
    return ((double)numer) / denom;
}

Rational Rational::sqrt() const
{
    Rational res(
        b_sqrt(numer), b_sqrt(denom)
    );
    return res;
}

// ввод / вывод

ostream& operator <<(ostream& out, const Rational& r)
{
    out << r.numer << "/" << r.denom;
    return out;
}

istream& operator >>(istream& in, Rational& r)
{
    in >> r.numer >> r.denom;
    return in;
}


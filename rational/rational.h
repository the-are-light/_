#ifndef _RATIONAL_H_
#define _RATIONAL_H_

#include <iostream>
#include "bmath.h"

using namespace std;

class Rational {
	int numer, denom;
	void simplify();
	int gcd(int a, int b);

public:

	Rational();
	Rational(int num);
	Rational(int n, int d);

	friend ostream& operator <<(ostream& out, const Rational& r);
	friend istream& operator >>(istream& in, Rational& r);

	//сравнение
	bool operator ==(const Rational& r) const;
	bool operator !=(const Rational& r) const;

	//инкременты
	Rational& operator ++(); // префикс
	Rational operator ++(int); //постфикс

	// перегрузка операторов
	Rational operator +(const Rational& r) const;
	Rational& operator +=(const Rational& r);
	Rational operator -() const;
	Rational operator -(const Rational& r) const;
	Rational& operator -=(const Rational& r);

	Rational& operator *=(const Rational& r);
	Rational operator *(const Rational& r) const;
	Rational& operator /=(const Rational& r);
	Rational operator /(const Rational& r) const;

	operator int() const;
	operator double() const;

	bool operator >(const Rational& r) const;
	bool operator <(const Rational& r) const;

	Rational sqrt() const;

};




#endif // !_RATIONAL_H_

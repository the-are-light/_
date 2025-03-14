
#include <iostream>
#include "locale.h"
#include "rational.h"
#include "bmath.h"

using namespace std;

Rational linear_eq(Rational& b, Rational& k);
void square_eq(Rational a, Rational b, Rational c, Rational out[2]);


void main() {

    setlocale(LC_ALL, "russian");
    
    Rational k(2, 3), b1(1, 4);
    cout << linear_eq(b1, k) << endl;

    Rational a(1, 2);
    Rational b(-5, 6);
    Rational c(1, 3);
    Rational out[2] = { 0, 0 };
    square_eq(a, b, c, out);

    cout << "Для уравнения y = (" << a << ")*x^2 + (" << b << ")*x + (" << c
        << ") x1 = " << out[0] << " x2 = " << out[1] << endl;
}

Rational linear_eq(Rational& b, Rational& k)
{
    return -b / k;
}

void square_eq(Rational a, Rational b, Rational c, Rational out[2])
{
    Rational d = b * b - Rational(4) * a * c;
    
    if (d < (Rational)0)
    {
        cout << "Корней нет";
    }
    out[0] = (-b + d.sqrt()) / Rational(2) * a;
    out[1] = (-b - d.sqrt()) / Rational(2) * a;
}
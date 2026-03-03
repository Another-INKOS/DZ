#include "Complex.h"
#include <iostream>
#include <cmath>

using namespace std;
Complex::Complex()
    : re(0.0),
    im(0.0)
{

}
Complex::Complex(double x, double y)
    : re(x),
    im(y)
{

}
double Complex::GetRe() const 
{
    return re;
}
double Complex::GetIm() const 
{
    return im;
}
void Complex::SetRe(double x) 
{
    re = x;
}
void Complex::SetIm(double y) 
{
    im = y;
}
double Complex::Abs() const 
{
    return sqrt(re * re + im * im);
}
double Complex::Arg() const 
{
    return atan2(im, re);
}
void Complex::Print() const 
{
    cout << re;

    if (im >= 0) 
    {
        cout << " + ";
    }
    else 
    {
        cout << " - ";
    }

    cout << abs(im) << "i" << endl;
}
void Complex::TrigPrint() const 
{
    double r = Abs();
    double phi = Arg();

    cout << r << "*(cos(" << phi << ") + i*sin(" << phi << "))" << endl;
}
void Complex::ExpPrint() const 
{
    double r = Abs();
    double phi = Arg();

    cout << r << "*exp(i*" << phi << ")" << endl;
}
Complex Complex::Add(const Complex& z) const 
{
    return Complex(re + z.re, im + z.im);
}
Complex Complex::Sub(const Complex& z) const
{
    return Complex(re - z.re, im - z.im);
}
Complex Complex::Mult(const Complex& z) const 
{
    double real = re * z.re - im * z.im;
    double imag = re * z.im + im * z.re;
    return Complex(real, imag);
}
Complex Complex::Div(const Complex& z) const 
{
    double denom = z.re * z.re + z.im * z.im;

    double real = (re * z.re + im * z.im) / denom;
    double imag = (im * z.re - re * z.im) / denom;

    return Complex(real, imag);
}

//  =============== BEGIN ASSESSMENT HEADER ================
/// @file lab3/ex1.cpp 
/// @brief Lab 4 for CS 12 Winter 2014
///
/// @author David Anderson [dande011@ucr.edu]
/// @date 1/29/2014
///
/// @par Enrollment Notes 
///     Lecture Section: 001
/// @par
///     Lab Section: 021
/// @par
///     TA: Nkenge Wheatland
///
/// @par Plagiarism Section
/// I hereby certify that the code in this file
/// is ENTIRELY my own original work.
//  =============== END ASSESSMENT HEADER ==================
#include <iostream>
using namespace std;

class Rational
{
   private:
      int numer;
      int denom; 
   public:
      Rational();
      Rational(int); 
      Rational(int, int); 
      const Rational add(const Rational &) const; 
      const Rational subtract(const Rational &) const; 
      const Rational multiply(const Rational &) const; 
      const Rational divide(const Rational &) const; 
      void display() const; 
};

Rational::Rational() : numer(0), denom(1) {};
Rational::Rational(int x) :  numer(x), denom(1) {};
Rational::Rational(int x, int y) : numer(x), denom(y) {};


void Rational::display() const
{
	cout << numer << '/' << denom;
}

const Rational Rational::add(const Rational &x) const
{
	Rational temp;
	temp.numer = (numer * x.denom) + (denom * x.numer);
	temp.denom = denom * x.denom;
	return temp;
}
const Rational Rational::subtract(const Rational &x) const
{
	Rational temp;
	temp.numer = (numer * x.denom) - (denom * x.numer);
	temp.denom = denom * x.denom;
	return temp;
}
const Rational Rational::multiply(const Rational &x) const
{
	Rational temp;
	temp.numer = numer * x.numer;
	temp.denom = denom * x.denom;
	return temp;
}
const Rational Rational::divide(const Rational &x) const
{
	Rational temp;
	temp.numer = numer * x.denom;
	temp.denom = denom * x.numer;
	return temp;
}



int main()
{
	
	return 0;
}

// Jisoo Choi
// CS 2336
// Lab 03

#include <lab03.h>
#include <cmath>
#include <iostream>

Rational Rational::add(const Rational& addend) const
{
	int myLCM = lcm(getDenominator(), addend.getDenominator());
	//int myLCM = lcm((*this)getDenominator(), addend.getDenominator());
	//int myLCM = lcm(this->getDenominator(), addend.getDenominator());
	
	int leftNumerator = myLCM / getDenominator() * getNumerator();
	int rightNumerator = myLCM / addend.getDenominator() * addend.getNumerator();
	
	Rational sum(leftNumerator + rightNumerator, myLCM);
	
	sum.reduce();
	
	return sum;

}

Rational Rational::additiveInverse() const
{
	return Rational(getNumerator() * -1, getDenominator());
}

Rational Rational::subtract(const Rational& subtrahend) const
{
	return add(subtrahend.additiveInverse());
}

Rational Rational::multiply(const Rational& multiplicand) const {
	Rational multi(getNumerator() * multiplicand.getNumerator(), getDenominator() * multiplicand.getDenominator());
	multi.reduce();
	
	return multi;
}

Rational Rational::multiplicativeInverse() const
{
	return Rational(getDenominator(), getNumerator());
}

Rational Rational::divide(const Rational& divisor) const
{
	int numeratorNew = getNumerator() * divisor.multiplicativeInverse().getNumerator();
	int DenominatorNew = getDenominator() * divisor.multiplicativeInverse().getDenominator();
	
	Rational divideR (numeratorNew, DenominatorNew);
	divideR.reduce();
	return divideR;
}

ostream& Rational::print(ostream& os) const
{
	os << getNumerator() << '/' << getDenominator();
	return os;
}

istream& Rational::read(istream& is) 
{
	int num, denom;
	
	if(is >> num >> denom){
		setNumerator(num);
		setDenominator(denom);
	}
	else {
		setNumerator(0);
		setDenominator(1);
	}
	
	return is;
}

int 	 Rational::lcm(int m, int n) const
{
	if(m == 0 && n == 0)
		return 0;
	else
		return abs(m * n) / gcd(m, n);
}

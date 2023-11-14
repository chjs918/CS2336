//Jisoo Choi
//CS 2336
//LAB 07

#include <lab07.h>
// It must be a member variable to modify.
// overloaded input operator initializes Rational rat from input stream in
/*friend*/ istream& operator>>(istream& in, Rational& rat){
	int num, denom;
	
	if(in >> num >> denom){
		rat.setNumerator(num);
		rat.setDenominator(denom);
	}
	else {
		rat.setNumerator(0);
		rat.setDenominator(1);
	}
	
	return in;
}

// overloaded output operator prints Rational rat to output stream out
/*friend*/ ostream& operator<<(ostream& out, const Rational& rat){
	out << rat.getNumerator() << "/" << rat.getDenominator();
	return out;
}

Rational& Rational::operator=(const Rational& rhs)       // *this = rhs;
{
	//now this is address..
	if(this != &rhs) //avoid self-assignment
	{
		data.first = rhs.data.first;
		data.second = rhs.data.second;
	}
	
	//return this;
	return *this;
	//return &this;
}
Rational  Rational::operator+(const Rational& addend) const// returns *this + addend
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

Rational  Rational::operator-() const                     // returns -(*this) (unary)
{
	return Rational(getNumerator() * -1, getDenominator());
}

Rational  Rational::operator-(const Rational& subtrahend) const// returns *this - subtrahend (binary)
{
	//return add(subtrahend.additiveInverse());
	//return operator+(subtrahend.operator-());	//works
	return *this + -subtrahend;
}

Rational  Rational::operator*(const Rational& multiplicand) const// returns *this * multiplicand
{
	Rational multi(getNumerator() * multiplicand.getNumerator(), getDenominator() * multiplicand.getDenominator());
	multi.reduce();
	
	return multi;
}
Rational  Rational::operator/(const Rational& divisor) const// returns *this / divisor
{
	return *this * divisor.multiplicativeInverse();
}
bool 	  Rational::operator==(const Rational& rhs) const     // *this == rhs
{
	//return subtract(other).getNumerator() == 0;
	return (*this - rhs).getNumerator() == 0;
}
bool 	  Rational::operator!=(const Rational& rhs) const     // *this != rhs
{
	return !(*this == rhs);  //return !operator==(this) //works
}
bool 	  Rational::operator< (const Rational& rhs) const     // *this <  rhs
{
	return (*this - rhs).getNumerator() < 0;
}
bool 	  Rational::operator<=(const Rational& rhs) const     // *this <= rhs
{
	if(*this < rhs || *this == rhs)
		return true;
	else
		return false;
}
bool 	  Rational::operator> (const Rational& rhs) const     // *this >  rhs
{
	return !(*this <= rhs);
} 
bool 	  Rational::operator>=(const Rational& rhs) const     // *this >= rhs
{
	if(*this > rhs || *this == rhs)
		return true;
	else
		return false;
}
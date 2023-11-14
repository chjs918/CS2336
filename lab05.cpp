m//Jisoo Choi
//CS 2336
//Lab 05

#include <lab05.h>
/*  There are two equality operators, == and !=.
	There are four relational operators, <, <=, >, >=.

	It is only necessary to write the code for ONE of the equality
	operator and One of the relational operators, It's traditional 
	to write the code for == and <. The remaining four are then
	written in terms of these two.

	== : write the code
	!= : !(==)
	<: write the code
	<=: (<) || (==)
	>: !(<)
	>=: !(<=) = !((<) || (==)) = !(<) && !(==) //Demorgan's Law
*/
	
bool Rational::isEqualTo(const Rational& other) const    // *this == other
{
	return subtract(other).getNumerator() == 0;
}
bool Rational::isNotEqualTo(const Rational& other) const // *this != other
{
	return !isEqualTo(other);
}
bool Rational::isLessThan(const Rational& other) const   // *this < other
{
	return subtract(other).getNumerator() < 0;
}
bool Rational::isLessThanOrEqualTo(const Rational& other) const // *this <= other
{
	return isEqualTo(other) || isLessThan(other);
}
bool Rational::isGreaterThan(const Rational& other) const // *this > other
{
	return !isLessThan(other);
}
bool Rational::isGreaterThanOrEqualTo(const Rational& other) const // *this >= other
{
	return !isLessThan(other) && !isEqualTo(other);
}
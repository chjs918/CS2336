//Jisoo Choi
//CS 2336
//LAB 09

#include <lab09.h>
 
Rational&  Rational::operator++()                         // preincrement
{
	// add "1" to *this
	*this = *this + Rational(1,1);
	return *this;
	
}

Rational   Rational::operator++(int)                       // postincrement
{
	//Rational copy(*this);
	Rational copy = *this;
	
	//increment *this by calling the preincrement operator
	++*this; 											//works
	//*++this; 											//doesn't work (wrong order)
	//*this++; 											//doesn't work, calls postincrement
	//this->operator++(); 								//works
	//(*this)->operator();								//works
	//this->operator++(0);								//doesn't work, calls postincrement
	
	//++copy;
	
	return copy;
}

Rational&  Rational::operator--()                         // predecrement
{
	//subtract "1" from *this
	*this = *this - Rational(1,1);
	return *this;
}

Rational   Rational::operator--(int)                       // postdecrement
{
	Rational copy = *this;
	
	--*this; 
	return copy;
}
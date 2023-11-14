// Jisoo Choi
// CS 2336
// Lab 02

#include <lab02.h>
#include <cmath> // for abs
//alt+drag add Rational:: 
	Rational::Rational()
			:Rational(0, 1)
	{}
	
	Rational::Rational(int num, int denom)
	{
		setNumerator(num);
		setDenominator(denom);
	}
	
	void Rational::setNumerator(int num) // set numerator to num
	{
		data.first = num;
	}
	
	void Rational::setDenominator(int denom) // set denominator to denom
	{
		data.second = (denom == 0) ? 1 : denom;
	}
	
	int  Rational::getNumerator() const // return numerator
	{
		return data.first;
	}
	
	int  Rational::getDenominator() const // return denominator
	{
		return data.second;
	}
	
	void Rational::reduce() // Reduce to lowest terms and
	{
		int myGCD = gcd(getNumerator(), getDenominator());
		
		if(getDenominator() < 0)
			myGCD = -myGCD;
		
		setNumerator(getNumerator()/myGCD);
		setDenominator(getDenominator()/myGCD);
	}
	
	int  Rational::gcd(int m, int n) const 
	{
		if(m == 0)
			return abs(n);
		else if (n == 0)
			return abs(m);
		else //use Euclid Alg
		{
			m = abs(m);
			n = abs(n);
			int rem = m % n;
			
			while (rem != 0)
			{
				m = n;
				n = rem;
				rem = m % n;
			}
			
			return n;
		}
	}
	
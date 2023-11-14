//Jisoo Choi
//CS 2336
//LAB 11

#include <lab11.h>

bool IntegerSet::operator==(const IntegerSet& rhs) const // Test for equality
{
	// compare bit
	for(uint e = 0 ; e < N ; ++e) {
		if(getBit(bitVector[word(e)], bit(e)) != getBit(rhs.bitVector[rhs.word(e)], rhs.bit(e)))
			return false;
	}
	return true;
}

bool IntegerSet::operator<=(const IntegerSet& rhs) const // Subset
{
	//intersection == *this
	if(rhs * *this == *this)
		return true;
	else
		return false;
}

bool IntegerSet::operator< (const IntegerSet& rhs) const // Proper Subset
{
	//<= && !=
	if(*this <= rhs && !(*this == rhs))
		return true;
	else
		return false;
}
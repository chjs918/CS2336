//Jisoo Choi
//CS 2336
//LAB 10

#include <lab10.h>
 
IntegerSet IntegerSet::operator+(const IntegerSet& rhs) const // union
{
	IntegerSet myUnion;
	
	//manipulate the local object
	//Loop for e = 0, 1, 2,.. (N-1)
	//	if e is a member of *this or a member of otherSet then
	// 		insert e into myUnion
	for(uint e = 0; e < N ; ++e){
		if(isMember(e) || rhs.isMember(e)) {
			myUnion = myUnion + e; //Okay, differ from function operator.
		}
	}
		
	//return the local object
	return myUnion;
}
IntegerSet IntegerSet::operator*(const IntegerSet& rhs) const // intersection
{
	IntegerSet myUnion;
	
	for(uint e = 0; e < N ; ++e){
		if(isMember(e) && rhs.isMember(e)) {
			myUnion = myUnion + e;
		}
	}
		
	//return the local object
	return myUnion;
}
IntegerSet IntegerSet::operator-(const IntegerSet& rhs) const // difference
{
	IntegerSet myUnion;
	
	for(uint e = 0; e < N ; ++e){
		if(isMember(e) && !rhs.isMember(e)) {
			myUnion = myUnion + e; 
		}
	}
		
	//return the local object
	return myUnion;
}
IntegerSet IntegerSet::operator/(const IntegerSet& rhs) const // symmetric diff
{
	IntegerSet myUnion = *this + rhs;
	
	for(uint e = 0; e < N ; ++e){
		if(isMember(e) && rhs.isMember(e)) {
			myUnion = myUnion - e; 
		}
	}
		
	//return the local object
	return myUnion;
}
//Jisoo Choi
//CS 2336
//Lab 06

#include <lab06.h>

//must set classname!
IntegerSet IntegerSet::Union(const IntegerSet& otherSet) const
{
	IntegerSet myUnion;
	
	//manipulate the local object
	//Loop for e = 0, 1, 2, (N-1)
	//	if e is a member of *this or a member of otherSet then
	// 		insert e into myUnion
	for(uint e = 0; e < N ; ++e){
		if(isMember(e) || otherSet.isMember(e)) {
			myUnion.insertElement(e);
		}
	}
		
	//return the local object
	return myUnion;
}

IntegerSet IntegerSet::intersection(const IntegerSet& otherSet) const
{
	IntegerSet myUnion;
	for(uint e = 0; e < N ; ++e){
		if(isMember(e) && otherSet.isMember(e)) {
			myUnion.insertElement(e);
		}
	}
	
	//return the local object
	return myUnion;
}

IntegerSet IntegerSet::difference(const IntegerSet& otherSet) const
{
	IntegerSet myUnion;
	
	for(uint e = 0; e < N ; ++e){
		if(isMember(e) && !otherSet.isMember(e)) {
			myUnion.insertElement(e);
		}
	}
	
	//return the local object
	return myUnion;
}

IntegerSet IntegerSet::symmetricDifference(const IntegerSet& otherSet) const
{
	IntegerSet myUnion = Union(otherSet);
	
	for(uint e = 0; e < N ; ++e){
		if(isMember(e) && otherSet.isMember(e)) {
			myUnion.deleteElement(e);
		}
	}
	
	//return the local object
	return myUnion;
}

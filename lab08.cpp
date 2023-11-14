//Jisoo Choi
//CS 2336
//LAB 08

#include <lab08.h>

// overloaded output operator for printing IntegerSet set to
// output stream out
/*friend*/ 
ostream& operator<<(ostream& out, const IntegerSet& set) {
	uint cnt = 0; 
	
	if(set.cardinality() == 0)
		out << static_cast<char>(216) << endl;
	else{
		out << "{";
		// Loop through the universe 0, 1, 2, ... , (N-1)
		// if e is a element of *this then 
		// print e
		for(uint e = 0 ; e < N ; ++e) {
			if(set.isMember(e)){
				cnt++;
				if(cnt < set.cardinality()){
					out << e << ", ";
				} else {
					out << e;
				}
			}
		}
		
		out << "}" << endl;
	}
	return out;
}

IntegerSet  IntegerSet::operator+(uint e) const     // if e is valid and not a member  the set, insert e into set
{
	IntegerSet mySet(*this); 	//create a local object
	
	if(isValid(e) && !isMember(e)){
		// setBit:  return value with bit n set to v (0 or 1).
		//unsigned int setVit(unsigned int word, int n, unsigned int)
		mySet.bitVector[word(e)] = setBit(bitVector[word(e)], bit(e), 1);
	}
	
	return mySet; //return the local object
}	
										
IntegerSet  IntegerSet::operator-(uint e) const     // if e is valid and a member of the set, delete e from set
{
	IntegerSet mySet(*this); 
	
	if(isValid(e) && isMember(e)){
		// setBit:  return value with bit n set to v (0 or 1).
		//unsigned int setVit(unsigned int word, int n, unsigned int)
		mySet.bitVector[word(e)] = setBit(bitVector[word(e)], bit(e), 0);
	}
	
	return mySet; //return the local object
}

IntegerSet  IntegerSet::operator-() const          // complement of a Set
{	
	IntegerSet myComplement; //Declare a local object
	
	//manipulate the local object
	//...
	
	//uint e = 5;
	//myComplement = myComplement + e;
	//myComplement = myComplement - e; //legal, cuz this operator is binary, function operator is unary
	
	//my Complement = -myComplement; //illeal, unary
	//Syntax Error
	//myComplement += e; //illegal, We don't have +=. (We have +, = each.)
	//myComplement = e + myComplement; //illegal, wrong order. Integer + IntegerSet(x), IntegerSet + Integer(o)
	
	for(uint e = 0; e < N ; ++e){
		if(isMember(e))
			myComplement = myComplement - e;
		else
			myComplement = myComplement + e;
	}
	
	return myComplement; //return the local object
}

IntegerSet& IntegerSet::operator=(const IntegerSet& rhs)
{
	if(this != &rhs) //void self-assignment
	{
		//Loop through out universe e = 0, 1, 2, ...,(N-1)
		//if e is a member of rhs then
		// 	*this = *this + e
		//else
		//	*this = *this - e
	
		for(uint e = 0; e < N ; ++e){
			/*
			if(rhs.isMember(e)){
				*this = *this + e;
			} else {
				*this = *this - e;
				*/
				//recursive, not use =
			int v = 0;
			if(rhs.isMember(e)){
				v = 1;
			} else {
				v = 0;
			}
			
			bitVector[word(e)] = setBit(bitVector[word(e)], bit(e), v);
		}
		
	}
	
	return *this;
	
}

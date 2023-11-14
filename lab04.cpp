// Jisoo Choi
// CS 2336
// Lab 04

#include <lab04.h>
#include <iostream>
#include <bits.h> //for getBit, setBit, ...

IntegerSet::IntegerSet()
{
	//call allocateStorage first to allocate memory for bitVector
	allocateStorage();
	
	//Loop through the universe 0, 1, 2, ..., N-1
	for(uint e = 0 ; e < N; ++e){
		deleteElement(e);
	}
}                                                   

IntegerSet::IntegerSet(const IntegerSet& otherSet)
{
	//call allocateStorage first to allocate memory for bitVector
	allocateStorage();
	
	//Loop through the universe 0, 1, 2, ..., N-1
	//if e is a member of otherSet then
	// insert e from * this
	//else
	// delete e from * this
	for(uint e = 0; e < N ; ++e){
		if(otherSet.isMember(e)) 
			insertElement(e);
		else
			deleteElement(e);
	}
	
}

IntegerSet::~IntegerSet()
{
	//destructor: call delete
	delete [] bitVector;
}                      

bool      IntegerSet::isMember(uint e) const    
{
	//getBit: get Value of bit n in word.
	//unsigned int getBit(unsigned int word, int n);
	return isValid(e) && getBit(bitVector[word(e)], bit(e));
}         
                          
uint      IntegerSet::cardinality() const
{
	uint cnt = 0;
    for(uint e = 0; e < N; ++e) 
	  if(isMember(e)) 
	     cnt ++;
	
	return cnt;
}  
												
void      IntegerSet::insertElement(uint e)
{
		if(isValid(e) && !isMember(e)){
			// setBit:  return value with bit n set to v (0 or 1).
			//unsigned int setVit(unsigned int word, int n, unsigned int)
			bitVector[word(e)] = setBit(bitVector[word(e)], bit(e), 1);
		}
}             
                            
void      IntegerSet::deleteElement(uint e)  
{
		if(isValid(e) && isMember(e)){
			// setBit:  return value with bit n set to v (0 or 1).
			//unsigned int setVit(unsigned int word, int n, unsigned int)
			bitVector[word(e)] = setBit(bitVector[word(e)], bit(e), 0);
		}
}           
                                        
IntegerSet IntegerSet::complement() const  
{
	IntegerSet myComplement; //Declare a local object
	
	//manipulate the local object
	//...
	
	//myComplement.insertElement(5);
	
	for(uint e = 0; e < N ; ++e){
		if(isMember(e))
			myComplement.deleteElement(e);
		else
			myComplement.insertElement(e);
	}
	
	return myComplement; //return the local object
}        
	
ostream&   IntegerSet::print(ostream& os) const
{
	uint cnt = 0; 
	
	if(cardinality() == 0)
		os << static_cast<char>(216) << endl;
	else{
		os << "{";
		// Loop through the universe 0, 1, 2, ... , (N-1)
		// if e is a element of *this then 
		// print e
		for(uint e = 0 ; e < N ; ++e) {
			if(isMember(e)){
				cnt++;
				if(cnt < cardinality()){
					os << e << ", ";
				} else {
					os << e;
				}
			}
		}
		
		os << "}" << endl;
	}
	return os;
}
	
bool       IntegerSet::isValid(uint e) const  
{
	return 0 <= e && e < N;
}            
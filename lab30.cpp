//Jisoo Choi
//CS 2336
//Lab 30

#include <iostream>
#include <IntegerSet.h>

using namespace std;

void sieveOfEratosthenes(IntegerSet& prime) {
	uint i, j;
	
	for(i = 2; i * i < prime.size(); ++i) {
		if(prime.isMember(i)) {
			for(j = i * 2; j < prime.size(); j += i) {
				prime.reset(j);
			}
		}
			
	}
}

// overloaded output operator for printing IntegerSet set to
// output stream out
/*friend*/ ostream& operator<<(ostream& out, const IntegerSet& set) {
	
	for(uint i = 0 ; i < set.size(); ++i) {
		if(set.isMember(i)) {
			out << i << endl;
			//out << e << '\n';
		}
	}
	
	return out;
}

//Jisoo Choi
//CS 2336
//Lab15

#include <bits.h>

using namespace std;

// printQuaternary is a recursive function that writes the quaternary
// representation of num to output stream os
void printQuaternary(int num, ostream& os) {
	if(num == 0) {
		return;
	}
	else {
		uint unum = static_cast<uint> (num);
		int lsb1 = getBit(unum, 0);
		int lsb2 = getBit(unum, 1);
		int sum = lsb2 * 2 + lsb1;
		
		printQuaternary(unum >> 2, os);
		os << sum;
	}
}
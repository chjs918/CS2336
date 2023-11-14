//Jisoo Choi
//CS 2336
//Lab 16

#include <bits.h>

using namespace std;

// printOctal is a recursive function that writes the octal
// representation of num to output stream os
void printOctal(int num, ostream& os) {
	if(num == 0) {
		return;
	}
	else {
		uint unum = static_cast<uint> (num);
		int lsb1 = getBit(unum, 0);
		int lsb2 = getBit(unum, 1);
		int lsb3 = getBit(unum, 2);
		int sum = lsb3 * 4 + lsb2 * 2 + lsb1;
		
		printOctal(unum >> 3, os);
		os << sum;
	}
}
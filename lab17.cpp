//Jisoo Choi
//CS 2336
//Lab 17

#include <bits.h>

using namespace std;

// printHexadecimal is a recursive function that writes the hexadecimal
// representation of num to output stream os
void printHexadecimal(int num, ostream& os) {
	if(num == 0) {
		return;
	}
	else {
		uint unum = static_cast<uint> (num);
		int lsb1 = getBit(unum, 0);
		int lsb2 = getBit(unum, 1);
		int lsb3 = getBit(unum, 2);
		int lsb4 = getBit(unum, 3);
		int sum = lsb4 * 8 + lsb3 * 4 + lsb2 * 2 + lsb1;
		
		printHexadecimal(unum >> 4, os);
		(sum < 10) ? os << sum : os << static_cast<char> (sum - 10 + 65);
	}
	
	
}
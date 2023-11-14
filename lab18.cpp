//Jisoo Choi
//CS 2336
//Lab 18

#include <bits.h>

using namespace std;

// printBase32 is a recursive function that writes the base32
// representation of num to output stream os
void printBase32(int num, ostream& os) {
	if(num == 0) {
		return;
	}
	else {
		uint unum = static_cast<uint> (num);
		int lsb1 = getBit(unum, 0);
		int lsb2 = getBit(unum, 1);
		int lsb3 = getBit(unum, 2);
		int lsb4 = getBit(unum, 3);
		int lsb5 = getBit(unum, 4);
		int sum = lsb5 * 16 + lsb4 * 8 + lsb3 * 4 + lsb2 * 2 + lsb1;
		
		printBase32(unum >> 5, os);
		(sum < 10) ? os << sum : os << static_cast<char> (sum - 10 + 65);
	}
}
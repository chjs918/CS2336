//Jisoo Choi
//CS 2336
//Lab14

#include <bits.h>
#include <climits>

using namespace std;

void printBinary (int num, ostream& os) {
	if(num == 0)
		return;
	else{
		uint unum = static_cast<uint>(num);
		int lsb = getBit(unum, 0);
		printBinary(unum >> 1, os);
		os << lsb;
	}
}
//Jisoo Choi
//CS 2336
//Lab13

#include <bits.h>

int countOneBits(int num) {
	if (num == 0)	//base case
		return 0;
	else
	{
		uint unum = static_cast<int> (num);
		int lsb = getBit(unum, 0);
		return lsb + countOneBits(unum >> 1);
	}
}
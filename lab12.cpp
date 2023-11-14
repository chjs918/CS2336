//Jisoo Choi 
//CS 2336
//Lab 12

#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

void insertComma(unsigned long num, ostream& os)
{
	if(num < 1000) { //base case
		os << num;
	} else { //general recursive case
		insertComma(num / 1000, os);
		char ch = os.fill(); // save a copy of the fill character
		os << "," << setw(3) << setfill('0') << num % 1000;
		os.fill(ch); //restore the original fill character
	}
}

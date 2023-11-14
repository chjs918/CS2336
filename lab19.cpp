//Jisoo Choi
//CS 2336
//Lab 19

#include <string>

using namespace std;

// isPalindrome is a recursive function that returns true if string s
// is a palindrome and false otherwise
bool isPalindrome(string s) {
	if(s.length() == 0 || s.length() == 1) {
		return true;
	}
	else {
		if(toupper(s[0]) != toupper(s[s.length() - 1]))
			return false;
		
		return isPalindrome(s.substr(1, s.length() - 2));
	}
}

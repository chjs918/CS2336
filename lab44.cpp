//Jisoo Choi
//CS 2336
//Lab 44

#include <cctype>
#include <string>
#include <algorithm>
#include <deque>

using namespace std;

bool isPalindrome(string s) {
	deque <char> d;
	
	transform(s.cbegin(), s.cend(),
			s.begin(), //write to the same location
			[](unsigned char c) {return toupper(c); });
			
	for(uint i = 0; i < s.size();i++) {
		d.push_back(s[i]);
	}
	
	for(uint j = 0; j < d.size(); j++){
		if(d.front() != d.back()) return false;
		d.pop_front();
		d.pop_back();
	}
	
	return true;
}
//Jisoo Choi
//CS 2336
//Lab 39

#include <iostream>
#include <algorithm>
#include <cctype>
#include <string>
#include <stack>

using namespace std;

bool isPalindrome(string s) {
	stack<char> a, b, c;
	
	transform(s.cbegin(), s.cend(),
			s.begin(), //write to the same location
			[](unsigned char c) {return toupper(c); });
			
	for(uint i = 0; i < s.size();i++) {
		a.push(s[i]);
		b.push(s[i]);
	}
	
	//Use b to find the reverse
	for(uint j = 0; j < s.size(); j++){
		c.push(b.top());
		b.pop();
	}
	
	return (a == c) ? true : false;
}

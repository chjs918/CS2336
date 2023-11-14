//Jisoo Choi
//CS 2336
//Lab 42

#include <stack>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

bool isPalindrome(string s) {
	stack<char> stack;
	queue<char> queue;
	
	transform(s.cbegin(), s.cend(),
			s.begin(), //write to the same location
			[](unsigned char c) {return toupper(c); });
	
	for(uint i = 0; i < s.size();i++) {
		stack.push(s[i]);
		queue.push(s[i]);
	}
	
	for(uint j = 0; j < s.size(); j++){
		if(stack.top() != queue.front()) return false;
		stack.pop();
		queue.pop();
	}
	
	return true;
}
//Jisoo Choi
//CS 2336
//Lab 40

#include <string>
#include <stack>

using namespace std;

bool isNestedCorrectly(string s)
{
	stack<char> stack;
	
	for(uint i = 0; i < s.size();i++) {
		char ch = s[i];
		switch (ch) {
			case '(': case '[': case '{':
				stack.push(ch);
				break;
			case ')': case ']': case '}':
				if(stack.empty()) return false;
				else {
					char open_ch = stack.top();
					stack.pop();
					if((open_ch == '(' && ch != ')') || (open_ch == '[' && ch != ']')
												|| (open_ch == '{' && ch != '}')) {
													return false;
												}
				}
				break;
			}
		}
		
	if(!stack.empty()) return false;
	
	return true;
	
}
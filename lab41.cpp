//Jisoo Choi
//CS 2336
//Lab 41

//I don't know why my code stop after infix: A+B*C
//This works well when I enter each command!

#include <string>
#include <stack>
#include <iostream>
#include <cctype>


using namespace std;

bool isoperator(char);
bool hasPrecedenceGreaterThanOrEqualTo(char, char);

// Function infix2Postfix accepts an infix expression and converts to the
// equivalent postfix expression. The postfix expression is written to
// ostream out.
void infix2Postfix(string infix, ostream& out) {
	stack<char> symbols;
	uint i = 0;
	uint size = infix.size();

	do {
		char c = infix[i];
		
		if(isspace(c))
			continue;
		else if(c == '(')
			symbols.push(c);
		else if(isupper(c))
			out << c << ' ';
		else if(isoperator(c)) {
			while(!symbols.empty() && symbols.top() != '(' 
			&& (isoperator(symbols.top()) && hasPrecedenceGreaterThanOrEqualTo(symbols.top(), c)))
			{
				out << symbols.top() << " ";
				symbols.pop();
			}
			symbols.push(c);
		}
		else {
			while(symbols.top() != '(' && !symbols.empty()) {
				out << symbols.top() << " ";
				symbols.pop();
			};
			
			if(symbols.empty()){
					out << "error";
					exit(0);
				}
				
			symbols.pop();
		}
		i++;
	}while (i < size);


	 while(!symbols.empty()) {
		out << symbols.top() << ' ';
		symbols.pop();
	 }
}

bool isoperator(char c) {
	if ((c == '+') || (c == '-') || (c == '*') || (c == '/'))
		return true;
	return false;
}

// Function hasPrecedenceGreaterThanOrEqualTo accepts two character
// parameters, each representing an arithmetic operator (+, -, *, /).
// The function returns true if operator1 has precedence greater than 
// or equal to operator2 and false otherwise.
bool hasPrecedenceGreaterThanOrEqualTo(char operator1, char operator2) {
	if(operator1 == '+') {
		if((operator2 == '*') || (operator2 == '/')) return false;
	} else if(operator1 == '-') {
		if((operator2 == '*') || (operator2 == '/')) return false;
	}
	
	return true;
}
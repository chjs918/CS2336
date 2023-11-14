//Jisoo Choi
//CS 2336
//Lab 31

#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <vector>

using namespace std;

const string ID = "Jisoo Choi - CS 2336 - Lab 31 \n\n";

int main() {
	
	cout << ID;
	cout << "------------------------------------------------------------" << endl;

	string inputLine;
	vector<string> fileNames;
	
	// read an unknown # of lines from the standard input, each
	//containing a single filename
	while (getline(cin, inputLine)) {
		fileNames.emplace_back(inputLine);
	}
	
	//sort the algorithms vector in ascending order
	sort(fileNames.begin(), fileNames.end());
	
	vector<string>::const_pointer ptr, 
		end = fileNames.data() + fileNames.size();
	
	uint F = fileNames.size();
	
	uint L = 0;
	for(ptr = fileNames.data(); ptr < end ; ++ptr){
		if(L < ptr->size())
			L = ptr->size();
	}
	
	uint C = (60 - L) / (L + 2) + 1;
	
	uint R = (F % C == 0) ? (F / C) : (F / C) + 1;
	
	C = (F % R == 0) ? (F / R) : F / R + 1;
	
	
	for(uint i = 0; i < R; i++) {
		for(ptr = fileNames.data() + i; ptr < end; ptr += R)
			cout <<left << setw(L + 2) << *ptr;
		cout << endl;
	}
	
	
	
	
	return 0;
}
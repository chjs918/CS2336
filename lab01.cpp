// Jisoo Choi
// CS 2336
// Lab 01

#include <iostream>
#include <string>

using namespace std;

const string ID = "Jisoo Choi - CS 2336 - Lab01\n\n";

uint productOfDigits(uint num);

int main()
{ 	
	//(uint)
	unsigned int num;
	unsigned int cnt = 0;
	
	//output ID line;
	cout << ID;
	
	//read an unknown # of uints from stdin
	while (cin >> num){
		cout << num;
		do{
			 num = productOfDigits(num);
			 cout << " -> " << num;
			 cnt++;
		} while(productOfDigits(num) != num);
		cout << " persistence = " << cnt << endl;
		cnt = 0;
	}
		
	return 0;
}

uint productOfDigits(uint num) {
	uint product, digit;
	
	product = (num == 0) ? 0 : 1; // ternary/conditional
	
	while (num > 0)
	{
		//Step 1: compute the rightmost digit of num
		digit = num % 10;
		
		//Step2 : incorporate digit into product
		product = product * digit;
		
		//Step3 : eliminate the rightmost digit from num 
		num = num / 10;
	}
	
	
	
	return product;
}
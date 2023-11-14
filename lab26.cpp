//Jisoo Choi
//CS 2336
//Lab 26

#include <vector>

using namespace std;

int meanUsingIndexing(const vector<int>& v) {
	vector<int>::size_type i, end = v.size();
	double sum = 0;
	
	for(i = 0; i < end; ++i) {
		sum += v[i]; // or sum += v.at(i);
	}
	
	return sum;
}

int meanUsingIterators(const vector<int>& v) {
	vector<int>::const_iterator itr, end = v.cend();
	double sum = 0;
	
	for(itr = v.cbegin(); itr < end ; ++itr)
	{
		sum += *itr;
	}
	
	return sum;
}

//pointer is the fastest.
int meanUsingPointers(const vector<int>& v) {
	//data(): A pointer to the first element in the array
	vector<int>::const_pointer ptr, end = v.data() + v.size();
	double sum = 0;
	
	for(ptr = v.data(); ptr < end ; ++ptr) {
		sum += *ptr;
	}

	
	return sum;
}

//Jisoo Choi
//CS 2336
//Lab 27

#include <algorithm> //for sort

template<typename T>
pair<T, int> modeUsingIndexing(const vector<T>& v)
{
	vector<T> copy(v); //copy constructor O(n) (linear)
	
	//sort the copy cector using the builtin sort algorithm
	sort(copy.begin(), copy.end());
	
	typename vector<T>::size_type i, end = copy.size();
	pair<T, int> myMode, tempMode;
	int cnt = 0;
	
	myMode.second = 0;
	tempMode.first = copy[0];
	tempMode.second = 1;
	
	for(i = 0; i < end ; ++i) {
		if(copy[i] != tempMode) {
			cnt = 1;
			tempMode.first = copy[i];
		} else {
			cnt++;
		}
		
		if(cnt > myMode.second) {
			myMode.first = tempMode;
			myMode.second = cnt;
		}
	}
	
	return myMode;
}

template<typename T>
pair<T, int> modeUsingIterators(const vector<T>& v) 
{ 	

	vector<T> copy(v); //copy constructor O(n) (linear)
	
	//sort the copy cector using the builtin sort algorithm
	sort(copy.begin(), copy.end());
	
	typename vector<T>::const_iterator itr, end = copy.end();
	pair<T, int> myMode;
	int cnt = 0;
	
	myMode.second = 0;
	tempMode.first = copy[0];
	tempMode.second = 1;
	
	for(itr = copy.begin(); itr < end ; ++itr) {
		if(*itr != tempMode) {
			cnt = 1;
			tempMode.first = *itr;
		} else {
			cnt++;
		}
		
		if(cnt > myMode.second) {
			myMode.first = tempMode;
			myMode.second = cnt;
		}
	}
	
	return myMode;
	
}

template<typename T>
pair<T, int> modeUsingPointers(const vector<T>& v) {
	vector<T> copy(v); //copy constructor O(n) (linear)
	
	//sort the copy cector using the builtin sort algorithm
	sort(copy.begin(), copy.end());
	
	typename vector<T>::const_pointer ptr, end = copy.data() + copy.size();
	pair<T, int> myMode;
	int cnt = 0;
	
	myMode.second = 0;
	tempMode.first = copy[0];
	tempMode.second = 1;
	
	for(ptr = copy.data(); ptr < end ; ++ptr) {
		if(*ptr != tempMode) {
			cnt = 1;
			tempMode.first = *ptr;
		} else {
			cnt++;
		}
		
		if(cnt > myMode.second) {
			myMode.first = tempMode;
			myMode.second = cnt;
		}
	}
	
	return myMode;
}
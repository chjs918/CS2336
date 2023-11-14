//Jisoo Choi
//CS 2336
//Lab 29

#include <algorithm>

template<typename T>
bool nextPermutation(vector<T>& v) {
	vector<int>::size_type i, j,
					index = -1, index2 = -1;
	
	if(v.size() <= 1) return false;
	
	for(i = v.size() - 2; i >= 0 ; --i) {
		if(v[i] < v[i + 1]) {
			index = i;
			break;
		}
	}
	
	for(j = v.size() - 1; j > index; --j) {
		if(v[j] > v[index]) {
			index2 = j;
			
			swap(v[index], v[index2]);
			reverse(v.begin() + index + 1, v.end());
			
			return true;
		}
	}
	
	reverse(v.begin(), v.end());
	return false;
}

template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
	vector<int>::size_type i;
	
	for(i = 0; i < v.size(); i++) {
		os << v[i];
	}
	
	return os;
}
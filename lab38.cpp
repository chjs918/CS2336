//Jisoo Choi
//CS 2336
//Lab 38

#include <iostream>
#include <cstdlib> // contains prototypes for functions srand and rand
#include <vector>
#include <cmath>

using namespace std;

ostream& operator<<(ostream& os, const vector<uint>& v);

void bucketSort(vector<uint>& v, uint numDigits)
{
	vector<vector<uint>> bucket(10);
	uint k, size = v.size();
	
	for(uint i = 0; i < numDigits; i++) {
		//Distribution Pass
		for(uint j = 0; j < size; j++) {
			k = (v[j] / (uint)pow(10, i)) % 10;
			bucket[k].push_back(v[j]);
		}
		v.clear();
		
		//Gathering Pass
		
		for(uint x = 0 ; x < bucket.size() ; x++) {
			for(uint y = 0; y < bucket[x].size(); y++){
				v.push_back(bucket[x][y]);
			}
			if(!bucket[x].empty())
				bucket[x].clear();
		}
		
		
	}
	
	return;
}
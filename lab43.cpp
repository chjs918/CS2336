//Jisoo Choi
//CS 2336
//Lab 43

#include <iostream>
#include <cstdlib> // contains prototypes for functions srand and rand
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

ostream& operator<<(ostream& os, const vector<uint>& v);

void bucketSort(vector<uint>& v, uint numDigits)
{
	vector<queue<uint>> buckets(10);
	
	uint k, size = v.size();
	
	for(uint i = 0; i < numDigits; i++) {
		//Distribution Pass
		for(uint j = 0; j < size; j++) {
			k = (v[j] / (uint)pow(10, i)) % 10;
			buckets[k].push(v[j]);
		}
		v.clear();
		
		//Gathering Pass
		for(uint x = 0 ; x < buckets.size() ; x++) {
			for(uint y = 0; y < buckets[x].size(); y++){
				v.push_back(buckets[x].front());
				buckets[x].pop();
			}
		
		}
		//cout << v;
		
	}
	
	return;
}
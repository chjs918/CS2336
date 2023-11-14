//Jisoo Choi
//CS 2336
//Lab 49

#include <queue>

template <typename T>
void pqSort(vector<T>& v) {
	priority_queue<T, vector<T>, greater<T>> myPQ; //O(N)
	
	//Loop through the elements of v, pushing each to myPQ
	//N log N
	while(!v.empty()) {
		myPQ.push(v.back());
		v.pop_back();
	}
	
	//Loop through the PQ, pushing the top element from myPQ to the 
	//back of v
	//N log N
	while(!myPQ.empty()) {
		v.push_back(myPQ.top());
		myPQ.pop();
	}
	
	//Total running time = N log N + N log N = 2N log N + N
	
}
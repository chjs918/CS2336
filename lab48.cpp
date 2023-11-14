//Jisoo Choi
//CS 2336
//Lab 48

#include <queue>

using namespace std;

template<typename T>
void distribution(const priority_queue<T>& pq, ostream& os) {
	if(pq.empty()) return;
	
	priority_queue<T> copy(pq);
	T value = copy.top();
	uint cnt = 0;
	
	
	while(!copy.empty()) {
		if(copy.top() != value) {
			os << value << "(" << cnt << ")\n";
			value = copy.top();
			cnt = 1;
		}
		else {
			cnt++;
		}
		copy.pop();
	}
	
	os << value << "(" << cnt << ")\n";
}

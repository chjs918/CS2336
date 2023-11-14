//Jisoo Choi
//CS 2336
//Lab 32

template <typename T>
void exchangeSort(vector<T>& v) {
	typename vector<T>::pointer i, j,
		begin = v.data(),
		end = v.data() + v.size();
	T temp;
		
	for(i = begin ; i < end - 1; i++) {
		for(j = i + 1 ; j < end ; j++) {
			if(*i > *j) {
				temp = *j;
				*j = *i;
				*i = temp;
			}
		}
	}
	
	return;
}
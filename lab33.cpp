//Jisoo Choi
//CS 2336
//Lab 33

template <typename T>
void shellSort(vector<T>& v) {
	uint k, n = v.size(), l;
	typename vector<T>::pointer ptr, begin = v.data(), end = v.data() + v.size();
	
	for(k = 1; k <= n / 9; k = 3 * k + 1){}
	
	while(k > 1) {
		for (uint i = 0; i < k ; i++) {
			vector<T> sublist;
			for(ptr = begin + i; ptr < end ; ptr += k) {
				sublist.emplace_back(*ptr);
			}
			
			insertionSort(sublist);
			
			for(ptr = begin + i, l = 0; ptr < end ; ptr += k, l++){
				*ptr = sublist[l];
			}
		}
		k = k / 3;
	}
	
	insertionSort(v);
}
/*
	Pseudocode for Shell sort
	calculate k 
	for(k = 1; k < = n / 9; k = 3 * k + 1){}

	while(k > 1) {
		loop for i = 0, 1, 2, 3, ..., (k-1)
		{
			create the sublist
			vector<T> sublist;
			
			loop for j = i, i + k, i + 2k,...
				insert v[j] into sublist
			
			insertionSort(sublist)
			
			loop to return the elements from sublist back to v
				back to v
				v[j] = sublist[l]
		} //end loop i
		
		
		k = k / 3;
		
	} // end while k
	
	k will not be one, so call the insertionSort one more time
	insertionSort(v)
*/


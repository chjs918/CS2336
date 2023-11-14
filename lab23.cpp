//Jisoo Choi
//CS 2336
//Lab 23

// function template prototype
template<typename T>
int numDistinct(const T *array, int n) {
	/*iterative 
	const T *outer, *inner, *const end = array + n;
	int distinct = 0;
	
	for(outer = array ; outer < end ; ++outer) {
		for(inner = outer + 1; inner < end ; ++inner) {
			if(*outer == *inner) 
				break;
		}
		
		if(inner >= end)
			++distinct;
	}
	
	return distinct;
	*/
	int e;
	
	if(n <= 1)
		return n;
	else {
		for(e = 1 ; e < n ; ++e) 
			if(*array == *(array + e))
				return numDistinct(array + 1, n - 1);
		
		return 1 + numDistinct(array + 1, n - 1);
	}
}
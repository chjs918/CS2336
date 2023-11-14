//Jisoo Choi
//CS 2336
//Lab 21

// function template prototype
template<typename T>
const T *linearSearch(const T *array, int n, T itemToFind) {
	
	/*iterative 
	const T *ptr, *const endptr = array + n; //can change value, cannot change value
	
	for(ptr = array; ptr < endptr; ++ptr){
		if(*ptr == itemToFind)
			return ptr;
	}
	return nullptr;
	 */
	 
	/*recursive*/
	if(n == 0)
		return nullptr;
	else if(*array == itemToFind)
		return array;
	else
		return linearSearch(array + 1, n - 1, itemToFind);
}
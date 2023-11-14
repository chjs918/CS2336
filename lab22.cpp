//Jisoo Choi
//CS 2336
//Lab 22

// function template prototype
template<typename T>
const T *binarySearch(const T *first, const T *last, T itemToFind) {
	/*iterative 
	const T *middle;
	bool found = false;
	
	while(first <= last && !found) //It is okay to compare pointer.
	{
		//+ has higher operator priority than <<. 
		middle = first + ((last - first) >> 1); //It is more efficient than /2.
		if(itemToFind == *middle) 
			found = true;
		else if(itemToFind < *middle)
			last = middle - 1;
		else
			first = middle + 1;
	}
	
	return found ? middle : nullptr;
	*/
	
	const T *middle;
	
	middle = first + ((last - first) >> 1);
	
	if(last < first)
		return nullptr;
	
	if(*middle == itemToFind)
		return middle;
	else if(itemToFind < *middle)
		return binarySearch(first, middle - 1, itemToFind);
	else
		return binarySearch(middle + 1, last, itemToFind);
	
}

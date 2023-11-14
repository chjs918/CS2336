//Jisoo Choi
//CS 2336
//Lab 34

template<typename T>
void miniVector<T>::insert(int i, const T& item)
// insert item at index i in the vector.
// Precondition vector is not empty and 0 <= i <= vSize.
// Postcondition the vector size increases by 1.
{
	if(vSize == 0 && i != 0)
		throw underflowError("miniVector insert(): vector empty");
	
	if( 0 >	i || i > vSize)
		throw indexRangeError("miniVector insert(): index range error",
									i, vSize);
								
	//call push_back to insert item at the back
	push_back(item);
	
	//Loop to shift the elements of vArr so that position id is free.
	
	for(int j = size() - 2; j >= i ; j--) {
		vArr[j + 1] = vArr[j];
	}
	
	vArr[i] = item;
}

template<typename T>
void miniVector<T>::erase(int i) 
// erase the item at index i in the vector.
// Precondition vector is not empty and 0 <= i < vSize.
// Postcondition the vector size decreases by 1.
{
	if(vSize == 0)
		throw underflowError("miniVector erase(): vector empty");
	
	if( 0 >	i || i >= vSize)
		throw indexRangeError("miniVector erase(): index range error",
									i, vSize);
	
	for(int j = i; j < size() - 1 ; j++) {
		vArr[j] = vArr[j + 1];
	}		

	pop_back();
}


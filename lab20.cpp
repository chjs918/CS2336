//Jisoo Choi
//CS 2336
//Lab 20

//function template prototypes
template<typename T>
void mySwap(T& first, T& second){
	T temp = first;
	first = second;
	second = temp;
}

template<typename T>
void bubbleSort(T *array, int n){
	/*iterative
	int i, j;
	
	for(i = 0; i < n - 1 ; ++i)
		for(j = 0; j < n - i - 1; ++j)
				if(array[j] > array[j + 1])
					mySwap(array[j], array[j + 1]);
	*/
				
		
	 /*recursive*/	
	int i;
	
	if(n <= 0)
		return;
	else{
		
		for(i = 0; i < n - 1 ; ++i){
			if(array[i] > array[i + 1]){
				mySwap(array[i], array[i + 1]);
			}
		}
		bubbleSort(array, n - 1);
	}
}
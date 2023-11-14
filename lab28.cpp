//Jisoo Choi
//CS 2336
//Lab 28

template<typename T>
vector<Frequency<T>> distribution(const vector<T>& v) 
{
	vector<Frequency<T>> myDist;
	typename vector<T>::const_pointer ptr, end = v.data() + v.size();
	typename vector<Frequency<T>>::iterator findItr;
	
	//Loop through the elements of v
	for (ptr = v.data(); ptr < end ; ++ptr) {
		//search for *ptr in myDist using the find algorithms
		findItr = find(myDist.begin(), myDist.end(), *ptr);
		
		if(findItr == myDist.end()) //*ptr was not found (return last)
		{
			myDist.emplace_back(Frequency<T>(*ptr));
		}
		else //did find *ptr in myDist; call increment function
		{
			findItr->increment(); //++1
		}
	}
	return myDist;
}

template<typename T>
ostream& operator<<(ostream& out, const vector<Frequency<T>>& v) {
	typename vector<Frequency<T>>::const_pointer ptr, end = v.data() + v.size();
	
	for (ptr = v.data(); ptr < end ; ++ptr) {
		out << ptr->getValue() << " -> " << ptr->getFrequency() << endl;
	}
	
	return out;
}

template<typename T>
bool Frequency<T>::operator==(const T rhs) const {
	//called by the find algorithm
	return (this->getValue() == rhs);
}

template<typename T>
bool Frequency<T>::operator< (const Frequency<T> rhs) const {
	//called by the sort algorithm
	return (this->getFrequency() < rhs.getFrequency());
}

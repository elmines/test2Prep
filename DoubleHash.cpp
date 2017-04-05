#include<iostream>
using namespace std;

template<typename T>
class DoubleHash
{
	public:
		void put(T e);
		bool remove(T e);
		bool contains(T e);
		bool isEmpty();
		void output();
	
		DoubleHash(int capacity, int (*hash)(T), int (*step)(int, T) );
		~DoubleHash();

	private:
		int capacity, size;
		T* Array;
		bool *Empty;
		bool *usedBefore; //Used to identify slots that have had elements in them at some point
		int (*hash)(T); //Hash function passed in by the user
		int (*step)(int, T); //Secondary hash function passed in by the user
};

template<typename T>
DoubleHash<T>::DoubleHash(int capacity, int (*hash)(T), int (*step)(int, T) )
{
	this->capacity = capacity;
	this->size = 0;
	this->Array = new T[capacity];
	this->Empty = new bool[capacity];
	this->usedBefore = new bool[capacity];
	this->hash = hash;
	this->step = step;

	for (int i = 0; i < capacity; ++i){
		Empty[i] = true;
		usedBefore[i] = false;
	}
}

template<typename T>
DoubleHash<T>::~DoubleHash()
{
	delete[] Array;
	delete[] Empty;
	delete[] usedBefore;
}

template<typename T>
void DoubleHash<T>::put(T e)
{
	if (capacity == size) throw "Hashtable array full.";

	int startingIndex = hash(e);
	int index = startingIndex;
	int i = 1;

	while ( !Empty[index] )
	{
		index = (startingIndex + step(i, e)) % capacity;
		++i;
	}
	Array[index] = e;
	Empty[index] = false;
	usedBefore[index] = true;
	++size;
}
		
template<typename T>
bool DoubleHash<T>::remove(T e)
{
	if (size == 0) return false;

	int startingIndex = hash(e);
	int index = startingIndex;
	int i = 1;
	
	while ( usedBefore[index]  )
	{
		index = (startingIndex + step(i, e)) % capacity;
		++i;
cerr << "i = " << i << endl;
	}
	
	if (e == Array[index]) 
	{
		Empty[index] = true;
		--size;
		return true;
	}
	return false;
}

template<typename T>
bool DoubleHash<T>::contains(T e)
{
	if (size == 0) return false;

	int startingIndex = hash(e);
	int index = startingIndex;
	int i = 1;
	
	while ( usedBefore[index] && (e != Array[index]) )
	{
		index = (startingIndex + step(i, e)) % capacity;
		++i;
	}
	
	if (e == Array[index]) return true;	
	else return false;
}

template<typename T>
bool DoubleHash<T>::isEmpty(){return size == 0;}

template<typename T>
void DoubleHash<T>::output()
{
	cout << '[';
	int i;
	for (i = 0; i < capacity - 1; ++i)
	{
		if (Empty[i]) cout << "EMPTY, ";
		else          cout << Array[i] << ", ";
	}
	if (Empty[i]) cout << "EMPTY";
	else          cout << Array[i];

	cout << "]" << endl;
}


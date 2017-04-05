#include<iostream>
using namespace std;

template<typename T>
class ProbeHash
{
	public:
		void put(T e);
		bool remove(T e);
		bool contains(T e);
		bool isEmpty();
		void output();
	
		ProbeHash(int capacity, int (*hash)(T), int (*step)(int) );
		~ProbeHash();

	private:
		int capacity, size;
		T* Array;
		bool *Empty;
		bool *usedBefore; //Used to identify slots that have had elements in them at some point
		int (*hash)(T); //Hash function passed in by the user
		int (*step)(int); //Step function passed in by the user (could be linear, quadratic, a double hash, etc.)
};

template<typename T>
ProbeHash<T>::ProbeHash(int capacity, int (*hash)(T), int (*step)(int) )
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
ProbeHash<T>::~ProbeHash()
{
	delete[] Array;
	delete[] Empty;
	delete[] usedBefore;
}

template<typename T>
void ProbeHash<T>::put(T e)
{
	if (capacity == size) throw "Hashtable array full.";

	int startingIndex = hash(e);
	int index = startingIndex;
	int i = 1;

	while ( !Empty[index] )
	{
		index = (startingIndex + step(i)) % capacity;
		++i;
	}
	Array[index] = e;
	Empty[index] = false;
	usedBefore[index] = true;
	++size;
}
		
template<typename T>
bool ProbeHash<T>::remove(T e)
{
	if (size == 0) return false;

	int startingIndex = hash(e);
	int index = startingIndex;
	int i = 1;
	
	while ( usedBefore[index]  )
	{
		index = (startingIndex + step(i)) % capacity;
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
bool ProbeHash<T>::contains(T e)
{
	if (size == 0) return false;

	int startingIndex = hash(e);
	int index = startingIndex;
	int i = 1;
	
	while ( usedBefore[index] && (e != Array[index]) )
	{
		index = (startingIndex + step(i)) % capacity;
		++i;
	}
	
	if (e == Array[index]) return true;	
	else return false;
}

template<typename T>
bool ProbeHash<T>::isEmpty(){return size == 0;}

template<typename T>
void ProbeHash<T>::output()
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


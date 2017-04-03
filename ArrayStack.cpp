#include "Stack.h"
#include <iostream>
using namespace std;

template<typename T>
class ArrayStack : public Stack<T>
{
	public:
		ArrayStack(int capacity);
		~ArrayStack();
		void push(T e);
		T pop();
		T peek();
		void output();
		bool isEmpty();

	private:
		int capacity, top;
		T* Array;
};

template<typename T>
ArrayStack<T>::ArrayStack(int capacity)
{
	this->capacity = capacity;
	this->top = 0;
	this->Array = new T[capacity];
}

template<typename T>
ArrayStack<T>::~ArrayStack()
{
	//cout << "Called destructor." << endl;
	delete[] Array;
}

template<typename T>
void ArrayStack<T>::push(T e)
{
	if (top == capacity) throw "ArrayStack full.";

	Array[top] = e;
	++top;
}

template<typename T>
T ArrayStack<T>::pop()
{
	if (top == 0) throw "ArrayStack empty.";

	--top;
	return Array[top];
}

template<typename T>
T ArrayStack<T>::peek()
{
	if (top == 0) throw "ArrayStack empty.";
	return Array[top - 1];
}

template<typename T>
void ArrayStack<T>::output()
{
	if (top == 0)
	{
		cout << "[Empty]" << endl;
		return;
	}

	int i = 0;
	for ( ; i < top - 1; ++i)
	{
		cout << Array[i] << ", ";
	}
	cout << Array[i] << endl;
}	

template<typename T>
bool ArrayStack<T>::isEmpty()
{
	return top == 0;
}

#include "Queue.cpp"

template<typename T>
class ArrayQueue : public Queue<T>
{
	public:
		ArrayQueue(int capacity);
		~ArrayQueue();
		bool enqueue(T e);
		T dequeue();
		T peek();
		bool isEmpty();

	private:
		int capacity, length, front, back;
		T *Array;
};

template<typename T>
ArrayQueue<T>::ArrayQueue(int capacity)
{
	this->length = 0;
	this->capacity = capacity;
	this->Array = new T[capacity];
	this->front = 0; //FIXME: Check that index
	this->back = 0; //FIXME: Check that index
}

template<typename T>
ArrayQueue<T>::~ArrayQueue()
{
//FIXME: Need to delete and end from the proper spots
	for (int i = 0; i < length; ++i) delete Array[i];

	delete[] Array;
}

template<typename T>
bool ArrayQueue<T>::enqueue(T e)
{
	if (length == capacity) return false;

	Array[back] = e;
	back = (back + 1) % capacity;
	++length;
	return true;
}

template<typename T>
T ArrayQueue<T>::dequeue()
{
	if (length == 0) return 0;

	T toReturn = Array[front];
	front = (front + 1) % capacity;
	--length;
	return toReturn;
}

template<typename T>
T ArrayQueue<T>::peek()
{
	if (length == 0) return 0;
	return Array[front];
}

template<typename T>
bool ArrayQueue<T>::isEmpty()
{
	return length == 0;
}


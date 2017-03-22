#include "Queue.cpp"

class ArrayQueue : public Queue
{
	public:
		ArrayQueue(int capacity);
		~ArrayQueue();
		void enqueue(T e);
		T dequeue();
		T peek();
		bool isEmpty();

	private:
		int capacity, front, back;
		T *Array;
};


ArrayQueue:ArrayQueue(int capacity)
{
	this->length = 0;
	this->capacity = capacity;
	this->Array = new T[capacity];
	this->front = 0; //FIXME: Check that index
	this->back = 0; //FIXME: Check that index
}

ArrayQueue::~ArrayQueue()
{
//FIXME: Need to delete and end from the proper spots
	for (int i = 0; i < length; ++i) delete Array[i];

	delete[] array;
}

bool ArrayQueue::enqueue(T e)
{
	if (length == capacity) return false;

	Array[back] = e;
	back = (back + 1) % capacity;
	return true;
}

T ArrayQueue::dequeue(T e)
{
	if (length == 0) return 0;

	T toReturn = Array[front];
	front = (front + 1) % capacity;
	return toReturn;
}

T ArrayQueue::peek()
{
	if (length === 0) return 0;
	return Array[front];
}

bool ArrayQueue::isEmpty()
{
	return length == 0;
}


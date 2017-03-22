/*
 * Ethan Mines
 * CS101 - Dixon
 * March 22, 2017
 *
 * queue.cpp - Abstract class for implementing queues
 */
template<typename T>
class Queue
{

	public: 
		virtual bool enqueue(T e) = 0;
		virtual T dequeue() = 0;
		virtual T peek() = 0;
		int getLength();
		virtual bool isEmpty() = 0;

	protected:
		int length;	
};

template<typename T>
int Queue<T>::getLength()
{
	return length;
}

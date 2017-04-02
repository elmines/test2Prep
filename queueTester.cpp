#include<iostream>
#include "ArrayQueue.cpp"
using namespace std;

int arrayQueueTest()
{

	int capacity = 10, extraItem = 44;
	//Queue<int> line =
	ArrayQueue<int> line(capacity);
	bool result;

	for (int i = 0; i < 10; ++i) line.enqueue( (i + 1) * 5);
	cout << "Added 10 elements to line." << endl;

	cout << "Adding 1 more, which should cause it to exceed capacity." << endl;
	result = line.enqueue(extraItem);
	cout << "Item added: " << result << endl;

	cout << "Outputting the queue from front to back: "; line.output();

	int numDequeues = 3;
	for (int i = 0; i < numDequeues; ++i) line.dequeue();
	cout << "Did " << numDequeues << "dequeues: "; line.output();
	cout << "Peeking at the head: " << line.peek() << endl;

	line.enqueue(extraItem);
	cout << "Enqueued in a new value: "; line.output();

	for (int i = 0; i < capacity - numDequeues + 1; ++i) line.dequeue();
	cout << "Did " << capacity - numDequeues + 1 << " more dequeues." << endl;
	cout << "Empty: " << line.isEmpty() << endl;
	cout << "Peeking: " << line.peek() << endl;
	cout << "Outputting: "; line.output();

	int numNewQueues = 6;
	for (int i = 0; i < numNewQueues; ++i) line.enqueue( (i + 1) * 7);
	cout << "Did " << numNewQueues << " more enqueues." << endl;
	cout << "Empty: " << line.isEmpty() << endl;
	cout << "Peeking: " << line.peek() << endl;
	cout << "Outputting: "; line.output();	

	return 0;
}

int main()
{
	return arrayQueueTest();
}

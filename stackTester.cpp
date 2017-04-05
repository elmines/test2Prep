#include "ArrayStack.cpp"
#include <iostream>
using namespace std;

#include<cstdlib> //For rand
#include<ctime> //For time

int stackTest()
{

	double toDisplay;

	int capacity = 10;

	srand(time(0));
	ArrayStack<double> s(capacity);

	cout << "Stack is empty: " << s.isEmpty() << endl;
	try{
		cout << "Going to peek at the empty stack. . ." << endl;
		s.peek();
	}
	catch(const char* message)
	{
		//message = new char[15];
		//message[0] = 'a';
		cout << message << endl;
	}

	try{
		cout << "Going to pop from the empty stack. . ." << endl;
		s.pop();
	}
	catch(char const* message)
	{
		cout << message << endl;
	}

	cout << ".output() called to empty stack: "; s.output();

	for (int i = 0; i < capacity; ++i) s.push( rand() % 100 + 1);
	cout << "Filled stack: "; s.output();
	cout << "Top of stack: " << s.peek() << endl;
	cout << "Stack is empty: " << s.isEmpty() << endl;

	int numPops = 3;
	ArrayStack<double> t(numPops);
	for (int i = 0; i < numPops; ++i) t.push(s.pop());
	cout << "Popped " << numPops << " elements from the first stack and pushed them onto a new one." << endl;

	cout << "First stack: "; s.output();
		cout << "\tTop of stack: " << s.peek() << endl;
		cout << "\tStack is empty: " << s.isEmpty() << endl;

	cout << "Second stack: "; t.output();
		cout << "\tTop of stack: " << t.peek() << endl;
		cout << "\tStack is empty: " << t.isEmpty() << endl;


	try{
		cout << "Doing " << capacity - numPops + 1 << " pops from my stack of " << capacity - numPops << ", which should generate an exception the last pop." << endl;
		for (int i = 0; i < capacity - numPops + 1; ++i) s.pop();
	}
	catch(const char* message)
	{
		cout << message << endl;
	}

	//toDisplay = s.peek();
	cout << "Cleared stack: "; s.output();
		//cout << "\tTop of stack: " << toDisplay << endl;
		cout << "\tStack is empty: " << s.isEmpty() << endl;

	for (int i = 0; i < capacity / 2; ++i) s.push( rand() % 100 + 1);


	toDisplay = s.peek();
	cout << "Did " << capacity / 2 << " pushes to that empty stack: "; s.output();
		cerr << "\tTop of stack: " << toDisplay << endl;
		cout << "\tStack is empty: " << s.isEmpty() << endl;

	return 0;
}

int main(){ return stackTest();}

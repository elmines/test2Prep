#include "ArrayStack.cpp"
#include <iostream>
using namespace std;

#include<cstdlib> //For rand
#include<ctime> //For time

int stackTest()
{
	int capacity = 10;

	srand(time(0));
	ArrayStack<double> s(capacity);

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

	return 0;
}

int main(){ return stackTest();}

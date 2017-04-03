template<typename T>
class Stack
{
	public:
		virtual void push(T e) = 0;
		virtual T pop() = 0;
		virtual T peek() = 0;
		virtual void output() = 0;
		virtual bool isEmpty() = 0;
};

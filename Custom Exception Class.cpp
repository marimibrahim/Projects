#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cctype>
#include <cmath>

using namespace std;

class StackEmpty {
public:
	StackEmpty() {}
	StackEmpty(string _msg) : msg(_msg) {}
	string get_msg() { return msg; }
protected:
	string msg;
};
class StackFull {
public:
	StackFull() {}
	StackFull(string _msg) : msg(_msg) {}
	string get_msg() { return msg; }
protected:
	string msg;
};
class Stack {
public:
	Stack(int cap = 10);
	Stack(const Stack& in);
	~Stack();
	Stack& operator=(const Stack& in);
	Stack(Stack&& in);
	Stack& operator=(Stack&& in);
	void push(int x)
	{
		if (full())
		{
			throw (StackFull("Full stack\n"));
			exit(1);
		}
		data[head] = x;
		head++;
	}
	int pop()
	{
		if (empty())
		{
			throw (StackEmpty("Empty stack\n"));
		}
		head--;
		return data[head];
	}
	bool empty() { return head == 0; }
	bool full() { return head == capacity; }

private:
	int capacity;
	int* data;
	int head;
};
Stack::Stack(int cap)
{
	capacity = cap;
	data = new int[capacity];
	head = 0;
}
Stack::Stack(const Stack& in)
{
	capacity = in.capacity;
	head = in.head;
	data = new int[capacity];
	for (int i = 0; i < head; i++)
	{
		data[i] = in.data[i];
	}
}
Stack::Stack(Stack&& in)
{
	capacity = in.capacity;
	head = in.head;
	data = in.data;
	in.data = nullptr;
}
Stack::~Stack()
{
	delete[]data;
}
Stack& Stack::operator = (const Stack& in)
{
	if (this == &in)
	{
		return *this;
	}
	if (capacity != in.capacity)
	{
		delete[]data;
		capacity = in.capacity;
		data = new int[capacity];
	}
	head = in.head;
	for (int i = 0; i < head; i++)
	{
		data[i] = in.data[i];
	}
	return *this;
}
Stack& Stack::operator = (Stack&& in)
{
	if (this == &in)
	{
		return *this;
	}
	capacity = in.capacity;
	head = in.head;
	delete[]data;
	data = in.data;
	in.data = nullptr;
	return *this;
}
Stack createStack(int size, int numOfItems)
{
	Stack res(size);
	for (int i = 0; i < numOfItems; i++)
	{
		res.push(i + 1);
	}
	return res;
}
void printStack(Stack stk)
{
	while (!stk.empty())
	{
		cout << stk.pop() << " ";
	}
	cout << endl;
}

int main()
{
	try {
		Stack stk1 = createStack(7, 7);
		for (int i = 0; i < 100; i++)
		{
			cout << stk1.pop() << " ";
		}
	}
	catch (StackEmpty s)
	{
		cout << s.get_msg();
	}
}
#include <iostream>
using namespace std;

class Stack {

public:

	Stack(int cap = 10);

	int& operator[](int index)

	{

		if (index >= 0 and index < head)

			return data[index];

		else

		{

			cout << "Index out of range\n";

			exit(1);

		}

	}

	void push(int x)

	{

		if (full())

		{

			cout << "Full stack\n";

			exit(1);

		}

		data[head] = x;

		head++;

	}

	int pop()

	{

		if (empty())

		{

			cout << "Empty Stack\n";

			exit(1);

		}

		head--;

		return data[head];

	}

	bool empty() {
		return head == 0;
	}

	bool full() {
		return head == capacity;
	}
	Stack(const Stack& rhs);
	Stack& operator=(const Stack& rhs);
	~Stack();

private:

	int capacity;

	int* data;

	int head;

};
Stack::Stack(const Stack& rhs)
{
	capacity = rhs.capacity;
	data = new int[capacity];
	head = rhs.head;

	for (int i = 0; i < head; i++)
	{
		data[i] = rhs.data[i];
	}
}
Stack& Stack::operator=(const Stack& rhs)
{
	if (capacity != rhs.capacity) //revise this
	{
		delete[] data;
		data = new int[capacity]; //new int not =
		capacity = rhs.capacity;
		head = rhs.head;

		for (int i = 0; i < head; i++)
		{
			data[i] = rhs.data[i];
		}

	}

	return *this;
}
Stack::~Stack()
{
	if (data != NULL)
	{
		delete[] data;
		capacity = 0;
		head = 0;
	}
}

Stack::Stack(int cap)

{

	capacity = cap;

	data = new int[capacity];

	head = 0;

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

void printStack(Stack& stk)

{

	while (!stk.empty())

	{

		cout << stk.pop() << " ";

	}

	cout << endl;

}

int main()



{

	Stack stk1 = createStack(7, 5); // Testing the copy constructor

	Stack stk2 = stk1; // Testing the copy constrcutor again

	Stack stk3;

	stk3 = stk2; // Testing the = operator

	stk3[0] = 9999; // setting the first value of stk to 9999

	cout << "Stack 1 : ";
	printStack(stk1);

	cout << "Stack 2 : ";
	printStack(stk2);

	cout << "Stack 3 : ";
	printStack(stk3);

	return 0;

}

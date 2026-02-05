#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cctype>
#include <cmath>

using namespace std;

template<typename T>
class Stack {
public:
	Stack(int cap = 10);
	Stack(const Stack& in);
	~Stack();
	Stack& operator=(const Stack& in);
	Stack(Stack&& in);
	Stack& operator=(Stack&& in);
	void push(T x) {
		if (full()) {
			cout << "Full stack\n";
			exit(1);
		}
		data[head] = x;
		head++;
	}
	T pop() {
		if (empty()) {
			cout << "Empty Stack\n";
			exit(1);
		}
		head--;
		return data[head];
	}
	bool empty() { return head == 0; }
	bool full() { return head == capacity; }

private:
	int capacity;
	T* data;
	int head;
};
template<typename T>
Stack<T>::Stack(int cap) {
	capacity = cap;
	data = new T[capacity];
	head = 0;
}
template<typename T>
Stack<T>::Stack(const Stack& in) {
	capacity = in.capacity;
	head = in.head;
	data = new T[capacity];
	for (int i = 0; i < head; i++) {
		data[i] = in.data[i];
	}
}
template<typename T>
Stack<T>::Stack(Stack&& in) {
	capacity = in.capacity;
	head = in.head;
	data = in.data;
	in.data = nullptr;
}
template<typename T>
Stack<T>::~Stack() { delete[] data; }
template<typename T>
Stack<T>& Stack<T>::operator=(const Stack& in) {
	if (this == &in) {
		return *this;
	}
	if (capacity != in.capacity) {
		delete[] data;
		capacity = in.capacity;
		data = new T[capacity];
	}
	head = in.head;
	for (int i = 0; i < head; i++) {
		data[i] = in.data[i];
	}
	return *this;
}
template<typename T>
Stack<T>& Stack<T>::operator=(Stack&& in) {
	if (this == &in) {
		return *this;
	}
	capacity = in.capacity;
	head = in.head;
	delete[] data;
	data = in.data;
	in.data = nullptr;
	return *this;
}
int main() {
	Stack<string> myStack;
	myStack.push("A");
	myStack.push("b");
	myStack.push("C");
	while (!myStack.empty()) {
		cout << myStack.pop() << endl;
	}
	return 0;
}
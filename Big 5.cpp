#include <iostream>
using namespace std;
#define COPY_CONSTRUCTOR
#define OPERATOREQUAL
class IntArr
{
public:
	//constructors
	IntArr() : size(10) {
		arr = new int[size];
		for (int i = 0; i < size; i++)
			arr[i] = rand() % 100;
	}
	IntArr(int _size) : size(_size) {
		arr = new int[size];
		for (int i = 0; i < size; i++)
			arr[i] = rand() % 100;
	}

	friend ostream& operator<<(ostream& out, const IntArr& a);

	IntArr(const IntArr& rhs);
	IntArr& operator=(const IntArr& rhs);
	~IntArr(); //important has brackets
	IntArr& operator=(IntArr&& rhs);
	IntArr(IntArr&& rhs);
private:
	int* arr; // <---
	int size;
};
//------------------------------------------
//operator= (v5)
ostream& operator<<(ostream& out, const IntArr& a)
{
	for (int i = 0; i < a.size; i++)
	{
		out << a.arr[i] << " | ";
	}
	out << "\n";

	return out;
}
IntArr::IntArr(const IntArr& rhs)
{
	size = rhs.size;
	arr = new int[size];

	for (int i = 0; i < size; i++)
	{
		arr[i] = rhs.arr[i];
	}
}

IntArr& IntArr::operator=(const IntArr& rhs)
{
	if (this == &rhs) //important youll forget
	{
		return *this;
	}

	delete[] arr;
	size = rhs.size;
	arr = new int[size];
	for (int i = 0; i < size; i++)
	{
		arr[i] = rhs.arr[i];
	}
	return *this;
}
IntArr::~IntArr()
{
	if (arr != NULL)
	{
		delete[] arr;
		size = 0;
	}
}
IntArr& IntArr::operator=(IntArr&& rhs)
{
	if (this != &rhs)
	{
		delete[] arr;
		arr = rhs.arr;
		size = rhs.size;
		rhs.arr = NULL;
		rhs.size = 0;
	}
	return *this;
}
IntArr::IntArr(IntArr&& rhs)
{
	arr = rhs.arr;
	size = rhs.size;
	rhs.arr = NULL;
	rhs.size = 0;
}

//------------------------------------------
//--cases in which the copy constructor is called automatically

//Copy constructor is called when the argument in main
//is copied to the parameter in the function 'a'
void funTakesAnIntArrByCopy(IntArr a)
{
	cout << "funTakesAnIntArrByCopy(IntArr a){}\n";
} //'a' goes out of scope => the destructor is called.

IntArr funThatReturnsAnIntArrByCopy()
{
	IntArr rst;
	return rst;
}


//-------------------------------------------
int main()
{
	srand(time(0));

	//if i do not have a copy constructor then
	//C++ will provide me with one, however
	//it will be a shallow-copy version
	//hence we need to implement the copy constructor
	IntArr a, b(7), c(b);

	IntArr c2(b); //this calls the copy constructor not operator=

	cout << "a and b objects are:\n";
	cout << a << b << c << endl;

	//--cases in which the copy constructor is called
	funTakesAnIntArrByCopy(a);
	cout << a << endl; // with a copy constructor

	//--cases in which the copy constructor is called
	IntArr d;
	d = funThatReturnsAnIntArrByCopy();

	cout << d << endl; // with a copy constructor

	//--Operator=
	IntArr e(c);
	a = b = c;
	(a.operator= (b.operator=(c))); //C++ will provide you with a default operator=, but with shallow copy

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;

	a = a = a = a;

	cout << "Done!\n";

	return 0;
}

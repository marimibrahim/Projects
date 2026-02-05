#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cctype>
#include <cmath>

using namespace std;

template<typename T>
class GenericList {
public:
	GenericList() : item(nullptr), max_rows(0), current_rows(0), max_cols(0), current_cols(0) {}
	GenericList(int max_rows, int max_cols);
	GenericList(const GenericList<T>& list);
	GenericList& operator=(const GenericList<T>& list);
	GenericList& operator=(GenericList<T>&& list);
	~GenericList();
	GenericList(GenericList<T>&& list);

	int length() { return current_rows; }
	void add(T new_item);
	bool full() const { return (max_rows == current_rows && max_cols == current_cols); }
	void erase() { current_rows = 0; current_cols = 0; }

	//Friend functions need the prefix
	template<typename T>
	friend ostream& operator<<(ostream& out, const GenericList<T>& list);
private:
	T** item;
	int max_rows;
	int current_rows;
	int max_cols;
	int current_cols;
};

template<typename T>
GenericList<T>::GenericList(int _max_rows, int _max_cols) : max_rows(_max_rows), max_cols(_max_cols), current_rows(0), current_cols(0)
{
	item = new T * [max_rows];
	for (int i = 0; i < max_rows; i++)
	{
		item[i] = new T[max_cols];
	}
}

template<typename T>
GenericList<T>::GenericList(const GenericList<T>& list)
{
	current_rows = list.current_rows;
	current_cols = list.current_cols;
	max_rows = list.max_rows;
	max_cols = list.max_cols;
	item = new T * [max_rows];
	for (int i = 0; i < max_rows; i++)
	{
		item[i] = new T[max_cols];
	}
	for (int i = 0; i < current_rows; i++)
	{
		for (int j = 0; j < current_cols; j++)
		{
			item[i][j] = list.item[i][j];
		}
	}
}

template<typename T>
GenericList<T>::GenericList(GenericList<T>&& list)
{
	current_rows = list.current_rows;
	current_cols = list.current_cols;
	max_rows = list.max_rows;
	max_cols = list.max_cols;
	item = list.item;

	list.current_rows = 0;
	list.current_cols = 0;
	list.max_rows = 0;
	list.max_cols = 0;
	list.item = NULL;
}

template<typename T>
GenericList<T>& GenericList<T>::operator=(GenericList<T>&& list)
{

	item = list.item;
	current_rows = list.current_rows;
	current_cols = list.current_cols;
	max_rows = list.max_rows;
	max_cols = list.max_cols;

	list.current_rows = 0;
	list.current_cols = 0;
	list.max_rows = 0;
	list.max_cols = 0;
	list.item = NULL;
}

template<typename T>
GenericList<T>& GenericList<T>::operator=(const GenericList<T>& list)
{
	if (this == &list)
	{
		return *this;
	}
	if (max_rows != list.max_rows || max_cols != list.max_cols)
	{
		for (int i = 0; i < max_rows; i++)
		{
			delete[] item[i];
		}
		delete[] item;

		max_rows = list.max_rows;
		max_cols = list.max_cols;
		item = new T * [max_rows];
		for (int i = 0; i < max_rows; i++)
		{
			item[i] = new T[max_cols];
		}
	}
	current_rows = list.current_rows;
	current_cols = list.current_cols;
	for (int i = 0; i < current_rows; i++)
	{
		for (int j = 0; j < current_cols; j++)
		{
			item[i][j] = list.item[i][j];
		}
	}
	return *this;
}

template<typename T>
GenericList<T>::~GenericList()
{
	if (item != NULL)
	{
		for (int i = 0; i < max_rows; i++)
		{
			delete[] item[i];
			item[i] = NULL;
		}
		delete[] item;
		item = NULL;
	}
}
template<typename T>
void GenericList<T>::add(T new_item)
{
	if (full())
	{
		cout << "Error: adding to a full list.\n";
		exit(1);
	}
	else
	{
		int r = current_rows;
		int c = current_cols;

		item[current_rows][0] = new_item;

		current_cols++;
		if (current_cols == max_cols) {
			current_cols = 0;
			current_rows++;
		}
	}
}

template<typename T>
ostream& operator<<(ostream& out, const GenericList<T>& list)
{
	for (int i = 0; i < list.current_rows; i++)
	{
		for (int j = 0; j < list.max_cols; j++)
		{
			out << list.item[i][j] << " ";
		}
		out << "\n";
	}
	out << "\n";
	return out;
}

int main()
{
	GenericList<int> row1(1, 1);
	row1.add(1);

	GenericList<int> row2(1, 1);
	row2.add(2);

	GenericList<int> row3(1, 1);
	row3.add(3);

	// Outer matrix of 3x1 lists
	GenericList<GenericList<int>> matrix(3, 1);
	matrix.add(row1);
	matrix.add(row2);
	matrix.add(row3);

	cout << matrix;
	return 0;
}
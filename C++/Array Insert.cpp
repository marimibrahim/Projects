#include <iostream>
using namespace std;

int main()
{
	//declare variables to store the size and the elements of the first array
	int size;
	int* arr;

	//the user inputs the size of the array
	cout << "Enter the array size: ";
	cin >> size;

	//creates a dynamic array
	arr = new int[size];

	//fills the array with random values between 0 and 100
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 101;
	}

	//prints out the array
	cout << "Array before insert:\n";
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}

	//creates a new variable to store the index where the new value will be stored
	int index;
	cout << "\nEnter an index to insert an item at (must be >= 0 and < " << size << "): ";
	cin >> index;

	//validates the index entered by the user to make sure it is within the size
	while (index < 0 || index > size - 1)
	{
		cout << "Enter an index to insert an item at (must be >= 0 and < " << size << "): ";
		cin >> index;
	}

	//creates a new variable to store the new element input by the user
	int new_element;
	cout << "Enter the value of the item to insert: ";
	cin >> new_element;

	//creates a new array to copy the old array's elements and the new element in by increasing its size
	int* new_arr;
	new_arr = new int[size + 1];

	//copies the elements from the old array
	for (int i = 0; i < index; i++)
	{
		new_arr[i] = arr[i];
	}

	new_arr[index] = new_element;

	for (int i = index + 1; i < size + 1; i++)
	{
		new_arr[i] = arr[i - 1];
	}

	//prints out the new array after all elements are copied
	cout << "Array after insert:\n";
	for (int i = 0; i < size + 1; i++)
	{
		cout << new_arr[i] << " ";
	}

	//deletes the dynamic arrays
	delete[] arr;
	delete[] new_arr;

	return 0;
}

#include <iostream>
using namespace std;

//Delete the first occurene of a value in a dynamic array
void fillArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 101;
        cout << "arr[" << i << "] = " << arr[i] << "\n";
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "arr[" << i << "] = " << arr[i] << "\n";
    }
}

int main()
{
    int* arr;
    int size;
    int element;

    cout << "Enter size of array: ";
    cin >> size;

    arr = new int[size];

    fillArray(arr, size);

    cout << "Enter the element you want to delete: ";
    cin >> element;

    int* new_arr;
    new_arr = new int[size - 1];

    bool found = false;

    for (int i = 0; i < size - 1; i++)
    {
        if (arr[i] == element)
        {
            found = true;
        }

        if (found == false)
        {
            new_arr[i] = arr[i];
        }
        else
        {
            new_arr[i] = arr[i + 1];
        }
    }

    printArray(new_arr, size - 1);

    delete[] arr;
    delete[] new_arr;

    return 0;
}

//Delete the last occurence of a value in a dynamic array
void fillArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 101;
        cout << "arr[" << i << "] = " << arr[i] << "\n";
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "arr[" << i << "] = " << arr[i] << "\n";
    }
}

int main()
{
    int* arr;
    int size;
    int element;

    cout << "Enter size of array: ";
    cin >> size;

    arr = new int[size];

    fillArray(arr, size);

    cout << "Enter the element you want to delete: ";
    cin >> element;

    int* new_arr;
    new_arr = new int[size - 1];

    int index;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            index = i;
        }
    }

    for (int i = 0; i < size - 1; i++)
    {
        if (i < index)
        {
            new_arr[i] = arr[i];
        }

        if (i >= index)
        {
            new_arr[i] = arr[i + 1];
        }
    }

    printArray(new_arr, size - 1);

    delete[] arr;
    delete[] new_arr;

    return 0;
}
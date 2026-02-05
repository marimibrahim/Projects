#include <iostream>
using namespace std;


//Add new element at the end of a dynamic array
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

    cout << "Enter size of array: ";
    cin >> size;

    arr = new int[size];

    fillArray(arr, size);
    int new_element;
    int* new_arr;
    new_arr = new int[size + 1];

    cout << "Enter the new element: ";
    cin >> new_element;

    for (int i = 0; i < size; i++)
    {
        new_arr[i] = arr[i];
    }
    new_arr[size] = new_element;

    printArray(new_arr, size + 1);


    delete[] arr;
    delete[] new_arr;

    return 0;
}

//Add new element at the top of a dynamic array
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

    cout << "Enter size of array: ";
    cin >> size;

    arr = new int[size];

    fillArray(arr, size);
    int new_element;
    int* new_arr;
    new_arr = new int[size + 1];

    cout << "Enter the new element: ";
    cin >> new_element;

    new_arr[0] = new_element;
    for (int i = 1; i < size; i++)
    {
        new_arr[i] = arr[i - 1];
    }
    new_arr[size] = arr[size - 1];


    printArray(new_arr, size + 1);


    delete[] arr;
    delete[] new_arr;

    return 0;
}

//Add new element at a certain index of a dynamic array
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

    cout << "Enter size of array: ";
    cin >> size;

    arr = new int[size];

    fillArray(arr, size);
    int new_element;
    int* new_arr;
    new_arr = new int[size + 1];
    int index;

    cout << "Enter the new element: ";
    cin >> new_element;

    cout << "Which index do you want to add it to? ";
    cin >> index;
    while (index < 0 || index > size - 1)
    {
        cout << "Invalid index. Try again. ";
        cin >> index;
    }

    if (index == 0)
    {
        new_arr[0] = new_element;
        for (int i = 1; i < size; i++)
        {
            new_arr[i] = arr[i - 1];
        }
        new_arr[size] = arr[size - 1];
    }
    else if (index == size - 1)
    {
        for (int i = 0; i < size; i++)
        {
            new_arr[i] = arr[i];
        }
        new_arr[size] = new_element;
    }
    else
    {
        for (int i = 0; i < index; i++)
        {
            new_arr[i] = arr[i];
        }
        new_arr[index] = new_element;
        for (int j = index; j < size; j++)
        {
            new_arr[j + 1] = arr[j];
        }
    }

    printArray(new_arr, size + 1);

    delete[] arr;
    delete[] new_arr;

    return 0;
}
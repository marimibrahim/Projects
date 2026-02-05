#include <iostream>
using namespace std;

void swap(int& num1, int& num2)
{
    int temp;
    temp = num2;
    num2 = num1;
    num1 = temp;
}

int indexOfSmallest(int arr[], int size, int start_index)
{
    int min = arr[start_index];
    int min_i = start_index;

    for (int i = start_index + 1; i < size; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
            min_i = i;
        }
    }

    return min_i;
}

void sort(int arr[], int size)
{
    int in_min;
    for (int i = 0; i < size; i++)
    {
        in_min = indexOfSmallest(arr, size, i);
        swap(arr[i], arr[in_min]);
    }
}

int main()
{
    const int SIZE = 10;
    int arr[SIZE];

    for (int i = 0; i < SIZE; i++)
    {
        arr[i] = rand() % 101;
        cout << "arr[" << i << "] = " << arr[i] << "\n";
    }

    sort(arr, SIZE);
    cout << "Sorted array:\n";

    for (int i = 0; i < SIZE; i++)
    {
        cout << "arr[" << i << "] = " << arr[i] << "\n";
    }

    return 0;
}
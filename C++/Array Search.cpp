#include <iostream>
using namespace std;

//Find first occurence
int findOccurence(int arr[], int size, int target)
{
    int index = -1;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] == target)
        {
            index = i;
            break;
        }
    }

    return index;
}

//Find last occurence
int findLastOccurence(int arr[], int size, int target)
{
    int index = -1;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] == target)
        {
            index = i;
        }
    }

    return index;
}

//find all occurences
void findAllOccurences(int arr[], int size, int target, int locations[], int& locations_used)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == target)
        {
            locations[locations_used++] = i;
        }
    }
}

int main()
{
    const int SIZE = 10;
    int arr[SIZE];
    int target;
    int locations[SIZE];
    int locations_used = 0;
    int index;

    for (int i = 0; i < SIZE; i++)
    {
        arr[i] = rand() % 101;
        cout << "arr[" << i << "] = " << arr[i] << "\n";
    }

    cout << "Enter a target: ";
    cin >> target;

    index = findOccurence(arr, SIZE, target);
    if (index == -1)
    {
        cout << "Target not found.";
    }
    else
    {
        cout << "Target found at " << index;
    }

    index = findLastOccurence(arr, SIZE, target);
    if (index == -1)
    {
        cout << "Target not found.";
    }
    else
    {
        cout << "Target last found at " << index;
    }

    findAllOccurences(arr, SIZE, target, locations, locations_used);
    if (locations_used == 0)
    {
        cout << "Target not found";
    }
    else
    {
        cout << "Target found at indexes: ";
        for (int i = 0; i < locations_used; i++)
        {
            cout << locations[i];
        }
    }

    return 0;

}

//Find min and max in an array
int main()
{
    int min, max;
    int min_i, max_i;
    const int SIZE = 10;
    int arr[SIZE];

    for (int i = 0; i < SIZE; i++)
    {
        arr[i] = rand() % 101;
        cout << "arr[" << i << "] = " << arr[i] << "\n";
    }

    min = arr[0];
    max = arr[0];
    min_i = 0;
    max_i = 0;

    for (int i = 1; i < SIZE; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
            min_i = i;
        }
        if (arr[i] > max)
        {
            max = arr[i];
            max_i = i;
        }
    }

    cout << "min = " << min << " at index: " << min_i << "\n";
    cout << "max = " << max << " at index: " << max_i << "\n";

    return 0;
}

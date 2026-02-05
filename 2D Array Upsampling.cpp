#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cctype>
#include <cmath>

using namespace std;

void read2DArray(int** a, int rows, int cols)
{
    // TO DO 1: Read the 2D array {a} with size {rows} by {cols} from the user row by row.
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> a[i][j];
        }
    }
}
void print2DArray(int** a, int rows, int cols)
{
    // TO DO 2: Print the 2D array {a} with size {rows} by {cols} to the user row by row.
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
}

// TO DO 2: develop the upSample function, it should take a pointer to the original array, a pointer to the resulted array, number of rows and number of columns, it should Upsample the original array by 2 and save the upsampled array into the resulted array, remember that the size of the resulted array is (2*number of rows) by (2*number of columns)
void upSample(int** arr, int** upsampled, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            upsampled[2 * i][2 * j] = arr[i][j];
            upsampled[(2 * i) + 1][2 * j] = arr[i][j];
            upsampled[2 * i][(2 * j) + 1] = arr[i][j];
            upsampled[(2 * i) + 1][(2 * j) + 1] = arr[i][j];
        }
    }
}

int main() {
    int** arr;
    int rows, cols;
    cout << "Please enter the array size; rows then cols : ";
    cin >> rows >> cols;
    arr = new int* [rows];
    for (int i = 0; i < rows; i++)
    {
        arr[i] = new int[cols];
    }
    cout << "Please enter " << rows << " rows each with " << cols << " integers :\n";
    read2DArray(arr, rows, cols);
    cout << "You entered :\n";
    print2DArray(arr, rows, cols);

    // TO DO 3: Allocate memory for {upsampled} with size {2*rows} by {2*cols} 
    int** upsampled;
    upsampled = new int* [rows * 2];
    for (int i = 0; i < rows * 2; i++)
    {
        upsampled[i] = new int[cols * 2];
    }
    upSample(arr, upsampled, rows, cols);
    cout << "The Upsampled array is : \n";
    // TO DO 4: Call the function print2DArray to print the upsampled array {upsampled} 
    print2DArray(upsampled, rows * 2, cols * 2);
    for (int i = 0; i < rows; i++)
    {
        delete[]arr[i];
    }
    delete[]arr;
    for (int i = 0; i < 2 * rows; i++)
    {
        delete[]upsampled[i];
    }
    delete[]upsampled;

    return 0;
}
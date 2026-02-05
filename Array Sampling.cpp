#include <iostream>
using namespace std;

int main()
{
    int r, c;
    r = 4;
    c = 4;

    cout << "R is " << r;
    cout << "C is " << c;
    cout << "\n";

    int** arr;
    arr = new int* [r];

    for (int rs = 0; rs < r; rs++)
    {
        arr[rs] = new int[c];
    }

    for (int rs = 0; rs < r; rs++)
    {
        for (int cs = 0; cs < c; cs++)
        {
            arr[rs][cs] = (rand() % 10) + 1;
            cout << arr[rs][cs] << " ";
        }
        cout << "\n";
    }

    int** arr2;
    arr2 = new int* [r / 2];

    for (int rs = 0; rs < r / 2; rs++)
    {
        arr2[rs] = new int[c / 2];
    }

    for (int rs = 0; rs < r / 2; rs++)
    {
        for (int cs = 0; cs < c / 2; cs++)
        {
            arr2[rs][cs] = arr[rs * 2][cs * 2];
            cout << arr2[rs][cs] << " ";
        }
        cout << "\n";
    }

    for (int rs = 0; rs < r; rs++)
    {
        delete[] arr[rs];
    }
    delete[] arr;

    for (int rs = 0; rs < r / 2; rs++)
    {
        delete[] arr2[rs];
    }
    delete[] arr2;

    return 0;
}

Upsampling an array :
#include <iostream>
using namespace std;

int main()
{
    int r, c;
    r = 2;
    c = 2;

    cout << "R is " << r;
    cout << "C is " << c;
    cout << "\n";

    int** arr;
    arr = new int* [r];

    for (int rs = 0; rs < r; rs++)
    {
        arr[rs] = new int[c];
    }

    for (int rs = 0; rs < r; rs++)
    {
        for (int cs = 0; cs < c; cs++)
        {
            arr[rs][cs] = (rand() % 10) + 1;
            cout << arr[rs][cs] << " ";
        }
        cout << "\n";
    }

    int** arr2;
    arr2 = new int* [r * 2];

    for (int rs = 0; rs < r * 2; rs++)
    {
        arr2[rs] = new int[c * 2];
    }

    for (int rs = 0; rs < r; rs++)
    {
        for (int cs = 0; cs < c; cs++)
        {
            arr2[rs * 2][cs * 2] = arr[rs][cs];
            arr2[rs * 2 + 1][cs * 2] = arr[rs][cs];
            arr2[rs * 2][cs * 2 + 1] = arr[rs][cs];
            arr2[rs * 2 + 1][cs * 2 + 1] = arr[rs][cs];
        }
    }

    for (int rs = 0; rs < r * 2; rs++)
    {
        for (int cs = 0; cs < c * 2; cs++)
        {
            cout << arr2[rs][cs] << " ";
        }
        cout << "\n";
    }

    for (int rs = 0; rs < r; rs++)
    {
        delete[] arr[rs];
    }
    delete[] arr;

    for (int rs = 0; rs < r * 2; rs++)
    {
        delete[] arr2[rs];
    }
    delete[] arr2;

    return 0;
}

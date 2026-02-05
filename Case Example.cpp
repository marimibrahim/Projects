#include <iostream>
using namespace std;

void calculate(int x, char op, double& result)
{
    switch (op)
    {
    case '/':
        result = double(x) / 100;
        break;
    case '-':
        result = -x;
        break;
    case '^':
        result = x ^ x;
        break;
    default:
        cout << "Not a valid operator";
    }
}

int main()
{
    int x;
    double result;
    char op;

    cout << "Enter the number: ";
    cin >> x;

    cout << "Enter the operator: ";
    cin >> op;

    calculate(x, op, result);
    cout << "The result = " << result;

    return 0;
}
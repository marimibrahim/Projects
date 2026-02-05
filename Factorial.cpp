#include <iostream>
using namespace std;

int g_num;
int g_product = 1;

void factorial()
{
	int i; //counter in for loop

	for (i = 1; i <= g_num; i++)
	{
		g_product *= i; //calculates the factorial by n(n-1)!
	}
}

int main()
{
	cout << "Enter a number to find its factorial: ";
	cin >> g_num; //the user inputs a number

	factorial(); //the function is called 

	cout << "The factorial of " << g_num << " is: " << g_product; //the factorial is displayed

	return 0;
}
#include <iostream>
using namespace std;

int main() {
	int A, a, B, b, b2, digits, A_digits, digits_found;

	do
	{
		cout << "Enter the first number: ";
		cin >> A; //A is the value entered by the user
		cout << "Enter the second number: ";
		cin >> B; //B is the value entered by the user
	} while (A <= 0 && B <= 0);

	A_digits = A; //A_digits is used to decrement the number of digits in A
	digits = 0; //digits is used to find the number of digits in A
	digits_found = 0; //digits_found is used to compare if the digits in A are in B
	b2 = 0; //b2 is used to decrement the number of digits in B

	while (A_digits != 0)
	{
		A_digits = A_digits / 10;
		digits++;
	}

	while (digits_found != digits && A != 0) //this loops when not all digits are in B and there are still remaining digits in A
	{
		a = A % 10; //extracts the right-most digit
		b2 = B; //temporary value to not alter the value of B, restores b2 to B when the loop runs again
		while (b2 != 0)
		{
			b = b2 % 10; //extracts the right-most digit
			if (b == a)
			{
				digits_found++;
			}
			b2 = b2 / 10; //decreases b2 by a digit
		}
		A = A / 10; //decreases A by a digit
	}

	if (digits_found == digits)
	{
		cout << "All digits in A are in B\n";
	}
	else
	{
		cout << "Not all digits are in B\n";
	}


	return 0;
}
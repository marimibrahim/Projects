#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cctype>
#include <cmath>

using namespace std;

int main()
{
	srand(time(0));
	string s = "Error: Negative number\n";
	// this program will simulate calculating the grades for up to 100 students, the program will stop if any student scored negative number in any exam. 
	for (int i = 0; i < 100; i++)
	{
		cout << "Student " << i + 1 << " grades: ";
		// assume each student will have 4 equally weighted exams 
		float total = 0;
		float exam = 0;
		try {
			for (int j = 0; j < 4; j++)
			{
				exam = rand() % 110 - 10; // range -10 -> 99; 
				cout << exam << " ";
				if (exam < 0)
				{
					throw(s);
				}
				total += exam;
			}
			cout << " Avg: " << total / 4 << endl;
		}
		catch (string e) {
			cout << e;
			exit(0);
		}
	}
}
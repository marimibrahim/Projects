#include <iostream>
#include <string>
#include <cstring>
using namespace std;

void lowerCase(string& s1)
{
    for (int i = 0; i < s1.length(); i++)
    {
        s1[i] = tolower(s1[i]);
    }
}

string nopunct(string s1, string punct)
{
    string s1_nopunct;
    for (int i = 0; i < s1.length(); i++)
    {
        if (punct.find(s1[i]) == -1)
        {
            s1_nopunct = s1_nopunct + s1[i];
        }
    }
    return s1_nopunct;
}

void swap(char& s1, char& s2)
{
    char temp;
    temp = s1;
    s1 = s2;
    s2 = temp;
}

string reverse(string s1)
{
    string s1_reversed = s1;
    int start, end;
    start = 0;
    end = s1.length();

    while (start < end)
    {
        end--;
        swap(s1_reversed[start], s1_reversed[end]);
        start++;
    }
    return s1_reversed;
}

int main()
{
    string s1;
    cout << "Enter s1: ";
    getline(cin, s1);

    lowerCase(s1);
    cout << s1 << "\n";

    string punct = ".,_-'!?<>\" ";
    string s1_nopunct = nopunct(s1, punct);
    cout << s1_nopunct << "\n";

    string s1_reversed = reverse(s1_nopunct);
    cout << s1_reversed;
    if (s1_reversed == s1_nopunct)
    {
        cout << "This is a palindrome";
    }
    else
    {
        cout << "This is not a palindrome";
    }

    return 0;
}

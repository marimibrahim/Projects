#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cctype>
#include <cmath>

using namespace std;

int main()
{
    string line = "In this Fall, we have only 14 weeks of lectures";
    //To-DO a: Add " and labs" at the end of the string, print the {line} to the user
    line.insert(line.length(), " and labs");
    cout << "a - " << line << "\n";

    //To-Do b: Remove " this" from the string; using find and erase, print the {line} to the user
    string to_remove = " this";
    int index = line.find(to_remove);
    line.erase(line.begin() + index, line.begin() + index + to_remove.length());
    cout << "b - " << line << "\n";

    //To-Do c: Insert " 2025" after Fall; using find and insert, print the {line} to the user
    string to_find = "Fall";
    index = line.find(to_find);
    line.insert(index + to_find.length(), " 2025");
    cout << "c - " << line << "\n";

    //To-Do d: Take the text after starting from "we" and save it in {sub_line} string, print the {sub_line} to the user
    index = line.find("we");
    string sub_line = line.substr(index);
    cout << "d - " << sub_line << "\n";

    //To-Do e: Capitalize the first letter in {sub_line}, print the {sub_line} to the user
    sub_line[0] = toupper(sub_line[0]);
    cout << "e - " << sub_line << "\n";


}
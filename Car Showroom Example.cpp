#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cctype>
#include <cmath>

using namespace std;

void addData(vector<string>& names, vector<int>& powers) {
    int size;
    cout << "How many cars do you want to add: ";
    cin >> size;
    int power;
    string name;
    for (int i = 0; i < size; i++) {
        cout << "Please enter the car information in one line; power followed by "
            "the make and the model and the year (example: 581 Mercedes E63 2025) :";
        cin >> power;
        cin.ignore();
        getline(cin, name);

        //To Do #1: Add the name to the names vector and the power to the powers vector. 
        names.push_back(name);
        powers.push_back(power);
    }
}
string toLower(const string& input) {
    //To Do #2: Make a copy of the input string, convert all of its letters to lower case, and return it. 
    string output = input;
    for (int i = 0; i < input.size(); i++)
    {
        output[i] = tolower(input[i]);
    }
    return output;
}
void printAt(const vector<string>& names, const vector<int>& powers, int index) {
    //To Do #3: If the index is outside the range, print “Car is not found”; otherwise, print the car at that index in the format: Name {name_of_the_car_at_index} Power {power_of_the_car_at_index}   
    if (index < 0 || index > names.size())
    {
        cout << "Car is not found\n";
    }
    else {
        cout << "Name {" << names[index] << "} Power {" << powers[index] << "}\n";
    }
}
void printShowroom(const vector<string>& names, const vector<int>& powers) {
    //To Do #4: Using the printAt, print all cars in the showroom
    for (int i = 0; i < names.size(); i++)
    {
        printAt(names, powers, i);
    }
}
int findByName(const vector<string>& names, const string& to_find) {
    //To Do #5: using the strings’ find function, return the index of the name at which the to_find is found. If nothing is found, then return -1. Note: You must use toLower with all of your strings to compare in a non-sensitive manner. 
    int index = -1;
    for (int i = 0; i < names.size(); i++)
    {
        if (toLower(names[i]).find(toLower(to_find)) != -1)
        {
            index = i;
            break;
        }
    }
    return index;
}
bool startsWith(const string& name, const string& starting) {
    //To Do #6: return true if the name starts with starting, hint: use the find function.   Note: You must use toLower with all of your strings to compare in a non-sensitive manner. 
    return (toLower(name).find(toLower(starting)) == 0);
}
bool endsWith(const string& name, const string& ending) {
    //To Do #7: return true if the name ends with ending, hint: use the find function.   Note: You must use toLower with all of your strings to compare in a non-sensitive manner.
    return (toLower(name).find(ending) == (name.size() - ending.size()));
}
string getModel(const string& name)
{
    //To Do #8: extract the model name from the full car name, hint: the model is between the index of the first space and the index of the second space, see how the find function works, you will need to use the substr function to extract the model.  Note: You must use toLower with all of your strings to compare in a non-sensitive manner. 
    int index_of_first_space = name.find(" ");
    string sub_line = name.substr(index_of_first_space + 1);
    int index_of_second_space = sub_line.find(" ");
    string model = sub_line.substr(0, index_of_second_space);
    return model;
}
void removeAt(vector<string>& names, vector<int>& powers, int index) {
    //To Do #9: if index is outside the range, then print “Car is not found” otherwise, delete the car at that index (delete from the names and powers). Hint: you must use the vectors’ erase function here 
    if (index < 0 || index > names.size())
    {
        cout << "Car is not found\n";
    }
    else {
        names.erase(names.begin() + index);
        powers.erase(powers.begin() + index);
    }
}
int getOption()
{
    cout << "---------- My ShowRoom ----------\n";
    cout << "|   1 -> Add Cars               |\n";
    cout << "|   2 -> List All Cars          |\n";
    cout << "|   3 -> Find Car by Name       |\n";
    cout << "|   4 -> List Cars by Make      |\n";
    cout << "|   5 -> List Cars by Model     |\n";
    cout << "|   6 -> List Cars by Year      |\n";
    cout << "|   7 -> Delete Car by Name     |\n";
    cout << "|   8 -> Exit                   |\n";
    cout << "---------------------------------\n";
    int option;
    while (true)
    {
        cout << "Please enter your option: ";
        cin >> option;
        if (option >= 1 && option <= 8)
        {
            return option;
        }
        cout << "Invalid Option, please look at the menu\n";
    }
}
int main()
{
    vector<string> names;
    vector<int> powers;
    while (true)
    {
        int option = getOption();
        if (option == 1)
        {
            //To Do #10 Call the function to add new Cars to our showroom:
            addData(names, powers);
        }
        else if (option == 2)
        {
            //To Do #11 Call the function to print all cars in the showroom        }
            printShowroom(names, powers);
        }
        else if (option == 3)
        {
            string something;
            cout << "Please enter something: ";
            cin >> something;
            //To Do #12 Call the function to find the index of the name that contains `something`, then call another function to print the Car at that index. 
            int index = findByName(names, something);
            if (index == -1)
            {
                cout << "Car is not found\n";
            }
            else {
                printAt(names, powers, index);
            }
        }
        else if (option == 4)
        {
            string make;
            cout << "Please enter Make: ";
            cin >> make;
            for (int i = 0; i < names.size(); i++)
            {
                //To Do #13 if the car name starts with `make` then print that car. 
                if (startsWith(names[i], make))
                {
                    printAt(names, powers, i);
                }
            }
        }
        else if (option == 5)
        {
            string model;
            cout << "Please enter Model: ";
            cin >> model;
            for (int i = 0; i < names.size(); i++)
            {
                //To Do #14 if the model of the car is equal to `model` then print that car 
                if (toLower(getModel(names[i])) == toLower(model))
                {
                    printAt(names, powers, i);
                }
            }
        }
        else if (option == 6)
        {
            string year;
            cout << "Please enter Year: ";
            cin >> year;
            for (int i = 0; i < names.size(); i++)
            {
                //To Do #15 if the car name ends with `year` then print that car. 
                if (endsWith(names[i], year))
                {
                    printAt(names, powers, i);
                }
            }
        }
        else if (option == 7)
        {
            string something;
            cout << "Please enter something: ";
            cin >> something;
            //To Do #16 Call the function to find the index of the name that contains `something`, then call another function to remove the Car at that index.
            int index = findByName(names, something);
            removeAt(names, powers, index);
        }
        else if (option == 8)
        {
            exit(0);
        }
    }
}
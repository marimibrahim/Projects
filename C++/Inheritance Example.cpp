#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cctype>
#include <cmath>

using namespace std;

class Person {
protected:
    string name;
public:
    Person() : name("No name") { cout << "The default constructor of Person is called\n"; }
    Person(string _name) : name(_name) { cout << "The non-default constructor of Person is called\n"; }
    ~Person() { cout << "The destructor of Person is called\n"; };
};

class Employee : public Person {
protected:
    string employer;
public:
    Employee() : Person(), employer("No employer") { cout << "The default constructor of Employee is called\n"; }
    Employee(string _name, string _employer) : Person(_name), employer(_employer) { cout << "The non-default constructor of Employee is called\n"; }
    ~Employee() { cout << "The destructor of Employee is called\n"; };
};

class PartTimeEmployee : public Employee {
public:
    float hourly_rate;
    PartTimeEmployee() : Employee(), hourly_rate(0.0) { cout << "The default constructor of PartTimeEmployee is called\n"; }
    PartTimeEmployee(string _name, string _employer, float _hourly_rate) : Employee(_name, _employer), hourly_rate(_hourly_rate) { cout << "The non-default constructor of PartTimeEmployee is called\n"; }
    ~PartTimeEmployee() { cout << "The destructor of PartTimeEmployee is called\n"; }
};

int main() {
    PartTimeEmployee p1;
    PartTimeEmployee p2("Mariam", "AUS", 20);

    return 0;
}
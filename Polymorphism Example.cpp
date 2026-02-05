#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cctype>
#include <cmath>

using namespace std;

class Vehicle {
public:
	virtual void drive() = 0;
	virtual ~Vehicle() {
		cout << "Destructor of class Vehicle is called\n";
	}
};

class MotorizedVehicle : public Vehicle {
protected:
	string fuel_type;
	float motor_power;
public:
	MotorizedVehicle() : fuel_type("Gasoline"), motor_power(100) {}
	MotorizedVehicle(string _fuel_type, float _motor_power) : fuel_type(_fuel_type), motor_power(_motor_power) {}
	virtual ~MotorizedVehicle() {
		cout << "Destructor of class MotorizedVehicle is called\n";
	}
};

class Car : public MotorizedVehicle {
protected:
	string model;
public:
	Car() : MotorizedVehicle(), model("Unknown") {}
	Car(string _fuel_type, float _motor_power, string _model) : MotorizedVehicle(_fuel_type, _motor_power), model(_model) {}
	virtual ~Car() {
		cout << "Destructor of class Car is called\n";
	}
	virtual void drive() {
		cout << "{" << model << "} Car with {" << fuel_type << "} engine of {" << motor_power << "} hp is driving\n";
	}
};

int main()
{
	Vehicle* v[3];
	v[0] = new Car();
	v[1] = new Car("Gasoline", 80, "Ford T");
	v[2] = new Car("Diesel", 130, "Skoda Octavia");

	for (int i = 0; i < 3; i++)
	{
		v[i]->drive();
	}

	for (int i = 0; i < 3; i++)
	{
		delete v[i];
	}

	return 0;
}
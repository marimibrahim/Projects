#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cctype>
#include <cmath>

using namespace std;

class Movie {
private:
	string ID;
	string name;
	string release_data;

	//one-to-one relationship
	//TO DO 1: create a string director_id to keep the 1-1 relation between Movie and a Director (Staff)
	string director_id;
	//one-to-many relationship
	vector<string> stars_ids;
	//TO DO 2: create a vector of strings stars_ids to keep the 1-n relation between Movie and the Stars (Staff)


public:
	Movie() : ID("None"), name("None"), release_data("None"), director_id("None") {} //TO DO 3: initialize all string variables to “None”,  keep the vector as it is. 

	Movie(string _id, string _name, string _release_data, string _director_id, vector<string> _stars_ids)
		: ID(_id), name(_name), release_data(_release_data), director_id(_director_id), stars_ids(_stars_ids) {
	} //TO DO 4: implement this constructor 

	string get_ID() {
		return ID;
	}//TO DO 5: this function should return the id of the movie
	string get_DirectorID() {
		return director_id;
	}//TO DO 6: this function should return the id of the movie’s director 
	void printInfo() {
		cout << ID << " | " << name << " | " << release_data << " | Director ID: " << director_id;
		cout << "\nStars IDs: ";
		for (int i = 0; i < stars_ids.size(); i++)
		{
			cout << stars_ids[i] << " | ";
		}
		cout << "\n";
	};//TO DO 7: print the movie object information, for the director and stars print only their ids 
	vector<string> getStarsIDs() {
		return stars_ids;
	}//TO DO 8: this function should return the stars id list 
};

class Staff {
private:
	string ID;
	string name;
	string place_of_birth;

public:
	Staff() : ID("None"), name("None"), place_of_birth("None") {}//TO DO 9: initialize all string variables to “None”.
	Staff(string _id, string _name, string _place_of_birth)
		: ID(_id), name(_name), place_of_birth(_place_of_birth) {
	}//TO DO 10: Implement this constructor 
	void printInfo() {
		cout << ID << " | " << name << " | " << place_of_birth << "\n";
	}//TO DO 11: print the staff object information 
	string get_ID() { return ID; }
};
void readStaffFromFile(vector <Staff>& staff_list)
{
	ifstream mycin("staff.txt");
	if (mycin.fail())
	{
		cout << "Can't open staff file\n";
		exit(2);
	}
	int no_staff;
	mycin >> no_staff;

	for (int i = 0; i < no_staff; i++)
	{
		string _id, _name, _place_of_birth;
		mycin >> _id;
		mycin.ignore(1000, '\n');
		getline(mycin, _name);
		getline(mycin, _place_of_birth);

		staff_list.push_back(
			Staff(_id, _name, _place_of_birth)
		);

	}
	mycin.close();
}
void readMoviesFromFile(vector <Movie>& movies_list)
{
	ifstream mycin("movies.txt");
	if (mycin.fail())
	{
		cout << "Can't open movies file\n";
		exit(2);
	}
	int no_movies;
	mycin >> no_movies;
	for (int i = 0; i < no_movies; i++) {
		string _id, _name, _release_data, _director_id;
		mycin >> _id;
		mycin.ignore(1000, '\n');
		getline(mycin, _name);
		mycin >> _release_data;
		mycin >> _director_id;
		int no_staff;
		mycin >> no_staff;
		//read list of staff ids
		vector<string> _stars_list;
		for (int i = 0; i < no_staff; i++) {
			string _staffID;
			mycin >> _staffID;
			_stars_list.push_back(_staffID);
		}
		//Now we have read one movie, add it to the list of movies
		movies_list.push_back(
			Movie(_id, _name, _release_data, _director_id, _stars_list)
		);

	}
	mycin.close();

}

int findStaffByID(vector <Staff> staff_list, string _ID)
{
	//TO DO 12: loop and search for the staff ID in the list of staffs (if not found then return -1)
	for (int i = 0; i < staff_list.size(); i++)
	{
		if (staff_list[i].get_ID() == _ID)
		{
			return i;
			break;
		}
	}
	return -1;
}
//--------------------------------------------------------------------------------
int main()
{
	vector <Movie> movies_list;
	vector <Staff> staff_list;

	readMoviesFromFile(movies_list);
	readStaffFromFile(staff_list);


	vector<string> _listOfStars_IDs;

	for (int d = 0; d < movies_list.size(); d++)
	{
		//print object's information
		cout << "\n-----------------" << "Movie " << movies_list[d].get_ID() << " Information: \n";
		movies_list[d].printInfo();

		cout << "\n\nDirector information:\n";
		int dir_id = findStaffByID(staff_list, movies_list[d].get_DirectorID());
		staff_list[dir_id].printInfo();
		//print detailed employee info for each employee in the department
		cout << "\nStars information:\n";

		//get list of stars IDs
		_listOfStars_IDs = movies_list[d].getStarsIDs();

		//get staff info for each ID from the list of stars (you need a loop here)
		for (int e = 0; e < _listOfStars_IDs.size(); e++)
		{
			int star_index_inList = findStaffByID(staff_list, _listOfStars_IDs[e]);
			if (star_index_inList >= 0)
				staff_list[star_index_inList].printInfo();
			else
				cout << "\nStar: " << _listOfStars_IDs[e] << " is not found!\n";
		}
	}

	return 0;
}

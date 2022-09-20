// Project V - Assignment #2
// Jonah Pearce - September 20th, 2022

#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <iostream>
using namespace std;

// Student data structure
struct STUDENT_DATA {
	string firstname;
    string lastname;
};

int main() {
	
	//Vector for storing all student data
	vector<STUDENT_DATA> data;

	ifstream getFile("StudentData.txt");

	if (getFile.is_open()) {
		string line;
		while (getline(getFile, line)) {
			stringstream getLine(line);

			STUDENT_DATA student;
			// Parsing student data from the files using the commas.
			getline(getLine, student.lastname, ',');
			getline(getLine, student.firstname, ',');

			data.push_back(student);
		}
	}

	return 1;
}





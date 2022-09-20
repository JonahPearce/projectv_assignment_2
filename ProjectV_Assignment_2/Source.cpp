// Project V - Assignment #2
// Jonah Pearce - September 20th, 2022

#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <iostream>
using namespace std;

#define prerelease

#ifdef prerelease
#define Log(x) std::cout << x << "PreRelease" << endl;
#else
#define Log(x) std::cout << x << "Standard" << endl;
#endif

struct STUDENT_DATA {
	string firstname;
    string lastname;
#ifdef prerelease
	string email;
#endif
};

int main() {
	
	//Vector for storing all student data
	vector<STUDENT_DATA> data;
#ifdef prerelease
	ifstream getFile("StudentData_Emails.txt");
#else
	ifstream getFile("StudentData.txt");
#endif
	if (getFile.is_open()) {
		string line;
		while (getline(getFile, line)) {
			stringstream getLine(line);

			STUDENT_DATA student;
			// Parsing student data from the files using the commas.
			getline(getLine, student.lastname, ',');
			getline(getLine, student.firstname, ',');
#ifdef prerelease
			getline(getLine, student.email, ',');
#endif
			data.push_back(student);
		}
	}

#ifdef _DEBUG
	for (int i = 0; i < data.size(); i++) {
		STUDENT_DATA readStudent = data.at(i);
#ifdef prerelease
		cout << "Name: " << readStudent.firstname << " " << readStudent.lastname << " " << readStudent.email << endl;
#else
		cout << "Name: " << readStudent.firstname << " " << readStudent.lastname << endl;
#endif	
	}
#endif 

	Log("The program is running ")

	return 1;
}





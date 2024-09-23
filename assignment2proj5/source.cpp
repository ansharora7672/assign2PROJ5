#include <iostream>
using namespace std;
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

struct STUDENT_DATA {
	string firstname;
	string lastname;
};

int main() {

	ifstream file("StudentData.txt");

	vector<STUDENT_DATA> student_data;
	string line;

	while (getline(file, line))
	{
		istringstream iss(line);
		STUDENT_DATA student;
		getline(iss, student.firstname, ',');
		getline(iss, student.lastname);
		student_data.push_back(student);
	}

	file.close();

	return 1;

}
#include <iostream>
using namespace std;
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

struct STUDENT_DATA {
	string firstname;
	string lastname;
	string email;
};

int main() {

#ifdef PRE_RELEASE
	cout << "Running in Pre-Release mode." << endl;
#else
	cout << "Running in Standard mode." << endl;
#endif

	ifstream file("..\\StudentData.txt");

	

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

#ifdef _DEBUG
	for (int i = 0; i < student_data.size(); ++i)
	{
		cout << "First Name: " << student_data[i].firstname << ", Last Name: " << student_data[i].lastname << endl;
	}
#endif


#ifdef PRE_RELEASE
	ifstream file2("..\\StudentData_Emails.txt");

	 size_t index = 0;
	while (getline(file2, line) && index < student_data.size()) {
		istringstream iss(line);
		string email;
		getline(iss, email, ',');
		cout << "First Name: " << student_data[index].firstname << ", Last Name: " << student_data[index].lastname << ", Email: " << email << endl;
		index++;
	}

	file2.close();

#endif


	return 1;

}
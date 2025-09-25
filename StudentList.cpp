#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

struct Student {
	char firstName[100];
	char lastName[100];
	int ID;
	float GPA;
};
int main(){
	//Basic var instantiation
	char command[100];
	char fName[100];
	char lName[100];
	int inputID;
	float GPA;
	vector<Student*> studentList;

	//Valid Command prompts
	char del[] = "DELETE";
	char print[] = "PRINT";
	char add[] = "ADD";
	char quit[] = "QUIT";

	while (true){
		//Command parsing and prompting
		cin >> command;
		command[6] = '\0';

		//Command recognition
		if (strcmp(command, del) == 0){
			cout << "Delete command initiated" << endl;
		}
		else if (strcmp(command, print) == 0) {
			cout << "Print command initiated" << endl;

			for (Student* element : studentList){
				cout << "\nFirst Name: " << element->firstName << endl;
				cout << "Last Name: " << element->lastName << endl;
				cout << "Student ID: " << element->ID << endl;
				cout << "Student GPA: " << element->GPA << endl;
				cout << endl;
			}
		}
		else if (strcmp(command, add) == 0){

			cout << "Add command initiated" << endl;

			Student *createdStudent = new Student();

			cout << "First name: ";
			cin >> fName;
			cout << "\nLast name: ";
			cin >> lName;
			cout << "\nStudent ID: ";
			cin >> inputID;
			cout << "\nStudent GPA: ";
			cin >> GPA;
			
			strcpy(createdStudent->firstName,fName);
			strcpy(createdStudent->lastName,lName);
			createdStudent->ID = inputID;
			createdStudent->GPA = GPA;

			studentList.push_back(createdStudent);

			cout << "Student Created!" << endl;
		}
		else if (strcmp(command, quit) == 0){
			cout << "Quit command initiated. Program off." << endl;
		}
		else {
			cout << "Command prompt unrecognized." << endl;
		}
	}
	

	return 0;
}

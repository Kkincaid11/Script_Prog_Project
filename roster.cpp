#include "roster.h"
#include "student.h"
#include <iostream>
#include <sstream>
using namespace std;



const static int classRosterSize = 5;  

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, 
					int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degreeProgram)
{
	int daysInCourse[3] = {daysInCourse1, daysInCourse2, daysInCourse3};

	for (int i = 0; i < classRosterSize; i++) {
		if (classRosterArray[i] == nullptr) {
			if (degreeProgram == NETWORK) {
				classRosterArray[i] = new NetworkStudent(studentID, firstName, lastName, emailAddress, age, daysInCourse, degreeProgram);
			}
			else if (degreeProgram == SECURITY) {
				classRosterArray[i] = new SecurityStudent(studentID, firstName, lastName, emailAddress, age, daysInCourse, degreeProgram);
			}
			else if (degreeProgram == SOFTWARE) {
				classRosterArray[i] = new SoftwareStudent(studentID, firstName, lastName, emailAddress, age, daysInCourse, degreeProgram);
			}
		}
		else {
			cout << "Degree Program not found." << endl;
			}
			}
		}


void Roster::printAll()
{
	for (int i = 0; i < classRosterSize; i++) {
		if (classRosterArray[i] != nullptr) {
		classRosterArray[i]->print();
		}
	}
}


void Roster::printInvalidEmails(){
	for (int i = 0; i < classRosterSize; i++) {
		string email = classRosterArray[i]->getEmailAddress();
		int emailLength = sizeof(email);

		for (i = 0; i < emailLength; i++){

			cout << "Invalid emails: " << endl;

			if (email.find("@") == -1) { 
				cout << email << endl;
			}
			else if (email.find(".") == -1){
				cout << email << endl;
			}
			else if (email.find(" ") != std::string::npos){ 
				cout << email << endl;
			}
		}

	}
}

 
void Roster::printByDegreeProgram(int degreeProgram) {

	for (int i = 0; i < classRosterSize; i++) {
		if (classRosterArray[i]->getDegreeProgram() == degreeProgram) {
			classRosterArray[i]->print();
			cout << endl;
		}
	}
 };


void Roster::printDaysInCourse(string studentID){
		int i;
	for (int i = 0; i < classRosterSize; i++) {
		
		int* daysInCourse = classRosterArray[i]->getDaysInCourse();
		
		if (classRosterArray[i]->getStudentID() == studentID){
     		 cout << "Average days in a course: " << (daysInCourse[0] + daysInCourse[1] 
			  + daysInCourse[2]) /3 << endl;
		}
	}
	
 };


void Roster::remove(string studentID) {
	
	for (int i=0; i < classRosterSize; i++) { 
		if (classRosterArray[i] != nullptr && classRosterArray[i]->getStudentID() == studentID) {
				classRosterArray[i] = nullptr;
				cout << "Student " << studentID << "removed from roster." << endl;
			
		}
		else cout << "ERROR: " << studentID << "not found." << endl;

	}
	
	
 };


Roster::Roster(){
};

Roster::~Roster(){
}; 




void Roster::parseAdd(string row)
{	
	int i;
	
for (i = 0; i < classRosterSize; i++){
		classRosterArray[i]++;
	if (i < classRosterSize){

	int rhs = row.find(",");
	string studentID = row.substr(0, rhs);

	int lhs = rhs+1;
	rhs = row.find(",", lhs);
	string firstName = row.substr(lhs, rhs-lhs);

	lhs = rhs+1;
	rhs = row.find(",", lhs);
	string lastName = row.substr(lhs, rhs-lhs);
	
	lhs = rhs+1;
	rhs = row.find(",", lhs);
	string emailAddress = row.substr(lhs, rhs-lhs);
	
	lhs = rhs+1;
	rhs = row.find(",", lhs);
	int age = stod(row.substr(lhs, rhs-lhs));

	lhs = rhs+1;
	rhs = row.find(",", lhs);
	double daysInCourse1 = stod(row.substr(lhs, rhs-lhs));

	lhs = rhs+1;
	rhs = row.find(",", lhs);
	double daysInCourse2 = stod(row.substr(lhs, rhs-lhs));

	lhs = rhs+1;
	rhs = row.find(",", lhs);
	double daysInCourse3 = stod(row.substr(lhs, rhs-lhs));

	lhs = rhs+1;
	rhs = row.find(",", lhs);
        
        Degree dd;
	string d = row.substr(lhs, rhs-lhs);
		if (d == "SOFTWARE") {dd = SOFTWARE;}
		else if (d == "SECURITY") {dd = SECURITY;}
		else if (d == "NETWORK") {dd = NETWORK;}
		else {
			cout << "ERROR: INVALID PROGRAM TYPE" << endl;
		}
		
		
	add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, dd);
}
	else {
		cout << "ERROR: MAX CAPACITY REACHED" << endl;
	}
}
}




int main() {
 
        cout << "Scripting and Programming Appilications - C867" << endl;
        cout << "C++" << endl;
        cout << "Student ID: 000948018"  << endl;
        cout << "Kaitlyn Kincaid" << endl;

        
const string studentData[] =
 {
    "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
    "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
    "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
    "A5,Kaitlyn,Kincaid,kkinc15@wgu.edu,26,10,15,22,SOFTWARE"
 };

Roster classRoster; 


cout << "Parsing and adding students." << endl;
for (int i = 0; i < classRosterSize; i++) 
{
    classRoster.parseAdd(studentData[i]);
}
cout << "Displaying all books." << endl;

//From instructions
	classRoster.printAll();
	cout << endl;

	classRoster.printInvalidEmails();
	cout << endl;

	for (int i = 0; i < classRosterSize; i++){
		classRoster.printDaysInCourse(classRoster.classRosterArray[i]->getStudentID());
	}
	cout << endl;

	cout << "Software students: " << endl;
	classRoster.printByDegreeProgram(SOFTWARE);
	cout << endl;

	classRoster.remove("A3");
	cout << "Student removed." << endl;
	classRoster.remove("A3");

	classRoster.~Roster();

	return 0;
};
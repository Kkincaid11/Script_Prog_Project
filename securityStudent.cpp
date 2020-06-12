#include "securityStudent.h"
using namespace std;
#include <iostream>


SecurityStudent::SecurityStudent() : Student() {
            this->degreeProgram = SECURITY;
}

SecurityStudent::SecurityStudent(string studentID, string firstName, string lastName, string emailAddress,
	                int age, int daysInCourse[], Degree deg) : Student(studentID, firstName, lastName, emailAddress, age, daysInCourse)
                    {
            this->degreeProgram = deg;
}

Degree SecurityStudent::getDegreeProgram(){
    return this->degreeProgram;
}

void SecurityStudent::setDegreeProgram(Degree degreeProgram){
    this->degreeProgram = SECURITY;
}

void SecurityStudent::print(){
    this->Student::print();
    cout << "SECURITY" << endl;
}


SecurityStudent::~SecurityStudent(){
    Student::~Student();
};
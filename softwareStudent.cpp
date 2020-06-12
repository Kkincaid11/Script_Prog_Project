#include "softwareStudent.h"
using namespace std;
#include <iostream>


SoftwareStudent::SoftwareStudent() : Student(){
    this->degreeProgram = SOFTWARE;
}; 

SoftwareStudent::SoftwareStudent(string studentID, string firstName, string lastName, string emailAddress, int age, 
int daysInCourse[], Degree deg) : Student(studentID, firstName, lastName, emailAddress, age, daysInCourse)
 {
this->degreeProgram = deg;
 }

Degree SoftwareStudent::getDegreeProgram(){
    return this->degreeProgram; 
};

void SoftwareStudent::setDegreeProgram(Degree degreeProgram){
    this->degreeProgram = SOFTWARE;
}

void SoftwareStudent::print(){
    this->Student::print();
    cout << "SOFTWARE" << endl;
}

SoftwareStudent::~SoftwareStudent(){
    Student::~Student();
};
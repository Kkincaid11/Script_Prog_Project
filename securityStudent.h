#pragma once
#include "student.h"
#include <iostream>
using namespace std;


class SecurityStudent : public Student {

public:
	SecurityStudent();

	SecurityStudent(
		string studentID,
		string firstName,
		string lastName,
		string emailAddress,
		int age,
		int* daysInCourse,
		Degree deg
	); 
	
	void print();
	Degree getDegreeProgram(); //overrides virtual method in Student
	
	void setDegreeProgram(Degree degreeProgram);

	~SecurityStudent();

private: 
    Degree degreeProgram;

};


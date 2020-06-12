#pragma once
#include "student.h"
#include <iostream>
using namespace std;

class SoftwareStudent : public Student {

public:
	SoftwareStudent();

	SoftwareStudent(
		string studentID,
		string firstName,
		string lastName,
		string emailAddress,
		int age,
		int* daysInCourse,
		Degree deg
	); 
	
	void print();
	Degree getDegreeProgram();
	
	void setDegreeProgram(Degree degreeProgram);
        
	~SoftwareStudent();
    
private: 
    Degree degreeProgram;

};

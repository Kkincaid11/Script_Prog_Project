#pragma once
#include "student.h"
#include <iostream>
using namespace std;



class NetworkStudent : public Student { //inheriting from Student class

public:
	NetworkStudent();
	
	NetworkStudent(
		string studentID,
		string firstName,
		string lastName,
		string emailAddress,
		int age,
		int* daysInCourse,
		Degree deg
	); 
	
	void print(); //implements virtual print
	Degree getDegreeProgram(); //overrides vitrual method

	void setDegreeProgram(Degree degreeProgram); 
	
	~NetworkStudent();


private: 
    Degree degreeProgram;

};



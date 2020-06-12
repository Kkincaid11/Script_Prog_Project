#pragma once
#include "degree.h"
#include <iostream>
using namespace std;


class Student{

    public:
        const static int daysInCourseArraySize = 3;

    protected:
        string studentID;
        string firstName;
        string lastName; 
        string emailAddress;
        int age;
        int daysInCourse[daysInCourseArraySize];

        
    public:
    Student(); //empty constructor

        Student(string studentID, string firstName, string lastName, string emailAddress, 
        int age, int daysInCourse[]); //full constructor
        
        //getters
        string getStudentID();
        string getFirstName();
        string getLastName();
	string getEmailAddress();
        int getAge();
        int* getDaysInCourse(); //pointer as it is an array
        virtual Degree getDegreeProgram() = 0; //this class will not implement degreeProgram, subclasses will

	//setters
        void setStudentID(string studentID); //passing in nothing (void)
        void setFirstName(string firstName);
        void setLastName(string lastName);
        void setEmailAddress(string emailAddress);
        void setAge(int age);
        void setDaysInCourse(int daysInCourse[]);


        virtual void print(); 


~Student(); //destructor


};


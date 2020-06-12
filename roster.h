#pragma once
#include <iostream>
#include "student.h"
#include "securityStudent.h"
#include "softwareStudent.h"
#include "networkStudent.h"
using namespace std;

class Roster {
    
    public: 
        const static int classRosterSize = 5; 
        const static int studentDataMax = 9; //capacity - max data elements for each student
        
        Roster();
        Roster(int classRosterSize); //sets max size
        
        Student* classRosterArray[classRosterSize]; 

        void parseAdd(string row);
        void add(string studentID, string firstName, string lastName, string emailAddress, 
        int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degreeProgram);
        void printAll();
        void printByDegreeProgram(int degreeProgram);
        void printDaysInCourse(string studentID);
        void printInvalidEmails();
	void remove(string studentID);
    
        ~Roster();  


};


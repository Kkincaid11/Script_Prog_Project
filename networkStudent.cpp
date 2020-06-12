#include "networkStudent.h"
using namespace std;



NetworkStudent::NetworkStudent() : Student() {
    this->degreeProgram = NETWORK;
}

NetworkStudent::NetworkStudent(string studentID, string firstName, string lastName, string emailAddress,
	                int age, int daysInCourse[], Degree deg) : Student(studentID, firstName, lastName, emailAddress, age, daysInCourse)
            {
                this->degreeProgram = deg;
            }

Degree NetworkStudent::getDegreeProgram(){
    return this->degreeProgram;  
}

void NetworkStudent::setDegreeProgram(Degree degreeProgram){
    this->degreeProgram = NETWORK;
}

void NetworkStudent::print(){
    this->Student::print(); 
    cout << "NETWORK" << endl;
}


NetworkStudent::~NetworkStudent(){
    Student::~Student();
};



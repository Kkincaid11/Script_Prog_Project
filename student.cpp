#include "degree.h"
#include "student.h"
#include <iostream>
using  namespace std;



Student::Student() //empty constructor - sets to default values
{
    this -> studentID = "";
    this -> firstName = "";
    this -> lastName = "";
    this -> emailAddress = "";
    this -> age = 0; 
    for (int i=0; i < daysInCourseArraySize; i++) this->daysInCourse[i] = 0;
};


Student::Student(string studentID, string firstName, string lastName, string emailAddress, 
    int age, int daysInCourse[]) //full constructor
{
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->age = age;
    for (int i=0; i < daysInCourseArraySize; i++) this -> daysInCourse[i] = daysInCourse[i];
}

       void Student::setStudentID(string studentID){ //mutator/setter
            this->studentID = studentID;
       }
       string Student::getStudentID()  { //accessor/getter
           return studentID;
       }

      void Student::setFirstName(string firstName){
            this->firstName = firstName;
       }
       string Student::getFirstName()  {
           return firstName;
       }
       
        void Student::setLastName(string lastName){
            this->lastName = lastName;
       }
       string Student::getLastName()  {
           return lastName;
       }

        void Student::setEmailAddress(string emailAddress){
            this->emailAddress = emailAddress;
       }
       string Student::getEmailAddress()  {
           return emailAddress;
       }

        void Student::setAge(int age){
            this->age = age;
       }
       int Student::getAge()  {
           return age;
       }

        void Student::setDaysInCourse(int daysInCourse[]){
            for (int i = 0; i < daysInCourseArraySize; i++)
                this->daysInCourse[i] = daysInCourse[i];
       }
       int* Student::getDaysInCourse()  {
           return daysInCourse;
       }


//do not need a getter for degreeProgram, set in roster.cpp

void Student::print() {
    
    cout << studentID << "\t";
    cout << firstName << "\t";
    cout << lastName << "\t"; 
    cout << age << "\t";
    cout << daysInCourse[0] << "\t";
    cout << daysInCourse[1] << "\t";
    cout << daysInCourse[2] << "\t";

    // INSTRUCTIONS say to leave the implementation of getDegreeProgram empty  
};

Student::~Student(){ //destructor

    };
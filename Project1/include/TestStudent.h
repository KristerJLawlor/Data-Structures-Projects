//TestStudent.h
//Krister Lawlor
//COP-4415 Sec. 2
//Last Date of Modification: 10/18/2021
//This is the test file for the Student class and their member functions

#ifndef TESTSTUDENT_H_INCLUDED
#define TESTSTUDENT_H_INCLUDED

#include <iostream>
#include<ios>
#include<string>
#include<stdint-gcc.h>
#include<fstream>
#include<limits>
#include "Person.h"
#include "Student.h"


using namespace std;

/////////////////////////////TEST FUNCTIONS/////////////////////////////////

//Function to Test the Student Class
void TestStudent()
{
    Student S(4000, "TestStudent", 25, 16, 5, 3.5);
    cout<<S;
    S.addCourse("H", "H", 3, 90);
    S.addCourse("Y", "Y", 2, 80);
    S.addCourse("Z", "Z", 1, 70);
    S.printCourses();
    S.deleteCourse("H");
    S.deleteCourse("Y");
    S.deleteCourse("Z");
    S.printCourses();
    S.addCourse("H", "H", 3, 90);
    S.addCourse("Y", "Y", 2, 80);
    S.addCourse("Z", "Z", 1, 70);
    cout<<S;
}


#endif // TESTSTUDENT_H_INCLUDED

//TestCourse.h
//Krister Lawlor
//COP-4415 Sec. 2
//Last Date of Modification: 10/18/2021
//This is the test file for the Course class and their member functions

#ifndef TESTCOURSE_H_INCLUDED
#define TESTCOURSE_H_INCLUDED

#include <iostream>
#include<ios>
#include<string>
#include<stdint-gcc.h>
#include<fstream>
#include<limits>
#include "Person.h"
#include "Student.h"
#include "Course.h"


using namespace std;

/////////////////////////////TEST FUNCTIONS/////////////////////////////////

//Function to Test the Course Class
void TestCourse()
{
    Course C("Underwater BasketWeaving", "BSK2300", 2, 26.4);
    cout<<C;
    C.setAll("Fencing", "FNC4000", 3, 88.7);
    cout<<C;
}


#endif // TESTCOURSE_H_INCLUDED

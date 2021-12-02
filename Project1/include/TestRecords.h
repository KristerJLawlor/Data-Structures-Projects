//TestRecords.h
//Krister Lawlor
//COP-4415 Sec. 2
//Last Date of Modification: 10/18/2021
//This is the test file for the Records class and their member functions

#ifndef TESTRECORDS_H_INCLUDED
#define TESTRECORDS_H_INCLUDED


#include <iostream>
#include<ios>
#include<string>
#include<stdint-gcc.h>
#include<fstream>
#include<limits>
#include "Person.h"
#include "Student.h"
#include "Course.h"
#include "Records.h"

using namespace std;

/////////////////////////////TEST FUNCTIONS/////////////////////////////////

//Function to Test the Record Class
void TestRecord(Records R)
{

    R.deleteStudent(100); //Should say list is empty
    R.addStudent(100, "James Tiberius Kirk", 32, 15, 4, 3.3);
    R.addStudent(200, "Doctor Doolittle", 41, 16, 5, 3.9);
    R.addStudent(300, "Schmitty Van WergermanJensen", 79, 12, 4, 1);
    R.printSingleRecord(300);
    R.printAllRecords();
    R.deleteStudent(200);
    uint32_t UID;
        cout << "Give UID of Student you wish to add Course: " << endl;
        cin>>UID;
        R.addCourseToStudent(UID);
    R.printAllRecords();
}

#endif // TESTRECORDS_H_INCLUDED

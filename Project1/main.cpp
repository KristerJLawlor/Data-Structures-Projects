//Main.cpp
//Krister Lawlor
//COP-4415 Sec. 2
//Last Date of Modification: 10/19/2021

//This is the Main file for the Data Structures Project 1.
//It is designed to implement the Course and Student Linked Lists through the creation of an instance of the Records class.

//This program loads Course and Student data from the included .csv files and adds them to the StudentRecords object of the Records class.
//Then, the user is given an interface where they can choose to

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
#include "TestPerson.h"
#include "TestStudent.h"
#include "TestCourse.h"
#include "TestRecords.h"


using namespace std;

/////////////////////////////CSV FILE READER FUNCTIONS///////////////////////////////////

//read default.csv file
void readDefaultCSV(Records &StudentRecords)
{
    cout << "Opening File default.csv" << endl;
// File pointer
    fstream fin;

    // Open an existing file
    fin.open("default.csv", ios::in);

   //variables needed to read data to to pass to addStudent
   std::ifstream file;
   std::string inputstream;
    uint32_t UID;
    std::string name;
    uint8_t age;
    uint32_t totalCreditHours;
    uint32_t numberOfCourses;
    double GPA;

    //read the file comma by comma, while saving data to variables
    while(getline(fin, inputstream,','))
    {
       //read and store inputs after converting to correct data type
       UID = stoi(inputstream);
       getline(fin, inputstream,',');

       name = inputstream;
       getline(fin, inputstream,',');
       age = stoi(inputstream);

       getline(fin, inputstream,',');
       totalCreditHours = stoi(inputstream);

       getline(fin, inputstream,',');
       numberOfCourses = stoi(inputstream);

       getline(fin, inputstream,'\n');
       GPA = stod(inputstream);
       //Create new student using read variables
       StudentRecords.addStudent(UID, name, age, totalCreditHours, numberOfCourses, GPA);

    }
    return;

}


//read coursesDefaults.csv file
void readcoursesDefaultsCSV(Records &StudentRecords)
{
    cout << "Opening File coursesDefaults.csv" << endl;
// File pointer
    fstream fin;

    // Open an existing file
    fin.open("coursesDefaults.csv", ios::in);

   //variables needed to read data to to pass to addStudent
   std::ifstream file;
   std::string inputstream;
    uint32_t UID;
    std::string title;
    std::string code;
    uint8_t creditHour;
    double grade;

    //read the file comma by comma, while saving data to variables
    while(getline(fin, inputstream,','))
    {
       //read and store inputs after converting to correct data type
       UID = stoi(inputstream);

       getline(fin, inputstream,',');
       code = inputstream;

       getline(fin, inputstream,',');
       title = inputstream;

       getline(fin, inputstream,',');
       creditHour = stoi(inputstream);

       getline(fin, inputstream,'\n');
       grade = stod(inputstream);
       //Create new student using read variables
       StudentRecords.addCourseToStudent(UID, title, code, creditHour, grade);

    }
    return;

}


////////////////////////////////////MAIN FUNCTION//////////////////////////////////////


int main()
{
    //Create the Student Records object
    Records StudentRecords;
    //Create user input variable
    char userinput;


    //Test Functions (unused)
    //TestPerson();
    //TestStudent();
    //TestCourse();
    TestRecord(StudentRecords);


    //Open the csv files and read their data
    readDefaultCSV(StudentRecords);
    readcoursesDefaultsCSV(StudentRecords);

    while(userinput != '0')
    {

        //print the UI selection screen
        cout << "\tWelcome to FLPoly Simple Student Record System" << endl <<
        "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;

        cout << "Please Select One of the Following: " << endl <<
            "\t[1] Print All Records" << endl <<
            "\t[2] Print Record for a Single Student" << endl <<
            "\t[3] Add a Student" << endl <<
            "\t[4] Delete a Student" << endl <<
            "\t[5] Add a Course to a Student" << endl <<
            "\t[6] Delete a Course from a Student" << endl <<
            "\t[0] To exit Program" << endl <<
            "\nEnter Your Selection: " ;

        //Take user input
        userinput = getchar();

        //to print all records
        if(userinput == '1')
        {
            cout << "Printing All Records" << endl;
            StudentRecords.printAllRecords();
            cout << "Average GPA: " << StudentRecords.getAverageGPA() << endl;
            cout << "Number of Students: " << StudentRecords.getNumberOfStudents() << endl;
        }

        //to print record for a student
        if(userinput == '2')
        {
            uint32_t UID;
            cout << "Give UID of Student you wish to print: " << endl;
            cin>>UID;
            StudentRecords.printSingleRecord(UID);
        }

        //add a student
        if(userinput == '3')
        {
            uint32_t UID;
            std::string name;
            uint32_t age;   //changed to uint32_t instead of uint8_t to fix output errors
            uint32_t totalCreditHours;
            uint32_t numberOfCourses;
            double GPA;
            cout << "Enter the details of the student: " << endl;
            cout << "Enter Student UID: " << endl;
            cin >> UID;
            cin.sync();
            cout << "Enter Student Name: " << endl;
            getline(cin, name);
            cin.sync();
            cout << "Enter Student Age: " << endl;
            cin >> age;
            cin.sync();
            cout << "Enter Total Credit Hours: " << endl;
            cin >> totalCreditHours;
            cin.sync();
            cout << "Enter Number of Courses: " << endl;
            cin >> numberOfCourses;
            cin.sync();
            cout << "Enter Student GPA: " << endl;
            cin >> GPA;
            cin.sync();
            StudentRecords.addStudent(UID, name, age, totalCreditHours, numberOfCourses, GPA);

        }

        //delete a student
        if(userinput == '4')
        {
            uint32_t UID;
            cout << "Give UID of Student you wish to remove: " << endl;
            cin>>UID;
            cin.sync();
            StudentRecords.deleteStudent(UID);
        }

        //add course to a student
        if(userinput == '5')
        {
            uint32_t UID;
            cout << "Give UID of Student you wish to add Course: " << endl;
            cin>>UID;
            cin.sync();
            StudentRecords.addCourseToStudent(UID);


        }

        //delete course from a student
        if(userinput == '6')
        {
            uint32_t UID;
            cout << "Deleting Course from Student" << endl;
            cout << "Give UID of Student for Course: ";
            cin >> UID;
            cin.sync();
            StudentRecords.deleteCourseFromStudent(UID);
        }
        cin.sync();
        cout << "\n\n\n" ;
        cin.sync();
    }
    return 0;
}



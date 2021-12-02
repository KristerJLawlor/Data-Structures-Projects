//Records.cpp
//Krister Lawlor
//COP-4415 Sec. 2
//Last Date of Modification: 10/18/2021

//This is the file for defining the constructors and functions for the Records class
//The Records class also doubles as a doubly linked list that holds containers of Student class instances (where Student holds instances of Courses)

#include "Student.h"
#include <iostream>
#include<string>
#include<stdint-gcc.h>
#include "Records.h"

//default constructor
Records::Records()
{
    averageGPA = 0;
    numberOfStudents = 0; //length
    students = nullptr; //head
    tail = nullptr;  //tail
}

//destructor
Records::~Records()
{
    //dtor
}


//adds one student to the total
void Records::updateNumberOfStudents()
{
    this->numberOfStudents = this->getNumberOfStudents() + 1;
}


//get total number of students
uint32_t Records::getNumberOfStudents() const
{
    return numberOfStudents;
}


//calculate the average GPA
double Records::getAverageGPA() const
{
    return averageGPA/numberOfStudents;
}


//add a student node to the list by passing Student parameters to the Student constructor through the Records class
void Records::addStudent(uint32_t UID, std::string name, uint8_t age, uint32_t totalCreditHours, uint32_t numberOfCourses, double GPA)
{
    //increment # of students when adding a new student
    if(students != nullptr)
    {
        tail->setNext(new Student(UID, name, age, totalCreditHours, numberOfCourses, GPA));
        tail->getNext()->setPrevious(tail);
        tail = tail->getNext();
        numberOfStudents++;
        this->averageGPA = averageGPA + GPA;
        std::cout << "---------------------------------------------" << std::endl;
        std::cout << "Successfully Added Student" << std::endl;
        std::cout << "---------------------------------------------" << std::endl;
    }
    else
    {
        students = new Student(UID, name, age, totalCreditHours, numberOfCourses, GPA);
        tail = students;
        //increment student count
        numberOfStudents++;
        //update the averageGPA, which is the total GPA
        this->averageGPA = averageGPA + GPA;
        std::cout << "---------------------------------------------" << std::endl;
        std::cout << "Successfully Added Student" << std::endl;
        std::cout << "---------------------------------------------" << std::endl;
    }


}



//deletes node that matches the University ID
void Records::deleteStudent(uint32_t UID)
{
    if(students == nullptr)
    {
        std::cout << "---------------------------------------------" << std::endl;
        std::cout << "List is Empty" << std::endl;
        std::cout << "---------------------------------------------" << std::endl;
        return;
    }

    //check if the head contains the UID we're searching for
    if(students->getUID() == UID)
    {
        Student* T = students;
        students = students->getNext();
        if(students != nullptr)
        {
            students->setPrevious(nullptr);
        }
        //remove 1 student
        numberOfStudents--;
        //remove the GPA held by this student
        this->averageGPA = averageGPA - T->getGPA();
        delete T;
        std::cout << "---------------------------------------------" << std::endl;
        std::cout << "Successfully Deleted Student" << std::endl;
        std::cout << "---------------------------------------------" << std::endl;
    }
    else
    {
        //Assume the UID is somewhere in the list
        Student* A = students;  //temporary pointer
        Student* B = A->getNext(); //node pointer to be deleted
        while(A->getNext() != nullptr)
        {
            if(A->getNext()->getUID() == UID)
            {
                A->setNext(B->getNext());
                if(A->getNext() != nullptr)
                {
                    A->getNext()->setPrevious(A);
                }
                else
                {
                    tail = A;
                }
                //remove 1 student
                numberOfStudents--;
                //remove the GPA held by this student
                this->averageGPA = averageGPA - B->getGPA();
                delete B;
                std::cout << "---------------------------------------------" << std::endl;
                std::cout << "Successfully Deleted Student" << std::endl;
                std::cout << "---------------------------------------------"  << std::endl;
                break;
            }
            A = A->getNext();
            B = B->getNext();
        }
    }
}


//set the tail of the doubly linked list
void Records::setTail(Student* tail)
{
    this->tail = tail;
}


//get the tail pointer of the doubly linked list
Student* Records::getTail()
{
    return tail;
}


//set the head of the doubly linked list
void Records::setHead(Student* head)
{
    this->students = head;
}


//get the head of doubly linked list
Student* Records::getHead()
{
    return students;
}


//Print all the Student records
void Records::printAllRecords()
{
    Student* T = students;
    //print out records until T is null
    while(T != nullptr)
    {
        std::cout << "------------------STUDENT--------------------"  << std::endl;
        std::cout << "UID: " << unsigned(T->getUID()) << std::endl;
        std::cout << "Name: " << T->getName() << std::endl;
        std::cout << "Age: " << unsigned(T->getAge()) << std::endl;
        std::cout << "GPA: " << T->getGPA() << std::endl;
        std::cout << "Number of Courses: " << +T->getnumberOfCourses() << std::endl;
        std::cout << "Total Credit Hours: " << +T->gettotalCreditHours() << std::endl;
        std::cout << " "  << std::endl;
        std::cout << "------------------COURSES--------------------"  << std::endl;
        T->printCourses();
        std::cout << " "  << std::endl;
        T = T->getNext();
    }
    //T = students;
    //std::cout<<*T;
}


//Print the record of a single student
void Records::printSingleRecord(uint32_t UID)
{

    Student* T = students;
    //If no student exists or cannot be found
        if(T == nullptr)
        {
            std::cout << "---------------------------------------------" << std::endl;
            std::cout << "Student Not Found" << std::endl;
            std::cout << "---------------------------------------------" << std::endl;
            return;
        }
    while(T != nullptr)
    {
        if(T->getUID() == UID)
        {
            std::cout << "------------------STUDENT--------------------"  << std::endl;
            std::cout << "UID: " << unsigned(T->getUID()) << std::endl;
            std::cout << "Name: " << T->getName() << std::endl;
            std::cout << "Age: " << unsigned(T->getAge()) << std::endl;
            std::cout << "Total Credit Hours: " << +T->gettotalCreditHours() << std::endl;
            std::cout << "GPA: " << T->getGPA() << std::endl;
            std::cout << "Number of Courses: " << +T->getnumberOfCourses() << std::endl;
            std::cout << " "  << std::endl;
            std::cout << "------------------COURSES--------------------"  << std::endl;
            T->printCourses();
            std::cout << " "  << std::endl;
        }
        T = T->getNext();
    }
}


//Pass UID to find student you want to add class to
void Records::addCourseToStudent(uint32_t UID)
{
    Student* T = students;
    std::string title;
    std::string code;
    uint8_t creditHour;
    double grade;
    //loop through the linked list and check if student with UID is found
    while(T != nullptr)
    {
        if(T->getUID() == UID)
        {
            std::cin.sync();
            std::cout << "Enter Course Title: " << std::endl;
            getline(std::cin, title);
            std::cin.sync();
            std::cout << "Enter Course Code: " << std::endl;
            getline(std::cin, code);
            std::cin.sync();
            std::cout << "Enter Course Credit: " << std::endl;
            std::cin >> creditHour;
            std::cin.sync();
            std::cout << "Enter Course Grade: " << std::endl;
            std::cin >> grade;
            std::cin.sync();
            //create course object attached to this student
           T->addCourse(title, code, creditHour, grade);
           return;
        }
        T = T->getNext();

    }
        //If no student exists or cannot be found
        if(T == nullptr)
        {
            std::cout << "---------------------------------------------" << std::endl;
            std::cout << "Student Not Found" << std::endl;
            std::cout << "---------------------------------------------" << std::endl;
            return;
        }
}


//add course to student by uid from the .csv file
void Records::addCourseToStudent(uint32_t UID, std::string title, std::string code, uint8_t creditHour, double grade)
{
    Student* T = students;
    //loop through the linked list and check if student with UID is found
    while(T != nullptr)
    {
        if(T->getUID() == UID)
        {
            //create course object attached to this student
           T->addCourse(title, code, creditHour, grade);
           return;
        }
        T = T->getNext();

    }
        //If no student exists or cannot be found
        if(T == nullptr)
        {
            std::cout << "---------------------------------------------" << std::endl;
            std::cout << "Student Not Found" << std::endl;
            std::cout << "---------------------------------------------" << std::endl;
            return;
        }
}


//Find student by UID and then call deleteCourse from Student class with the Course code
void Records::deleteCourseFromStudent(uint32_t UID)
{
    Student* T = students;
    std::string code;
    //loop through the linked list
    while(T != nullptr)
    {
        if(T->getUID() == UID)
        {

            std::cout << "Enter Course Code of Course you wish to Remove: " << std::endl;
            std::cin >> code;

           T->deleteCourse(code);
           return;
        }
        T = T->getNext();

    }
        //If no student exists or cannot be found
        if(T == nullptr)
        {
            std::cout << "---------------------------------------------" << std::endl;
            std::cout << "Student Not Found" << std::endl;
            std::cout << "---------------------------------------------" << std::endl;
            return;
        }
}



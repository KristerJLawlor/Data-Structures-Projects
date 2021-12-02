//Course.h
//Krister Lawlor
//COP-4415 Sec. 2
//Last Date of Modification: 10/13/2021

//This is the header file to prototype all the data members and functions for the Student Class.
//The Student class implements a singly linked list of type Courses, which are tied to each individual student.
//Therefore, each student (object) has their own singly linked list that contains Course nodes.

#include <iostream>
#include<stdint-gcc.h>
#include<string>
#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"
#include "Course.h"


class Student : public Person
{

    public:
        //double GPA;
    //Data members
    protected:
        uint32_t totalCreditHours;
        uint32_t numberOfCourses;
        uint32_t UID;
        double GPA;
        Course* courses; //will be the head pointing to NULL until a course object is added
        Student* next;  //will point to next
        Student* previous;  //will point to previous
    public:
        //Constructors
        Student();
        Student(uint32_t UID, double GPA);
        Student(uint32_t UID, std::string name, uint8_t age, uint32_t totalCreditHours, uint32_t numberOfCourses, double GPA);
        Student(uint32_t totalCreditHours, uint32_t numberOfCourses, uint32_t UID, double GPA, Student* next, Student* previous);
        virtual ~Student();


        //Member functions
        uint32_t gettotalCreditHours() const;
        void settotalCreditHours(uint32_t creditHours);

        void setnumberOfCourses(uint32_t numberOfCourses);
        uint32_t getnumberOfCourses() const;

        uint32_t getUID() const;
        void setUID(uint32_t UID);

        double getGPA() const;
        void setGPA(double GPA);

        void addCourse(std::string title, std::string code, uint8_t creditHour, double grade); //pass course data to function then pass function parameters to the constructor of Course class then set the next.
        void deleteCourse(std::string code);

        //linked list functions
        Student* getNext();
        void setNext(Student* next);
        Student* getPrevious();
        void setPrevious(Student* previous);
        void printCourses();


//operator overload to auto-print values when putting object next to <<
friend std::ostream& operator<<(std::ostream& os, Student& S)
{
    std::cout << "UID: " << unsigned(S.getUID()) << std::endl;
    std::cout << "Name: " << S.getName() << std::endl;
    std::cout << "GPA: " << S.getGPA() << std::endl;
    std::cout << "Number of Courses: " << +S.getnumberOfCourses() << std::endl;
    std::cout << "Total Credit Hours: " << +S.gettotalCreditHours() << std::endl;
    S.printCourses();
    // write S to stream
    return os;
}

};

#endif // STUDENT_H

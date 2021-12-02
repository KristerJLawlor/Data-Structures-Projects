//Records.h
//Krister Lawlor
//COP-4415 Sec. 2
//Last Date of Modification: 10/18/2021

//This is the header file to prototype all the data members and functions for the Records Class
//The Records class acts as a handler for the Course and Student/Person classes. It contains a doubly linked list
//that holds Students, where Students hold Courses.

#include <iostream>
#include<stdint-gcc.h>
#include<string>
#ifndef RECORDS_H
#define RECORDS_H
#include "Student.h"

class Records
{
    public:
        uint32_t numberOfStudents; //length
        double averageGPA;

    protected:
        Student* students; //head
        Student* tail;  //tail

    public:
        Records();
        virtual ~Records();

        void addNumberOfStudents(uint32_t numberOfStudents);
        uint32_t getNumberOfStudents() const;

        void addAverageGPA(double averageGPA);
        double getAverageGPA() const;

        void updateNumberOfStudents();

        void addStudent(uint32_t UID, std::string name, uint8_t age, uint32_t totalCreditHours, uint32_t numberOfCourses, double GPA);
        void deleteStudent(uint32_t UID);
        void addCourseToStudent(uint32_t UID);
        void addCourseToStudent(uint32_t UID, std::string title, std::string code, uint8_t creditHour, double grade);
        void deleteCourseFromStudent(uint32_t UID);

        void setTail(Student* tail);
        Student* getTail();
        void setHead(Student* head);
        Student* getHead();

        void printAllRecords();
        void printSingleRecord(uint32_t UID);


//operator overload to auto-print values when putting object next to <<
friend std::ostream& operator<<(std::ostream& os, const Records& rec)
{
    // write rec to stream
    os << "Average GPA: " << rec.getAverageGPA() << std::endl;
    os << "Number of Students: " << unsigned(rec.getNumberOfStudents()) << std::endl;
    return os;
}
};


#endif // RECORDS_H

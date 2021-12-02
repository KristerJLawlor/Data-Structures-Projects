//Course.h
//Krister Lawlor
//COP-4415 Sec. 2
//Last Date of Modification: 10/13/2021

//This is the header file to prototype all the data members and functions for the Course Class
//The Course class also doubles as a container/Node to a linked list for each individual student instance
#include <iostream>
#include<string>
#include<stdint-gcc.h>
#ifndef COURSE_H
#define COURSE_H


class Course
{
    protected:
        //Data members
        std::string title;
        std::string code;
        uint8_t creditHour;
        double grade;
        Course* next;  //will point to the next Course

    public:
        //Constructors
        Course();
        Course(std::string title, std::string code, uint8_t creditHour, double grade);
        Course(std::string title, std::string code, uint8_t creditHour, double grade, Course* next);
        virtual ~Course();


        //Get and Set functions
        void setAll(std::string title, std::string code, uint8_t creditHour, double grade);
        std::string getTitle() const;
        void setTitle(std::string title);
        std::string getCode() const;
        void setCode(std::string code);
        uint8_t getCreditHour() const;
        void setCreditHour(uint8_t creditHour);
        double getGrade() const;
        void setGrade(double grade);
        Course* getNext();
        void setNext(Course* next);


//operator overload to auto-print values when putting object next to <<
friend std::ostream& operator<<(std::ostream& os, Course& C)
{
    std::cout << "Course Title: " << C.getTitle() << std::endl;
    std::cout << "Course Code: " << C.getCode() << std::endl;
    std::cout << "Credit Hour: " << +C.getCreditHour() << std::endl;
    std::cout << "Grade: " << C.getGrade() << std::endl;
    // write C to stream
    return os;
}

};

#endif // COURSE_H

//Course.cpp
//Krister Lawlor
//COP-4415 Sec. 2
//Last Date of Modification: 10/13/2021

//This is the file for defining the constructors and functions for the Course class
//The Course class also doubles as a container/Node to a linked list for each individual student instance
#include <iostream>
#include<string>
#include<stdint-gcc.h>
#include "Course.h"


//Define the constructors
Course::Course()
{
    title = "unknown";
    code = "unknown";
    creditHour = 0;
    grade = 0;
    next = nullptr;
}

Course::Course(std::string title, std::string code, uint8_t creditHour, double grade)
{
    this->title = title;
    this->code = code;
    this->creditHour = creditHour;
    this->grade = grade;
    next = nullptr;
}

//destructor
Course::~Course()
{
    //dtor
}

//Define the class functions
    void Course::setAll(std::string title, std::string code, uint8_t creditHour, double grade)
    {
        this->title = title;
        this->code = code;
        this->creditHour = creditHour;
        this->grade = grade;
        next = nullptr;
    }

    //get title string
    std::string Course::getTitle() const
    {
        return title;
    }

    //set title string
    void Course::setTitle(std::string title)
    {
        this->title = title;
    }

    //get course code string
    std::string Course::getCode() const
    {
        return code;
    }

    //set course code string
    void Course::setCode(std::string code)
    {
        this->code = code;
    }

    //get credit hour value
    uint8_t Course::getCreditHour() const
    {
        return creditHour;
    }

    //set credit hour value
    void Course::setCreditHour(uint8_t creditHour)
    {
        this->creditHour = creditHour;
    }

    //get the grade value
    double Course::getGrade() const
    {
        return grade;
    }

    //set the grade value
    void Course::setGrade(double grade)
    {
        this->grade = grade;
    }

    //get pointer to next node in the list
    Course* Course::getNext()
    {
        return next;
    }

    //set pointer to next node in list
    void Course::setNext(Course* next)
    {
        this->next = next;
    }

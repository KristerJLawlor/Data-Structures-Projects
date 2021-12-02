//Student.cpp
//Krister Lawlor
//COP-4415 Sec. 2
//Last Date of Modification: 10/15/2021

//This is the file for defining the constructors and functions for the Student class
//The Student class holds a linked list of Courses and acts as a Node for the Records class

#include <iostream>
#include<string>
#include<stdint-gcc.h>
#include "Student.h"
#include "Course.h"
//Constructors
Student::Student()
{
    totalCreditHours = 0;
    numberOfCourses = 0;
    UID = 0;
    GPA = 0;
    courses = nullptr;
    next = nullptr;
    previous = nullptr;
}

Student::Student(uint32_t UID, double GPA)
{
    totalCreditHours = 0;
    numberOfCourses = 0;
    this->UID = UID;
    this->GPA = GPA;
    courses = nullptr;
    next = nullptr;
    previous = nullptr;
}



Student::Student(uint32_t UID, std::string name, uint8_t age, uint32_t totalCreditHours, uint32_t numberOfCourses, double GPA)
{
    this->totalCreditHours = totalCreditHours;
    this->numberOfCourses = numberOfCourses;
    this->UID = UID;
    this->GPA = GPA;
    setName(name);
    setAge(age);
    courses = nullptr;
    next = nullptr;
    previous = nullptr;
}


//destructor
Student::~Student()
{   }


//Member functions
//get total credit hours value
uint32_t Student::gettotalCreditHours() const
{
        return totalCreditHours;
}

//set the total credit hours value
void Student::settotalCreditHours(uint32_t totalCreditHours)
{
        this->totalCreditHours = totalCreditHours;
}

//set the number of courses
void Student::setnumberOfCourses(uint32_t numberOfCourses)
{
        this->numberOfCourses = numberOfCourses;
}

//get the number of courses taken
uint32_t Student::getnumberOfCourses() const
{
    return numberOfCourses;
}

//retrieve UID
uint32_t Student::getUID() const
{
        return UID;
}

//set the UID value
void Student::setUID(uint32_t UID)
{
        this->UID = UID;
}

//get student GPA
double Student::getGPA() const
{
        return GPA;
}

//set student GPA
void Student::setGPA(double GPA)
{
        this->GPA = GPA;
}

//Add a course by taking course object values and creating a new Course object and setting it to next
void Student::addCourse(std::string title, std::string code, uint8_t creditHour, double grade)
{

    if(courses != nullptr)
    {
        //make temporary head pointer
        Course* T;
        T = courses;
        //Cycle through the list until reaching the end
        while(T->getNext() != nullptr)
         {
           T = T->getNext();
         }
         //Add course to the next to replace nullptr
         T->setNext(new Course(title, code, creditHour, grade));
         this->numberOfCourses++;
            std::cout << "---------------------------------------------" << std::endl;
            std::cout << "Successfully Added Course" << std::endl;
            std::cout << "---------------------------------------------" << std::endl;
    }

    //Add a Course when courses points to a nullptr
    if(courses == nullptr)
    {
        courses = new Course(title, code, creditHour, grade);
            std::cout << "---------------------------------------------" << std::endl;
            std::cout << "Successfully Added Course" << std::endl;
            std::cout << "---------------------------------------------" << std::endl;

    }
    //since were passing creditHour to the function, we can update Student's totalCreditHour
    this->totalCreditHours = this->totalCreditHours + creditHour;
    //Increment # of courses
    this->numberOfCourses++;
}


//Delete a course from the singly linked list
void Student::deleteCourse(std::string code) //delete course that matches the code
{
    //if list is empty
    if(courses == nullptr)
    {
        std::cout << "---------------------------------------------" << std::endl;
        std::cout << "List is Empty" << std::endl;
        std::cout << "---------------------------------------------" << std::endl;
        return;
    }

    //delete head node if it matches the code
    if(courses->getCode() == code)
    {
        //create temporary pointer to the head so we can delete the original head
        Course* T;
        T = courses;
        //remove credithours from totalCreditHours
        this->totalCreditHours = this->totalCreditHours - T->getCreditHour();
        courses = courses->getNext();
        delete T;
        //decrement # of courses
        this->numberOfCourses--;
        std::cout << "---------------------------------------------" << std::endl;
        std::cout << "Successfully Deleted Course" << std::endl;
        std::cout << "---------------------------------------------" << std::endl;

    }

    //search through the list to find if any course in the list matches the code
    else
    {
        //create temporary pointer
        Course* T;
        T = courses;
        //cycle through the list
        while(T->getNext() != nullptr)
        {
            if(T->getNext()->getCode() == code)
            {
                //remove credithours from totalCreditHours
                this->totalCreditHours = this->totalCreditHours - T->getCreditHour();
                //set new pointer from before and after the deleted node
                Course* A = T;
                T = T->getNext();
                Course* B = T->getNext();
                A->setNext(B);

                delete T;
                //decrement # of courses
                this->numberOfCourses--;
                std::cout << "---------------------------------------------" << std::endl;
                std::cout << "Successfully Deleted Course" << std::endl;
                std::cout << "---------------------------------------------" << std::endl;
                break;
            }
            T = T->getNext();
        }
    }
}

//print out the Courses linked list for given student
void Student::printCourses()
{
    Course* T = courses;
    //loop through the list until null
    if(T == nullptr)
    {
        std::cout << "No Courses in Student Record" << std::endl;
        std::cout << "---------------------------------------------" << std::endl;
        std::cout << "  " << std::endl;
    }
    while(T != nullptr)
    {

        std::cout << "Course Title: " << T->getTitle() << std::endl;
        std::cout << "Course Code: " << T->getCode() << std::endl;
        std::cout << "Credit Hour: " << unsigned(T->getCreditHour()) << std::endl;
        std::cout << "Grade: " << T->getGrade() << std::endl;
        std::cout << "---------------------------------------------"  << std::endl;
        T = T->getNext();
    }
}

//get a pointer to the next node in list
Student* Student::getNext()
{
    return next;
}

//set a pointer pointing to the next node in the list
void Student::setNext(Student* next)
{
    this->next = next;
}

//get a pointer to the previous node in list
Student* Student::getPrevious()
{
    return previous;
}

//set a pointer pointing to the previous node in the list
void Student::setPrevious(Student* previous)
{
    this->previous = previous;
}

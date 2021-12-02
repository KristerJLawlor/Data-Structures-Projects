//Person.h
//Krister Lawlor
//COP-4415 Sec. 2
//Last Date of Modification: 10/13/2021

//This is the header file to prototype all the data members and functions for the Person Class
#include <iostream>
#include<string>
#include<stdint-gcc.h>
#ifndef PERSON_H
#define PERSON_H


class Person
{
    protected:
        //Data members
        uint8_t age;
        std::string name;

    public:

        //Class constructors
        Person();
        Person(std::string name);
        Person(std::string name, uint8_t age);

        //Class destructor
        virtual ~Person();

        //Class Get/Set functions
        uint8_t getAge() const;
        void setAge(uint8_t age);
        std::string getName() const;
        void setName(std::string name);


//operator overload to auto-print values when putting object next to <<
friend std::ostream& operator<<(std::ostream& os, Person& P)
{
    std::cout << "Name: " << P.getName() << std::endl;
    std::cout << "Age: " << +P.getAge() << std::endl;
    // write P to stream
    return os;
}

};

#endif // PERSON_H

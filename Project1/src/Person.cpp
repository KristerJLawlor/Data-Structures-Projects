//Person.cpp
//Krister Lawlor
//COP-4415 Sec. 2
//Last Date of Modification: 10/13/2021

//This is the file for defining the constructors and functions for the Person class
#include <iostream>
#include<string>
#include<stdint-gcc.h>
#include "Person.h"

//define the constructors
Person::Person()
{
    age = 0;
    name = "unknown";
}

Person::Person(std::string name)
{
    age = 0;
    this->name = name;
}

Person::Person(std::string name, uint8_t age)
{
    this->name = name;
    this->age = age;
}

//destructor
Person::~Person()
{
    //dtor
}

//define the get and set functions
//set Age
void Person::setAge(uint8_t age)
{
    this->age = age;
}

//get Age value
uint8_t Person::getAge() const
{
    return age;
}

//set name string
void Person::setName(std::string name)
{
    this->name = name;
}

//get name string
std::string Person::getName() const
{
    return name;
}


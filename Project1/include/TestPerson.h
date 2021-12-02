//TestPerson.h
//Krister Lawlor
//COP-4415 Sec. 2
//Last Date of Modification: 10/18/2021
//This is the test file for all the classes and their member functions

#ifndef TESTPERSON_H_INCLUDED
#define TESTPERSON_H_INCLUDED

#include <iostream>
#include<ios>
#include<string>
#include<stdint-gcc.h>
#include<fstream>
#include<limits>
#include "Person.h"

using namespace std;

/////////////////////////////TEST FUNCTIONS/////////////////////////////////


//Function to Test the Person Class
void TestPerson()
{
    Person P("TestPerson", 25);
    cout<<P;
}

#endif // TESTPERSON_H_INCLUDED

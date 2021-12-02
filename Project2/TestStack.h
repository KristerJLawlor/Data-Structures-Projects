//Krister Lawlor
//Data Structures Sec. 2
//Last Edit Made: Nov 4th, 2021
//This Program is made for testing the Stack class and the PostFix Notation
#ifndef TESTSTACK_H_INCLUDED
#define TESTSTACK_H_INCLUDED

#include "Node.h"
#include "Stack.h"
#include <cstddef>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void TestingStack()
{

       //TESTING STACK
    cout << "- - - - - - TESTING STACK - - - - - -" << endl;

    Stack stackVector;
    cout << "Push 1" << endl;
    stackVector.push(46.1);
    cout << "Push 2" << endl;
    stackVector.push(8.0);
    cout << "Push 3" << endl;
    stackVector.push(4.0);
    cout << "Push 4" << endl;
    stackVector.push('x');
    cout << "Push 5" << endl;
    stackVector.push(2.0);
    cout << "Push 6" << endl;
    stackVector.push('/');
    cout << "Push 7" << endl;
    stackVector.push('+');
    cout << "Size of stack is : " << stackVector.getSize() << endl;

    stackVector.print();

    cout << "Result of Expression is: " << stackVector.evaluate() << endl;

    cout << "Popping back" << endl;
    stackVector.pop();

    cout << "Size is : " << stackVector.getSize() << endl;

    stackVector.print();

    cout << "- - - - - - END STACK TEST- - - - - -\n\n\n\n" << endl;


}

#endif // TESTSTACK_H_INCLUDED

//Krister Lawlor
//Data Structures Sec. 2
//Last Edit Made: Nov 4th, 2021
//This Program is for testing the Node class
#ifndef TESTNODE_H_INCLUDED
#define TESTNODE_H_INCLUDED

#include "Node.h"
#include <cstddef>
#include <iostream>
#include <string>

using namespace std;

void TestingNode()
{
    cout << "- - - - - - TESTING NODE - - - - - -" << endl;

    Node testNode;

    testNode.printNode();

    testNode.setDataD(20.0);

    testNode.printNode();

    testNode.setDataC('+');

    testNode.printNode();

    cout << "- - - - - - END NODE TEST- - - - - -\n\n\n\n" << endl;


}


#endif // TESTNODE_H_INCLUDED

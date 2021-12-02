//Krister Lawlor
//Data Structures Sec. 2
//Last Edit Made: Nov 4th, 2021
//This Program is the Node class designed to hold data to be used by the Stack class
#include "Node.h"
#include <vector>
#include <iostream>
#include <cstddef>
using namespace std;

//constructor
Node::Node()
{
    dataD = 0;
    dataC = '\0';
}

Node::Node(double dataD)
{
    this->dataD = dataD;
    this->dataC = '\0';
}

Node::Node(char dataC)
{
    this->dataD = 0;
    this->dataC = dataC;
}

//get methods
double Node::getDataD()
{
    return dataD;
}

char Node::getDataC()
{
    return dataC;
}

//set methods
void Node::setDataD(double dataD)
{
    this->dataD = dataD;
}

void Node::setDataC(char dataC)
{
    this->dataC = dataC;
}

//print the node's operator char if it contains one, otherwise will print the double value
void Node::printNode()
{
    if(this->getDataC() != '\0')
    {
        cout << "Operator: " << this->getDataC() << endl;
    }
    else
    {
        cout << "Value: " << this->getDataD() << endl;
    }
}

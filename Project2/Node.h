//Krister Lawlor
//Data Structures Sec. 2
//Last Edit Made: Nov 4th, 2021
//This Program is the Node class designed to hold data to be used by the Stack class
#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED
#include <vector>
#include <iostream>
#include <cstddef>
using namespace std;

class Node{

private:
    double dataD;
    char dataC;


public:
    //constructor
    Node();

    Node(double dataD);

    Node(char dataC);

    //get methods
    double getDataD();

    char getDataC();

    //set methods
    void setDataD(double dataD);

    void setDataC(char dataC);

    //print the node's operator char if it contains one, otherwise will print the double value
    void printNode();


};

#endif // NODE_H_INCLUDED

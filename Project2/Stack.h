//Krister Lawlor
//Data Structures Sec. 2
//Last Edit Made: Nov 1st, 2021
//This Program is the class implementation of a Stack by using the STL vector
#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#include "Node.h"
#include <vector>
#include <iostream>
#include <cstddef>

using namespace std;

class Stack{

private:
    //vector to hold Nodes
    vector<Node> vectorStack;


public:

Stack();
//unless we need to create multiple stacks, we do not need to make any constructors


void setCapacity(size_t capacity);

vector<Node> getVectorStack();

void push(double dataD);

void push(char dataC);

//remove and return
void pop();

//return the size of stack
int getSize();

//return the Node element at the end/top
Node top();

//print out the values held at the stack location
void print();

//evaluate the RPN expression
double evaluate();


};


#endif // STACK_H_INCLUDED

//Krister Lawlor
//Data Structures Sec. 2
//Last Edit Made: Nov 1st, 2021
//This Program is the class implementation of a Stack by using the STL vector
#include "Stack.h"
#include "Node.h"
#include <vector>
#include <iostream>
#include <cstddef>

using namespace std;


Stack::Stack()
{
    cout << "Stack Created." << endl;
}
//unless we need to create multiple stacks, we do not need to make any constructors


void Stack::setCapacity(size_t capacity)
{
    vectorStack.reserve(capacity);
}

vector<Node> Stack::getVectorStack()
{
    return vectorStack;
}

//push double to stack
void Stack::push(double dataD)
{
    //vectorStack.push_back(node);
    vectorStack.push_back(Node(dataD));
}

//push char to stack
void Stack::push(char dataC)
{
    //vectorStack.push_back(node);
    vectorStack.push_back(Node(dataC));
}

//remove and return
void Stack::pop()
{
    if(vectorStack.size() != 0)
    {
        vectorStack.pop_back();
    }
    else
    {
        return;
    }
}

//return the size of stack
int Stack::getSize()
{
    return vectorStack.size();
}

//return the Node element at the end/top
Node Stack::top()
{
    return vectorStack[vectorStack.size() - 1];
}

//print out the values held at the stack location
void Stack::print()
{
    cout << " - - - - - Displaying Stack - - - - - " << endl;
    for(int i = vectorStack.size() - 1; i >= 0; i--)
    {
        vectorStack[i].printNode();
    }
    cout << " - - - - - - - - - - - - - - - - - - " << endl;
}

//evaluate the given expression
double Stack::evaluate()
{
    cout << "Evaluating the Expression.\n" << endl;
    //check to make sure there is at least one value in the stack still
    if(vectorStack.size() >= 1)
    {
        //if top of the stack is an operand
        if(top().getDataC() == '\0')
        {
            //will pop the element off stack and return the double value it held
            double operandX = top().getDataD();
            cout << "\n\nPopping " << operandX << " off the Stack." << endl;
            pop();
            cout << "Returning Operand: " << operandX << "\n\n" << endl;
            return operandX;
        }


        //if the top of the stack is an operator
        if(top().getDataC() != '\0')
        {
            char operatorC = top().getDataC();
            cout << "Encounter Operator " << operatorC << endl;
            cout << "Popping Operator " << operatorC << " off the Stack." << "\n\n" << endl;
            pop();

            double operandA = evaluate();
            double operandB = evaluate();

            //perform an operation
            switch(operatorC)
            {
                case '+' : push(operandB + operandA); cout << "Adding " << operandB << " and " << operandA << endl << "Pushing " << operandB + operandA << "\n\n" << endl; break;
                case '-' : push(operandB - operandA); cout << "Subtracting " << operandB << " and " << operandA << endl  << "Pushing " << operandB - operandA << "\n\n" << endl; break;
                case '/' : push(operandB / operandA); cout << "Dividing " << operandB << " and " << operandA << endl  << "Pushing " << operandB / operandA << "\n\n" << endl; break;
                case 'x' : push(operandB * operandA); cout << "Multiplying " << operandB << " and " << operandA << endl  << "Pushing " << operandB * operandA << "\n\n" << endl; break;
            }
            double operatorResult = top().getDataD();
            pop();
            return operatorResult;
        }
    }
    else
    {
        double operatorResult = top().getDataD();
        pop();
        return operatorResult;
    }

}




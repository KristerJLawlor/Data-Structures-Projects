//Krister Lawlor
//Data Structures Sec. 2
//Last Edit Made: Nov 4th, 2021
//This Program is the Main program that takes the arguments from the command line
//and evaluates it as a PostFix Expression by passing each argument in to the stack.
//once it stores everything in the stack, it recursively evaluates each operation and returns the result.
#include "Node.h"
#include "Stack.h"
#include "TestNode.h"
#include "TestStack.h"
#include <cstddef>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <math.h>

using namespace std;

int main(int argc, char *argv[])
{
    //Test Node Class
    //TestingNode();
    //Test Stack Class
    //TestingStack();


    Stack stackRPN;
    //set stack size to be that of the size of argc
    stackRPN.setCapacity(argc);
    //check the size of the stack
    //cout << "Stack Size: " << stackRPN.getSize() << endl;

    //if less than 3 given values/operators, exit
    if(argc <= 3)
    {
        cout << "Too Few Parameters. Exiting." << endl;
        exit(EXIT_FAILURE);
    }

    //continue to take the arguments and populate the stack
    else
    {
        cout << "Populating the Stack with Command-Line Arguments." << endl;
        for(int i = 1; i < argc; i++)
        {
            //checking if passed argument is a character
            if(*argv[i] == '+' || *argv[i] == '-' || *argv[i] == '/' || *argv[i] == 'x')
            {
                cout << "Pushing " << *argv[i] << " to Stack." << endl;
                stackRPN.push(*argv[i]);
                cout << "Stack Size: " << stackRPN.getSize() << endl;
            }
            //if argument is a number
            else
            {
                cout << "Pushing " << atof(argv[i]) << " to Stack." << endl;
                stackRPN.push(atof(argv[i]));
                cout << "Stack Size: " << stackRPN.getSize() << endl;
            }

        }
    }
    stackRPN.print();
    double result = stackRPN.evaluate();
    //cout << stackRPN.evaluate() << endl;
    cout << "\n\n----------------------------------------\n\n" << "Result of Expression: "
         << result << "\n\n----------------------------------------\n\n" << endl;



    exit(EXIT_SUCCESS);
}

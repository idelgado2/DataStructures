/*************************************************************************
 * Lab5.cpp
 * Isaac Delgado
 * COSC2437
 * 3/23/2015
 *
 * Purpose: The purpose of this class is to convert an infix expression
 *          into a postfix expression and set precedence to operators.
 **************************************************************************/

#ifndef infixToPostfix_h
#define infixToPostfix_h


#include "lstacks.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class infixToPostfix{
    
public:
    void getInfix(string);
    //Function to return the infix expression
    //Postcondition: return the infix expression
    
    string showInfix();
    //Function to print out the infix expression
    //Postcondition: printing out the infix expression
    
    string showPostfix();
    //Function to print out the Postfix expression
    //Postcondition: printing out the Postfix expression
    
    void convertToPostfix();
    //Function conver the infix expression to a postfix expression
    //Postcondition: converting infix to postfix
    
    infixToPostfix();
    //default constructor, to initialize the Infix and postfix
    //Postcondition: intialized infix and postfix
    
    infixToPostfix(string);
    //constructor to intialize the infix with the givin parameter
    //Postcondition: infix is intialized with parameter
    
    ~infixToPostfix();
    //destructor

    
private:
    string infix;
    string postfix;
    lstacks<char> stack;    //linked list stack to hold operators
    
    int setOperatorPrecedece(char);
    //Function to determine the precedence between operators
    //Postcondition: assign values to each operator acoording to their precedence
    
    bool precedence (char, char);
    //Function to determine weather the stacktop is greater or equal to the current operator in  the
    //expression
    //Postcondition: returns true if stack top is greater or equal, else false if other wise
};


#endif














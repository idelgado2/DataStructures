/*************************************************************************
 * Lab5.cpp
 * Isaac Delgado
 * COSC2437
 * 3/23/2015
 * Purpose: The purpose of this program is to convert an infix expression
 *          into a postfix expression.
 *
 * Input:   The input of the program will be the from the file, "testData.tx"
 *          in this file contains test infix expressions to convert
 *
 * Output:  The output of this program will be the original infix expression
 *          followed by the converted postfix expression. there will be
 *          process output for the user, however the expressions will be
 *          outputted to the file "idelgado2Lab5.out".
 **************************************************************************/

#include "infixToPostfix.h"
#include <cstring>
#include <iostream>
#include <fstream>
#include <cassert>
#include <cstdlib>
using namespace std;


int main(){
    string expression;
    
    ifstream testfile;  //input file objects
    ofstream outputfile;
    
    outputfile.open("idelgado2Lab5.out");
    
    testfile.open("testData.txt");       //streaming from lab3.dat
    if (testfile.fail()) {    //check if files are openable
        cerr << "could not open file" << endl;
        exit(EXIT_FAILURE);
    }
    
    cout << "Reading in list from testData.txt file..." << endl << endl;
    cout << "Converting Infix expressions to Postfix expressions..." << endl << endl;
    
    outputfile << "Infix Expression from file testData.txt" << endl << endl;
    
    while (getline(testfile, expression)) { //till there are no more items to input from file
        
        infixToPostfix line(expression);

        line.convertToPostfix();
        
        outputfile << "Infix: ";
        outputfile << line.showInfix();
        outputfile << endl;
        
        outputfile << "Postfix: ";
        outputfile << line.showPostfix();
        outputfile << endl << endl;
    }
    
    cout << "Process Complete, results in file idelgado2Lab5.out..." << endl << endl;
    
    testfile.close();
    outputfile.close();
    
    return 0;

}

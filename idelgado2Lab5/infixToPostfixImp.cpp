#include "infixToPostfix.h"
#include <iostream>

using namespace std;

infixToPostfix::infixToPostfix(){
    infix = "";
    postfix = "";
}

infixToPostfix::infixToPostfix(string expression){
    infix = expression;
    postfix = "";
}

infixToPostfix::~infixToPostfix(){
    
}


void infixToPostfix::getInfix(string expression){
    infix = expression;
}

string infixToPostfix::showInfix(){
    return  infix;
}

string infixToPostfix::showPostfix(){
    return postfix;
}

void infixToPostfix::convertToPostfix(){
    
    for (int i = 0; i < infix.length(); i++) {  //for loop to cycle through each character in infix expression
        char sym = infix[i];
        
        if(sym == ' '|| sym == ';') continue;   //if character is a space or semicolon ignore
        
        switch (sym) {
            case'*':
            case'/':
            case'+':        //in the case of '*' '/' '+' '-' do the following algorithm
            case'-':
                if (stack.isEmptyStack()){      //if stack top is empty push the operator into stack
                    stack.push(sym);
                }
                else{
                    
                    while (!stack.isEmptyStack() && stack.top() != '(' && precedence(stack.top(), sym))
                        //while stack is not empty AND stack to does not equal '(' symbol AND stacktop is
                        //greater than or equal to the current operator in the infix espression
                    {
                        
                        postfix += stack.top();     //add stacktop value to postfix expression
                        stack.pop();
                    }
                    
                    stack.push(sym);
                }
                break;
                
            case'(':  //in the case of '(' push into stack
                stack.push(sym);
                break;
                
            case')': //in the case of ')'
                if(stack.isEmptyStack())
                    cout << "Error";
                else
                {
                    while (stack.top() != '(' && !stack.isEmptyStack())
                    {
                        postfix += stack.top();  //add all values in stack to postfix expression until
                        stack.pop();            //stack is empty or symbol '(' appears
                    }
                    stack.pop();  //pop symbol
                }
                break;
                
            default:
                postfix += sym;  //else if all other cases fail, must be an operand and thus add to postfix
                break;
        }
        
    }
    
    
    while (!stack.isEmptyStack()) //pop any reamining values in stack if stack is not empty
    {
        postfix += stack.top();
        stack.pop();
    }
    
}



bool infixToPostfix::precedence(char stacktop, char sym){
    
    int stackTopValue = setOperatorPrecedece(stacktop); //set values for comparing
    int symValue = setOperatorPrecedece(sym);
    
    if (stackTopValue >= symValue)
        return true;
    else
        return false;
}

int infixToPostfix::setOperatorPrecedece(char oper){
    
    int value;
    
    
    if (oper == '-' || oper == '+')
        value = 1;
    if(oper == '/' || oper == '*')
        value = 2;
    else
        value = 0;
    
    
    return value;
}

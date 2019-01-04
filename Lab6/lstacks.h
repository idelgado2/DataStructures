/*************************************************************************
 *   Taken from text book "Data Structures using c++, 2nd edition"
 *   Author: D.S. Malik
 *
 *   This clss specifies the basic operations on a stack as a linked stack.
 **************************************************************************/

#ifndef lstacks_h
#define lstacks_h

#include "StackADT3.h"
#include <iostream>
#include <cassert>

using namespace std;

template<class kind>
struct nodeType{
    
    kind info;
    nodeType<kind> *link;
    
};

template<class kind>
class lstacks: public StackADT3<kind>{
public:
    void initializeStack();
    //Function to initialize the stack to an empty state.
    //Postcondition: The stack elements are removed;
    // stackTop = NULL;
    
    bool isEmptyStack() const;
    //Function to determine whether the stack is empty.
    //Postcondition: Returns true if the stack is empty;
    // otherwise returns false.
    
    bool isFullStack() const;
    //Function to determine whether the stack is full.
    //Postcondition: Returns false.
    
    void push(const kind& newItem);
    //Function to add newItem to the stack.
    //Precondition: The stack exists and is not full.
    //Postcondition: The stack is changed and newItem is
    // added to the top of the stack.
    
    void pop();
    //Function to remove the top element of the stack.
    //Precondition: The stack exists and is not empty.
    //Postcondition: The stack is changed and the top
    //    element is removed from the stack.
    
    kind top() const;
    //Function to return the top element of the stack.
    //Precondition: The stack exists and is not empty.
    //Postcondition: If the stack is empty, the program
    // terminates; otherwise, the top element of
    //    the stack is returned.
    
    int getCount() const;
    //Function get the number of items in the stack.
    //Postcondition: Returns the number of items in the stack.
    
    lstacks();
    //Default constructor
    //Postcondition: stackTop = NULL;
    
    lstacks(const lstacks<kind>& otherstack);
    //Copy constructor
    
    ~lstacks();
    //Destructor
    //Postcondition: All the elements of the stack are removed.
    
    const lstacks<kind>& operator=(const lstacks<kind>& otherstack);
    //Function to overload the '=' operator
    //postcondition: makes the a copy of otherstack and sets the copy
    //as this object
    
private:
    nodeType<kind> *stacktop;  //pointer to stacktop
    int count;
    
    void copystacks(const lstacks<kind>& otherstack);
    //Function to make a copy of otherstack
    //postcondition: a copy of otherstack is created
    //and assigned to this stack


    
};

template<class kind>
lstacks<kind>::lstacks(){
    stacktop = NULL;
}

template<class kind>
int lstacks<kind>::getCount() const{
    return count;
}

template<class kind>
void lstacks<kind>::initializeStack(){
    
    nodeType<kind> *temp; //pointer to delete the node
    
    while (stacktop != NULL) {  //while there are elements in
                                //the stack
        temp = stacktop;     //set temp to point to the current node
        
        stacktop = stacktop -> link;   //advance stacktop to the next node
        
        delete temp;        //deallocate memory occupied by temp
    }
}

template<class kind>
bool lstacks<kind>::isEmptyStack() const{
    return (stacktop == NULL);
    
}//end isEmptyStack

template<class kind>
bool lstacks<kind>::isFullStack()const{
    
    return false;
}//end isFullStack



template <class kind>
void lstacks<kind>::push(const kind& newItem){
    
    nodeType<kind> *newnode;        //pointer to create the new node
    
    newnode = new nodeType<kind>;   //create the node
    
    newnode->info = newItem;        //store newElement in the node
    newnode->link = stacktop;       //insert newNode before stackTop
    stacktop = newnode;             //set stacktop to point to the top node
    count++;
}//end push

template<class kind>
void lstacks<kind>::pop(){
    
    nodeType<kind> *temp;   //pointer to deallocate memory
    if (stacktop != NULL) {
        
        temp = stacktop;        //set temp to point to the top node
        stacktop = stacktop ->link;    //advance stacktop to the nextnode
        delete temp;        //delete the top node
        count--;
    }
    else
        cout << "Cannot remove from an empty stack.";
    
}//end pop

template<class kind>
kind lstacks<kind>::top() const{
    assert(stacktop != NULL);   //if stack is empty terminate program
    
    return (stacktop->info);    //return the top element
}//end top

template<class kind>
void lstacks<kind>::copystacks(const lstacks<kind>& otherstack){
    nodeType<kind> *current, *last, *newnode;
    
    if(stacktop != NULL){   //if stack is nonempty, make it empty
        initializeStack();
    }
    
    if (otherstack.stacktop == NULL) {
        stacktop = NULL;
    }
    else {
        current  = otherstack.stacktop;     //set current to point to the stack to be copied
    
        //copy the stacktop element of the stack
        stacktop = new nodeType<kind>;  //create the node
        
        stacktop->info = current->info; //copy the info
        stacktop->link = NULL;  //set the link field to NULL
        last = stacktop;    //set last to point to the node
        current = current->link;        //set current to point to the next node
        
        //copy the remaining stack
        while (current != NULL) {
            
            newnode = new nodeType<kind>;
            newnode->info = current->info;
            newnode->link = NULL;
            last->link = newnode;
            last = newnode;
            current = current->link;
        }//end while
    }//end else
        count = otherstack.count;  //copy count from other stack
}//end copystack


template<class kind>
const lstacks<kind>& lstacks<kind>::operator=(const lstacks<kind>& otherstack){
    
    if(this != &otherstack){    //avoid self-copy
        copystacks(otherstack);
    }
    
    return *this;
    
}//end operator

template<class kind>
lstacks<kind>::lstacks(const lstacks<kind>& otherstack){
    stacktop = NULL;
    copystacks(otherstack);
    
}//end copyconstructor

template<class kind>
lstacks<kind>::~lstacks<kind>(){
    
    initializeStack();
}//end destructor

#endif














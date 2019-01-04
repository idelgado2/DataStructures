#ifndef Lab3_linkedListType_h
#define Lab3_linkedListType_h
#include "linkedListIterator.h"
#include <iostream>
using namespace std;

template <class kind>
class linkedListType{
public:
    const linkedListType<kind> & operator= (const linkedListType<kind> &);
    //Overload the assignment operator
    
    void initializeList();
    //Initialize the list to an empty state
    //postcondition: first = NULL, last = NULL, count = 0
    
    bool isEmptyList() const;
    //Function to determine whether the list is empty
    //postconidtion: Returns true if the list is empty, otherwise
    //  it returns false
    
    void print() const;
    //Function to output the data contained in each node
    //postcondition: none
    
    int length() const;
    //Function to return the number of nodes in the list
    //postcondition: The value of count is returned
    
    void destroyList();
    //Fucntion to delete all the nodes from the list.
    //postcondition: first = NULL, lst = NULL, count = 0
    
    kind front() const;
    //Function to return the first element of the list.
    //precondition: the list must exist and must not be empty
    //postcondition: if the list is empty, the program terminates;
    //          otherwise, the first element of th elist is returned;
    
    kind back() const;
    //Function to return the last element of the list.
    //precondition: the list must exist and must not be empty
    //postcondition: if the list is empty, the program terminates;
    //          otherwise, the lst element of th elist is returned;
    
    virtual bool search(const kind& searchItem) const = 0;
    //Function to determine whether searchItem is in the list.
    //postcondition: returns true if serchItem is in the list,
    //          otherwise the value false is returned
    
    virtual void insertFirst(const kind& newItem) = 0;
    //Function to isnert newItem ar the beginning of the list.
    //postcondition: first points to the new list, newItem is
    //   inserted at the end of the list, last points to
    //      the last node in the list, and count is inremented by 1.
    
    virtual void insertLast(const kind& newItem) = 0;
    //Function to isnert newItem at the end of the list.
    //postcondition: first points to the new list, newItem is
    //   inserted at the beginning of the list, last points to
    //      the last node in the list, and count is inremented by 1.
    
    virtual void deleteNode(const kind& deleteItem) = 0;
    //Function to delete deleteItem from the list.
    //postcondition: if found, the node containning deleteITem is
    //      deleted from the list. first points to the first node,
    //      last points to the last node of th eupdated list, and
    //      count is decremented by 1.
    
    linkedListIterator<kind> begin();
    //function to return an iterator at the beginning of the
    //linked list
    //postcondition: returns an iterator such that current si set
    //      to first.

    linkedListIterator<kind> end();
    //function to return an iterator one element past the
    //last element of th elinked list
    //postcondition: returns an iterator such that current is set
    //      to null.
    
    linkedListType();
    //default constructor
    //initializes th elist to an empty state
    //postconidition: the list object is destroyed.
    
    linkedListType(const linkedListType<kind>& otherList);
    //copy constructor
    
    ~linkedListType();
    //destructor
    //deletes al lth enodes form the list.
    //Postcondition: The list object is detroyed.
    
protected:
    int count;  //variable to store the number of list elements
    nodeType<kind> *first;  //pointer to the lfirst node of the list
    nodeType<kind> *last;   //pointer to the last node of the list

private:
    void copyList(const linkedListType<kind>& otherList);
    //function to make a copy of otherList.
    //postcondition: a copy of otherList is created and assigned
    //      to this list.
};

template<class kind>
bool linkedListType<kind>::isEmptyList() const{
    return (first == NULL);
}

template<class kind>
linkedListType<kind>::linkedListType(){  //default constructor
    first = NULL;
    last = NULL;
    count = 0;
}

template<class kind>
void linkedListType<kind>::destroyList(){
    nodeType<kind> *temp;   //pointer to deallocate the memory
    //occupied by the node
    while (first != NULL) {     //while there are nodes in the list
        temp = first;           //set temp to the current node
        first = first -> link;      //advance first to the nect node
        delete temp;            //deallocate the memory occupied by temp
    }
    
    last = NULL;            //initialize last to NULL, first has already
    //been set to NULL by the while loop
    count = 0;
}

template<class kind>
void linkedListType<kind>::initializeList(){
    destroyList(); //if the list has any nodes, delete them
}

template <class kind>
void linkedListType<kind>::print() const{
    nodeType<kind> *current; //pointer to traverse th elist
    
    current = first; //set current point to the first node
    while (current != NULL) {   //set current point to the first node
        cout << current -> info;
        current = current -> link;
    }
    
    //end print
}

template<class kind>
int linkedListType<kind>::length() const{
    return count;
}

template <class kind>
kind linkedListType<kind>::front() const{
    assert(first != NULL);
    
    return first -> info;   //return the info of the last node
}//end of front

template<class kind>
kind linkedListType<kind>::back() const{
    assert(last != NULL);
    
    return last -> info; //return the info of the last node
}//end back

template<class kind>
linkedListIterator<kind> linkedListType<kind>::begin(){
    linkedListIterator<kind> temp(first);
    
    return temp;
}

template<class kind>
linkedListIterator<kind> linkedListType<kind>::end(){
    linkedListIterator<kind> temp(NULL);
    
    return temp;
}

template<class kind>
void linkedListType<kind>::copyList (const linkedListType<kind>& otherList){
    nodeType<kind> *newNode;    //pointer to create a new node
    nodeType<kind> *current;    //pointer to traverse the list
    
    if (first != NULL) { //if list is non-empty, make it empty
        destroyList();
    }
    
    if (otherList.first == NULL) {   //other list is empty
        first = NULL;
        last = NULL;
        count = 0;
    }
    else{
        current = otherList.first;  //current points to the list to be copied
        
        count = otherList.count;
        
        //copy the first node
        first = new nodeType<kind>;     //creatw the node
        first -> info = otherList.first -> info;    //copy the info
        first -> link = NULL;   //set the link firld of the node to NULL
        last = first;   //make last point to the first node
        current = current -> link;  //make current point to the next node
        
        //copy the remainning list
        while(current != NULL){
            newNode = new nodeType<kind>;   //create the node
            newNode -> info = current -> info;  //copy the info
            newNode -> link = NULL;     //set the link of newNode to NULL
            
            last -> link = newNode;     //attach newNode after last
            last = newNode;     //make last point to the actual last node
            current = current -> link;      //make current point to the next node
        }
    }
    
}

template<class kind>
linkedListType<kind>::~linkedListType(){  //destuctor
    destroyList();
}

template<class kind>
linkedListType<kind>::linkedListType(const linkedListType<kind>& otherList){
    first = NULL;
    copyList(otherList);
}//end copy constructor

template<class kind>
const linkedListType<kind>& linkedListType<kind>::operator= (const linkedListType<kind>& otherList){
    if (&otherList == this) {       //avoid self-copy
        copyList(otherList);
    }//end else
    
    return *this;
}








#endif

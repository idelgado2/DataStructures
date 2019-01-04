#ifndef listQueue_listQueue_h
#define listQueue_listQueue_h
#include "queueADT.h"
#include <iostream>
#include <cassert>
using namespace std;

template<class kind>
struct nodetype{
    
    kind info;
    nodetype<kind> *link;
    
};

template<class kind>
class listQueue: public queueADT<kind>{
    
public:
    const listQueue<kind>& operator= (const listQueue<kind>&);
    void initializeQueue();
    //Function to initialize the queue to an empty state
    //postcondition: the queue is empty
    
    bool isEmptyQueue() const;
    //Function to determine whether the queue is empty.
    //Postcondition: Returns true if the queue is empty,
    //  otherwirse return false.
    
    bool isFullQueue() const;
    //Function to determine whether the queue is full.
    //postcondition: Returns true if the queue is full,
    //  otherwise returns false.
    
    kind back() const;
    //Function to return the last element of the queue.
    //precondition: The queue exists and is not empty.
    //postcondition: If the queue is empty, the program
    //         terminates; otherwise, the last element
    //          of the queue is returned
    
    kind front() const;
    //Function to return the first element of the queue.
    //precondition: The queue exists and is not empty.
    //postcondition: If the queue is empty, the program
    //         terminates; otherwise, the first element
    //          of the queue is returned
    
    void addQeuue(const kind& newitem);
    //Function to add newitem to the queue.
    //precondition: The queue exists and is not Full.
    //postcondition: the queue is changed and
    //       newitem is added to the queue.
    
    void deleteQueue();
    //Function to remove the first element of the queue.
    //precondition: The queue exists and is not Empty.
    //postcondition: the queue is changed and
    //       the first element is removed from the queue.
    
    listQueue();
    //Default constructor
    //Postcondition: queuefront = NULL; queuerear == NULL
    
    listQueue(const listQueue<kind>& otherqueue);
    //Copyconstructor
    
    ~listQueue();
    //destructor
    
private:
    nodetype<kind> *queueFront;  //pointer to queueFront
    nodetype<kind> *queueRear;  //pointer to queueRear
    
    void copyQueue(const listQueue<kind>& otherqueue);
    //Function to copy a queue from otherqueue
    //postcondition: makes the a copy of otherstack and sets the copy
    //as this object
    
};

template<class kind>
void listQueue<kind>::initializeQueue(){
    
    nodetype<kind> *temp; //temporary pointer
    
    while (queueFront != NULL) { //while there are values in the queue
        temp = queueFront;
        queueFront = queueFront -> link;
        delete temp;
    }
    
    queueRear = NULL;
    
}

template<class kind>
bool listQueue<kind>::isEmptyQueue() const{
    return (queueFront == NULL);
}

template<class kind>
bool listQueue<kind>::isFullQueue() const{
    return false;
}

template<class kind>
kind listQueue<kind>::front() const{
    assert(queueFront != NULL);
    return queueFront -> info;
}

template<class kind>
kind listQueue<kind>::back() const{
    assert(queueRear != NULL);
    return queueRear -> info;
}

template<class kind>
void listQueue<kind>::addQeuue(const kind& newitem){
    nodetype<kind> *newnode;
    newnode = new nodetype<kind>;  //create a new node to add value with
    
    newnode -> info = newitem;
    newnode -> link = NULL;
    
    if (queueFront == NULL) {  //if this will be the first and only value in the queue
        queueFront = newnode;
        queueRear = newnode;
    }
    else{   //else there is already atleast one value in the queue
        
        queueRear -> link = newnode;
        queueRear = newnode;
        
    }
}

template<class kind>
void listQueue<kind>::deleteQueue(){
    nodetype<kind> *temp;
    if (!isEmptyQueue()) {  //if the queue is not empty
        temp = queueFront;
        queueFront = queueFront -> link;
        delete temp;
        
        if (queueFront == NULL) //if there are no more values in the queue
            queueRear = NULL;   //then the queuerear and queuefront are both pointing to NULL
    }
    else
        cout << "Cannot remove from an empty queue" << endl;
}

template<class kind>
void listQueue<kind>::copyQueue(const listQueue<kind>& otherqueue){
    nodetype<kind> *current, *newnode;
    
    if (queueFront != NULL) { //if queue has values initialize it
        initializeQueue();
    }
    
    if (otherqueue.queueFront == NULL) {  //if otherqueue has not values
        queueFront = NULL;                 //then make this queue have no values
        queueRear = NULL;
    }
    else{
        
        current  = otherqueue.queueFront;
        
        queueFront = new nodetype<kind>;
        queueRear = new nodetype<kind>;
        
        queueFront -> info = current -> info;
        queueFront -> link = NULL;
        queueRear = queueFront;
        current = current -> link;
        
        while (current != NULL) {           //while you can still compare values from the other queue
            newnode = new nodetype<kind>;
            newnode -> info = current -> info;
            newnode -> link = NULL;
            queueRear -> link = newnode;
            queueRear = newnode;
            current = current -> link;
        }
        
    }
    
}


template<class kind>
const listQueue<kind>& listQueue<kind>::operator=(const listQueue<kind>& otherqueue){
    
    if(this != &otherqueue){ 
        copyQueue(otherqueue);
    }
    
    return *this;
}

template<class kind>
listQueue<kind>::listQueue(){
    queueFront = NULL;
    queueRear = NULL;
}

template<class kind>
listQueue<kind>::listQueue(const listQueue<kind>& otherqueue){
    queueFront = NULL;
    queueRear = NULL;
    copyQueue(otherqueue);
}

template<class kind>
listQueue<kind>::~listQueue(){
    initializeQueue();
}

#endif









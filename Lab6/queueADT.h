#ifndef Queue_queueADT_h
#define Queue_queueADT_h

template<class kind>
class queueADT{
    
public:
    virtual void initializeQueue() = 0;
    //Function to initialize the queue to an empty state
    //postcondition: the queue is empty

    virtual bool isEmptyQueue() const = 0;
    //Function to determine whether the queue is empty.
    //Postcondition: Returns true if the queue is empty,
    //  otherwirse return false.
    
    virtual bool isFullQueue() const = 0;
    //Function to determine whether the queue is full.
    //postcondition: Returns true if the queue is full,
    //  otherwise returns false.
    
    virtual kind back() const = 0;
    //Function to return the last element of the queue.
    //precondition: The queue exists and is not empty.
    //postcondition: If the queue is empty, the program
    //         terminates; otherwise, the last element
    //          of the queue is returned
    
    virtual kind front() const = 0;
    //Function to return the first element of the queue.
    //precondition: The queue exists and is not empty.
    //postcondition: If the queue is empty, the program
    //         terminates; otherwise, the first element
    //          of the queue is returned
    
    virtual void addQeuue(const kind& newitem) = 0;
    //Function to add newitem to the queue.
    //precondition: The queue exists and is not Full.
    //postcondition: the queue is changed and
    //       newitem is added to the queue.
    
    virtual void deleteQueue() = 0;
    //Function to remove the first element of the queue.
    //precondition: The queue exists and is not Empty.
    //postcondition: the queue is changed and
    //       the first element is removed from the queue.
    
};

#endif

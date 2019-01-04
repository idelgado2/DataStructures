/********************************************************************
 * Name: Isaac Delgado
 * Course #: COSC2437
 * Semester: Spring 2015
 *** Code is taken from "Data Structures Using C++", by D.S. Malik***
 ********************************************************************/

#ifndef linkedListIterator_h
#define linkedListIterator_h
#include <iostream>

template<class kind>
struct nodeType{
    kind info;
    nodeType<kind> *link;
};

template <class kind>
class linkedListIterator {
    
public:
    linkedListIterator();
    //Default constructor
    //Postcondition: current = NULL;
    
    linkedListIterator(nodeType<kind> *ptr);
    //constroctor with parameter
    //postconditon: current = ptr;
    
    kind operator* ();
    //Function to overload the dereferencing operator *.
    //postcondition: returns the info contained in the node
    
    linkedListIterator<kind> operator++ ();
    //Overload the preincrement operatir
    //postcondition: The iterator is adcanced to the next node.
    
    bool operator== (const linkedListIterator<kind>& right) const;
    //Overload the equality operator.
    //postcondition: returns true if this iterator is equal
    //to the iterator specified by right, otherwise it returns false
    
    bool operator!= (const linkedListIterator<kind>& right) const;
    //Overload the not equal to operator
    //postcondition : returns true if this iterator is not equal to
    //  the iterator specified by right, otherwise it returns
    //      false
    
private:
    nodeType<kind> *current; //pointer to point to the current
                            //node in the linked list
};


template<class kind>
linkedListIterator<kind>::linkedListIterator(){
    
    current  = NULL;
}


template<class kind>
linkedListIterator<kind>::linkedListIterator(nodeType<kind> *ptr){
    
    current = ptr;
}


template<class kind>
kind linkedListIterator<kind>::operator* (){
    
    return current -> info;
}


template<class kind>
linkedListIterator<kind> linkedListIterator<kind>::operator++ (){
    
    current = current -> link;
    
    return *this;
}


template<class kind>
bool linkedListIterator<kind>::operator== (const linkedListIterator<kind>& right) const{
    
    return (current == right.current);
}


template<class kind>
bool linkedListIterator<kind>::operator!= (const linkedListIterator<kind>& right) const{
    
    return (current != right.current);
}


#endif

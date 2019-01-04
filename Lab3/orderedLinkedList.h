#ifndef Lab3_orderedLinkedList_h
#define Lab3_orderedLinkedList_h
#include "linkedListType.h"
#include <iostream>
using namespace std;

/*using linkedListType<kind>::first;
using linkedListType<kind>::last;
using linkedListType<kind>::count;*/

template<class kind>
class orderedLinkedList: public linkedListType<kind>{
    
    using linkedListType<kind>::first;
    using linkedListType<kind>::last;
    using linkedListType<kind>::count;
    
public:
    bool search(const kind& searchItem) const;
    //Fucntion to determine whether searchItem is in the list.
    //postcondition: returns true if searchItem is in th elist.
    //      otherwise the calue false is returned.
    
    void insert(const kind& newItem);
    //function to insert newItem in the list
    //postcondition: first points to the new list, newItem
    //      is inserted at the proper place in the list, and
    //      count is incremented by 1.
    
    void insertFirst(const kind& newItem);
    //function to insert newItem at the beginning of the list
    //postcondition: first points to the new list, newItem
    //      is inserted at the beginning of the list, and
    //      count is incremented by 1.
    
    void insertLast(const kind& newItem);
    //function to insert newItem at the end of the list
    //postcondition: first points to the new list, newItem
    //      is inserted at the end of the list, and
    //      count is incremented by 1.
    
    void deletenode(const kind& deleteItem);
    //function to delete deleteItem from the list.
    //postcondition: if found, the node containning deleteItem is
    //deleted from the list; first points to the first node
    //of the new list, and count is decremented by 1. if
    //deleteItem is not in the list, an appropriate message
    //is printed.
};

template<class kind>
bool orderedLinkedList<kind>::search(const kind& searchItem) const{
    bool found = false;
    nodeType<kind> *current;   //pointer to traverse the list
    
    current = first;  //start the search at the first node
    
    while(current != NULL && !found){
        if (current -> info >= searchItem)
            found = true;
        else
            current = current -> link;
    }
    
    if (found) {
        found = (current -> link == searchItem);  //test for equality
    }
    
    return found;
}//end search

template<class kind>
void orderedLinkedList<kind>::insert(const kind& newItem){
    nodeType<kind> *current;        //pointer to traverse the list
    nodeType<kind> *trailCurrent;       //pointer just before current
    nodeType<kind> *newNode;            //pointer to create a node
    
    bool found;
    
    newNode = new nodeType<kind>;       //create the node
    newNode -> info = newItem;          //store newItem in the node
    newNode -> link = NULL;            //set the link field of the node to NULL
    
    if (first == NULL) {
        first = newNode;
        last = newNode;
        count++;
    }
    else{
        current = first;
        found = false;
        
        while (current != NULL && !found) {
            if(current -> info >= newItem)
                found = true;
            else{
                trailCurrent = current;
                current = current -> link;
            }
        }
        if (current == first){
            newNode -> link = first;
            first = newNode;
            count++;
        }
        else{
            trailCurrent -> link = newNode;
            newNode -> link = current;
            
            if (current == NULL)
                last = newNode;
            
            count++;
        }
    }
}

template<class kind>
void orderedLinkedList<kind>::insertFirst(const kind& newItem){
    insert(newItem);
}

template<class kind>
void orderedLinkedList<kind>::insertLast(const kind& newItem){
    insert(newItem);
}

template<class kind>
void orderedLinkedList<kind>::deletenode(const kind& deleteItem){
    nodeType<kind> *current;  //pointer to traverse th elist
    nodeType<kind> *trailCurrent; //pointer just before current
    
    bool found;
    
    if (first == NULL)
        cout << "Cannot delete from an empty list." << endl;
    else{
        current = first;
        found = false;
        
        while (current != NULL && !found) {  //search list
            if (current -> info >= deleteItem)
                found = true;
            else{
                trailCurrent = current;
                current = current -> link;
            }
        }
        
        if (current == NULL)
            cout << "The item to be deleted is not in the list." << endl;
        else{
            if(current -> info == deleteItem){  //the item to be deleted is in the list
                if (first == current) {
                    first = first -> link;
                    if (first == NULL)
                        last = NULL;
                    
                    delete current;
                }
                
                else{
                    trailCurrent -> link = current -> link;
                
                        if(current == last)
                            last = trailCurrent;
                
                        delete current;
                    }
                    count--;
                }
            else
                cout << "The item to be deleted is not in the list." << endl;
            }

        
    }//end deleteNode










#endif

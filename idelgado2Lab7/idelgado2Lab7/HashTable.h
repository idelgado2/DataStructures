/**********************************************************************************
 * Lab7.cpp
 * Isaac Delgado
 * COSC2437
 * 4/12/2015
 * Purpose: The purpose of this class is to create a hashtable(quick searching list)
 *          with inserting, searching and printing capabilities.
 ***********************************************************************************/
#ifndef idelgado2Lab7_HashTable_h
#define idelgado2Lab7_HashTable_h
#include <iostream>
#include <cassert>
#include <iomanip>
#include <fstream>

using namespace std;

template<class kind>
class HashTable{
public:
    void insert(const kind& item);
    //Function to insert an item in the hash table.
    //The item to be inserted is specified by the
    //parameter item.
    //Postcondition: If an empty position is found in the hash
    //  table otherwise, an appropriate error message is displayed.
    
    bool search(const kind& item);
    //Function to search for an item in the hash table.
    //The item to be searched for is specified by the
    //parameter item.
    //Postcondition: If the item is found will return TRUE
    //      otherwise return FALSE
    
    HashTable(int size = 100);
    //constructor function to initializes HashTable size with givin size or default parameter of 100 and
    //memeroy allocates arrays for HashTable and StatusList
    //as well as intialize arrays to vacant status
    //postcondition: HashTable and statuslist arrays initialized to vacant and HashTable size initialized
    // to givin parameter or default parameter
    
    ~HashTable();
    //destructor
    //deallocating HashTable and Status list.
    
    void print(ifstream&, ofstream&);
    //funtion to print out all tables and information to file idelgado2lab7.out
    //postconditon: Information printed out to file idelgado2lab7.out
    
private:
    kind *HTable;  //pointer to the hashtable
    int *StatusList;  //pointer to the paralle array that indicated wheather
    //the corresponding position in the hashtable is occupied or not
    int HTsize;  //maximum size of the hash table
    int CurrentCollisions; //number of collisions per element search
    int TotalCollisions = 0; //Total number of collisions
    
};


template<class kind>
HashTable<kind>::HashTable(int size){
    HTsize = size;
    
    HTable = new kind [size]; //allocating memorey for Hashtale
    StatusList = new int [size]; //allocating memory for parallel status array
    
    for (int i = 0; i < HTsize; i++) {  //set every subscript to vacant
        HTable[i] = -1;
        StatusList[i] = 0;
    }

}

template<class kind>
HashTable<kind>::~HashTable(){
    delete [] HTable;  //deallocating array
    delete [] StatusList; //deallocating array
}

template<class kind>
void HashTable<kind>::insert(const kind& item){
    int HashIndex = item % HTsize;  //Modulo-division hashing
    int count = 0; //counter on how many subscripts/elements in Hastable have been compared

    while (StatusList[HashIndex]== 1 && HTable[HashIndex] != item && count < HTsize )  //While space in Hash Table is occupied
    {                       //and item does not equal element in hashtable and all possible spaces have not been checked yet
        HashIndex = (HashIndex + 1) % HTsize;  //linear probing to resoulve collison
        count++;
    }
    if (StatusList[HashIndex] != 1) {  //if there is no element occupiing subscript in Hash Tbale
        HTable[HashIndex] = item;       //assign itme to this subscript in Hash Table
        StatusList[HashIndex] = 1;  //set the status of this subscript occupied
    }
    else if (HTable[HashIndex] == item){  //else if item and Hash Table element are equal
        cerr << "There cannot be dublicates in the list, cannot add this item\n";
    }
    else{  //else all subscripts have been checked, thus full list
        cerr << "Cannot avoid collison, the list is full\n";
    }
    
}

template<class kind>
bool HashTable<kind>::search(const kind &item){
    int HashIndex = item % HTsize;  //Modulo-division hashing
    int count = 0; //counter on how many subscripts/elements in Hastable have been compared
   CurrentCollisions = 0; //initializing number of collision for the searched item to 0
    
    while (HTable[HashIndex] != item && StatusList[HashIndex]== 1 && count < HTsize )  //While item does not equal element in
                            //hashtable and space in Hash Table is occupied and all possible spaces have not been checked yet
    {
        HashIndex = (HashIndex + 1) % HTsize;  //linear probing to resoulve collison
        count++;
        CurrentCollisions++;
    }
    
    TotalCollisions += CurrentCollisions; //Adding total amount of collisons
    
    if (HTable[HashIndex] == item) { //if item was found
        return true;
    }
    else    //if item was not found
        return false;
    
}

template<class kind>
void HashTable<kind>::print(ifstream& searchfile, ofstream& outputfile) {
    int searchitem;
    outputfile << "HASH METHOD: modulo-division\n"
                << "COLLISION RESOLUTION: linear probe\n"
                        << "HASHED LIST:\n";
    outputfile << "SUB" << setw(6) << "KEY" << endl;
    for (int i = 0; i < HTsize; i++) {
        outputfile << setw(3) << i  << setw(8) << HTable[i] << endl;
    }
    
    outputfile << endl;
    outputfile << "HASHED LIST SEARCH RESULTS:" << endl;
    outputfile << setw(3) << "KEY" << setw(7) << "FOUND" << setw(12) << "#COLLISIONS" << endl;
    while (searchfile >> searchitem) {  //while there are items to search from search file
        if (search(searchitem)) //if item is found
            outputfile << setw(3) << searchitem << setw(5) << "YES" << setw(5) << CurrentCollisions << endl;
        else  //if item is NOT found
            outputfile << setw(3) << searchitem << setw(5) << "NO" << setw(5) << CurrentCollisions << endl;
    }
    
    outputfile << "****Total Number of Collisions: " << TotalCollisions << endl;
}

#endif








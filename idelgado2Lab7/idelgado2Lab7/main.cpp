/*************************************************************************
 * Lab7.cpp
 * Isaac Delgado
 * COSC2437
 * 4/12/2015
 * Purpose: The purpose of this program is to take input items and insert
 *          them into a quick searching HashTable using modular divison to 
 *          resolve collisons.
 *
 * Input:   The input of the program will be the from the file, "lab7.out"
 *          and "lab7srch.dat" in these files contains input to insert in 
 *          the hashTable and items to search within the HashTable
 *
 * Output:  The output of this program will be the Hashtable with the 
 *          inserted inputs as well as the list of searched items with a 
 *          confirmation on whether the item is found in the hashtable
 **************************************************************************/
#include "HashTable.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cassert>
using namespace std;

int main() {

    int item; //integer to hold hashtable input items
    ifstream file, searchfile;
    ofstream outputfile;
    
    file.open("lab7.dat");
    if(file.fail()){
        cerr << "Could Not Open file containing input items\n";
        exit(1);
    }
    
    searchfile.open("lab7srch.dat");
    if(searchfile.fail()){
        cerr << "Could Not Open search item file\n";
        exit(1);
    }

    HashTable<int> list(13);  //creating HashTable Object

    cout << "Reading items from file \"lab7.out\" and inserting into a HashTable...\n\n";

    while (file >> item) { //while there are items from file lab7.dat to input into hashtable
        list.insert(item); //insert current item into hashtable
    }
    
    outputfile.open("idelgado2lab7.out");
    list.print(searchfile, outputfile);  //print out table and search items information
    
    cout << "Printing out HashTable and other information to file \"idelgado2lab7.out\"...\n\n"
                   << "***Process Complete***\n";
    
    file.close();
    searchfile.close();
    return 0;
}

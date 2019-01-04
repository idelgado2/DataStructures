/*************************************************************************
 * Lab3.cpp
 * Isaac Delgado
 * COSC2437
 * 2/11/2015
 * Purpose: The purpose of this program is to retrive the information of 
 *          the file, "lab3.dat" and pu tthe items into a linked list.
 *          following, the program will update the linked list with the 
 *          information of the file "lab3up.dat".
 *
 * Input:   The input of the program will be the from the files, "lab3.dat"
 *          and "lab3up.dat". witch will either insert or delete items from
 *          a linkedlist, provided items by "Lab3.dat"
 *
 * Output:  The output of this program will be the orginal list of items 
 *          "lab3.dat" as well as the length of the list. following will 
 *          commands from the file "lab3up.dat" and if the command failed
 *          succseeded. following will be printed the updated length of new 
 *          list created and the actual updated list created.
 **************************************************************************/

#include "orderedLinkedList.h"
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int main() {
    
    int code, num, count, countup;
    
    ifstream numfile, numfile2;  //input file objects
    
    numfile.open("lab3.dat");       //streaming from lab3.dat
    
    numfile2.open("lab3up.dat");        //streaming from Lupdated list commands "lab3up.dat"
    
    
    if (numfile.fail() || numfile2.fail()) {    //check if files are openable
        
        cerr << "could not open file" << endl;
        
        exit(1);
    }
    
    orderedLinkedList<int> list;    //creating orderedlinkedlist object
    
    
    cout << "Reading in list from Lab3.dat file..." << endl;
    
    
    while (numfile >> num) {        //till there are no more items to input from file
        
        list.insert(num);           //insert the items into the linked list
        
    }
    
    count = list.length();  //returning original length of the list
    
    cout<< "List" << endl;
    
    cout << "List Length: ";
    
    cout << count;
    
    cout << endl << "**********************************" << endl;
    
    list.print();
    
    cout << endl << "**********************************" << endl << endl;
    
    cout << "CODE\t KEY\t MESSAGE" << endl;
    
    while (numfile2 >> code) {    //while there is a code to inputfrom the updated list
        
        if (code == 0) {    //when number needs to be deleted from the list
            
            numfile2 >> num;  //set current code to num
            
            if (!list.search(num)) {  //if code is not in the list
                
                cout << code << setw(12) << num <<" \tDELETE Failed (NOT in list)" << endl;
            }
            else{
                
                list.deleteNode(num);   //delete the node from the list
                
                cout << code << setw(12) << num << " \tDELETE Successful" << endl;
            }
            
        }
        else{  //else code is 1, meanning to insert the item into the list
            
            numfile2 >> num;  //set current code to num
            
            if (list.length() >= count) {  //if the list is is the same length as the original length of the list, then fail(overflow)
                
                cout << code << setw(12) << num << " \tINSERT Failed (OVERFLOW)" << endl;
                
            }
            else if (list.search(num)){     //else if, item is already in the list, fail(cant be dublicate items)
                
                cout << code << setw(12) << num << " \tINSERT Failed (DUPLICATE key)" << endl;
                
            }
            else{
                
                list.insert(num);    //insert the item
                
                cout << code << setw(12) << num << " \tINSERT Successful" << endl;
                
            }
            
        }
        
    }
    
    cout << endl;
    
    countup = list.length(); //set updated length to countup
    
    cout << "Updated-list" << endl;
    
    cout << "Updated-List Length: ";
    
    cout << countup;
    
    cout << endl << "**********************************" << endl;
    
    list.print();
    
    cout << endl << "**********************************" << endl << endl;
    
    numfile.close();        //close file
    
    numfile2.close();       //close file
    
    return 0;
}

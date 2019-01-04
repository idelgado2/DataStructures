/*************************************************************************
 * Lab8.cpp
 * Isaac Delgado
 * COSC2437
 * 4/20/2015
 * Purpose: The purpose of this program is to take a list givin by file "lab8.dat"
 *          and sort it using "Selection Sort", "Insertion Sort", and "QuickSort"
 *          and record the amount of moves and loop interations each techinique uses
 *
 * Input:   The input of the program will be the from the file, "lab8.dat"
 *          which contains the elemnts to sort in a list
 *
 * Output:  The output of this program will be directed to file "idelgado2lab8.out"
 *          and in the file will be the sorted list after being sorted
 *          by all three techineques to prove it it fully sorted the list as will
 *          as the number of loop iterations and moves produced.
 **************************************************************************/
#include "ArrayListType.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <cassert>

using namespace std;
int main() {

    ifstream elementsFile;
    ofstream outputFile;
    ArrayListType<int> listSelectionSort(70); //creatign an array with a size of 70;
    int element;
    
    elementsFile.open("lab8.dat");  //will read from file "lab8.dat"
    outputFile.open("idelgado2lab8.out"); //will output to file "idelgado2lab8.out"
    
    if(elementsFile.fail()){
        cerr << "Could Not Open file containing input items\n";
        exit(1);
    }
    
    cout << "Reading in list from file \"lab8.dat\"..." << endl << endl;
    
    while (elementsFile >> element) {
        listSelectionSort.Insert(element);  //insert each element in file to array
    }
    
    ArrayListType<int> listInsertionSort(listSelectionSort); //copy constructor, copying contents of original list to new one
    ArrayListType<int> listQuickSort(listSelectionSort);    //copy constructor, copying contents of original list to new one
    
    outputFile << "******************************************************" << endl;
    outputFile << "\"Selection Sort\"" << endl << endl;
    listSelectionSort.SelectionSort();
    listSelectionSort.print(outputFile);
    outputFile << "******************************************************" << endl;
    
    outputFile << endl;
    
    outputFile << "******************************************************" << endl;
    outputFile << "\"Insertion Sort\"" << endl << endl;
    listInsertionSort.InsertionSort();
    listInsertionSort.print(outputFile);
    outputFile << "******************************************************" << endl;
    
    outputFile << endl;
    
    outputFile << "******************************************************" << endl;
    outputFile << "\"Quick Sort\"" << endl << endl;
    listQuickSort.QuickSort();
    listQuickSort.print(outputFile);
    outputFile << "******************************************************" << endl;


}

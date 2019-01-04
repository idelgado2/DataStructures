/*************************************************************************
 * Lab9.cpp
 * Isaac Delgado
 * COSC2437
 * 4/25/2015
 * Purpose: The purpose of this program is to input values from file "lab9.dat"
 *          and insert into an AVL tree. Afterwards, program will print
 *          preOrder, inOrder, and postOrder values from AVl tree.
 *
 * Input:   The input of the program will be the from the file, "lab9.dat"
 *          which contains the elemnts to insert in to AVL tree
 *
 * Output:  The output of this program will be directed to file "idelgado2lab9.out"
 *          and in the file will be printed the preOrder, inOrder, and postOrder
 *          values of values inserted in the AVL tree.
 **************************************************************************/
#include "avlTree.h"
#include <fstream>
#include <cstdlib>
#include <cassert>
#include <iostream>
using namespace std;

void print(ofstream& outputfile, AVLTreeType<char>& Tree, int& num); //Function to Print to file "idelgado2lab9.out"

int main() {
    char node;
    int numberOfNodes;
    
    AVLTreeType<char> tree; //creating avl tree
    
    ifstream readfile;
    ofstream outputfile;
    readfile.open("lab9.dat");
    if (readfile.fail()) {
        cerr << "ERROR...Could not open file";
        exit(1);
    }
    
    cout << "Reading in list from file \"lab9.dat\"..." << endl << endl;

    while (readfile >> node) {  //while you can read in values, insert into AVL tree
        tree.insert(node);
    }
    
    numberOfNodes = tree.getNumberOfNodes();
    
    outputfile.open("idelgado2la9.out");
    
    cout << "Printing information into file \"idelgado2lab9.out\"..." << endl << endl;
    
    print(outputfile, tree, numberOfNodes);  //Print information to file "idelagdo2lab9.out"
    
    cout << "End of Program" << endl;
    
    readfile.close();
    outputfile.close();
}

void print(ofstream& outputfile, AVLTreeType<char>& Tree, int& num){
    outputfile << "Lab 9, ouput" << endl;
    outputfile << "*****************************************" << endl;
    outputfile << "Number of Nodes in AVLTREE: " << Tree.getNumberOfNodes();
    outputfile << endl << endl;
    
    outputfile << "PreOrder Traversal Result:";
    Tree.preOrderTraversal(outputfile);  //preOrder Function call
    outputfile << endl << endl;
    
    outputfile << "InOrder Traversal Result:";
    Tree.inOrderTraversal(outputfile);  //inOrder Function call
    outputfile << endl << endl;
    
    outputfile << "PostOrder Traversal Result:";
    Tree.postOrderTraversal(outputfile);  //postOrder Function call
    outputfile << endl;
    outputfile << "*****************************************" << endl;
}
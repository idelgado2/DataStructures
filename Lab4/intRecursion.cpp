/*************************************************************************
 * intRecursion.cpp
 * Isaac Delgado
 * COSC2437
 * 2/28/2015
 * Purpose: The purpose of this program is count and return the elements
 *          of and integer array.
 *
 * Input:   The input of the program will be an integer array with the 
 *          values giving by the user.
 *
 * Output:  The output of this program will be the sum of all the elements
 *          in an integer array.
 **************************************************************************/

#include <iostream>
using namespace std;

void initializeArray(int [], int);
//Function to intialize an integer array.
//precondition: an integer array with a specific length
//postcondition: intialize the values with input of the user

int sumOfInts(int [], int, int);
//Function to return the sum of all the elements in an integer array.
//precondition: an initialized integer array, with values intialized by the user
//postcondition: well return the sum of all the elements in an integer array.

int main(){
    int *numberlist;
    int num;
    
    cout << "How many numbers do you want in your list?\n";
    
    cin >> num;   //length of array
    
    numberlist = new int[num];  //dynamically allocating memmory for array size
    
    cout << "Please enter the values of your list\n";
    
    initializeArray(numberlist, num);
    
    cout << "The sum of all values in your list is " << sumOfInts(numberlist, 0, num) << endl;  //recursive functoion to add up elements
    
    
    
}

void initializeArray(int array[], int length){
    //Function to intialize an integer array.
    //precondition: an integer array with a specific length
    //postcondition: intialize the values with input of the user
    
    for (int i = 0; i < length; i++) {
        
        cout << "Value " << i + 1 << ": ";
        
        cin >> array[i];
        
    }

}


int sumOfInts(int array[], int index, int length){
    //Function to return the sum of all the elements in an integer array.
    //precondition: an initialized integer array, with values intialized by the user
    //postcondition: well return the sum of all the elements in an integer array.
    
    
    if (index >= length) {
        //if subscrpit of array is greater or equal to length return 0
        //base case of recursive function
        
        return 0;
    }
    else{
        //else add the element at the specific subscript with the following element
        
        return array[index] + sumOfInts(array, index + 1, length);
    }
    
}
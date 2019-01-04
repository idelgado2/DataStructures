/********************************************************************
 * Name: Isaac Delgado
 * Course #: COSC2437
 * Semester: Spring 2015
 *** Code is taken from "Data Structures Using C++", by D.S. Malik***
 ********************************************************************/
#ifndef idelgado2Lab8_ArrayListType_h
#define idelgado2Lab8_ArrayListType_h

#include <iostream>
#include <fstream>

using namespace std;

template<class kind>
class ArrayListType{
public:
    bool isEmpty() const;
    //Function to determine if array is empty or not
    //Postcondition: will return true if array
    //     is empty or false if array has atleast one
    //     itme in the array
    
    bool isFull() const;
    //Function to determine if array is full or not
    //Postcondition: will return true if array
    //     is full or false if array is not full
    
    int ListSize() const;
    //Function to return the size of the array
    //Postcondition: a number of items int array
    
    int MaxSize() const;
    //Function tp return the Maxsize of the array
    //Postcondition: a number indicating the maximum size
    
    ArrayListType(int size = 70);
    //Constructor to intialize length, maxsize, and the array
    //postcondition: An initialized array
    
    ArrayListType(const ArrayListType<kind>& otherlist);
    //Copyconstructor
    //postcondition: An initialized array
    
    ~ArrayListType();
    //Destructor
    //postcondition: deleted memorey for array
    
    void print(ofstream & outputfile);
    //Function to print out infromation
    //postcondition: contents of arrat to screen
    
    const ArrayListType<kind>& operator=(const ArrayListType<kind>& otherlist);
    //function to overload the "=" operator
    //postconditon: An initlialized array with the contents of the otherlist
    
    void Insert(const kind& item);
    //function to insert an item into the array
    //postconditon: The array with a new item in the list
    
    int minLocation(int first, int last);
    //function return the location of the smallest value int array
    
    void Swap(int first, int second);
    //fucntion to swap two values within the array
    //Postcondition: The array will contain the two passed values
    //      bu they will be swapped inlocation
    
    void SelectionSort();
    //Function to Sort the array by Selection sort
    //postconstion: Array will be sorted in acending order
    
    void InsertionSort();
    //Function to Sort the array by Selection sort
    //postconstion: Array will be sorted in acending order
    
    int Partition(int first, int last);
    //Function to seperate array into two sublist, with the middle
    //element being the pivot and seperating all elements smaller
    //than the middle element to the left of the element and elements
    //greater than the middle element to the right.
    //postcondition: The array should be "partitioned" or seperated
    //      into an orgainized manner depeneding on the pivot value
    
    void recQuickSort(int first, int last);
    //Function to recursielly partition the and sort array,
    //beggingin with finding the elements that are smaller than
    //the pivot value, followed by partioning the values greater
    //than the pivot
    //postondition: arrray will be sorted in asending order
    
    void QuickSort();
    //Function to QuickSort an array, by partitionin recursivly
    //postondition: arrray will be sorted in asending order

private:
    kind *list;
    int length;
    int maxsize;
    int loopIterations;
    int moves;
};

template<class kind>
bool ArrayListType<kind>::isEmpty() const{
    return(length == 0);
}

template<class kind>
bool ArrayListType<kind>::isFull() const{
    return(length == maxsize);
}

template<class kind>
int ArrayListType<kind>::ListSize() const{
    return length;
}

template<class kind>
int ArrayListType<kind>::MaxSize()const{
    return MaxSize;
}

template<class kind>
void ArrayListType<kind>::print(ofstream &outputfile){
    outputfile << "Sorted List: " << endl;
    for (int i = 0; i < length; i++) { //for loop print out every item in array
        outputfile << list[i] << " ";
    }
    outputfile << endl << endl;
    outputfile << "# of Loop iterations: " << loopIterations << endl;
    outputfile << "# of moves by sorting: " << moves << endl;
}

template<class kind>
ArrayListType<kind>::ArrayListType(int size){
    if (size < 0 || size > 100) {
        cout << "Invlaid input for size, Size must be postivie and no higher than 100" << endl
                <<"Setting size to 100 by default.. " << endl;
        maxsize = 100;  //setting maxsize to default
    }
    else
        maxsize = size;
    
    list = new kind[maxsize]; //dynamically allocating array
    length = 0;
}

template<class kind>
ArrayListType<kind>::~ArrayListType(){
    delete [] list;
}

template<class kind>
ArrayListType<kind>::ArrayListType(const ArrayListType<kind>& otherlist){
    maxsize = otherlist.maxsize;
    length = otherlist.length;
    list = new kind[maxsize];       //create a new array
    for (int i  = 0; i < length; i++) {//copying each item from other array to this one
        list[i] = otherlist.list[i];
    }
}

template<class kind>
const ArrayListType<kind>& ArrayListType<kind>::operator=(const ArrayListType<kind>& otherlist){
    if(this != otherlist){
        maxsize = otherlist.maxsize;
        length = otherlist.length;
        list = new kind[maxsize];       //create a new array
        for (int i  = 0; i < length; i++) {//copying each item from other array to this one
            list[i] = otherlist.list[i];
        }
    }
    return *this;
}

template<class kind>
void ArrayListType<kind>::Insert(const kind& item){
    
    if (isFull()){
        cerr<< "Cannot Enter anymore items, the array is full";
    }
    else{
        list[length] = item;
        length++;
    }
    
}
template<class kind>
int ArrayListType<kind>::minLocation(int first, int last){
    int minIndex;
    
    minIndex = first;
    for (int location = first + 1; location <= last; location++) {
        if (list[location] < list[minIndex])
            minIndex = location;
    }
    
    return minIndex;
}

template<class kind>
void ArrayListType<kind>::Swap(int first, int second){
    kind temp;
    temp = list[first];
    list[first] = list[second];
    list[second] = temp;
}

template<class kind>
void ArrayListType<kind>::SelectionSort(){
    loopIterations = 0;     //initializ loopiteration
    moves = 0;              //initialize move counter
    int minIndex;
    for (int location = 0; location < length - 1; location++) {
        minIndex = minLocation(location, length - 1);
        Swap(location, minIndex);
        loopIterations++;       //count the number of iterations within the for loop
        moves++;                //count the number of moves commited but this sorting algorithm
    }
}

template<class kind>
void ArrayListType<kind>::InsertionSort(){
    loopIterations = 0;     //initializ loopiteration
    moves = 0;              //initialize move counter
    int location;
    int temp;
    for (int firstOutOfOrder = 1; firstOutOfOrder < length; firstOutOfOrder++) {
        if (list[firstOutOfOrder] < list[firstOutOfOrder - 1]) {
            temp = list[firstOutOfOrder];
            location = firstOutOfOrder;
            do {
                list[location] = list[location - 1];
                location--;
                loopIterations++;  //count the number of interations within do while loop
                moves++;            //count the number of moves commited but this sorting algorithm
            } while (location > 0 && list[location - 1] > temp);
            
            list[location] = temp;
            moves++;            //count the number of moves commited but this sorting algorithm
        }
        loopIterations++;   //count the number of iterations within the for loop
    }
}

template<class kind>
int ArrayListType<kind>::Partition(int first, int last){
    
    kind pivot;
    
    int smallIndex;
    Swap(first, (first + last) / 2);  //smoving pivot to the front of array
    
    pivot = list[first];
    smallIndex = first;
    
    for (int i = first + 1; i <= last; i++) {
        if (list[i] < pivot) {
            smallIndex++;
            Swap(smallIndex, i);
            moves++;
        }
        loopIterations++;
    }
    Swap(first, smallIndex);
    
    return smallIndex;
}

template<class kind>
void ArrayListType<kind>::recQuickSort(int first, int last){
    int pivotLocation;
    if (first < last) {
        pivotLocation = Partition(first, last);
        recQuickSort(first, pivotLocation - 1);  //Recusrive call to partition values less than pivot
        recQuickSort(pivotLocation + 1, last);      //Recursive call to partition values greater than pivot
    }
}

template<class kind>
void ArrayListType<kind>::QuickSort(){
    loopIterations = 0;
    moves = 0;
    recQuickSort(0, length - 1);
}







#endif

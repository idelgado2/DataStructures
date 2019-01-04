//Name:     Isaac Delgado
//Course:   COSC 2437
//Lab #:    1
//Assigned: Jan 29, 2015
//Due:      Feb 4, 2015, 11:59pm
//Late Due: Feb 6, 2015, 11:59pm
//Purpose:  To implement a simple mainline or driver program to
//              test the clockType class found in Malik, chapter 1.
//
//Input:    keyboard input for integer hours, minutes and seconds
//
//Output:   screen ouput
//
//Program Outline/Design:
//          -Create two clockType objects: cellPhoneClock and
//          myComputerClock
//          -Prompt the user to enter the times for both clocks.
//          -Display both times with appropriate documentation.
//          -If the clocks do not have equal times, set myComputerClock
//          to the cellPhoneClock time.
//          -Set myComputerClock so that it is 1 hour, 5 minutes,
//          23 seconds faster than the cellPhoneClock.
//          -Display both times again, with appropriate documentation.

#include "clockType.h" /***class taken from "Data Structures Using C++", by D.S. Malik****/
#include <iostream>
using namespace std;

int main() {
    int hours, minutes, seconds;
    cout << "Hello, please set both your Phone Clock, and your Computer CLock\n";
    cout<< "\t***Phone Clock***\n";
    
    cout << "Hours: ";
    cin >> hours;
    
    cout << "Minutes: ";
    cin >> minutes;
    
    cout << "seconds: ";
    cin >> seconds;
    
    clockType cellPhoneClock(hours, minutes, seconds); //creating a clockType object called cellPhone Clock
    
    cout<< "\t***Computer Clock***\n";
    
    cout << "Hours: ";
    cin >> hours;
    
    cout << "Minutes: ";
    cin >> minutes;
    
    cout << "seconds: ";
    cin >> seconds;

    clockType myComputerClock(hours, minutes, seconds); //creating a clockType object called cellPhone Clock
    
    cout << endl << endl;
    
    cout << "Cell Phone Clock:\t";
    cellPhoneClock.printTime();
    
    cout << endl << endl;
    
    cout << "Computer CLock:\t";
    myComputerClock.printTime();
    
    cout << endl << endl;
    
    if (cellPhoneClock.equalTime(myComputerClock)){     //if both clocks are equal
        cout << "Clocks are equal\n";
    }
    else{
        cout << "Clocks are NOT equal\n\n";             //if clocks are NOT equal then setting myComputerclock time to cellPhoneClock
        myComputerClock.getTime(hours, minutes, seconds);
        cellPhoneClock.setTime(hours, minutes, seconds);


    }
    
    cout << "setting my Computer Clock, 1 hours, 5 minutes, and 23 seconds faster than cell Phone Clock...\n\n";
    for (int i = 1; i <= 1; i++) {
        myComputerClock.incrementHours();
    }
    
    for (int i = 1; i <= 5; i++) {
        myComputerClock.incrementMinutes();
    }
    
    for (int i = 1; i <= 23; i++) {
        myComputerClock.incrementSeconds();
    }

    cout << "cell Phone Clock:\t";
    cellPhoneClock.printTime();
    cout << endl;
    
    cout << "my Computer Clock:\t";
    myComputerClock.printTime();
    cout << endl;
    
}

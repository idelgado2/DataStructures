/*************************************************************************
 * Lab2.cpp
 * Isaac Delgado
 * COSC2437
 * 2/11/2015
 * Purpose: The purpose of this program is to get the details of a circle
 *          with the infromation givin by the user, then this program will
 *          calculate and print out the area and the circumference as well
 *          the x and y coordinates of the givin circle provided by the user.
 *
 * Input:   The input of the program will be the informatino about he circle
 *          givin by the user. the user will input the x and y coordinate
 *          of the their circle and the radius
 *
 * Output:  The output of this program will be the the x and y coordinates
 *          of the circle followed by the area and the circumferece of the 
 *          the givin circle with the givin radius.
 **************************************************************************/
#include "pointType.h"
#include "circleType.h"
#include <iostream>
using namespace std;

int main() {
    double x = 0, y = 0, r = 0;
    
    cout << "Hello, Welcome to Lab2" << endl;
    
    cout << "Please input the center of your Circle" << endl;
    
    cout << "X-Coordinate: ";
    cin >> x;
    
    cout << "Y-Coordinate: ";
    cin >> y;
    
    cout << "Please input the radius of your Circle" << endl;
    cin >> r;
    
    circleType yourCircle (x, y, r);
    
    cout << "Printing out information about your Circle" << endl << endl;
    
    cout << yourCircle;
    
    return 0;
}


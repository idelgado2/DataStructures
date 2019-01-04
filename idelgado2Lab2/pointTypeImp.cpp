/********************************************************************
 * Name: Isaac Delgado
 * Course #: COSC2437
 * Semester: Spring 2015
 ********************************************************************/
#include "pointType.h"
#include <iostream>
using namespace std;

void pointType::setPoint(double x, double y){
    
    xCoordinate = x;
                        //set the coordinates to the givin parameters
    yCoordinate = y;
}
void pointType::print() const{
    
    cout << "***************" << endl;
    
    cout << "X-Coordinate: " << xCoordinate << endl;
                                                        //printing information
    cout << "Y-Coordinate: " << yCoordinate << endl;
    
    cout << "***************";
    
    cout << endl;
}
double pointType::getX() const{
    
    return xCoordinate;
}

double pointType::getY() const{
    
    return yCoordinate;
}

pointType::pointType(double x, double y){
    setPoint(x, y);                         //setting x and y coordinates
}


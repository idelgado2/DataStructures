/********************************************************************
 * Name: Isaac Delgado
 * Course #: COSC2437
 * Semester: Spring 2015
 ********************************************************************/
#ifndef H_CircleType
#define H_CircleType

#include "pointType.h"
#include <iostream>
using namespace std;
 
class circleType: public pointType
{
public:
	void print() const;
    //function to print all infromation about
    //circle (x and y coordinates, area, and circumference)
    //postcondition: will print x and y coordinates,
    //area, and circumference as well as labels for the information
    
    friend ostream& operator<<(ostream& out, const circleType& circle);
    //overloading output operator to output the x and y coordinates, area,
    //and circumference of the circle
    //postcondition:will print x and y coordinates,
    //area, and circumference as well as labels for the information
    
	void setRadius(double r);
    //parameter is set for the radius
    //Postconditions: the parameter is stored in the
    //private memeber variable radius
    
	double getRadius() const;
    //function to return the radius
    //postsondition: will return the value in private member
    //function called radius
    
	double getCircumference() const;
    //function to return the output of the equation,(2 * pi * radius)
    //postsondition: will return the value of the the 2 * pi * radius
    //for the circumference of the circle
    
	double getArea() const;
    //function to return the output of the equation,(2 * pi * radius^2)
    //postsondition: will return the value of the the 2 * pi * radius^
    //for the area of the circle
    
	circleType(double x = 0.0, double y = 0.0, double r = 0.0);
    //constructor that will store 0.0 in both the x and y coordinates
    //as well as 0.0 as the radius
    //postcondition: private memeber variables x and y coordinates will be
    //initalized to 0.0 as well as the radius

protected:
	double radius;
};

#endif



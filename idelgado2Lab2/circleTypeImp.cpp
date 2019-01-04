#include "circleType.h"
#include <iostream>
#include <cmath>

using namespace std;

void circleType::print() const{         //printing information about circle
    
    cout << "Center Points:" << endl;
    
    pointType::print();
    
    cout<< endl;
    
    cout<< "*********************" << endl;
    
    cout<< "Radius: " << radius << endl;
    
    cout<< "Circumference: " << getCircumference() << endl;
    
    cout<< "Area: " << getArea() << endl;
    
    cout<< "*********************" << endl;

}

ostream& operator<<(ostream& out, const circleType& circle)
    //overloading output operator to output the information about the circle
{
    out << "Center Points:" << endl;
    
    out << "***************" << endl;
    
    out << "X-Coordinate: " << circle.getX() << endl;
    
    out << "Y-Coordinate: " << circle.getY() << endl;
    
    out << "***************";
    
    out<< endl << endl;
    
    out<< "*********************" << endl;
    
    out<< "Radius: " << circle.radius << endl;
    
    out<< "Circumference: " << circle.getCircumference() << endl;
    
    out<< "Area: " << circle.getArea() << endl;
    
    out<< "*********************" << endl;

    return out;
}


void circleType::setRadius(double r){
    //setting the giving parameter to radius
    radius = r;
}
double circleType::getRadius() const{
    
    return radius;
}

double circleType::getCircumference() const{
    
    return (2 * 3.14 * radius);
}

double circleType::getArea() const{
    //returnning area
    return (3.14 * pow(radius, 2.0));
}

circleType::circleType(double x, double y, double r){
    //setting points for x and y coordinates as well as the radius
    setPoint(x, y);
    setRadius(r);
}
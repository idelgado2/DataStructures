/********************************************************************
 * Name: Isaac Delgado
 * Course #: COSC2437
 * Semester: Spring 2015
 ********************************************************************/
#ifndef H_PointType
#define H_PointType

class pointType
{
public:
    void setPoint(double x, double y);
    //parameters are set for the x and y coordinates
    //Postconditions: the parametes are stored in
    //the private member variables for x-coordinate and y- coordinate
    
    void print() const;
    //function to print the x and y coordinates
    //postcondition: the x coordinates are printed along with
    //strings indicating which coordinate is which.
    
    double getX() const;
    //function to return the x-coordinate
    //postsondition: will return the value in private member
    //function called x-coordinate
    
    double getY() const;
    //function to return the y-coordinate
    //postsondition: will return the value in private member
    //function called y-coordinate
    
    pointType(double x = 0.0, double y = 0.0);
    //constructor that will store 0.0 int both the x and y coordinates
    //postcondition: private memeber variables x and y coordinates will be initalized to 0.0

protected:
    double xCoordinate;
    
    double yCoordinate;
};

#endif


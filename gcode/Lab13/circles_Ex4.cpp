// __________________________________________________________________
//
// This program declares a class for a circle that will have
// member functions that set the center, find the area, find
// the circumference and display these attributes.
// The program as written does not allow the user to input data, but
// rather has the radii and center coordinates of the circles
// (spheres in the program) initialized at definition or set by a function.

// Bisshoy Anwar

#include <iostream>
using namespace std;

// class declaration section	(header file)

class Circles
{
public:
    double findArea();
    double findCircumference();
    void printCircleStats();	// This outputs the radius and center of the circle. 
    Circles(float r);		// Constructor
    Circles();			// Default constructor 
    Circles(int x, int y);
    Circles(float r, int x, int y);
    ~Circles() {cout << "This concludes the Circles class" << endl;};
private:
    float radius;
    int	center_x;
    int	center_y;
};

const double PI = 3.14;

// Client section 

int main()
{
    Circles sphere(8, 9, 10);
    sphere.printCircleStats();

    cout << "The area of the circle is " << sphere.findArea() << endl;
    cout << "The circumference of the circle is "
	 << sphere.findCircumference() << endl << endl;

    // Exercise 2 Stuff
    Circles sphere1 = Circles(2);
    Circles sphere2;
    Circles sphere3(15,16);

    sphere1.printCircleStats();
    cout << "Area of sphere1: " << sphere1.findArea() << endl;
    cout << "Circumference of sphere1: " << sphere1.findCircumference() << endl << endl;

    sphere2.printCircleStats();
    cout << "Area of sphere2: " << sphere2.findArea() << endl;
    cout << "Circumference of sphere2: " << sphere2.findCircumference() << endl << endl;

    sphere3.printCircleStats();
    cout << "Area of sphere3: " << sphere3.findArea() << endl;
    cout << "Circumference of sphere3: " << sphere3.findCircumference() << endl << endl;

    return 0;
    
}

// __________________________________________________________________
//
// Implementation section	Member function implementation

Circles::Circles()
{
    radius = 1;
    center_x = 0;
    center_y = 0;
}

// Fill in the code to implement the non-default constructor
Circles::Circles(float r = 1)
{
    radius = r;
    center_x = 0;
    center_y = 0;
}

Circles::Circles(int x, int y)
{
    radius = 1;
    center_x = x;
    center_y = y;
}

Circles::Circles(float r, int x, int y)
{
    radius = 4;
    center_x = x;
    center_y = y;
}

// Fill in the code to implement the findArea member function
double Circles::findArea()
{
    return (PI * radius * radius);
}

// Fill in the code to implement the findCircumference member function
double Circles::findCircumference()
{
    return (2 * PI * radius);
}

void Circles::printCircleStats()
// This procedure prints out the radius and center coordinates of the circle
// object that calls it.
{
    cout << "The radius of the circle is " << radius << endl;
    cout << "The center of the circle is (" << center_x
	 << "," << center_y << ")" << endl;
}


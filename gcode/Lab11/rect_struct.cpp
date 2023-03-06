// This program uses a structure to hold data about a rectangle

// Bisshoy Anwar

#include <iostream>
#include <iomanip>

using namespace std;

// Fill in code to declare a structure named rectangle which has
// members length, width, area, and perimeter all of which are floats
struct rectangle
{
	float length;
	float width;
	float area;
	float perimeter;
};

int main()
{
	// Fill in code to define a rectangle variable named box
	rectangle box;

	cout << "Enter the length of a rectangle: ";
	cin >> box.length;
	// Fill in code to read in the length member of box

	cout << "Enter the width of a rectangle: ";
	cin >> box.width;
	// Fill in code to read in the width member of box

	cout << endl << endl;

	// Fill in code to compute the area member of box
	box.area = box.length * box.width;

	// Fill in code to compute the perimeter member of box
	box.perimeter = (2 * box.length) + (2 * box.width);

	cout << fixed << showpoint << setprecision(2);

	// Fill in code to output the area with an appropriate message
	cout << "Area: " << box.area << endl;

	// Fill in code to output the perimeter with an appropriate message
	cout << "Perimeter: " << box.perimeter << endl;

	if (box.length == box.width) {
		cout << "Your rectangle is a square." << endl;
	} else {
		cout << "Your rectangle is not a square." << endl;
	}

	return 0;

}
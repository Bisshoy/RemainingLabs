#include <fstream>
#include <iostream>
#include <iomanip> 

using namespace std;

// Bisshoy Anwar  

const int MAXNAME = 20;

int main()
{
	ifstream inData;
	inData.open("grades.txt");

	char name[MAXNAME + 1];	// holds student name 
	float average;			// holds student average

	inData.get(name, MAXNAME + 1);

	while (inData)
	{
		inData >> average;

		// Fill in the code to print out name and
		// student average
		cout << left << setw(20) << name << " has a(n) average of ";
		cout << average << endl;

		// Fill in the code to complete the while
		// loop so that the rest of the student
		// names and average are read in properly
		inData.ignore(80,'\n');

		inData.get(name, MAXNAME + 1);
	}

	return 0;
}


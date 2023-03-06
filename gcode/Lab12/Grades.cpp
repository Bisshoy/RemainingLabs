// This program reads records from a file. The file contains the
// following: student's name, two test grades and final exam grade.
// It then prints this information to the screen.

// Bisshoy Anwar 

#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

const int NAMESIZE = 15;
const int MAXRECORDS = 50;

// declares a structure 
struct Grades 
{
	char name[NAMESIZE + 1];
	int test1;
	int test2;
	int final;
	char letter;
};

typedef Grades gradeType[MAXRECORDS];
// This makes gradeType a data type
// that holds MAXRECORDS
// Grades structures.

// FIll IN THE CODE FOR THE PROTOTYPE OF THE FUNCTION ReadIt
// WHERE THE FIRST ARGUMENT IS AN INPUT FILE, THE SECOND IS THE
// ARRAY OF RECORDS, AND THE THIRD WILL HOLD THE NUMBER OF RECORDS
// CURRENTLY IN THE ARRAY.

void readIt(ifstream&, gradeType, int&);

int main()
{
	ifstream indata;

	indata.open("graderoll.dat");

	int numRecord;	// number of records read in 
	gradeType studentRecord;

	if (!indata)
	{
		cout << "Error opening file. \n";
		cout << "It may not exist where indicated" << endl;
		return 1;
	}

	// FILL IN THE CODE TO CALL THE FUNCTION ReadIt.
	readIt(indata, studentRecord, numRecord);

	// output the information

	for (int count = 0; count < numRecord; count++)
	{
		cout << studentRecord[count].name << setw(10) << studentRecord[count].test1 
		     << setw(10) << studentRecord[count].test2;
		cout << setw(10) << studentRecord[count].final << setw(10) << studentRecord[count].letter << endl;
	}

	indata.close();

	return 0;
}

//**************************************************************
//	readIt
//
//	task:	  This procedure reads records into an array of
//	          records from an input file and keeps track of the
//	          total number of records
//	data in:  data file containing information to be placed in
//	          the array
//	data out: an array of records and the number of records
//
//**************************************************************

void readIt(ifstream& indata, gradeType graderec, int& total)
	
			// FILL IN THE CODE FOR THE FORMAL PARAMETERS AND THEIR
	        // DATA	TYPES.
	        // inData, gradeRec and total are the formal parameters
	        // total is passed by reference)
{
	total = 0;

	indata.get(graderec[total].name, NAMESIZE);

	while(indata)
	{
		// FILL IN THE CODE TO READ test1
		indata >> graderec[total].test1;
		// FILL IN THE CODE TO READ test2
		indata >> graderec[total].test2;
		// FILL IN THE CODE TO READ final
		indata >> graderec[total].final;

		int numScore = (0.3 * graderec[total].test1) 
					 + (0.3 * graderec[total].test2) 
					 + (0.4 * graderec[total].final);

		if (numScore <= 100 && numScore >= 90) {
			graderec[total].letter = 'A';
		} else if (numScore <= 89 && numScore >= 80) {
			graderec[total].letter = 'B';
		} else if (numScore <= 79 && numScore >= 70) {
			graderec[total].letter = 'C';
		} else if (numScore <= 69 && numScore >= 60) {
			graderec[total].letter = 'D';
		} else {
			graderec[total].letter = 'F';
		}

		total++;	// add one to total

		// FILL IN THE CODE TO CONSUME THE END OF LINE
		indata.ignore(81, '\n');

		// FILL IN THE CODE TO READ name
		indata.get(graderec[total].name, NAMESIZE);

	}

}

